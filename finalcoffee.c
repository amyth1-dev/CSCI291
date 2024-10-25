#include <stdio.h>
#include <stdlib.h>

// Constants for ingredient requirements and prices
#define ESPRESSO_COFFEE_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_MILK 0
#define ESPRESSO_CHOCOLATE 0
#define ESPRESSO_PRICE espresso_update
float espresso_update = 3.5;

#define CAPPUCCINO_COFFEE_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_CHOCOLATE 0
#define CAPPUCCINO_PRICE cappuccino_update
float cappuccino_update = 4.5;

#define MOCHA_COFFEE_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATE 30
#define MOCHA_PRICE mocha_update
float mocha_update = 5.5;

// Admin password constant
#define ADMIN_PASSWORD 1234

// Low threshold quantities for alerts
#define COFFEE_BEANS_THRESHOLD 10
#define WATER_THRESHOLD 100
#define MILK_THRESHOLD 150
#define CHOCOLATE_THRESHOLD 45

// Variable to hold the total sales amount
float total_amount = 0.0;
int payment = 0;

// Quantity variables for each ingredient
int coffee_beans_quantity = 100;  
int water_quantity = 300; 
int milk_quantity = 300; 
int chocolate_quantity = 150;

// Function prototypes
void displayCoffeeMenu();
void orderCoffee();
void adminMode();
void checkIngredientLevels();
void replenishIngredients();
void changeCoffeePrice();
void displaySales();
void processPayment(float price);

