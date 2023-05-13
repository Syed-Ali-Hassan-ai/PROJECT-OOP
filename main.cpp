#include <iostream>
#include <stdlib.h>
#include "Admin.h"
#include "user.h"
using namespace std;
void homesceen()
{
    int choice;
    User admin;
    Checker visitor;
    do
    {
        /* code */
        system("cls");
        cout<<"\t\t__________________Welcome To the Gating System GIKI__________________"<<endl;
        cout<<"\t\t1. Admin "<<endl;
        cout<<"\t\t2. User "<<endl;
        cout<<"\t\t3. Exit "<<endl;
        

        cout<<endl;
        cout<<"Enter your Choice ";cin>>choice;

        switch (choice)
        {
        case 1:
            admin.admin();
            break;
        case 2:
            visitor.check();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice!=3);
    
}
int main()
{
    homesceen();
}