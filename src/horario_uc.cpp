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
 * @details
 * runs a cycle through the vector with the classes
 * checking if they match with the user's UC choice and adds it to the set Classes. AAAAAAAAAAAAAAAAAAAA
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
