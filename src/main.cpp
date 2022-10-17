#include <iostream>
#include "read.h"
#include "horario_turmas.h"
#include "horario_aluno.h"
#include <set>

int main() {
    int escolha = 0;
    while(escolha != 4){
        //mostar opçoes
        cout << "Escolha o ficheiro:" << '\n';
        cout << "1 -> classes_per_uc" << '\n';
        cout << "2 -> classes" << '\n';
        cout << "3 -> student _classes" << '\n';
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
                        break;
                    }

                    //UC's da Turma
                    case 2:{
                        cout << "Escolha a turma" << '\n';
                        //mostar opçoes
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
                //criar set de Turmas (sem duplicados)
                for(auto b:clss){
                    Classes.insert(b.ClassCode);
                }
                //mostar opçoes
                cout << "1 -> Horario de uma turma" << '\n';
                cout << "2 -> xxxxxxxxxx" << '\n';
                cout << "3 -> xxxxxxxxxx" << '\n';
                //deixar utilizador escolher
                cin >> escolha2;
                switch(escolha2){
                    case 1:{
                        cout << "Escolha a turma" << '\n';
                        //mostar opçoes
                        set<string>::iterator it;
                        for(it = Classes.begin(); it != Classes.end(); it++){
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
                        if(escolhadia=="Todos"){
                            Horario_Turma escolhida(escolhaClass, clss);
                            escolhida.Print_Horario();
                        }else{
                            Horario_Turma escolhida(escolhaClass, clss);
                            escolhida.Print_Horario_Dia(escolhadia);
                        }
                        break;
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
                        
                        Horario_Aluno escolhido(StudentNameOrCode,clss);
                        
                        escolhido.Print_Horario_Sorted();
                        
                        break;
                    }
                }
                break;
            }
        }

    }
    return 0;
}
