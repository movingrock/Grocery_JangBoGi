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

void Food::setName(string name) // 이름 세터
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
				cout << getName() << "의 일을 다시 입력하시오(1~" << days << ")\n" << endl;
				return;
			}

		}
		else {
			cout << getName() << "의 월을 다시 입력하시오(1~12)\n" << endl;
			return;
		}
	}
	else {
		cout << getName() << "의 년을 다시 입력하시오(" << thisYear << "~)\n" << endl;
		return;
	}
}

void Food::setMakeFood() {
	cout << getName() << "으로 만들 수 있는 음식 목록을 재설정합니다.";
	cin >> recipe[0] >> recipe[1] >> recipe[2];
}

void Food::setState() {
	string state;
	cout << getName() << "의 보관상태를 입력하시오 : ";
	cin >> state;
	while (1) {
		if (state == "상온" || state == "냉장" || state == "냉동")
		{
			this->state = state;   return;
		}
		else {  //세가지 상태에 해당 안되면 재입력.
			cout << "재입력 : ";
			cin >> state;
		}
	}
}

void Food::setState1(string state) { // 현황판에 보이기 위해 작성
	if (state == "냉장" || state == "냉동" || state == "상온")
	{
		this->state = state;
		return;
	}
	else {
		cout << "보관상태 재입력: ";
		cin >> state;
	}
}

void Food::showLeftDate() {
	//if (state == "미") //현재 사용자의 냉장고에 미보관이면 유통기한 출력X
	//	return;
	time_t shelfdate, today;
	double diff; //유통기한과 현재시각 비교
	int day; //비교 후 남은 일수 넣음
	struct tm user_stime; //현재시각 넣을 곳
	user_stime.tm_year = f_year - 1900;
	user_stime.tm_mon = f_month - 1;
	user_stime.tm_mday = f_day;
	user_stime.tm_hour = 0, user_stime.tm_min = 0, user_stime.tm_sec = 0, user_stime.tm_isdst = 0;
	shelfdate = mktime(&user_stime); //유통기한
	time(&today); //현재시각
	diff = difftime(shelfdate, today);
	day = (int)diff / (60 * 60 * 24); //남은 날

	//cout << "day : " << day << "diff: "<<diff  << endl;
	if (day >= 1)//이틀 이상 남음
		cout << day + 1 << "일 남았습니다." << endl;
	else if(day == 0 && diff >= 0)//내일이 유통기한
		cout << "1일 남았습니다." << endl;
	else if (day == 0 && diff < 0) //오늘이 유통기한
		cout << "유통기한이 오늘까지입니다." << endl;
	else //지남
		cout << (-1 * day) << "일 지났습니다." << endl;
}


