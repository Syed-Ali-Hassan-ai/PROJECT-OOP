#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Student
{
protected:
    string name;
    char gender;
    string address;
    string phone_number;
    string dob;
    string cnic;
    // string tym;
    string etym;
    vector<time_t> entry;
    vector<time_t> exit;

public:
    Student(){};
    Student(string n, char g, string a, string p, string d, string c)
    {
        name = n;
        gender = g;
        address = a;
        phone_number = p;
        dob = d;
        cnic = c;
        // tym = t;
    }

    void save_to_file(ofstream &file) const
    {
        file << name << endl;
        file << gender << endl;
        file << address << endl;
        file << phone_number << endl;
        file << dob << endl;
        file << cnic << endl;

        // Save the entry timestamps
        file << entry.size() << endl;
        for (const auto &timestamp : entry)
        {
            file << to_string(timestamp) << endl;
        }

        // Save the exit timestamps
        file << exit.size() << endl;
        for (const auto &timestamp : exit)
        {
            file << to_string(timestamp) << endl;
        }
    }

    friend class User;
    friend class Checker;
};

#endif
