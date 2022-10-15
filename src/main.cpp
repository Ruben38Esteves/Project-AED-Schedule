#include <iostream>
#include "read.h"
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
                Read teste1;
                vector<classes_per_uc> cpu;
                cpu = teste1.read_classes_per_uc();
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

                break;
            }

            //student _classes
            case 3:{

                break;
            }
        }

    }
    return 0;
}
