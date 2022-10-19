#include "horario_aluno.h"
#include <algorithm>
//transformar dia da semana em int para se conseguir ordenar
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
}
//ordenar por hora de inicio
bool sortaula_hora(pair<pair<string,string>,aula> a, pair<pair<string,string>,aula> b){
    return a.second.StartHour < b.second.StartHour;
}
//ordenar por dia da semana
bool sortaula_dia(pair<pair<string,string>,aula> a, pair<pair<string,string>,aula> b){
    return weekday_to_int(a.second.Weekday) < weekday_to_int(b.second.Weekday);
}

Horario_Aluno::Horario_Aluno(string student,vector<classes> ClassLine){
    vector<pair<string,string>> turmas;
    vector<pair<pair<string,string>,aula>> horario_novo;
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
    cout << "O horario do aluno " << this->StudentName << '(' << this->StudentCode << ") é:" << '\n';
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
        cout << "    " << a.first.first << " com a turma " << a.first.second<< " do tipo " << a.second.Type<< " desde as " << a.second.StartHour<< " ate as " << a.second.EndHour<< " / " <<'\n';
    }
};
