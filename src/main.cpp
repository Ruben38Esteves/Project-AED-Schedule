/**
 * @brief main file
 *
 */
#include <iostream>
#include "read.h"
#include "horario_turmas.h"
#include "horario_aluno.h"
#include "horario_uc.h"
#include <set>
#include <vector>
#include <queue>
/**
 * @brief main function
 * @details Guides the user through the program and prints its request.
 * It prints classes' schedules, chosen students' or UC's.
 * It also prints, if requested, a list of students by year, class, UC or all.
 * Also takes in the user's requests to remove/add students to UCs or classes, adding the requests to a lists and
 * applying changes when asked.
 *
 * @return
 */
int main() {
    Read ler;
    vector <classes_per_uc> CPU = ler.read_classes_per_uc();
    vector <classes> Classes = ler.read_classes();
    vector <students_classes> StuClasses = ler.read_students_classes();
    set <string> SetClasses;
    for (auto a: CPU) {
        SetClasses.insert(a.ClassCode);
    }
    set <string> SetUcs;
    for (auto a: CPU) {
        SetUcs.insert(a.UcCode);
    }
    queue <students_classes> currentchanges;
    int mainmenu = 0;
    while (mainmenu != 5) {
        //mostar opçoes
        cout << "1 -> Show Schedules" << '\n';
        cout << "2 -> Show Students" << '\n';
        cout << "3 -> Show Classes" << '\n';
        cout << "4 -> Show UC's" << '\n';
        cout << "5 -> Exit" << '\n';
        cin >> mainmenu;
        switch (mainmenu) {
            case 1: {
                cout << "1 -> Student Schedule" << '\n';
                cout << "2 -> Class Schedule" << '\n';
                cout << "3 -> UC CSchedule" << '\n';
                int menu1 = 0;
                cin >> menu1;
                switch (menu1) {
                    case 1: {
                        cout << "Write the students name or number" << '\n';
                        string nameorcode;
                        cin >> nameorcode;
                        Horario_Aluno ChosenStudent(nameorcode, Classes, StuClasses);
                        ChosenStudent.Print_Horario();
                        break;
                    }
                    case 2: {
                        cout << "Which Class?" << '\n';
                        set<string>::iterator it;
                        for (it = SetClasses.begin(); it != SetClasses.end(); it++) {
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        string chosenclass;
                        cin >> chosenclass;
                        Horario_Turma ChosenClass(chosenclass, Classes);
                        ChosenClass.Print_Horario();
                        cout << '\n';
                        break;
                    }
                    case 3: {
                        cout << "Which UC?" << '\n';
                        set<string>::iterator it;
                        for (it = SetUcs.begin(); it != SetUcs.end(); it++) {
                            cout << *it << " / ";
                        }
                        cout << '\n';
                        string chosenuc;
                        cin >> chosenuc;
                        Horario_UC ChosenUC(chosenuc, Classes);
                        ChosenUC.Print_Horario();
                        cout << '\n';
                        break;
                    }
                }
                break;
            }
            case 2: {
                cout << "1 -> Show all students" << '\n';
                cout << "2 -> Show students by class" << '\n';
                cout << "3 -> Show students by UC" << '\n';
                cout << "4 -> Show students by year" << '\n';
                cout << "5 -> Remove student from UC" << '\n';
                cout << "6 -> Remove Student from class" << '\n';
                cout << "7 -> Add Student to Class/Uc" << '\n';
                cout << "8 -> Apply Changes" << '\n';
                int menu2;
                cin >> menu2;
                switch (menu2) {
                    case 1: {
                        set <pair<string, string>> StudentsList;
                        for (auto a: StuClasses) {
                            pair <string, string> temp;
                            temp = make_pair(a.StudentName, a.StudentCode);
                            StudentsList.insert(temp);
                        }
                        vector <pair<string, string>> alunos;
                        for (auto a: StudentsList) {
                            alunos.push_back(a);
                        }
                        cout << "1 -> Show sorted by alphabetical order" << '\n';
                        cout << "2 -> Show sorted by inverted alphabetical order" << '\n';

                        int menu5;
                        cin >> menu5;
                        switch (menu5) {
                            case 1: {
                                sort(alunos.begin(), alunos.end());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }
                            case 2: {
                                sort(alunos.begin(), alunos.end(), greater < pair < string, string >> ());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }

                        }

                        cout << '\n' << '\n';
                        break;
                    }
                    case 2: {
                        cout << "Choose class:" << '\n';
                        string turma;
                        cin >> turma;
                        vector <pair<string, string>> alunos;
                        for (auto a: StuClasses) {
                            if (a.ClassCode == turma) {
                                pair <string, string> temp;
                                temp = make_pair(a.StudentName, a.StudentCode);
                                alunos.push_back(temp);
                            }
                        }

                        cout << "1 -> Show sorted by alphabetical order" << '\n';
                        cout << "2 -> Show sorted by inverted alphabetical order" << '\n';

                        int menu5;
                        cin >> menu5;
                        switch (menu5) {
                            case 1: {
                                sort(alunos.begin(), alunos.end());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }
                            case 2: {
                                sort(alunos.begin(), alunos.end(), greater < pair < string, string >> ());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }

                        }

                        cout << '\n' << '\n';
                        break;
                    }
                    case 3: {
                        cout << "Choose UC:" << '\n';
                        string uc;
                        cin >> uc;

                        cout << "1 -> Show sorted by alphabetical order" << '\n';
                        cout << "2 -> Show sorted by inverted alphabetical order" << '\n';

                        vector <pair<string, string>> alunos;
                        for (auto a: StuClasses) {
                            if (a.UcCode == uc) {
                                pair <string, string> temp;
                                temp = make_pair(a.StudentName, a.StudentCode);
                                alunos.push_back(temp);
                            }
                        }
                        int menu5;
                        cin >> menu5;
                        switch (menu5) {
                            case 1: {
                                sort(alunos.begin(), alunos.end());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }
                            case 2: {
                                sort(alunos.begin(), alunos.end(), greater < pair < string, string >> ());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }

                        }


                        cout << '\n' << '\n';
                        break;
                    }
                    case 4: {
                        cout << "Choose Year:" << '\n';
                        char year;
                        cin >> year;

                        set <pair<string, string>> SetStudents;
                        for (auto a: StuClasses) {
                            if (a.ClassCode[0] == year) {
                                pair <string, string> temp;
                                temp = make_pair(a.StudentName, a.StudentCode);
                                SetStudents.insert(temp);
                            }
                        }

                        cout << "1 -> Show sorted by alphabetical order" << '\n';
                        cout << "2 -> Show sorted by inverted alphabetical order" << '\n';

                        int menu5;
                        cin >> menu5;
                        switch (menu5) {
                            case 1: {
                                for (auto a: SetStudents) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }
                            case 2: {
                                vector <pair<string, string>> alunos;
                                for (auto a: SetStudents) {
                                    alunos.push_back(a);
                                }
                                sort(alunos.begin(), alunos.end(), greater < pair < string, string >> ());
                                for (auto a: alunos) {
                                    cout << a.first << "(" << a.second << ")" << "; ";
                                }
                                break;
                            }
                        }
                        cout << '\n' << '\n';

                        break;
                    }
                    case 5: {
                        cout << "Choose the Student" << '\n';
                        string student;
                        cin >> student;
                        if (isdigit(student[0])) {
                            for (auto a: StuClasses) {
                                if (student == a.StudentCode) {
                                    cout << a.UcCode << '\n';
                                }
                            }
                        } else {
                            for (auto a: StuClasses) {
                                if (student == a.StudentName) {
                                    cout << a.UcCode << '\n';
                                }
                            }
                        }
                        cout << '\n';
                        cout << "Choose the UC you want to remove from:" << '\n';
                        string removeUC;
                        cin >> removeUC;
                        if (isdigit(student[0])) {
                            auto it = StuClasses.begin();
                            while (it != StuClasses.end()) {
                                if (it->StudentCode == student && it->UcCode == removeUC) {
                                    it = StuClasses.erase(it);
                                } else {
                                    ++it;
                                }
                            }
                        } else {
                            auto it = StuClasses.begin();
                            while (it != StuClasses.end()) {
                                if (it->StudentName == student && it->UcCode == removeUC) {
                                    it = StuClasses.erase(it);
                                } else {
                                    ++it;
                                }
                            }
                        }
                        break;
                    }
                    case 6: {
                        cout << "Choose the Student" << '\n';
                        string student;
                        cin >> student;
                        if (isdigit(student[0])) {
                            for (auto a: StuClasses) {
                                if (student == a.StudentCode) {
                                    cout << a.ClassCode << '\n';
                                }
                            }
                        } else {
                            for (auto a: StuClasses) {
                                if (student == a.StudentName) {
                                    cout << a.ClassCode << '\n';
                                }
                            }
                        }
                        cout << "Choose the Class you want to remove from:" << '\n';
                        string turma;
                        cin >> turma;
                        if (isdigit(student[0])) {
                            auto it = StuClasses.begin();
                            while (it != StuClasses.end()) {
                                if (it->StudentCode == student && it->ClassCode == turma) {
                                    it = StuClasses.erase(it);
                                } else {
                                    ++it;
                                }
                            }
                        } else {
                            auto it = StuClasses.begin();
                            while (it != StuClasses.end()) {
                                if (it->StudentName == student && it->ClassCode == turma) {
                                    it = StuClasses.erase(it);
                                } else {
                                    ++it;
                                }
                            }
                        }
                        break;
                    }
                    case 7: {
                        bool changing = true;
                        while (changing) {
                            cout << "Choose the UC" << '\n';
                            for (auto a: SetUcs) {
                                cout << a << "; ";
                            }
                            cout << '\n';
                            string chosenuc;
                            cin >> chosenuc;
                            map<string, int> ClassOcup;
                            for (auto a: StuClasses) {
                                if (a.UcCode == chosenuc) {
                                    map<string, int>::iterator it = ClassOcup.find(a.ClassCode);
                                    if (it != ClassOcup.end()) {
                                        it->second++;
                                    } else {
                                        ClassOcup.insert(make_pair(a.ClassCode, 1));
                                    }
                                }
                            }
                            int minstu = 50;
                            int maxstu = 0;
                            for (auto a: ClassOcup) {
                                cout << "Class " << a.first << " has " << a.second << " students." << '\n';
                                if (a.second > maxstu) {
                                    maxstu = a.second;
                                }
                                if (a.second < minstu) {
                                    minstu = a.second;
                                }
                            }
                            cout << "Choose the class you wish to add the student to:" << '\n';
                            string chosenclass;
                            cin >> chosenclass;
                            if (ClassOcup[chosenclass] - minstu < 4 && maxstu - ClassOcup[chosenclass] < 4) {
                                cout << "Adding to this class won't create imbalance" << '\n';
                                students_classes temp;
                                temp.ClassCode = chosenclass;
                                temp.UcCode = chosenuc;
                                string chosencode;
                                cout << "What's the students code?" << '\n';
                                cin >> chosencode;
                                temp.StudentCode = chosencode;
                                string chosenname;
                                cout << "What's the students name?" << '\n';
                                cin >> chosenname;
                                temp.StudentName = chosenname;
                                currentchanges.push(temp);
                            } else {
                                cout << "Adding to this class will create imbalance" << '\n';
                                cout << "Do you wish to continue?(Y/N)" << '\n';
                                string option;
                                cin >> option;
                                if (option == "Y" || option == "y") {
                                    students_classes temp;
                                    temp.ClassCode = chosenclass;
                                    temp.UcCode = chosenuc;
                                    string chosencode;
                                    cout << "What's the students code?" << '\n';
                                    cin >> chosencode;
                                    temp.StudentCode = chosencode;
                                    string chosenname;
                                    cout << "What's the students name?" << '\n';
                                    cin >> chosenname;
                                    temp.StudentName = chosenname;
                                    currentchanges.push(temp);
                                }

                            }
                            cout << "Do you wish to make more changes?(Y/N)" << '\n';
                            string keepchanging = "r";
                            while (!(keepchanging == "Y" || keepchanging == "y" || keepchanging == "N" ||
                                     keepchanging == "n")) {
                                cin >> keepchanging;
                            }
                            if (keepchanging == "Y" || keepchanging == "y") {
                                changing = true;
                            } else {
                                changing = false;
                            }
                        }
                        cout << "The changes were saved but not applied, to apply them select the apply changes option."
                             << '\n';
                        break;
                    }
                    case 8: {
                        while (currentchanges.size() > 0) {
                            StuClasses.push_back(currentchanges.front());
                            currentchanges.pop();
                        }
                        cout << "Changes were applied." << '\n';
                    }
                }
                break;
            }
            case 3: {
                cout << "1-> Show all classes" << '\n';
                cout << "2-> Show a Student's class" << '\n';
                cout << "3-> Show classes by UC" << '\n';
                int menu3;
                cin >> menu3;
                switch (menu3) {
                    case 1: {
                        vector <string> turma;
                        for (auto a: SetClasses) {
                            turma.push_back(a);
                        }

                        cout << "1 -> Show sorted by ascending order" << '\n';
                        cout << "2 -> Show sorted by descending order" << '\n';

                        int menu6;
                        cin >> menu6;
                        switch (menu6) {
                            case 1: {
                                sort(turma.begin(), turma.end());
                                for (auto a: turma) {
                                    cout << a << "; ";
                                }
                                break;
                            }
                            case 2: {
                                sort(turma.begin(), turma.end(), greater<string>());
                                for (auto a: turma) {
                                    cout << a << "; ";
                                }
                                break;
                            }
                        }


                        cout << '\n' << '\n';
                        break;
                    }
                    case 2: {
                        cout << "Write Student's name or code:" << '\n';
                        string name_or_code;
                        cin >> name_or_code;
                        if (isdigit(name_or_code[0]) == 1) {
                            for (auto a: StuClasses) {
                                if (name_or_code == a.StudentCode) {
                                    cout << a.UcCode << " with " << a.ClassCode << '\n';
                                }
                            }
                        } else {
                            for (auto a: StuClasses) {
                                if (name_or_code == a.StudentName) {
                                    cout << a.UcCode << " with " << a.ClassCode << '\n';
                                }
                            }
                        }
                        cout << '\n';
                        break;
                    }
                    case 3: {
                        cout << "Choose UC:" << "\n";
                        string uc;
                        cin >> uc;
                        vector <string> turma;
                        for (auto a: CPU) {
                            if (a.UcCode == uc) {
                                turma.push_back(a.ClassCode);
                            }
                        }

                        cout << "1 -> Show sorted by ascending order" << '\n';
                        cout << "2 -> Show sorted by descending order" << '\n';

                        int menu6;
                        cin >> menu6;
                        switch (menu6) {
                            case 1: {
                                sort(turma.begin(), turma.end());
                                for (auto a: turma) {
                                    cout << a << "; ";
                                }
                                break;
                            }
                            case 2: {
                                sort(turma.begin(), turma.end(), greater<string>());
                                for (auto a: turma) {
                                    cout << a << "; ";
                                }
                                break;
                            }
                        }

                        cout << '\n' << '\n';
                    }
                        break;
                }
                break;
            }
            case 4: {
                cout << "1-> Show all UC's" << '\n';
                cout << "2-> Show UC's by class" << '\n';
                cout << "3-> Show Student's UC's" << '\n';
                int menu4;
                cin >> menu4;
                switch (menu4) {
                    case 1: {
                        for (auto a: SetUcs) {
                            cout << a << "; ";
                        }
                        cout << '\n' << '\n';
                        break;
                    }
                    case 2: {
                        cout << "Choose Class:" << '\n';
                        string turma;
                        cin >> turma;
                        for (auto a: CPU) {
                            if (a.ClassCode == turma) {
                                cout << a.UcCode << "; ";
                            }
                        }
                        cout << '\n' << '\n';
                        break;
                    }
                    case 3: {
                        cout << "Write Student's name or code:" << '\n';
                        string name_or_code;
                        cin >> name_or_code;
                        if (isdigit(name_or_code[0]) == 1) {
                            for (auto a: StuClasses) {
                                if (a.StudentCode == name_or_code) {
                                    cout << a.UcCode << '\n';
                                }
                            }
                        } else {
                            for (auto a: StuClasses) {
                                if (a.StudentName == name_or_code) {
                                    cout << a.UcCode << '\n';
                                }
                            }
                        }
                        cout << '\n';
                        break;
                    }
                        break;
                }
                break;
            }
        }
    }
}