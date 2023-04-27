#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_COURSES = 5;

struct Student {
    string name;
    int id;
    int course;
};

struct Teacher {
    string name;
    int course;
};

Student students[MAX_STUDENTS];
Teacher teachers[MAX_COURSES];

int numStudents = 0;
int numTeachers = 0;

void addStudent() {
    if (numStudents == MAX_STUDENTS) {
        cout << "Cannot add more students, maximum reached!" << endl;
        return;
    }

    cout << "Enter name of student: ";
    cin >> students[numStudents].name;
    cout << "Enter ID of student: ";
    cin >> students[numStudents].id;
    cout << "Enter course of student (1-5): ";
    cin >> students[numStudents].course;
    numStudents++;
}

void addTeacher() {
    if (numTeachers == MAX_COURSES) {
        cout << "Cannot add more teachers, maximum reached!" << endl;
        return;
    }

    cout << "Enter name of teacher: ";
    cin >> teachers[numTeachers].name;
    cout << "Enter course of teacher (1-5): ";
    cin >> teachers[numTeachers].course;
    numTeachers++;
}

void sortStudentsByCourse() {
    for (int i = 0; i < numStudents; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].course > students[j].course) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void assignStudentsToTeachers() {
    sortStudentsByCourse();

    int studentIndex = 0;
    int teacherIndex = 0;

    while (studentIndex < numStudents && teacherIndex < numTeachers) {
        if (students[studentIndex].course == teachers[teacherIndex].course) {
            cout << students[studentIndex].name << " (ID: " << students[studentIndex].id << ") assigned to " << teachers[teacherIndex].name << endl;
            studentIndex++;
        } else if (students[studentIndex].course < teachers[teacherIndex].course) {
            studentIndex++;
        } else {
            teacherIndex++;
        }
    }
}

void printStudents() {
    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << students[i].name << " (ID: " << students[i].id << ", Course: " << students[i].course << ")" << endl;
    }
}

void printTeachers() {
    cout << "List of teachers:" << endl;
    for (int i = 0; i < numTeachers; i++) {
        cout << teachers[i].name << " (Course: " << teachers[i].course << ")" << endl;
    }
}

int main() {
    int choice;
    
    do {
        cout << "Menu:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Add teacher" << endl;
        cout << "3. Assign students to teachers" << endl;
        cout << "4. Print students" << endl;
        cout << "5. Print teachers" << endl;
        cout << "6. Quit" << endl;

        cout << "Enter your choice"<<endl;
        cin>>choice;
    }while(choice!=6);
    return 0;
}
void printTeacherStudents() {
    cout << "Enter teacher name: ";
    string teacherName;
    cin >> teacherName;

    int teacherIndex = -1;
    for (int i = 0; i < numTeachers; i++) {
        if (teachers[i].name == teacherName) {
            teacherIndex = i;
            break;
        }
    }

    if (teacherIndex == -1) {
        cout << "Teacher not found!" << endl;
        return;
    }

    cout << "List of students assigned to " << teacherName << ":" << endl;
    for (int i = 0; i < teachers[teacherIndex].numStudents; i++) {
        int studentId = teachers[teacherIndex].studentIds[i];
        for (int j = 0; j < numStudents; j++) {
            if (students[j].id == studentId) {
                cout << students[j].name << " (ID: " << students[j].id << ", Course: " << students[j].course << ")" << endl;
                break;
            }
        }
    }
}

