#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    double price;
};

vector<Item> cart;  // holds every choice made, across all submenus

void Menu() {
    cout << "1. Coke - 50\n2. Juice - 60\n3. Water - 30\n";
    int choice;
    cin >> choice;

    if (choice == 1) cart.push_back({"Coke", 50});
    else if (choice == 2) cart.push_back({"Juice", 60});
    else if (choice == 3) cart.push_back({"Water", 30});
}

void addonsMenu() {
    cout << "1. Fries - 40\n2. Extra Cheese - 20\n";
    int choice;
    cin >> choice;

    if (choice == 1) cart.push_back({"Fries", 40});
    else if (choice == 2) cart.push_back({"Extra Cheese", 20});
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
            case 2: addonsMenu(); break;
            case 3: checkout(); break;
        }
    } while (choice != 3);

    return 0;
}