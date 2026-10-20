#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    double price;
};

vector<Item> cart;  // holds every choice made, across all submenus

void BirthdayCakeMenu() {
    int choice, choice2;
    cout<<"\nchoose flavor: "<<endl;
    cout<< "\n1. Mango\n2. Ube\n3.Caramel\n4. Chocolate\n5. Sans Rival\n";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. Roll Cake\n2. Standard Cake\n";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back({"Mango Roll Cake", 550});
        else if (choice2 == 2) cart.push_back({"Mango Cake", 1150});
        break;

        case 2:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Ube Roll Cake", 518});
        else if (choice2 == 2) cart.push_back({"Ube Cake", 880});
        break;

        case 3:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Caramel Roll Cake", 480});
        else if (choice2 == 2) cart.push_back({"Caramel Cake", 1120});
        break;

        case 4:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Chocolate Roll Cake", 460});
        else if (choice2 == 2) cart.push_back({"Chocolate Cake", 920});
        break;

        case 5:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. Roll Cake\n2. Standard Cake ";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Sansrival Roll Cake", 590});
        else if (choice2 == 2) cart.push_back({"Sansrival Cake", 1050});
        break;
            
        default: cout<< "Invalid Choice";
    }
}

void WeddingCakeMenu() {
    int choice, choice2;
    cout<<"\nchoose flavor: "<<endl;
    cout<< "\n1. Raspberry and Almond Meringue\n2. Lemon Elderflower\n3. Chocolate and Salted Caramel\n4. Pistachio and Sour Cherry\n5. Red Velvet Cheesecake Mousse\n";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back({"Raspberry and Almond Meringue (1-Tier)", 4000});
        else if (choice2 == 2) cart.push_back({"Raspberry and Almond Meringue (2-Tier)", 8200});
        else if (choice2 == 3) cart.push_back({"Raspberry and Almond Meringue (3-Tier)", 16000});
        else if (choice2 == 4) cart.push_back({"Raspberry and Almond Meringue (4-Tier+)", 26500});
        break;

        case 2:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Lemon Elderflower (1-Tier)", 4200});
        else if (choice2 == 2) cart.push_back({"Lemon Elderflower (2-Tier)", 8800});
        else if (choice2 == 3) cart.push_back({"Lemon Elderflower (3-Tier)", 17000});
        else if (choice2 == 4) cart.push_back({"Lemon Elderflower (4-Tier+)", 28000});
        break;

        case 3:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Chocolate and Salted Caramel (1-Tier)", 3800});
        else if (choice2 == 2) cart.push_back({"Chocolate and Salted Caramel (2-Tier)", 7800});
        else if (choice2 == 3) cart.push_back({"Chocolate and Salted Caramel (3-Tier)", 15500});
        else if (choice2 == 4) cart.push_back({"Chocolate and Salted Caramel (4-Tier+)", 25800});
        break;

        case 4:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Pistachio and Sour Cherry (1-Tier)", 4800});
        else if (choice2 == 2) cart.push_back({"Pistachio and Sour Cherry (2-Tier)", 9500});
        else if (choice2 == 3) cart.push_back({"Pistachio and Sour Cherry (3-Tier)", 18500});
        else if (choice2 == 4) cart.push_back({"Pistachio and Sour Cherry (4-Tier+)", 31000});
        break;

        case 5:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Red Velvet Cheesecake Mousse (1-Tier)", 3500});
        else if (choice2 == 2) cart.push_back({"Red Velvet Cheesecake Mousse (2-Tier)", 7500});
        else if (choice2 == 3) cart.push_back({"Red Velvet Cheesecake Mousse (3-Tier)", 15000});
        else if (choice2 == 4) cart.push_back({"Red Velvet Cheesecake Mousse (4-Tier+)", 25000});
        break;
            
        default: cout<< "Invalid Choice";
    }

}

void addons() {
    int choice, choice2;
    
    cout<<"\nchoose add-ons: "<<endl;
     cout<< "\n1. Cupcakes\n2. Cookies\n3. Brownies\n";
     cin>>choice;

     switch (choice) {
        case 1: 
        cout<<"\nchoose what flavor: "<<endl;
        cout<< "\n1. Molten Chocolate Lava\n2. Lemon Meringue\n3. Blueberry Burst\n4. Strawberry Shortcake\n5. Spiced Pumpkin\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Molten Chocolate Lava", 140});
        else if (choice2 == 2) cart.push_back({"Lemon Meringue", 130});
        else if (choice2 == 3) cart.push_back({"Blueberry Burst", 120});
        else if (choice2 == 4) cart.push_back({"Strawberry Shortcake", 150});
        else if (choice2 == 5) cart.push_back({" Spiced Pumpkin", 130});
        break;

        case 2: 
        cout<<"\nchoose what flavor: "<<endl;
        cout<< "\n1. Biscoff Cookie Butter\n2. Oatmeal Raisin\n3. Chocolate Chip\n4. Queso de Bolae\n5. S'mores\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Biscoff Cookie Butter", 180});
        else if (choice2 == 2) cart.push_back({"Oatmeal Raisin", 80});
        else if (choice2 == 3) cart.push_back({"Chocolate Chip", 85});
        else if (choice2 == 4) cart.push_back({"Queso de Bolae", 140});
        else if (choice2 == 5) cart.push_back({"S'mores", 160});
        break;

        case 3: 
        cout<<"\nchoose what flavor: "<<endl;
        cout<< "\n1. Triple Chocolate Chunk\n2. Cookies and Cream\n3. Walnut Fudge\n4. Cream Cheese Swirl\n5. Matcha\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Triple Chocolate Chunk", 75});
        else if (choice2 == 2) cart.push_back({"Cookies and Cream", 70});
        else if (choice2 == 3) cart.push_back({"Walnut Fudge", 80});
        else if (choice2 == 4) cart.push_back({"Cream Cheese Swirl", 110});
        else if (choice2 == 5) cart.push_back({"Matcha", 120});
        break;
     }
}

void Menu() {
    int choice;
    
    cout<<"\nchoose type of cake: "<<endl;
    cout<< "\n1. Birthday Cake\n2. Wedding Cake\n";
    cin>>choice;

    switch (choice) {
        case 1: BirthdayCakeMenu(); break;
        case 2: WeddingCakeMenu(); break;
        default: cout<< "Invalid Choice";
    }

    
}

void checkout() {
    double total = 0, amount, final, balance, change;
    int discount;
    bool choice, valid;
    string label;

    cout << "\n--- Receipt ---\n";
    for (const auto &item : cart) {
        cout << item.name << " - " << item.price << "\n";
        total += item.price;
    }
    cout << "Total: " << total << "\n";
    
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
            break;
        case 2:
            amount = total * 0.20;
            label = "PWD (20%)";
            break;
        case 3:
            amount = total * 0.10;
            label = "Student (10%)";
            break;
        case 4:
            amount = 0;
            label = "None";
            break;
        default:
            cout << "\nInvalid choice. Try again\n";
            choice = false;
            break;
    }
} while (!choice);

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
    } while (choice != 3);

    return 0;
}