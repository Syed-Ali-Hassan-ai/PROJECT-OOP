#include <iostream>
#include <string>

using namespace std;
const int MAX_students = 100;
const int MAX_Teachers = 100;
const int MAX_course = 50;

struct Course
{
    string course_name;
    int course_id;
};

struct student
{
    string name;
    int reg;
    int course;
    int course2[5];
    int numcourse=0;
    Course* courses[5];
};

student s[MAX_students];

int numstudents = 0;
int numcourse = 0;
Course c[MAX_course];

struct teacher
{
    string name;
    int id;
    char dept[10];
    int courseid;
    int numStudents;
    int studentIDs[MAX_students];
};
teacher t[MAX_Teachers];
int numteachers = 0;
void addstudent();
void addteacher();
void showstudent();
void showteachers();
void removeStudent();
void removeTeacher();
void updateStudent();
void updateTeacher();
void addCourse();
void showCourse();
void removeCourse();
void updatecourse();
void sortStudentsByCourse();
void assignStudentsToTeachers();
void printTeacherStudents();
void homescreen();
void enrollCourse();
void displayEnrolledCourses();

void admin()
{

    int choice;
    do // executes atleast once
    {
        /* code */

        cout << "                 Admin System initiated " << endl;
        cout << "                 1. Add a student " << endl;
        cout << "                 2. Remove a student " << endl;
        cout << "                 3. Add a Teacher  " << endl;
        cout << "                 4. Remove a Teacher " << endl;
        cout << "                 5. Show all students " << endl;
        cout << "                 6. Show all Teachers " << endl;
        cout << "                 7. Update a student " << endl;
        cout << "                 8. Update Teacher " << endl;
        cout << "                 9. Add a course " << endl;
        cout << "                 10. Show a course " << endl;
        cout << "                 11. Remove a course " << endl;
        cout << "                 12. Update a course " << endl;
        cout << "                 13. Assign students to teacher    " << endl;
        cout << "                 14. Print Student According to Teacher  " << endl;
        cout << "                 15. Go back to Homescreen   " << endl;
        cout << "                 16. Quit   " << endl;

        cout << "                 Enter Your Choice ";
        cin >> choice;

        if (choice == 1)
        {

            /* code */
            addstudent();
        }

        else if (choice == 3)
        {
            /* code */

            // cout<<"Enter How many teacher you want to add";cin>>size2;

            addteacher();
        }

        else if (choice == 5)
        {
            /* code */

            showstudent();
        }
        else if (choice == 6)
        {
            /* code */

            showteachers();
        }
        else if (choice == 2)
        {
            removeStudent();
        }
        else if (choice == 4)
        {
            /* code */
            removeTeacher();
        }
        else if (choice == 7)
        {
            /* code */
            updateStudent();
        }
        else if (choice == 8)
        {
            /* code */
            updateTeacher();
        }
        else if (choice == 9)
        {
            /* code */
            addCourse();
        }
        else if (choice == 10)
        {
            /* code */
            showCourse();
        }
        else if (choice == 11)
        {
            /* code */
            removeCourse();
        }
        else if (choice == 12)
        { /* code */
            updatecourse();
        }

        else if (choice == 13)
        { /* code */
            assignStudentsToTeachers();
        }
        else if (choice == 14)
        { /* code */
            printTeacherStudents();
        }
        else if (choice == 15)
        {
            /* code */
            homescreen();
        }

    } while (choice != 16);
}
void seestudent();
void student1()
{
    int choice;
    cout << "                 Student Portal " << endl;
    cout << "                 1. See your Detail " << endl;
    cout << "                 2. Enroll in a course" << endl;
    cout << "                 3. See list of courses one is enrolled in " << endl;
    cout << "                 4. See list of His Teachers " << endl;

    cout << "                 7. Quit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        /* code */
        seestudent();

        break;
    case 2:
        
        enrollCourse();
        break;
    case 3:
        displayEnrolledCourses();
        
    default:
        break;
    }
}
void homescreen()

{
    cout << "                 Learning Management System" << endl;
    cout << endl;
    cout << "                             GIKI            " << endl;

    cout << "                 1. Admin " << endl;
    cout << "                 2. Student " << endl;
    cout << "                 3. Teacher " << endl;
    cout << "Enter your choice " << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        /* code */
        admin();
        break;
    case 2:
        student1();
        break;
    default:
        break;
    }
}

int main()
{
    homescreen();
}

