#ifndef CADDRESS_H_INCLUDED
    #define CADDRESS_H_INCLUDED
#include<string>
using namespace std;

class CAddress{
        
    public:
        
        CAddress();
        CAddress(std::string s,std::string p, std::string t);
        std::string getStreet()
        {   return Street;}
        std::string getPostcode()
        {   return Postcode;}
        std::string getTown()
        {   return Town;}

        void setStreet(std::string s)
            {   Street = s;}
        void setPostcode(std::string p)
            {   Postcode = p;}
        void setTown(std::string t)
            {   Town = t;}    
        void print(); 
    
    private:
        
        std::string Street;
        std::string Postcode;
        std::string Town;      
          
};
#endif