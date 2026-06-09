#include "Console.h"
#include <print>
#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

void ConsoleUI::displayMenu() {
    println("1. Print List\n3. Add Item\n4. Remove Item\n5. Exit");
}


void ConsoleUI::handleRemoveItem() {
    string removalInput;
    print("Enter name or list number of item to remove: ");
    //need to figure out how to parse as either a string or int
    cin >> removalInput;
    if (all_of(removalInput.begin(), removalInput.end(), ::isdigit)) {
        list_.removeItem(stoi(removalInput));
    } else {
        list_.removeItem(removalInput);
    }
}
void ConsoleUI::handleAddItem() {
    string inputName;
    double inputPrice;
    double inputQuantity;
    
    print("What item do you want to add: ");
    getline(cin >> ws, inputName);

    print("What's the price of the item: ");

    while (!(cin >> inputPrice) && ) {
        println("Invalid Input, please enter a valid price: ");
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );
    }
       

    print("How many of the item do you want to add? ");
    while(!(cin >> inputQuantity)) {
        print("Invalid input, please enter a valid quantity: ");
        cin.clear();
        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );
    }



    list_.addItem({inputName, inputPrice, static_cast<int>(std::round(inputQuantity))});
}

void ConsoleUI::run() {
    bool running = true;
    while (running) {
        displayMenu();
        print("Pick an option: ");
        int input = -1;
        cin >> input;
        

        switch (input) {
            case 1:
                list_.printList();
                break;
            case 3:
                handleAddItem();
                break;
            case 4: 
                list_.printList();
                handleRemoveItem();
                break;
            case 5:
                running = false;
                break;
            default:
                println("That's not an option");
        }
    }
}

void ConsoleUI::addList(const ShoppingList& list) {
    list_ = list;
}
