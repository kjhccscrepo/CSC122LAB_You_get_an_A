#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "student.hpp"
class gradebook {
private:
    std::vector<student*> my_students;

    static std::string make_letter_grade(const double &grade_num);
    bool has_student(const student &student_to_find) const;
public:
    void sort_by_lastName();
    void sort_by_Score();
    void sort_by_ID();
    void addStudent(student *student_to_add);
    void addStudent(student student_to_add);
    std::string displayGrades() const;
    friend std::ostream& operator<<(std::ostream &os, const gradebook &myBook);
};
std::ostream& operator<<(std::ostream &os, const gradebook &myBook);
#endif