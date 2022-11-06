/**
 * @file sort.cpp
 * @brief
 * functions used throughout the program assist in sorting
 *
 */
#include "sort.h"

/**
 * @brief
 * Facilitates usage of weekdays.
 * Complexity 1
 * @details Associates each weekday to a number.
 *
 * @param weekday
 * @return int
 */
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


/**
 * @brief Compares the start hour of class s1 with s2.
 * @param s1
 * @param s2
 * @return Whether or not s1 start hour is inferior to s2
 */
bool sortHorario_hora(pair<string, aula> s1, pair<string, aula> s2){
    return s1.second.StartHour < s2.second.StartHour;
}
/**
 * @brief Compares the weekday of class s1 with s2.
 * @param s1
 * @param s2
 * @return Whether or not s1 weekday is inferior to s2 after is turned into an int by weekday_to_int.
 */
bool sortHorario_weekday(pair<string, aula> s1, pair<string, aula> s2){
    return weekday_to_int(s1.second.Weekday) < weekday_to_int(s2.second.Weekday);
}


