#include "ShoppingList.h"

#include <algorithm>
#include <iostream>
#include <print>

using namespace std;

void ShoppingList::addItem(const Item& new_item) {
    items_.push_back(new_item);
}

void ShoppingList::removeItem(const std::string& item_name) {
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
    println("The right method was called");
    int removalIndex = listNumber - 1;
    if (removalIndex < 0 || removalIndex < items_.size())
        items_.erase(items_.begin() + removalIndex);
    else {
        println("That list number is invalid");
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