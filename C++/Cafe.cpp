#include <iostream>
#include <vector>     // Allows the use of dynamic arrays to store our shopping cart items
#include <string>     // Allows the use of string objects   // Allows string stream operations
using namespace std;

struct Item {                 // bundles all 3 variables in a single container 
    string name;              // item name
    double price;             // item price
    int quantity;             // item quantity
    
    Item(string n, double p, int q) {           // makes sure that whenever creating a new item, it follows this format (ex. cart.push_back(Item(...)))
        name = n;
        price = p;
        quantity = q;
    }
};

vector<Item> cart;  // holds every choice made, across all submenus

// Helper function to ensure menu choices and switch inputs reject decimals/doubles and letters
int getValidInt() {
    string input;
    while (true) {
        cin >> input;
        bool hasDecimal = false;
        bool isValid = true;

        for (size_t i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == '.') {
                hasDecimal = true;
            } else if (!isdigit(c) && !(i == 0 && c == '-')) {
                isValid = false;
            }
        }

        if (hasDecimal || !isValid) {
            cout << "\nInvalid Input! Decimals and letters are not allowed. Please enter a whole number: ";
            continue;
        }

        try {
            return stoi(input);
        } catch (...) {
            cout << "\nInvalid Input! Please enter a valid whole number: ";
        }
    }
}

// function that handles the categories under the Coffee and Expresso
void CoffeeMenu() {
    int choice, choice2, quantity;
    while (true) {
        cout<<"\n\n--------------------------";
        cout<<"\nChoose Coffee Category: "<<endl;
        cout<< "\n1. Hot Coffee & Espresso\n2. Cold Coffee & Espresso\n3. Coffee Frappuccino\n4. Back to Previous Menu\n> ";
        choice = getValidInt();
        
        if (choice == 4) {
            break;
        }
        
        switch (choice) {
            case 1: {
                bool valid;
                do { 
                    valid = true;
                    cout<<"\n\n--------------------------";
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Blonde Roast (₱140.00)\n2. Cappuccino (₱175.00)\n3. Featured Dark Roast (₱140.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();
                    
                    if (choice2 == 1){ cart.push_back(Item("Blonde Roast", 140 * quantity, quantity)); cout << "\n[Added Blonde Roast to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Cappuccino", 175 * quantity, quantity)); cout << "\n[Added Cappuccino to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Featured Dark Roast", 140 * quantity, quantity)); cout << "\n[Added Featured Dark Roast to cart!]\n";}
                    else {
                        cout<<"\nInvalid Choice Try Again!\n";
                        valid = false;
                    } 
                } while (!valid);
                break;
            }

            case 2: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Iced Coffee (₱150)\n2. Vanilla Protein Cream Cold Brew (₱205.00)\n3. Iced Caffe Mocha (₱190.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Iced Coffee", 150 * quantity, quantity)); cout << "\n[Added Iced Coffee to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Vanilla Protein Cream Cold Brew", 205 * quantity, quantity)); cout << "\n[Added Vanilla Protein Cream Cold Brew to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Iced Caffe Mocha", 190 * quantity, quantity)); cout << "\n[Added Iced Caffe Mocha to cart!]\n";}
                    else {
                        cout<<"\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 3: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Mocha Cookie Crumble Frappuccino Blended Beverage (₱210.00)\n2. Horchata Frappuccino Blended Beverage (₱200.00)\n3. Caramel Ribbon Crunch Frappuccino Blended Beverage (₱210.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Mocha Cookie Crumble Frappuccino Blended Beverage", 210 * quantity, quantity)); cout << "\n[Added Mocha Cookie Crumble Frappuccino to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Horchata Frappuccino Blended Beverage", 200 * quantity, quantity)); cout << "\n[Added Horchata Frappuccino to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Caramel Ribbon Crunch Frappuccino Blended Beverage", 210 * quantity, quantity)); cout << "\n[Added Caramel Ribbon Crunch Frappuccino to cart!]\n";}
                    else {
                        cout<<"\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }
                
            default: 
                cout<< "\nInvalid Choice. Try Again.\n";
        }
    }
}

