#include <Arduino.h>
#include <WiFi.h>
#include <time.h>
#include "epd_driver.h"
#include "firasans.h"
#include "opensans12b.h"
#include "opensans18b.h"
#include "opensans24b.h"
#include "Melone_40.h"
#include "DFRobot_GR10_30.h"
#include <HardwareSerial.h>
#include "recipe.h"

// Wi-Fi and NTP Configuration
const char* ssid = "Makerbrains";
const char* password = "Balaji2830";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 19800;  // IST (UTC +5:30)
const int daylightOffset_sec = 0;

// Gesture Sensor Configuration
HardwareSerial mySerial(2);
#define SENSOR_RX 12  // ESP32 RX -> Sensor TX
#define SENSOR_TX 13  // ESP32 TX -> Sensor RX
DFRobot_GR10_30 gr10_30(GR10_30_DEVICE_ADDR, &mySerial);

// Variables
int currentPage = 0;
int currentMealType = 0;
int currentMealIndex = 0;
int currentRecipeStep = 0;
unsigned long lastGestureTime = 0;
const unsigned long gestureDelay = 1000;
const unsigned long sleepTimeout = 300000; // 5 minutes

#define BUTTON_PIN 39  // Wake-up button pin

void setup() {
    Serial.begin(115200);
    mySerial.begin(9600, SERIAL_8N1, SENSOR_RX, SENSOR_TX);
    
    // Configure wake-up button
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    
    // Check wake-up reason
    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_EXT0) {
        Serial.println("Woke up from button press");
    }
    
    epd_init();
    connectToWiFi();
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    while (gr10_30.begin() != 0) {
        Serial.println("Sensor initialization failed!");
        delay(1000);
    }
    Serial.println("Sensor initialized successfully!");
    gr10_30.enGestures(GESTURE_UP | GESTURE_DOWN | GESTURE_LEFT | GESTURE_RIGHT);

    suggestMeal(); // Suggest meal based on real-time
    displayMainPage();
}

void loop() {
    handleGesture();
    if (millis() - lastGestureTime > sleepTimeout) {
        goToSleep();
    }
}

void displayMainPage() {
    epd_clear();

    int32_t cursor_x = 0, cursor_y = 0;

    cursor_x = 75; cursor_y = 100;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 75; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 75; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 75; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);

    cursor_x = 185; cursor_y = 220;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 185; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 185; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);
    cursor_x = 185; cursor_y += 53;
    writeln((GFXfont *)&FiraSans, "░░░░░░", &cursor_x, &cursor_y, nullptr);

    // Display day of week
    cursor_x = 500; cursor_y = 100;
    writeln((GFXfont *)&FiraSans, "Today is", &cursor_x, &cursor_y, nullptr);
    cursor_x = 500; cursor_y = 180;
    writeln((GFXfont *)&Melone_40, getDayOfWeek().c_str(), &cursor_x, &cursor_y, nullptr);
    
    // Display date
    cursor_x = 500; cursor_y = 240;
    writeln((GFXfont *)&OpenSans24B, getFormattedDate().c_str(), &cursor_x, &cursor_y, nullptr);

    // Display time
    cursor_x = 500; cursor_y = 320;
    writeln((GFXfont *)&FiraSans, "Time Now", &cursor_x, &cursor_y, nullptr);
    cursor_x = 500; cursor_y = 400;
    writeln((GFXfont *)&Melone_40, getFormattedTime().c_str(), &cursor_x, &cursor_y, nullptr);
    
    cursor_x = 0; cursor_y = 450;
    writeln((GFXfont *)&FiraSans, "________________________________________________", &cursor_x, &cursor_y, nullptr);
    
    // Display instruction
    cursor_x = 150; cursor_y = 510;
    writeln((GFXfont *)&FiraSans, "➤➤ Swipe to unlock your food! ➤➤", &cursor_x, &cursor_y, nullptr);
    
    epd_poweroff();
}

void displayMealPage() {
    epd_clear();
    int32_t cursor_x = 50, cursor_y = 60;
    String mealHeader = String(meals[currentMealType][currentMealIndex]) + " Ingredients:";
    writeln((GFXfont *)&OpenSans18B, mealHeader.c_str(), &cursor_x, &cursor_y, nullptr);
    cursor_x = 900; cursor_y = 60;
    writeln((GFXfont *)&FiraSans, "➹", &cursor_x, &cursor_y, nullptr);

    cursor_x = 0; cursor_y = 80;
    writeln((GFXfont *)&FiraSans, "________________________________________________", &cursor_x, &cursor_y, nullptr);
    
    // Display ingredients one by one, ignoring commas inside parentheses
    cursor_x = 50; cursor_y += 50;
    String ingredientsStr = ingredients[currentMealType][currentMealIndex];
    int startIndex = 0, commaIndex;
    bool insideParentheses = false;
    
    for (int i = 0; i < ingredientsStr.length(); i++) {
        char c = ingredientsStr[i];
        if (c == '(') insideParentheses = true;
        if (c == ')') insideParentheses = false;
        
        if (c == ',' && !insideParentheses) {
            String ingredient = ingredientsStr.substring(startIndex, i);
            ingredient.trim();
            writeln((GFXfont *)&OpenSans12B, ingredient.c_str(), &cursor_x, &cursor_y, nullptr);
            cursor_x = 50;
            cursor_y += 30;
            startIndex = i + 1;
        }
    }
    // Display last ingredient
    String lastIngredient = ingredientsStr.substring(startIndex);
    lastIngredient.trim();
    writeln((GFXfont *)&OpenSans12B, lastIngredient.c_str(), &cursor_x, &cursor_y, nullptr);
    
    epd_poweroff();
}

