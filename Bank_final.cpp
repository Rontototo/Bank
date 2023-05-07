#include "Accounts.h"
#include "User.h"
#include <iostream>

int main()
{
    Account szef(0);
    Biezace biezace(0);
    Oszczednosciowe oszczednosciowe(0);
    Client klient;
    Employee pracownik;

    pracownik.CreateAccB(biezace, 123456);
    pracownik.CreateAccO(oszczednosciowe, 654321);

    klient.MoneIn(szef, 123456, 200);
    klient.MoneIn(szef, 654321, 300);

    klient.ShowStat(szef, 123456);
    klient.ShowStat(szef, 654321);

    klient.MoneOut(szef, 123456, 50);
    klient.MoneOut(szef, 654321, 20);

    biezace.Naleznosc();
    oszczednosciowe.Oszczedz();

    klient.ShowStat(szef, 123456);
    klient.ShowStat(szef, 654321);

    pracownik.deeleteAcc(szef, 654321);
    pracownik.ChangeNum(szef, 123456, 987654);

    klient.ShowStat(szef, 123456);
    klient.ShowStat(szef, 654321);
    klient.ShowStat(szef, 987654);

    pracownik.Nuke(szef);

    return 0;
}