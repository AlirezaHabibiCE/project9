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
    void readClassMember ();
    double calculateClassSalary() const;

public:
    explicit Controller(std::string currentSemester);
    void load();
    void save() const;

    void addStudent(std::string ID, std::string first, std::string last);
    void addProfessor(std::string ID, std::string first, std::string last, std::string title);
    void addCourse(std::string courseName, std::string profLast, std::string semester,
            std::vector<std::string> pre);
    void takeCourse(const std::string& studentID, const std::string& courseName);
    Student& findStudent(std::string ID);
    void dropCourse (const std::string& ID , std::string coursename);
    void showStudentCourse (std:: string ID);
    double calculateSalary(string ID);

    bool inStudents(const std::string& ID) const;
    bool inProfessors(const std::string& ID) const;
    bool inProfessorsByLastName(const std::string& last) const;
    bool inCourses(const std::string& courseName) const;
};


#endif //TA_19_CONTROLLER_H
