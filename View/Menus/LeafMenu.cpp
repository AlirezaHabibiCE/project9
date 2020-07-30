#include "LeafMenu.h"
#include <map>
#include <iomanip>

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void LeafMenu:: showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if(name == "Show This Semester Courses"){
        for ( const auto & course : controller.currentSemesterCourses ){
            cout << course.toString() << endl;
        }
    }

    else if(name == "Take Course"){
        string ID;
        string coursename;
        cout << "enter student ID: ";
        cin >> ID;
        cout << "enter coursename: ";
        cin >> coursename;
        controller.takeCourse(ID , coursename);
    }

    else if(name == "Drop Course"){
        string ID;
        string coursename;
        cout << "enter student ID: ";
        cin >> ID;
        cout << "enter coursename: ";
        cin >> coursename;
        controller.dropCourse(ID , coursename);
    }

    else if(name == "Show Student Courses In Current Semester"){
        string ID;
        cout << "enter student ID: ";
        cin >> ID;
        controller.showStudentCurrentCourse( ID );
    }

    else if(name == "Calculate Student Salary"){
        string ID;
        cout << "enter student ID: ";
        cin >> ID;
        cout << "salary: " <<controller.calculateSalary(ID) <<endl;
    }

    else if(name == "Show Professor Courses In Current Semester"){
        cout << "enter the professor's ID :";
        string Id;
        cin >> Id;
        Professor prof = controller.findProfessor(Id);
        for (const auto& course : prof.getCurrentSemesterCourses() ){
            cout << course.first <<"\t";
        }
        if (prof.getCurrentSemesterCourses().size() == 0){
            cout<<"this professor have not any course in this semester."<<endl;
        }
        cout << endl;
    }

    else if(name == "Submit Grade"){
        controller.Submitgrade();
    }

    else if(name == "Calculate Professor Salary"){
        cout << "enter profId :";
        string profID;
        cin >> profID;
        Professor prof = controller.findProfessor(profID);
        cout << prof.calculateSalary() << endl;
    }

    else if(name == "Add Professor"){
        string ID,last,title,first;
        cout << "enter ID,first, last, title:";
        cin >> ID >> last >> title >> first;
        controller.addProfessor(ID,first,last,title);
    }

    else if(name == "Show Professors"){
        controller.showProfesors();
    }

    else if(name == "Add Student"){
        string ID,first,last;
        cout << "Enter student ID: ";
        cin >> ID;
        cout << "Enter First Name: ";
        cin >> first;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID , first, last);
    }

    else if(name == "Show Students"){
        controller.showstudent();
    }

    else if(name == "Add Course"){
        string courseName,profLast,semester;
        int numOfpre;
        vector <string> pre;
        cout << "enter your courseName,profLast,semester and number of pre courses:";
        cin >> courseName >> profLast>>semester >>numOfpre;

        if ( numOfpre != 0){
        cout << "enter your pre courses:";}

        for (int i{0} ; i < numOfpre ; ++i){
            cin >> pre[i] ;
        }
        try
        {   controller.addCourse(courseName,profLast,semester,pre);
        }
           catch(invalid_argument e){
          cout << e.what() << endl;}
    }

    else if(name == "Show Current Semester Courses"){
        for (const auto& crs : controller.currentSemesterCourses ){
            cout << crs.toString() << endl;
        }
    }

    else if(name == "Show All Courses"){
        for (const auto& crs : controller.courses ){
            cout << crs.toString() << endl;
        }
    }

    else if(name == "Read Members From File"){
        controller.readClassMember();
    }

    else if(name == "Calculate Total Salary"){
        cout << "Math salary is: " << controller.calculateClassSalary() <<endl;
    }

    else{
        throw invalid_argument("This Menu has not been defined!!");
    }
}
