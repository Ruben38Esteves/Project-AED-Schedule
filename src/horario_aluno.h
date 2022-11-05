/**
 * @file horario_aluno.cpp
 * @brief
 * horario_aluno header file
 */
#ifndef _hORARIO_ALUNO_H_
#define _HORARIO_ALUNO_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include "read.h"
#include "sort.h"

using namespace std;

class Horario_Aluno{
    private:
    //identificar aluno
        string StudentCode;
        string StudentName;
    //turmas/Ucs em que o aluno esta inscrito
        vector<pair<string,string>> turmas;
    //aulas em que o aluno esta inscrito
        vector<pair<string,vector<aula>>> aulas;
        vector<pair<pair<string,string>,aula>> horario_novo;

    public:
        Horario_Aluno(string student,vector<classes> ClassLine,vector<students_classes> StuClasses);
        void Print_Horario();
};

#endif