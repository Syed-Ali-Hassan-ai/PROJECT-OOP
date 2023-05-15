#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Admin.h"
#include "Time.h"

vector<Entry> time1;
vector<Exit> time2;

class Checker : public User// Make checker a friend class to access protected members
{
private:
User user1;
public:
    void user()
    {
        system("cls");
        int choice = 0;
        while (choice != 3)
        {
            cout << "Entry Exit menu Menu:\n";
            cout << "1. Verify Entry\n";
            cout << "2. Exit GIKI\n";
            cout << "3. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                check();
                break;
            case 2:
                Exit();
                break;
            case 3:
                //user1.save_users("test.txt");
                cout << "Return to Main Menu";

                break;

            default:
                cout << "Invalid choice!\n";
                break;
            }
        }
    }

    int temp =0;
    void check()
    {
        
        string nic;
        cout << "Enter your CNIC: ";
        cin >> nic;

        
        for (int i = 0; i < users.size(); i++)
        {
            if (nic == users[i].cnic)
            {
                temp = i;
                cout << "\t\t USER VERIFIED, ENTRY GRANTED TO GIKI\n"
                     << "================================\n"
                     << "\t\tWELCOME\n";
                time_t now = time(0);
                users[i].entry.push_back(now);

                cout << "\tYou Entered Ghulam Ishaq Khan Institute at " << ctime(&users[i].entry.back());
                return;

                // homesceen();
            }
        }

        if (nic != users[temp].cnic)
        {
            cout << "ENtry DENIED!!!\n";
            return;
            // homesceen();
        }
    }

    void Exit()
    {
       // system("cls");
        string anic;
        cout << "Enter your CNIC: ";
        cin >> anic;

        for (int i = 0; i < users.size(); i++)
        {
            if (anic == users[i].cnic)
            {
                temp = i;
                cout << "\t\t USER VERIFIED, YOU CAN EXIT GIKI NOW\n"
                     << "================================\n"
                     << "\t\tWELCOME\n";
                time_t now = time(0);
                users[i].exit.push_back(now);
                cout << "\tYou EXITED Ghulam Ishaq Khan Institute at " << ctime(&users[i].exit.back());
                return;
            } 
        }
        if (anic != users[temp].cnic)
            {
                cout << "Entry Invalid, Contact ADMIN";
                return;
            }
    }
};
