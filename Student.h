#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>

 using namespace std; 
    class Student {
    protected:
        string name;
        char gender;
        string address;
        string phone_number;
        string dob;
        string cnic;
        string tym;
        string etym;

    public:
        Student() {};
        Student(string n, char g, string a, string p, string d, string c, string t)
        {
            name = n;
            gender = g;
            address = a;
            phone_number = p;
            dob = d;
            cnic = c;
            tym = t;
        }

        void save_to_file(ofstream& file) const {
            file << name << endl;
            file << gender << endl;
            file << address << endl;
            file << phone_number << endl;
            file << dob << endl;
            file << cnic << endl;
            file << tym << endl;
            file << etym << endl;
        }

        friend class User;
        friend class Checker;
    };


#endif
