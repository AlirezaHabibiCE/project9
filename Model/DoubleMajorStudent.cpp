#include "DoubleMajorStudent.h"

using namespace std;

DoubleMajorStudent::DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,
                   std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses , string major2)
                   : Student(studentId, move(first), move(last) ,  workHours,
        move(passedCourses), move(currentSemesterCourses))
                     {
    this->major2 = move(major2);
}

DoubleMajorStudent::DoubleMajorStudent(const string& studentId, std::string first, std::string last , double workHours)
:Student( (studentId), move(first), move(last) , (workHours)){}


double DoubleMajorStudent::calculateSalary() const{
    return 6500 * getWorkHours();
}

