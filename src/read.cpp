/**
 * @file read.cpp
 * @brief
 * functions to process data from files
 *
 */
#include "read.h"

vector<classes_per_uc> Read::read_classes_per_uc(){
    vector<classes_per_uc> cpu;
    //abrir ficheiro
    ifstream file_cpu;
    file_cpu.open("../classes_per_uc.csv");
    //verificar se foi possivel abrir
    if(!file_cpu.is_open()){
        return cpu;
    }

    string code;

    //ir buscar primeira linha (UcCode,ClassCode)
    getline(file_cpu, code);

    //ler linha a linha
    while(getline(file_cpu, code)){
        stringstream line(code);
        string buffer;
        classes_per_uc temp;

        //buscar UcCode (le ate ',')
        getline(line, buffer, ',');
        temp.UcCode = buffer;

        //buscar ClassCode (le ate fim de linha)
        getline(line, buffer, '\r');
        temp.ClassCode = buffer;

        //adicionar a vetor
        cpu.push_back(temp);
    }
    return cpu;
}

vector<classes> Read::read_classes(){
    vector<classes> aulas;
    //abrir ficheiro
    ifstream file_classes;
    file_classes.open("../classes.csv");
    //verificar se foi possivel abrir
    if(!file_classes.is_open()){
        return aulas;
    }

    string value;

    //ir buscar a primeira linha
    getline(file_classes, value);

    //ler linha a linha
    while(getline(file_classes, value)){
        stringstream line(value);
        string buffer;
        classes temp;
        double start;
        double duration;

        //buscar ClassCode
        getline(line, buffer, ',');
        temp.ClassCode = buffer;

        //Buscar UcCode
        getline(line, buffer, ',');
        temp.UcCode = buffer;

        //Buscar Weekday
        getline(line, buffer, ',');
        temp.Weekday = buffer;

        //Buscar StartHour
        getline(line, buffer, ',');
        temp.StartHour = buffer;
        start = stod(buffer);

        //Buscar Duration
        getline(line, buffer, ',');
        temp.Duration = buffer;
        duration = stod(buffer);

        //Calcular EndHour
        temp.EndHour = start + duration;


        //Buscar Type
        getline(line, buffer, '\r');
        temp.Type = buffer;

        //adicionar ao vetor
        aulas.push_back(temp);
    }
    return aulas;
}

vector<students_classes> Read::read_students_classes(){
    vector<students_classes> sc;
    //abrir ficheiro
    ifstream file_students_classes;
    file_students_classes.open("../students_classes.csv");
    //verificar se foi possível abrir
    if(!file_students_classes.is_open()){
        return sc;
    }

    string str;
    //ir buscar primeira linha(StudentCode,StudentName,UcCode,ClassCode)
    getline(file_students_classes, str);

    //ler linha a linha
    while(getline(file_students_classes, str)){
        stringstream line(str);
        string buffer;
        students_classes temp;
        //buscar StudentCode
        getline(line,buffer,',');
        temp.StudentCode=buffer;
        //buscar StudentName
        getline(line,buffer,',');
        temp.StudentName=buffer;
        //buscar UcCode
        getline(line,buffer,',');
        temp.UcCode=buffer;
        //buscar Classcode;
        getline(line,buffer,'\r');
        temp.ClassCode=buffer;
        //adicionar ao vetor
        sc.push_back(temp);
    }
    return sc;
};


/*string Read::nome_por_code(string code){
    string ret;
    //abrir ficheiro
    ifstream file_students_classes;
    file_students_classes.open("../students_classes.csv");
    //verificar se foi possível abrir
    if(!file_students_classes.is_open()){
        return ret;
    }
    string str;
    //ir buscar primeira linha(StudentCode,StudentName,UcCode,ClassCode)
    getline(file_students_classes, str);

    //ler linha a linha
    while(getline(file_students_classes, str)){
        stringstream line(str);
        string buffer;
        //buscar student code
        getline(line,buffer,',');
        if(buffer==code){
            getline(line,buffer,',');
            return buffer;
        }else{
            getline(line,buffer,'\r');
        }

    }
    return ret;
};

string Read::code_por_nome(string nome){
    string ret;
    //abrir ficheiro
    ifstream file_students_classes;
    file_students_classes.open("../students_classes.csv");
    //verificar se foi possível abrir
    if(!file_students_classes.is_open()){
        return ret;
    }
    string str;
    //ir buscar primeira linha(StudentCode,StudentName,UcCode,ClassCode)
    getline(file_students_classes, str);

    //ler linha a linha
    while(getline(file_students_classes, str)){
        stringstream line(str);
        string buffer;
        string code;
        //buscar student code
        getline(line,buffer,',');
        code=buffer;
        //buscar nome
        getline(line,buffer,',');
        if(buffer==nome){
            return code;
        }else{
            getline(line,buffer,'\r');
        }
    }
    return ret;
}*/

