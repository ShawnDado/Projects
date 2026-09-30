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
    int choice;
    int choice2;
    cout<<"\nchoose flavor: "<<endl;
    cout<< "\n1. Mango\n2. Ube\n3.Caramel\n4. Chocolate\n5. Sans Rival\n";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose size:\n ";
        cout<<"\n1.Roll Cake\n2. Standard Cake\n";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back({"Roll Cake", 550});
        else if (choice2 == 2) cart.push_back({"Standard Cake", 1150});
        break;

        case 2:
        cout<<"\nChoose size:\n ";
        cout<<"\n1.Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Roll Cake", 518});
        else if (choice2 == 2) cart.push_back({"Standard Cake", 880});
        break;

        case 3:
        cout<<"\nChoose size:\n ";
        cout<<"\n1.Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Roll Cake", 480});
        else if (choice2 == 2) cart.push_back({"Standard Cake", 1120});
        break;

        case 4:
        cout<<"\nChoose size:\n ";
        cout<<"\n1.Roll Cake\n2. Standard Cake\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Roll Cake", 460});
        else if (choice2 == 2) cart.push_back({"Standard Cake", 920});
        break;

        case 5:
        cout<<"\nChoose size:\n ";
        cout<<"\n1.Roll Cake\n2. Standard Cake ";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"Roll Cake", 590});
        else if (choice2 == 2) cart.push_back({"Standard Cake", 1050});
        break;
            
        default: cout<< "Invalid Choice";
    }
}

void WeddingCakeMenu() {
    int choice;
    int choice2;
    cout<<"\nchoose flavor: "<<endl;
    cout<< "\n1. Raspberry and Almond Meringue\n2. Lemon Elderflower\n3. Chocolate and Salted Caramel\n4. Pistachio and Sour Cherry\n5. Red Velvet Cheesecake Mousse\n";
    cin>>choice;
    
    switch (choice) {
        case 1:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;
        
        if (choice2 == 1) cart.push_back({"1-Tier", 4000});
        else if (choice2 == 2) cart.push_back({"2-Tier", 8200});
        else if (choice2 == 3) cart.push_back({"3-Tier", 16000});
        else if (choice2 == 4) cart.push_back({"4-Tier+", 26500});
        break;

        case 2:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"1-Tier", 4200});
        else if (choice2 == 2) cart.push_back({"2-Tier", 8800});
        else if (choice2 == 3) cart.push_back({"3-Tier", 17000});
        else if (choice2 == 4) cart.push_back({"4-Tier+", 28000});
        break;

        case 3:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"1-Tier", 3800});
        else if (choice2 == 2) cart.push_back({"2-Tier", 7800});
        else if (choice2 == 3) cart.push_back({"3-Tier", 15500});
        else if (choice2 == 4) cart.push_back({"4-Tier+", 25800});
        break;

        case 4:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"1-Tier", 4800});
        else if (choice2 == 2) cart.push_back({"2-Tier", 9500});
        else if (choice2 == 3) cart.push_back({"3-Tier", 18500});
        else if (choice2 == 4) cart.push_back({"4-Tier+", 31000});
        break;

        case 5:
        cout<<"\nChoose size:\n ";
        cout<<"\n1. 1-Tier (15-20 servings)\n2. 2-Tier (40-60 servings)\n3. 3-Tier (75-100 servings)\n4. 4-Tier+ (125-175+ servings)\n";
        cin>>choice2;

        if (choice2 == 1) cart.push_back({"1-Tier", 3500});
        else if (choice2 == 2) cart.push_back({"2-Tier", 7500});
        else if (choice2 == 3) cart.push_back({"3-Tier", 15000});
        else if (choice2 == 4) cart.push_back({"4-Tier+", 25000});
        break;
            
        default: cout<< "Invalid Choice";
    }

}

void GraduationCakeMenu() {

}

void Menu() {
    int choice;
    cout<<"\nchoose type of cake: "<<endl;
    cout<< "\n1. Birthday Cake\n2. Wedding Cake\n3. Graduation Cake\n";
    cin>>choice;

    switch (choice) {
        case 1: BirthdayCakeMenu(); break;
        case 2: WeddingCakeMenu(); break;
        case 3: GraduationCakeMenu(); break;
        default: cout<< "Invalid Choice";
    }

    
}

void checkout() {
    double total = 0;
    cout << "\n--- Receipt ---\n";
    for (const auto &item : cart) {
        cout << item.name << " - " << item.price << "\n";
        total += item.price;
    }
    cout << "Total: " << total << "\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Menu\n2. Add-ons\n3. Checkout\n> ";
        cin >> choice;

        switch (choice) {
            case 1: Menu(); break;
            case 3: checkout(); break;
            default:
            cout<< "\nInvalid";
            break;
        }
    } while (choice != 3);

    return 0;
}