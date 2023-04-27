#include <iostream>
#include <string>
using namespace std;

// Define a structure to hold student information
struct Student {
    string name;
    int age;
    string major;
    string courses[5];
};

// Function to display student information
void displayStudent(Student s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Major: " << s.major << endl;
    cout << "Enrolled courses: " << endl;
    for (int i = 0; i < 5; i++) {
        if (s.courses[i] != "") {
            cout << s.courses[i] << endl;
        }
    }
    cout << endl;
}

// Function to enroll a student in a course
void enroll(Student& s, string course) {
    for (int i = 0; i < 5; i++) {
        if (s.courses[i] == "") {
            s.courses[i] = course;
            cout << "Enrolled in " << course << endl;
            return;
        }
    }
    cout << "You have reached the maximum number of courses." << endl;
}

int main() {
    // Create a student and initialize their information
    Student student;
    student.name = "John Doe";
    student.age = 20;
    student.major = "Computer Science";

    // Display the student's information
    displayStudent(student);

    // Enroll the student in courses
    enroll(student, "Programming I");
    enroll(student, "Data Structures");
    enroll(student, "Web Development");
    enroll(student, "Database Systems");
    enroll(student, "Operating Systems");
    enroll(student, "Artificial Intelligence");

    // Display the student's information again to show the courses they enrolled in
    displayStudent(student);

    return 0;
}
