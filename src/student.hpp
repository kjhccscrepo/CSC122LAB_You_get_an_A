#ifndef YOU_GET_AN_A_STUDENT_HPP
#define YOU_GET_AN_A_STUDENT_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "assignment.hpp"
class student {
    std::string my_name;
    std::string my_id;
    bool has_assignment(const assignment &assignment_to_find) const;
public:
    std::vector<assignment> my_assignments;
    explicit student(const std::string &n, const std::string &id);
    void addAssignment(const assignment& assignment);
    double calculateOverallGrade() const;
    void grade_assignment(const assignment *assignment_to_grade, const double &score);
    void grade_assignment(const assignment &assignment_to_grade, const double &score);
    std::string getName() const;
    std::string getName_First() const;
    std::string getName_Last() const;
    std::string getID() const;
};
#endif