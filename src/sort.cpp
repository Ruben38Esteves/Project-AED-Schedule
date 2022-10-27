#include "sort.h"

int weekday_to_int(string weekday){
    if(weekday=="Monday"){
        return 1;
    }
    if(weekday=="Tuesday"){
        return 2;
    }
    if(weekday=="Wednesday"){
        return 3;
    }
    if(weekday=="Thursday"){
        return 4;
    }
    if(weekday=="Friday"){
        return 5;
    }
    return 0;
};



bool sortHorario_hora(pair<string, aula> s1, pair<string, aula> s2){
    return s1.second.StartHour < s2.second.StartHour;
}
bool sortHorario_weekday(pair<string, aula> s1, pair<string, aula> s2){
    return weekday_to_int(s1.second.Weekday) < weekday_to_int(s2.second.Weekday);
}