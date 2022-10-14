#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct classes_per_uc
{
    string UcCode;
    string ClassCode;
};

struct classes
{
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    string Type;
};

struct students_classes
{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};

struct schedule_struct
{
     
};

class Read
{
    public:
        vector<classes_per_uc> read_classes_per_uc();
        vector<classes> read_classes();
        vector<students_classes> read_students_classes();
        
};

#endif