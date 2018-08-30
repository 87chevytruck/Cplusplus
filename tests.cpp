#include "catch/src/catch/single_include/catch.hpp"
#include <random>
#include "StudentCode.hpp"


TEST_CASE("Test1", "CppTest") {
	auto nq = grader::get_nq();

	auto res = get_solutions(*nq, 8, 8);

	REQUIRE(res.at(8) == 92);
}


TEST_CASE("Test2", "CppTest") {

	auto nq = grader::get_nq();

	auto res = get_solutions(*nq, 5, 10);

	for (auto i = 5; i <= 10; ++i) {
		REQUIRE(res.at(i) == grader::val_at(i - 1));
	}
}


TEST_CASE("Test3", "CppTest") {

	auto nq = grader::get_nq();
	auto res = get_solutions(*nq, 1, 11);

	for (auto i = 1; i <= 11; ++i) {
		REQUIRE(res.at(i) == grader::val_at(i - 1));
	}
}
