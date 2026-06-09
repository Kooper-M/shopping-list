#pragma once
#include "ShoppingList.h"

class ConsoleUI {
    public:
        void run();
        void addList(const ShoppingList& list);

    private:
        void displayMenu();
        void handleAddItem();
        void handleRemoveItem();

        ShoppingList list_;
};
