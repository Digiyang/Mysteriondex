#include<ctime>
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

#include"CDate.h"
#include"CCustomer.h"
#include"CAccount.h" 
#include"CAddress.h"

CCustomer::CCustomer(long i, std::string n, CDate b, CAddress ad)
{
    id = i;
    name = n;
    birthday = b;
    address = ad ;

    number = 0;
}
void CCustomer::print()
{
    int y;
    printf("%s (Kd-Nr. %d) \n", name.c_str(), id);
    printf("%s \n%s %s \n", address.getStreet().c_str(), address.getPostcode().c_str(),address.getTown().c_str());
    printf("geboren am: ");
    birthday.print();
    printf("\nKonten:\n");
    for(y = 0; y < getNumber(); y++)
    {
        printf("- KontoNr.: %.4s %.4s %.4s %.4s %.4s %.2s\n",accountList[y]->getIBAN().c_str(),accountList[y]->getIBAN().c_str()+4,accountList[y]->getIBAN().c_str()+8,accountList[y]->getIBAN().c_str()+12,accountList[y]->getIBAN().c_str()+16,accountList[y]->getIBAN().c_str()+20);
    }
}


