#include <iostream>
#include "src/gradebook.hpp"
#include "src/id_maker.hpp"

int main() {
    ID_maker maker;
    gradebook myGradebook;

    assignment hw1("Homework 1", 10);
    assignment hw2("Homework 2", 10);
    assignment hw3("Homework 3", 15);
    assignment quiz1("Unit 1 Quiz", 50);
    assignment exam1("Unit 1 Exam", 200);

    student sara("Sara J. Smith", maker.generateID());
    student ivan("Ivan Chesterton", maker.generateID());
    student jacklynn("Jacklynn Tyler", maker.generateID());
    student rosie("Rosie Tyler", maker.generateID());

    sara.grade_assignment(hw1, 9);
    sara.grade_assignment(hw2, 10);
    sara.grade_assignment(hw3, 13);
    sara.grade_assignment(quiz1, 40);
    sara.grade_assignment(exam1, 180);

    ivan.grade_assignment(hw1, 8);
    ivan.grade_assignment(hw2, 9);
    ivan.grade_assignment(hw3, 15);
    ivan.grade_assignment(quiz1, 45);
    ivan.grade_assignment(exam1, 160);

    jacklynn.grade_assignment(hw1, 8);
    jacklynn.grade_assignment(hw2, 10);
    jacklynn.grade_assignment(hw3, 13);
    jacklynn.grade_assignment(quiz1, 42);
    jacklynn.grade_assignment(exam1, 195);

    rosie.grade_assignment(hw1, 10);
    rosie.grade_assignment(hw2, 6);
    rosie.grade_assignment(hw3, 9);
    rosie.grade_assignment(quiz1, 23);
    rosie.grade_assignment(exam1, 117);

    myGradebook.addStudent(sara);
    myGradebook.addStudent(ivan);
    myGradebook.addStudent(jacklynn);
    myGradebook.addStudent(rosie);

    myGradebook.sort_by_lastName();

    std::cout << myGradebook;
    return 0;
}