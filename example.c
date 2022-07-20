#include "c_test.h"

//Example of writing tests

void test1(c_test_log* log)
{
	int a = 2;
	int b = 2;
	c_test_assert_true(log,"test1",a == b);
}

void test2(c_test_log* log)
{
	int a = 2;
	int b = 2;
	c_test_assert_false(log,"test2",a != b);
}

int main(void)
{
	//Making array of tests functions
	int tests_count = 2;
	TEST tasks[tests_count] = { &test1,&test2 };

	//Run list of tests and writing result to file
	c_test_run(tasks,tests_count,"log_output.txt");

	return 0;
}
