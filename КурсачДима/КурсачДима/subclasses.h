#pragma once
#include "libraries.h"
#include "Functions.h"

int AvoidChar(int& num);

using namespace std;

class Fio {
	string name;
	string surname;
	string patronymic;
public:
	Fio();
	void Set();
	string GetName() { return name; }
	string GetSurname() { return surname; }
	string GetPatronymic() { return patronymic; }

	friend fstream& operator>>(fstream& fs, Fio& obj);
	friend bool operator==(Fio obj1, Fio obj2);
};

Fio::Fio() {
	name = "-";
	surname = "-";
	patronymic = "-";
}

void Fio::Set() {
	cout << "Введите имя: "; cin >> name;
	cout << "\nВведите фамилию: "; cin >> surname;
	cout << "\nВведите отчество: "; cin >> patronymic;
}

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	void Set();
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }

	friend fstream& operator>>(fstream& fs, Date& obj);
	friend fstream& operator<<(fstream& fs, Date& obj);

	Date& operator=(const Date& obj) {
		day = obj.day;
		month = obj.month;
		year = obj.year;
		return *this;
	}
};

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

void Date::Set() {
	while (true) {
		cout << "Введите день: "; AvoidChar(day);
		if (day > 31 || day < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}

	while (true) {
		cout << "\nВведите месяц: "; AvoidChar(month);
		if (month > 12 || month < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}

	while (true) {
		cout << "\nВведите год: "; AvoidChar(year);
		if (year < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}
}