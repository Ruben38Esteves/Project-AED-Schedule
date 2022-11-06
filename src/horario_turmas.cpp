/**
 * @file horario_turmas
 * @brief Functions to generate and print classes' schedules.
 */
#include "horario_turmas.h"

/**
 * @brief Gathers information to generate classes' schedule.
 * Complexity n^2
 * @details
 * Compares chosen ClassCode with ClassCode of every class using a for loop and when it matches, adds the respective
 * UCCode to a set 'UCs'. Then using a double for loop, for every UCCode in 'UCs', searches every class for a matching
 * UCCode and ClassCode. In each match a variable temp of type aula is created, the values containing the information of
 * the lesson are stored in it, and it is added in a pair alongside the UCCode to the vector 'horario'.
 * @param ClassCode
 * @param ClassLines
 */
Horario_Turma::Horario_Turma(string ClassCode,vector<classes> ClassLines){
    set<string> UCs;
    vector<aula> Aulas_Uc;
    vector<pair<string,aula>> horario;
    //criar set de Ucs
    for(auto a: ClassLines){
        if(a.ClassCode==ClassCode){
            UCs.insert(a.UcCode);
        }
    }

    for(auto b: UCs){
        for(auto c: ClassLines){
            if(c.ClassCode==ClassCode && b==c.UcCode){
                //criar uma aula
                aula temp;
                temp.Weekday = c.Weekday;
                temp.StartHour = stod(c.StartHour);
                temp.Duration = stod(c.Duration);
                temp.EndHour = c.EndHour;
                temp.Type = c.Type;
                //adicionar aula a vetor de aulas
                horario.push_back(pair<string,aula>(b,temp));
            }
        }
    }
    //guardar valores na classe
    this->ClassCode=ClassCode;
    sort(horario.begin(), horario.end(), sortHorario_hora);
    sort(horario.begin(), horario.end(), sortHorario_weekday);
    this->aulas=horario;
};
/**
 * @brief Prints out the classes' schedule
 * Complexity n
 */
void Horario_Turma::Print_Horario(){
    cout << "O Horario da turma " << this->ClassCode << " é: " << '\n';
    string lastday;
    lastday = this->aulas[0].second.Weekday;
    cout<< lastday << ':' << "\n";
    for(auto a :aulas){
        if(a.second.Weekday!=lastday){
            lastday = a.second.Weekday;
            cout<< lastday << ':' << "\n";
        }
        cout << a.first << ' ' << a.second.Type << " class from " << a.second.StartHour << " until " << a.second.EndHour<<'\n';
    }
}