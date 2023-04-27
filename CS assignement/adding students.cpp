#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

void addStudents(Student students[]) {
    // add 5 students to the array
    for (int i = 0; i < 5; i++) {
        cout << "Enter name of student " << i+1 << ": ";
        getline(cin, students[i].name);
        cout << "Enter age of student " << i+1 << ": ";
        cin >> students[i].age;
        cout << "Enter GPA of student " << i+1 << ": ";
        cin >> students[i].gpa;
        cin.ignore(); // ignore newline character after inputting GPA
    }
}

void displayStudents(Student students[]) {
    // display all students in the array
    cout << "List of students:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << students[i].gpa << endl;
    }
}

int main() {
    Student students[5];
    addStudents(students);
    displayStudents(students);
    return 0;
}
