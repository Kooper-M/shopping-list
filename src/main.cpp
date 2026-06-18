#include <iostream>
#include <string>
#include <vector>
#include <print>

#include "Item.h"
#include "ShoppingList.h"
#include "Console.h"

using namespace std;



int main() {
    ShoppingList list;

    list.addItem({"eggs", 1.00, 3});
    list.addItem({"bacon", 3.00, 4});

    ConsoleUI console(list);
    console.run();
}

