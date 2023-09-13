#include"linkedlist.h"

void Fill_Record(struct SStudent* new_student ){
	char temp_text[20];
	DPRINTF("\nEnter ID : ");
	gets(temp_text);
	new_student->student.id=atoi(temp_text);
	DPRINTF("\nEnter Student full name  ");
	gets(new_student->student.name);
	DPRINTF("\nEnter height ");
	gets(temp_text);
	new_student->student.height=atof(temp_text);
}
void Add_Student(){
	struct SStudent* PNewstudent;
	struct SStudent* PLastStudent;
	if(gpfirststudent==NULL){ //if it is empty
		PNewstudent=(struct SStudent*)malloc(sizeof(struct SStudent)); //reserve at runtime
		//assign gpfirststudent to it
		gpfirststudent=PNewstudent;
	}
	else{ //if list contain recored
		//navigate till reach to last one
		PLastStudent=gpfirststudent;
		while(PLastStudent->PNextStudent){
			PLastStudent=PLastStudent->PNextStudent;}
		PNewstudent=(struct SStudent*)malloc(sizeof(struct SStudent));
		PLastStudent->PNextStudent=PNewstudent;

	}
	//fill new recored
	Fill_Record(PNewstudent);
	//make next point to null
	PNewstudent->PNextStudent=NULL;
}
void view_students(){
	struct SStudent* PCurrent_Student=gpfirststudent;
	int count =0;
	if(PCurrent_Student==NULL){
		DPRINTF("\nthe linked is empty ");
	}
	else{

		while(PCurrent_Student){

			DPRINTF("\n Recored number is : %d ",count+1);
			DPRINTF("\n ID is : %d ",PCurrent_Student->student.id);
			DPRINTF("\n Name is : %s ",PCurrent_Student->student.name);
			DPRINTF("\n Height is : %.2f ",PCurrent_Student->student.height );

			PCurrent_Student=PCurrent_Student->PNextStudent;
			count++;


		}
	}
}
void DeleteAll(){
	struct SStudent* PCurrent_Student=gpfirststudent;
	if(PCurrent_Student==NULL){
		DPRINTF("\nthe linked is empty ");
	}
	else{

		while(PCurrent_Student){
			struct SStudent* PTemp=PCurrent_Student;
			PCurrent_Student=PCurrent_Student->PNextStudent;
			free(PTemp);
		}
		gpfirststudent=NULL;
	}

}
int Delete_Student()
{
	//struct SStudent* gpFirstStudent=NULL ;

	char temp_text[40];
	unsigned int selected_id;

	//get the selected id
	DPRINTF("\n enter the student id to be deleted :");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//list is not empty
	if (gpfirststudent)
	{
		struct SStudent* pSlectedStudent =gpfirststudent ;
		struct SStudent* pPreviousStudent = NULL ;

		//loop on all records
		while(pSlectedStudent)
		{
			//compare each node with the selected ID
			if(pSlectedStudent->student.id==selected_id)
			{
				if(pPreviousStudent) // the first student is not the selected one
				{
					pPreviousStudent->PNextStudent = pSlectedStudent->PNextStudent ;
				}
				else //1st student == ID
				{
					gpfirststudent=pSlectedStudent->PNextStudent;
				}
				free(pSlectedStudent);
				return 1;
			}
			pPreviousStudent = pSlectedStudent ;
			pSlectedStudent = pSlectedStudent->PNextStudent;

		}
	}
	DPRINTF("\n Cannot find student ID.");
	return 0;
}
int Search (){
	struct SStudent* PCurrent_Student=gpfirststudent;
	char temp_text[10];
	int search,count=0;
	if(gpfirststudent==(void*)0){
		DPRINTF("\nLinekedlist is empty");
	}
	else{
		DPRINTF("\nEnter the index");
		gets(temp_text);
		search=atoi(temp_text);
		while(PCurrent_Student){
			if(search==count+1){
				DPRINTF("\n Recored number is : %d ",count+1);
				DPRINTF("\n ID is : %d ",PCurrent_Student->student.id);
				DPRINTF("\n Name is : %s ",PCurrent_Student->student.name);
				DPRINTF("\n Height is : %.2f ",PCurrent_Student->student.height );
				return 1;
			}
			else{
				PCurrent_Student=PCurrent_Student->PNextStudent;
				count++;
			}
		}
	}
	DPRINTF("\n invalid index");
	return 0;
}
void Count(){
	struct SStudent* PCurrent_Student=gpfirststudent;
		int count=0;
		if(gpfirststudent==(void*)0){
			DPRINTF("\nLinekedlist is empty");
		}
		while(PCurrent_Student){
			PCurrent_Student=PCurrent_Student->PNextStudent;
			count++;
		}
DPRINTF("/n number of nodes equal : %d",count);
}
int Node_from_the_end()
{
	struct SStudent* pCurrentStudent =gpfirststudent ;
	struct SStudent* pReferenceStudent =gpfirststudent ;
	int count=0,counter=0;
	char node[40];
	int search;
	DPRINTF("\nEnter index : ");
	gets(node);
	search = atoi(node);
	while(count!=search)
	{
		count++;
		pReferenceStudent=pReferenceStudent->PNextStudent;
	}
	while (pReferenceStudent)
	{
		if (counter==search)
		{
			DPRINTF("\n record number %d ",counter);
			DPRINTF("\n \t ID: %d ",pCurrentStudent->student.id);
			DPRINTF("\n \t Name %s ",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %f ",pCurrentStudent->student.height);
			return 1;
		}
		else
		{
		counter++;
		pReferenceStudent=pCurrentStudent->PNextStudent;
		pReferenceStudent=pReferenceStudent->PNextStudent;
		}
	}

return 0;
}
void Reverse()
{
	struct SStudent* pCurrentStudent =gpfirststudent ;
	struct SStudent* pPreviousStudent =NULL ;
	struct SStudent* pNextStudent =NULL ;

    while (pCurrentStudent) {
        // Store next
    	pNextStudent = pCurrentStudent->PNextStudent;

        // Reverse current node
    	pCurrentStudent->PNextStudent = pPreviousStudent;

        // Move pointers one position ahead.
    	pPreviousStudent = pCurrentStudent;
    	pCurrentStudent = pNextStudent;
    }
    gpfirststudent= pPreviousStudent;
}
