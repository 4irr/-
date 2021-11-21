#pragma once
#include "libraries.h"
#include "Learner.h"

using namespace std;

class Specialist : public Learner {
public:
	void SetInfo() override {
		Learner::SetInfo();
		cout << "\nНаличие общежития(да или нет): "; cin >> dormitory;
	}

	void PrintUniqueInfo(fstream& fs) override {
		fs << " " << dormitory;
	}

	void SetUniqueInfo(fstream& fs) override {
		fs >> dormitory;
	}

	string GetDormitory() override {
		return dormitory;
	}
};

