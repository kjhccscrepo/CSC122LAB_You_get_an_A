#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/student.hpp"

student john("John Joseph James", "H00A025P7");
TEST_CASE( "full name can be called" ) {
    REQUIRE( john.getName() == "John Joseph James" );
}
TEST_CASE( "first name can be called" ) {
    REQUIRE( john.getName_First() == "John" );
}
TEST_CASE( "last name can be called" ) {
    REQUIRE( john.getName_Last() == "James" );
}
TEST_CASE( "and id is stored" ) {
    REQUIRE( john.getID() == "H00A025P7" );
}
TEST_CASE( "A student can have a grade reported" ) {
    assignment wk1("worksheet 1", 8);
    assignment wk2("worksheet 2", 8);
    assignment qz1("unit 1 quiz", 16);
    john.grade_assignment(wk1, 8);
    john.grade_assignment(wk2, 8);
    john.addAssignment(qz1);
    REQUIRE( john.calculateOverallGrade() == 50 );
    john.grade_assignment(qz1, 13);
    REQUIRE( john.calculateOverallGrade() == 90.625 );
}