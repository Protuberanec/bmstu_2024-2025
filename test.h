#ifndef _test_h_
#define _test_h_

#include <iostream>
#include <string>

template<typename T>
void run_test(T, const std::string& test_funct_name) {
	std::cout << "Test run for " << test_funct_name << std::endl;
	T();
}
void run_test1(void (*f)(), const std::string&);
#define RUN_TEST(f)	run_test1(f, #f)
template<class T>
void my_assert(T expr, const std::string& expr_str) {
	if (expr == true) {
		std::cout << "\t\tTEST OK" << std::endl;
		return;
	}

	std::cout << "\t\tTEST BAD - " << expr_str << std::endl;
	std::cout << "\t\t\t" << __func__ << " " << __FILE__ << std::endl;

}
#define	ASSERT(expr_true)	my_assert(expr_true, #expr_true)

template<class T>
void my_assert_equal(const T& expr, const T& expr_true, const std::string& expr_str, const std::string& expr_true_str) {
	if (expr == expr_true) {
		std::cout << "\t\tTEST OK" << std::endl;
		return;
	}

	std::cout << "\t\tTEST BAD {" << expr_str << " != " << expr_true_str << "}" << std::endl;
}
#define ASSERT_EQUAL(expr, expr_true)	my_assert_equal(expr, expr_true, #expr, #expr_true)



#endif
