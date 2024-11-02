//  Program II 
//  Ty'Mon Harvey
//  Partner: Shane Brown
//  10/10/23

#include <iostream>
#include <fstream>
#include <string>
#include "PhoneType.h"
#include "List.h"

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\nPhone Management System\n";
    cout << "1. Add a new phone\n";
    cout << "2. Remove a phone\n";
    cout << "3. Display all phones\n";
    cout << "4. Sort phones by price\n";
    cout << "5. Load phones from file\n";
    cout << "6. Save phones to file\n";
    cout << "7. Move a phone\n";
    cout << "8. Duplicate a phone\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

// Function to load phones from a file into the linked list
void loadFromFile(LinkedList<PhoneType>& phoneList, const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int index;
    string model, brand;
    float price;

    while (infile >> index >> model >> brand >> price) {
        PhoneType phone(index, model, brand, price);
        phoneList.append(phone);
    }

    infile.close();
}

// Function to save phones to a file from the linked list
void saveToFile(LinkedList<PhoneType>& phoneList, const string& filename) {
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Customize this part to write to the file
    phoneList.print();

    outfile.close();
}

int main() {
    LinkedList<PhoneType> phoneList;
    int choice;
    int index, fromIndex, toIndex;
    string model, brand, filename;
    float price;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Add a new phone
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter model: ";
            cin >> model;
            cout << "Enter brand: ";
            cin >> brand;
            cout << "Enter price: ";
            cin >> price;
            phoneList.append(PhoneType(index, model, brand, price));
            break;
        case 2: // Remove a phone
            cout << "Enter index of phone to remove: ";
            cin >> index;
            phoneList.remove(PhoneType(index, "", "", 0)); // Assuming remove can search by index
            break;
        case 3: // Display all phones
            phoneList.print();
            break;
        case 4: // Sort phones by price
            phoneList.mergeSort();
            cout << "Phones sorted by price.\n";
            break;
        case 5: // Load phones from file
            cout << "Enter filename to load from: ";
            cin >> filename;
            loadFromFile(phoneList, filename);
            cout << "Phones loaded from file.\n";
            break;
        case 6: // Save phones to file
            cout << "Enter filename to save to: ";
            cin >> filename;
            saveToFile(phoneList, filename);
            cout << "Phones saved to file.\n";
            break;
        case 7: // Move phone
            cout << "Enter the current index of the phone to move: ";
            cin >> fromIndex;
            cout << "Enter the new index position for the phone: ";
            cin >> toIndex;
            phoneList.move(fromIndex, toIndex);
            break;
        case 8: // Duplicate phone
            cout << "Enter the index of the phone to duplicate: ";
            cin >> index;
            phoneList.duplicate(index);
            break;
        case 9: // Exit
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
