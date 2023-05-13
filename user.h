#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Admin.h"

class Checker   // Make checker a friend class to access protected members
{
    public:
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
                << "\t\tWELCOME";                
            }

            else 
            {
                cout << "Entry Invalid, Contact ADMIN";
                return;
            }                
        }
    }
};
