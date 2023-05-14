#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Student.h"
#include "Admin.h"

class Checker   // Make checker a friend class to access protected members
{
    public:
    void user()
    {
        int choice = 0;
        while (choice != 4)
        {
            cout << "Address Book Menu:\n";
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
            cout << "Return to Main Menu";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
            }
        }
    }
    void check()
    {
        string nic; 
        cout << "Enter your CNIC: "; 
        cin >> nic;

        for (int i = 0; i < users.size(); i++)
        {
            if (nic == users[i].cnic)
            {
                cout << "\t\t USER VERIFIED, ENTRY GRANTED TO GIKI\n" << "================================\n"
                << "\t\tWELCOME\n";
                   time_t now = time(0);
                users[i].tym = ctime(& now);

                cout << "\tYou Entered Ghulam Ishaq Khan Institute at " << users[i].tym;  
                //homesceen();
            }

            if (nic != users[i].cnic)
            {
                cout << "ENtry DENIED!!!\n" ; 
                //homesceen();
            }          
        }
    }

    void Exit()
    {
        string nic; 
        cout << "Enter your CNIC: "; 
        cin >> nic;

        for (int i = 0; i < users.size(); i++)
        {
            if (nic == users[i].cnic)
            {
                cout << "\t\t USER VERIFIED, YOU CAN EXIT GIKI NOW\n" << "================================\n"
                << "\t\tWELCOME\n";
                //users[i].tym = time (0);
                cout << "\tYou EXITED Ghulam Ishaq Khan Institute at " << time(0);  
            }

            else 
            {
                cout << "Entry Invalid, Contact ADMIN";
                return;
            }                
        }
    }
};