// function that handles the categories under the Non-Coffee Beverages
void NoncoffeeMenu() {
    int choice, choice2, quantity;
    while (true) {
        cout<<"\n\n--------------------------";
        cout<<"\nChoose Non-Coffee Category: "<<endl;
        cout<< "\n1. Tea\n2. Refreshments\n3. Chocolate and Cream\n4. Back to Previous Menu\n> ";
        choice = getValidInt();
        
        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Chamomile Tea (₱135.00)\n2. Chai Tea Latte (₱175.00)\n3. Green Tea Latte (₱180.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Chamomile Tea", 135 * quantity, quantity)); cout << "\n[Added Chamomile Tea to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Chai Tea Latte", 175 * quantity, quantity)); cout << "\n[Added Chai Tea Latte to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Green Tea Latte", 180 * quantity, quantity)); cout << "\n[Added Green Tea Latte to cart!]\n";}
                    else { 
                        cout<<"\nInvalid Choice Try again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 2: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Strawberry Acai Refresher (₱165.00)\n2. Mango Dragonfruit with Lemonade (₱185.00)\n3. Pink Drink (₱190.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Strawberry Acai Refresher", 165 * quantity, quantity)); cout << "\n[Added Strawberry Acai Refresher to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Mango Dragonfruit with Lemonade", 185 * quantity, quantity)); cout << "\n[Added Mango Dragonfruit with Lemonade to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Pink Drink", 190 * quantity, quantity)); cout << "\n[Added Pink Drink to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 3: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\nChoose order:\n ";
                    cout<<"\n1. Signature Hot Chocolate (₱170.00)\n2. Strawberry Cream (₱195.00)\n3. Chocolate Cream Chip (₱200.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Signature Hot Chocolate", 170 * quantity, quantity)); cout << "\n[Added Signature Hot Chocolate to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Strawberry Cream", 195 * quantity, quantity)); cout << "\n[Added Strawberry Cream to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Chocolate Cream Chip", 200 * quantity, quantity)); cout << "\n[Added Chocolate Cream Chip to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }
              
            default: 
                cout<< "\nInvalid Choice. Try Again.\n";
        }
    }
}

