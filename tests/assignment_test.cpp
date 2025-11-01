#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/assignment.hpp"
assignment Lab_1("Lab - week 1", 40);
TEST_CASE( "An assignment initializes and has a name" ) {
    REQUIRE(Lab_1.my_name() == "Lab - week 1");
}
TEST_CASE( "An assignment initializes and has a max score" ) {
    REQUIRE(Lab_1.getMaxScore() == 40);
}
TEST_CASE( "An assignment initializes and has a no scored points" ) {
    REQUIRE(Lab_1.getPercentage() == 0);
    REQUIRE(Lab_1.getStudentScore() == 0);
}
TEST_CASE( "An assignment score can be updated and grabbed." ) {
    Lab_1.setStudentScore(38);
    REQUIRE(Lab_1.getPercentage() == 95);
    REQUIRE(Lab_1.getStudentScore() == 38);
}
TEST_CASE( "An assignment score can be put back to 0." ) {
    Lab_1.setStudentScore(0);
    REQUIRE(Lab_1.getPercentage() == 0);
    REQUIRE(Lab_1.getStudentScore() == 0);
}
TEST_CASE( "An assignment score can be put over 100% for extra credit" ) {
    Lab_1.setStudentScore(42);
    REQUIRE(Lab_1.getPercentage() == 105);
    REQUIRE(Lab_1.getStudentScore() == 42);
}
TEST_CASE( "decimal values work" ) {
    assignment big_final ("Final Essay", 400);
    REQUIRE(big_final.getPercentage() == 0);
    REQUIRE(big_final.getStudentScore() == 0);
    big_final.setStudentScore(377);
    REQUIRE(big_final.getPercentage() == 94.25);
    REQUIRE(big_final.getStudentScore() == 377);
}