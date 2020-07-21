#include "LeafMenu.h"

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
        controller.showStudentCourse( ID );
    }

    else if(name == "Calculate Student Salary"){

    }

    else if(name == "Show Professor Courses In Current Semester"){

    }

    else if(name == "Submit Grade"){

    }

    else if(name == "Calculate Professor Salary"){

    }

    else if(name == "Add Professor"){

    }

    else if(name == "Show Professors"){

    }

    else if(name == "Add Student"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    }

    else if(name == "Show Students"){

    }

    else if(name == "Add Course"){

    }

    else if(name == "Show All Courses"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}
