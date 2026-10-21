#include <iostream>
#include <vector>     // Allows the use of dynamic arrays to store our shopping cart items
#include <string>
using namespace std;

struct Item {                 // bundles all 3 variables in a single container 
    string name;              // item name
    double price;             // item price
    int quantity;             // item quanity
    
    Item(string n, double p, int q) {           // makes sure that whenever creating a new item, it follows this format (ex. cart.push_back(Item(...)))
        name = n;
        price = p;
        quantity = q;
    }
};

vector<Item> cart;  // holds every choice made, across all submenus


// function that handles the categories under the Coffee and Expresso
void CoffeeMenu() {
    int choice, choice2, quantity;
    cout<<"\nchoose category: "<<endl;
    cout<< "\n1. Hot Coffee & Espresso\n2. Cold Coffee & Espresso\n3. Coffee Frappuccino\n> ";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Blonde Roast (₱140)\n2. Cappuccino (₱175)\n3. Featured Dark Roast (₱140)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;
        
        // Adds the selected coffee item and its total price to the cart
        if (choice2 == 1) cart.push_back(Item("Blonde Roast", 140 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Cappuccino", 175 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Featured Dark Roast", 140 * quantity, quantity));
        break;

        case 2:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Iced Coffee (₱150)\n2. Vanilla Protein Cream Cold Brew (₱205)\n3. Iced Caffe Mocha (₱190)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Iced Coffee", 150 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Vanilla Protein Cream Cold Brew", 205 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Iced Caffe Mocha", 190 * quantity, quantity));
        break;

        case 3:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Mocha Cookie Crumble Frappuccino Blended Beverage (₱210)\n2. Horchata Frappuccino Blended Beverage (₱200)\n3. Caramel Ribbon Crunch Frappuccino Blended Beverage (₱210)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Mocha Cookie Crumble Frappuccino Blended Beverage", 210 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Horchata Frappuccino Blended Beverage", 200 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Caramel Ribbon Crunch Frappuccino Blended Beverage", 210 * quantity, quantity));
        break;
            
        default: cout<< "Invalid Choice";
    }
}

// function that handles the categories under the Non-Coffee Beverages
void NoncoffeeMenu() {
    int choice, choice2, quantity;
    cout<<"\nchoose category: "<<endl;
    cout<< "\n1. Tea\n2. Refreshments\n3. Chocolate and Cream\n> ";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Chamomile Tea (₱135)\n2. Chai Tea Latte (₱175)\n3. Green Tea Latte (₱180)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Chamomile Tea", 135 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Chai Tea Latte", 175 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Green Tea Latte", 180 * quantity, quantity));
        break;

        case 2:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Strawberry Acai Refresher (₱165)\n2. Mango Dragonfruit with Lemonade (₱185)\n3. Pink Drink (₱190)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Strawberry Acai Refresher", 165 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Mango Dragonfruit with Lemonade", 185 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Pink Drink", 190 * quantity, quantity));
        break;

        case 3:
        cout<<"\nChoose order:\n ";
        cout<<"\n1. Signature Hot Chocolate (₱170)\n2. Strawberry Cream (₱195)\n3. Chocolate Cream Chip (₱200)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Signature Hot Chocolate", 170 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Strawberry Cream", 195* quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Chocolate Cream Chip", 200 * quantity, quantity));
        break;
          
        default: cout<< "Invalid Choice";
    }

}


