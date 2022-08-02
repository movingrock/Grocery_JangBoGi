#include "food.h"

string Food::getRecipe() const {
	string FullRecipe;
	for (int i = 0; i < 3; i++) {
		if (recipe[i] != "x" && recipe[i] != "X") {
			FullRecipe += recipe[i];
			if ((i < 2) && ((recipe[i + 1] != "x") && (recipe[i + 1] != "X")))
				FullRecipe += " ";
		}
	}
	if (FullRecipe == "")
		return "";
	return FullRecipe;
}

string Food::getRecipe1() const {
	string FullRecipe;
	for (int i = 0; i < 3; i++) {
		FullRecipe += recipe[i];
		if (i < 2)
			FullRecipe += " ";
	}
	return FullRecipe;
}

void Food::setName(string name) // �̸� ����
{
	this->name = name;
}

void Food::setShelfDate(int f_year, int f_month, int f_day)
{
	int days = 0;
	if ((thisYear <= f_year) && (f_year <= thisYear + 100))
	{
		if (1 <= f_month && f_month <= 12)
		{
			if (f_month == 1 || f_month == 3 || f_month == 5 || f_month == 7 || f_month == 8 || f_month == 10 || f_month == 12) {
				days = 31;
			}
			else if (f_month == 2) {
				days = 28;
			}
			else
				days = 30;

			if ((1 <= f_day) && (f_day <= days)) {
				this->f_year = f_year;
				this->f_month = f_month;
				this->f_day = f_day;
			}
			else {
				cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(1~" << days << ")\n" << endl;
				return;
			}

		}
		else {
			cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(1~12)\n" << endl;
			return;
		}
	}
	else {
		cout << getName() << "�� ���� �ٽ� �Է��Ͻÿ�(" << thisYear << "~)\n" << endl;
		return;
	}
}

void Food::setMakeFood() {
	cout << getName() << "���� ���� �� �ִ� ���� ����� �缳���մϴ�.";
	cin >> recipe[0] >> recipe[1] >> recipe[2];
}

void Food::setState() {
	string state;
	cout << getName() << "�� �������¸� �Է��Ͻÿ� : ";
	cin >> state;
	while (1) {
		if (state == "���" || state == "����" || state == "�õ�")
		{
			this->state = state;   return;
		}
		else {  //������ ���¿� �ش� �ȵǸ� ���Է�.
			cout << "���Է� : ";
			cin >> state;
		}
	}
}

void Food::setState1(string state) { // ��Ȳ�ǿ� ���̱� ���� �ۼ�
	if (state == "����" || state == "�õ�" || state == "���")
	{
		this->state = state;
		return;
	}
	else {
		cout << "�������� ���Է�: ";
		cin >> state;
	}
}

void Food::showLeftDate() {
	//if (state == "��") //���� ������� ����� �̺����̸� ������� ���X
	//	return;
	time_t shelfdate, today;
	double diff; //������Ѱ� ����ð� ��
	int day; //�� �� ���� �ϼ� ����
	struct tm user_stime; //����ð� ���� ��
	user_stime.tm_year = f_year - 1900;
	user_stime.tm_mon = f_month - 1;
	user_stime.tm_mday = f_day;
	user_stime.tm_hour = 0, user_stime.tm_min = 0, user_stime.tm_sec = 0, user_stime.tm_isdst = 0;
	shelfdate = mktime(&user_stime); //�������
	time(&today); //����ð�
	diff = difftime(shelfdate, today);
	day = (int)diff / (60 * 60 * 24); //���� ��

	//cout << "day : " << day << "diff: "<<diff  << endl;
	if (day >= 1)//��Ʋ �̻� ����
		cout << day + 1 << "�� ���ҽ��ϴ�." << endl;
	else if(day == 0 && diff >= 0)//������ �������
		cout << "1�� ���ҽ��ϴ�." << endl;
	else if (day == 0 && diff < 0) //������ �������
		cout << "��������� ���ñ����Դϴ�." << endl;
	else //����
		cout << (-1 * day) << "�� �������ϴ�." << endl;
}


