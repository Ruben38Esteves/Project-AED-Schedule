/**
 * @file horario_uc.cpp
 * @brief
 * functions to display a unit's schedules
 *
 */

#include "horario_uc.h"
#include <algorithm>

/**
 * @brief
 * generates the curricular unit's schedule
 * Complexity n^2
 * @details
 * runs a cycle through the vector with the classes
 * checking if the UCCode match with the user's UC choice and adds the respective ClassCode to the set Classes.
 * Then every class 'b' existing (ClassLines) is searched for a match in UCCode and ClassCode of
 * every class 'a' in Classes using a double for loop. If both match, a variable temp of type aula is created and in it
 * is stored all the information of class 'b'. Then it is added to the set horario the matching ClassCode 'a' and the variable
 * temp.
 *
 * @param UCCode
 * @param ClassLines
 */
Horario_UC::Horario_UC(string UCCode, vector<classes> ClassLines){
    set<string> Classes;
    vector <pair<string, aula>> horario;

                for(auto a: ClassLines){
                    if (a.UcCode == UCCode){
                        Classes.insert(a.ClassCode);
                    }
                }
                for (auto a: Classes){
                    for(auto b: ClassLines){
                        if (UCCode==b.UcCode && a==b.ClassCode){
                            aula temp;
                            temp.Weekday = b.Weekday;
                temp.StartHour = stod(b.StartHour);
                temp.Duration = stod(b.Duration);
                temp.EndHour = b.EndHour;
                temp.Type = b.Type;
                horario.push_back(pair<string, aula>(a, temp));
            }
        }
    }
    sort(horario.begin(), horario.end(), sortHorario_hora);
    sort(horario.begin(), horario.end(), sortHorario_weekday);
    
    this->UCCode = UCCode;
    this->aulas=horario;
};
/**
 * @brief
 * prints the curricular unit's schedule.
 */
void Horario_UC::Print_Horario(){
    cout << "O Horario da UC " << this->UCCode << " é: " << '\n';
    string lastday;
    lastday = this->aulas[0].second.Weekday;
    cout<< lastday << ':' << "\n";
    for(auto a: aulas) {
        if (a.second.Weekday != lastday) {
            lastday = a.second.Weekday;
            cout << lastday << ':' << "\n";
        }
        cout << a.second.Type<< " class" << " from class " << a.first << " since " << a.second.StartHour << " until " << a.second.EndHour << '\n';
    }

}
