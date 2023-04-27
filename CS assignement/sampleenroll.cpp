#include <iostream>
#include <string>

using namespace std;

// Define a structure to store the information about a course
struct Course {
    int courseID;
    string courseName;
    int courseCredit;
};

// Define a structure to store the information about a student
struct Student {
    int studentID;
    string studentName;
    Course enrolledCourses[10]; // assume a student can enroll up to 10 courses
    int numEnrolledCourses; // track the number of courses a student has enrolled
};

// Function to add a new course to the system
void addCourse(Course courses[], int& numCourses) {
    // Prompt the admin to enter the course information
    cout << "Enter the course ID: ";
    cin >> courses[numCourses].courseID;
    cin.ignore(); // ignore the newline character left in the input stream
    cout << "Enter the course name: ";
    getline(cin, courses[numCourses].courseName);
    cout << "Enter the course credit: ";
    cin >> courses[numCourses].courseCredit;
    
    // Increment the numCourses variable
    numCourses++;
    
    cout << "Course added successfully!\n";
}

// Function to display all the courses in the system
void displayCourses(Course courses[], int numCourses) {
    // Loop through the courses array and display each course's information
    for (int i = 0; i < numCourses; i++) {
        cout << "Course ID: " << courses[i].courseID << endl;
        cout << "Course Name: " << courses[i].courseName << endl;
        cout << "Course Credit: " << courses[i].courseCredit << endl << endl;
    }
}

// Function to let a student enroll in a course
void enrollCourse(Student& student, Course courses[], int numCourses) {
    // Prompt the student to enter the course ID he/she wants to enroll in
    int courseID;
    cout << "Enter the course ID you want to enroll in: ";
    cin >> courseID;
    
    // Check if the course ID is valid (i.e., exists in the courses array)
    bool found = false;
    for (int i = 0; i < numCourses; i++) {
        if (courses[i].courseID == courseID) {
            found = true;
            student.enrolledCourses[student.numEnrolledCourses] = courses[i];
            student.numEnrolledCourses++;
            cout << "Enrollment successful!\n";
            break;
        }
    }
    if (!found) {
        cout << "Invalid course ID!\n";
    }
}

// Function to display a student's enrolled courses
void displayEnrolledCourses(Student student) {
    cout << "Enrolled courses for student " << student.studentID << ": \n";
    for (int i = 0; i < student.numEnrolledCourses; i++) {
        cout << "Course ID: " << student.enrolledCourses[i].courseID << endl;
        cout << "Course Name: " << student.enrolledCourses[i].courseName << endl;
        cout << "Course Credit: " << student.enrolledCourses[i].courseCredit << endl << endl;
    }
}

int main() {
    Course courses[100];
    int numCourses = 0;
    Student student;
    
    // Add some courses to the system
    addCourse(courses, numCourses);
    addCourse(courses, numCourses);
    addCourse(courses, numCourses);
    
    // Let the student enroll in a course
    student.studentID = 1;
    student
