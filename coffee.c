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
//displaycoffee,alertlowingredients functions to be used in ordercoffee
//checkingridient,replenishingredient,changecoffeeprice,displaysales to be used in adminmode
