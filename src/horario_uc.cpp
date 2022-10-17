#include "horario_uc.h"
#include <algorithm>

Horario_UC::Horario_UC(string UCCode, vector<classes> ClassLines){
    set<string> Classes;
    vector<aula> aula_class;
    map<string, vector<aula>> horario;

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
                aula_class.push_back(temp);
            }
        }
        horario.insert(pair<string, vector<aula>>(a, aula_class));
        aula_class.clear();
    }
    
    this->UCCode = UCCode;
    this->aulas=horario;
};

void Horario_UC::Print_Horario(){
    cout << "O Horario da UC " << this->UCCode << " é: " << '\n';
    map<string,vector<aula>>::iterator itr;
    for(itr = this->aulas.begin(); itr !=this->aulas.end();itr++ ){
        for(auto a: itr->second){
            cout << "Aula " << a.Type << " da turma " << itr->first << " no dia " <<  a.Weekday << " desde as " << a.StartHour << " ate " << a.EndHour << '\n';
        }
    }
}
