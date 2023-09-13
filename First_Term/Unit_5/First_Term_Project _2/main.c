#include "Queue.h"


int main(){
	Queue_Buf_t MYQueue;
element_type students[55];
Queue_init(&MYQueue,students,55);
char temp_text[20];
DPRINTF("\t\tStudents Management System\n");

while(1){
	DPRINTF("\n\t Choose one of the following options: \n");
	DPRINTF(" 1: Add student\n ");
	DPRINTF("2: Search for student by ID\n ");
	DPRINTF("3: Search for student by first name\n ");
	DPRINTF("4: Search for student by last name\n ");
	DPRINTF("5: Search for student by course id\n ");
	DPRINTF("6: Find total number of students\n ");
	DPRINTF("7: Delete student recorded\n ");
	DPRINTF("8: Update student\n ");
	DPRINTF("9: Show all information\n ");
	gets(temp_text);

switch(atoi(temp_text)){
case 1:add_student_manually(&MYQueue);break;
case 2:find_id(&MYQueue);break;
case 3:find_by_first_name(&MYQueue); break;
case 4:find_by_last_name(&MYQueue); break;
case 5:find_course_ID(&MYQueue); break;
case 6:total_student(&MYQueue); break;
case 7:delet_student(&MYQueue); break;
case 8:update_student(&MYQueue); break;
case 9:show_all_information(&MYQueue); break;

}


}
	return 0;
}
