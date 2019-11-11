#include<stdio.h>
#include"CCustomer.h"
#include"CAccount.h"
#include"CMoney.h"
#include<iostream>

using namespace std;

CAccount::CAccount(std::string IB, CCustomer *cu, CMoney ba)
{
      IBAN=IB;
      customer = cu;
      balance= ba;
      
      customer->AddAccount(this);
}


void CAccount::print(){
    printf("Kunde: %s (Kd-Nr. %ld) \n", customer->getName().c_str(), customer->getID());
    printf("IBAN: %.4s %.4s %.4s %.4s %.4s %.2s\n", IBAN.c_str(),IBAN.c_str()+4,IBAN.c_str()+8,IBAN.c_str()+12,IBAN.c_str()+16,IBAN.c_str()+20);
    printf("Kontostand: ");
    balance.print();
      }
