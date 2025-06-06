#include <iostream>
#include"other.h"
using namespace std;


class Grade {
    public:
        int subjectId;
        string subjectName;
        int score;
        string date;
        Grade() {};
        Grade(int newSubjectId, string newSubjectName, int newScore, string newDate) {
            subjectId = newSubjectId;
            subjectName = newSubjectName;
            score = newScore;
            date = newDate;
        }
    };


class Person {
    int id;
    string name;
    string surname;

public:
    Person() {};
    Person(int newId, string newName, string newSurname) {
        id = newId;
        name = newName;
        surname = newSurname;
    }
    virtual void Log() {
        cout << "ID: " << id << " Name: " << name << " Surname: " << surname << endl;
    }
};

class Student : public Person {
    Grade* grades;
    int gradesCount;

public:
    Student(int newId, string newName, string newSurname, Grade* newGrades, int count)
        : Person(newId, newName, newSurname) {
        grades = newGrades;
        gradesCount = count;
    }
    
    void Log() override {
        Person::Log();
        for (int i = 0; i < gradesCount; i++) {
            cout << grades[i].subjectName << " - " << grades[i].score << " - " << grades[i].date << endl;
        }
    }
};
class Group{
    public:
    int numberOfStudents;
    Student* students;
    int GroupId;
    Group(Student* newStudents, int count){
        students=newStudents;
        numberOfStudents=count;
    };
    int get_id(){
        return GroupId;
    }
    void log(){
        for (int i = 0; i < numberOfStudents; i++)
        {
            students[i].Person::Log();
        }
        
    };
};
class Teacher : public Person {
    int subjectID;
    string subjectName;
    Group* groups;
public:
    Teacher() {};
    Teacher(int newId, string newName, string newSurname, int newSubjectID, string newSubjectName, Group* newGroups)
        :Person(newId, newName, newSurname) {
        subjectID = newSubjectID;
        subjectName = newSubjectName;
        groups = newGroups;
    }
    void show_subjectID() {
        cout << subjectID;
    }
    void show_subjectName() {
        cout << subjectName;
    }
    void show_all_groups() {
        int arrSize = sizeof(groups) / sizeof(groups[0]);
        cout << "groups that you have\n";
        for (int i = 0; i < arrSize; i++)
        {
            cout << i + 1 << ") " << groups[i].get_id() << endl;
        }
    }
    void show_all() {
        Person::Log();
        show_all_groups();
        show_subjectName();
        show_subjectID();
    }
    void choose_group(int group_numb){
        cout<<"Students of "<< group_numb<< " group\n";
        groups[group_numb-1].log();
        
    }
    void add_grade(){

    }
};