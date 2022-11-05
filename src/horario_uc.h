/**
 * @file horario_uc.h
 * @brief
 * horario_uc header file
 *
 */
#ifndef _HORARIO_UC_H_
#define _HORARIO_UC_H_

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
 *
 */
class Horario_UC{
    private :
        string UCCode;
        vector <pair<string, aula>> aulas;
    public:
        Horario_UC(string UCCode, vector<classes> ClassLine);
        void Print_Horario();

};

#endif