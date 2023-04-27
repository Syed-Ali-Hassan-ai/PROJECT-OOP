#include <iostream>
#include <string>

using namespace std;
const int MAX_students=100;
const int MAX_Teachers=100;

struct student
{
    string name;
    int reg;
    int course;

};
int numstudents=0;
student s[MAX_students];

struct teacher
{
    string name;
    int id;
    char dept[10];
    int numStudents;
    int studentIDs[MAX_students];
};
teacher t[MAX_Teachers];
int numteachers=0;
void addstudent();
void addteacher();
void showstudent();
void showteachers();
void removeStudent();
void removeTeacher();
void updateStudent();
void updateTeacher();

void admin()
{
    
    int choice;
    do
    {
        /* code */
    
    cout<<"                 Admin System initiated "<<endl;
    cout<<"                 1. Add a student "<<endl;
    cout<<"                 2. Remove a student "<<endl;
    cout<<"                 3. Add a Teacher  "<<endl;
    cout<<"                 4. Remove a Teacher "<<endl;
    cout<<"                 5. Show all students "<<endl;
    cout<<"                 6. Show all Teachers "<<endl;
    cout<<"                 7. Update a student "<<endl;
    cout<<"                 8. Update Teacher "<<endl;
    cout<<"                 9. Quit   "<<endl;

    cout<<"                 Enter Your Choice ";cin>>choice;

    if(choice==1){


        /* code */
        addstudent();
    }

        else if (choice==3)
        {
            /* code */
        
        //cout<<"Enter How many teacher you want to add";cin>>size2;
       
        addteacher();

        }
    
    else if (choice==5)
    {
        /* code */
        
        
        showstudent();
    }
    else if (choice==6)
    {
        /* code */
    
        
        showteachers();
    }
    else if (choice==2)
    {
         removeStudent();
    }
    else if (choice==4)
    {
        /* code */
        removeTeacher();
    }
    else if (choice==7)
    {
        /* code */
        updateStudent();
    }
    else if (choice==8)
    {
        /* code */
        updateTeacher();
    }
    
    
    } while (choice!=9);
}
void homescreen()

{
    cout<<"                 Learning Management System"<<endl;
    cout<<endl;
    cout<<"                             GIKI            "<<endl;
    
    cout<<"                 1. Admin "<<endl;
    cout<<"                 2. Student "<<endl;
    cout<<"                 3. Teacher "<<endl;
    cout<<"Enter your choice "<<endl;
    int choice;cin>>choice;


    switch (choice)
    {
    case 1:
        /* code */
        admin();
        break;
    
    default:
        break;
    }
}

