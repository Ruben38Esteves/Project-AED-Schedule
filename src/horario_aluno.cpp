#include "horario_aluno.h"
#include <algorithm>


bool sortHorario(aula s1, aula s2){
    return s1.StartHour < s2.StartHour;
}


Horario_Aluno::Horario_Aluno(string student,vector<classes> ClassLine){
    vector<pair<string,string>> turmas;
    vector<aula> Aulas_Uc;
    vector<pair<string,vector<aula>>> horario;
    vector<aula> aulas_sorted_weekday;
    //verificar set é code ou name
    if(isdigit(student[0])){
        string Code = student;
        //atribuir code
        this->StudentCode = Code;
        //atribuir turmas
        Read ler;
        turmas = ler.read_students_classes_per_studentcode(Code);
        this->turmas = turmas;
        //atribuir name
        this->StudentName = ler.nome_por_code(Code);
    }else{
        string Name = student;
        //atribuir name
        this->StudentName= Name;
        //atribuir turmas
        Read ler;
        turmas = ler.read_students_classes_per_studentname(Name);
        this->turmas = turmas;
        //atribuir code
        this->StudentCode = ler.code_por_nome(Name);
    }
    for(auto a:turmas){
        for(auto b:ClassLine){
            if(a.first == b.UcCode && a.second == b.ClassCode){
                //criar uma aula
                aula temp;
                temp.Weekday = b.Weekday;
                temp.StartHour = stod(b.StartHour);
                temp.Duration = stod(b.Duration);
                temp.EndHour = b.EndHour;
                temp.Type = b.Type;
                //adicionar aula a vetor de aulas
                Aulas_Uc.push_back(temp);
            }
        }
        //adicionar o par UC/vetor de aulas ao horario
        horario.push_back(pair<string,vector<aula>>(a.first,Aulas_Uc));
        //limpar vetor de aulas
        Aulas_Uc.clear();
    }
    //ordenar horario
    for (int i = 0; i < horario.size(); i++){
        sort(horario[i].second.begin(), horario[i].second.end(), sortHorario);
    }

    //guardar valores na classe
    this->aulas=horario;
    //criar vetor so de aulas
    for (int i = 0; i < horario.size(); i++){
        for(int j = 0;j<horario[i].second.size();j++){
            aulas_sorted_weekday.push_back(horario[i].second[j]);
        }
    }
    //ordenar
    for(int k=0; k<aulas_sorted_weekday.size();k++){
        sort(aulas_sorted_weekday.begin(), aulas_sorted_weekday.end(), sortHorario);
    }

    this->aulas_sorted_weekday=aulas_sorted_weekday;
    
};

void Horario_Aluno::Print_Horario(){
    cout << "O horario do aluno " << this->StudentName << '(' << this->StudentCode << ") é:" << '\n';
    
    for(int i = 0; i < aulas.size(); i++){
        for(auto a: aulas[i].second){
            cout << "Aula " << a.Type << " de " << aulas[i].first << " no dia " <<  a.Weekday << " desde as " << a.StartHour << " ate " << a.EndHour << '\n';
        }
    }
    
   
    for(auto a : aulas_sorted_weekday){
        cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
    }


    
};

void Horario_Aluno::Print_Horario_Sorted(){
    cout << "O horario do aluno " << this->StudentName << '(' << this->StudentCode << ") é:" << '\n';
    for(auto a: aulas_sorted_weekday){
        if(a.Weekday=="Monday"){
            cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
        }
    }
    for(auto a: aulas_sorted_weekday){
        if(a.Weekday=="Tuesday"){
            cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
        }
    }
    for(auto a: aulas_sorted_weekday){
        if(a.Weekday=="Wednesday"){
            cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
        }
    }
    for(auto a: aulas_sorted_weekday){
        if(a.Weekday=="Thursday"){
            cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
        }
    }
    for(auto a: aulas_sorted_weekday){
        if(a.Weekday=="Friday"){
            cout << a.Type << " / " << a.Weekday << " / " << a.StartHour << " / " << a.EndHour << '\n';
        }
    }
}