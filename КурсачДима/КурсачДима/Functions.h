#pragma once
#include "libraries.h"
#include "subclasses.h"
#include "User.h"
#include "Learner.h"

using namespace std;

bool operator==(Fio obj1, Fio obj2) {
	if (obj1.name == obj2.name && obj1.surname == obj2.surname && obj1.patronymic == obj2.patronymic) return true;
	else return false;
}

fstream& operator>>(fstream& fs, User& obj) {
	fs >> obj.login >> obj.password;
	return fs;
}

fstream& operator<<(fstream& fs, Date& obj) {
	fs << obj.day << " " << obj.month << " " << obj.year;
	return fs;
}

fstream& operator>>(fstream& fs, Date& obj) {
	fs >> obj.day >> obj.month >> obj.year;
	return fs;
}

fstream& operator<<(fstream& fs, Fio& obj) {
	fs << obj.GetName() << " " << obj.GetSurname() << " " << obj.GetPatronymic();
	return fs;
}

fstream& operator>>(fstream& fs, Fio& obj) {
	fs >> obj.name >> obj.surname >> obj.patronymic;
	return fs;
}

fstream& operator<<(fstream& fs, Learner& obj) {
	fs << endl;
	fs << obj.fio << " " << obj.age << " ";
	fs << obj.receiptDate << " " << obj.faculty << " " << obj.speciality << " " << obj.educForm << " ";
	fs << obj.scientificWork;
	return fs;
}

fstream& operator>>(fstream& fs, Learner& obj) {
	fs >> obj.fio >> obj.age;
	fs >> obj.receiptDate >> obj.faculty >> obj.speciality;
	fs >> obj.educForm >> obj.scientificWork;
	return fs;
}

int AvoidChar(int& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0;
	while (true)
	{
		while (true) {
			ch = _getch();
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13) break;
		}
		if (ch == 13) {
			break;
		}
		if (ch == 27) {
			flag = 1;
			break;
		}
		if (ch == 8 && !info.empty()) {
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}
		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

int Menu() {
	int choice;
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t\t||=========================================||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t|| 1. Регистрация нового пользователя      ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||=========================================||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t|| 2. Вход                                 ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||=========================================||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t|| 3. Выход                                ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||=========================================||\n\n";
	cout << "\t\t\t\t\t               Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int UserMenu() {
	int choice;
	cout << "\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  1. Добавить данные                    ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  2. Отредактировать данные             ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  3. Удалить данные                     ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  4. Просмотреть записанные данные      ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  5. Поиск данных                       ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  6. Просмотреть отсортированные данные ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||  7. Назад                              ||\n"
		"\t\t\t\t\t||                                        ||\n"
		"\t\t\t\t\t||========================================||\n"
		"\t\t\t\t\t               Ваш выбор: "; AvoidChar(choice);
	return choice;

}

int AddMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t  ||==============================================||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||   1. Добавить данные о студенте              ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||==============================================||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||   2. Добавить данные о специалисте           ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||==============================================||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||   3. Добавить данные о магистранте           ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||==============================================||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||   4. Добавить данные об аспиранте            ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||==============================================||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||   5. Назад                                   ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||==============================================||\n\n"
		"\t\t\t\t                   Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int RedMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||==================================================||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||  1. Отредактировать данные о студенте            ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||==================================================||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||  2. Отредактировать данные о специалисте         ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||==================================================||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||  3. Отредактировать данные о магистранте         ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||==================================================||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||  4. Отредактировать данные об аспиранте          ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||==================================================||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||  5. Назад                                        ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||==================================================||\n\n"
		"\t\t\t\t                     Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int DelMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   1. Удалить данные о студенте              ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   2. Удалить данные о специалисте           ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   3. Удалить данные о магистранте           ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   4. Удалить данные об аспиранте            ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   5. Назад                                  ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice); 
	return choice;
}

int ShowMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   1. Просмотреть данные о студентах         ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   2. Просмотреть данные о специалистах      ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   3. Просмотреть данные о магистрантах      ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   4. Просмотреть данные об аспирантах       ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   5. Назад                                  ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||=============================================||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int FindMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||==========================================||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||   1. Поиск данных о студентах            ||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||==========================================||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||   2. Поиск данных о специалистах         ||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||==========================================||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||   3. Поиск данных о магистрантах         ||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||==========================================||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||   4. Поиск данных об аспирантах          ||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||==========================================||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||   5. Назад                               ||\n"
		"\t\t\t\t||                                          ||\n"
		"\t\t\t\t||==========================================||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int SortMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||===============================================||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||   1. Сортированные данные о студентах         ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||===============================================||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||   2. Сортированные данные о специалистах      ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||===============================================||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||   3. Сортированные данные о магистрантах      ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||===============================================||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||   4. Сортированные данные об аспирантах       ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||===============================================||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||   5. Назад                                    ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||===============================================||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

void Encryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] + 5;
	}
}

void Decryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 5;
	}
}

int HidePass(string& info) {
	int flag = 0;
	info = "";
	int ch = 0;
	while (true) {
		ch = _getch();
		if (ch == 13) {
			break;
		}
		if (ch == 27) {
			flag = 1;
			break;
		}
		if (ch == 8 && !info.empty()) {
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}
		if (ch != 8) {
			cout << "*";
			info += (char)ch;
		}
	}
	cout << endl;
	return flag;
}

int CheckLog(string log, string pass) {
	int flag = 1;
	fstream fs;
	fs.open("Users.txt");
	if (fs.is_open()) {
		deque <User> U;
		while (!fs.eof())
		{
			User user;
			fs >> user;
			U.push_back(user);
		}
		fs.close();
		for (int i = 0; i < U.size(); i++)
		{
			Decryption(U[i].password);
			(U[i].login == log) ? flag = 0 : flag;
			(U[i].login == log && U[i].password == pass) ? flag = 2 : flag;
		}
	}
	else {
		flag = -1;
	}
	return flag;
}

int Check(string path) {
	int res = 0;
	fstream fs;
	fs.open(path);
	if (fs.is_open()) res = 1;
	return res;
}

void registration() {
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Введите логин: "; cin >> user.login;
		int ch = CheckLog(user.login, "");
		if (ch == 1 || ch == -1) {
			cout << "\nВведите пароль: "; HidePass(user.password);
			cout << "\nПовторите пароль: "; HidePass(user.confpass);
			if (user.password == user.confpass) {
				system("pause");
				fstream fs;
				fs.open("Users.txt", fstream::in | fstream::app);
				if (fs.is_open()) {
					Encryption(user.password);
					fs << user.login << " " << user.password << endl;
					cout << "\nРегистрация прошла успешно" << endl;
					fs.close();
				}
				else {
					system("cls");
					cout << "Не удалось записать информацию в файл!\n";
					system("pause");
				}
				flag = false;
			}
			else {
				cout << "Пароль или логин не совпадают!" << endl;
				system("pause");
			}
		}
		else {
			cout << "Пользователь с таким логином уже зарегистрирован!" << endl;
			system("pause");
		}
	}
}

int authorization() {
	int res;
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		int ch = Check("Users.txt");
		if (ch == 0) {
			cout << "Необходима регистрация!" << endl;
			res = -1;
			system("pause");
			break;
		}
		cout << "Введите логин: "; cin >> user.login;
		cout << "\nВведите пароль: "; HidePass(user.password);
		ch = CheckLog(user.login, user.password);
		if (ch == 2) {
			res = 1;
			cout << "Вход выполнен успешно!" << endl;
			system("pause");
			flag = false;
		}
		else {
			cout << "\nНеверный логин или пароль!\n";
			system("pause");
			continue;
		}
	}
	return res;
}

void AddInfo(Learner* obj, string path) {
	obj->SetInfo();
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << *obj;
		obj->PrintUniqueInfo(fs);
		fs.close();
	}
	else {
		cout << "Не удалось записать информацию" << endl;
	}
}

template <class Type>
void RedactInfo(Type type, string path) {
	cout << endl;
	if (Check(path) == 0) {
		cout << "Информация об учащихся отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО учащегося, информацию о котором необходимо изменить: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) {
				flag = 1;
				cout << "Введите новую информацию:" << endl << endl;
				D[i].SetInfo();
			}
		}
		if (flag == 0) {
			cout << endl << "Учащийся с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				fs << D[i];
				D[i].PrintUniqueInfo(fs);
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось отредактировать информацию" << endl;
	}
}

