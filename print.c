#include "header.h"
void print(employee_type* emp_ptr)
{
	employee_type* ptr;
	ptr=emp_ptr;
	printf("\n\n**********PRINTING START**********\n\n");
	while(ptr!=NULL)	/* Printing */
	{
		printf("Employee Name :-\t");
		puts(ptr->employee_name);
		printf("Employee's Project :-\t");
		puts(ptr->project_name);
		printf("Number of Hours :-\t");
		printf("%u\n",ptr->numHrs);
		printf("Employee's Salary :-\t");
		printf("%u\n",ptr->employee_salary);
		printf("Employee's Address :-\t");
		puts(ptr->employee_address);
		printf("Employee's Phone Number :-\t");
		printf("%lu\n\n",ptr->phone_number);
		ptr=ptr->next;
	}
	printf("\n\n**********PRINTING END**********\n\n");
	return;	
}
