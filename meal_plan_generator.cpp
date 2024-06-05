/*
 * @file group project.cpp
 * @authors Jason, Ho, Mo, Jacob
 * @brief group project
 * @version 1.01
 * @date 2023-12-5
 * 
 * @copyright Copyright (c) 2023
 * 
 * @description This program asks the user for the health info and nutrition goal and then generates daily macros and calories, as well as meals that fit with the macros and calories.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//food class with data types
class Food {
    public:
        string name;
        double servingSize;
        double calories;
        double protein;
        double carbs;
        double fat;
    };

//the following are subclasses for types of food as used by our program, they inherit the qualities of their parent class, food

class ProteinSource: public Food {

};

class CarbSource: public Food {

};

class FatSource: public Food {

};

class Vegetable: public Food {

};

class Fruit: public Food {

};

//these variables hold user info
double weight, height, age;
int goal, activityLevel, sex;

//BMR (basal metabolic rate) is calories needed without exercise
double BMR;

//amount of total calories and calories from each macro needed for the day
double caloriesNeeded, proteinCaloriesNeeded, carbsCaloriesNeeded, fatCaloriesNeeded;

//amount of grams of each macro needed for the day
double proteinGramsNeeded, carbsGramsNeeded, fatGramsNeeded;

//amount of meals, calories in each meal and macro grams in each meal
double meals, caloriesPerMeal, proteinGramsPerMeal, carbsGramsPerMeal, fatGramsPerMeal;

double totalCalorieCount, totalProteinCount, totalCarbsCount, totalFatCount;

int restrictions, userChoice;
bool stop = false, vegetarian = false, glutenFree = false, nutAllergy = false;

//protein from fruits and vegetables
double extraProtein, extraCarbs, extraCalories, extraFat;


//macronutrient ratios as a percent of calories
const double CARB_PERCENT = 0.45, PROTEIN_PERCENT = 0.25, FAT_PERCENT = 0.3;

void getInfo();
void calculateMacros();

//main function
int main() {

  getInfo();

  calculateMacros();
    
  cout << endl << "Your plan is listed below." << endl << endl;

  //food objects

    //protein sources
  
    ProteinSource chicken;
    chicken.name = "chicken";
    chicken.servingSize = 100;
    chicken.calories = 165;
    chicken.protein = 31;
    chicken.carbs = 0;
    chicken.fat = 3.6;

    ProteinSource steak;
    steak.name = "steak";
    steak.servingSize = 100;
    steak.calories = 150;
    steak.protein = 26;
    steak.carbs = 0;
    steak.fat = 4.3;

    ProteinSource salmon; 
    salmon.name = "salmon";
    salmon.servingSize = 100;
    salmon.calories = 169;
    salmon.protein = 25.4;
    salmon.carbs = 0;
    salmon.fat = 6.7;

    ProteinSource tofu; 
    tofu.name = "tofu";
    tofu.servingSize = 100;
    tofu.calories = 83;
    tofu.protein = 10;
    tofu.carbs = 1.2;
    tofu.fat = 5.3;
  
    ProteinSource turkey; 
    turkey.name = "turkey";
    turkey.servingSize = 100;
    turkey.calories = 189.4;
    turkey.protein = 28.3;
    turkey.carbs = 0.1;
    turkey.fat = 7.4;
  
    ProteinSource ham; 
    ham.name = "ham";
    ham.servingSize = 100;
    ham.calories = 138.8;
    ham.protein = 22.4;
    ham.carbs = 1;
    ham.fat = 5.1;
  
    ProteinSource greekYogurt; 
    greekYogurt.name = "greek yogurt";
    greekYogurt.servingSize = 100;
    greekYogurt.calories = 59.1;
    greekYogurt.protein = 10.3;
    greekYogurt.carbs = 3.5;
    greekYogurt.fat = 0.4;
  
    ProteinSource egg; 
    egg.name = "egg";
    egg.servingSize = 100;
    egg.calories = 144;
    egg.protein = 12.6;
    egg.carbs = 0.7;
    egg.fat = 9.6;
  
  
    //carb sources
  
    CarbSource whiteRice;
    whiteRice.name = "white rice";
    whiteRice.servingSize = 100;
    whiteRice.calories = 130;
    whiteRice.protein = 2.4;
    whiteRice.carbs = 28.6;
    whiteRice.fat = 0.2;

    CarbSource potato;
    potato.name = "potato";
    potato.servingSize = 100;
    potato.calories = 87;
    potato.protein = 1.9;
    potato.carbs = 20.1;
    potato.fat = 0.1;

    CarbSource corn;
    corn.name = "corn";
    corn.servingSize = 100;
    corn.calories = 71;
    corn.protein = 2.3;
    corn.carbs = 15.1;
    corn.fat = 1.4;

    CarbSource wholeWheatBread;
    wholeWheatBread.name = "whole wheat bread";
    wholeWheatBread.servingSize = 100;
    wholeWheatBread.calories = 253.1;
    wholeWheatBread.protein = 12.5;
    wholeWheatBread.carbs = 43.8;
    wholeWheatBread.fat = 3.4;
  
    CarbSource oats;
    oats.name = "oats";
    oats.servingSize = 100;
    oats.calories = 373.3;
    oats.protein = 12.9;
    oats.carbs = 65.9;
    oats.fat = 6.3;
  
    CarbSource blackBeans;
    blackBeans.name = "black beans";
    blackBeans.servingSize = 100;
    blackBeans.calories = 132;
    blackBeans.protein = 8.7;
    blackBeans.carbs = 23.8;
    blackBeans.fat = 0.5;
  
    CarbSource lentils;
    lentils.name = "lentils";
    lentils.servingSize = 100;
    lentils.calories = 114.1;
    lentils.protein = 9.1;
    lentils.carbs = 19.7;
    lentils.fat = 0.4;
  
    CarbSource brownRice;
    brownRice.name = "brown rice";
    brownRice.servingSize = 100;
    brownRice.calories = 111.2;
    brownRice.protein = 2.3;
    brownRice.carbs = 23.5;
    brownRice.fat = 0.8;
  
    CarbSource quinoa;
    quinoa.name = "quinoa";
    quinoa.servingSize = 100;
    quinoa.calories = 119.3;
    quinoa.protein = 4.4;
    quinoa.carbs = 21.5;
    quinoa.fat = 1.9;
  
    
    //fat sources
  
    FatSource oliveOil; 
    oliveOil.name = "olive oil";
    oliveOil.servingSize = 4.5;
    oliveOil.calories = 40;
    oliveOil.protein = 0;
    oliveOil.carbs = 0;
    oliveOil.fat = 4.5;

    FatSource avocado;
    avocado.name = "avocado";
    avocado.servingSize = 100;
    avocado.calories = 160;
    avocado.protein = 1.78;
    avocado.carbs = 0.08;
    avocado.fat = 22.7;

    FatSource pumpkinSeeds;
    pumpkinSeeds.name = "pumpkin seeds";
    pumpkinSeeds.servingSize = 100;
    pumpkinSeeds.calories = 445.2;
    pumpkinSeeds.protein = 18.7;
    pumpkinSeeds.carbs = 53.1;
    pumpkinSeeds.fat = 18.7;

    FatSource walnuts;
    walnuts.name = "walnuts";
    walnuts.servingSize = 100;
    walnuts.calories = 650;
    walnuts.protein = 15.5;
    walnuts.carbs = 14;
    walnuts.fat = 65;
  
    FatSource almonds;
    almonds.name = "almonds";
    almonds.servingSize = 30;
    almonds.calories = 173.6;
    almonds.protein = 6.36;
    almonds.carbs = 6.48;
    almonds.fat = 14.97;

  
    //vegetables
  
    Vegetable carrots; 
    carrots.name = "carrots";
    carrots.servingSize = 100;
    carrots.calories  = 34;
    carrots.protein = 0.5;
    carrots.carbs = 7.7;
    carrots.fat = 0.4;

    Vegetable spinach;
    spinach.name = "spinach";
    spinach.servingSize = 100;
    spinach.calories = 25;
    spinach.protein = 2.8;
    spinach.carbs = 1.6;
    spinach.fat = 0.8;

    Vegetable broccoli;
    broccoli.name = "broccoli";
    broccoli.servingSize = 100;
    broccoli.calories = 34; 
    broccoli.protein = 4.3; 
    broccoli.carbs = 3.2;
    broccoli.fat = 0.6;

    Vegetable kale;
    kale.name = "kale";
    kale.servingSize = 100;
    kale.calories = 27.7; 
    kale.protein = 1.9; 
    kale.carbs = 5.6;
    kale.fat = 0.4;
  
    Vegetable peas;
    peas.name = "peas";
    peas.servingSize = 100;
    peas.calories = 83.8; 
    peas.protein = 5.4; 
    peas.carbs = 15.6;
    peas.fat = 0.2;
  
    Vegetable beets;
    beets.name = "beets";
    beets.servingSize = 100;
    beets.calories = 44; 
    beets.protein = 1.7; 
    beets.carbs = 10;
    beets.fat = 0.2;
  
    Vegetable asparagus;
    asparagus.name = "asparagus";
    asparagus.servingSize = 100;
    asparagus.calories = 22.7; 
    asparagus.protein = 2.4; 
    asparagus.carbs = 4.1;
    asparagus.fat = 0.2;
  
    Vegetable butternutSquash;
    butternutSquash.name = "butternut squash";
    butternutSquash.servingSize = 100;
    butternutSquash.calories = 40; 
    butternutSquash.protein = 0.9; 
    butternutSquash.carbs = 10.7;
    butternutSquash.fat = 0.1;

  
    //fruits

    Fruit blueberries; 
    blueberries.name = "blueberries";
    blueberries.servingSize = 100;
    blueberries.calories = 57;
    blueberries.protein = 1;
    blueberries.carbs = 14;
    blueberries.fat = 0.3;

    Fruit banana;
    banana.name = "banana";
    banana.servingSize = 118;
    banana.calories = 105;
    banana.protein = 1.3;
    banana.carbs = 27;
    banana.fat = 0.4;

    Fruit orange;
    orange.name = "orange";
    orange.servingSize = 131;
    orange.calories = 61.6;
    orange.protein = 1.2;
    orange.carbs = 15.4;
    orange.fat = 0.2;

  Fruit blackberries; 
  blackberries.name = "blackberries";
  blackberries.servingSize = 100;
  blackberries.calories = 43.1;
  blackberries.protein = 1.4;
  blackberries.carbs = 9.5;
  blackberries.fat = 0.5;

  Fruit strawberries; 
  strawberries.name = "strawberries";
  strawberries.servingSize = 100;
  strawberries.calories = 32.2;
  strawberries.protein = 0.7;
  strawberries.carbs = 7.7;
  strawberries.fat = 0.3;

  Fruit grapes; 
  grapes.name = "grapes";
  grapes.servingSize = 100;
  grapes.calories = 69.4;
  grapes.protein = 0.7;
  grapes.carbs = 18.2;
  grapes.fat = 0.2;

  Fruit raspberries; 
  raspberries.name = "raspberries";
  raspberries.servingSize = 100;
  raspberries.calories = 50;
  raspberries.protein = 1;
  raspberries.carbs = 12;
  raspberries.fat = 0.5;

  Fruit mango; 
  mango.name = "mango";
  mango.servingSize = 100;
  mango.calories = 60.1;
  mango.protein = 0.8;
  mango.carbs = 14.9;
  mango.fat = 0.4;

  
    //10-3-23
    //arrays for each food subclass with the objects inside
    ProteinSource protein[] = {chicken, steak, salmon, turkey, ham, tofu, greekYogurt, egg};
    Vegetable vegetables[] = {carrots, spinach, broccoli, kale, peas, beets, asparagus, butternutSquash};
    FatSource fats[] = {oliveOil, avocado, pumpkinSeeds, walnuts, almonds};
    CarbSource carb[] = {whiteRice, potato, corn, oats, blackBeans, lentils, brownRice, quinoa, wholeWheatBread};
    Fruit fruits[] = {blueberries, banana, orange, blackberries, strawberries, grapes, raspberries, mango};  

  
    //Output daily calories and macros
  
    cout << "Ideal daily calories: " << caloriesNeeded << " cal" << endl;
    cout << "Ideal daily protein: " << proteinGramsNeeded << " g" << endl;
    cout << "Ideal daily carbs: " << carbsGramsNeeded << " g" << endl;
    cout << "Ideal daily fat: " << fatGramsNeeded << " g" << endl;

    cout << endl;

    cout << setprecision(0) << fixed;

    //tracks calories in outputted meals
    double calorieCount = 0, proteinCount = 0, carbsCount = 0, fatCount = 0;

    bool play = true;
    int choice;


    int randomProtein;
    int randomFat;
    int randomCarb;
    int randomVegetable;
    int randomFruit;
    int fruitOrVeg;
  
  
while(play == true) {
  
for(int i = 1; i <= meals; i++) {
  //10-3-23
  randomProtein = rand() % 8;
  randomFat = rand() % 5;
  randomCarb = rand() % 9;
  
  fruitOrVeg = rand() % 3;

  if(fruitOrVeg == 0) {
    randomFruit = rand() % 8;
    extraProtein = fruits[randomFruit].protein;
    extraCarbs = fruits[randomFruit].carbs;
    extraCalories = fruits[randomFruit].calories;
    extraFat = fruits[randomFruit].fat;
  }
  else if(fruitOrVeg == 1) {
    randomVegetable = rand() % 8;
    extraProtein = vegetables[randomVegetable].protein;
    extraCarbs = vegetables[randomVegetable].carbs;
    extraCalories = vegetables[randomVegetable].calories;
    extraFat = vegetables[randomVegetable].fat;
  }
  else if(fruitOrVeg == 2) {
    randomVegetable = rand() % 8;
    randomFruit = rand() % 8;
    extraProtein = fruits[randomFruit].protein + vegetables[randomVegetable].protein;
    extraCarbs = fruits[randomFruit].carbs + vegetables[randomVegetable].carbs;
    extraCalories = fruits[randomFruit].calories + vegetables[randomVegetable].calories;
    extraFat = fruits[randomFruit].fat + vegetables[randomVegetable].fat;
  }

  if(nutAllergy == true) {
    randomFat = rand() % 3;
  }

  if(vegetarian == true) {
    randomProtein = (rand() % 3) + 5;
  }

  if(glutenFree == true) {
    randomCarb = rand() % 8;
  }
  


//calculates the servings of each macro and the total serving sizes  


  double proteinServingRemaining, carbsServingRemaining, fatServingRemaining;

  double totalProteinMultiplier, totalCarbsMultiplier, totalFatMultiplier;


  //calculates amounts of each macros needed after adjusting for extra macronutrients in other foods in the meal, the ratio of servings now needed in relation to the previous amount needed, and the amount of servings now needed

  fatServingRemaining = fatGramsPerMeal;
  proteinServingRemaining = proteinGramsPerMeal;
  carbsServingRemaining = carbsGramsPerMeal;

  for(int n = 0; n < 1000; n++) {
    double o = n;

    if(abs(((o / 100) * fats[randomFat].fat) - fatGramsPerMeal) < (0.05 * fatGramsPerMeal)) {
      fatServingRemaining = (o / 100) * fats[randomFat].servingSize;
    }
  }


  if(abs(carbsGramsPerMeal - ((carbsServingRemaining / carb[randomCarb].servingSize) * carb[randomCarb].carbs) + ((fatServingRemaining / fats[randomFat].servingSize) * fats[randomFat].carbs) + extraCarbs) > (carbsGramsPerMeal * 0.05)) {
    //iterate from 0 to 1000
      for(int j = 0; j < 1000; j ++) {
        //if the absolute value of the difference between desired grams of protein per meal and the amount of protein coming from the protein source when multiplied by i is less than 25% of the desired protein per meal, set the serving size to i/100 times the designated serving size for that protein source
        //store iteration as double to be divided by 100 to allow accuracy to hundredths place instead of ones place
        double k = j;

        if(abs(((k/100) * carb[randomCarb].carbs) + ((fatServingRemaining / fats[randomFat].servingSize) * fats[randomFat].carbs) + extraCarbs - carbsGramsPerMeal) < (carbsGramsPerMeal * 0.05)) {
          carbsServingRemaining = (k/100) * carb[randomCarb].servingSize;
        }
      }
  }

  //if the absolute value of the difference between desired grams of protein per meal and the amount of protein coming from the protein source is greater than 25% of the desired protein per meal
if(abs(proteinGramsPerMeal - ((proteinServingRemaining / protein[randomProtein].servingSize) * protein[randomProtein].protein) + ((carbsServingRemaining / carb[randomCarb].servingSize) * carb[randomCarb].protein) + ((fatServingRemaining / fats[randomFat].servingSize) * fats[randomFat].protein) + extraProtein) > (proteinGramsPerMeal * 0.05)) {
  //iterate from 0 to 1000
    for(int l = 0; l < 1000; l ++) {
      //if the absolute value of the difference between desired grams of protein per meal and the amount of protein coming from the protein source when multiplied by i is less than 25% of the desired protein per meal, set the serving size to i/100 times the designated serving size for that protein source
      //store iteration as double to be divided by 100 to allow accuracy to hundredths place instead of ones place
      double m = l;
      
      if(abs(((m/100) * protein[randomProtein].protein) + ((carbsServingRemaining / carb[randomCarb].servingSize) * carb[randomCarb].protein) + ((fatServingRemaining / fats[randomFat].servingSize) * fats[randomFat].protein) + extraProtein - proteinGramsPerMeal) < (proteinGramsPerMeal * 0.05)) {
        //sets serving to amount that falls within the bounds and modifies it to create more accurate results
        proteinServingRemaining = (m/100) * protein[randomProtein].servingSize * 1.05;
      }
    }
  }

  if(abs(fatGramsPerMeal - ((proteinServingRemaining / protein[randomProtein].servingSize) * protein[randomProtein].fat) + ((carbsServingRemaining / carb[randomCarb].servingSize) * carb[randomCarb].fat) + ((fatServingRemaining / fats[randomFat].servingSize) * fats[randomFat].fat)) > (fatGramsPerMeal * 0.05)) {
  //iterate from 0 to 1000
    for(int l = 0; l < 1000; l ++) {
      //if the absolute value of the difference between desired grams of protein per meal and the amount of protein coming from the protein source when multiplied by i is less than 25% of the desired protein per meal, set the serving size to i/100 times the designated serving size for that protein source
      //store iteration as double to be divided by 100 to allow accuracy to hundredths place instead of ones place
      double m = l;

      if(abs(((m/100) * fats[randomFat].fat) + ((carbsServingRemaining / carb[randomCarb].servingSize) * carb[randomCarb].fat) + ((proteinServingRemaining / protein[randomProtein].servingSize) * protein[randomProtein].fat) - fatGramsPerMeal) < (fatGramsPerMeal * 0.05)) {
        //sets serving to amount that falls within the bounds and modifies it to create more accurate results
        fatServingRemaining = (m/100) * fats[randomFat].servingSize * 0.87;
      }
    }
  }

  if((proteinServingRemaining / protein[randomProtein].servingSize) * protein[randomProtein].fat >= (fatGramsPerMeal * 0.75)) {
    fatServingRemaining = 0;
  }

  //outputs the number of meals given by the user 
    cout << "Meal " << i << ": " << endl;
  if(proteinServingRemaining > 0) {
    cout << proteinServingRemaining << " g of " << protein[randomProtein].name << endl;
  }

  if(carbsServingRemaining > 0) {
     cout << carbsServingRemaining << " g of " << carb[randomCarb].name << endl;
  }
  
  if(fatServingRemaining > 0) {
    cout << fatServingRemaining << " g of " << fats[randomFat].name << endl;
  }

  
  if(fruitOrVeg == 0) {
    cout << "100 g of " << fruits[randomFruit].name << endl;
  }
  else if(fruitOrVeg == 1) {
    cout << "100 g of " << vegetables[randomVegetable].name << endl;
  }
  else if(fruitOrVeg == 2) {
    cout << "100 g of " << vegetables[randomVegetable].name << endl;
    cout << "100 g of " << fruits[randomFruit].name << endl;
  }

  
  totalProteinMultiplier = (proteinServingRemaining / 100);
  totalCarbsMultiplier = (carbsServingRemaining / 100);
  totalFatMultiplier = (fatServingRemaining / fats[randomFat].servingSize);


  //the following counts the calories, protein, carbs, and fat for each meal
  calorieCount += (protein[randomProtein].calories * totalProteinMultiplier) + (carb[randomCarb].calories * totalCarbsMultiplier) + (fats[randomFat].calories * totalFatMultiplier) + extraCalories;

  proteinCount += (protein[randomProtein].protein * totalProteinMultiplier) + (carb[randomCarb].protein * totalCarbsMultiplier) + (fats[randomFat].protein * totalFatMultiplier) + extraProtein;

  carbsCount += (protein[randomProtein].carbs * totalProteinMultiplier) + (carb[randomCarb].carbs * totalCarbsMultiplier) + (fats[randomFat].carbs * totalFatMultiplier) + extraCarbs;

  fatCount += (protein[randomProtein].fat * totalProteinMultiplier) + (carb[randomCarb].fat * totalCarbsMultiplier) + (fats[randomFat].fat * totalFatMultiplier) + extraFat;

  //outputs amounts of calories and macros in each meal
  cout << "Calories in this meal: " << calorieCount << " cal" << endl;
  totalCalorieCount += calorieCount;
  calorieCount = 0;
  cout << "Protein in this meal: " << proteinCount << " g" << endl;
  totalProteinCount += proteinCount;
  proteinCount = 0;
  cout << "Carbs in this meal: " << carbsCount << " g" << endl;
  totalCarbsCount += carbsCount;
  carbsCount = 0;
  cout << "Fat in this meal: " << fatCount << " g" << endl << endl;
  totalFatCount += fatCount;
  fatCount = 0;
  
}

  cout << "Total calories for the day: " << totalCalorieCount << " cal" << endl;
  totalCalorieCount = 0;
  cout << "Total protein for the day: " << totalProteinCount << " g" << endl;
  totalProteinCount = 0;
  cout << "Total carbs for the day: " << totalCarbsCount << " g" << endl;
  totalCarbsCount = 0;
  cout << "Total fat for the day: " << totalFatCount << " g" << endl;
  totalFatCount = 0;

  //Allows user to generate more meals
  cout << "Would you like to generate more meals?" << endl;
  cout << "1) yes" << endl;
  cout << "2) no" << endl;
  cin >> choice;

  if(choice == 2) {
    play = false;
  }
  
}
    
    return 0;
}

void getInfo() {
  
  //Asks for and collects user input

  cout << "Welcome to the nutritional meal generator." << endl;

  cout << "What is your weight in pounds?" << endl;
  cin >> weight;

  cout << "What is your height in inches?" << endl;
  cin >> height;

  cout << "What is your age?" << endl;
  cin >> age;

  cout << "What is your sex?" << endl;
  cout << "1) Male" << endl;
  cout << "2) Female" << endl;
  cin >> sex;

  
  //Modify calorie needs based on exercise

  cout << "How active are you?" << endl;
  cout << "1) Little to no exercise." << endl; //No activity (sedentary)
  cout << "2) Exercise 1-3 days/week." << endl; //Lightly active
  cout << "3) Exercise 3-5 days/week." << endl; //Moderately Active
  cout << "4) Exercise 6-7 days/week." << endl; //Active
  cout << "5) Hard exercise 6-7 days/week." << endl; //Very Active
  cin >> activityLevel;

  
  //Modify calorie needs based on weight goal
  cout << "Would you like to gain weight, lose weight, or maintain weight?" << endl;
  cout << "1) gain weight" << endl;
  cout << "2) lose weight" << endl;
  cout << "3) maintain weight" << endl;
  cin >> goal;

  
  //Get number of meals from the user

  cout << "How many meals would you like to have?" << endl;
  cin >> meals;

  //Dietary restrictions
  cout << "Do you have any dietary restrictions?" << endl;
  cout << "1) Yes" << endl;
  cout << "2) No" << endl;
  cin >> restrictions;
  
  if(restrictions == 1) {
    while(stop == false) {
      // If there are dietary restrictions, it will ask the user to choose one of the following.
      cout << "Select from the following (select done to exit):" << endl;
      cout << "1) Vegetarian" << endl;
      cout << "2) Gluten free" << endl;
      cout << "3) Nut allergy" << endl;
      cout << "4) Done" << endl;
      cin >> userChoice;

      if(userChoice == 1) {
        vegetarian = true;
      }

      if(userChoice == 2) {
        glutenFree = true;
      }

      if(userChoice == 3) {
        nutAllergy = true;
      }

      if(userChoice == 4) {
        stop = true;
      }
      
    }

  }
  
}

void calculateMacros() {
  
  //calculate BMR

  if(sex == 1) {
    BMR = 66.47 + (13.75 * (weight/2.2)) + (5.003 * (height * 2.54)) - (6.755 * age);
  }
  else if(sex == 2) {
    BMR = 655.1 + (9.563 * (weight/2.2)) + (1.850 * (height * 2.54)) - (4.676 * age);
  }



  //According to the activity level of user, it will calculate calories needed.
  if (activityLevel == 1) {
    caloriesNeeded = BMR * 1.2;
  }
  else if (activityLevel == 2) {
    caloriesNeeded = BMR * 1.375;
  }
  else if (activityLevel == 3) {
    caloriesNeeded = BMR * 1.55;
  }
  else if (activityLevel == 4) {
    caloriesNeeded = BMR * 1.725;
  }
  else if (activityLevel == 5) {
    caloriesNeeded = BMR * 1.9;
  }






  if (goal == 1) {
    caloriesNeeded += 500;
    cout << "You have selected to gain weight." << endl;
  }      
  else if (goal == 2) {
    caloriesNeeded -= 500;
    cout << "You have selected to lose weight." << endl;
  }
  else if (goal == 3) {
    cout << "You have selected to maintain weight." << endl;
  }

  //10-3-23
  //calculate macronutrient calories for the day
  proteinCaloriesNeeded = caloriesNeeded * PROTEIN_PERCENT;
  carbsCaloriesNeeded = caloriesNeeded * CARB_PERCENT;
  fatCaloriesNeeded = caloriesNeeded * FAT_PERCENT;

  //added 10/11/23
  //calculate grams of macros for the day
  proteinGramsNeeded = proteinCaloriesNeeded / 4;
  carbsGramsNeeded = carbsCaloriesNeeded / 4;
  fatGramsNeeded = fatCaloriesNeeded / 9;

  //calculate calories and macros per meal
  caloriesPerMeal = caloriesNeeded / meals;
  proteinGramsPerMeal = proteinGramsNeeded / meals;
  carbsGramsPerMeal = carbsGramsNeeded / meals;
  fatGramsPerMeal = fatGramsNeeded / meals;
  //int randomInRange = (rand() % (maxValue - minValue + 1)) + minValue;
  
}
