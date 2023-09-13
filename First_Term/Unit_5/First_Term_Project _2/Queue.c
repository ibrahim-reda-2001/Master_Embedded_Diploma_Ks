#include "Queue.h"

Queue_status Queue_init(Queue_Buf_t* Queue ,element_type *buf , uint32_t length ){
	if(buf==NULL){
		return Queue_null;}
	else{
		Queue->base=buf;
		Queue->count=0;
		Queue->head=buf;
		Queue->tail=buf;
		Queue->length=length;
		return Queue_no_errors;}
}
Queue_status Queue_enqueue(Queue_Buf_t* Queue ,element_type *item  ){
	if(Queue_check(Queue)==Queue_null){
		return Queue_null;}
	if(Queue_check(Queue)==Queue_full){
		return Queue_full;}
	*(Queue->head)=*item;
	Queue->count++;
	//circuler Queue u can't overwrite
	if(Queue->head==(Queue->base+sizeof(element_type)*Queue->length)){
		Queue->head=Queue->base;
	}
	else{
		Queue->head++;
	}

	return Queue_no_errors;
}
Queue_status Queue_dequeue(Queue_Buf_t* Queue ,element_type* item  ){
	if(Queue_check(Queue)==Queue_null){
		return Queue_null;}
	//check empty
	if(Queue->count==0)
		return Queue_empty;
	//tail still in base at first because first in first out
	*item =*(Queue->tail);
	Queue->count--;
	if(Queue->tail==(Queue->base+sizeof(element_type)*Queue->length)){
		Queue->tail=Queue->base;
	}
	else{
		Queue->tail++;
	}
	return Queue_no_errors;
}
Queue_status Queue_check(Queue_Buf_t* Queue){
	if(!Queue->base||!Queue->head||!Queue->tail){
		return Queue_null;}
	if(Queue->count==Queue->length){
		return Queue_full;}
	if(Queue->count==0){
		return Queue_empty;
	}
	return Queue_no_errors;
}
/*void Queue_print(Queue_Buf_t* Queue){
	element_type *temp;
	int i=0;
	if(Queue->count==0){
		DPRINTF("Queue is empty\n");
	}
	else{
		temp=Queue->tail;
		DPRINTF("\n=======Queue_print========\n");
		for(i=0;i<Queue->count;i++){
			DPRINTF("\t %x \n",*temp);
			temp++;
		}
		DPRINTF("============\n");
	}

}*/
Queue_status check_Id(Queue_Buf_t* my_Queue, unsigned int ID){
	Queue_status x =OK;
	Sstudent *sptr=my_Queue->tail;

	for(int i=0;i< my_Queue->count ;i++){//for loop to check every id in database
		if(ID==sptr->student_id){
			x=	NOK;
		}
		if(sptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
			sptr=my_Queue->base;
		}
		else{
			sptr++;
		}

	}
	return x;
}
/*void add_student_from_file(Queue_Buf_t* my_Queue){
	FILE *fptr;
	char ch[300];
	fptr=fopen("filename","r");
	//check if file opened successfully
	if(fptr==NULL){
		DDPRINTF("the file is not opened\n");
		exit(0);
	}
	else {
		while (fgets(ch,300,fptr)!=NULL)//fgets reads a text line or a string from the specified file.
{
Sstudent student;
fscanf(fptr,"%s %s %d %f %d  %d  %d  %d  %d ",student.Fname,student.Lname,&student.id,&student.GPA,&student.course_ID[0],
&student.course_ID[1],&student.course_ID[2],&student.course_ID[3],&student.course_ID[4]);
Queue_status status=check_Id(my_Queue,student.id);
if(status==OK){
	DDPRINTF(" *****Error : id exist ***************\n");
}
else{
	Queue_status x =Queue_check(my_Queue);
	if(x==Queue_null||x==Queue_full){
		DDPRINTF("Error to add student\n");
	}
	else{
		DDPRINTF("the student add successfully\n")
	}
}
fclose(fptr);
}
	}
}*/
void add_student_manually(Queue_Buf_t* my_Queue){

	char temp_text[10];
	Sstudent new_student;
	DPRINTF("Enter student id : \n");
	gets(temp_text);
	new_student.student_id=atoi(temp_text);
	DPRINTF("Enter student GPA : \n");
	gets(temp_text);
	new_student.GPA=atof(temp_text);
	DPRINTF("Enter student first_name : \n");
	gets(new_student.Fname);
	DPRINTF("Enter student Last_name : \n");
	gets(new_student.Lname);
	for (int i=0;i<courses_number;i++){
		DPRINTF(" Course %d ID ",i+1);
		gets(temp_text);
		new_student.course_ID[i]=atoi(temp_text);
	}
	Queue_status ret_ID=check_Id(my_Queue,new_student.student_id);
	if(ret_ID==NOK){
		DPRINTF("[Error] Id already exist\n");
		return;
	}
	Queue_status ret_status =Queue_enqueue(my_Queue,&new_student);


	if(ret_status==Queue_no_errors){
		DPRINTF("Student added successfully \n");
	}
	else{
		DPRINTF("/********Error************\n");

	}


}
void find_id(Queue_Buf_t* my_Queue){
	if(Queue_check(my_Queue)==Queue_no_errors||Queue_check(my_Queue)==Queue_empty){
			int id;
			char temp_text[10];
			DPRINTF("Enter the ID \n");
			gets(temp_text);
			id=atoi(temp_text);
			Sstudent *sptr=my_Queue->tail;
			for (int i=0;i<my_Queue->length;i++){
				if (id==sptr->student_id){
					DPRINTF("the first name is %s and the last is %s \n",sptr->Fname,sptr->Lname);
					DPRINTF("the ID is %d\n",sptr->student_id);
					DPRINTF("the GPA is %.2f\n",sptr->GPA)
					for (int i=0;i<courses_number;i++){
						DPRINTF("the course number %d ID is %d\n",i+1,sptr->course_ID[i])
					}
					DPRINTF("***************************\n")
					return;

				}
				else {
					DPRINTF("the id not found \n");
					break;
				}
			}

		}
		else if(Queue_check(my_Queue)==Queue_full){
			DPRINTF("The Queue is full\n");
		}
		else if(Queue_check(my_Queue)==Queue_null){
			DPRINTF("The Queue is null\n");

		}
}
void find_by_first_name(Queue_Buf_t* my_Queue){
	char name[20];
	DPRINTF("Enter first name \n");
	gets(name);
	Sstudent *ptr=my_Queue->tail;
	for(int i=0;i<my_Queue->length;i++){
		//strcasecmp this function return 0 when equal
		if(!strcasecmp(ptr->Fname,name)){
			DPRINTF("the first name is %s and the last is %s \n",ptr->Fname,ptr->Lname);
			DPRINTF("the ID is %d\n",ptr->student_id);
			DPRINTF("the GPA is %.2f\n",ptr->GPA)
			for (int i=0;i<courses_number;i++){
				DPRINTF("\n the course number %d ID is %d",i+1,ptr->course_ID[i])
			}
			DPRINTF("\n**********************************\n");

			return ;//to exist all function
			//if it is break it will print "the name not found" after print information
		}
		if(ptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
			ptr=my_Queue->base;
		}
		else{
			ptr++;
		}

	}
	DPRINTF("the name not found \n");
}
void find_by_last_name(Queue_Buf_t* my_Queue){
	char name[20];
		DPRINTF("Enter last name \n");
		gets(name);
		Sstudent *ptr=my_Queue->tail;
		for(int i=0;i<my_Queue->length;i++){
			//strcasecmp this function return 0 when equal
			if(!strcasecmp(ptr->Lname,name)){
				DPRINTF("the first name is %s and the last is %s \n",ptr->Fname,ptr->Lname);
				DPRINTF("the ID is %d\n",ptr->student_id);
				DPRINTF("the GPA is %.2f\n",ptr->GPA)
				for (int i=0;i<courses_number;i++){
					DPRINTF("\n the course number %d ID is %d",i+1,ptr->course_ID[i])
				}
				DPRINTF("\n**********************************\n");

				return ;//to exist all function
				//if it is break it will print "the name not found" after print information
			}
			if(ptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
				ptr=my_Queue->base;
			}
			else{
				ptr++;
			}

		}
		DPRINTF("the name not found \n");
}
void find_course_ID(Queue_Buf_t* my_Queue){
	char text_temp[20];
	int course_id;
		DPRINTF("Enter the course ID \n");
		gets(text_temp);
		course_id=atoi(text_temp);
		Sstudent *sptr=my_Queue->tail;
		for(int i=0;i<my_Queue->length;i++){
			//strcasecmp this function return 0 when equal
			for(int j=0;j<courses_number;j++){
				if(sptr->course_ID[j]==course_id){
				DPRINTF("the first name is %s and the last is %s \n",sptr->Fname,sptr->Lname);
				DPRINTF("the ID is %d\n",sptr->student_id);
				DPRINTF("the GPA is %.2f\n",sptr->GPA)
				for (int i=0;i<courses_number;i++){
					DPRINTF("\n the course number %d ID is %d",i+1,sptr->course_ID[i])
				}
				DPRINTF("\n**********************************\n");

				//break ;//to exist all function
				//if it is break it will print "the name not found" after print information
				}
			}
			if(sptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
				sptr=my_Queue->base;
			}
			else{
				sptr++;
			}

		}
}
void total_student(Queue_Buf_t* my_Queue){
	DPRINTF("The total number of students is added  %d\n",my_Queue->count);
	DPRINTF("you can add till %d students \n",number_of_students);
DPRINTF("you can add now  %d  students\n",number_of_students-my_Queue->count);
}
void delet_student(Queue_Buf_t* my_Queue){
char text_temp[20];
int i,id_delete;
DPRINTF("Enter the ID of student you want delete \n");
gets(text_temp);
id_delete=atoi(text_temp);
Sstudent *sptr=my_Queue->base;
for(i=0;i<my_Queue->count;i++){
	if(sptr->student_id==id_delete){
		break;
	}
	else{
		sptr++;
	}
	if(i<my_Queue->count){
		for (int j = 0; j < my_Queue->count; j++, i++) {
					my_Queue->base[i] = my_Queue->base[i + 1];
				}
				my_Queue->head--;
				my_Queue->count--;
	}
	else{
		DPRINTF("The ID not found \n")
	}

}

}
void update_student(Queue_Buf_t* my_Queue){
	int id;
	char temp_text[5],temp_text2[5];

	DPRINTF("Enter the ID \n");
	gets(temp_text);
	id=atoi(temp_text);
	Sstudent *sptr=my_Queue->tail;
	for (int i=0;i<my_Queue->length;i++){
		if (id ==sptr->student_id){
			DPRINTF("Enter 1 to modify first and last name\n .Enter 2 to modify ID \n .Enter 3 to modify GPA \n. Enter 4 to modify courses ID \n");
			gets (temp_text2);
			int switch_case=atoi(temp_text2);
			switch(switch_case){
			case 1:
				DPRINTF("Enter the new first name \n");
				gets(sptr->Fname);
				DPRINTF("Enter the new last name \n");
				gets(sptr->Lname);
				break;
			case 2:
				DPRINTF("Enter the new ID  \n");
				scanf("%d",&(sptr->student_id));
				break;
			case 3:
				DPRINTF("Enter the new GPA  \n");
								scanf("%f",&(sptr->GPA));
				break;
			case 4:
				DPRINTF("Enter the new ID of each course\n ");
				for(int i=0;i<courses_number;i++){
					DPRINTF("The course ID %d \n",i+1);
					scanf("%d",&sptr->course_ID[i]);
				}
				break;
			}

return;
		}

		if(sptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
						sptr=my_Queue->base;
					}
					else{
						sptr++;
					}
	}
	DPRINTF("The ID you enter not found \n");
}
void show_all_information(Queue_Buf_t* my_Queue){
if(Queue_check(my_Queue)==Queue_no_errors){
Sstudent *sptr;
sptr=my_Queue->tail;
for(int i=0;i<my_Queue->count;i++){
DPRINTF("the first name is %s and the last is %s \n",sptr->Fname,sptr->Lname);
DPRINTF("the ID is %d\n",sptr->student_id);
DPRINTF("the GPA is %.2f\n",sptr->GPA)
for (int i=0;i<courses_number;i++){
DPRINTF("the course number %d ID is %d\n",i+1,sptr->course_ID[i])
}
DPRINTF("******************************\n");
if(sptr==(my_Queue->base+sizeof(element_type)*my_Queue->length)){
			sptr=my_Queue->base;
		}
		else{
			sptr++;
		}

}
DPRINTF("\n");

}
else if(Queue_check(my_Queue)==Queue_empty){
DPRINTF("The Queue is empty\n");
}
else if(Queue_check(my_Queue)==Queue_null){
DPRINTF("The Queue is null\n");

}
}
