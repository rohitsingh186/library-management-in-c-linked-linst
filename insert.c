#include "header.h"
status_code insert(employee_type **emp_pptr,char emp_name[],char proj_name[],unsigned int Hrs,unsigned int emp_salary,char emp_address[],unsigned long int phone)
{
	status_code SC=SUCCESS;
	employee_type *ptr,*nptr;
	if(*emp_pptr==NULL)	/* Empty List */
	{
		nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
		if(nptr==NULL)
		{
			SC=FAILURE;	/* Failure */
		}	
		else
		{
			*emp_pptr=nptr;
		}
	}
	else	/* Non-Empty List */
	{
		ptr=search(*emp_pptr,emp_name,proj_name);	/* Searching for given Key */
		if(ptr==NULL)	/* Insert at Start */
		{
			nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
			if(nptr==NULL)
			{
				SC=FAILURE;	/* Failure */
			}	
			else
			{
				nptr->next=*emp_pptr;
				*emp_pptr=nptr;
			}
		}
		else
		{
			if((strcmp(ptr->employee_name,emp_name)==0) && (strcmp(ptr->project_name,proj_name)==0))	/* Exact match found. UPDATE */
			{
				ptr->numHrs=Hrs;
				ptr->employee_salary=emp_salary;
				strcpy(ptr->employee_address,emp_address);
				ptr->phone_number=phone;	
			}	
			else	/* Exact match not found. Appropriate position found */
			{
				nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
				if(nptr==NULL)
				{
					SC=FAILURE;	/* Failure */
				}	
				else
				{
					nptr->next=ptr->next;
					ptr->next=nptr;	
				}
			}
		}
	}
	return SC;
}
