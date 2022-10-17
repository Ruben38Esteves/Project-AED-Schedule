#include "horario_aluno.h"

Horario_Aluno::Horario_Aluno(string student,vector<classes> ClassLine){
    vector<pair<string,string>> turmas;
    vector<aula> Aulas_Uc;
    map<string,vector<aula>> horario;
    //verificar se é code ou name
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
        horario.insert(pair<string,vector<aula>>(a.first,Aulas_Uc));
        //limpar vetor de aulas
        Aulas_Uc.clear();
    }
    //guardar valores na classe
    this->aulas=horario;
};

void Horario_Aluno::Print_Horario(){
    cout << "O horario do aluno " << this->StudentName << '(' << this->StudentCode << ") é:" << '\n';
    map<string,vector<aula>>::iterator itr;
    for(itr = this->aulas.begin(); itr !=this->aulas.end();itr++ ){
        for(auto a: itr->second){
            cout << "Aula " << a.Type << " de " << itr->first << " no dia " <<  a.Weekday << " desde as " << a.StartHour << " ate " << a.EndHour << '\n';
        }
    }
}