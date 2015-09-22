#include "header.h"
int getMaxNumHrs(employee_type* emp_ptr,char proj_name[],empname_type** name_pptr)
{
	/* Declarations */
	employee_type *ptr;
	empname_type *nptr,*last_ptr,*lptr;
	/* Initializations */
	nptr=NULL;
	ptr=NULL;
	last_ptr=NULL;
	lptr=NULL;
	int maxNumHrs=0;
	if(emp_ptr!=NULL)
	{
		ptr=emp_ptr;
		while(ptr!=NULL)
		{
			if(strcmp(proj_name,ptr->project_name)==0)	/* Project name Matched */
			{
				if((ptr->numHrs)>maxNumHrs)	/* New maxNumHrs */
				{
					maxNumHrs=ptr->numHrs;
					nptr=create_node(ptr->employee_name);
					lptr=*name_pptr;
					freeof_empname(&lptr);
					*name_pptr=nptr;
					last_ptr=nptr;
				}
				else if((ptr->numHrs)==maxNumHrs)		/* Same maxNumHrs. Addition of new node in the same list */
				{
					nptr=create_node(ptr->employee_name);
					last_ptr->next=nptr;
					last_ptr=nptr;
				}
			}
			ptr=ptr->next;
		}	
	}
	return maxNumHrs;
}
