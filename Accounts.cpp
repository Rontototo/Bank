#include "Accounts.h"
#include "User.h"
#include <vector>
#include <iostream>

using namespace std;

vector <Biezace*> Account::BiezNum;
vector <Oszczednosciowe*> Account::OszczNum;

//----------------------Account-------------------------------

Account::Account(int a) : Num(a), Stat(0) {
	cout << "Utworzono konto\n";
}

Account::~Account() {
	cout << "Usunieto konto\n\n";
}

void Account::ShowStat(int num) {
	for (int i = 0; i < OszczNum.size(); ++i) {
		if (OszczNum.empty()) {
			break;
		}
		if (OszczNum[i]->Num == num) {
			cout << "Stan konta: " << OszczNum[i]->Stat << endl << endl;
		}
	}

	for (int i = 0; i < BiezNum.size(); ++i) {
		if (BiezNum.empty()) {
			break;
		}
		if (BiezNum[i]->Num == num) {
			cout << "Stan konta: " << BiezNum[i]->Stat << endl << endl;
		}
	}
}

void Account::Nuke() {
	for (int i = OszczNum.size() - 1; i >= 0; --i) {
		delete OszczNum[i];
		OszczNum.erase(OszczNum.begin() + i);
	}

	for (int i = BiezNum.size() - 1; i >= 0; --i) {
		delete BiezNum[i];
		BiezNum.erase(BiezNum.begin() + i);
	}
}

void Account::MonIn(int num, int mone) {
	for (int i = 0; i < OszczNum.size(); ++i) {
		if (OszczNum.empty()) {
			cout << "Nie ma takiego konta\n\n";
			break;
		}
		if (OszczNum[i]->Num == num) {
			OszczNum[i]->Stat += mone;
			break;
		}
	}

	for (int i = 0; i < BiezNum.size(); ++i) {
		if (BiezNum.empty()) {
			cout << "Nie ma takiego konta\n\n";
			break;
		}
		if (BiezNum[i]->Num == num) {
			BiezNum[i]->Stat += mone;
			break;
		}
	}
}

void Account::MonOut(int num, int mone) {
	for (int i = 0; i < OszczNum.size(); ++i) {
		if (OszczNum.empty()) {
			cout << "Nie ma takiego konta\n\n";
			break;
		}
		if (OszczNum[i]->Num == num) {
			OszczNum[i]->Stat -= mone;
			break;
		}
	}

	for (int i = 0; i < BiezNum.size(); ++i) {
		if (BiezNum.empty()) {
			cout << "Nie ma takiego konta\n\n";
			break;
		}
		if (BiezNum[i]->Num == num) {
			BiezNum[i]->Stat -= mone;
			break;
		}
	}
}

//----------------------Biezace--------------------------------

Biezace::Biezace(int a) : Account(a) {
	cout << "Jest to konto biezace\n\n";
}

Biezace::~Biezace() {
	cout << "Usunieto konto biezace\n";
}

void Biezace::Naleznosc() {
	for (int i = 0; i < BiezNum.size(); ++i) {
		BiezNum[i]->Stat -= 15;
	}
}

void Biezace::MakeAcc(int num) {
	if (num < 10000) {
		cout << "Numer niezgodny z kryteriami\n\n";
		return;
	}
	
	for (int i = 0; i < OszczNum.size(); ++i) {
		if (OszczNum.empty()) {
			break;
		}

		else if (OszczNum[i]->Num == num) {
			cout << "Klient o tym numerze juz istnieje\n\n";
			return;
		}
	}

	for (int i = 0; i < BiezNum.size(); ++i) {
		if (BiezNum.empty()) {
			BiezNum.push_back(new Biezace(num));
		}

		else if (BiezNum[i]->Num == num) {
			cout << "Klient o tym numerze juz istnieje\n\n";
			return;
		}
	}

	BiezNum.push_back(new Biezace(num));
}

//----------------------Oszczednosciowe-------------------------

Oszczednosciowe::Oszczednosciowe(int a) : Account(a) {
	cout << "Jest to konto oszczednosciowe\n\n";
}

Oszczednosciowe::~Oszczednosciowe() {
	cout << "Usunieto konto oszczednosiowe\n";
}

void Oszczednosciowe::Oszczedz() { 
	for (int i = 0; i < OszczNum.size(); ++i) {
		OszczNum[i]->Stat += OszczNum[i]->Stat * 0.05;
	}
}

void Oszczednosciowe::MakeAcc(int num) {
	if (num < 10000) {
		cout << "Numer niezgodny z kryteriami\n\n";
		return;
	}

	for (int i = 0; i < BiezNum.size(); ++i) {
		if (BiezNum.empty()) {
			break;
		}

		else if (BiezNum[i]->Num == num) {
			cout << "Klient o tym numerze juz istnieje\n\n";
			return;
		}
	}

	for (int i = 0; i < OszczNum.size(); ++i) {
		if (OszczNum.empty()) {
			OszczNum.push_back(new Oszczednosciowe(num));
		}

		else if (OszczNum[i]->Num == num) {
			cout << "Klient o tym numerze juz istnieje\n\n";
			return;
		}
	}

	OszczNum.push_back(new Oszczednosciowe(num));
}