template <class Type>
void DeleteInfo(Type type, string path) {
	if (Check(path) == 0) {
		cout << "Информация об учащихся отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО учащегося, информацию о котором необходимо удалить: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Учащийся с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].fio == fio)) {
					fs << D[i];
					D[i].PrintUniqueInfo(fs);
				}
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void ShowInfo(Type type, string path, int flag) {
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();

		if (flag == 1) {
			for (int i = 1; i < D.size(); i++)
			{
				int d = exp2(i) - 1;
				if (d <= D.size()) {

					for (int k = 0; k < D.size() - d; k++)
					{
						int j = k;
						while (j >= 0 && D[j].receiptDate.GetYear() * 365 * D[j].receiptDate.GetMonth() * 30 + D[j].receiptDate.GetDay() > D[j+d].receiptDate.GetYear() * 365 * D[j+d].receiptDate.GetMonth() * 30 + D[j+d].receiptDate.GetDay())
						{
							Type object = D[j];
							D[j] = D[j + d];
							D[j + d] = object;
							j--;
						}
					}
				}
			}
		}

		//1я и 2я строка шапки
		cout << "|" << setw(118) << setfill('=') << "|" << endl;
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
		cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

		//текстовая строка шапки
		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::left);
		cout << "| " << setw(29) << setfill(' ') << "Имя Фамилия Отчество" << "| " << setw(8) << setfill(' ') << "Возраст" << "| " << setw(12) << setfill(' ') << "Поступление" << "| ";
		cout << setw(10) << setfill(' ') << "Факультет" << "| " << setw(14) << setfill(' ') << "Специальность" << "| " << setw(9) << setfill(' ') << "Обучение" << "| " << setw(10) << setfill(' ') << "Иссл.раб." << "| ";
		cout << setw(10) << setfill(' ') << "Общежитие" << "|" << endl;

		//4я и 5я строка шапки
		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::right);
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
		cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
		cout << "|" << setw(118) << setfill('=') << "|" << endl;
		for (int i = 0; i < D.size(); i++)
		{
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
			cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
			stringstream A;
			A << D[i].receiptDate.GetDay() << "." << D[i].receiptDate.GetMonth() << "." << D[i].receiptDate.GetYear();
			string date; A >> date;

			cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(8) << setfill(' ') << D[i].GetAge() << "| " << setw(12) << setfill(' ') << date << "| " << setw(10) << setfill(' ') << D[i].GetFaculty() << "| ";
			cout << setw(14) << setfill(' ') << D[i].GetSpeciality() << "| " << setw(9) << setfill(' ') << D[i].GetEducForm() << "| " << setw(10) << setfill(' ') << D[i].GetScientificWork() << "| " << setw(10) << setfill(' ') << D[i].GetDormitory() << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
			cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
			cout << "|" << setw(118) << setfill('=') << "|" << endl;
		}
		system("pause");
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void FindInfo(Type type, string path) {
	if (Check(path) == 0) {
		cout << "Информация об учащихся отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО учащегося, информацию о котором необходимо найти: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Учащийся с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		cout << endl;
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) {
				//1я и 2я строка шапки
				cout << "|" << setw(118) << setfill('=') << "|" << endl;
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
				cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

				//текстовая строка шапки
				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::left);
				cout << "| " << setw(29) << setfill(' ') << "Имя Фамилия Отчество" << "| " << setw(8) << setfill(' ') << "Возраст" << "| " << setw(12) << setfill(' ') << "Поступление" << "| ";
				cout << setw(10) << setfill(' ') << "Факультет" << "| " << setw(14) << setfill(' ') << "Специальность" << "| " << setw(9) << setfill(' ') << "Обучение" << "| " << setw(10) << setfill(' ') << "Иссл.раб." << "| ";
				cout << setw(10) << setfill(' ') << "Общежитие" << "|" << endl;

				//4я и 5я строка шапки
				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::right);
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
				cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
				cout << "|" << setw(118) << setfill('=') << "|" << endl;

				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
				cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::left);
				string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
				stringstream A;
				A << D[i].receiptDate.GetDay() << "." << D[i].receiptDate.GetMonth() << "." << D[i].receiptDate.GetYear();
				string date; A >> date;

				cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(8) << setfill(' ') << D[i].GetAge() << "| " << setw(12) << setfill(' ') << date << "| " << setw(10) << setfill(' ') << D[i].GetFaculty() << "| ";
				cout << setw(14) << setfill(' ') << D[i].GetSpeciality() << "| " << setw(9) << setfill(' ') << D[i].GetEducForm() << "| " << setw(10) << setfill(' ') << D[i].GetScientificWork() << "| " << setw(10) << setfill(' ') << D[i].GetDormitory() << "|" << endl;

				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::right);
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|";
				cout << setw(16) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
				cout << "|" << setw(118) << setfill('=') << "|" << endl;
			}
		}
		system("pause");
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}