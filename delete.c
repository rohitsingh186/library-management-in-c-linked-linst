#include "header.h"
status_code delete_entry(employee_type **emp_pptr,char emp_name[],char proj_name[])
{
	status_code SC=SUCCESS;
	employee_type *ptr,*lptr;
	if(*emp_pptr==NULL)	/* Empty List */
	{
		SC=FAILURE;
	}
	else
	{
		ptr=search(*emp_pptr,emp_name,proj_name);	/* Searching for given Key */
		if(ptr==NULL)	/* Not Found */
		{
			SC=FAILURE;	
		}
		else
		{
			if((strcmp(ptr->employee_name,emp_name)==0) && (strcmp(ptr->project_name,proj_name)==0))	/* Exact match found */
			{
				if(ptr==*emp_pptr)	/* Key is present in first node only */
				{
					(*emp_pptr)=(*emp_pptr)->next;
					free(ptr);	
				}
				else	/* Key is present in other than first node */
				{
					lptr=*emp_pptr;
					while(lptr->next!=ptr)
					{
						lptr=lptr->next;
					}		
					lptr->next=ptr->next;
					free(ptr);
				}
			}	
			else	/* Not Found */
			{
				SC=FAILURE;
			}
		}
	}
	return SC;
}
