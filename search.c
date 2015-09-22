#include "header.h"
employee_type* search(employee_type* emp_ptr,char emp_name[],char proj_name[])
{
	employee_type *ptr,*prev,*ret_val;
	int cmp,flag=1;
	ret_val=NULL;
	ptr=emp_ptr;
	prev=NULL;
	if(emp_ptr!=NULL)	/* Non-Empty List */
	{
		cmp=strcmp(emp_name,ptr->employee_name);
		while(cmp>0 && flag==1)    /* Appropriate position according to employee name is not found */
		{
			prev=ptr;
			ptr=ptr->next;
			if(ptr!=NULL)
			{
				cmp=strcmp(emp_name,ptr->employee_name);	
			}	
			else
			{
				flag=0;		/* ptr is NULL */
			}
		}
		if(ptr!=NULL)	/* list is not fully traversed */
		{
			cmp=strcmp(proj_name,ptr->project_name);	
		}	
		while(cmp>0 && flag==1)		/* Appropriate position according to project name is not found */
		{
			prev=ptr;
			ptr=ptr->next;
			if(ptr==NULL)
			{
				flag=0;	
			}		
			else
			{
				if(strcmp(emp_name,ptr->employee_name)==0)	
				{
					cmp=strcmp(proj_name,ptr->project_name);		
				}
				else
				{
					flag=0;		/* ptr is NULL */
				}
			}
		}
		if(ptr!=NULL)
		{
			if((strcmp(ptr->employee_name,emp_name)==0) && (strcmp(ptr->project_name,proj_name)==0))	/* Exact match found */
			{
				ret_val=ptr;	
			}
			else	/* Appropriate place found */
			{
				ret_val=prev;
			}
	    }
	    else
	    {
			ret_val=prev;	/* Appropriate place found */	
		}
	}
	return ret_val;
}
