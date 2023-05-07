#pragma once
#include "User.h"
#include <vector>

using namespace std;

class Account {
protected:
	friend class Employee;
	friend class Client;
	friend class Biezace;
	friend class Oszczednosciowe;
	static vector <Oszczednosciowe*> OszczNum;
	static vector <Biezace*> BiezNum;
	int Num;
	double Stat;
	void Nuke();
	void MonIn(int num, int mone);
	void MonOut(int num, int mone);
	void ShowStat(int num);
public:
	Account(int a);
	virtual ~Account();
};

class Biezace : protected Account {
protected:
	friend class Employee;
	friend class Account;
	friend class Oszczednosciowe;
	void MakeAcc(int num);
public:
	Biezace(int a);
	virtual ~Biezace();
	void Naleznosc();
};

class Oszczednosciowe : protected Account {
protected:
	friend class Employee;
	friend class Account;
	friend class Biezace;
	void MakeAcc(int num);
public:
	Oszczednosciowe(int a);
	virtual ~Oszczednosciowe();
	void Oszczedz();
};