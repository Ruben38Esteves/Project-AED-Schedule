#include <iostream>
#include "read.h"
#include "horario_turmas.h"
#include "horario_aluno.h"
#include "horario_uc.h"
#include <set>
#include <vector>

int main() {
    Read ler;
    vector<classes_per_uc> CPU = ler.read_classes_per_uc();
    vector<classes> Classes = ler.read_classes();
    vector<students_classes> StuClasses = ler.read_students_classes();
    set<string> SetClasses;
    for(auto a: CPU){
        SetClasses.insert(a.ClassCode);
    }
    set<string> SetUcs;
    for(auto a: CPU){
        SetUcs.insert(a.UcCode);
    }
    int mainmenu = 0;
    while(mainmenu != 5){
        //mostar opçoes
        cout << "1 -> Show Schedules" << '\n';
        cout << "2 -> Show Students" << '\n';
        cout << "3 -> Show Classes" << '\n';
        cout << "4 -> Show UC's" << '\n';
        cin >> mainmenu;
        switch(mainmenu){
            case 1:{
                cout << "1 -> Student Schedule" << '\n';
                cout << "2 -> Class Schedule" << '\n';
                cout << "3 -> UC CSchedule" << '\n';
                int menu1 = 0;
                cin >> menu1;
                switch (menu1){
                    case 1:{
                        cout << "Write the students name or number" << '\n';
                        string nameorcode;
                        cin >> nameorcode;
                        Horario_Aluno ChosenStudent(nameorcode,Classes,StuClasses);
                        ChosenStudent.Print_Horario();
                        break;
                    }
                    case 2:{
                        cout << "Which Class?" << '\n';
                        set<string>::iterator it;
                        for(it = SetClasses.begin(); it != SetClasses.end(); it++){
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        string chosenclass;
                        cin >> chosenclass;
                        Horario_Turma ChosenClass(chosenclass, Classes);
                        ChosenClass.Print_Horario();
                        break;
                    }
                    case 3:{
                        cout << "Which UC?" << '\n';
                        set<string>::iterator it;
                        for(it = SetUcs.begin(); it != SetUcs.end(); it++){
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        string chosenuc;
                        cin >> chosenuc;
                        Horario_UC ChosenUC(chosenuc, Classes);
                        ChosenUC.Print_Horario();
                        break;
                    }
                }
                break;
            }
            case 2:{
                cout << "1 -> Show all students" << '\n';
                cout << "2 -> Show students by class" << '\n';
                cout << "3 -> Show students by UC" << '\n';
                cout << "4 -> Remove student from UC" << '\n';
                cout << "5 -> remove Student from class" << '\n';
                int menu2;
                cin >> menu2;
                switch(menu2){
                    case 1:{
                        set<pair<string,string>> StudentsList;
                        for(auto a : StuClasses){
                            pair<string,string> temp;
                            temp = make_pair(a.StudentName,a.StudentCode);
                            StudentsList.insert(temp);
                        }
                        set<pair<string,string>>::iterator it;
                        for(it=StudentsList.begin();it!=StudentsList.end();it++){
                            pair<string,string> temp2 = *it;
                            cout << temp2.first << '(' << temp2.second << ")" <<"; " ;
                        }
                        cout<<'\n'<<'\n';
                        break;
                    }
                    case 2:{
                        cout<< "Choose class:" << '\n';
                        string turma;
                        cin>> turma;

                        for(auto a: StuClasses){
                            if(a.ClassCode==turma){
                                cout<< a.StudentName<< "("<< a.StudentCode<< "); ";
                            }
                        }
                        cout<< '\n'<< '\n';
                        break;
                    }
                    case 3:{
                        cout<< "Choose UC:"<<'\n';
                        string uc;
                        cin>> uc;

                        for(auto a: StuClasses){
                            if(a.UcCode==uc){
                                cout<<a.StudentName<<"("<<a.StudentCode<<"); ";
                            }
                        }

                        cout<< '\n'<< '\n';
                        break;
                    }
                    case 4:{
                        cout << "Choose the Student" << '\n';
                        string student;
                        cin >> student;
                        if(isdigit(student[0])){
                            for(auto a: StuClasses){
                                if(student==a.StudentCode){
                                    cout << a.UcCode << '\n';
                                }
                            }
                        }else{
                            for(auto a: StuClasses){
                                if(student==a.StudentName){
                                    cout << a.UcCode << '\n';
                                }
                            }
                        }
                        string removeUC;
                        cin >> removeUC;
                        if(isdigit(student[0])){
                            auto it = StuClasses.begin();
                            while(it != StuClasses.end()){
                                if(it->StudentCode==student && it->UcCode==removeUC){
                                    it = StuClasses.erase(it);
                                }else{
                                    ++it;
                                }
                            }
                        }else{
                            auto it = StuClasses.begin();
                            while(it != StuClasses.end()){
                                if(it->StudentName==student && it->UcCode==removeUC){
                                    it = StuClasses.erase(it);
                                }else{
                                    ++it;
                                }
                            }
                        }
                        break;
                    }
                } 
                break;
            }
            case 3:{
                cout<< "1-> Show all classes"<< '\n';
                cout<< "2-> Show a Student's class"<< '\n';
                cout<< "3-> Show classes by UC"<< '\n';
                int menu3;
                cin>> menu3;
                switch(menu3){
                    case 1:{
                        for(auto a:SetClasses){
                            cout<< a <<"; ";
                        }
                        cout<< '\n'<< '\n';
                    break;
                    }
                    case 2:{
                        cout<< "Write Student's name or code:"<< '\n';
                        string name_or_code;
                        cin>> name_or_code;
                        if(isdigit(name_or_code[0])==1){
                            for(auto a:StuClasses){
                                if(name_or_code==a.StudentCode){
                                    cout<< a.UcCode<< " with "<< a.ClassCode<< '\n';
                                }
                            }
                        }else{
                            for(auto a:StuClasses){
                                if(name_or_code==a.StudentName){
                                    cout<< a.UcCode<< " with "<< a.ClassCode<< '\n';
                                }
                            }
                        }
                        cout<< '\n';
                    break;
                    }
                    case 3:{
                        cout<< "Choose UC:"<< "\n";
                        string uc;
                        cin>> uc;
                        for(auto a: CPU){
                            if(a.UcCode==uc){
                                cout<< a.ClassCode <<"; " ;
                            }
                        }
                        cout << '\n'<< '\n';
                    }
                    break;
                }
                break;
            }
            case 4:{
                cout<< "1-> Show all UC's"<< '\n';
                cout<< "2-> Show UC's by class"<< '\n';
                cout<< "3-> Show Student's UC's"<< '\n';
                int menu4;
                cin>> menu4;
                switch(menu4){
                    case 1:{
                        for(auto a:SetUcs){
                            cout<< a<< "; ";
                        }
                        cout<<'\n'<<'\n';
                        break;
                    }
                    case 2:{
                        cout<< "Choose Class:"<< '\n';
                        string turma;
                        cin>> turma;
                        for(auto a: CPU){
                            if(a.ClassCode==turma){
                                cout<< a.UcCode <<"; " ;
                            }
                        }
                        cout << '\n'<<'\n';
                        break;
                    }
                    case 3:{
                        cout<<"Write Student's name or code:"<< '\n';
                        string name_or_code;
                        cin>> name_or_code;
                        if(isdigit(name_or_code[0])==1){
                            for(auto a:StuClasses){
                                if(a.StudentCode==name_or_code){
                                    cout<<a.UcCode<<'\n';
                                }
                            }
                        }else{
                            for(auto a:StuClasses){
                                if(a.StudentName==name_or_code){
                                    cout<<a.UcCode<<'\n';
                                }
                            }
                        }
                        cout<<'\n';
                        break;
                    }
                    break;
                }
            break;
            }
        }
    }
/*
    int escolha = 0;
    //funçoes de ler
    //xxxxxxxxxxx
    while(escolha != 4){
        //mostar opçoes
        cout << "Escolha o ficheiro:" << '\n';
        cout << "1 -> classes_per_uc" << '\n';
        cout << "2 -> classes" << '\n';
        cout << "3 -> student_classes" << '\n';
        cout << "4 -> Sair" << '\n';
        //deixar utilizador escolher
        cin >> escolha;
        switch(escolha){
            //classes_per_uc
            case 1:{
                Read case1;
                vector<classes_per_uc> cpu;
                cpu = case1.read_classes_per_uc();
                set<string> UCs;
                set<string> Classes;
                //criar set de UC's (sem duplicados)
                for(auto a:cpu){
                    UCs.insert(a.UcCode);
                }
                //criar set de Turmas (sem duplicados)
                for(auto b:cpu){
                    Classes.insert(b.ClassCode);
                }
                int escolha1;
                //mostar opçoes
                cout << "1 -> Turmas na UC" << '\n';
                cout << "2 -> UC's da Turma" << '\n';
                cout << "3 -> Tudo" << '\n';
                //deixar utilizador escolher
                cin >> escolha1;
                switch(escolha1){

                    //Turmas na UC
                    case 1:{
                        cout << "Escolha a UC" << '\n';
                        //mostar opçoes
                        set<string>::iterator it;
                        for(it = UCs.begin(); it != UCs.end(); it++){
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        //deixar utilizador escolher
                        string escolhaUC;
                        cin >> escolhaUC;
                        //mostrar resultados
                        cout << "As turmas da UC " << escolhaUC << " sao:" << '\n';
                        for(auto d:cpu){
                            if(d.UcCode == escolhaUC){
                                cout << d.ClassCode << '\n';
                            }
                        }

                        //dar a possibilidade de ver alunos da turma
                        cout << "1-> ver alunos por turma" << '\n';
                        int turma;
                        cin>> turma;
                        switch(turma){
                            case 1:{
                                //deixar utilizador escolher turma
                                cout<< "Escolha a turma:" << '\n';
                                string escolhaturma;
                                cin>>escolhaturma;

                                //alunos da turma

                                Read at;
                                vector<string> alunos;
                                alunos = at.students_per_class_UC(escolhaturma, escolhaUC);
                                cout << "Turma " << escolhaturma << " na UC" << escolhaUC << ':' << '\n';

                                //ordenar por ordem alfabética
                                sort(alunos.begin(),alunos.end());
                                for (string a: alunos) {
                                    cout << a << '\n';
                                }
                                break;
                            }
                        }
                        break;
                    }

                    //UC's da Turma
                    case 2:{
                        cout << "Escolha a turma" << '\n';
                        //mostrar opçoes
                        set<string>::iterator it;
                        for(it = Classes.begin(); it != Classes.end(); it++){
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        //deixar utilizador escolher
                        string escolhaClass;
                        cin >> escolhaClass;
                        //mostrar resultados
                        cout << "As UC's da turma " << escolhaClass << " sao:" << '\n';
                        for(auto e:cpu){
                            if(e.ClassCode == escolhaClass){
                                cout << e.UcCode << '\n';
                            }
                        }
                        break;

                    }

                    //Tudo
                    case 3:{
                        for(auto f: cpu){
                            cout << "UC:" << f.UcCode << " / Turma:" << f.ClassCode << '\n';
                        }
                        break;
                    }
                }
                break;
            }

            //classes
            case 2:{
                Read case2;
                vector<classes> clss;
                clss = case2.read_classes();
                int escolha2;
                set<string> Classes;
                set<string> UCs;
                //criar set de Turmas (sem duplicados)
                for(auto b:clss){
                    UCs.insert(b.UcCode);
                    Classes.insert(b.ClassCode);
                }


                //mostar opçoes
                cout << "1 -> Horário de uma turma" << '\n';
                cout << "2 -> Horário de uma UC" << '\n';
                cout << "3 -> xxxxxxxxxx" << '\n';
                //deixar utilizador escolher
                cin >> escolha2;
                switch(escolha2) {
                    case 1: {
                        cout << "Escolha a turma:" << '\n';
                        //mostar opçoes
                        set<string>::iterator it;
                        for (it = Classes.begin(); it != Classes.end(); it++) {
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        //deixar utilizador escolher
                        string escolhaClass;
                        cin >> escolhaClass;
                        cout << "Escolha o dia:" << '\n';
                        cout << "Monday" << '\n';
                        cout << "Tuesday" << '\n';
                        cout << "Wednsday" << '\n';
                        cout << "Thursday" << '\n';
                        cout << "Friday" << '\n';
                        cout << "Todos" << '\n';
                        //mostrar resultados
                        string escolhadia;
                        cin >> escolhadia;
                        if (escolhadia == "Todos") {
                            Horario_Turma escolhida(escolhaClass, clss);
                            escolhida.Print_Horario();
                        } else {
                            Horario_Turma escolhida(escolhaClass, clss);
                            escolhida.Print_Horario_Dia(escolhadia);
                        }
                        break;
                    }
                    case 2:{
                        cout << "Escolha a UC: \n";
                        set<string>::iterator it;
                        for (it = UCs.begin(); it!= UCs.end(); it++){
                            cout << *it << " / ";
                        }
                        cout << "\n";
                        string EscolhaUC;
                        cin >> EscolhaUC;
                        Horario_UC escolhido(EscolhaUC, clss);
                        escolhido.Print_Horario();
                    }
                }
                break;
            }


            //student _classes
            case 3:{
                Read case3;
                vector<classes> clss;
                clss = case3.read_classes();
                int escolha3;
                //mostar opçoes
                cout << "1 -> Horario de um aluno" << '\n';
                cout << "2 -> xxxxxxxxxx" << '\n';
                cout << "3 -> xxxxxxxxxx" << '\n';
                cin >> escolha3;
                switch(escolha3){
                    case 1:{
                        string StudentNameOrCode;
                        cout << "Escolha o aluno" << '\n';
                        cin >> StudentNameOrCode;
                        //print ao horario
                        Horario_Aluno escolhido(StudentNameOrCode,clss);
                        escolhido.Print_Horario();
                        break;
                    }
                }
                break;
            }
        }

    }
    */
    return 0;
}