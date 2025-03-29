const char* mealTypes[] = {"Breakfast", "Brunch", "Lunch", "Snacks", "Dinner", "Midnight Meal"};

const char* meals[6][10] = {
  // Breakfast
  {"Masala Poha", "Upma", "Idli-Sambar", "Aloo Paratha", "Mysore Masala Dosa", "Besan Chilla", "Vegetable Uttapam", "Sabudana Khichdi", "Pongal", "Medu Vada"},
  
  // Brunch
  {"Dhokla", "Khandvi", "Misal Pav", "Pav Bhaji", "Aloo Puri", "Rava Idli", "Vegetable Frankie", "Dahi Vada", "Methi Thepla", "Mango Shrikhand"},
  
  // Lunch
  {"Dal Tadka-Rice", "Rajma Chawal", "Chole Bhature", "Vegetable Biryani", "Palak Paneer-Roti", "Sambar-Rice", "Kadhi Pakoda", "Malai Kofta", "Baingan Bharta", "Mixed Vegetable Curry"},
  
  // Snacks
  {"Samosa", "Aloo Tikki", "Pani Puri", "Bhel Puri", "Vegetable Pakora", "Kachori", "Dhokla", "Corn Chaat", "Pav Vada", "Spring Rolls"},
  
  // Dinner
  {"Khichdi", "Dal-Roti-Sabzi", "Vegetable Pulao", "Dahi Kadhi-Rice", "Methi Malai Mutter", "Vegetable Kofta Curry", "Lauki Chana Dal", "Bhindi Masala", "Aloo Jeera", "Mix Veg Jalfrezi"},
  
  // Midnight Meal
  {"Milk-Banana", "Toast-Jam", "Poha", "Upma", "Cornflakes", "Fruit Salad", "Sabudana Khichdi", "Vermicelli Upma", "Bread Pakora", "Dahi-Chiwda"}
};

