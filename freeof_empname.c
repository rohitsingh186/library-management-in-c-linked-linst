#include "header.h"
/* FREE function for linked-list containing empname-type nodes */
void freeof_empname(empname_type** name_pptr)
{
	empname_type* ptr;
	while(*name_pptr!=NULL)
	{
		ptr=*name_pptr;
		*name_pptr=(*name_pptr)->next;
		free(ptr);
	}
	return;
}