//���Ͽ� �̸� �Էµ� ������ �ܿ� �߰��� �� ����.
void writeInFile(vector<Food>& food) { // txt���ϵ鿡 ������ write
	if (food.empty())
		return;
	if (food[0].getName() == "����") {
		FILE* writeFile = fopen("meat.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, food[i].getRecipe1().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "���") {
		FILE* writeFile = fopen("fish.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			fprintf(writeFile, " ");
			fprintf(writeFile, food[i].getRecipe1().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "ä��") { //veget[0].getName()
		FILE* writeFile = fopen("veget.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {  //ù ������ �Է� -> ���� -> �������Է� -> ... -> ���� -> �������Է�    ,,,,,, ������ �ѹ� �� ����ߵż� j=1�� ��.
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "�ҽ�") {
		FILE* writeFile = fopen("sauce.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "����") {
		FILE* writeFile = fopen("drink.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "�׿�") {
		FILE* writeFile = fopen("other.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "����") {
		FILE* writeFile = fopen("refrigeration.txt", "w");
		int i = 0;
		int j = 1;

		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // ���
				fprintf(writeFile, " "); // ��� 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x ����ǵ��� // ��� 1 2 3
				fprintf(writeFile, " ");// ��� 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // ��� 1 2 3 2000
				fprintf(writeFile, " ");// ��� 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // ��� 1 2 3 2000 2
				fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // ��� 1 2 3 2000 2 2 2
			}


			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "�õ�") {
		FILE* writeFile = fopen("freeze.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // ���
				fprintf(writeFile, " "); // ��� 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x ����ǵ��� // ��� 1 2 3
				fprintf(writeFile, " ");// ��� 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // ��� 1 2 3 2000
				fprintf(writeFile, " ");// ��� 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // ��� 1 2 3 2000 2
				fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // ��� 1 2 3 2000 2 2 2
			}


			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "���") {
		FILE* writeFile = fopen("room.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // ���
				fprintf(writeFile, " "); // ��� 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x ����ǵ��� // ��� 1 2 3
				fprintf(writeFile, " ");// ��� 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // ��� 1 2 3 2000
				fprintf(writeFile, " ");// ��� 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // ��� 1 2 3 2000 2
				fprintf(writeFile, " ");// ��� 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // ��� 1 2 3 2000 2 2 2
			}


			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	return;
} // �Է��ؼ� ���°� �ƴ϶� else ó�� ������. 


void init(vector<Food>& food, string s) { //s�� �´� ����� ������� �ʱ�ȭ�� ex) init(food, "����") ---> meat.txt�� �ۼ��� ������� food ���Ͱ� �ʱ�ȭ��.
	food.clear();
	if (s == "����") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "meat.txt", "r"); //readFile = fopen("meat.txt", "r"); 
		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32];
				char recipe2[32];
				char recipe3[32];

				char* ptr = strtok(buf, " ");
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);

				ptr = strtok(NULL, "\n");
				strcpy(recipe3, ptr);

				Food new_food(name, recipe1, recipe2, recipe3);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}
	if (s == "���") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "fish.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32];
				char recipe2[32];
				char recipe3[32];

				char* ptr = strtok(buf, " ");
				strcpy(name, ptr);
				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);
				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);
				ptr = strtok(NULL, "\n");
				strcpy(recipe3, ptr);
				Food new_food(name, recipe1, recipe2, recipe3);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}
	if (s == "ä��") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "veget.txt", "r");

		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}
	if (s == "�ҽ�") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "sauce.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}
	if (s == "����") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "drink.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}
	if (s == "��Ÿ") {
		FILE* readFile = NULL;
		fopen_s(&readFile, "other.txt", "r");
		if (readFile != NULL) {
			char buf[1024];
			while (!feof(readFile)) {
				fgets(buf, sizeof(buf), readFile);

				char name[32];

				char* ptr = strtok(buf, "\n");
				strcpy(name, ptr);
				Food new_food(name);
				food.push_back(new_food);

			}
		}
		fcloseall();
	}

	// ����, �õ�, ��� ��Ȳ�� ���̱� ���� �߰�
	if (s == "����") { // refrigeration
		FILE* readFile = NULL;
		fopen_s(&readFile, "refrigeration.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- ���� �޴� �κ�
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("����");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof���� �ݺ�
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // ����̸� x x x 2202 22 22
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe3, ptr);

				ptr = strtok(NULL, " ");
				strcpy(y, ptr);

				ptr = strtok(NULL, " ");
				strcpy(m, ptr);

				ptr = strtok(NULL, "\n");
				strcpy(d, ptr);

				Food new_food(name, recipe1, recipe2, recipe3, atoi(y), atoi(m), atoi(d));
				new_food.setState1("����");
				food.push_back(new_food);
			}
		}
		fcloseall();
	}

	if (s == "�õ�") { // freeze
		FILE* readFile = NULL;
		fopen_s(&readFile, "freeze.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- �õ� �޴� �κ�
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("�õ�");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof���� �ݺ�
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // ����̸� x x x 2202 22 22
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe3, ptr);

				ptr = strtok(NULL, " ");
				strcpy(y, ptr);

				ptr = strtok(NULL, " ");
				strcpy(m, ptr);

				ptr = strtok(NULL, "\n");
				strcpy(d, ptr);

				Food new_food(name, recipe1, recipe2, recipe3, atoi(y), atoi(m), atoi(d));
				new_food.setState1("�õ�");
				food.push_back(new_food);
			}
		}
		fcloseall();
	}

	if (s == "���") { // room
		FILE* readFile = NULL;
		fopen_s(&readFile, "room.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- ��� �޴� �κ�
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("���");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof���� �ݺ�
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // ����̸� x x x 2202 22 22
				strcpy(name, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe1, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe2, ptr);

				ptr = strtok(NULL, " ");
				strcpy(recipe3, ptr);

				ptr = strtok(NULL, " ");
				strcpy(y, ptr);

				ptr = strtok(NULL, " ");
				strcpy(m, ptr);

				ptr = strtok(NULL, "\n");
				strcpy(d, ptr);

				Food new_food(name, recipe1, recipe2, recipe3, atoi(y), atoi(m), atoi(d));
				new_food.setState1("�õ�");
				food.push_back(new_food);

			}

		}

		fcloseall();
	}
}
