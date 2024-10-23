//  Program II 
//  Ty'Mon Harvey
//  Partner: Shane Brown
//  10/10/23


#include "PhoneType.h" 

PhoneType::PhoneType(int i, string m, string b, float p) 
{ 
    index = i; 
    model = m; 
    brand = b; 
    price = p; 
} 

int PhoneType::getIndex() 
{ 
    return index; 
} 

void PhoneType::setIndex(int i) 
{ 
    index = i; 
} 

float PhoneType::getPrice() 
{ 
    return price; 
} 

bool PhoneType::operator <(const PhoneType& p) 
{ 
    return price < p.price; 
} 

bool PhoneType::operator >(const PhoneType& p) 
{ 
    return price > p.price; 
}
