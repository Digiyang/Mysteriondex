#include"CAddress.h"
#include<stdio.h>
#include<string>
#include<iostream>

CAddress::CAddress(std::string s, std::string p, std::string t)
{
    Street = s ;
    Postcode = p ;
    Town = t ; 
}

void CAddress::print()
{
    std::cout << Street << "\n" << Postcode << " " <<Town ;/*<< Postcode << Town ;*/
}