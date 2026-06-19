#pragma once
#include <vector>

#include "Item.h"

class ShoppingList {
public:
    void addItem(const Item& new_item);
    void removeItem(const std::string& item_name); 
    void removeItem(const int listNumber);
    void printList() const;
    Item* get_item(const std::string& item_name);
    Item* get_item(const int listNumber);
    static void printItem(const Item& item);
    bool saveList() const;
    bool loadList(const std::string& inputFileName);

private:
    std::vector<Item> items_;
    void clearList();
};