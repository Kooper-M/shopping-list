#pragma once
#include "ShoppingList.h"

class ConsoleUI {
    public:
        void run();
        ConsoleUI(const ShoppingList& list);

    private:
        //bool validStringInput(const std::string& prompt);
        int getIntInput(const std::string& prompt);
        double getDoubleInput(const std::string& prompt);

        void displayMenu();
        void handleAddItem();
        void handleEditItem();
        void handleRemoveItem();

        ShoppingList list_;
};
