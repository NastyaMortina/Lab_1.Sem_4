#include <iostream> 
#include <clocale>
#include "TInterface.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	TInterface mainMenu;
	mainMenu.menu();
}