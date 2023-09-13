
#ifndef Queue_H_
#define Queue_H_
#include <stdio.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
// select element type (uint8_t,uint16_t,uint32_t,.....
//default 1 byte
#define element_type  Sstudent
//solve printf problem
#define DPRINTF(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}

//student data
typedef struct {
	char Fname[20];
	char Lname[20];
	float GPA;
	int student_id;
	unsigned int course_ID[10];


}Sstudent;
#define courses_number   4
#define number_of_students 55
//Queue data types
typedef struct {
	unsigned int length;
	element_type* base;
	element_type* head;
	unsigned int count;
	element_type *tail;

}Queue_Buf_t;


typedef enum {
	Queue_no_errors,
	Queue_full,
	Queue_empty,
	Queue_null,
	Queue_not_empty,
	OK,
	NOK
}Queue_status;

//APIS
Queue_status Queue_init(Queue_Buf_t* Queue ,element_type *buf , uint32_t length );
Queue_status Queue_enqueue(Queue_Buf_t* Queue ,element_type *item  );
Queue_status Queue_dequeue(Queue_Buf_t* Queue ,element_type* item  );
Queue_status Queue_check(Queue_Buf_t* Queue);
Queue_status check_Id(Queue_Buf_t* my_Queue, unsigned int ID);
//void Queue_print(Queue_Buf_t* Queue);
void add_student_from_file(Queue_Buf_t* my_Queue);
void add_student_manually(Queue_Buf_t* my_Queue);
void find_id(Queue_Buf_t* my_Queue);
void find_by_first_name(Queue_Buf_t* my_Queue);
void find_by_last_name(Queue_Buf_t* my_Queue);
void find_course_ID(Queue_Buf_t* my_Queue);
void total_student(Queue_Buf_t* my_Queue);
void delet_student(Queue_Buf_t* my_Queue);
void update_student(Queue_Buf_t* my_Queue);
void show_all_information(Queue_Buf_t* my_Queue);


#endif /* Queue_H_ */
