#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct classes_per_uc{
    string UcCode;
    string ClassCode;
};

struct classes{
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    double EndHour;
    string Type;
};

struct students_classes{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};

struct aula{
    string Weekday;
    double StartHour;
    double Duration;
    double EndHour;
    string Type;
};

class Read{
    public:
        vector<classes_per_uc> read_classes_per_uc();
        vector<classes> read_classes();
        vector<students_classes> read_students_classes();
        vector<pair<string,string>> read_students_classes_per_studentcode(string studentcode);
        vector<pair<string,string>> read_students_classes_per_studentname(string studentname);
        vector<pair<string,string>> read_students_classes_per_UC(string UC);
        vector<pair<string,string>> read_students_classes_per_Class(string Class);
        
};

#endif