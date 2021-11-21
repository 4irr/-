#pragma once
#include "libraries.h"
#include "Learner.h"

using namespace std;

class Postgraduate : public Learner {
public:
	void PrintUniqueInfo(fstream& fs) override { }

	void SetUniqueInfo(fstream& fs) override { }

	string GetDormitory() override { return "   --"; }
};

