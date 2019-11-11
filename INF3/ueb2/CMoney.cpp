#include"CMoney.h"
#include <stdio.h>
#include<string>
#include<iostream>



CMoney::CMoney(double a, std::string c){
     
     amount = a;
     currency = c;
     
}
    
CMoney::CMoney(double a ){
    amount = a;
    currency = "EUR";
}


void CMoney::print()
{
    std::cout << amount << " " << currency;

}