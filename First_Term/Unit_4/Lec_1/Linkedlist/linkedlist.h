

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<stdio.h>
#include <stdlib.h>
#include<string.h>


#define DPRINTF(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}

//effective data
typedef struct {
	char name[40];
	int id;
	float height;
}SData;
//create a node
struct SStudent{
	SData student;
	struct SStudent* PNextStudent;
};
struct SStudent* gpfirststudent;
void Fill_Record();
void Add_Student();
int Delete_Student();
void view_students();
void DeleteAll();
int Search ();
void Count();
int Node_from_the_end();
void Mid();
void Reverse();


#endif /* LINKEDLIST_H_ */
