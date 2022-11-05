#ifndef _READ_H_
#define _READ_H_

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
/**
 * @brief
 * This class helps arranging data from the csv file "classes_per_uc"
 */
struct classes_per_uc{
    string UcCode;
    string ClassCode;
};
/**
 * @brief
 * This class helps arranging data from the csv file "classes"
 */

struct classes{
    string ClassCode;
    string UcCode;
    string Weekday;
    string StartHour;
    string Duration;
    double EndHour;
    string Type;
};
/**
 * @brief
 * This class helps arranging data from the csv file "students_classes"
 */

struct students_classes{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};

/**
 * @brief
 * This class stores the separated values obtained from read.cpp of the csv file "classes"
 */
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
        //para apagar
        vector<pair<string,string>> read_students_classes_per_studentcode(string studentcode);
        string nome_por_code(string code);
        string code_por_nome(string nome);
        vector<pair<string,string>> read_students_classes_per_studentname(string studentname);
        vector<pair<string,string>> read_students_classes_per_UC(string UC);
        vector<pair<string,string>> read_students_classes_per_Class(string Class);
        vector<string> students_per_class_UC(string turma, string UC);


};

#endif