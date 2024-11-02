 //  Program II 
//  Ty'Mon
//  Partner: Shane
//  10/10/24

#ifndef PHONETYPE_H 
#define PHONETYPE_H 

#include<iostream> 
using namespace std; 

class PhoneType 
{ 
private: 
    int index; 
    string model; 
    string brand; 
    float price; 

public: 
    PhoneType(int, string, string, float); 

    int getIndex(); 
    void setIndex(int); 
    float getPrice(); 

    bool operator <(const PhoneType& p); 
    bool operator >(const PhoneType& p); 

    friend ostream& operator <<(ostream& os, const PhoneType& p) 
    { 
        os << p.brand << " " << p.model << ": $" << p.price; 
        return os; 
    } 
}; 

#endif
