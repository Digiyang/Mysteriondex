#ifndef CACCOUNT_H_INCLUDED
   #define CACCOUNT_H_INCLUDED
   
   #include "CMoney.h"
   #include "CCustomer.h"
   #include <string>
   using namespace std;
   
   class CCustomer;

   class CAccount 
   {
      public:
      
      CAccount(std::string , CCustomer* , CMoney );
      void setIBAN(std::string iban){
         IBAN = iban;
      }
      std::string getIBAN(){
         return IBAN;
      }
      void print();
        
      private:
      
      std::string IBAN ;
      CCustomer *customer;
      CMoney balance ;
      
   };

#endif