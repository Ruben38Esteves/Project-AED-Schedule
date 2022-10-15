#include <iostream>
#include "read.h"
#include <set>

int main() {
    while(true){
        int escolha;
        cout << "Escolha o ficheiro:" << '\n';
        cout << "1 -> classes_per_uc" << '\n';
        cout << "2 -> classes" << '\n';
        cout << "3 -> student _classes" << '\n';
        cin >> escolha;
        switch(escolha){
            case 1:
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
                cout << "1 -> Turmas na UC" << '\n';
                cout << "2 -> UC's da Turma" << '\n';
                cout << "3 -> Tudo" << '\n';
                cin >> escolha1;
                switch(escolha1){
                    case 1:
                        cout << "Escolha a UC" << '\n';
                        set<string>::iterator it;
                        for(it = UCs.begin(); it != UCs.end(); it++){
                            cout << *it << " / ";
                        }
                        string escolhaUC;
                        cin >> escolhaUC;
                        for(auto d:cpu){
                            if(d.UcCode == escolhaUC){
                                cout << d.ClassCode << '\n';
                            }
                        }
                        break;
                    

                }
                break;
            
        }

    }
    return 0;
}
