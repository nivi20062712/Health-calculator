#include <stdio.h>
#include <math.h>

// Global variables
int choice;
int repeat = 1;

// Function Declarations
void bmiCalculator();
void calorieCalculator();
void heartRateCalculator();
void basicCalculator();


// Function Definitions


// ---- BMI CALCULATOR ----
void bmiCalculator() {
    float weight, height_cm, height_m, bmi;

    printf("\n--- BMI CALCULATOR ---\n");
    printf("Enter your weight (kg): ");
    scanf("%f", &weight);
    printf("Enter your height (cm): ");
    scanf("%f", &height_cm);

    // Convert height to meters
    height_m = height_cm / 100.0;

    // Calculate BMI
    bmi = weight / pow(height_m, 2);

    // Display result
    printf("\nYour BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
        printf("Category: Underweight\n");
    else if (bmi < 24.9)
        printf("Category: Normal weight\n");
    else if (bmi < 29.9)
        printf("Category: Overweight\n");
    else
        printf("Category: Obese\n");

    printf("Maintain a balanced diet and regular exercise.\n\n");
}

// ---- CALORIE CALCULATOR ----
void calorieCalculator() {
    int age, gender, activity;
    float weight, height_cm, bmr = 0, calories = 0;

    printf("\n--- DAILY CALORIE CALCULATOR ---\n");

    printf("Enter your age (in years): ");
    scanf("%d", &age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &height_cm);

    printf("Select Gender (1 for Male, 2 for Female): ");
    scanf("%d", &gender);

    // Calculate BMR
    if (gender == 1)
        bmr = 10 * weight + 6.25 * height_cm - 5 * age + 5;
    else if (gender == 2)
        bmr = 10 * weight + 6.25 * height_cm - 5 * age - 161;
    else {
        printf("Invalid gender option!\n");
        return;
    }

    // Ask for activity level
    printf("\nSelect your activity level:\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly active (1-3 days/week)\n");
    printf("3. Moderately active (3-5 days/week)\n");
    printf("4. Very active (6-7 days/week)\n");
    printf("Enter your choice: ");
    scanf("%d", &activity);

    // Multiply BMR by activity factor
    switch (activity) {
        case 1: calories = bmr * 1.2; break;
        case 2: calories = bmr * 1.375; break;
        case 3: calories = bmr * 1.55; break;
        case 4: calories = bmr * 1.725; break;
        default:
            printf("Invalid activity choice!\n");
            return;
    }

    // Display result
    printf("\nYour estimated daily calorie requirement is: %.2f kcal\n", calories);
}

// ---- HEART RATE CALCULATOR ----
void heartRateCalculator() {
    int age;
    float maxHeartRate, lowerTarget, upperTarget;

    printf("\n--- HEART RATE CALCULATOR ---\n");
    printf("Enter your age (in years): ");
    scanf("%d", &age);

    // Calculate heart rate values
    maxHeartRate = 220 - age;
    lowerTarget = 0.50 * maxHeartRate;
    upperTarget = 0.85 * maxHeartRate;

    printf("\nYour Maximum Heart Rate: %.1f bpm\n", maxHeartRate);
    printf("Your Target Heart Rate Range: %.1f - %.1f bpm\n", lowerTarget, upperTarget);
    printf("\nDuring exercise, try to keep your heart rate within this range to improve heart and lung health safely.\n");
    
}

// ---- BASIC CALCULATOR ----
void basicCalculator() {
    int operation;
    float num1, num2, result;

    printf("\n---- BASIC CALCULATOR ----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &operation);

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (operation) {
        case 1:
            result = num1 + num2;
            printf("Result = %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result = %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result = %.2f\n", result);
            break;
        case 4:
            if (num2 != 0)
                result = num1 / num2;
            else {
                printf("Error! Division by zero.\n");
                return;
            }
            printf("Result = %.2f\n", result);
            break;
        default:
            printf("Invalid operation!\n");
    }
}


int main() {
    while (repeat == 1) {
        printf("\n=========================\n");
        printf("\tSIMPLE CALCULATOR\n");
        printf("=========================\n");
        printf("1. BMI Calculator\n");
        printf("2. Calorie Calculator\n");
        printf("3. Heart Rate Calculator\n");
        printf("4. Basic Calculator\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bmiCalculator();
                break;
            case 2:
                calorieCalculator();
                break;
            case 3:
                heartRateCalculator();
                break;
            case 4:
                basicCalculator();
                break;
            case 5:
                printf("\nThank you for using Simple Calculator!\nStay healthy and take care!\n");
                repeat = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        if (repeat != 0) {
            printf("\nDo you want to continue? (1.Yes / 0.No): ");
            scanf("%d", &repeat);
        }
    }

    printf("\nThank you for using Simple Calculator!\nStay healthy and take care!\n");
    return 0;
}