// function that handles the categories under add-ons
void addons() {
    int choice, choice2, quantity;
    
    while (true) {
        cout<<"\n\n--------------------------";
        cout<<"\nchoose add-ons: "<<endl;
        cout<< "\n1. Sandwiches\n2. Pastries\n3. Desserts\n4. Syrups & Flavors\n5. Milk Options\n6. Toppings & Extras\n7. Back to Main Menu\n> ";
        choice = getValidInt();

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\n+================+";
                    cout<<"\n|choose add-ons: |"<<endl;
                    cout<<"+================+";
                    cout<< "\n1. Chicken Pesto Sandwich (₱185.00)\n2. Grilled Cheese Sandwich (₱165.00)\n3. Ham, Egg & Cheese Sandwich (₱145.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Chicken Pesto Sandwich", 185 * quantity, quantity)); cout << "\n[Added Chicken Pesto Sandwich to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Grilled Cheese Sandwich", 165 * quantity, quantity)); cout << "\n[Added Grilled Cheese Sandwich to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Ham, Egg & Cheese Sandwich", 145 * quantity, quantity)); cout << "\n[Added Ham, Egg & Cheese Sandwich to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 2: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\n=================";
                    cout<<"\nChoose order "<<endl;
                    cout<<"=================";
                    cout<< "\n1. French Butter Croissant (₱95.00)\n2. Cinnamon Danish (₱115.00)\n3. Banana Bread (₱85.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("French Butter Croissant", 95 * quantity, quantity)); cout << "\n[Added French Butter Croissant to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Cinnamon Danish", 115 * quantity, quantity)); cout << "\n[Added Cinnamon Danish to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Banana Bread", 85 * quantity, quantity)); cout << "\n[Added Banana Bread to cart!]\n";}
                    else {
                        cout<< "Invalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 3: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\n******************";
                    cout<<"\nChoose order: "<<endl;
                    cout<<"******************";
                    cout<< "\n1. Classic Chocolate Cake (₱220.00)\n2. Chocolate Pistachio Dream Bar (₱150.00)\n3. NewYork Cheesecake (₱235.00)\n> ";
                    choice2 = getValidInt();
                    cout<<"\nEnter quantity: ";
                    quantity = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Classic Chocolate Cake", 220 * quantity, quantity)); cout << "\n[Added Classic Chocolate Cake to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Chocolate Pistachio Dream Bar", 150 * quantity, quantity)); cout << "\n[Added Chocolate Pistachio Dream Bar to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("NewYork Cheesecake", 235 * quantity, quantity)); cout << "\n[Added NewYork Cheesecake to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 4: { 
                bool valid;
                do {
                    valid = true;
                    cout<<"\n------------------";
                    cout<<"\nChoose order: "<<endl;
                    cout<<"------------------";
                    cout<< "\n1. Vanilla Syrup (₱25.00)\n2. Salted Caramel Syrup (₱30.00)\n3. Hazelnut Syrup (₱35.00)\n> ";
                    choice2 = getValidInt();
                    
                    if (choice2 == 1){ cart.push_back(Item("Vanilla Syrup", 25, 1)); cout << "\n[Added Vanilla Syrup to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Salted Caramel Syrup", 30, 1)); cout << "\n[Added Salted Caramel Syrup to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Hazelnut Syrup", 35, 1)); cout << "\n[Added Hazelnut Syrup to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 5: {
                bool valid;
                do {
                    valid = true;
                    cout<<"\n..................";
                    cout<<"\n|Choose order:   |"<<endl;
                    cout<<"..................";
                    cout<< "\n1. Oatmilk (₱65.00)\n2. Soy milk (₱35.00)\n3. Almond milk (₱45.00)\n> ";
                    choice2 = getValidInt();

                    if (choice2 == 1){ cart.push_back(Item("Oatmilk", 65, 1)); cout << "\n[Added Oatmilk to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Soy milk", 35, 1)); cout << "\n[Added Soy milk to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Almond milk", 45, 1)); cout << "\n[Added Almond milk to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            case 6: { 
                bool valid;
                do {
                    valid = true;
                    cout<<"\n+----------------+";
                    cout<<"\n|Choose order:   |"<<endl;
                    cout<<"+----------------+";
                    cout<< "\n1. Pomegranate Pearls (₱40.00)\n2. Coffee Jelly (₱45.00)\n3. Additional Frappuccino Chips (₱50.00)\n> ";
                    choice2 = getValidInt();
                    
                    if (choice2 == 1){ cart.push_back(Item("Pomegranate Pearls", 40, 1)); cout << "\n[Added Pomegranate Pearls to cart!]\n";}
                    else if (choice2 == 2){ cart.push_back(Item("Coffee Jelly", 45, 1)); cout << "\n[Added Coffee Jelly to cart!]\n";}
                    else if (choice2 == 3){ cart.push_back(Item("Additional Frappuccino Chips", 50, 1)); cout << "\n[Added Additional Frappuccino Chips to cart!]\n";}
                    else {
                        cout<< "\nInvalid Choice Try Again!\n";
                        valid = false;
                    }
                } while (!valid);
                break;
            }

            default: 
                cout<< "\nInvalid Choice. Try Again.\n"; 
        }
    }
}

