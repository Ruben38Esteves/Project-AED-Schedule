#ifndef _SORT_H_
#define _SORT_H_
#include <algorithm>
#include <string>
#include "read.h"

using namespace std;

int weekday_to_int(string weekday);
bool sortHorario_hora(pair<string, aula> s1, pair<string, aula> s2);
bool sortHorario_weekday(pair<string, aula> s1, pair<string, aula> s2);






#endif
