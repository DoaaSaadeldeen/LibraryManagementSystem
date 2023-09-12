#include<iostream>
#include "publications.h"
using namespace std;
int calcNumberofDays(Date today, Date BorrowedDay);
class Human {
public :
	void SearchForPublication(Publication *arr[],int &sz)
	{
		cout << "write the name  of publication:-\n";
		string pubName;
		cin >> pubName;
		for (int i = 0; i < sz;i++) {
			if (arr[i]->name == pubName) {
				cout << "found ";
				if (arr[i]->available == true) {
					cout << "and available\n";
				}
				else {
					cout << "but currently it is borrowed\n";
				}
				return;
			}
		}
		cout << "not found\n";
	}
	void DispalyAVailablePubs(Publication* arr[], int &sz) {
		bool printed = false;
		for (int i = 0; i < sz; i++) {
			if (arr[i]->available == true) {
				if (printed == false) {
					cout << "the available publications are:-\n";
					printed = true;
				}
				cout << arr[i]->name << "\n";
			}
		}
		if (printed == false) {
			cout << "no available publications\n";
		}
	}
	void DispalyABorrowdPubs(Publication* arr[], int &sz) {
		bool printed = false;
		for (int i = 0; i < sz; i++) {
			if (arr[i]->available == false) {//borrowed
				if (printed == false) {
					cout << "the Borrowed publications are:-\n";
					printed = true;
				}
				cout << arr[i]->name << "\n";
			}
		}
		if (printed == false) {
			cout << "no borrowed publications\n";
		}
	}
};
class Student :public Human {
public:

	void Borrow(Publication* arr[], int &sz)
	{
		cout << "write the name  of publication:-\n";
		string pubName;
		cin >> pubName;
		bool found = false;
		for (int i = 0; i < sz; i++) {
			if (arr[i]->name == pubName) {
				found = true;
				if (arr[i]->available == true) {
					arr[i]->available = false;
					cout << "please enter the date of today in form of \n day\n month \n year\n";
					int d, m, y;
					cin >> d >> m >> y;
					Date* today = new Date(d, m, y);
					arr[i]->dateOfBorrowing = *today;
					cout << "the process of borrowing is done successfully\n";
				}
				else {
					cout << "sorry this publication is borrowed\n";
				}
				break;
			}
		}
		if (found == false) {
			cout << "this publication is not available in our library\n";
		}
	}
};
class Admin:public Human {
public:
	void addPublication(Publication* arr[], int &sz) {
		cout << "write the type of publication:-\n 1: Book\n 2: booklet\n 3: magazine\nthen the name of the publication\n";
		string pubName;
		int choice;
		cin >> choice >> pubName;
		if (choice == 1) {//Book
			arr[sz] = new Book(pubName);
			sz++;
		}
		else if (choice == 2) {//Booklet
			arr[sz] = new Booklet(pubName);
			sz++;
		}
		else if (choice == 3) {//Magazine
			arr[sz] = new Magazine(pubName);
			sz++;
		}
		else {
			cout << "wrong entry\n";
			return;
		}
		cout << "your publication has added successfully\n";
	}
	void modifyPublication(Publication* arr[], int& sz) {
		cout << "write the name  of publication:-\n";
		string pubName;
		cin >> pubName;
		int choice;
		for (int i = 0; i < sz; i++) {
			if (arr[i]->name == pubName) {
				cout << "this publication details is:-\n";
				cout << "name : " << arr[i]->name << "\n";
				cout << "availablity : ";
				if (arr[i]->available == true)
					cout << "Yes\n";
				else {
					cout<<"No it borowed in " << arr[i]->dateOfBorrowing.day << "/" <<
											     arr[i]->dateOfBorrowing.month << "/" <<
						                         arr[i]->dateOfBorrowing.year  << "\n";
				}
				cout << "allowed period of borrowing : " << arr[i]->allowedPeriod << "\n";
				cout << " 1: modifying name\n 2: modifying availabilty\n 3: modifying period of borrowing\n 4: modifying date of borrowing\n";
				int choice;
				cin >> choice;
				if (choice == 1) {//name
					cout << "please enter the new name\n";
					string s;
					cin >> s;
					arr[i]->name = s;
					cout << "name is changed successfully\n";

				}
				else if (choice == 2) {//availabilty
					cout << "please enter the new state of availabilty\n";
					cout << " 0:not available\n 1:available\n";
					int avail;
					cin >> avail;
					if (avail) {
						arr[i]->available = true;
						arr[i]->dateOfBorrowing = *new Date(0, 0, 0);
				   }
					cout << "availabilty is changed successfully\n";
				}
				else if (choice == 3) {//period of borrowing
					cout << "please enter the new available period of borrowing \n";
					int p;
					cin >> p;
					arr[i]->allowedPeriod = p;
					cout << "allowedPeriod is changed successfully\n";
				}
				else if (choice == 4) {//date of borrowing
					cout << "please enter the new date of borrowing in form of \n day\n month \n year\n";
					int d, m, y;
					cin >> d >> m >> y;
					if (arr[i]->available == true) {
						if (d != 0 || m != 0 || y != 0) {
							arr[i]->available = false;
						}
					}
					else {
						if (d == 0 || m == 0 || y == 0) {
							arr[i]->available = true;
							d = m = y = 0;
						}
					}
					Date* borrowingDate = new Date(d, m, y);
					arr[i]->dateOfBorrowing = *borrowingDate;
					cout << "date of borrowing is changed successfully\n";
				}
				else {
					cout << "wrong entry\n";
				}
				break;
			}
		}
	}
	void deletePublication(Publication* arr[], int& sz) {
		cout << "write the name  of publication:-\n";
		string pubName;
		cin >> pubName;
		bool deleted = false;
		for (int i = 0; i < sz; i++) {
			if (arr[i]->name == pubName) {
				int idx = i;
				for (int j = i ; j < sz-1; j++)
				{
					arr[j] = arr[j + 1];
				}
				sz--;
				deleted = true;
				break;
			}
		}
		if (deleted == false){
			cout << "this publication isn't found\n";
		}
		else {
			cout << "publication is deleted successfully\n";
		}
	}
	void DispalyOverPeriodPubs(Publication* arr[], int& sz) {//DispalyOverPeriodPublications
		bool printed = false;
		cout << "please enter the date of today in form of \n day\n month \n year\n";
		int d, m, y;
		cin >> d >> m >> y;
		Date *today = new Date(d, m, y);
		for (int i = 0; i < sz; i++) {
			//cout << "\n\ntest1\n\n";
			if (arr[i]->available == false) {//borrowed
				int numOfDays = calcNumberofDays(*today, arr[i]->dateOfBorrowing);
				/*cout << "\n\ntest2\n\n" << numOfDays << "\n" <<
					arr[i]->dateOfBorrowing.day << "\n" <<
					arr[i]->dateOfBorrowing.month << "\n" <<
					arr[i]->dateOfBorrowing.year << "\n" << "\n\n" <<
					today->day << "\n" << today->month << "\n" << today->year << "lol\n";*/

					;
				if (numOfDays > arr[i]->allowedPeriod) {
					if (printed == false) {
						cout << "over period publications are:-\n";
						printed = true;
					}
					cout << arr[i]->name <<" period = "<< numOfDays << "\n";
				}
			}
		}
		if (printed == false) {
			cout << "no publications are over period\n";
		}
	}
};

