#include "header.h"
employee_type* create_checklist(void)
{
	/*Declarations*/
	employee_type *ptr,*nptr,*ret_ptr;
	char dumbo[2];
	char emp_name[NAME_LEN];
	char proj_name[NAME_LEN];
	unsigned int Hrs;
	unsigned int emp_salary;
	char emp_address[ADD_LEN];
	unsigned long int phone;
	int choice;
	/*Declarations End*/
	/*Initializations*/
	ptr=NULL;
	nptr=NULL;
	ret_ptr=NULL;
	choice=0;
	/*Initializations*/
	/*Creating Linked List with duplicate entries*/
	do
	{
		printf("Enter Employee Name :-\t");
		gets(dumbo);
		gets(emp_name);
		remove_space_make_uppercase(emp_name);
		printf("Enter Employee's Project Name :-\t");
		gets(proj_name);
		remove_space_make_uppercase(proj_name);
		printf("Enter Number of Hours :-\t");
		scanf("%u",&Hrs);
		printf("Enter Employee's Salary :-\t");
		scanf("%u",&emp_salary);
		printf("Enter Employee's Address :-\t");
		gets(dumbo);
		gets(emp_address);
		remove_space_make_uppercase(emp_address);
		printf("Enter Employee's Phone Number :-\t");
		scanf("%lu",&phone);
		if(ret_ptr==NULL)	/*Empty List*/
		{
			nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
			if(nptr!=NULL)
			{
				ret_ptr=nptr;
			}
		}
		else	/*Non-Empty List*/
		{
			ptr=search(ret_ptr,emp_name,proj_name);	/*Searching for given Key*/
			if(ptr==NULL)	/*Insert at Start*/
			{
				nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
				if(nptr!=NULL)
				{
					nptr->next=ret_ptr;
					ret_ptr=nptr;
				}
			}
			else
			{
				if((strcmp(ptr->employee_name,emp_name)==0) && (strcmp(ptr->project_name,proj_name)==0))	/*Exact match found. UPDATE*/
				{
					ptr->numHrs=Hrs;
					ptr->employee_salary=emp_salary;
					strcpy(ptr->employee_address,emp_address);
					ptr->phone_number=phone;	
				}	
				else	/*Exact match not found. Appropriate position found*/
				{
					nptr=make_node(emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
					if(nptr!=NULL)
					{
						nptr->next=ptr->next;
						ptr->next=nptr;	
					}
				}
			}
		}
		printf("\n\nIf you want to enter more data. Enter 1 if YES or 0 if NO\nYour Choice :-  ");
		scanf("%d",&choice);
	}while(choice==1);
	printf("*****Testing Entries Are*****");
	print(ret_ptr);
	return ret_ptr;
}
