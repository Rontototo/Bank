#include "User.h"
#include "Accounts.h"
#include <iostream>

User::User() {
	cout << "Stworzono konto uzytkownika\n";
}

User::~User() {
	cout << "Usunieto konto uzytkownika\n\n";
}

//---------------Klient-----------------------

Client::Client() {
	cout << "Jest to konto klienta\n\n";
}

Client::~Client() {
	cout << "Usunieto konto klienta\n";
}

void Client::MoneIn(Account& szef, int num, int mone) {
	szef.MonIn(num, mone);
}

void Client::MoneOut(Account& szef, int num, int mone) {
	szef.MonOut(num, mone);
}

void Client::ShowStat(Account& szef, int num) {
	szef.ShowStat(num);
}

//---------------Pracownik-----------------------

Employee::Employee() {
	cout << "Jest to konto pracownika\n\n";
}

Employee::~Employee() {
	cout << "Usunieto konto pracownika\n";
}

void Employee::CreateAccB(Biezace& biez, int num) {
	biez.MakeAcc(num);
}

void Employee::CreateAccO(Oszczednosciowe& oszcz, int num) {
	oszcz.MakeAcc(num);
}

void Employee::ChangeNum(Account& szef, int prev, int newer) {
	if (newer < 10000) {
		cout << "Numer niezgodny z kryteriami\n\n";
		return;
	}
	
	for (int i = 0; i < szef.BiezNum.size(); ++i) {
		if (szef.BiezNum.empty()) {
			break;
		}

		if (szef.BiezNum[i]->Num == prev) {
			szef.BiezNum[i]->Num = newer;
		}
	}

	for (int i = 0; i < szef.OszczNum.size(); ++i) {
		if (szef.OszczNum.empty()) {
			break;
		}

		if (szef.OszczNum[i]->Num == prev) {
			szef.OszczNum[i]->Num = newer;
		}
	}
}

void Employee::deeleteAcc(Account& szef, int num) {
	for (int i = 0; i < szef.BiezNum.size(); ++i) {
		if (szef.BiezNum.empty()) {
			break;
		}

		if (szef.BiezNum[i]->Num == num) {
			delete szef.BiezNum[i];
			szef.BiezNum.erase(szef.BiezNum.begin() + i);
		}
	}

	for (int i = 0; i < szef.OszczNum.size(); ++i) {
		if (szef.OszczNum.empty()) {
			break;
		}

		if (szef.OszczNum[i]->Num == num) {
			delete szef.OszczNum[i];
			szef.OszczNum.erase(szef.OszczNum.begin() + i);
		}
	}
}

void Employee::Nuke(Account& szef) {
	szef.Nuke();
}