//파일에 미리 입력된 데이터 외에 추가할 때 사용됨.
void writeInFile(vector<Food>& food) { // txt파일들에 식재료들 write
	if (food.empty())
		return;
	if (food[0].getName() == "육류") {
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
	else if (food[0].getName() == "어류") {
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
	else if (food[0].getName() == "채소") { //veget[0].getName()
		FILE* writeFile = fopen("veget.txt", "w");
		int i = 0, j = 1;
		while (i < food.size()) {  //첫 데이터 입력 -> 개행 -> 데이터입력 -> ... -> 개행 -> 데이터입력    ,,,,,, 개행을 한번 덜 해줘야돼서 j=1로 둠.
			fprintf(writeFile, food[i].getName().c_str());
			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "소스") {
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
	else if (food[0].getName() == "음료") {
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
	else if (food[0].getName() == "그외") {
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
	else if (food[0].getName() == "냉장") {
		FILE* writeFile = fopen("refrigeration.txt", "w");
		int i = 0;
		int j = 1;

		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // 재료
				fprintf(writeFile, " "); // 재료 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x 저장되도록 // 재료 1 2 3
				fprintf(writeFile, " ");// 재료 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // 재료 1 2 3 2000
				fprintf(writeFile, " ");// 재료 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // 재료 1 2 3 2000 2
				fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // 재료 1 2 3 2000 2 2 2
			}


			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "냉동") {
		FILE* writeFile = fopen("freeze.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // 재료
				fprintf(writeFile, " "); // 재료 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x 저장되도록 // 재료 1 2 3
				fprintf(writeFile, " ");// 재료 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // 재료 1 2 3 2000
				fprintf(writeFile, " ");// 재료 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // 재료 1 2 3 2000 2
				fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // 재료 1 2 3 2000 2 2 2
			}


			if (j < food.size()) {
				fprintf(writeFile, "\n");
			}
			i++;
			j++;
		}
		fclose(writeFile);
	}
	else if (food[0].getName() == "상온") {
		FILE* writeFile = fopen("room.txt", "w");
		int i = 0;
		int j = 1;
		while (i < food.size()) {
			if (i == 0) {
				fprintf(writeFile, food[i].getName().c_str());
			}
			else {
				fprintf(writeFile, food[i].getName().c_str()); // 재료
				fprintf(writeFile, " "); // 재료 
				fprintf(writeFile, food[i].getRecipe1().c_str()); // x x x 저장되도록 // 재료 1 2 3
				fprintf(writeFile, " ");// 재료 1 2 3 
				fprintf(writeFile, to_string(food[i].getFYear()).c_str()); // 재료 1 2 3 2000
				fprintf(writeFile, " ");// 재료 1 2 3 2000 
				fprintf(writeFile, to_string(food[i].getFMonth()).c_str()); // 재료 1 2 3 2000 2
				fprintf(writeFile, " ");// 재료 1 2 3 2000 2 
				fprintf(writeFile, to_string(food[i].getFDay()).c_str()); // 재료 1 2 3 2000 2 2 2
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
} // 입력해서 쓰는게 아니라 else 처리 안해줌. 


void init(vector<Food>& food, string s) { //s에 맞는 식재료 목록으로 초기화함 ex) init(food, "육류") ---> meat.txt에 작성된 식재료들로 food 벡터가 초기화됨.
	food.clear();
	if (s == "육류") {
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
	if (s == "어류") {
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
	if (s == "채소") {
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
	if (s == "소스") {
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
	if (s == "음료") {
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
	if (s == "기타") {
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

	// 냉장, 냉동, 상온 현황에 보이기 위해 추가
	if (s == "냉장") { // refrigeration
		FILE* readFile = NULL;
		fopen_s(&readFile, "refrigeration.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 냉장 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("냉장");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // 재료이름 x x x 2202 22 22
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
				new_food.setState1("냉장");
				food.push_back(new_food);
			}
		}
		fcloseall();
	}

	if (s == "냉동") { // freeze
		FILE* readFile = NULL;
		fopen_s(&readFile, "freeze.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 냉동 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("냉동");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // 재료이름 x x x 2202 22 22
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
				new_food.setState1("냉동");
				food.push_back(new_food);
			}
		}
		fcloseall();
	}

	if (s == "상온") { // room
		FILE* readFile = NULL;
		fopen_s(&readFile, "room.txt", "r");
		if (readFile != NULL) {

			char buf[1024];

			char name[32];
			fgets(buf, sizeof(buf), readFile);
			char* ptr = strtok(buf, "\n"); //- 상온 받는 부분
			strcpy(name, ptr);

			Food new_food(name);
			new_food.setState1("상온");
			food.push_back(new_food);

			while (!feof(readFile)) { // eof까지 반복
				fgets(buf, sizeof(buf), readFile);

				char name[32];
				char recipe1[32] = { 0, };
				char recipe2[32] = { 0, };
				char recipe3[32] = { 0, };
				char y[5];
				char m[3];
				char d[3];

				char* ptr = strtok(buf, " \n"); // 재료이름 x x x 2202 22 22
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
				new_food.setState1("냉동");
				food.push_back(new_food);

			}

		}

		fcloseall();
	}
}
