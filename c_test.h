#include "c_test_log.h"
#include <stdio.h>

typedef void (*TEST)(c_test_log*);

const char* LOG_START     = "Test ";
const char* LOG_PASSED    = "passed";
const char* LOG_FAILED    = "failed";

void c_test_write_log(c_test_log* log,const char* filename)
{
	FILE* file_log = fopen(filename,"w");
	
	struct c_test_node* current = log->head;
	
	while(current){
		
		fputs(LOG_START,file_log);
		fputc('"',file_log);
		fputs(current->name,file_log);
		fputs("\" ",file_log);
		
		if(current->result)
			fputs(LOG_PASSED,file_log);
		else
			fputs(LOG_FAILED,file_log);

		fputs("\n",file_log);
		
		current = current->next;
	}

	fclose(file_log);

}

void c_test_run(TEST* tests,const int count,const char* filename)
{
	c_test_log* log = c_test_new_log();

	for(int i = 0;i < count;i++) tests[i](log);

	c_test_write_log(log,filename);

	c_test_log_clear(log);
}

void c_test_assert_true(c_test_log* log,char* test_name,const int expression)
{
	struct c_test_node* node = c_test_new_node(test_name,expression != 0);

	c_test_log_add(log,node);
}

void c_test_assert_false(c_test_log* log,char* test_name,const int expression)
{
	struct c_test_node* node = c_test_new_node(test_name,expression == 0);

	c_test_log_add(log,node);
}