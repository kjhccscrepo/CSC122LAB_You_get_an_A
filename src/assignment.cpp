#include "assignment.hpp"

assignment::assignment(const std::string &name, const double maxS): name_of_assignment(name), maxScore(maxS), studentScore(0.0) {}
void assignment::setStudentScore(const double score) {
    if (score >= 0) {
        studentScore = score;
    }
}
double assignment::getPercentage() const {
    if (maxScore > 0) {
        return (studentScore / maxScore) * 100.0;
    }
    return 0.0;
}
double assignment::getMaxScore() const {
    return maxScore;
}
double assignment::getStudentScore() const {
    return studentScore;
}
std::string assignment::my_name() const {
    return name_of_assignment;
}