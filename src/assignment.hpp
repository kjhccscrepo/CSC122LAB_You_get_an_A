#ifndef YOU_GET_AN_A_ASSIGNMENT_HPP
#define YOU_GET_AN_A_ASSIGNMENT_HPP
#include <string>
class assignment {
    std::string name_of_assignment;
    double maxScore;
    double studentScore;
public:

    assignment(const std::string &name, double maxS);
    void setStudentScore(double score);
    double getPercentage() const;
    double getMaxScore() const;
    double getStudentScore() const;
    std::string my_name() const;
};
#endif //YOU_GET_AN_A_ASSIGNMENT_HPP