#include "header.h"
employee_type* list_symmetric_difference(employee_type* list1,employee_type* list2)
{
	employee_type *list3,*ptr1,*ptr2,*ptr3,*nptr;
	list3=NULL;
	ptr3=list3;
	ptr1=list1;
	ptr2=list2;
	while(ptr1!=NULL && ptr2!=NULL)		/* Both lists are non-empty */
	{
		if(strcmp(ptr1->employee_name,ptr2->employee_name)>0)	/* list2's element is taken in list3 */
		{
			nptr=make_node(ptr2->employee_name,ptr2->project_name,ptr2->numHrs,ptr2->employee_salary,ptr2->employee_address,ptr2->phone_number);
			if(list3==NULL)
			{
				list3=nptr;
			}
			else
			{
				ptr3->next=nptr;
			}
			ptr2=ptr2->next;
			ptr3=nptr;
		}	
		else if(strcmp(ptr1->employee_name,ptr2->employee_name)<0)		/* list1's element is taken in list3 */
		{
			nptr=make_node(ptr1->employee_name,ptr1->project_name,ptr1->numHrs,ptr1->employee_salary,ptr1->employee_address,ptr1->phone_number);
			if(list3==NULL)
			{
				list3=nptr;	
			}
			else
			{
				ptr3->next=nptr;
			}
			ptr1=ptr1->next;	
			ptr3=nptr;	
		}
		else	/* Employee name of ptr1 and ptr2 are same */
		{
			if(strcmp(ptr1->project_name,ptr2->project_name)>0)		/* list2's element is taken in list3 */
			{
				nptr=make_node(ptr2->employee_name,ptr2->project_name,ptr2->numHrs,ptr2->employee_salary,ptr2->employee_address,ptr2->phone_number);
				if(list3==NULL)
				{
					list3=nptr;	
				}
				else
				{
					ptr3->next=nptr;
				}
				ptr2=ptr2->next;
				ptr3=nptr;
			}	
			else if(strcmp(ptr1->project_name,ptr2->project_name)<0)	/* list1's element is taken in list3 */
			{
				nptr=make_node(ptr1->employee_name,ptr1->project_name,ptr1->numHrs,ptr1->employee_salary,ptr1->employee_address,ptr1->phone_number);
				if(list3==NULL)
				{
					list3=nptr;	
				}
				else
				{
					ptr3->next=nptr;
				}
				ptr1=ptr1->next;	
				ptr3=nptr;	
			}	
			else		/* Project name of ptr1 and ptr2 are also same */
			{
				ptr1=ptr1->next;
				ptr2=ptr2->next;	
			}
		}
	}
	while(ptr1!=NULL)	/* if ptr2 is NULL but ptr1 not */
	{
		nptr=make_node(ptr1->employee_name,ptr1->project_name,ptr1->numHrs,ptr1->employee_salary,ptr1->employee_address,ptr1->phone_number);
		if(list3==NULL)
		{
			list3=nptr;	
		}
		else
		{
			ptr3->next=nptr;
		}
		ptr1=ptr1->next;
		ptr3=nptr;	
	}
	while(ptr2!=NULL)	/* if ptr1 is NULL but ptr2 not */
	{
		nptr=make_node(ptr2->employee_name,ptr2->project_name,ptr2->numHrs,ptr2->employee_salary,ptr2->employee_address,ptr2->phone_number);
		if(list3==NULL)
		{
			list3=nptr;
		}
		else
		{
			ptr3->next=nptr;
		}
		ptr2=ptr2->next;
		ptr3=nptr;
	}
	return list3;
}