const char* ingredients[6][10] = {
  // Breakfast
  {
    // Masala Poha
    "1.5 cups thick poha, 1 onion (finely chopped), 1 potato (diced), 2 green chilies, 1/2 tsp mustard seeds, 1/2 tsp turmeric, 10-12 curry leaves, 2 tbsp peanuts, 1 tbsp lemon juice, 2 tbsp oil, salt to taste, fresh coriander",
    
    // Upma
    "1 cup semolina (rava), 1 onion, 1 carrot, 1 tomato, 1 green chili, 1/2 tsp mustard seeds, 1/2 tsp urad dal, 10 curry leaves, 1 tbsp ghee, 2 cups water, salt, lemon juice",
    
    // Idli-Sambar
    "2 cups idli rice, 1 cup urad dal, 1/2 tsp fenugreek seeds, salt, water for grinding; For sambar: toor dal, vegetables (drumstick, carrot, pumpkin), sambar powder, tamarind, jaggery, curry leaves",
    
    // Aloo Paratha
    "2 cups whole wheat flour, 3 boiled potatoes, 1 tsp cumin seeds, 1/2 tsp red chili powder, 1 tsp coriander powder, 2 tbsp ghee, salt, water for kneading",
    
    // Mysore Masala Dosa
    "2 cups rice, 1/2 cup urad dal, 1/4 tsp fenugreek, salt; For masala: 3 potatoes, 1 onion, 2 green chilies, 1/2 tsp mustard seeds, turmeric, curry leaves; For chutney: coconut, chana dal, red chilies",
    
    // Besan Chilla
    "1 cup besan, 1 onion (finely chopped), 1 tomato (diced), 1 green chili, 1/2 tsp cumin, 1/4 tsp turmeric, 1 tsp coriander powder, 2 tbsp oil, salt, water as needed",
    
    // Vegetable Uttapam
    "1 cup idli batter, 1 onion (chopped), 1 tomato (diced), 1 carrot (grated), 2 tbsp coriander, 1 green chili, 1/2 tsp mustard seeds, oil for cooking",
    
    // Sabudana Khichdi
    "1 cup sabudana (soaked overnight), 1 potato (diced), 2 green chilies, 1/2 tsp cumin, 1 tbsp peanuts, 1 tsp sugar, 2 tbsp ghee, salt, fresh coconut for garnish",
    
    // Pongal
    "1 cup rice, 1/4 cup moong dal, 1 tsp cumin, 1/2 tsp pepper, 10 curry leaves, 2 tbsp ghee, 1 tbsp cashews, salt, water as needed",
    
    // Medu Vada
    "1 cup urad dal (soaked 4 hrs), 1 tbsp rice flour, 1/2 tsp cumin, 2 green chilies, 10 curry leaves, oil for frying, salt"
  },
  
  // Brunch
  {
    // Dhokla
    "1 cup besan, 1/2 cup yogurt, 1 tsp ginger-chili paste, 1/2 tsp turmeric, 1 tsp eno fruit salt, 1 tbsp oil, salt; For tempering: 1 tsp mustard seeds, 1 tsp sesame seeds, 10 curry leaves, 2 green chilies",
    
    // Khandvi
    "1 cup besan, 1/2 cup yogurt, 1 tsp ginger paste, 1/2 tsp turmeric, 1/4 tsp asafoetida, salt; For tempering: 1 tsp mustard seeds, 1 tsp coconut, 2 tbsp coriander",
    
    // Misal Pav
    "1 cup moth beans (matki), 1 onion, 1 tomato, 2 tbsp goda masala, 1/2 tsp turmeric, 1 tbsp tamarind, pav bread, sev, coriander, lemon, farsan",
    
    // Pav Bhaji
    "4 potatoes, 1 cup mixed vegetables (capsicum, peas, cauliflower), 2 tbsp pav bhaji masala, 1 tbsp butter, 1 onion, 1 tomato, pav bread, lemon, butter for serving",
    
    // Aloo Puri
    "2 cups wheat flour, 4 potatoes, 1 tsp cumin, 1/2 tsp amchur, 1/2 tsp garam masala, oil for frying, salt, water for dough",
    
    // Rava Idli
    "1 cup semolina, 1/2 cup yogurt, 1 tsp eno fruit salt, 1/2 tsp mustard seeds, 10 curry leaves, 2 tbsp grated carrot, 1 tbsp cashews, 1 tsp ghee",
    
    // Vegetable Frankie
    "4 rotis, 2 potatoes (mashed), 1 onion (sliced), 1 capsicum (sliced), 2 tbsp green chutney, 1 tbsp tamarind chutney, chaat masala, 1 tsp oil",
    
    // Dahi Vada
    "1 cup urad dal (soaked), 1/2 cup yogurt (whisked), 1 tsp cumin powder, 1/2 tsp red chili powder, 2 tbsp tamarind chutney, 1 tbsp mint chutney, salt",
    
    // Methi Thepla
    "2 cups wheat flour, 1/2 cup fresh fenugreek leaves, 1 green chili, 1/2 tsp turmeric, 1 tbsp oil, 1/2 tsp ajwain, salt, water for dough",
    
    // Mango Shrikhand
    "2 cups hung yogurt, 1 cup mango pulp, 1/4 tsp cardamom powder, 2 tbsp sugar, 1 tbsp chopped pistachios, 1 tsp saffron strands (soaked)"
  },
  
  // Lunch
  {
    // Dal Tadka-Rice
    "1 cup toor dal, 2 tomatoes, 1 onion, 2 green chilies, 1 tsp cumin, 1/2 tsp turmeric, 1 tsp garam masala, 2 tbsp ghee, 1 tsp mustard seeds, 10 curry leaves, coriander for garnish",
    
    // Rajma Chawal
    "1 cup rajma (soaked overnight), 2 onions, 3 tomatoes, 2 tbsp rajma masala, 1 tsp ginger-garlic paste, 1/2 tsp turmeric, 2 tbsp oil, fresh coriander",
    
    // Chole Bhature
    "1 cup chickpeas (soaked), 2 tea bags for dark color, 2 onions, 3 tomatoes, 2 tbsp chole masala, 1 tsp amchur; For bhature: 2 cups maida, 1/2 cup yogurt, oil for frying",
    
    // Vegetable Biryani
    "2 cups basmati rice, 1 cup mixed veggies (carrot, beans, potato, cauliflower), 1 onion, 2 tomatoes, 1/2 cup yogurt, 2 tbsp biryani masala, whole spices (bay leaf, cardamom, cinnamon), saffron milk",
    
    // Palak Paneer-Roti
    "2 bunches spinach, 200g paneer, 1 onion, 2 tomatoes, 1 tsp garam masala, 1/2 cup cream, 2 tbsp oil; For roti: 2 cups wheat flour, water, ghee",
    
    // Sambar-Rice
    "1 cup toor dal, 1 cup mixed vegetables (drumstick, carrot, brinjal), 2 tbsp sambar powder, small lemon-sized tamarind, 1 tsp jaggery, 1/2 tsp turmeric, curry leaves",
    
    // Kadhi Pakoda
    "1 cup besan, 1/2 cup yogurt, 1 onion (for pakodas), 1 tsp cumin, 1/2 tsp fenugreek seeds, 1 tbsp ghee, 1 tsp red chili powder, curry leaves",
    
    // Malai Kofta
    "3 potatoes, 1/2 cup paneer, 2 tbsp cornflour, 1 onion, 2 tomatoes, 1/2 cup cashew paste, 1 tsp garam masala, 1/2 cup cream, oil for frying",
    
    // Baingan Bharta
    "2 large brinjals, 2 onions, 3 tomatoes, 2 green chilies, 1 tsp cumin, 1/2 tsp turmeric, 1 tsp coriander powder, 2 tbsp oil, coriander leaves",
    
    // Mixed Vegetable Curry
    "1 cup mixed vegetables (potato, carrot, beans, peas), 1 onion, 2 tomatoes, 1 tsp ginger-garlic paste, 1/2 tsp turmeric, 1 tsp coriander powder, 1/2 cup coconut milk"
  },
  
  // Snacks
  {
    // Samosa
    "2 cups maida, 4 potatoes, 1/2 cup peas, 1 tsp cumin, 1 tsp coriander powder, 1/2 tsp garam masala, 1 tsp amchur, oil for frying",
    
    // Aloo Tikki
    "4 potatoes, 1/2 cup breadcrumbs, 1 tsp cumin, 1 tsp chaat masala, 1 green chili, 2 tbsp cornflour, oil for shallow frying",
    
    // Pani Puri
    "20 puris, 1 cup mashed potatoes, 1/2 cup boiled chickpeas, 1/2 cup tamarind chutney; For pani: mint leaves, coriander, green chili, black salt, cumin powder",
    
    // Bhel Puri
    "2 cups puffed rice, 1/2 cup sev, 1 onion (chopped), 1 tomato (chopped), 2 tbsp tamarind chutney, 1 tbsp green chutney, 1 tsp chaat masala, coriander",
    
    // Vegetable Pakora
    "1 cup besan, 1 potato (sliced), 1 onion (sliced), 1/2 cup spinach, 1 tsp ajwain, 1/2 tsp turmeric, oil for deep frying",
    
    // Kachori
    "2 cups maida, 1/2 cup urad dal (soaked), 1 tsp fennel seeds, 1 tsp coriander powder, 1/2 tsp red chili powder, oil for frying",
    
    // Dhokla
    "1 cup besan, 1/2 cup yogurt, 1 tsp ginger-chili paste, 1/2 tsp turmeric, 1 tsp eno fruit salt, 1 tbsp oil, salt; For tempering: 1 tsp mustard seeds, 1 tsp sesame seeds, 10 curry leaves, 2 green chilies",
    
    // Corn Chaat
    "1 cup boiled corn, 1 onion (chopped), 1 tomato (chopped), 1/2 cup sev, 1 tbsp green chutney, 1 tbsp tamarind chutney, chaat masala, lemon juice",
    
    // Pav Vada
    "4 pav bread, 4 potatoes (mashed), 2 tbsp coriander chutney, 1 tsp mustard seeds, 10 curry leaves, oil for frying; For batter: 1 cup besan, water",
    
    // Spring Rolls
    "10 spring roll sheets, 1 cup shredded cabbage, 1 carrot (julienned), 1 capsicum (julienned), 1 tsp soy sauce, 1 tsp vinegar, oil for frying"
  },
  
  // Dinner
  {
    // Khichdi
    "1 cup rice, 1/2 cup moong dal, 1 tsp cumin, 1/2 tsp turmeric, 2 tbsp ghee, 1 tsp ginger, vegetables (optional), salt",
    
    // Dal-Roti-Sabzi
    "1 cup toor dal, 2 cups chopped vegetables (bottle gourd, carrot, beans), 1 tsp cumin, 1/2 tsp turmeric; For roti: 2 cups wheat flour, water; For sabzi: any seasonal vegetable",
    
    // Vegetable Pulao
    "2 cups basmati rice, 1 cup mixed vegetables, 1 onion, 2 green chilies, whole spices (bay leaf, cardamom, cinnamon), 2 tbsp ghee",
    
    // Dahi Kadhi-Rice
    "1 cup besan, 2 cups yogurt, 1 tsp cumin, 1/2 tsp fenugreek seeds, 1 tbsp ghee, curry leaves; For pakodas: 1 onion, 1 green chili, besan",
    
    // Methi Malai Mutter
    "1 cup fenugreek leaves, 1 cup peas, 1/2 cup cream, 1 onion (paste), 1 tsp ginger-garlic paste, 1/2 tsp garam masala, 2 tbsp butter",
    
    // Vegetable Kofta Curry
    "3 potatoes, 1/2 cup mixed vegetables, 2 tbsp cornflour; For gravy: 2 onions, 2 tomatoes, 1 tsp garam masala, 1/2 cup cream",
    
    // Lauki Chana Dal
    "1 cup chana dal, 1 bottle gourd, 1 onion, 2 tomatoes, 1 tsp cumin, 1/2 tsp turmeric, 1 tsp coriander powder, 2 tbsp oil",
    
    // Bhindi Masala
    "250g bhindi (okra), 1 onion, 2 tomatoes, 1 tsp cumin, 1/2 tsp turmeric, 1 tsp coriander powder, 1/2 tsp amchur",
    
    // Aloo Jeera
    "4 potatoes (cubed), 1 tsp cumin, 1/2 tsp turmeric, 1 green chili, 1 tsp coriander powder, 2 tbsp oil, coriander leaves",
    
    // Mix Veg Jalfrezi
    "1 cup mixed vegetables (capsicum, carrot, beans), 1 onion, 2 tomatoes, 1 tsp ginger-garlic paste, 1 tsp soy sauce, 1 tsp vinegar, 1/2 tsp garam masala"
  },
  
  // Midnight Meal
  {
    // Milk-Banana
    "1 glass milk, 1 banana, 1 tsp honey (optional), 2-3 almonds (chopped), pinch of cardamom powder",
    
    // Toast-Jam
    "2 slices bread, 2 tbsp jam (any flavor), 1 tsp butter (optional)",
    
    // Poha
    "Same as breakfast section (smaller portion)",
    
    // Upma
    "Same as breakfast section (smaller portion)",
    
    // Cornflakes
    "1 cup cornflakes, 1 cup milk, 1 tsp sugar (optional), few chopped nuts",
    
    // Fruit Salad
    "1 banana, 1 apple, 1/2 cup pomegranate, 1/2 cup grapes, 1 tsp honey, pinch of chaat masala (optional)",
    
    // Sabudana Khichdi
    "Same as breakfast section (smaller portion)",
    
    // Vermicelli Upma
    "1 cup vermicelli, 1/2 onion (chopped), 1 green chili, 1/2 tsp mustard seeds, 10 curry leaves, 1 tbsp oil",
    
    // Bread Pakora
    "4 bread slices, 1 cup besan, 1/2 tsp turmeric, 1 tsp red chili powder, 1 tsp ajwain, oil for frying",
    
    // Dahi-Chiwda
    "1 cup beaten yogurt, 1 cup chiwda (flattened rice), 1 tsp roasted cumin powder, 1/2 tsp black salt, 1 tsp sugar"
  }
};

