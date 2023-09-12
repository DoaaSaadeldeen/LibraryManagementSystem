#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include "Humans.h"

using namespace std;
int calcNumberofDays(Date today, Date BorrowedDay) {
	int daysNum1, daysNum2;
	daysNum1 = today.day + today.month * 30 + today.year * 365;
	daysNum2 = BorrowedDay.day + BorrowedDay.month * 30 + BorrowedDay.year * 365;

	return daysNum1 - daysNum2;
}
int main() {
	static Publication* arr[1000];
	static int sz = 0;
	while (true) {
		cout << "1: admin\n2: student\n";

		int choice;
		cin >> choice;
		if (choice == 1) {//admin
			cout << "enter password\n";
			string s, pass = "123456780";
			cin >> s;
			if (s == pass) {
				Admin* ad = new Admin();
				while (true) {
					cout << "  1: adding publication\n";
					cout << "  2: Display AVailable publications\n";
					cout << "  3: Display Borrowed publication\n";
					cout << "  4: search for publication\n";
					cout << "  5: modify  publication\n";
					cout << "  6: delete  publication\n";
					cout << "  7: over period borrowed publications\n";
					cout << "  8: exit\n";
					int option;  cin >> option;
					if (option == 1)		ad->addPublication(arr, sz);
					else if (option == 2)	ad->DispalyAVailablePubs(arr, sz);
					else if (option == 3)	ad->DispalyABorrowdPubs(arr, sz);
					else if (option == 4)	ad->SearchForPublication(arr, sz);
					else if (option == 5)	ad->modifyPublication(arr, sz);
					else if (option == 6)	ad->deletePublication(arr, sz);
					else if (option == 7)	ad->DispalyOverPeriodPubs(arr, sz);
					else break;
				}
			}
			else {
				cout << "wrong password\n";
			}
		}
		else if (choice == 2) {//student
			Student* st = new Student();
			while (true) {
				cout << "  1: Borrow publication\n";
				cout << "  2: Display AVailable publications\n";
				cout << "  3: Display Borrowd publications\n";
				cout << "  4: search for publication\n";
				cout << "  5: exit\n";

				int option;  cin >> option;
				if (option == 1)     st->Borrow(arr, sz);
				else if (option == 2)st->DispalyAVailablePubs(arr, sz);
				else if (option == 3)st->DispalyABorrowdPubs(arr, sz);
				else if (option == 4)st->SearchForPublication(arr, sz);
				else break;
			}
		}
		else {
			cout << "wrong entry :(\n";

		}
	}
	return 0;
}