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
	init(meat, "����");
	vector<Food> fish;
	init(fish, "���");
	vector<Food> veget;
	init(veget, "ä��");
	vector<Food> sauce;
	init(sauce, "�ҽ�");
	vector<Food> drink;
	init(drink, "����");
	vector<Food> other;
	init(other, "��Ÿ");

	vector<Food> refrigeration;
	init(refrigeration, "����");
	vector<Food> freeze;
	init(freeze, "�õ�");
	vector<Food> room;
	init(room, "���");
	
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
				init(refrigeration, "����");
				init(freeze, "�õ�");
				init(room, "���");
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
				init(meat, "����");
				init(fish, "���");
				init(veget, "ä��");
				init(sauce, "�ҽ�");
				init(drink, "����");
				init(other, "��Ÿ");
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