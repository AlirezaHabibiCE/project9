#ifndef TA_19_DOUBLEMAJORSTUDENT_H
#define TA_19_DOUBLEMAJORSTUDENT_H

#include "Student.h"
#include <string>

using namespace std;

class DoubleMajorStudent : public Student {

private:
    string major2;
    DoubleMajorStudent() = default;
public:
    DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours);
    DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,
            std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses , string major2);
    double calculateSalary() const override;

};




#endif //TA_19_DOUBLEMAJORSTUDENT_H