// function that handles the categories under add-ons
void addons() {
    int choice, choice2, quantity;
    
    cout<<"\nchoose add-ons: "<<endl;
     cout<< "\n1. Sandwiches\n2. Pastries\n3. Desserts\n4. Syrups & Flavors\n5. Milk Options\n6. Toppings & Extras\n> ";
     cin>>choice;

     switch (choice) {
        case 1: 
        cout<<"\nChoose order: "<<endl;
        cout<< "\n1. Chicken Pesto Sandwich (₱185)\n2. Grilled Cheese Sandwich (₱165)\n3. Ham, Egg & Cheese Sandwich (₱145)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Chicken Pesto Sandwich", 185 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Grilled Cheese Sandwich", 165 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Ham, Egg & Cheese Sandwich", 145 * quantity, quantity));
        break;

        case 2: 
        cout<<"\nChoose order "<<endl;
        cout<< "\n1. French Butter Croissant (₱95)\n2. Cinnamon Danish (₱115)\n3. Banana Bread (₱85)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("French Butter Croissant", 95 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Cinnamon Danish", 115 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("Banana Bread", 85 * quantity, quantity));
        break;

        case 3: 
        cout<<"\nChoose order: "<<endl;
        cout<< "\n1. Classic Chocolate Cake (₱220)\n2. Chocolate Pistachio Dream Bar (₱150)\n3. NewYork Cheesecake (₱235)\n> ";
        cin>>choice2;
        cout<<"\nEnter quantity: ";
        cin>>quantity;

        if (choice2 == 1) cart.push_back(Item("Classic Chocolate Cake", 220 * quantity, quantity));
        else if (choice2 == 2) cart.push_back(Item("Chocolate Pistachio Dream Bar", 150 * quantity, quantity));
        else if (choice2 == 3) cart.push_back(Item("NewYork Cheesecake", 235 * quantity, quantity));
        break;

        case 4: 
        cout<<"\nChoose order: "<<endl;
        cout<< "\n1. Vanilla Syrup (₱25)\n2. Salted Caramel Syrup (₱30)\n3. Hazelnut Syrup (₱35)\n> ";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back(Item("Vanilla Syrup", 25, 1));
        else if (choice2 == 2) cart.push_back(Item("Salted Caramel Syrup", 30, 1));
        else if (choice2 == 3) cart.push_back(Item("Hazelnut Syrup", 35, 1));
        break;

        case 5: 
        cout<<"\nChoose order: "<<endl;
        cout<< "\n1. Oatmilk (₱65)\n2. Soy milk (₱35)\n3. Almond milk (₱45)\n> ";
        cin>>choice2;

        if (choice2 == 1) cart.push_back(Item("Oatmilk", 65, 1));
        else if (choice2 == 2) cart.push_back(Item("Soy milk", 35, 1));
        else if (choice2 == 3) cart.push_back(Item("Almond milk", 45, 1));
        break;

        case 6: 
        cout<<"\nChoose order: "<<endl;
        cout<< "\n1. Pomegranate Pearls (₱40)\n2. Coffee Jelly (₱45)\n3. Additional Frappuccino Chips (₱50)\n> ";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back(Item("Pomegranate Pearls", 40, 1));
        else if (choice2 == 2) cart.push_back(Item("Coffee Jelly", 45, 1));
        else if (choice2 == 3) cart.push_back(Item("Additional Frappuccino Chips", 50, 1));
        break;

        default: cout<< "Invalid Choice"; 
     }
}

// Main Menu function to route user to Coffee or Non-Coffee option
void Menu() {
    int choice;
    
    cout<<"\nChoose type of coffee: "<<endl;
    cout<< "\n1. Coffee & Espresso\n2. Non-Coffee Beverages\n> ";
    cin>>choice;
    
    switch (choice) {
        case 1: CoffeeMenu(); break;
        case 2: NoncoffeeMenu(); break;
        default: cout<< "Invalid Choice";
    }

    
}

// Function to display the receipt, apply discounts, and calculate payment and change
void checkout() {
    double total = 0, amount, final, balance, change;
    int discount;
    bool choice, valid;
    string label;

    // validates if cart is empty
    if (cart.empty()) {
        cout << "\nYour cart is empty! Please add some items before checking out.\n";
        return; 
    }
    
    // Loop through the cart vector to display items and calculate subtotal
    cout << "\n--- Receipt ---\n";
    for (const auto &item : cart) {
        cout << item.name << "(x" << item.quantity << ") - " << item.price << "\n";
        total += item.price;
    }
    cout << "Total: " << total << "\n";
    
    // Loop to ensure a valid discount choice is made
    do { 
    cout << "\nChoose Discount:\n";
    cout << "1. Senior Citizen Discount (20%)\n";
    cout << "2. PWD Discount (20%)\n";
    cout << "3. Student Discount (10%)\n";
    cout << "4. No Discount\n";
    cout << "> ";
    cin >> discount;

    switch (discount) {
        case 1:
            amount = total * 0.20;
            label = "Senior Citizen (20%)";
            choice = true;
            break;
        case 2:
            amount = total * 0.20;
            label = "PWD (20%)";
            choice = true;
            break;
        case 3:
            amount = total * 0.10;
            label = "Student (10%)";
            choice = true;
            break;
        case 4:
            amount = 0;
            label = "None";
            choice = true;
            break;
        default:
            cout << "\nInvalid choice. Try again\n";
            choice = false;
            break;
    }
} while (!choice);

    // Loop to handle cash input and verify payment is enough
    do {
        final = total - amount;

    cout << "\n--------------------\n";
    cout << "Discount Applied: " << label << "\n";
    cout << "Discount Amount: -" << amount << "\n";
    cout << "Final Total: " << final << "\n";
    cout << "--------------------\n";
    cout << "Enter Amount: ";
    cin>>balance;

    if (balance >=final) {
       change = balance - final;
       cout<< "\nYour change is: " <<change;
       cout<< "\nThank You for Purchasing";
       valid = true;
    } else {
        cout<< "\nInvalid Payment! Try again";
        valid = false;
    }
    
   } while (!valid);
}

// Main function: Runs the program loop
int main() {
    int choice;
    do {
        cout << "\n1. Menu\n2. Add-ons\n3. Checkout\n> ";
        cin >> choice;

        switch (choice) {
            case 1: Menu(); break;
            case 2: addons(); break;
            case 3: checkout(); break;
            default:
            cout<< "\nInvalid";
            break;
        }
    } while (choice != 3 || cart.empty()); // Loops until the user chooses checkout and cart is not empty

    return 0;
}