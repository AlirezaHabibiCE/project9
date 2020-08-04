#ifndef TA_19_CONTROLLER_H
#define TA_19_CONTROLLER_H

#include <string>
#include <vector>
#include "../Model/Student.h"
#include "../Model/DoubleMajorStudent.h"
#include "../Model/Professor.h"
#include "../Model/Course.h"

class Controller {
    friend class Menu;
    friend class LeafMenu;
    friend class CommandsFromFileMenu;
private:
    std::string currentSemester;
    std::vector<Student> students;
    std::vector<Professor> professors;
    std::vector<Course> courses;
    std::vector<Course> currentSemesterCourses;
    Controller() = default;
    vector <Person *> mathClass;


public:
    void readClassMember ();//load class list
    double calculateClassSalary() const;//calculate salary for a class
    explicit Controller(std::string currentSemester);
    void load();//load all files
    void save() const;//save changes to files

    void addStudent(std::string ID, std::string first, std::string last);
    void addProfessor(std::string ID, std::string first, std::string last, std::string title);
    void addCourse(std::string courseName, std::string profLast, std::string semester,
            std::vector<std::string> pre);
    void takeCourse(const std::string& studentID, const std::string& courseName);// chose course by student
    Student& findStudent(std::string ID);//find studnet by ID
    Professor& findProfessor(std::string ID);//find professor by ID
    void dropCourse (const std::string& ID , std::string coursename);//delete course by student
    void showStudentCurrentCourse (std:: string ID);
    void showProfesors ();//show professor list
    void showstudent ();//show student list
    double calculateSalary(string ID);//calculate student salary(one argument)
    void Submitgrade();//this function submit professor grade
    bool inStudents(const std::string& ID) const;//check is any students with this ID
    bool inProfessors(const std::string& ID) const;//check is any professors with this ID
    bool inProfessorsByLastName(const std::string& last) const;//check is any professors with this Last Name
    bool inCourses(const std::string& courseName) const;//check is any course with this course name
};


#endif //TA_19_CONTROLLER_H