void displayRecipePage() {
    epd_clear();
    int32_t cursor_x = 50, cursor_y = 60;
    String recipeHeader = String(meals[currentMealType][currentMealIndex]) + " Recipe Steps:";
    writeln((GFXfont *)&OpenSans18B, recipeHeader.c_str(), &cursor_x, &cursor_y, nullptr);

    cursor_x = 900; cursor_y = 60;
    writeln((GFXfont *)&FiraSans, "➷", &cursor_x, &cursor_y, nullptr);

    cursor_x = 0; cursor_y = 80;
    writeln((GFXfont *)&FiraSans, "________________________________________________", &cursor_x, &cursor_y, nullptr);
    
    cursor_y += 50;
    
    for (int i = 0; i < 10; i++) { // Display all steps
        cursor_x = 50;
        String stepText = recipeSteps[currentMealType][currentMealIndex][i];
        while (stepText.length() > 0) {
            int splitPos = stepText.lastIndexOf(' ', 70);
            if (splitPos == -1 || splitPos > 70) splitPos = min(70, (int)stepText.length());
            cursor_x = 50;
            String line = stepText.substring(0, splitPos);
            writeln((GFXfont *)&OpenSans12B, line.c_str(), &cursor_x, &cursor_y, nullptr);
            cursor_y += 30;
            stepText = stepText.substring(splitPos + 1);
            if (cursor_y > EPD_HEIGHT - 30) break;
        }
        if (cursor_y > EPD_HEIGHT - 30) break;
    }
    epd_poweroff();
}

void handleGesture() {
    if (millis() - lastGestureTime < gestureDelay) return;
    
    if (gr10_30.getDataReady()) {
        uint16_t gestures = gr10_30.getGesturesState();
        lastGestureTime = millis();

        if (gestures & GESTURE_RIGHT && currentPage == 0) {
            suggestMeal();  // Update meal suggestion when entering the meal page
            currentPage = 1;
            displayMealPage();
        } else if (gestures & GESTURE_UP && currentPage == 1) {
            currentPage = 2;
            currentRecipeStep = 0;
            displayRecipePage();
        } else if (gestures & GESTURE_LEFT && currentPage == 1) {
            currentMealIndex = (currentMealIndex - 1 + 10) % 10;
            displayMealPage();
        } else if (gestures & GESTURE_RIGHT && currentPage == 1) {
            currentMealIndex = (currentMealIndex + 1) % 10;
            displayMealPage();
        } else if (gestures & GESTURE_DOWN && currentPage == 2) {
            currentPage = 1;
            displayMealPage();
        }
    }
}


void goToSleep() {
    Serial.println("Going to sleep...");
    delay(100); // Give serial time to send
    
    // Configure wake-up source
    esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, LOW);
    
    // Enter deep sleep
    epd_poweroff_all();
    esp_deep_sleep_start();
}

void connectToWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");
}

String getFormattedTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) return "Time Error";
    char timeString[10];
    strftime(timeString, sizeof(timeString), "%I:%M %p", &timeinfo);
    // Remove leading zero if present (optional)
    if (timeString[0] == '0') {
        memmove(timeString, timeString+1, strlen(timeString));
    }
    return String(timeString);
}

String getFormattedDate() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) return "Date Error";
    char dateString[15];
    strftime(dateString, sizeof(dateString), "%d-%m-%Y", &timeinfo);
    return String(dateString);
}

String getDayOfWeek() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) return "Day Error";
    char dayString[15];
    strftime(dayString, sizeof(dayString), "%A", &timeinfo);
    return String(dayString);
}

void suggestMeal() {
  int hour = getCurrentHour();
  if (hour >= 6 && hour < 10) currentMealType = 0; // Breakfast
  else if (hour >= 10 && hour < 12) currentMealType = 1; // Brunch
  else if (hour >= 12 && hour < 16) currentMealType = 2; // Lunch
  else if (hour >= 16 && hour < 18) currentMealType = 3; // Snacks
  else if (hour >= 18 && hour < 22) currentMealType = 4; // Dinner
  else currentMealType = 5; // Midnight Meal
  currentMealIndex = random(0, 10); // Random meal suggestion
}

int getCurrentHour() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) return 0;
    return timeinfo.tm_hour;
}