const char* recipeSteps[6][10][10] = {
  // Breakfast
  {
    // Masala Poha
    {
      "1. Rinse poha in water and drain immediately. Keep aside.",
      "2. Heat oil in pan. Add mustard seeds, let splutter. Add peanuts, curry leaves, green chilies.",
      "3. Add chopped onions, sauté till translucent. Add diced potatoes, turmeric, salt. Cover and cook till potatoes are done.",
      "4. Add drained poha, mix gently. Sprinkle little water if too dry. Cover and cook on low heat for 2-3 mins.",
      "5. Turn off heat. Add lemon juice, chopped coriander. Mix well. Serve hot with tea.",
      "", "", "", "", ""
    },
    
    // Upma
    {
      "1. Dry roast semolina in pan till fragrant. Keep aside.",
      "2. Heat ghee in same pan. Add mustard seeds, urad dal, curry leaves. Let dal turn golden.",
      "3. Add chopped onions, green chilies. Sauté till onions turn pink.",
      "4. Add chopped vegetables (carrot, tomato). Cook for 2 mins.",
      "5. Add 2 cups water, salt. Bring to boil. Reduce heat.",
      "6. Slowly add roasted semolina while stirring continuously to avoid lumps.",
      "7. Cover and cook on low heat for 3-4 mins till upma leaves sides of pan.",
      "8. Add lemon juice, mix well. Garnish with coriander. Serve hot.",
      "", ""
    },
    
    // Idli-Sambar
    {
      "1. Soak rice and urad dal separately for 4-6 hours with fenugreek seeds.",
      "2. Grind urad dal to fluffy batter. Grind rice coarsely. Mix both with salt.",
      "3. Ferment overnight (8-10 hrs) in warm place till batter doubles.",
      "4. Grease idli moulds, pour batter. Steam for 10-12 mins.",
      "5. For sambar: Pressure cook dal with turmeric. Cook vegetables separately.",
      "6. Mix dal, vegetables. Add sambar powder, tamarind extract, jaggery.",
      "7. Temper with mustard seeds, curry leaves. Garnish with coriander.",
      "8. Serve hot idlis with sambar and coconut chutney.",
      "", ""
    },
    
    // Aloo Paratha
    {
      "1. Knead wheat flour with water to make soft dough. Rest for 15 mins.",
      "2. Mash boiled potatoes. Add cumin, red chili powder, coriander powder, salt.",
      "3. Divide dough into lemon-sized balls. Roll one ball into small circle.",
      "4. Place potato stuffing in center. Bring edges together to seal.",
      "5. Dust with flour and roll gently into thick paratha.",
      "6. Heat tawa. Cook paratha on both sides with ghee till golden spots appear.",
      "7. Serve hot with yogurt, pickle or butter.",
      "", "", ""
    },
    
    // Mysore Masala Dosa
    {
      "1. Soak rice and dal separately for 4-6 hours with fenugreek seeds.",
      "2. Grind to smooth batter. Ferment overnight (8-10 hrs).",
      "3. For masala: Cook potatoes with mustard seeds, turmeric, curry leaves.",
      "4. For chutney: Grind coconut with roasted chana dal, red chilies, tamarind.",
      "5. Heat dosa tawa. Pour ladle of batter, spread in circular motion.",
      "6. Drizzle oil, cook till crisp. Spread red chutney, place potato masala.",
      "7. Fold dosa. Serve with sambar and coconut chutney.",
      "", "", ""
    },
    
    // Besan Chilla
    {
      "1. Mix besan with water to make lump-free batter of pouring consistency.",
      "2. Add chopped onions, tomatoes, green chili, coriander, spices.",
      "3. Heat tawa. Pour ladle of batter, spread like dosa.",
      "4. Drizzle oil around edges. Cook till golden on both sides.",
      "5. Serve hot with green chutney or ketchup.",
      "", "", "", "", ""
    },
    
    // Vegetable Uttapam
    {
      "1. Prepare idli batter as per earlier steps.",
      "2. Mix chopped onions, tomatoes, carrot, coriander in bowl.",
      "3. Heat tawa. Pour ladle of batter, don't spread too thin.",
      "4. Immediately sprinkle vegetable mix on top. Press gently.",
      "5. Drizzle oil around edges. Cook covered for 2 mins.",
      "6. Flip carefully. Cook other side for 1 min.",
      "7. Serve hot with sambar or chutney.",
      "", "", ""
    },
    
    // Sabudana Khichdi
    {
      "1. Soak sabudana in just enough water to cover for 4-5 hrs or overnight.",
      "2. Heat ghee. Add cumin, peanuts. Let peanuts turn golden.",
      "3. Add chopped green chilies, curry leaves. Sauté for 30 secs.",
      "4. Add diced potatoes. Cook covered till potatoes are done.",
      "5. Add soaked sabudana, salt, sugar. Mix gently.",
      "6. Cook covered on low heat for 5-7 mins, stirring occasionally.",
      "7. Garnish with fresh coconut and coriander. Serve hot.",
      "", "", ""
    },
    
    // Pongal
    {
      "1. Wash rice and dal together. Pressure cook with 4 cups water for 3 whistles.",
      "2. Heat ghee in pan. Add cumin, pepper, curry leaves, cashews.",
      "3. When cashews turn golden, add cooked rice-dal mixture.",
      "4. Add salt, mix well. Add more water if too thick.",
      "5. Cook on low heat for 5 mins, stirring occasionally.",
      "6. Serve hot with sambar or coconut chutney.",
      "", "", "", ""
    },
    
    // Medu Vada
    {
      "1. Grind soaked urad dal to smooth fluffy batter with minimal water.",
      "2. Add chopped green chilies, curry leaves, cumin, salt.",
      "3. Heat oil for frying. Wet hands, take lemon-sized batter.",
      "4. Make hole in center (donut shape) and gently drop in hot oil.",
      "5. Fry on medium heat till golden brown and crisp.",
      "6. Drain on paper towel. Serve hot with sambar and chutney.",
      "", "", "", ""
    }
  },
  
  // Brunch
  {
    // Dhokla
    {
      "1. Mix besan, yogurt, ginger-chili paste, turmeric, salt with water to make batter.",
      "2. Just before steaming, add eno fruit salt. Mix gently.",
      "3. Pour into greased thali. Steam for 15-20 mins.",
      "4. Check with knife - if comes out clean, it's done.",
      "5. For tempering: Heat oil, add mustard seeds, sesame seeds, curry leaves, green chilies.",
      "6. Pour tempering over dhokla. Cut into squares.",
      "7. Garnish with coriander and grated coconut.",
      "8. Serve with green chutney.",
      "", ""
    },
    
    // Khandvi
    {
      "1. Mix besan, yogurt, ginger paste, turmeric, salt with water to make smooth batter.",
      "2. Cook on low heat, stirring continuously till thick paste forms (5-7 mins).",
      "3. Spread thin layer on greased surface. Let cool for 5 mins.",
      "4. Cut into strips, roll carefully.",
      "5. For tempering: Heat oil, add mustard seeds, sesame seeds.",
      "6. Pour over khandvi rolls. Garnish with coconut and coriander.",
      "7. Serve at room temperature.",
      "", "", ""
    },
    
    // Misal Pav
    {
      "1. Pressure cook soaked matki with turmeric and salt till soft.",
      "2. Heat oil, add chopped onions, goda masala, cooked matki.",
      "3. Add tamarind water, jaggery. Simmer for 10 mins.",
      "4. For serving: Place misal in bowl, top with chopped onions, coriander.",
      "5. Add sev, farsan. Serve with pav bread and lemon wedge.",
      "", "", "", "", ""
    },
    
    // Pav Bhaji
    {
      "1. Pressure cook potatoes and mixed vegetables till soft. Mash well.",
      "2. Heat butter, add chopped onions. Sauté till golden.",
      "3. Add chopped tomatoes, pav bhaji masala. Cook till tomatoes soften.",
      "4. Add mashed vegetables. Mix well. Add water for desired consistency.",
      "5. Cook for 10-15 mins on low heat, stirring occasionally.",
      "6. Garnish with coriander, butter, lemon juice.",
      "7. Serve hot with buttered pav bread.",
      "", "", ""
    },
    
    // Aloo Puri
    {
      "1. Knead wheat flour with water to make stiff dough. Rest for 15 mins.",
      "2. For stuffing: Mash boiled potatoes. Add cumin, amchur, garam masala, salt.",
      "3. Divide dough into balls. Roll one ball, place potato stuffing, seal.",
      "4. Roll gently into thick puri.",
      "5. Heat oil. Deep fry puri, pressing gently till it puffs up.",
      "6. Drain on paper towel. Serve hot with pickle or yogurt.",
      "", "", "", ""
    },
    
    // Rava Idli
    {
      "1. Dry roast semolina till fragrant. Let cool.",
      "2. Mix with yogurt, water to make thick batter. Rest for 20 mins.",
      "3. Add eno fruit salt just before steaming. Mix gently.",
      "4. Pour into greased idli moulds. Top with grated carrot, cashews.",
      "5. Steam for 12-15 mins till done.",
      "6. Serve hot with coconut chutney and sambar.",
      "", "", "", ""
    },
    
    // Vegetable Frankie
    {
      "1. Heat oil in pan. Add cumin, chopped onions, capsicum. Sauté.",
      "2. Add mashed potatoes, spices. Mix well. Keep aside.",
      "3. Warm rotis on tawa. Spread green chutney on one side.",
      "4. Place vegetable mixture in center. Drizzle tamarind chutney.",
      "5. Sprinkle chaat masala. Roll tightly.",
      "6. Wrap lower half in paper. Serve hot.",
      "", "", "", ""
    },
    
    // Dahi Vada
    {
      "1. Grind soaked urad dal to smooth batter. Add salt.",
      "2. Make small balls, deep fry till golden. Soak in water for 15 mins.",
      "3. Squeeze out water gently. Arrange in serving dish.",
      "4. Whisk yogurt with salt, roasted cumin powder.",
      "5. Pour over vadas. Top with tamarind and mint chutney.",
      "6. Garnish with red chili powder and coriander.",
      "7. Serve chilled.",
      "", "", ""
    },
    
    // Methi Thepla
    {
      "1. Mix wheat flour, chopped methi leaves, spices, oil.",
      "2. Add water gradually to make soft dough. Rest for 15 mins.",
      "3. Divide into balls. Roll into thin circles.",
      "4. Cook on tawa with little oil till golden spots appear.",
      "5. Serve hot with yogurt or pickle.",
      "", "", "", "", ""
    },
    
    // Mango Shrikhand
    {
      "1. Hang yogurt in muslin cloth for 4-5 hrs to remove whey.",
      "2. Mix hung yogurt with mango pulp, sugar, cardamom powder.",
      "3. Chill for 1-2 hrs.",
      "4. Garnish with chopped pistachios and saffron.",
      "5. Serve cold.",
      "", "", "", "", ""
    }
  },
  
  // Lunch (showing first 2 for brevity)
  {
    // Dal Tadka-Rice
    {
      "1. Pressure cook toor dal with turmeric till soft.",
      "2. Heat ghee, add cumin, mustard seeds, curry leaves.",
      "3. Add chopped onions, green chilies. Sauté till golden.",
      "4. Add chopped tomatoes, cook till mushy.",
      "5. Add cooked dal, salt, water. Simmer for 10 mins.",
      "6. Add garam masala. Garnish with coriander.",
      "7. Serve hot with steamed rice and ghee.",
      "", "", ""
    },
    
    // Rajma Chawal
    {
      "1. Soak rajma overnight. Pressure cook with salt till soft.",
      "2. Heat oil, add cumin, chopped onions. Sauté till golden.",
      "3. Add ginger-garlic paste, chopped tomatoes, spices.",
      "4. Cook till oil separates. Add cooked rajma, water.",
      "5. Simmer for 15-20 mins till gravy thickens.",
      "6. Garnish with coriander. Serve hot with rice.",
      "", "", "", ""
    },
    // Chole Bhature
    {
      "1. Soak chickpeas overnight with tea bags for color. Pressure cook with salt till soft.",
      "2. Heat oil, add cumin, chopped onions. Sauté till golden.",
      "3. Add ginger-garlic paste, chopped tomatoes, chole masala.",
      "4. Cook till oil separates. Add cooked chickpeas, water.",
      "5. Simmer for 15 mins. Add amchur. Mash few chickpeas for thickness.",
      "6. For bhature: Mix maida, yogurt, salt to make soft dough. Rest for 2 hrs.",
      "7. Divide into balls, roll into circles. Deep fry till puffed.",
      "8. Garnish chole with ginger slices, coriander.",
      "9. Serve hot with bhature, onions, lemon wedges.",
      ""
    },
    
    // Vegetable Biryani
    {
      "1. Soak basmati rice for 30 mins. Parboil with whole spices. Drain.",
      "2. Heat ghee, add sliced onions. Fry till golden. Remove half for garnish.",
      "3. Add ginger-garlic paste, chopped vegetables. Sauté for 2 mins.",
      "4. Add yogurt, biryani masala, salt. Cook for 5 mins.",
      "5. Layer rice over vegetables in heavy bottomed pan.",
      "6. Sprinkle saffron milk, fried onions, coriander, mint.",
      "7. Cover with tight lid. Cook on dum (low heat) for 20 mins.",
      "8. Let rest for 10 mins before opening. Mix gently.",
      "9. Serve hot with raita.",
      ""
    },
    
    // Palak Paneer-Roti
    {
      "1. Blanch spinach in boiling water for 2 mins. Blend to smooth paste.",
      "2. Heat oil, add cumin, chopped onions. Sauté till translucent.",
      "3. Add ginger-garlic paste, chopped tomatoes. Cook till mushy.",
      "4. Add spinach puree, garam masala, salt. Simmer for 10 mins.",
      "5. Add paneer cubes, cream. Cook for 5 more mins.",
      "6. For roti: Knead wheat flour with water to make stiff dough.",
      "7. Divide into balls, roll into circles. Cook on tawa till brown spots.",
      "8. Apply ghee. Serve hot with palak paneer.",
      "", ""
    },
    
    // Sambar-Rice
    {
      "1. Pressure cook toor dal with turmeric till soft. Mash slightly.",
      "2. Cook chopped vegetables in tamarind water with sambar powder.",
      "3. Mix cooked dal and vegetables. Add jaggery, salt.",
      "4. For tempering: Heat oil, add mustard seeds, curry leaves, red chili.",
      "5. Pour tempering over sambar. Garnish with coriander.",
      "6. Serve hot with steamed rice and ghee.",
      "", "", "", ""
    },
    
    // Kadhi Pakoda
    {
      "1. Mix besan and yogurt with water to make smooth batter.",
      "2. Heat oil, add fenugreek seeds, cumin, curry leaves, ginger.",
      "3. Add besan-yogurt mixture, turmeric, salt. Simmer for 20 mins.",
      "4. For pakodas: Mix besan, chopped onions, spices with water.",
      "5. Make small balls, deep fry till golden. Add to kadhi.",
      "6. Temper with ghee, red chili powder. Serve with rice.",
      "", "", "", ""
    },
    
    // Malai Kofta
    {
      "1. Boil and mash potatoes. Mix with crumbled paneer, cornflour, salt.",
      "2. Make balls, stuff with cashew pieces. Deep fry till golden.",
      "3. For gravy: Sauté onion paste in butter till golden.",
      "4. Add tomato puree, cashew paste, spices. Cook till oil separates.",
      "5. Add cream, water. Simmer for 10 mins.",
      "6. Add koftas just before serving. Garnish with cream.",
      "7. Serve hot with naan or roti.",
      "", "", ""
    },
    
    // Baingan Bharta
    {
      "1. Roast whole brinjal on direct flame till charred and soft.",
      "2. Peel skin, mash pulp. Keep aside.",
      "3. Heat oil, add cumin, chopped onions. Sauté till golden.",
      "4. Add ginger-garlic paste, chopped tomatoes. Cook till mushy.",
      "5. Add mashed brinjal, turmeric, coriander powder, salt.",
      "6. Cook for 10-15 mins on low heat. Garnish with coriander.",
      "7. Serve hot with roti or paratha.",
      "", "", ""
    },
    
    // Mixed Vegetable Curry
    {
      "1. Heat oil, add cumin, chopped onions. Sauté till golden.",
      "2. Add ginger-garlic paste, chopped tomatoes. Cook till soft.",
      "3. Add turmeric, coriander powder, chopped vegetables.",
      "4. Sauté for 2 mins. Add coconut milk, water, salt.",
      "5. Cook covered till vegetables are done.",
      "6. Garnish with coriander. Serve hot with rice or roti.",
      "", "", "", ""
    }
  },
  
  // Snacks
  {
    // Samosa
    {
        "1. Knead maida with oil, water to make stiff dough. Rest for 30 mins.",
        "2. For filling: Boil potatoes. Heat oil, add cumin, chopped onions, peas.",
        "3. Add mashed potatoes, spices. Mix well. Cool.",
        "4. Roll dough into circles, cut in half. Make cone, add filling.",
        "5. Seal edges with water. Deep fry till golden.",
        "6. Serve hot with chutney.",
        "", "", "", ""
      },
    // Aloo Tikki
    {
        "1. Boil and mash potatoes. Add breadcrumbs, spices, salt.",
        "2. Make flat round patties. Coat with cornflour.",
        "3. Shallow fry in oil till golden and crisp on both sides.",
        "4. Serve hot with chutney, yogurt, chopped onions.",
        "", "", "", "", "", ""
      },
    // Pani Puri
    {
      "1. For pani: Blend mint, coriander, green chili, ginger with water.",
      "2. Strain. Add black salt, roasted cumin powder, lemon juice.",
      "3. For stuffing: Mix mashed potatoes, boiled chickpeas, spices.",
      "4. Make small hole in each puri using thumb.",
      "5. Stuff with potato mixture, dip in pani.",
      "6. Eat immediately before puri gets soggy.",
      "", "", "", ""
    },
    
    // Bhel Puri
    {
      "1. Mix puffed rice, chopped onions, tomatoes in large bowl.",
      "2. Add sev, chopped coriander, chaat masala.",
      "3. Add tamarind chutney and green chutney as per taste.",
      "4. Squeeze lemon juice. Mix gently.",
      "5. Serve immediately in paper cones garnished with more sev.",
      "", "", "", "", ""
    },
    
    // Vegetable Pakora
    {
      "1. Mix besan with ajwain, turmeric, red chili powder, salt.",
      "2. Add water gradually to make thick batter.",
      "3. Dip sliced vegetables (potato, onion, spinach) in batter.",
      "4. Deep fry in hot oil till golden and crisp.",
      "5. Drain on paper towel. Serve hot with chutney.",
      "", "", "", "", ""
    },
    
    // Kachori
    {
      "1. Soak urad dal for 2 hrs. Grind coarsely with spices.",
      "2. Heat oil, add cumin, asafoetida. Add dal mixture.",
      "3. Cook till dry. Cool. This is the filling.",
      "4. Knead maida with oil, water to make stiff dough.",
      "5. Make small balls, stuff with filling, roll into circles.",
      "6. Deep fry on medium heat till golden and crisp.",
      "7. Serve hot with chutney.",
      "", ""
    },
    
    // Dhokla
    {
        "1. Mix besan, yogurt, ginger-chili paste, turmeric, salt with water to make batter.",
        "2. Just before steaming, add eno fruit salt. Mix gently.",
        "3. Pour into greased thali. Steam for 15-20 mins.",
        "4. Check with knife - if comes out clean, it's done.",
        "5. For tempering: Heat oil, add mustard seeds, sesame seeds, curry leaves, green chilies.",
        "6. Pour tempering over dhokla. Cut into squares.",
        "7. Garnish with coriander and grated coconut.",
        "8. Serve with green chutney.",
        "", ""
      },

    // Corn Chaat
    {
      "1. Boil sweet corn kernels till soft. Drain.",
      "2. Mix with chopped onions, tomatoes, cucumber.",
      "3. Add both chutneys, chaat masala, lemon juice.",
      "4. Garnish with sev and coriander.",
      "5. Serve immediately.",
      "", "", "", "", ""
    },
    
    // Pav Vada
    {
      "1. Boil and mash potatoes. Add spices, chopped onions, coriander.",
      "2. Make flat patties. Dip in besan batter, deep fry till golden.",
      "3. Slice pav bread horizontally, apply chutney on both sides.",
      "4. Place vada between pav. Press gently.",
      "5. Serve hot with more chutney.",
      "", "", "", "", ""
    },
    
    // Spring Rolls
    {
      "1. Heat oil, add chopped garlic. Sauté shredded vegetables.",
      "2. Add soy sauce, vinegar, salt, pepper. Cook for 2 mins.",
      "3. Cool filling completely.",
      "4. Place spoonful on spring roll sheet, fold sides, roll tightly.",
      "5. Seal edge with cornflour paste.",
      "6. Deep fry till golden and crisp.",
      "7. Serve hot with schezwan sauce.",
      "", ""
    }
  },
  
  // Dinner
  {
    // Khichdi
    {
        "1. Wash rice and dal together. Soak for 15 mins.",
        "2. Heat ghee, add cumin, ginger, whole spices.",
        "3. Add drained rice-dal, turmeric, salt. Sauté for 2 mins.",
        "4. Add water (1:3 ratio). Pressure cook for 3 whistles.",
        "5. Let pressure release naturally. Mix gently.",
        "6. Serve hot with ghee, yogurt and pickle.",
        "", "", "", ""
      },
    // Dal-Roti-Sabzi
    {
        "1. Cook dal with turmeric. Mash slightly.",
        "2. For sabzi: Heat oil, add cumin, chopped vegetables.",
        "3. Add spices, little water. Cook covered till done.",
        "4. For roti: Knead dough, divide into balls.",
        "5. Roll into circles, cook on tawa till puffed.",
        "6. Serve hot dal with roti and sabzi.",
        "", "", "", ""
      },
    
    // Vegetable Pulao
    {
      "1. Soak basmati rice for 20 mins. Drain.",
      "2. Heat ghee, add whole spices (bay leaf, cardamom, cinnamon).",
      "3. Add sliced onions, sauté till golden. Add chopped vegetables.",
      "4. Add drained rice. Sauté for 2 mins.",
      "5. Add water (1:1.5 ratio), salt. Cook covered on low heat.",
      "6. When done, fluff with fork. Garnish with fried onions.",
      "7. Serve hot with raita.",
      "", "", ""
    },
    
    // Dahi Kadhi-Rice
    {
      "1. Mix besan and yogurt with water to make smooth batter.",
      "2. Heat ghee, add fenugreek seeds, cumin, curry leaves, ginger.",
      "3. Add besan-yogurt mixture, turmeric, salt. Simmer for 20 mins.",
      "4. For pakodas: Mix besan, chopped onions, spices with water.",
      "5. Make small balls, deep fry till golden. Add to kadhi.",
      "6. Temper with ghee, red chili powder. Serve with rice.",
      "", "", "", ""
    },
    
    // Methi Malai Mutter
    {
      "1. Blanch fenugreek leaves in hot water for 2 mins. Drain, chop.",
      "2. Heat butter, add onion paste. Sauté till golden.",
      "3. Add ginger-garlic paste, tomato puree. Cook till oil separates.",
      "4. Add fresh peas, fenugreek leaves, garam masala, salt.",
      "5. Add fresh cream. Simmer for 5 mins.",
      "6. Serve hot with naan or paratha.",
      "", "", "", ""
    },
    
    // Vegetable Kofta Curry
    {
      "1. Boil and mash potatoes. Mix with grated vegetables, cornflour.",
      "2. Make balls, stuff with paneer pieces. Deep fry till golden.",
      "3. For gravy: Sauté onion paste in oil till golden.",
      "4. Add tomato puree, cashew paste, spices. Cook till oil separates.",
      "5. Add water, cream. Simmer for 10 mins.",
      "6. Add koftas just before serving. Garnish with cream.",
      "7. Serve hot with naan or roti.",
      "", ""
    },
    
    // Lauki Chana Dal
    {
      "1. Pressure cook chana dal with turmeric till soft.",
      "2. Heat oil, add cumin, chopped bottle gourd. Sauté for 2 mins.",
      "3. Add chopped onions, tomatoes, spices. Cook till soft.",
      "4. Add cooked dal, water. Simmer for 10 mins.",
      "5. Garnish with coriander. Serve hot with roti.",
      "", "", "", "", ""
    },
    
    // Bhindi Masala
    {
      "1. Wash and dry bhindi thoroughly. Cut into 1-inch pieces.",
      "2. Heat oil, add cumin, chopped onions. Sauté till golden.",
      "3. Add chopped bhindi. Cook on medium heat without stirring much.",
      "4. When bhindi is half cooked, add chopped tomatoes, spices.",
      "5. Cook covered for 5 mins. Add amchur.",
      "6. Garnish with coriander. Serve hot with roti.",
      "", "", "", ""
    },
    
    // Aloo Jeera
    {
      "1. Boil and cube potatoes. Keep aside.",
      "2. Heat oil, add cumin seeds. Let them splutter.",
      "3. Add chopped green chilies, boiled potatoes.",
      "4. Add turmeric, red chili powder, salt. Mix gently.",
      "5. Cook on low heat till potatoes are lightly crisp.",
      "6. Garnish with coriander. Serve hot with roti.",
      "", "", "", ""
    },
    
    // Mix Veg Jalfrezi
    {
      "1. Heat oil, add cumin, chopped onions, capsicum. Sauté on high heat.",
      "2. Add other vegetables (carrot, beans). Stir fry for 2 mins.",
      "3. Add ginger-garlic paste, soy sauce, vinegar, spices.",
      "4. Toss well. Add sliced tomatoes. Cook for 1 min.",
      "5. Garnish with spring onions. Serve hot with noodles or rice.",
      "", "", "", "", ""
    }
  },
  
  // Midnight Meal
  {
    // Milk-Banana
    {
        "1. Warm milk slightly (optional).",
        "2. Slice banana into milk.",
        "3. Add honey, cardamom powder, chopped nuts.",
        "4. Mix gently. Serve.",
        "", "", "", "", "", ""
    },
    // Toast-Jam (already shown)
    {
        "1. Toast bread slices till golden.",
        "2. Spread butter (optional).",
        "3. Add jam evenly on slices.",
        "4. Cut diagonally. Serve.",
        "", "", "", "", "", ""
    },

    // Poha
    {
      "1. Rinse poha briefly, drain completely.",
      "2. Heat little ghee in pan. Add peanuts, roast till golden.",
      "3. Add mustard seeds, curry leaves, chopped green chili.",
      "4. Add chopped onions, sauté till translucent.",
      "5. Add turmeric, salt, sugar. Mix well.",
      "6. Add poha, mix gently. Cover and cook for 2 mins.",
      "7. Garnish with coriander and lemon juice.",
      "8. Serve warm.",
      "", ""
    },
    
    // Upma
    {
      "1. Dry roast rava till fragrant. Keep aside.",
      "2. Heat ghee, add mustard seeds, urad dal, curry leaves.",
      "3. Add chopped onions, green chili. Sauté till onions turn pink.",
      "4. Add 2 cups water, salt. Bring to boil.",
      "5. Slowly add roasted rava while stirring continuously.",
      "6. Cover and cook on low heat for 3-4 mins.",
      "7. Add lemon juice, mix well. Serve hot.",
      "", "", ""
    },
    
    // Cornflakes
    {
      "1. Take cornflakes in bowl.",
      "2. Add cold or warm milk as preferred.",
      "3. Sprinkle sugar if desired.",
      "4. Add chopped nuts or fruits (optional).",
      "5. Serve immediately before flakes get soggy.",
      "", "", "", "", ""
    },
    
    // Fruit Salad
    {
      "1. Chop all fruits into bite-sized pieces.",
      "2. Mix gently in large bowl.",
      "3. Add honey or sugar if needed.",
      "4. Sprinkle chaat masala for tangy version (optional).",
      "5. Chill for 30 mins before serving.",
      "", "", "", "", ""
    },
    
    // Sabudana Khichdi (same as breakfast section)
    
    // Vermicelli Upma
    {
      "1. Dry roast vermicelli till golden. Keep aside.",
      "2. Heat oil, add mustard seeds, urad dal, curry leaves.",
      "3. Add chopped onions, green chili. Sauté till onions turn pink.",
      "4. Add 2 cups water, salt. Bring to boil.",
      "5. Add roasted vermicelli. Cook covered on low heat.",
      "6. When done, fluff with fork. Serve hot.",
      "", "", "", ""
    },
    
    // Bread Pakora
    {
      "1. Mix besan with turmeric, red chili powder, ajwain, salt.",
      "2. Add water to make thick batter.",
      "3. Cut bread slices into triangles.",
      "4. Dip each piece in batter, coating well.",
      "5. Deep fry till golden and crisp.",
      "6. Serve hot with chutney or ketchup.",
      "", "", "", ""
    },
    
    // Dahi-Chiwda
    {
      "1. Rinse chiwda briefly, drain well.",
      "2. Whisk yogurt with roasted cumin powder, black salt, sugar.",
      "3. Mix chiwda with yogurt mixture.",
      "4. Garnish with chopped coriander.",
      "5. Serve chilled.",
      "", "", "", "", ""
    }
  }
};