int main() {
    int choice;
    // Infinite loop for Menu interface
    while (1) {
        printf("\nCoffee Maker Menu:\n");
        printf("1. Order a coffee type\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                orderCoffee();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting the application.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void displayCoffeeMenu() {
    printf("\nAvailable Coffee Types:\n");
    printf("1. Espresso - $%.2f\n", espresso_update);
    printf("2. Cappuccino - $%.2f\n", cappuccino_update);
    printf("3. Mocha - $%.2f\n", mocha_update);
}

void orderCoffee() {
    int choice;
    displayCoffeeMenu();
    printf("Select a coffee type: ");
    scanf("%d", &choice);

    float price = 0.0;
    int required_coffee_beans = 0, required_water = 0, required_milk = 0, required_chocolate = 0;

    switch (choice) {
        case 1: // Espresso
            price = espresso_update;
            required_coffee_beans = ESPRESSO_COFFEE_BEANS;
            required_water = ESPRESSO_WATER;
            required_milk = ESPRESSO_MILK;
            required_chocolate = ESPRESSO_CHOCOLATE;
            break;
        case 2: // Cappuccino
            price = cappuccino_update;
            required_coffee_beans = CAPPUCCINO_COFFEE_BEANS;
            required_water = CAPPUCCINO_WATER;
            required_milk = CAPPUCCINO_MILK;
            required_chocolate = CAPPUCCINO_CHOCOLATE;
            break;
        case 3: // Mocha
            price = mocha_update;
            required_coffee_beans = MOCHA_COFFEE_BEANS;
            required_water = MOCHA_WATER;
            required_milk = MOCHA_MILK;
            required_chocolate = MOCHA_CHOCOLATE;
            break;
        default:
            printf("Invalid coffee type selected.\n");
            return; // Exit function on invalid selection
    }

    // Process payment
    processPayment(price);

    // Check payment status
    if (payment) {
        // Check if ingredients are sufficient
        if (coffee_beans_quantity >= required_coffee_beans && 
            water_quantity >= required_water && 
            milk_quantity >= required_milk && 
            chocolate_quantity >= required_chocolate) {

            // Deduct ingredients
            coffee_beans_quantity -= required_coffee_beans;
            water_quantity -= required_water;
            milk_quantity -= required_milk;
            chocolate_quantity -= required_chocolate;

            // Update total sales
            total_amount += price;
            printf("Your coffee is ready!\n");
        } else {
            printf("Insufficient ingredients for the selected coffee.\n");
        }
    } else {
        printf("Payment was not successful. Order cancelled.\n");
    }
}

void processPayment(float price) {
    float amount;
    printf("Please enter payment amount: ");
    scanf("%f", &amount);

    if (amount >= price) {
        printf("Payment successful. Change: $%.2f\n", amount - price);
        payment = 1; // Successful payment
    } else {
        printf("Insufficient payment. Order cancelled.\n");
        payment = 0; // Failed payment
    }
}

void adminMode() {
    int password;
    printf("Enter Password: ");
    scanf("%d", &password);

    if (password == ADMIN_PASSWORD) {
        int admin_selection;
        while (1) {
            printf("\nAdmin Menu:\n");
            printf("1. Display Ingredients quantity and Total Sale\n");
            printf("2. Replenish Ingredients\n");
            printf("3. Change Coffee Price\n");
            printf("4. Exit Admin Mode\n");
            printf("Select an option: ");
            scanf("%d", &admin_selection);

            switch (admin_selection) {
                case 1:
                    checkIngredientLevels();
                    displaySales();
                    break;
                case 2:
                    replenishIngredients();
                    break;
                case 3:
                    changeCoffeePrice();
                    break;
                case 4:
                    printf("Exiting Admin Mode.\n");
                    return; // Exit admin mode
                default:
                    printf("Invalid option. Please try again.\n");
            }
        }
    } else {
        printf("Incorrect password. Returning to main menu.\n");
    }
}

void checkIngredientLevels() {
    printf("\nCurrent Ingredient Levels:\n"); 
    printf("Coffee beans: %d grams\n", coffee_beans_quantity); 
    printf("Water: %d ml\n", water_quantity); 
    printf("Milk: %d ml\n", milk_quantity); 
    printf("Chocolate: %d grams\n", chocolate_quantity); 
}

void displaySales() {
    printf("Total Sale Amount: $%.2f\n", total_amount);
}

void replenishIngredients() { 
    int add_coffee_beans, add_water, add_milk, add_chocolate;

    printf("\nReplenish Ingredients:\n");
    
    // Generate random amounts for each ingredient
    add_coffee_beans = rand() % 500 + 100; // Random amount between 100 and 599
    coffee_beans_quantity += add_coffee_beans;
    printf("Coffee beans added: %d grams\n", add_coffee_beans);

    add_water = rand() % 500 + 100; // Random amount between 100 and 599
    water_quantity += add_water;
    printf("Water added: %d ml\n", add_water);

    add_milk = rand() % 500 + 100; // Random amount between 100 and 599
    milk_quantity += add_milk;
    printf("Milk added: %d ml\n", add_milk);

    add_chocolate = rand() % 500 + 100; // Random amount between 100 and 599
    chocolate_quantity += add_chocolate;
    printf("Chocolate added: %d grams\n", add_chocolate);

    printf("Ingredients replenished successfully.\n");
    checkIngredientLevels();
}


void changeCoffeePrice() {
    int selection;
    printf("\nAvailable Coffee Types and Prices:\n");
    printf("1. Espresso - $%.2f\n", espresso_update);
    printf("2. Cappuccino - $%.2f\n", cappuccino_update);
    printf("3. Mocha - $%.2f\n", mocha_update);
    printf("4. Exit\n");
    printf("Enter the number of the coffee you want to change the price: ");
    scanf("%d", &selection);

    switch (selection) {
        case 1:
            printf("Enter new Espresso price: ");
            scanf("%f", &espresso_update);
            break;
        case 2:
            printf("Enter new Cappuccino price: ");
            scanf("%f", &cappuccino_update);
            break;
        case 3:
            printf("Enter new Mocha price: ");
            scanf("%f", &mocha_update);
            break;
        case 4:
            return; // Exit function
        default:
            printf("Invalid selection.\n");
            break;
    }
}
