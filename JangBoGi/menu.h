#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "food.h"

using namespace std;

class refrigerator {
private:
	std::string position;
	size_t cursor;
	int excess = 0;
	int excess_fr = 0;
	int excess_fz = 0;
	int excess_ro = 0;
	int excess_mt = 0;
	int excess_fs = 0;
	int excess_vt = 0;
	int excess_sc = 0;
	int excess_dk = 0;
	int excess_ot = 0;

public:
	refrigerator(string, int);
	void setPosition(string);
	void textcolor(int, int);
	bool getKey(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other, vector<Food> refrigeration, vector<Food> freeze, vector<Food> room);
	void show_inventory(vector<Food> fridge, vector<Food> freezer, vector<Food> room);
	void show_ingredient(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other);
	void deleteData(vector<Food>& food, size_t index); //Food 벡터에서 index에 해당하는 식재료 삭제 후 txt파일에서도 삭제 
	int checkDate(int year, int month, int day);
};