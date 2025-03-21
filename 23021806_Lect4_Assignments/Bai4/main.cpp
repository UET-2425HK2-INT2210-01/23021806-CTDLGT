#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

struct Student{
    int id;
    string name;
    string className;
};

Student studentList[MAX_STUDENTS];
int studentCount = 0;

void insertStudent(int id, string name, string className){
    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id == id){
            studentList[i].name = name;
            studentList[i].className = className;
            return;
        }
    }
    if (studentCount < MAX_STUDENTS){
        studentList[studentCount] ={id, name, className};
        studentCount++;
    }
}

void deleteStudent(int id){
    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id == id){
            for (int j = i; j < studentCount - 1; j++){
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

void inforStudent(int id){
    for (int i = 0; i < studentCount; i++){
        if (studentList[i].id == id){
            cout << studentList[i].name << "," << studentList[i].className << endl;
            return;
        }
    }
    cout << "NA,NA" << endl; 
}

int main(){
    string command;
    while (cin >> command){
        if (command == "Insert"){
            int id;
            string name, className;
            cin >> id >> name >> className;
            insertStudent(id, name, className);
        } 
        else if (command == "Delete"){
            int id;
            cin >> id;
            deleteStudent(id);
        } 
        else if (command == "Infor"){
            int id;
            cin >> id;
            inforStudent(id);
        }
    }
    return 0;
}
