//  Program II 
//  Ty'Mon Harvey 
//  Partner: Shane Brown
//  10/10/24

 

#include<fstream>
#include<iostream>
#include<string>
#include "PhoneType.h"  
#include "list.h"

using namespace std;

int main() {
    ifstream file;
    file.open("Phone_list.txt", ios::in);  

    if (!file.is_open()) {
        cout << "Error: Could not open the file!" << endl;
        return -1;
    }

    LinkedList<PhoneType*> phones;  
    PhoneType* newPhone;  

    int index;
    string model, brand;
    float price;

    while (file >> index >> model >> brand >> price) {
       
        newPhone = new PhoneType(index, model, brand, price);  

        
        phones.append(newPhone);  
    }

    file.close();

    // Sort the linked list
    phones.mergeSort();  

    // Print the sorted list
    phones.print();  

    return 0;
}
