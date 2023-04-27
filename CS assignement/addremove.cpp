#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 10;

struct Student {
    string name;
    int id;
};

int numStudents = 0;
Student students[MAX_STUDENTS];

void addStudent() {
    if (numStudents == MAX_STUDENTS) {
        cout << "Cannot add more students, maximum reached!" << endl;
        return;
    }

    cout << "Enter name of student: ";
    cin >> students[numStudents].name;
    cout << "Enter ID of student: ";
    cin >> students[numStudents].id;
    numStudents++;
}

void removeStudent() {
    if (numStudents == 0) {
        cout << "No students to remove!" << endl;
        return;
    }

    cout << "Enter ID of student to remove: ";
    int idToRemove;
    cin >> idToRemove;

    int indexToRemove = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == idToRemove) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    for (int i = indexToRemove; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    numStudents--;
    cout << "Student removed." << endl;
}

void printStudents() {
    if (numStudents == 0) {
        cout << "No students to print!" << endl;
        return;
    }

    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << students[i].name << " (ID: " << students[i].id << ")" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Remove student" << endl;
        cout << "3. Print students" << endl;
        cout << "4. Quit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                printStudents();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
