#ifndef CMONEY_H_INCLUDED
    #define CMONEY_H_INCLUDED
#include<string>
    class CMoney{
        
        public:
            CMoney();
            CMoney(double amount);
            CMoney(double amount, std::string currency);
            void print();

            void seta(double a){
                amount = a ;
            }
            double geta(){
                return amount;
            }

            void setc(std::string c){
                currency = c ;
            }
            std::string getc(){
                return currency;
            }


        private:
            
            double amount;
            std::string currency;

            
     };
#endif