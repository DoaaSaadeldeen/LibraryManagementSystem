#include<iostream>
#include "Date.h"
using namespace std;
class Publication {
public:
	string name="";
	bool available=1;
	Date dateOfBorrowing;
	int allowedPeriod;
	Publication() {
		this->name = "";
		this->available = 0;
		this->dateOfBorrowing = *new Date(0, 0, 0);
		this->allowedPeriod = 0;
	}
};
class Book : public Publication {
public:
	Book(string name) {
		this->name = name;
		this->available = true;
		this->allowedPeriod = 20;
		Date *d = new Date(0, 0, 0);
		(this->dateOfBorrowing) = *d;
	}
};
class Booklet : public Publication {
public:
	Booklet(string name) {
		this->name = name;
		this->available = true;
		this->allowedPeriod = 12;
		Date* d = new Date(0, 0, 0);
		(this->dateOfBorrowing) = *d;
	}
};
class Magazine : public Publication {
public:
	Magazine(string name) {
		this->name = name;
		this->available = true;
		this->allowedPeriod = 12;
		Date* d = new Date(0, 0, 0);
		(this->dateOfBorrowing) = *d;
	}
};