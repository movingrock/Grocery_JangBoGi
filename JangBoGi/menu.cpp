#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

#include "menu.h"
#include "add.h"

using namespace std;

refrigerator::refrigerator(string position = "NULL", int cursor = 0) { //생성자
	this->position = position;
	this->cursor = cursor;
}

void refrigerator::setPosition(string position) { //커서의 위치값 수정
	this->position = position;
}

void refrigerator::textcolor(int foreground, int background) //글자에 색과 배경색넣기
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//키 입력 받기 (x or X 키로 뒤로가기 / 방향키로 표 안을 이동가능)
bool refrigerator::getKey(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other, vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) {
	char c; // 키 입력
	int i; // 재료 상태(냉장, 냉동, 상온)
	int y = 0, m = 0, d = 0;
	time_t timer;
	struct tm* t;
	timer = time(NULL); 
	t = localtime(&timer);
	bool result;
	if (_kbhit()) {
		c = _getch();
		if (c == 88 || c == 120) {
			cursor = 0;
			return false;
		}
		if (c == 13&&cursor>0) {
			if (position == "meat")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result==false|| t->tm_year + 1900>y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon+1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
			

				if (i == 1)
				{
					if (!isexist_refri(meat[cursor + excess_mt].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, meat[cursor + excess_mt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, meat[cursor + excess_mt].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(meat[cursor + excess_mt].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, meat[cursor + excess_mt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, meat[cursor + excess_mt].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(meat[cursor + excess_mt].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, meat[cursor + excess_mt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, meat[cursor + excess_mt].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}

			}
			else if (position == "fish")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result == false || t->tm_year + 1900 > y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon + 1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}

				if (i == 1)
				{
					if (!isexist_refri(fish[cursor + excess_fs].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, fish[cursor + excess_fs].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, fish[cursor + excess_fs].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(fish[cursor + excess_fs].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, fish[cursor + excess_fs].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, fish[cursor + excess_fs].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(fish[cursor + excess_fs].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, fish[cursor + excess_fs].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, fish[cursor + excess_fs].getRecipe1().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}

			}
			else if (position == "veget")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result == false || t->tm_year + 1900 > y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon + 1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}

				if (i == 1)
				{
					if (!isexist_refri(veget[cursor + excess_vt].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor + excess_vt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(veget[cursor + excess_vt].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor + excess_vt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(veget[cursor + excess_vt].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, veget[cursor + excess_vt].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
			}
			else if (position == "drink")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result == false || t->tm_year + 1900 > y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon + 1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}

				if (i == 1)
				{
					if (!isexist_refri(drink[cursor + excess_dk].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor + excess_dk].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(drink[cursor + excess_dk].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor + excess_dk].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(drink[cursor + excess_dk].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, drink[cursor + excess_dk].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
			}
			else if (position == "sauce")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result == false || t->tm_year + 1900 > y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon + 1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}

				if (i == 1)
				{
					if (!isexist_refri(sauce[cursor + excess_sc].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor + excess_sc].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 2)
				{
					if (!isexist_freeze(sauce[cursor + excess_sc].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor + excess_sc].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(sauce[cursor + excess_sc].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, sauce[cursor + excess_sc].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
			}
			else if (position == "other")
			{
				cout << "재료의 상태를 입력하세요: (1.냉장 2.냉동 3.상온) ";
				cin >> i;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (i != 1 && i != 2 && i != 3)
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				cout << "재료의 유통기한을 입력하세요(ex: 2022 03 01): ";
				cin >> y >> m >> d;
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				if (cin.fail())
				{
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					cin.clear();
					cin.ignore(10, '\n');
					return true;
				}
				result = checkDate(y, m, d);
				if (result == false || t->tm_year + 1900 > y) {
					cout << "잘못된 입력입니다.";
					Sleep(1000);
					return true;
				}
				if (t->tm_year + 1900 == y)
				{
					if (t->tm_mon + 1 > m)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}
				if (t->tm_year + 1900 == y && t->tm_mon + 1 == m)
				{
					if (t->tm_mday >= d)
					{
						cout << "잘못된 입력입니다.";
						Sleep(1000);
						return true;
					}
				}

				if (i == 1)
				{
					if (!isexist_refri(other[cursor + excess_ot].getName()))
					{
						FILE* writeFile = fopen("refrigeration.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor + excess_ot].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}

				}
				else if (i == 2)
				{
					if (!isexist_freeze(other[cursor + excess_ot].getName()))
					{
						FILE* writeFile = fopen("freeze.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor + excess_ot].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
				else if (i == 3)
				{
					if (!isexist_room(other[cursor + excess_ot].getName()))
					{
						FILE* writeFile = fopen("room.txt", "a");
						fprintf(writeFile, "\n");
						fprintf(writeFile, other[cursor + excess_ot].getName().c_str());
						fprintf(writeFile, " ");
						fprintf(writeFile, "x x x");
						fprintf(writeFile, " ");
						fprintf(writeFile, to_string(y).c_str()); // 재료 1 2 3 2000
						fprintf(writeFile, " ");// 재료 1 2 3 2000 
						fprintf(writeFile, to_string(m).c_str()); // 재료 1 2 3 2000 2
						fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
						fprintf(writeFile, to_string(d).c_str()); // 재료 1 2 3 2000 2 2 2
						fclose(writeFile);
						cout << "성공적으로 입력됐습니다.";
						Sleep(1000);
						return true;
					}
					else
					{
						cout << "이미 존재하는 식재료 입니다.\n";
						Sleep(100);
						return true;
					}
				}
			}
		}
		if (c == -32) {
			c = _getch();

			switch (c) {
			case LEFT:
				if (position == "freezer") {
					position = "fridge";
					if (refrigeration.size() < cursor)
						cursor = refrigeration.size() - 1;
				}
				else if (position == "room") {
					position = "freezer";
					if (freeze.size() < cursor)
						cursor = freeze.size() - 1;
				}
				else if (position == "fish") {
					position = "meat";
					if (meat.size() < cursor)
						cursor = meat.size() - 1;
				}
				else if (position == "veget") {
					position = "fish";
					if (fish.size() < cursor)
						cursor = fish.size() - 1;
				}
				else if (position == "sauce") {
					position = "veget";
					if (veget.size() < cursor)
						cursor = veget.size() - 1;
				}
				else if (position == "drink") {
					position = "sauce";
					if (sauce.size() < cursor)
						cursor = sauce.size() - 1;
				}
				else if (position == "other") {
					position = "drink";
					if (drink.size() < cursor)
						cursor = drink.size() - 1;
				}
				return true;
				break;

			case RIGHT:
				if (position == "fridge") {
					position = "freezer";
					if (freeze.size() < cursor)
						cursor = freeze.size() - 1;
				}
				else if (position == "freezer") {
					position = "room";
					if (room.size() < cursor)
						cursor = room.size() - 1;
				}
				else if (position == "meat") {
					position = "fish";
					if (fish.size() < cursor)
						cursor = fish.size() - 1;
				}
				else if (position == "fish") {
					position = "veget"; 
					if (veget.size() < cursor)
						cursor = veget.size() - 1;
				}
				else if (position == "veget") {
					position = "sauce";
					if (sauce.size() < cursor)
						cursor = sauce.size() - 1;
				}
				else if (position == "sauce") {
					position = "drink";
					if (drink.size() < cursor)
						cursor = drink.size() - 1;
				}
				else if (position == "drink") {
					position = "other";
					if (other.size() < cursor)
						cursor = other.size() - 1;
				}
				return true;
				break;

			case UP:
				if (excess_fr > 0 && position == "fridge") {
					excess_fr -= 1;
				}
				else if (excess_fz > 0 && position == "freezer") {
					excess_fz -= 1;
				}
				else if (excess_ro > 0 && position == "room") {
					excess_ro -= 1;
				}
				else if (excess_mt > 0 && position == "meat") {
					excess_mt -= 1;
				}
				else if (excess_fs > 0 && position == "fish") {
					excess_fs -= 1;
				}
				else if (excess_vt > 0 && position == "veget") {
					excess_vt -= 1;
				}
				else if (excess_sc > 0 && position == "sauce") {
					excess_sc -= 1;
				}
				else if (excess_dk > 0 && position == "drink") {
					excess_dk -= 1;
				}
				else if (excess_ot > 0 && position == "other") {
					excess_ot -= 1;
				}
				else if (cursor >= 1 && cursor <= 20) {
					cursor -= 1;
				}
				return true;
				break;
			case DOWN:
				if (cursor < 20) {
					if (position == "fridge" && cursor < refrigeration.size() - 1) {
						cursor += 1;
					}
					else if (position == "freezer" && cursor < freeze.size() - 1) {
						cursor += 1;
					}
					else if (position == "room" && cursor < room.size() - 1) {
						cursor += 1;
					}
					else if (position == "meat" && cursor < meat.size() - 1) {
						cursor += 1;
					}
					else if (position == "fish" && cursor < fish.size() - 1) {
						cursor += 1;
					}
					else if (position == "veget" && cursor < veget.size() - 1) {
						cursor += 1;
					}
					else if (position == "sauce" && cursor < sauce.size() - 1) {
						cursor += 1;
					}
					else if (position == "drink" && cursor < drink.size() -1) {
						cursor += 1;
					}
					else if (position == "other" && cursor < other.size() - 1) {
						cursor += 1;
					}
				}
				else if (cursor == 20) {
					if (position == "fridge") {
						if (cursor + excess_fr + 1 < refrigeration.size())
						excess_fr += 1;
					}
					else if (position == "freezer") {
						if (cursor + excess_fz + 1 < freeze.size())
						excess_fz += 1;
					}
					else if (position == "room") {
						if (cursor + excess_ro + 1 < room.size())
						excess_ro += 1;
					}
					else if (position == "meat") {
						if(cursor + excess_mt +1 < meat.size())
							excess_mt += 1;
					}
					else if (position == "fish") {
						if (cursor + excess_fs + 1 < fish.size())
							excess_fs += 1;
					}
					else if (position == "veget") {
						if (cursor + excess_vt + 1 < veget.size())
							excess_vt += 1;
					}
					else if (position == "sauce") {
						if (cursor + excess_sc + 1 < sauce.size())
							excess_sc += 1;
					}
					else if (position == "drink") {
						if (cursor + excess_dk + 1 < drink.size())
							excess_dk += 1;
					}
					else if (position == "other") {
						if (cursor + excess_ot + 1 < other.size())
						excess_ot += 1;
					}
				}
				return true;
				break;
			}
		}
		if (c == 'd' || c == 'D') {
			if (position == "meat")
				deleteData(meat, cursor + excess_mt);
			else if (position == "fish")
				deleteData(fish, cursor + excess_fs);
			else if (position == "veget")
				deleteData(veget, cursor + excess_vt);
			else if (position == "sauce")
				deleteData(sauce, cursor + excess_sc);
			else if (position == "drink")
				deleteData(drink, cursor + excess_dk);
			else if (position == "other")
				deleteData(other, cursor + excess_ot);

			else if (position == "fridge")
				deleteData(refrigeration, cursor + excess_fr);
			else if (position == "freezer")
				deleteData(freeze, cursor + excess_fz);
			else if (position == "room")
				deleteData(room, cursor + excess_ro);
			else
				return true;
			return true;
		}
	}
	return true;
}

void refrigerator::show_inventory(vector<Food> refrigeration, vector<Food> freeze, vector<Food> room) //냉장, 냉동, 실온 리스트를 인자로 받고 출력
{
	int i;
	cout << "+==============================================================+\n";
	cout << "|";
	if (position == "fridge") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       냉장고";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       냉장고";
	}

	cout << "|";
	if (position == "freezer") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       냉동실";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       냉동실";
	}

	cout << "|";
	if (position == "room") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       실온";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       실온";
	}
	cout << "|";
	cout << endl;

	cout << "|==============================================================|\n";
	for (i = 1; i <= 20; i++) {
		if (position == "fridge" && cursor == i) {
			if (refrigeration.size() <= i + excess_fr) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_fr << left << setw(17) << refrigeration[i + excess_fr].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (refrigeration.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_fr << left << setw(17) << refrigeration[i + excess_fr].getName();
			}
		}

		if (position == "freezer" && cursor == i) {
			if (freeze.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_fz << left << setw(17) << freeze[i + excess_fz].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (freeze.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_fz << left << setw(17) << freeze[i + excess_fz].getName();
			}
		}

		if (position == "room" && cursor == i) {
			if (room.size() <= i) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_ro << left << setw(17) << room[i + excess_ro].getName();
				textcolor(WHITE, BLACK);
			}
			cout << "|" << endl;
		}
		else {
			if (room.size() <= i) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				cout << "|" << left << setw(3) << i + excess_ro << left << setw(17) << room[i + excess_ro].getName() << "|" << endl;
			}
		}
	}
	cout << "+==============================================================+\n";
	for (int i = 1; i <= 20; i++) {
      //cout << refrigeration.size(); ==> 1
      if (position == "fridge" && cursor == i) {
         if (i < refrigeration.size()) {
            cout << refrigeration[cursor + excess_fr].getName() << "의 레시피는 ";
            if (refrigeration[cursor + excess_fr].getRecipe() != "")
               cout << refrigeration[cursor + excess_fr].getRecipe() << "입니다." << endl;
            else
               cout << "없습니다." << endl;

            cout << "유통기한은 " << refrigeration[cursor + excess_fr].getFYear() << "년 " << refrigeration[cursor].getFMonth() << "월 " << refrigeration[cursor].getFDay() << "일" << "까지입니다." << " ";
            refrigeration[cursor].showLeftDate();
         }
      }
      else if (position == "freezer" && cursor == i) {
         if (i < freeze.size()) {
            cout << freeze[cursor + excess_fz].getName() << "의 레시피는 ";
            if (freeze[cursor + excess_fz].getRecipe() != "")
               cout << freeze[cursor + excess_fz].getRecipe() << "입니다." << endl;
            else
               cout << "없습니다." << endl;

            cout << "유통기한은 " << freeze[cursor + excess_fz].getFYear() << "년 " << freeze[cursor].getFMonth() << "월 " << freeze[cursor].getFDay() << "일" << "까지입니다." << " ";
            freeze[cursor + excess_fz].showLeftDate();
         }
      }
      else if (position == "room" && cursor == i) {
         if (i < room.size()) {
            cout << room[cursor + excess_ro].getName() << "의 레시피는 ";
            if (room[cursor + excess_ro].getRecipe() != "")
               cout << room[cursor + excess_ro].getRecipe() << "입니다." << endl;
            else
               cout << "없습니다." << endl;

            cout << "유통기한은 " << room[cursor + excess_ro].getFYear() << "년 " << room[cursor].getFMonth() << "월 " << room[cursor].getFDay() << "일" << "까지입니다." << " ";
            room[cursor + excess_ro].showLeftDate();
         }
      }
   }
}

void refrigerator::show_ingredient(vector<Food> meat, vector<Food> fish, vector<Food> veget, vector<Food> sauce, vector<Food> drink, vector<Food> other) {
	int i;
	cout << "+=============================================================================================================================+\n";
	cout << "|";
	if (position == "meat") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       고기";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       고기";
	}

	cout << "|";
	if (position == "fish") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       생선";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       생선";
	}

	cout << "|";
	if (position == "veget") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       채소";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       채소";
	}

	cout << "|";
	if (position == "sauce") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       소스";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       소스";
	}


	cout << "|";
	if (position == "drink") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       음료";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       음료";
	}

	cout << "|";
	if (position == "other") {
		textcolor(WHITE, RED);
		cout << left << setw(20) << "       그 외";
		textcolor(WHITE, BLACK);
	}
	else {
		cout << left << setw(20) << "       그 외";
	}
	cout << "|";
	cout << endl;

	cout << "|=============================================================================================================================|\n";
	for (i = 1; i <= 20; i++) {
		if (position == "meat" && cursor == i) {
			if (meat.size() <= i + excess_mt) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_mt << left << setw(17) <<  meat[i + excess_mt].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (meat.size() <= i + excess_mt) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_mt << left << setw(17) << meat[i + excess_mt].getName();
			}
		}

		if (position == "fish" && cursor == i) {
			if (fish.size() <= i + excess_fs) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_fs << left << setw(17) << fish[i + excess_fs].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (fish.size() <= i + excess_fs) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_fs << left << setw(17) << fish[i + excess_fs].getName();
			}
		}

		if (position == "veget" && cursor == i) {
			if (veget.size() <= i + excess_vt) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_vt << left << setw(17) << veget[i + excess_vt].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (veget.size() <= i + excess_vt) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_vt << left << setw(17) << veget[i + excess_vt].getName();
			}
		}

		if (position == "sauce" && cursor == i) {
			if (sauce.size() <= i + excess_sc) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_sc << left << setw(17) << sauce[i + excess_sc].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (sauce.size() <= i + excess_sc) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_sc << left << setw(17) << sauce[i + excess_sc].getName();
			}
		}

		if (position == "drink" && cursor == i) {
			if (drink.size() <= i + excess_dk) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_dk << left << setw(17) << drink[i + excess_dk].getName();
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (drink.size() <= i + excess_dk) {
				cout << "|" << left << setw(20) << "";
			}
			else {
				cout << "|" << left << setw(3) << i + excess_dk << left << setw(17) << drink[i + excess_dk].getName();
			}
		}

		if (position == "other" && cursor == i) {
			if (other.size() <= i + excess_ot) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				textcolor(WHITE, RED);
				cout << "|" << left << setw(3) << i + excess_ot << left << setw(17) << other[i + excess_ot].getName() << "|" << endl;
				textcolor(WHITE, BLACK);
			}
		}
		else {
			if (other.size() <= i + excess_ot) {
				cout << "|" << left << setw(20) << "" << "|" << endl;
			}
			else {
				cout << "|" << left << setw(3) << i + excess_ot << left << setw(17) << other[i + excess_ot].getName() << "|" << endl;
			}
		}
	}
	cout << "+=============================================================================================================================+\n";
}

void refrigerator::deleteData(vector<Food>& food, size_t index) //index는 cursor임.
{
	//cout << "index : " << index << " food.size():" << food.size() << endl;
	if (index >= food.size())
		return;
	food.erase(food.begin() + index);
	writeInFile(food);
}

int refrigerator::checkDate(int year, int month, int day) {

	if (month <= 0 || month>12)
		return false;

	if ((month % 2 == 1))  
	{
		if (month <= 7)
			if (day <= 0 || day > 31) return false;
			else    
				if (day <= 0 || day > 30) return false;
	}
	else 
	{
		if (month <= 6) {
			if (month == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // leap year  
				{
					if (day <= 0 || day > 30) return false;
				}
				else if (day <= 0 || day > 28) return false;

			}
			if (day <= 0 || day > 30) return false;
		}
		else {  

			if (day <= 0 || day > 31) return false;
		}
	}
	return true;
	
}