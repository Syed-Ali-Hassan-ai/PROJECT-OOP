#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

void addStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, students[i].name);
        cout << "Enter age of student " << i + 1 << ": ";
        cin >> students[i].age;
        cout << "Enter GPA of student " << i + 1 << ": ";
        cin >> students[i].gpa;
        cin.ignore(); // ignore newline character after inputting GPA
    }
}

void displayStudents(Student students[], int numStudents) {
    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << students[i].gpa << endl;
    }
}

void homeScreen() {
    cout << "Welcome to the student database!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add students" << endl;
    cout << "2. Display list of students" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        homeScreen();
        cin >> choice;
        cin.ignore(); // ignore newline character after inputting choice

        switch (choice) {
            case 1:
                cout << "How many students do you want to add? ";
                cin >> numStudents;
                cin.ignore(); // ignore newline character after inputting numStudents
                addStudents(students, numStudents);
                cout << numStudents << " students added successfully!" << endl;
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
