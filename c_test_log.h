#include <stdlib.h>

typedef struct {
	struct c_test_node* head;
	struct c_test_node* last;
} c_test_log;

struct c_test_node{
	char* name;
	int result;
	struct c_test_node* next;
};

void c_test_log_clear(c_test_log* log)
{
	struct c_test_node* current = log->head;
	
	while(current){
		
		struct c_test_node* next = current->next;
		
		free(current->name);
		free(current);
		
		current = next;
	}
}

struct c_test_node* c_test_new_node(char* test_name,const int result)
{
	struct c_test_node* new_node = malloc(sizeof(struct c_test_node));

	new_node->name = test_name;
	new_node->result = result;

	return new_node;
}

c_test_log* c_test_new_log()
{
	c_test_log* new_log = malloc(sizeof(c_test_log));
	
	new_log->head = NULL;
	new_log->last = NULL;
	
	return new_log;
}

void c_test_log_add(c_test_log* log,struct c_test_node* node)
{
	if(log->head){
		
		log->last->next = node;
		log->last = node;

	}else{

		log->head = node;
		log->last = node;
		
	}
}