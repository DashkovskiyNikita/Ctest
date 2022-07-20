#include "c_test.h"

void test1(c_test_log* log)
{
	c_test_assert_true(log,"test1",2 == 2);
}

void test2(c_test_log* log)
{
	c_test_assert_false(log,"test2",2 == 2);
}

int main(void)
{
	TEST tasks[2] = { &test1,&test2 };

	c_test_run(tasks,2,"log_output.txt");

	return 0;
}