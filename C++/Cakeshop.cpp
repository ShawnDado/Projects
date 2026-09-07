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
        }
    } while (choice != 3);

    return 0;
}