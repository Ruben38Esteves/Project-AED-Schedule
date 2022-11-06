/**
 * @file read.cpp
 * @brief
 * Functions to process data from files
 *
 */
#include "read.h"

/**
 * @brief Reads contents of the csv file "classes_per_uc"
 * @details
 * Starts by opening the file and checking if it was successful,
 * proceeds to discard the first line and runs a loop fetching the values between commas in the file and storing the
 * values in a variable temp of type classes_per_uc. It then adds temp to the vector 'cpu' at the end of each cycle.
 * @return vector with the file contents
 */
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
/**
 * @brief Reads contents of the csv file "classes"
 * @details
 * Starts by opening the file and checking if it was successful,
 * proceeds to discard the first line and runs a loop reading each value between commas in each line in the file
 * and giving its values to a variable temp of type classes that is stored in the vector 'aulas' in
 * the end of each cycle.
 * @return vector with the file content
 */

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
/**
 * @brief Reads contents of the csv file "students_classes"
 * @details
 * Starts by opening the file and checking if it was successful,
 * proceeds to discard the first line and run a cycle reading the file and storing the values in a variable "temp" of the type students_classes for each line.
 * In the end of each line in the file, the variable temp is added to the vector sc.
 * @return vector with the file content
 */
vector<students_classes> Read::read_students_classes(){
    vector<students_classes> sc;
    ifstream file_students_classes;
    file_students_classes.open("../students_classes.csv");
    if(!file_students_classes.is_open()){
        return sc;
    }

    string str;
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