void addCourse()
{
    cout << "Enter course name: ";
    cin >> c[numcourse].course_name;
    cout << "Enter course id: ";
    cin >> c[numcourse].course_id;
    numcourse++;
    cout << "Couse added successfully" << endl;
}
void removeCourse()
{
    if (numcourse == 0)
    {
        cout << "No courses to remove!" << endl;
        return;
    }

    cout << "Enter id of course to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1; // loop checking which reg to remove
    for (int i = 0; i < numcourse; i++)
    {
        if (c[i].course_id == idToRemove)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1)
    {
        cout << "Course not found!" << endl;
        return;
    }
    for (int i = indexToRemove; i < numcourse - 1; i++)
    {
        c[i] = c[i + 1];
    }

    numcourse--;
    cout << "Course  removed." << endl;
}
void showCourse()
{
    if (numcourse == 0)
    {
        /* code */
        cout << "No courses to show" << endl;
    }
    else
    {
        cout << "         Showing all courses " << endl;
        // int size;
        for (int i = 0; i < numcourse; i++)
        {
            /* code */
            cout << endl;
            cout << "course " << i << endl;
            cout << "Name   : " << c[i].course_name << endl;
            cout << "ID   : " << c[i].course_id << endl;
        }
    }
}
void updatecourse()
{
    if (numcourse == 0)
    {
        cout << "No Course to update!" << endl;
        return;
    }

    cout << "Enter course ID to update: ";
    int idToUpdate;
    cin >> idToUpdate;

    int indexToUpdate = -1;
    for (int i = 0; i < numcourse; i++)
    {
        if (c[i].course_id == idToUpdate)
        { // finding where the edit is to be made
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate == -1)
    {
        cout << "Course not found!" << endl;
        return;
    }

    cout << "Enter new name of Course: ";
    cin >> c[indexToUpdate].course_name; // updating student info
    cout << "Enter new Reg of student: ";
    cin >> c[indexToUpdate].course_id;

    cout << "Course updated." << endl;
}

void addstudent()
{
    // int size;

    cout << "                 Student Entry System " << endl;
    // cout<<"How many student you want to enter ";cin>>size;

    /* code */
    cout << "Enter Student's Name ";
    cin >> s[numstudents].name;
    cout << "Enter Student's Reg ";
    cin >> s[numstudents].reg;
    cout << "Enter Course ID {1-5}";
    cin >> s[numstudents].course;

    numstudents++;
}
void addteacher()
{
    // int size;

    cout << "                 Teacher Entry System " << endl;
    // cout<<"How many Teachers you want to enter ";cin>>size;

    /* code */
    cout << "Enter Teacher's Name ";
    cin >> t[numteachers].name;
    cout << "Enter Teacher's ID ";
    cin >> t[numteachers].id;
    cout << "Enter Teacher's Dept ";
    cin >> t[numteachers].dept;
    cout << "Enter Teacher's Course ID ";
    cin >> t[numteachers].courseid;
    t[numteachers].numStudents = 0;

    numteachers++;
}
void showstudent()
{
    clearerr;
    if (numstudents == 0)
    {
        /* code */
        cout << "No students to show" << endl;
    }
    else
    {
        cout << "         Showing all students " << endl;
        // int size;
        for (int i = 0; i < numstudents; i++)
        {
            /* code */
            cout << endl;
            cout << "student " << i << endl;
            cout << "Name   : " << s[i].name << endl;
            cout << "Reg   : " << s[i].reg << endl;
            cout << "Course ID   : " << s[i].course << endl;

        }
    }
}
void showteachers()
{
    if (numteachers == 0)
    {
        /* code */
        cout << "No teachers to show" << endl;
    }
    else
    {
        cout << "         Showing all Teachers " << endl;
        // int size;
        for (int i = 0; i < numteachers; i++)
        {
            /* code */
            cout << endl;
            cout << "Teacher " << i << endl;
            cout << "Name   : " << t[i].name << endl;
            cout << "ID   : " << t[i].id << endl;
            cout << "Dept  : " << t[i].dept << endl;
        }
    }
}
void removeStudent()
{
    if (numstudents == 0)
    {
        cout << "No students to remove!" << endl;
        return;
    }

    cout << "Enter Reg of student to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1; // loop checking which reg to remove
    for (int i = 0; i < numstudents; i++)
    {
        if (s[i].reg == idToRemove)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }
    for (int i = indexToRemove; i < numstudents - 1; i++)
    {
        s[i] = s[i + 1];
    }

    numstudents--;
    cout << "Student removed." << endl;
}
void removeTeacher()
{
    if (numteachers == 0)
    {
        cout << "No Teachers to remove!" << endl;
        return;
    }

    cout << "Enter ID of teacher to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1;
    for (int i = 0; i < numteachers; i++)
    {
        if (t[i].id == idToRemove)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1)
    {
        cout << "Teacher Not found!" << endl;
        return;
    }
    for (int i = indexToRemove; i < numteachers - 1; i++)
    {
        t[i] = t[i + 1];
    }

    numteachers--;
    cout << "Teacher removed." << endl;
}
void updateStudent()
{
    if (numstudents == 0)
    {
        cout << "No students to update!" << endl;
        return;
    }

    cout << "Enter Reg of student to update: ";
    int idToUpdate;
    cin >> idToUpdate;

    int indexToUpdate = -1;
    for (int i = 0; i < numstudents; i++)
    {
        if (s[i].reg == idToUpdate)
        { // finding where the edit is to be made
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "Enter new name of student: ";
    cin >> s[indexToUpdate].name; // updating student info
    cout << "Enter new Reg of student: ";
    cin >> s[indexToUpdate].reg;

    cout << "Student updated." << endl;
}
void updateTeacher()
{
    if (numteachers == 0)
    {
        /* code */
        cout << "No Teacher to update " << endl;
    }
    else
    {
        int idtoupdate;
        cout << "Enter the ID you want to update ";
        cin >> idtoupdate;
        int indextoupdate = -1;
        for (int i = 0; i < numteachers; i++)
        {
            /* code */
            if (t[numstudents].id == idtoupdate)
            {
                /* code */
                indextoupdate = i;
                break;
            }
        }
        if (indextoupdate == -1)
        {
            /* code */
            cout << "Teacher not found ";
            return;
        }
        cout << "Enter the Name you Want to update ";
        cin >> t[indextoupdate].name;
        cout << "Enter the ID you Want to update ";
        cin >> t[indextoupdate].id;
        cout << "Enter the Dept you want to update  ";
        cin >> t[indextoupdate].dept;
        cout << "Teacher Updated. " << endl;
    }
}
void sortStudentsByCourse()
{
    for (int i = 0; i < numstudents; i++)
    {
        for (int j = 0; j < numstudents - 1; j++)
        {
            if (s[j].course > s[j].course)
            {
                student temp = s[j];
                s[j] = s[j];
                s[j] = temp;
            }
        }
    }
}
void assignStudentsToTeachers()
{
    sortStudentsByCourse();

    int studentIndex = 0;
    int teacherIndex = 0;

    while (studentIndex < numstudents && teacherIndex < numteachers)
    {
        if (s[studentIndex].course == t[teacherIndex].courseid)
        {
            cout << s[studentIndex].name << " (ID: " << s[studentIndex].reg << ") assigned to " << t[teacherIndex].name << endl;
            studentIndex++;
        }
        else if (s[studentIndex].course < t[teacherIndex].courseid)
        {
            studentIndex++;
        }
        else
        {
            teacherIndex++;
        }
    }
}
void printTeacherStudents()
{
    cout << "Enter Name of teacher : ";
    string teacherName;
    cin >> teacherName;

    int teacherIndex = -1;
    for (int i = 0; i < numteachers; i++)
    {
        if (t[i].name == teacherName)
        {
            teacherIndex = i;
            break;
        }
    }

    if (teacherIndex == -1)
    {
        cout << "Teacher not found!" << endl;
        return;
    }

    cout << "List of students assigned to " << teacherName << ":" << endl;
    for (int i = 0; i < t[teacherIndex].numStudents; i++)
    {
        int studentId = t[teacherIndex].studentIDs[i];
        for (int j = 0; j < numstudents; j++)
        {
            if (s[j].reg == studentId)
            {
                cout << s[j].name << " (ID: " << s[j].reg << ", Course: " << s[j].course << ")" << endl;
                break;
            }
        }
    }
}

void seestudent()
{
    // Iterate through the array of students
    int regNumber;
    cout << "Enter your registration number: ";
    cin >> regNumber;
    for (int i = 0; i < numstudents; i++)
    {
        // If we find a student with a matching registration number, display their details
        if (s[i].reg == regNumber)
        {
            cout << "Name: " << s[i].name << endl;
            cout << "Major: " << s[i].course << endl;
            cout << "Registration Number: " << s[i].reg << endl;
            return;
        }
    }
}
void enrollCourse() {
    int courseId, studentId;
    bool courseFound = false, studentFound = false;
    cout << "Enter course ID: ";
    cin >> courseId;
    cin.ignore();
    for (int i = 0; i < numcourse; i++) {
        if (c[i].course_id == courseId) {
            courseFound = true;
            break;
        }
    }
    if (!courseFound) {
        cout << "Course not found" << endl;
        return;
    }
    cout << "Enter student ID: ";
    cin >> studentId;
    cin.ignore();
    for (int i = 0; i < numstudents; i++) {
        if (s[i].reg == studentId) {
            studentFound = true;
            if (s[i].numcourse >= 5) {
                cout << "Maximum number of courses reached for student " << s[i].name << endl;
                return;
            }
            s[i].courses[s[i].numcourse++] = &c[courseId];
            cout << "Enrollment successful" << endl;
            break;
        }
    }
    if (!studentFound) {
        cout << "Student not found" << endl;
        return;
    }
}
void displayEnrolledCourses() {
    int studentID;
    bool found = false;
    cout << "Enter student ID: ";
    cin >> studentID;
    cin.ignore();
    for (int i = 0; i < numstudents; i++) {
        if (s[i].reg == studentID) {
            found = true;
            cout << "Enrolled courses for student " << s[i].name << ":" << endl;
            for (int j = 0; j < numcourse; j++) 
            {
                if (s[i].course2[j] != -1) {
                    cout << "- " << c[s[i].course2[j]].course_name << endl;
                }
            }
            break;
        }
    }
    if (!found) {
        cout << "Student not found" << endl;
    }
}

