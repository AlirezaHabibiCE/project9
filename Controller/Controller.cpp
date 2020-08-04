#include "Controller.h"
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

Controller::Controller(std::string currentSemester)
   : currentSemester{move(currentSemester)} {}


void Controller:: load(){
    ifstream inputStu("students.txt");
    int studentSize;
    inputStu >> studentSize;
    Student stu;
    for( size_t i{0}; i < studentSize; ++i ){
        inputStu >> stu;
        students.push_back(stu);
    }
    inputStu.close();

    ifstream inputProf("professors.txt");
    int profSize;
    inputProf >> profSize;
    Professor prof;
    for( size_t i{0}; i < profSize; ++i){
        inputProf >> prof;
        professors.push_back(prof);
    }
    inputProf.close();

    ifstream inputCourse("courses.txt");
    int courseSize;
    inputCourse >> courseSize;
    Course crs;
    for( size_t i{0}; i < courseSize; ++i){
        inputCourse >> crs;
        courses.push_back(crs);
        if(crs.semester == currentSemester){
            currentSemesterCourses.push_back(crs);
        }
    }
    inputCourse.close();
}

void Controller::save() const{
    ofstream outputStu("students.txt", ios::out);
    outputStu << students.size() << endl;
    for( auto const& stu : students ){
        outputStu << stu << endl;
    }
    outputStu.close();

    ofstream outputProf("professors.txt");
    outputProf << professors.size() << endl;
    for( const auto& prof : professors ){
        outputProf << prof << endl;
    }
    outputProf.close();

    ofstream outputCourse("courses.txt");
    outputCourse << courses.size() << endl;
    for( auto const& crs : courses ){
        outputCourse << crs << endl;
    }
    outputCourse.close();
}

void Controller:: addStudent(std::string ID, std::string first, std::string last){
    if(!inStudents(ID)){
        Student stu{move(ID), move(first), move(last), 0,
                    vector<string>{}, map<string, double>{}};
        students.push_back(stu);
    }
}

void Controller:: addProfessor(std::string ID, std::string first,
        std::string last, std::string title){
    if(!inProfessors(ID)){
        Professor prof{move(ID), move(first), move(last), 0, move(title)};
        professors.push_back(prof);
    }
}

void Controller:: addCourse(std::string courseName, std::string profLast, std::string semester,
               std::vector<std::string> pre){
    //check has exit this course also professor
    if( !inCourses(courseName) && inProfessorsByLastName(profLast) ){
        Course crs{move(courseName), move(profLast), move(semester), move(pre)};
        courses.push_back(crs);
        if( crs.semester == currentSemester){
            currentSemesterCourses.push_back(crs);
        }
    } else
        throw invalid_argument (
         " your course name or Professor last name isn't on the our list ");
}

bool Controller::inStudents(const std::string& ID) const{
    for( const auto& stu : students ){
        if( stu.studentId == ID){
            return true;
        }
    }
    return false;
}

bool Controller::inProfessors(const std::string& ID) const{
    for( const auto& prof : professors ){
        if( prof.profId == ID){
            return true;
        }
    }
    return false;
}

bool Controller::inCourses(const std::string& courseName) const{
    for( const auto& crs : courses ){
        if( crs.courseName == courseName){
            return true;
        }
    }
    return false;
}

bool Controller:: inProfessorsByLastName(const std::string& last) const{
    for( const auto& prof : professors ){
        if( prof.getLastName() == last){
            return true;
        }
    }
    return false;
}

Student& Controller:: findStudent(string ID){
    for( auto& stu : students ){
        if(stu.studentId == ID){
            return stu;
        }
    }
    throw invalid_argument("The Student was not found!!");
}

Professor& Controller:: findProfessor(string ID){
    for( auto& prof : professors ){
        if(prof.profId == ID){
            return prof;
        }
    }
    throw invalid_argument("The Professor wasn't found!!");
}

void Controller:: takeCourse(const std::string& studentID, const std::string& courseName){
    if(inCourses(courseName)){
        findStudent(studentID).currentSemesterCourses.insert({courseName, 0});
    }
}

void Controller::dropCourse (const std::string& ID , std::string courseName){
    if(inCourses(courseName)){
        findStudent(ID).currentSemesterCourses.erase(courseName);
    }
}

void Controller ::showStudentCurrentCourse (std:: string ID){
    Student stu = findStudent(ID);

    for(const auto& crs : stu.currentSemesterCourses )
    {
        cout<<"course name: " << crs.first <<"\tcourse grade: " <<crs.second << endl;
    }
}

double Controller::calculateSalary(string ID){
    auto* stu = new Student(findStudent(move(ID)));

    return stu->calculateSalary();
}

void Controller::readClassMember (){
    string members;
    char* mem = new char[1000];
    ifstream input ("members");
    int numOfMember;
    cout << "enter number of member class: " ;
    cin >> numOfMember;

    for (int i{0} ; i < numOfMember ; ++i){

        //separate line to a array of string according to words
        input.getline(mem , 1000);
        members = (string) mem;
        istringstream iss {members};
        vector<string> result(istream_iterator<string> {iss} , istream_iterator<string>{});

        //breaking down list to Double Major Studnt and Student and Professor
        if (result[0] == "D"){
            double workhours = stod(result[4]);
            auto* mstu = new DoubleMajorStudent(result[1], result[2], result[3], workhours );
            mathClass.push_back(mstu);
        }

        if (result[0] == "S"){
            double workhours = stod(result[4]);
            auto* stu = new Student(result[1], result[2], result[3], workhours );
            mathClass.push_back(stu);
        }

        if (result[0] == "P"){
            double workhours = stod(result[5]);
            auto* prof = new Professor(result[1], result[2], result[3], workhours, result[4]);
            mathClass.push_back(prof);
        }
}}

double Controller::calculateClassSalary() const{
    double TotalSalary = 0.0;
    for (const auto& member : mathClass ){
        TotalSalary += member->calculateSalary();
        //calculate salary is a pure virtual function in Person Class
    }
    return TotalSalary;
}

void Controller::Submitgrade(){
    cout << "enter your Course name:";
    string courseName;
    cin>>courseName;
    cout << "enter your StudentId:";
    string StudentId;
    cin>>StudentId;
    cout << "enter your grade:";
    double grade;
    cin>>grade;
    Student& stu = findStudent(StudentId);//by reference for save changes
    for( auto& crs : stu.currentSemesterCourses ){
        if(crs.first == courseName ){
            crs.second = grade;}}
    }


void Controller::showProfesors (){
    for (const auto& prof : professors ){
        cout << prof << endl;
    }//we implement operator << for professor
    cout<<endl;
}

void Controller::showstudent (){
    for (const auto& stu : students ){
        cout << stu << endl;
    }//we implement operator << for student
    cout<<endl;
}
