#include <iostream>
#include <clocale>
#include "interface.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    Interface mainMenu;
    mainMenu.menu();
    system("pause");
    return 0;
}