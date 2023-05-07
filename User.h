#pragma once
#include "Accounts.h"

class User {
public:
	friend class Account;
	User();
	virtual ~User();
};

class Client : public User {
public:
	Client();
	virtual ~Client();
	void MoneIn(Account&, int num, int mone);
	void MoneOut(Account&, int num, int mone);
	void ShowStat(Account&, int num);
};

class Employee : public User {
public:
	friend class Biezace;
	friend class Oszczednosciowe;
	Employee();
	virtual ~Employee();
	void CreateAccB(Biezace&, int num);
	void CreateAccO(Oszczednosciowe&, int num);
	void ChangeNum(Account&, int prev, int newer);
	void deeleteAcc(Account&, int num);
	void Nuke(Account&);
};