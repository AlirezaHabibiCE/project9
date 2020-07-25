#ifndef TA_19_PROFESSOR_H
#define TA_19_PROFESSOR_H

#include <string>
#include <iostream>
#include "Person.h"
#include <map>

class Professor : public Person {
    friend class Controller;
    friend std::ostream& operator<<(std::ostream & output, const Professor& prof);
    friend std::istream& operator>>(std::istream & input, Professor& prof);
private:
    std::string title;
    std::string profId;
    std::map<std::string, double> currentSemesterCourses;

public:
    const std::map<std::string, double> &getCurrentSemesterCourses() const;
    Professor(){}
    Professor(std::string id, std::string first, std::string last, double wh, std::string title);
    Professor(std::string id, std::string first, std::string last, double wh, std::string title,
                  std::map<std::string, double> currentSemesterCourses);
    virtual double calculateSalary() const override;
};


#endif //TA_19_PROFESSOR_H
