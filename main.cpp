#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Admin.h"
#include "user.h"
#include <ctime>
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
using namespace std;
void homesceen()
{
    int choice;
    User admin;
    Checker visitor;
    do
    {
        
        
        cout<<BLUE<<BOLD<<"\t\t__________________Welcome To the Gating System GIKI__________________"<<RESET<<endl;
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
            visitor.user();
            break;
        case 3:
            admin.save_users("test.txt");
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
    User user;
    user.load_users("test.txt");

    homesceen();
}