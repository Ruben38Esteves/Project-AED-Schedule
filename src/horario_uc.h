#ifndef _HORARIO_UC_H_
#define _HORARIO_UC_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <ctype.h>
#include "read.h"


using namespace std;

class Horario_UC{
    private :
        string UCCode;
        map<string, vector<aula>> aulas;
    public:
        Horario_UC(string UCCode, vector<classes> ClassLine);
        void Print_Horario();

};

#endif