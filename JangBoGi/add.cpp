#include "add.h"
#include "food.h"
#include "home.h"

bool add()
{
	system("cls");
	string a;
	string r1, r2, r3;
	int i;
	cout << "�߰��� ����� �̸��� �Է����ּ��� (ó�� ȭ������ ���ư����� x�� �Է����ּ���): ";
	cin >> a;
	if (a == "x" || a == "X") { 
		return false;
	}
	cout << "�߰��� ����� ������ �Է����ּ��� ( 1:��� 2:���� 3:ä�� 4:�ҽ� 5:���� 6:�� ��): ";
	cin >> i;
	
	if (cin.fail())                                                                                   
	{
		cout << "�߸��� �Է��Դϴ�.";
		Sleep(1000);
		cin.clear();
		cin.ignore(10, '\n');
	}

	if (i == 1)
	{
		if (!(isexist_meat(a)))
		{
			FILE* writeFile = fopen("meat.txt", "a");
			cout << "ù��° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r1;
			cout << "�ι�° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r2;
			cout << "����° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r3;
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r1.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r2.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r3.c_str());	
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}

	}
	else if (i == 2)
	{
		if (!(isexist_fish(a)))
		{
			FILE* writeFile = fopen("fish.txt", "a");
			cout << "ù��° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r1;
			cout << "�ι�° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r2;
			cout << "����° �����Ǹ� �Է��ϼ��� (���ٸ� x�� �Է��ϼ���): ";
			cin >> r3;
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r1.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r2.c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, r3.c_str());
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 3)
	{
		if (!(isexist_veget(a)))
		{
			FILE* writeFile = fopen("veget.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 4)
	{
		if (!(isexist_sauce(a)))
		{
			FILE* writeFile = fopen("sauce.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 5)
	{
		if (!(isexist_drink(a)))
		{
			FILE* writeFile = fopen("drink.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}
	}
	else if (i == 6)
	{
		if (!(isexist_other(a)))
		{
			FILE* writeFile = fopen("other.txt", "a");
			fprintf(writeFile, "\n");
			fprintf(writeFile, a.c_str());
			fclose(writeFile);
			cout << "���������� �Էµƽ��ϴ�.";
			Sleep(1000);
			return true;
		}
		else
		{
			cout << "�̹� �����ϴ� ����� �Դϴ�.\n";
			Sleep(1000);
			return true;
		}
	}
	else
	{
		cout << "�߸��� �Է��Դϴ�\n";
		return true;
	}
}

bool isexist_meat(string s)
{
	FILE* readFile = fopen("meat.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_fish(string s)
{
	FILE* readFile = fopen("fish.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_veget(string s)
{
	FILE* readFile = fopen("veget.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_drink(string s)
{
	FILE* readFile = fopen("drink.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_sauce(string s)
{
	FILE* readFile = fopen("sauce.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_other(string s)
{
	FILE* readFile = fopen("other.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_freeze(string s)
{
	FILE* readFile = fopen("freeze.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_room(string s)
{
	FILE* readFile = fopen("room.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}

bool isexist_refri(string s)
{
	FILE* readFile = fopen("refrigeration.txt", "r"); //r �� �б���
	if (readFile != NULL)
	{
		char buf[2048];
		while (!feof(readFile))
		{
			fgets(buf, sizeof(buf), readFile);
			char name[32];


			char* ptr = strtok(buf, " ");
			strcpy(name, ptr);
			if (name == s)
			{
				return true;
			}
		}
	}
	return false;
}