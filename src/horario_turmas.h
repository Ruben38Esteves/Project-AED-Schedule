#ifndef _hORARIO_TURMAS_H_
#define _HORARIO_TURMAS_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <ctype.h>
#include "read.h"


using namespace std;

class Horario_Turma{
    private:
    //identificar turma
        string ClassCode;
    //aulas da turma <UC / Aulas>
        map<string,vector<aula>> aulas;

    public:
        Horario_Turma(string ClassCode,vector<classes> ClassLine);
        void Print_Horario();
        void Print_Horario_Dia(string weekday);
};

#endif