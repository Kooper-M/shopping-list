#include "ShoppingList.h"

#include <algorithm>
#include <iostream>
#include <print>
#include <fstream>
#include <sstream>

using namespace std;

void ShoppingList::addItem(const Item& new_item) {
    items_.push_back(new_item);
}

void ShoppingList::clearList() {
    items_.clear();
}

Item* ShoppingList::get_item(const std::string& item_name) {
    if (items_.empty()) {
        println("The list is empty, please add something to the list!");
        return nullptr;    
    }
    auto it = find_if(items_.begin(), items_.end(), [&item_name](const Item& item) {
        return item.name == item_name;
    });

    if (it == items_.end()) {
        println("That item does not exist!");
        return nullptr;
    } 

    return &(*it);
}

Item* ShoppingList::get_item(const int listNumber) {
    int itemIndex = listNumber - 1;
    if (itemIndex < 0 || itemIndex > items_.size()) {
        println("Invalid list number.");
        return nullptr;
    }
    
    return &items_[itemIndex];
}



void ShoppingList::removeItem(const std::string& item_name) {
    if (items_.empty()) {
        println("The list is empty, please add something to the list!");
        return;
    }

    auto it = find_if(items_.begin(), items_.end(), [&item_name](const Item& item) {
        return item.name == item_name;
    });
    if (it != items_.end()) {
        items_.erase(it);
    } else {
        println("{} not found!", item_name);
    }
}
void ShoppingList::removeItem(const int listNumber) {
    if (items_.empty()) {
        println("The list is empty, please add something to the list!");
        return;
    }

    int removalIndex = listNumber - 1;

    if (removalIndex >= 0 && removalIndex < items_.size())
        items_.erase(items_.begin() + removalIndex);
    else {
        println("That list number is invalid!");
    }
}
void ShoppingList::printList() const {
    int count = 1;
    double listTotal = 0;
    println("-----------------------------------------------");
    for (auto item : items_) {
        println("{}. {} | Price: ${} | Qty: {}", count++, item.name, item.price, item.quantity);
        listTotal += item.price;
    }
    println("Total: ${}", listTotal);
    println("-----------------------------------------------");
}

void ShoppingList::printItem(const Item& item) {
    println("-----------------------------------------------");
    println("{} | Price: ${} | Qty: {}", item.name, item.price, item.quantity);
    println("-----------------------------------------------");
}

bool ShoppingList::saveList() const {
    ofstream outFile("output.txt");

    if (!outFile.is_open()) {
        println("Something went wrong!");
        return false;
    }
    double total;
    for (auto item : items_) {
        outFile << item.name << "," << item.price << "," << item.quantity << "\n";
        total += item.price;
    }
    outFile << "Total: $" << total;
    outFile.close();
    println("File Saved!");
    return true;
}

bool ShoppingList::loadList(const std::string& inputFileName) {
    clearList();
    std::ifstream inFile(inputFileName);
    if (!inFile) {
        cerr << "Could Not Read File!";
        return false;
    }
    string line;
    while (getline(inFile, line)) {

        stringstream ss(line);
        string name;
        string priceString;
        string quantityString;

        getline(ss, name, ',');
        if (ss.eof()) {
            break;
        }
        getline(ss, priceString, ',');
        getline(ss, quantityString, ',');
        
        items_.push_back(Item{name, stod(priceString), stoi(quantityString)});
    }
    return true;
}