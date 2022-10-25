#include "horario_uc.h"
#include <algorithm>

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
        cout << "Aula " << a.second.Type << " da turma " << a.first << " no dia " <<  a.second.Weekday << " desde as " << a.second.StartHour << " ate " << a.second.EndHour << '\n';
    }

}
