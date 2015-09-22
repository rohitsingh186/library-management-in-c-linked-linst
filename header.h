#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define NAME_LEN 32
#define ADD_LEN 64

typedef enum status{FAILURE,SUCCESS}status_code;

/* Defining Data Types */
typedef struct employee_tag
{
	char employee_name[NAME_LEN];
	char project_name[NAME_LEN];
	unsigned int numHrs;
	unsigned int employee_salary;
	char employee_address[ADD_LEN];
	unsigned long int phone_number;
	struct employee_tag* next;
}employee_type;

typedef struct empname_tag
{
	char employee_name[NAME_LEN];
	struct empname_tag* next;
}empname_type;

typedef enum tag{NO,YES}boolean;

/* Main Functions */
status_code insert(employee_type **,char [],char [],unsigned int,unsigned int,char [],unsigned long int);

status_code delete_entry(employee_type**,char [],char []);

int getNumRecords(employee_type*);

boolean isEmpty(employee_type*);

void list_unique(employee_type*);

int getMaxNumHrs(employee_type*,char [],empname_type**);

employee_type* list_union(employee_type*,employee_type*);

employee_type* list_intersection(employee_type*,employee_type*);

employee_type* list_difference(employee_type*,employee_type*);

employee_type* list_symmetric_difference(employee_type*,employee_type*);

/* Auxilliary Functions */
employee_type* make_node(char [],char [],unsigned int,unsigned int,char [],unsigned long int);

void print(employee_type*);

void freeof_employee(employee_type**);

void freeof_empname(empname_type**);

void remove_space_make_uppercase(char []);

empname_type* create_node(char []);

employee_type* search(employee_type*,char [],char []);

employee_type* create_duplicate(void);

employee_type* create_checklist(void);

#endif
