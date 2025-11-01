#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/gradebook.hpp"

TEST_CASE( "A gradebook can be sorted correctly" ) {
    gradebook my_gb;
    student sara("Sara J. Smith", "D300612");
    student clara("Clara O. Oswald", "D1107B2");
    student roary("Roary Williams", "D115AE1");
    assignment ws1a("Worksheet 1-1", 10);
    assignment ws2a("Worksheet 1-2", 10);
    assignment qz1a("Unit 1 Quiz", 25);
    assignment ws3a("Worksheet 1-3", 15);
    assignment ex1a("Unit 1 Exam", 40);
    sara.grade_assignment(ws1a, 10);
    sara.grade_assignment(ws2a, 10);
    sara.grade_assignment(ws3a, 15);
    sara.grade_assignment(qz1a, 24);
    sara.grade_assignment(ex1a, 38);
    clara.grade_assignment(ws1a, 8);
    clara.grade_assignment(ws2a, 7);
    clara.grade_assignment(ws3a, 11);
    clara.grade_assignment(qz1a, 21);
    clara.grade_assignment(ex1a, 37);
    roary.grade_assignment(ws1a, 10);
    roary.grade_assignment(ws2a, 9);
    roary.grade_assignment(ws3a, 0);
    roary.grade_assignment(qz1a, 19);
    roary.grade_assignment(ex1a, 32);
    my_gb.addStudent(sara);
    my_gb.addStudent(clara);
    my_gb.addStudent(roary);
    my_gb.sort_by_lastName();
    REQUIRE(my_gb.displayGrades() == "Name: Clara O. Oswald\n"
                                     "ID: D1107B2	 (Clara)\n"
                                     "\tWorksheet 1-1:	  Score: 8/10 (80%)\n"
                                     "\tWorksheet 1-2:	  Score: 7/10 (70%)\n"
                                     "\tWorksheet 1-3:	  Score: 11/15 (73.3333%)\n"
                                     "\tUnit 1 Quiz:	  Score: 21/25 (84%)\n"
                                     "\tUnit 1 Exam:	  Score: 37/40 (92.5%)\n"
                                     "  Overall Grade: B  / ( 84% )\n"
                                     "\n"
                                     "Name: Sara J. Smith\n"
                                     "ID: D300612	 (Sara)\n"
                                     "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                     "\tWorksheet 1-2:	  Score: 10/10 (100%)\n"
                                     "\tWorksheet 1-3:	  Score: 15/15 (100%)\n"
                                     "\tUnit 1 Quiz:	  Score: 24/25 (96%)\n"
                                     "\tUnit 1 Exam:	  Score: 38/40 (95%)\n"
                                     "  Overall Grade: A+  / ( 97% )\n"
                                     "\n"
                                     "Name: Roary Williams\n"
                                     "ID: D115AE1	 (Roary)\n"
                                     "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                     "\tWorksheet 1-2:	  Score: 9/10 (90%)\n"
                                     "\tWorksheet 1-3:	  Score: 0/15 (0%)\n"
                                     "\tUnit 1 Quiz:	  Score: 19/25 (76%)\n"
                                     "\tUnit 1 Exam:	  Score: 32/40 (80%)\n"
                                     "  Overall Grade: D+  / ( 70% )\n"
                                     "\n");

    my_gb.sort_by_ID();
    REQUIRE(my_gb.displayGrades() == "Name: Clara O. Oswald\n"
                                 "ID: D1107B2	 (Clara)\n"
                                 "\tWorksheet 1-1:	  Score: 8/10 (80%)\n"
                                 "\tWorksheet 1-2:	  Score: 7/10 (70%)\n"
                                 "\tWorksheet 1-3:	  Score: 11/15 (73.3333%)\n"
                                 "\tUnit 1 Quiz:	  Score: 21/25 (84%)\n"
                                 "\tUnit 1 Exam:	  Score: 37/40 (92.5%)\n"
                                 "  Overall Grade: B  / ( 84% )\n"
                                 "\n"
                                 "Name: Roary Williams\n"
                                 "ID: D115AE1	 (Roary)\n"
                                 "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-2:	  Score: 9/10 (90%)\n"
                                 "\tWorksheet 1-3:	  Score: 0/15 (0%)\n"
                                 "\tUnit 1 Quiz:	  Score: 19/25 (76%)\n"
                                 "\tUnit 1 Exam:	  Score: 32/40 (80%)\n"
                                 "  Overall Grade: D+  / ( 70% )\n"
                                 "\n"
                                 "Name: Sara J. Smith\n"
                                 "ID: D300612	 (Sara)\n"
                                 "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-2:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-3:	  Score: 15/15 (100%)\n"
                                 "\tUnit 1 Quiz:	  Score: 24/25 (96%)\n"
                                 "\tUnit 1 Exam:	  Score: 38/40 (95%)\n"
                                 "  Overall Grade: A+  / ( 97% )\n"
                                 "\n");

    my_gb.sort_by_Score();
    REQUIRE(my_gb.displayGrades() ==
                                 "Name: Roary Williams\n"
                                 "ID: D115AE1	 (Roary)\n"
                                 "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-2:	  Score: 9/10 (90%)\n"
                                 "\tWorksheet 1-3:	  Score: 0/15 (0%)\n"
                                 "\tUnit 1 Quiz:	  Score: 19/25 (76%)\n"
                                 "\tUnit 1 Exam:	  Score: 32/40 (80%)\n"
                                 "  Overall Grade: D+  / ( 70% )\n"
                                 "\n"
                                 "Name: Clara O. Oswald\n"
                                 "ID: D1107B2	 (Clara)\n"
                                 "\tWorksheet 1-1:	  Score: 8/10 (80%)\n"
                                 "\tWorksheet 1-2:	  Score: 7/10 (70%)\n"
                                 "\tWorksheet 1-3:	  Score: 11/15 (73.3333%)\n"
                                 "\tUnit 1 Quiz:	  Score: 21/25 (84%)\n"
                                 "\tUnit 1 Exam:	  Score: 37/40 (92.5%)\n"
                                 "  Overall Grade: B  / ( 84% )\n"
                                 "\n"
                                 "Name: Sara J. Smith\n"
                                 "ID: D300612	 (Sara)\n"
                                 "\tWorksheet 1-1:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-2:	  Score: 10/10 (100%)\n"
                                 "\tWorksheet 1-3:	  Score: 15/15 (100%)\n"
                                 "\tUnit 1 Quiz:	  Score: 24/25 (96%)\n"
                                 "\tUnit 1 Exam:	  Score: 38/40 (95%)\n"
                                 "  Overall Grade: A+  / ( 97% )\n"
                                 "\n");
}