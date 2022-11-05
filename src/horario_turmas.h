/**
 * @file horario_turmas.h
 * @brief horario_turmas header file
 *
 */
#ifndef _hORARIO_TURMAS_H_
#define _HORARIO_TURMAS_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <ctype.h>
#include "read.h"
#include "sort.h"

using namespace std;

/**
 * @brief
 */
class Horario_Turma{
    private:
    //identificar turma
        string ClassCode;
    //aulas da turma <UC / Aulas>
        vector<pair<string,aula>> aulas;

    public:
        Horario_Turma(string ClassCode,vector<classes> ClassLine);
        void Print_Horario();
        void Print_Horario_Dia(string weekday);
};

#endif