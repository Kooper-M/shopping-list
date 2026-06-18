#include "Console.h"
#include "InputChecker.h"

#include <print>
#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;



//bool ConsoleUI::validStringInput(std::string str) {
//    if (str.empty()) {
//        return false;
//    }
//    return true;
//}

ConsoleUI::ConsoleUI(const ShoppingList& list) : list_(list) {}

void ConsoleUI::displayMenu() {
    println("1. Print List\n3. Add Item\n4. Remove Item\n5. Edit Item\n6. Exit");
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
    int inputQuantity;
    
    print("What item do you want to add: ");
    getline(cin >> ws, inputName);

    inputPrice = InputChecker::getDoubleInput("What's the price of the item: ");
    inputQuantity = InputChecker::getIntInput("How many of the item do you want to add: ");

    list_.addItem({inputName, inputPrice, inputQuantity});
}

void ConsoleUI::handleEditItem() {
    //pick list number to edit
    //pick what you want to edit
    //save changes
    string editInput = InputChecker::getStringInput("Enter list number or name of item to edit: ");
    Item* itemToEdit = nullptr;
    if (all_of(editInput.begin(), editInput.end(), ::isdigit)) {
        itemToEdit = list_.get_item(stoi(editInput));
    } else {
        itemToEdit = list_.get_item(editInput);
    }
    
    if (!itemToEdit) {
        println("That item does not exist!");
        return;
    }
    
    bool EditingPrompt = true;
    while (EditingPrompt) {
        ShoppingList::printItem(*itemToEdit);
        println("1. Edit Name\n3. Edit Price\n4. Edit Quantity\n5. Done Editing");
        int input = InputChecker::getIntInput("Pick an option: ");
        switch (input) {
            case 1: {
                itemToEdit->name = InputChecker::getStringInput("What is the new name: ");
                break;
            }
            case 3:
                itemToEdit->price = InputChecker::getDoubleInput("What is the new price: ");
                break;
            case 4:
                itemToEdit->quantity = InputChecker::getIntInput("What is the new quantity: ");
                break;
            case 5:
                EditingPrompt = false;
                break;
        }
    }

}

void ConsoleUI::run() {
    bool running = true;
    while (running) {
        displayMenu();
        int input = InputChecker::getIntInput("Pick an option: ");

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
                list_.printList();
                handleEditItem();
                break;
            case 6:
                running = false;
                break;
            default:
                println("That's not an option");
        }
    }
}


