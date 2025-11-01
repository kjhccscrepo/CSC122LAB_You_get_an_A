#include "gradebook.hpp"

std::string gradebook::make_letter_grade(const double &grade_num) {
    if (grade_num < 61) {
        return "F";
    }
    std::stringstream grade_stream;
    double grade_dub = grade_num;
    if (grade_num <= 71.49 && grade_num > 61) {
        grade_stream << "D";
        grade_dub = grade_dub - 61;
    } else if (grade_num <= 80.24 && grade_num > 61) {
        grade_stream << "C";
        grade_dub = grade_dub - 71.49;
    } else if (grade_num < 89.5 && grade_num > 61) {
        grade_stream << "B";
        grade_dub = grade_dub - 80.24;
    } else if (grade_num >= 89.5) {
        grade_stream << "A";
        grade_dub = grade_dub - 89.5;
    }
    if (grade_dub < 3.75) {
        grade_stream << "-";
    } else if (grade_dub > 6.5) {
        grade_stream << "+";
    }
    return grade_stream.str();
}

bool gradebook::has_student(const student &student_to_find) const {
    if (my_students.empty() == true) {
        return false;
    }
    auto it = std::ranges::find_if(my_students,
        [student_to_find](const student* obj) {
            return obj->getName() == student_to_find.getName();
    });
    if (it != my_students.end()) {
        return true;
    } else {
        return false;
    }
}

void gradebook::sort_by_lastName() {
    std::ranges::sort(my_students, [](const student* a, const student* b) {
        return a->getName_Last() < b->getName_Last();
    });
}

void gradebook::sort_by_Score() {
    std::ranges::sort(my_students, [](const student* a, const student* b) {
        return a->calculateOverallGrade() < b->calculateOverallGrade();
    });
}
void gradebook::sort_by_ID() {
    std::ranges::sort(my_students, [](const student* a, const student* b) {
        return a->getID() < b->getID();
    });
}
void gradebook::addStudent(student *student_to_add) {
    if (!has_student(*student_to_add)) {
        my_students.push_back(student_to_add);
    }
}

void gradebook::addStudent(student &student_to_add) {
    addStudent(&student_to_add);
}

std::string gradebook::displayGrades() const {
    std::stringstream all_grade;
    for (const auto& student : my_students) {
        all_grade << "Name: " << student->getName()
                  << std::endl
                  << "ID: " << student->getID()
                  << "\t (" << student->getName_First() << ")"
                  << std::endl;
        for (const auto& assignment : student->my_assignments) {
            all_grade << "\t" << assignment.my_name() << ":\t "
                      << " Score: " << assignment.getStudentScore() << "/" << assignment.getMaxScore()
                      << " (" << assignment.getPercentage() << "%)" << std::endl;
        }
        all_grade << "  Overall Grade: " << make_letter_grade(student->calculateOverallGrade())
                  << "  / ( " << student->calculateOverallGrade() << "% )" << std::endl
                  << std::endl;
    }
    return all_grade.str();
}
std::ostream& operator<<(std::ostream &os, const gradebook &myBook) {
    os << myBook.displayGrades();
    return os;
}