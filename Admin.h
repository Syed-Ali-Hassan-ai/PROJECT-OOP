#ifndef Adminh
#define Adminh
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;

vector<Student> users;

class User // Removed inheritance from Student because we have made it a friend class
{
private:
    // friend class Checker;

    void add_user()
    {
        system("cls");
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

        Student new_User(n, g, a, p, d, c);
        users.push_back(new_User);
        cout << "User added successfully!\n";
    }

    void remove_user()
    {
        system("cls");
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
    string temp_nic;
    int temp_i;
    void Search_User_nic()
    {
        system("cls");
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

                temp_nic = nic;
                temp_i = i;
                return;
            }
        }

        if (nic != users[temp_i].cnic)
        {
            cout << "User CNIC invalid \n";
            return;
        }
    }

    void Search_User_Gender()
    {
        system("cls");
        char gender;
        cout << "Enter the gender (M/F): ";
        cin >> gender;

        for (int i = 0; i < users.size(); i++)
        {

            if (users[i].gender == gender)
            {
                temp_i = i;
                cout << users[i].name << " " << users[i].cnic << " | "
                     << users[i].dob << " | " << users[i].phone_number << endl;
            }
        }

        if (gender != users[temp_i].gender)
        {
            cout << "Invalid Gender";
            return;
        }
    }

public:
    void Search_User_range()
    {
        system("cls");
        string name1, name2;
        cout << "Enter the first last name: ";
        cin >> name1;
        cout << "Enter the second last name: ";
        cin >> name2;
        bool print = false;
        for (int i = 0; i < users.size(); i++)
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
    // ...
    void save_users(const string &filename) const
    {
        ofstream outFile(filename); // Open the file in append mode
        cout << "\nsave_user exectued\n"
             << endl;
        if (!outFile)
        {
            cout << "Error opening file " << filename << endl;
            return;
        }
        for (const Student &user : users)
        {
            user.save_to_file(outFile);
        }

        outFile.close();
        cout << "Users saved successfully!\n";
    }

    void load_users(const string &filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "Error opening file " << filename << endl;
            return;
        }

        users.clear(); // Clear the users vector before loading data

        string name, gender, address, phone_number, dob, cnic;
        while (getline(inFile >> ws, name))
        {
            getline(inFile >> ws, gender);
            getline(inFile >> ws, address);
            getline(inFile >> ws, phone_number);
            getline(inFile >> ws, dob);
            getline(inFile >> ws, cnic);

            Student new_User(name, gender[0], address, phone_number, dob, cnic);

            // Load the entry timestamps
            int entryCount;
            inFile >> entryCount;
            inFile.ignore(); // Ignore the end-of-line character

            for (int i = 0; i < entryCount; i++)
            {
                string entryTimestampStr;
                getline(inFile >> ws, entryTimestampStr);
                new_User.entry.push_back(stoll(entryTimestampStr));
            }

            // Load the exit timestamps
            int exitCount;
            inFile >> exitCount;
            inFile.ignore(); // Ignore the end-of-line character

            for (int i = 0; i < exitCount; i++)
            {
                string exitTimestampStr;
                getline(inFile >> ws, exitTimestampStr);
                new_User.exit.push_back(stoll(exitTimestampStr));
            }

            users.push_back(new_User);
        }

        inFile.close();
        cout << "Users loaded successfully!\n";
    }

    void admin()
    {
        User user;
        string filename = "test.txt";

        // Load users from the file
        // user.load_users(filename);
        // display_users();
        cout << endl;
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
                // Save users to the file

                cout << endl;
                // user.save_users(filename);
                return;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        }
    }
};
#endif