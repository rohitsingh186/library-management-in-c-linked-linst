#include "header.h"
/* Creating nodes of employee-type */
employee_type* make_node(char emp_name[],char proj_name[],unsigned int Hrs,unsigned int emp_salary,char emp_address[],unsigned long int phone)
{
	employee_type *ptr;
	ptr=NULL;
	ptr=(employee_type*)malloc(sizeof(employee_type));		/* Creating Node */
	if(ptr!=NULL)		/* Assigning Values */
	{
		strcpy(ptr->employee_name,emp_name);
		strcpy(ptr->project_name,proj_name);
		ptr->numHrs=Hrs;
		ptr->employee_salary=emp_salary;
		strcpy(ptr->employee_address,emp_address);
		ptr->phone_number=phone;
		ptr->next=NULL;
    }
    return ptr;
}