int main()
{
    homescreen();
}
void addstudent()
{
    //int size;
    
    
    cout<<"                 Student Entry System "<<endl;
    // cout<<"How many student you want to enter ";cin>>size;
    
        /* code */
     cout<<"Enter Student's Name ";
     cin>>s[numstudents].name;
     cout<<"Enter Student's Reg ";cin>>s[numstudents].reg;

    numstudents++;

    
}
void addteacher()
{
    // int size;
    
    cout<<"                 Teacher Entry System "<<endl;
    // cout<<"How many Teachers you want to enter ";cin>>size;
    
        /* code */
     cout<<"Enter Teacher's Name ";cin>>t[numteachers].name;
     cout<<"Enter Teacher's ID ";cin>>t[numteachers].id;
     cout<<"Enter Teacher's Dept ";cin>>t[numteachers].dept;
      t[numteachers].numStudents = 0;

    numteachers++;

    
}
void showstudent()
{
    clearerr;
    if (numstudents==0)
    {
        /* code */
        cout<<"No students to show"<<endl;
    }
    else{
    cout<<"         Showing all students "<<endl;
    // int size;
    for (int i = 0; i < numstudents; i++)
    {
        /* code */
        cout<<endl;
        cout<<"student "<<  i<<endl;
        cout<<"Name   : "<<s[i].name<<endl;
        cout<<"Reg   : "<<s[i].reg<<endl;
    }
    }
}
void showteachers()
{
    if (numteachers==0)
    {
        /* code */
        cout<<"No teachers to show"<<endl;
    }
    else{
    cout<<"         Showing all Teachers "<<endl;
    // int size;
    for (int i = 0; i < numteachers; i++)
    {
        /* code */
        cout<<endl;
        cout<<"Teacher "<<  i<<endl;
        cout<<"Name   : "<<t[i].name<<endl;
        cout<<"ID   : "<<t[i].id<<endl;
        cout<<"Dept  : "<<t[i].dept<<endl;
    
    }
    }
}
void removeStudent() {
    if (numstudents == 0) {
        cout << "No students to remove!" << endl;
        return;
    }

    cout << "Enter Reg of student to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1;
    for (int i = 0; i < numstudents; i++) {
        if (s[i].reg == idToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "Student not found!" << endl;
        return;
    }
        for (int i = indexToRemove; i < numstudents - 1; i++) {
        s[i] = s[i + 1];
    }

    numstudents--;
    cout << "Student removed." << endl;
}
void removeTeacher() {
    if (numteachers == 0) {
        cout << "No Teachers to remove!" << endl;
        return;
    }

    cout << "Enter ID of teacher to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1;
    for (int i = 0; i < numteachers; i++) {
        if (t[i].id == idToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "Teacher Not found!" << endl;
        return;
    }
        for (int i = indexToRemove; i < numteachers - 1; i++) {
        t[i] = t[i + 1];
    }

    numteachers--;
    cout << "Teacher removed." << endl;
}
void updateStudent() {
    if (numstudents == 0) {
        cout << "No students to update!" << endl;
        return;
    }

    cout << "Enter Reg of student to update: ";
    int idToUpdate;
    cin >> idToUpdate;

    int indexToUpdate = -1;
    for (int i = 0; i < numstudents; i++) {
        if (s[i].reg == idToUpdate) {
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "Enter new name of student: ";
    cin >> s[indexToUpdate].name;
    cout << "Enter new Reg of student: ";
    cin >> s[indexToUpdate].reg;

    cout << "Student updated." << endl;
}
void updateTeacher()
{
    if (numteachers==0)
    {
        /* code */
        cout<<"No Teacher to update "<<endl;
    }
    else
    {
        int idtoupdate;
        cout<<"Enter the ID you want to update ";
        cin>>idtoupdate;
        int indextoupdate=-1;
        for (int i = 0; i < numteachers; i++)
        {
            /* code */
            if (t[numstudents].id==idtoupdate)
            {
                /* code */
                indextoupdate=i;
                break;

            }
            
        }
        if (indextoupdate==-1)
        {
            /* code */
            cout<<"Teacher not found ";
            return;
        }
        cout<<"Enter the Name you Want to update ";cin>>t[indextoupdate].name;
        cout<<"Enter the ID you Want to update ";cin>>t[indextoupdate].id;
        cout<<"Enter the Dept you want to update  ";cin>>t[indextoupdate].dept;
        cout<<"Teacher Updated. "<<endl;
        


    };
    
}
void printTeacherStudents() {
    cout << "Enter teacher name: ";
    string teacherName;
    cin >> teacherName;

    int teacherIndex = -1;
    for (int i = 0; i < numteachers; i++) {
        if (t[i].name == teacherName) {
            teacherIndex = i;
            break;
        }
    }

    if (teacherIndex == -1) {
        cout << "Teacher not found!" << endl;
        return;
    }

    cout << "List of students assigned to " << teacherName << ":" << endl;
    for (int i = 0; i < t[teacherIndex].numStudents; i++) {
        int studentId = t[teacherIndex].studentIDs[i];
        for (int j = 0; j < numstudents; j++) {
            if (s[j].reg == studentId) {
                cout << s[j].name << " (ID: " << s[j].reg << ", Course: " << s[j].course  << ")" << endl;
                break;
            }
        }
    }
}
