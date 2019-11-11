#ifndef CCUSTOMER_H_INCLUDED
   #define CCUSTOMER_H_INCLUDED
   #define MAXACCOUNT 10

   #include"CDate.h"
   #include"CAccount.h"
   #include"CAddress.h"
   #include<string>
  
   using namespace std;
   class CAccount;

   class CCustomer 
   {
      public:
      CCustomer(long id, std::string name , CDate birthday ,CAddress address);
      
      std::string getName(){
            return name;
      }
      long getID(){
         return id;
      }
      int getNumber(){
         return number;
      }
      void AddAccount(CAccount* x){
         accountList[number]= x;
         number ++;
      }
      void print();

      private:
      
      long id;
      int number ;
      std::string name;
      CDate birthday ;
      CAddress address;
      CAccount *accountList[MAXACCOUNT];
      

   };

#endif


