#include "horario_turmas.h"

Horario_Turma::Horario_Turma(string ClassCode,vector<classes> ClassLines){
    set<string> UCs;
    vector<aula> Aulas_Uc;
    map<string,vector<aula>> horario;
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
                Aulas_Uc.push_back(temp);
            }
        }
        //adicionar o par UC/vetor de aulas ao horario
        horario.insert(pair<string,vector<aula>>(b,Aulas_Uc)); 
        //limpar vetor de aulas
        Aulas_Uc.clear();
    }
    //guardar valores na classe
    this->ClassCode=ClassCode;
    this->aulas=horario;
};

void Horario_Turma::Print_Horario(){
    cout << "O Horario da turma " << this->ClassCode << " é: " << '\n';
    map<string,vector<aula>>::iterator itr;
    for(itr = this->aulas.begin(); itr !=this->aulas.end();itr++ ){
        for(auto a: itr->second){
            cout << "Aula " << a.Type << " de " << itr->first << " no dia " <<  a.Weekday << " desde as " << a.StartHour << " ate " << a.EndHour << '\n';
        }
    }
}

void Horario_Turma::Print_Horario_Dia(string weekday){
    cout << "O Horario da turma " << this->ClassCode << " no dia " << weekday << " é: " << '\n';
    map<string,vector<aula>>::iterator itr;
    for(itr = this->aulas.begin(); itr !=this->aulas.end();itr++ ){
        for(auto a: itr->second){
            if(a.Weekday == weekday){
                cout << "Aula " << a.Type << " de " << itr->first << " desde as " << a.StartHour << " ate " << a.EndHour << '\n';
            }
        }
    }
}