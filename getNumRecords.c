#include "header.h"
int getNumRecords(employee_type* emp_ptr)
{
	int numRecords=0;
	employee_type *ptr;
	ptr=emp_ptr;
	while(ptr!=NULL)
	{
		if((ptr->employee_name[0]!='\0') && (ptr->project_name[0]!='\0'))	/* ACTIVE Records */
		{
			numRecords++;	
		}	
		ptr=ptr->next;
	}
	return numRecords;
}
