#include "header.h"
/* Creating nodes of empname-type */
empname_type* create_node(char emp_name[])
{
	empname_type* nptr;
	nptr=(empname_type*)malloc(sizeof(empname_type));
	if(nptr!=NULL)
	{
		strcpy(nptr->employee_name,emp_name);
		nptr->next=NULL;	
	}
	return nptr;
}
