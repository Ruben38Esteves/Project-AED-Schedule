/**
 * @file horario_aluno.cpp
 * @brief
 * Functions to display student's schedules
 *
 */
#include "horario_aluno.h"
#include <algorithm>

//ordenar por hora de inicio
/**
 * @brief
 * Sorts classes by start hour
 * @details
 *
 *
 * @param a
 * @param b
 * @return
 */
bool sortaula_hora(pair<pair<string,string>,aula> a, pair<pair<string,string>,aula> b){
    return a.second.StartHour < b.second.StartHour;
}
/**
 * @brief
 * Sorts Classes by Weekday
 * @details
 *
 *
 * @param a
 * @param b
 * @return
 */
bool sortaula_dia(pair<pair<string,string>,aula> a, pair<pair<string,string>,aula> b){
    return weekday_to_int(a.second.Weekday) < weekday_to_int(b.second.Weekday);
}

Horario_Aluno::Horario_Aluno(string student,vector<classes> ClassLine,vector<students_classes> StuClasses){
    vector<pair<string,string>> turmas;
    vector<pair<pair<string,string>,aula>> horario_novo;
    vector<aula> aulas_sorted_weekday;
    //verificar set é code ou name

    if(isdigit(student[0])){
        this->StudentCode = student;
        for(auto a: StuClasses){
            if(a.StudentCode==student){
                turmas.push_back(make_pair(a.UcCode,a.ClassCode));
            }
            if(a.StudentCode==student){
                this->StudentName=a.StudentName;
            }
        }
        this->turmas = turmas;
    }else{
        this->StudentCode = student;
        for(auto a: StuClasses){
            if(a.StudentName==student){
                turmas.push_back(make_pair(a.UcCode,a.ClassCode));
            }
            if(a.StudentName==student){
                this->StudentCode=a.StudentCode;
            }
        }
        this->turmas = turmas;
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
                //adicionar aula a vetor de (UC/Turma)/aula
                horario_novo.push_back(pair<pair<string,string>,aula>(a,temp));
            }
        }
    }
    //ordenar por hora
    for(auto a:horario_novo){
        sort(horario_novo.begin(),horario_novo.end(),sortaula_hora);
    }
    //ordenar por dias
    for(auto a:horario_novo){
        sort(horario_novo.begin(),horario_novo.end(),sortaula_dia);
    }
    //guardar
    this->horario_novo=horario_novo;
};

void Horario_Aluno::Print_Horario(){
    cout << this->StudentName << "'s "<< '(' << this->StudentCode << ") schedule is:" << '\n';
    //inicializar o ultimo dia
    string lastday;
    lastday = this->horario_novo[0].second.Weekday;
    cout << lastday << ':' << '\n';
    for(auto a: horario_novo){
        //se se mudar de dia, indicar isso
        if(a.second.Weekday != lastday){
                    cout << a.second.Weekday << ':' << '\n';
                    lastday = a.second.Weekday;
        }
        //print ao horario
        cout << "    " << a.first.first << ", with class " << a.first.second<< ", which type is " << a.second.Type<< " since " << a.second.StartHour<< " until " << a.second.EndHour<< " ; " <<'\n';
    }
};
