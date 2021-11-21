#include "libraries.h"
#include "Functions.h"
#include "Learner.h"
#include "Student.h"
#include "Specialist.h"
#include "Master.h"
#include "Postgraduate.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag) {
		system("cls");
		int choice1 = Menu();
		switch (choice1) {
		case 1:
			system("cls");
			registration();
			continue;
			break;
		case 2:
			system("cls");
			if (authorization() == -1) continue;
			while (true) {
				system("cls");
				int choice2 = UserMenu();
				if (choice2 == 7) break;
				switch (choice2) {
				case 1:
					while (true) {
						system("cls");
						int choice3 = AddMenu();
						if (choice3 == 5) break;
						switch (choice3) {
						case 1: {
							system("cls");
							Student student;
							AddInfo(&student, "Students.txt");
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							AddInfo(&specialist, "Specialists.txt");
							break;
						}
						case 3: {
							system("cls");
							Master master;
							AddInfo(&master, "Masters.txt");
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							AddInfo(&postgraduate, "Postgraduates.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 2:
					while (true) {
						system("cls");
						int choice4 = RedMenu();
						if (choice4 == 5) break;
						switch (choice4) {
						case 1: {
							system("cls");
							Student student;
							ShowInfo(student, "Students.txt", 0);
							RedactInfo(student, "Students.txt");
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							ShowInfo(specialist, "Specialists.txt", 0);
							RedactInfo(specialist, "Specialists.txt");
							break;
						}
						case 3: {
							system("cls");
							Master master;
							ShowInfo(master, "Masters.txt", 0);
							RedactInfo(master, "Masters.txt");
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							ShowInfo(postgraduate, "Postgraduates.txt", 0);
							RedactInfo(postgraduate, "Postgraduates.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 3:
					while (true) {
						system("cls");
						int choice5 = DelMenu();
						if (choice5 == 5) break;
						switch (choice5) {
						case 1: {
							system("cls");
							Student student;
							DeleteInfo(student, "Students.txt");
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							DeleteInfo(specialist, "Specialists.txt");
							break;
						}
						case 3: {
							system("cls");
							Master master;
							DeleteInfo(master, "Masters.txt");
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							DeleteInfo(postgraduate, "Postgraduates.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 4:
					while (true) {
						system("cls");
						int choice6 = ShowMenu();
						if (choice6 == 5) break;
						switch (choice6) {
						case 1: {
							system("cls");
							Student student;
							ShowInfo(student, "Students.txt", 0);
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							ShowInfo(specialist, "Specialists.txt", 0);
							break;
						}
						case 3: {
							system("cls");
							Master master;
							ShowInfo(master, "Masters.txt", 0);
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							ShowInfo(postgraduate, "Postgraduates.txt", 0);
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 5:
					while (true) {
						system("cls");
						int choice7 = FindMenu();
						if (choice7 == 5) break;
						switch (choice7) {
						case 1: {
							system("cls");
							Student student;
							FindInfo(student, "Students.txt");
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							FindInfo(specialist, "Specialists.txt");
							break;
						}
						case 3: {
							system("cls");
							Master master;
							FindInfo(master, "Masters.txt");
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							FindInfo(postgraduate, "Postgraduates.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 6:
					while (true) {
						system("cls");
						int choice8 = SortMenu();
						if (choice8 == 5) break;
						switch (choice8) {
						case 1: {
							system("cls");
							Student student;
							ShowInfo(student, "Students.txt", 1);
							break;
						}
						case 2: {
							system("cls");
							Specialist specialist;
							ShowInfo(specialist, "Specialists.txt", 1);
							break;
						}
						case 3: {
							system("cls");
							Master master;
							ShowInfo(master, "Masters.txt", 1);
							break;
						}
						case 4: {
							system("cls");
							Postgraduate postgraduate;
							ShowInfo(postgraduate, "Postgraduates.txt", 1);
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				default: {
					system("cls");
					cout << "Неверный выбор!\nПовторите попытку." << endl;
					system("pause");
				}
				}
			}
			continue;
			break;
		case 3:
			exit(0);
			break;
		default: {
			system("cls");
			cout << "Неверный выбор!\nПовторите попытку." << endl;
			system("pause");
		}
		}
	}
	return 0;
}