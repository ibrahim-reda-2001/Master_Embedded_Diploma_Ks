
#include "linkedlist.h"



int main ()
{
	char temp_text[40];
	while (1)
	{
		DPRINTF("\n============");

		DPRINTF("\n\t Choose one of the following options: ");

		DPRINTF("\n1:Add Student ");

		DPRINTF("\n2:Delete Student ");

		DPRINTF("\n3:View Students ");

		DPRINTF("\n4:Delete All");

		DPRINTF("\n5:Search");
		DPRINTF("\n6:count nodes");
		DPRINTF("\n7:node from end");
		DPRINTF("\n8:Reverse");



		DPRINTF("\nEnter an Option : ");

		gets(temp_text);

		DPRINTF("\n============");

		switch(atoi(temp_text))
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			DPRINTF("\n********************************************** ");
			view_students();
			DPRINTF("\n********************************************** ");
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			Search();
			break;
		case 6:
			Count();
			break;
		case 7:
			Node_from_the_end();
			break;
		case 8:
			Reverse();
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}
	}
	return 0;
}
