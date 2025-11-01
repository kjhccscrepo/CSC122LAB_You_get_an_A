#include "student.hpp"

bool student::has_assignment(const assignment &assignment_to_find) const {
    if (my_assignments.empty() == true) {
        return false;
    }
    auto it = std::ranges::find_if(my_assignments,
        [assignment_to_find](const assignment& obj) {
            return obj.my_name() == assignment_to_find.my_name();
    });
    if (it != my_assignments.end()) {
        return true;
    } else {
       return false;
    }
}
student::student(const std::string &n, const std::string &id): my_name(n), my_id(id) {}
void student::addAssignment(const assignment &assignment) {
    if (!has_assignment(assignment)) {
        my_assignments.push_back(assignment);
    }
}
double student::calculateOverallGrade() const {
    if (my_assignments.empty()) {
        return 0.0;
    }
    double totalWeightedScore = 0.0;
    double totalMaxScore = 0.0;
    for (const auto& assign : my_assignments) {
        totalWeightedScore += assign.getStudentScore();
        totalMaxScore += assign.getMaxScore();
    }
    if (totalMaxScore > 0) {
        return (totalWeightedScore / totalMaxScore) * 100.0;
    }
    return 0.0;
}
void student::grade_assignment(const assignment *assignment_to_grade, const double &score) {
    if (!has_assignment(*assignment_to_grade)) {
        addAssignment(*assignment_to_grade);
    }
    if (!my_assignments.empty()) {
        for (int i = 0; i < my_assignments.size(); i++) {
            if (my_assignments[i].my_name() == assignment_to_grade->my_name()) {
                my_assignments[i].setStudentScore(score);
            }
        }
    }
}

void student::grade_assignment(const assignment &assignment_to_grade, const double &score) {
    grade_assignment(&assignment_to_grade, score);
}

std::string student::getName() const {
    return my_name;
}
std::string student::getName_First() const {
    const std::string::size_type pos = my_name.find_first_of(' ');
    return my_name.substr(0, pos);
}
std::string student::getName_Last() const {
    const std::string::size_type pos = my_name.find_last_of(' ');
    return my_name.substr(pos + 1, my_name.size() - 1);
}
std::string student::getID() const {
    return my_id;
}