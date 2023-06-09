#ifndef Adminh
#define Adminh
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

vector<Student> users;

class User // Removed inheritance from Student because we have made it a friend class
{
private:
    friend class Checker;

    void add_user()
    {
        string n, a, p, d, c, t;
        char g;
        cout << "Enter first name: ";
        cin >> n;
        cout << "Enter gender (M/F): ";
        cin >> g;
        cin.ignore(); // Add this line to clear the newline character in buffer
        cout << "Enter address: ";
        getline(cin, a); // Changed from cin to getline to properly read the address
        cout << "Enter phone number: ";
        cin >> p;
        cout << "Enter date of birth (YYYY-MM-DD): ";
        cin >> d;
        cout << "Enter your CNIC number (without dashes)";
        cin >> c;

        Student new_User(n, g, a, p, d, c, t);
        users.push_back(new_User);
        cout << "User added successfully!\n";
    }

    void remove_user()
    {
        int index;
        cout << "Enter the index of the user to delete: ";
        cin >> index;
        if (index >= 0 && index < users.size())
        {
            users.erase(users.begin() + index);
            cout << "User deleted successfully!\n";
        }
        else
        {
            cout << "Invalid index!\n";
        }
    }

    void display_users()
    {
        system("cls");
        cout << "\t\tUsers:\n";
        cout << "=================================\n";
        for (int i = 0; i < users.size(); i++)
        {
            cout << "Index: " << i << endl;
            cout << "Name: " << users[i].name << endl;
            cout << "Gender: " << users[i].gender << endl;
            cout << "Address: " << users[i].address << endl;
            cout << "Phone number: " << users[i].phone_number << endl;
            cout << "DOB: " << users[i].dob << endl;
            cout << "CNIC: " << users[i].cnic << endl;

            cout << endl;
        }
    }
    void Search_User_nic()
    {
        string nic;
        cout << "Enter The CNIC you want to Search ";
        cin >> nic;
        for (int i = 0; i < users.size(); i++)
        {

            if (nic == users[i].cnic)
            {
                cout << "User Name == " << users[i].name << endl;
                cout << "Phone  " << users[i].phone_number << endl;
                cout << "You Entered GIKI at :: \n";
                for (int j = 0; j < users[i].entry.size(); j++)
                {
                    cout << "\t\t" << ctime(&users[i].entry[j]);
                };
                cout << "Time Exited GIKI at :: \n";
                for (int j = 0; j < users[i].exit.size(); j++)
                {
                    cout << "\t\t" << ctime(&users[i].exit[j]);
                }
                break;
            }
            else if (nic != users[i].cnic)
            {
                cout << "User CNIC invalid \n";
                break;
            }
        }
    }

public:
    void save_users(string filename)
    {
        ofstream outFile(filename);
        if (!outFile.is_open())
        {
            cout << "Error opening file " << filename << endl;
            return;
        }

        for (int i = 0; i < users.size(); i++)
        {
            outFile << users[i].name << endl;
            outFile << users[i].gender << endl;
            outFile << users[i].address << endl;
            outFile << users[i].phone_number << endl;
            outFile << users[i].dob << endl;
            outFile << users[i].tym << endl;
            outFile << users[i].cnic << endl;
        }

        outFile.close();
    }
    void load_users(string filename)
    {
        ifstream inFile(filename);
        if (!inFile.is_open())
        {
            cout << "Error opening file " << filename << endl;
            return;
        }

        string name, gender, address, phone_number, dob, cnic, tym;
        while (getline(inFile, name))
        {
            getline(inFile, gender);
            getline(inFile, address);
            getline(inFile, phone_number);
            getline(inFile, dob);
            getline(inFile, cnic);
            getline(inFile, tym);

            Student new_User(name, gender[0], address, phone_number, dob, cnic, tym);
            users.push_back(new_User);
        }

        inFile.close();
    }

    void Search_User_range()
    {
        string name1, name2;
    cout << "Enter the first last name: ";
    cin >> name1;
    cout << "Enter the second last name: ";
    cin >> name2;
    bool print = false;
    for (int i = 0; i < users.size() ; i++)
    {
        if (users[i].name == name1)
        {
            print = true;
        }
        if (print)
        {
            cout << users[i].name << " | "
                 << users[i].cnic << " " << users[i].dob << " | " << users[i].phone_number << endl;
        }
        if (users[i].name == name2)
        {
            break;
        }
    }
    }

    void Search_User_Gender()
    {
        char gender;
        cout << "Enter the gender (M/F): ";
        cin >> gender;
        for (int i =0; i < users.size(); i++)
        {
            if (users[i].gender == gender)
            {
                cout << users[i].name << " " <<  users[i].cnic << " | "
                    <<  users[i].dob << " | " << users[i].phone_number << endl;
            }
        }
    }

    void admin()
    {
        User user;
        string filename = "users1.txt";
        save_users(filename);
        load_users(filename);

        filename = "users2.txt";
        save_users(filename);
        load_users(filename);

        // system("cls");

        int choice = 0;
        while (choice != 5)
        {
            cout << "Address Book Menu:\n";
            cout << "1. Add user\n";
            cout << "2. Remove user\n";
            cout << "3. Display all users\n";
            cout << "4. Search User With Cnic\n";
            cout << "5. Print people with the same Gender\n";
            cout << "6. Print people between Ranges of two name\n";
            cout << "7. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                display_users();
                break;
            case 4:
                Search_User_nic();
                break;
            case 5:
                Search_User_Gender();
                break;
            case 6:
                Search_User_range();
                break;   
            case 7:
                cout << "Return to main menu!\n";
                return;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        }
    }
};
#endif