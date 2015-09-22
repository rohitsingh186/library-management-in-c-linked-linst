#include "header.h"
/* FREE function for linked-list containing employee-type nodes */
void freeof_employee(employee_type** emp_pptr)
{
	employee_type* ptr;
	while(*emp_pptr!=NULL)
	{
		ptr=*emp_pptr;
		*emp_pptr=(*emp_pptr)->next;
		free(ptr);	
	}
	return;
}