// Function to handle discounts, payments, and print the proper official receipt
void checkout() {
    double subtotal = 0, amount = 0, final = 0, balance = 0, change = 0;
    int discount;
    bool choice = false, valid = false;
    string label = "None";

    // validates if cart is empty
    if (cart.empty()) {
        cout << "\nYour cart is empty! Please add some items before checking out.\n";
        return; 
    }
    
    // Calculate subtotal from cart items
    for (const auto &item : cart) {
        subtotal += item.price;
    }
    
    double totalWithVat = subtotal * 1.12;
    
    // Loop to ensure a valid discount choice is made
    do { 
        cout << "\n+==================================+";
        cout << "\nChoose Discount:\n";
        cout << "1. Senior Citizen Discount (20%)\n";
        cout << "2. PWD Discount (20%)\n";
        cout << "3. Student Promo (10%)\n";
        cout << "4. No Discount\n";
        cout << "> ";
        discount = getValidInt();

        switch (discount) {
            case 1:
                amount = totalWithVat * 0.20;
                label = "Senior Citizen (20%)";
                choice = true;
                break;
            case 2:
                amount = totalWithVat * 0.20;
                label = "PWD (20%)";
                choice = true;
                break;
            case 3:
                amount = totalWithVat * 0.10;
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

    final = totalWithVat - amount;

    // Loop to handle cash input and verify payment is enough
    do {
        cout << "\n--------------------\n";
        cout << "Subtotal: ₱" << subtotal << "\n";
        cout << "VAT (12%): ₱" << (totalWithVat - subtotal) << "\n";
        cout << "Total with VAT: ₱" << totalWithVat << "\n";
        cout << "Discount (" << label << "): -₱" << amount << "\n";
        cout << "Final Total Due: ₱" << final << "\n";
        cout << "--------------------\n";
        cout << "Enter Cash Amount: ₱";
        cin >> balance;

        if (balance >= final) {
           change = balance - final;
           valid = true;
        } else {
            cout << "\nInsufficient Amount! Try again\n";
            valid = false;
        }
    } while (!valid);

    // ==========================================
    //          Receipt for POST-PAYMENT
    // ==========================================
    cout << "\n\n===========================================";
    cout << "\n           LAVENDER CAFÉ RECEIPT           ";
    cout << "\n===========================================";
    cout << "\nItemized Orders:";
    for (const auto &item : cart) {
        cout << "\n - " << item.name << " (x" << item.quantity << ") .......... ₱" << item.price;
    }
    cout << "\n-------------------------------------------";
    cout << "\nSubtotal       : ₱" << subtotal;
    cout << "\nVAT (12%)      : ₱" << (totalWithVat - subtotal);
    cout << "\nGross Total    : ₱" << totalWithVat;
    cout << "\nDiscount       : " << label << " (-₱" << amount << ")";
    cout << "\n-------------------------------------------";
    cout << "\nFINAL TOTAL    : ₱" << final;
    cout << "\nCash Tendered  : ₱" << balance;
    cout << "\nCHANGE         : ₱" << change;
    cout << "\n===========================================";
    cout << "\n        Thank You for Purchasing!          ";
    cout << "\n===========================================\n";

    // Clear cart after successful payment completion
    cart.clear();
}

// Main Menu function to route user to Coffee or Non-Coffee option
void Menu() {
    int choice;
    while (true) {
        cout<<"\n\n--------------------------";
        cout<<"\nChoose type of coffee: "<<endl;
        cout<< "\n1. Coffee & Espresso\n2. Non-Coffee Beverages\n3. Back to Main Menu\n> ";
        choice = getValidInt();
        
        if (choice == 3) {
            break;
        }
        
        switch (choice) {
            case 1: 
                CoffeeMenu(); 
                break;
            case 2: 
                NoncoffeeMenu(); 
                break;
            default: 
                cout<< "\nInvalid Choice. Please try again\n"; 
                break;
        }
    }
}

// Main function: Runs the program loop
int main() {
    int choice;
    do {
        cout<<"\n ****=============================****";
        cout<<"\n\t    Lavender Café";
        cout<<"\n ****=============================****";
        cout<<" \n\n======CATEGORIES======";
        cout << "\n1. Menu\n2. Add-ons\n3. Checkout\n> ";
        choice = getValidInt();

        switch (choice) {
            case 1: Menu(); break;
            case 2: addons(); break;
            case 3: checkout(); break;
            default:
                cout<< "\nInvalid Choice. Try Again.\n";
                break;
        }
    } while (choice != 3 || !cart.empty()); // Loops until checkout is completed and cart is empty

    return 0;
}