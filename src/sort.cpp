#include "sort.h"

int Sort::weekday_to_int(string weekday){
    if(weekday=="Monday"){
        return 1;
    }
    if(weekday=="Tuesday"){
        return 2;
    }
    if(weekday=="Wednsday"){
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



bool Sort::sortHorario_hora(aula s1, aula s2){
    return s1.StartHour < s2.StartHour;
}
bool Sort::sortHorario_weekday(aula a1, aula a2){
    return weekday_to_int(a1.Weekday) < weekday_to_int(a2.Weekday);
}