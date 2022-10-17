#ifndef _hORARIO_ALUNO_H_
#define _HORARIO_ALUNO_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include "read.h"

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

        vector<aula> aulas_sorted_weekday;

    public:
        Horario_Aluno(string student,vector<classes> ClassLine);
        void Print_Horario();
        void Print_Horario_Sorted();
};

#endif