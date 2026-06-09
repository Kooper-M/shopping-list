#pragma once
#include <vector>

#include "Item.h"

class ShoppingList {
public:
    void addItem(const Item& new_item);
    void removeItem(const std::string& item_name); 
    void removeItem(const int listNumber);
    void printList() const;


private:
    std::vector<Item> items_;

};