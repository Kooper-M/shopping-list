#include "ShoppingList.h"

#include <algorithm>
#include <iostream>
#include <print>

using namespace std;

void ShoppingList::addItem(const Item& new_item) {
    items_.push_back(new_item);
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
    println("-----------------------------------------------");
    for (auto item : items_) {
        println("{}. {} | Price: ${} | Qty: {}", count++, item.name, item.price, item.quantity);
    }
    println("-----------------------------------------------");
}

void ShoppingList::printItem(const Item& item) {
    println("-----------------------------------------------");
    println("{} | Price: ${} | Qty: {}", item.name, item.price, item.quantity);
    println("-----------------------------------------------");
}