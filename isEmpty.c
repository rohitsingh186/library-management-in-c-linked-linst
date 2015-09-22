#include "header.h"
boolean isEmpty(employee_type* emp_ptr)
{
	boolean boolret;
	boolret=NO;
	if(emp_ptr==NULL)
	{
		boolret=YES;	
	}
	return boolret;
}
