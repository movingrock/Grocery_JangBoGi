#include "home.h"
#include "menu.h"
#include "food.h"
#include "add.h"
#include <Windows.h>
#include <stdlib.h>

int main()
{
	refrigerator* ref = new refrigerator("NULL", 0);
	
	vector<Food> meat;
	init(meat, "육류");
	vector<Food> fish;
	init(fish, "어류");
	vector<Food> veget;
	init(veget, "채소");
	vector<Food> sauce;
	init(sauce, "소스");
	vector<Food> drink;
	init(drink, "음료");
	vector<Food> other;
	init(other, "기타");

	vector<Food> refrigeration;
	init(refrigeration, "냉장");
	vector<Food> freeze;
	init(freeze, "냉동");
	vector<Food> room;
	init(room, "상온");
	
	while (1)
	{
		system(" mode  con lines=25   cols=105 ");
		system("cls");
		init();
		title();
		int menucode = menudraw();
		if (menucode == 0)
		{
			system(" mode  con lines=28   cols=70 ");
			ref->setPosition("fridge");
			
			while (1) {
				init(refrigeration, "냉장");
				init(freeze, "냉동");
				init(room, "상온");
				ref->show_inventory(refrigeration, freeze, room);
				if (ref->getKey(meat, fish, veget, sauce, drink, other, refrigeration, freeze, room) == true) {
					Sleep(500);
					system("cls");
				}
				else {
					break;
				}
			}
		}
		else if (menucode == 1)
		{
			system(" mode  con lines=30   cols=140 ");
			ref->setPosition("meat");
			
			while (1) {
				init(meat, "육류");
				init(fish, "어류");
				init(veget, "채소");
				init(sauce, "소스");
				init(drink, "음료");
				init(other, "기타");
				ref->show_ingredient(meat, fish, veget, sauce, drink, other);
				if (ref->getKey(meat, fish, veget, sauce, drink, other, refrigeration, freeze, room) == true) {
					Sleep(100);
					system("cls");
				}
				else {
					break;
				}
			}
		}
		else if (menucode == 2)
		{
			while (1)
			{
				if (add() == true) {
					system("cls");
				}
				else {
					break;
				}
			}
			
		}
		else if (menucode == 3)
		{
			return 0;
			system("cls");
		}
		
	}
	system("pause");
}