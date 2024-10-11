#include <stdio.h>

// Constants for ingredient requirements and prices
#define ESPRESSO_COFFEE_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_MILK 0
#define ESPRESSO_CHOCOLATE 0
#define ESPRESSO_PRICE 3.5

#define CAPPUCCINO_COFFEE_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_CHOCOLATE 0
#define CAPPUCCINO_PRICE 4.5

#define MOCHA_COFFEE_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATE 30
#define MOCHA_PRICE 5.5

// Admin password constant
#define ADMIN_PASSWORD "admin123"

// Low threshold quantities for alerts
#define COFFEE_BEANS_THRESHOLD 10
#define WATER_THRESHOLD 100
#define MILK_THRESHOLD 150
#define CHOCOLATE_THRESHOLD 45

// Variable to hold the total sales amount
float total_amount = 0.0;

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
void alertLowIngredients();
void processPayment(float price);

int main() {
    int choice;
    //infinite loop for Menu interface
    while(1){
        printf("\nCoffee Make Menu:\n");
        printf("1.Order a coffee type\n");
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
    printf("1. Espresso - $%.2f\n", ESPRESSO_PRICE);
    printf("2. Cappuccino - $%.2f\n", CAPPUCCINO_PRICE);
    printf("3. Mocha - $%.2f\n", MOCHA_PRICE);
    }
void orderCoffee(){
    int choice;
    displayCoffeeMenu();
    printf("Select a coffee type: ");
    scanf("%d", &choice);
switch (choice) {
        case 1:
            if (coffee_beans_quantity >= ESPRESSO_COFFEE_BEANS && water_quantity >= ESPRESSO_WATER) {
                coffee_beans_quantity -= ESPRESSO_COFFEE_BEANS;
                water_quantity -= ESPRESSO_WATER;
                total_amount += ESPRESSO_PRICE;
                processPayment(ESPRESSO_PRICE);
                printf("Espresso is ready!\n");
            } else {
                printf("Insufficient ingredients for Espresso.\n");
            }
            break;
        case 2:
            if (coffee_beans_quantity >= CAPPUCCINO_COFFEE_BEANS && water_quantity >= CAPPUCCINO_WATER &&
                milk_quantity >= CAPPUCCINO_MILK) {
                coffee_beans_quantity -= CAPPUCCINO_COFFEE_BEANS;
                water_quantity -= CAPPUCCINO_WATER;
                milk_quantity -= CAPPUCCINO_MILK;
                total_amount += CAPPUCCINO_PRICE;
                processPayment(CAPPUCCINO_PRICE);
                printf("Cappuccino is ready!\n");
            } else {
                printf("Insufficient ingredients for Cappuccino.\n");
            }
            break;
        case 3:
            if (coffee_beans_quantity >= MOCHA_COFFEE_BEANS && water_quantity >= MOCHA_WATER &&
                milk_quantity >= MOCHA_MILK && chocolate_quantity >= MOCHA_CHOCOLATE) {
                coffee_beans_quantity -= MOCHA_COFFEE_BEANS;
                water_quantity -= MOCHA_WATER;
                milk_quantity -= MOCHA_MILK;
                chocolate_quantity -= MOCHA_CHOCOLATE;
                total_amount += MOCHA_PRICE;
                processPayment(MOCHA_PRICE);
                printf("Mocha is ready!\n");
            } else {
                printf("Insufficient ingredients for Mocha.\n");
            }
            break;
        default:
            printf("Invalid coffee type selected.\n");
    }
}
void processPayment(float price) {
    float amount;
    printf("Please enter payment amount: ");
    scanf("%f", &amount);
    
    if (amount >= price) {
        printf("Payment successful. Change: $%.2f\n", amount - price);
    } else {
        printf("Insufficient payment. Order cancelled.\n");
    }
}