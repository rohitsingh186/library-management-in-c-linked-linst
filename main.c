#include "header.h"
main()
{
	/* Declarations Start */
	status_code SC;
	boolean boolval;
	FILE *fp;
	employee_type *emp_ptr,*ptr;
	employee_type *list1,*list2,*list3;
	employee_type *duplicate;
	empname_type *name_ptr,*ptr_name;
	char dumbo[2];
	char emp_name[NAME_LEN];
	char proj_name[NAME_LEN];
	char c;
	unsigned int Hrs;
	unsigned int emp_salary;
	char emp_address[ADD_LEN];
	unsigned long int phone;
	int option,contnue;
	int numRecords,maxNumHrs;
	/* Declarations End */
	/* Initialisations Start */
	emp_ptr=NULL;
	name_ptr=NULL;
	ptr_name=NULL;
	ptr=NULL;
	list1=NULL;
	list2=NULL;
	list3=NULL;
	duplicate=NULL;
	fp=NULL;
	/* Initialisations End */
	/* Start Reading Data from File */
    fp=fopen("record.txt","a");
    fclose(fp);
    fp=fopen("record.txt","r");
    while((c=getc(fp)) != EOF)
    {
		fseek(fp,-sizeof(char),1);
	    fscanf(fp,"%s %s %u %u %s %lu",emp_name,proj_name,&Hrs,&emp_salary,emp_address,&phone);
	    SC=insert(&emp_ptr,emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
	}
	fclose(fp);
	fp=NULL;
	/* End Reading Data from File */
	do
	{
		/* Asking for Option */
		puts("ENTER the option as per the operation you want to do. ENTER :-\n");
		puts("1- insert/update\n2- delete\n3- getNumRecords\n4- isEmpty\n5- List_Unique\n6- getMaxNumHrs\n7- list_union\n8- list_intersection\n9- list_difference\n10- list_symmetric_difference\n");
		printf("Your Choice is:- ");
		scanf("%d",&option);
		printf("\n\n");
		switch (option)
		{
			/* INSERT/UPDATE */
			case 1: {
						    printf("***********INSERT**********\n\n");
						    /* Data Entering Start */
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
							/* Data Entering End */
							/* Inserting/Updating Data */
							SC=insert(&emp_ptr,emp_name,proj_name,Hrs,emp_salary,emp_address,phone);
							if(SC==SUCCESS)
							{
								puts("\n**********Data inserted**********\n");	
							}
							else
							{
								puts("\n**********Data insertion failed**********\n");	
							}
					  		break;
				     }
			/* DELETE */
			case 2:  {
							printf("***********DELETE**********\n\n");
							/* Data Entering Start */
							printf("Enter Employee Name :-\t");
							gets(dumbo);
							gets(emp_name);
							remove_space_make_uppercase(emp_name);
							printf("Enter Employee's Project Name :-\t");
							gets(proj_name);
							remove_space_make_uppercase(proj_name);
							/* Data Entering End */
							/* Deleting Data */
							SC=delete_entry(&emp_ptr,emp_name,proj_name);
							if(SC==SUCCESS)
							{
								puts("\n**********Data deleted**********\n");	
							}
							else
							{
								puts("\n**********Data deletion failed**********\n");	
							}
							break;
					 } 
			/* getNumRecords */  
			case 3:  {
							printf("***********getNumRecords**********\n\n");
							numRecords=getNumRecords(emp_ptr);
							printf("\n\nNumber of ACTIVE record in the list is :-  %d",numRecords);
							break;
					 }
			/* isEmpty */
			case 4:  {
							printf("***********isEmpty**********\n\n");
							boolval=isEmpty(emp_ptr);
							if(boolval==NO)
							{
								puts("The list is NOT EMPTY");	
							}
							else
							{
								puts("The list is EMPTY");	
							}
							break;
					 }
			/* list_unique */
			case 5:  {
							printf("***********list_unique**********\n\n");
							/* Creating Duplicate Entries for Testing */
							duplicate=create_duplicate();
							list_unique(duplicate);
							printf("\n\n*****LIST MADE UNIQUE*****\n\n");
							print(duplicate);
							freeof_employee(&duplicate);
							break;
					 }
			/* getMaxNumHrs */
			case 6:  {
							printf("***********getMaxNumHrs**********\n\n");
							/* Data Entering Start */
							printf("Enter Project Name :-\t");
							gets(dumbo);
							gets(proj_name);
							remove_space_make_uppercase(proj_name);
							/* Data Entering End */
							maxNumHrs=getMaxNumHrs(emp_ptr,proj_name,&name_ptr);
							printf("\nMaximum hours spent in the given project is :-  %d\n\n",maxNumHrs);
							if(maxNumHrs!=0)
							{
								printf("Employee's spending maximum hours in this project are :-\n");
								ptr_name=name_ptr;
								while(ptr_name!=NULL)
								{
									puts(ptr_name->employee_name);
									ptr_name=ptr_name->next;	
								}
							}
							freeof_empname(&name_ptr);
							ptr_name=NULL;
							break;
					 }
			/* list_union */	
	   	    case 7:  {
							printf("***********list_union**********\n\n");
							/* Creating list1 and list2 for Testing */
							puts("*****Creating Testing Entries for list1*****");
							list1=create_checklist();
							puts("*****Creating Testing Entries for list2*****");
							list2=create_checklist();
							list3=list_union(list1,list2);
							printf("\n\n*****UNION of the given lists is as follows*****\n\n");
							print(list3);
							freeof_employee(&list1);
							freeof_employee(&list2);
							freeof_employee(&list3);
							break;
					 }
			/* list_intersection */
			case 8:  {
							printf("***********list_intersection**********\n\n");
							/* Creating list1 and list2 for Testing */
							puts("*****Creating Testing Entries for list1*****");
							list1=create_checklist();
							puts("*****Creating Testing Entries for list2*****");
							list2=create_checklist();
							list3=list_intersection(list1,list2);
							printf("\n\n*****INTERSECTION of the given lists is as follows*****\n\n");
							print(list3);
							freeof_employee(&list1);
							freeof_employee(&list2);
							freeof_employee(&list3);
							break;
					 }
			/* list_difference */
			case 9:  {
							printf("***********list_difference**********\n\n");
							/* Creating list1 and list2 for Testing */
							puts("*****Creating Testing Entries for list1*****");
							list1=create_checklist();
							puts("*****Creating Testing Entries for list2*****");
							list2=create_checklist();
							list3=list_difference(list1,list2);
							printf("\n\n*****DIFFERENCE of the given lists is as follows*****\n\n");
							print(list3);
							freeof_employee(&list1);
							freeof_employee(&list2);
							freeof_employee(&list3);
							break;
					 }
			/* list_symmetric_difference */
			case 10:  {
							printf("***********list_symmetric_difference**********\n\n");
							/* Creating list1 and list2 for Testing */
							puts("*****Creating Testing Entries for list1*****");
							list1=create_checklist();
							puts("*****Creating Testing Entries for list2*****");
							list2=create_checklist();
							list3=list_symmetric_difference(list1,list2);
							printf("\n\n*****SYMMETRIC DIFFERENCE of the given lists is as follows*****\n\n");
							print(list3);
							freeof_employee(&list1);
							freeof_employee(&list2);
							freeof_employee(&list3);
							break;
					 }
			/* Default */
			default: {
							break;
					 }
		}
		/* Asking for CHOICE to Continue */
		puts("\n\nIf you want to continue... ? Enter 1 if YES or 0 if NO\n");
		printf("Your Choice is:- ");
		scanf("%d",&contnue);
		printf("\n\n");
	}while(contnue==1);
	/* Start Writing Data from File */
    fp=fopen("record.txt","w");
    ptr=emp_ptr;
    while(ptr!=NULL)
    {
       fprintf(fp,"%s %s %u %u %s %lu",ptr->employee_name,ptr->project_name,ptr->numHrs,ptr->employee_salary,ptr->employee_address,ptr->phone_number);
       ptr=ptr->next;
    }
    fclose(fp);
    fp=NULL;
    /* End Writing Data from File */
	if(emp_ptr!=NULL)
	{
		print(emp_ptr);
		freeof_employee(&emp_ptr);
	}
	getch();
}
