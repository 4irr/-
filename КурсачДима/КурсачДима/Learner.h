#pragma once
#include "libraries.h"
#include "subclasses.h"

using namespace std;

class Learner {
protected:
	Fio fio;
	int age;
	Date receiptDate;
	string faculty;
	string speciality;
	string educForm;
	string dormitory;
	string scientificWork;
public:

	Learner();

	int GetAge() { return age; }
	string GetFaculty() { return faculty; }
	string GetSpeciality() { return speciality; }
	string GetEducForm() { return educForm; }
	string GetScientificWork() { return scientificWork; }

	virtual void SetInfo();
	virtual void PrintUniqueInfo(fstream& fs) = 0;
	virtual void SetUniqueInfo(fstream& fs) = 0;
	virtual string GetDormitory() = 0;

	template <class Type> friend void ShowInfo(Type type, string path, int flag);
	template <class Type> friend void FindInfo(Type type, string path);
	template <class Type> friend void RedactInfo(Type type, string path);
	template <class Type> friend void DeleteInfo(Type type, string path);
	friend fstream& operator<<(fstream& fs, Learner& obj);
	friend fstream& operator>>(fstream& fs, Learner& obj);
};

Learner::Learner() {
	age = 0;
	string faculty = "-";
	string speciality = "-";
	string educForm = "-";
	string dormitory = "-";
	string scientificWork = "-";
}

void Learner::SetInfo() {
	cout << "������� ��� ���������:\n"; fio.Set();
	cout << "\n������� ������� ���������: "; AvoidChar(age);
	cout << "\n������� ���� �����������:\n"; receiptDate.Set();
	cout << "\n������� ���������: "; cin >> faculty;
	cout << "\n������� �������������: "; cin >> speciality;
	cout << "\n������� ����� ��������: "; cin >> educForm;
	cout << "\n������� � ����������������� �������(��� ��� ���� ������, ���� ��): "; cin >> scientificWork;
}