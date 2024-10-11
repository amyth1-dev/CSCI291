void checkIngredientLevels() {
    // Display current levels of all ingredients
    printf("\nCurrent Ingredient Levels:\n");
    printf("Coffee beans: %d grams\n", coffee_beans_quantity);
    printf("Water: %d ml\n", water_quantity);
    printf("Milk: %d ml\n", milk_quantity);
    printf("Chocolate: %d grams\n", chocolate_quantity);
}

void replenishIngredients() {
    // Allow the admin to restock ingredients
    printf("\nReplenish Ingredients:\n");
    
    printf("Enter quantity of coffee beans to add: ");
    int add_coffee_beans;
    scanf("%d", &add_coffee_beans);
    coffee_beans_quantity += add_coffee_beans;
    
    printf("Enter quantity of water to add (ml): ");
    int add_water;
    scanf("%d", &add_water);
    water_quantity += add_water;
    
    printf("Enter quantity of milk to add (ml): ");
    int add_milk;
    scanf("%d", &add_milk);
    milk_quantity += add_milk;
    
    printf("Enter quantity of chocolate to add (grams): ");
    int add_chocolate;
    scanf("%d", &add_chocolate);
    chocolate_quantity += add_chocolate;
    
    printf("Ingredients replenished successfully.\n");
}

void changeCoffeePrice() {
    // Allow the admin to modify coffee prices
    printf("\nChange Coffee Prices:\n");
    
    printf("Enter new price for Espresso: ");
    float new_espresso_price;
    scanf("%f", &new_espresso_price);
    
    printf("Enter new price for Cappuccino: ");
    float new_cappuccino_price;
    scanf("%f", &new_cappuccino_price);
    
    printf("Enter new price for Mocha: ");
    float new_mocha_price;
    scanf("%f", &new_mocha_price);
    
    // Updating global price constants
    *(float *)&ESPRESSO_PRICE = new_espresso_price;
    *(float *)&CAPPUCCINO_PRICE = new_cappuccino_price;
    *(float *)&MOCHA_PRICE = new_mocha_price;
    
    printf("Coffee prices updated successfully.\n");
}

void displaySales() {
    // Display the total amount of sales made so far
    printf("\nTotal Sales: $%.2f\n", total_amount);
}
