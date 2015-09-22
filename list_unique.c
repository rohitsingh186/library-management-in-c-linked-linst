#include "header.h"
/* ASSUMING THE GIVEN LIST AS SORTED */
void list_unique(employee_type *emp_ptr)
{
	employee_type *prev,*ptr;
	prev=NULL;
	ptr=NULL;
	if(emp_ptr!=NULL)
	{
		prev=emp_ptr;
		ptr=prev->next;	
	}
	while(prev!=NULL && ptr!=NULL)
	{
		if(strcmp(prev->employee_name,ptr->employee_name)==0)
		{
			if(strcmp(prev->project_name,ptr->project_name)==0)		/* Key Matched */
			{
				prev->next=ptr->next;
				free(ptr);
				ptr=prev->next;	
			}	
		}	
		else	/* Key didn't Match */
		{
			prev=ptr;
			ptr=ptr->next;	
		}
	}
	return;
}
