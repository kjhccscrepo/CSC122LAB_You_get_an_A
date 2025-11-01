#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "student.hpp"
class gradebook {
private:
    std::vector<student> my_students;
    std::string make_letter_grade(const double &grade_num) const;
public:
    void sort_by_lastName();
    void sort_by_Score();
    void sort_by_ID();
    void addStudent(const student& student);
    std::string displayGrades() const;
    friend std::ostream& operator<<(std::ostream &os, const gradebook &myBook);
};
std::ostream& operator<<(std::ostream &os, const gradebook &myBook);
#endif