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
            case 1:{
                Read teste1;
                vector<classes_per_uc> cpu;
                cpu = teste1.read_classes_per_uc();
                set<string> UCs;
                set<string> Classes;
                for(auto a:cpu){
                    UCs.insert(a.UcCode);
                }
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
                        for(auto d:cpu){
                            if(d.ClassCode == escolhaClass){
                                cout << d.UcCode << '\n';
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }

    }
    return 0;
}
