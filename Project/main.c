/******Author:  Shady Magdy Hussein ******/
/*Program name:Library Management System*/
#include "main.h"
u8 Bookn[MAXIN]; // matrix that stores Book name
u8 Authorn[MAXIN]; // matrix that stores Author name
u32 user_i;   //user input
u32 i; //counter
s32 book_cost;
int main(void)
{
	s32 Ret_Value = 0;
	List_t *List1 = NULL;
	List1 = Create_List();
	//screen that will appear to user
	printf("******************************************************************************\n");
	printf("----------WELCOME TO LIBRARY APP----------\n");
	printf("---------------------------------------------------------\n");
		printf("Choose one of the options:\n");
		printf("To View all books                         Enter(1)\n");
		printf("To Add a new book                         Enter(2)\n");
		printf("To Delete a book                          Enter(3)\n");
		printf("To View number of available books         Enter(4)\n");
		printf("To Exit Library App                       Enter(5)\n");
		printf("---------------------------------------------------------\n");
		printf("----->  Your choise is : ");
		scanf("%d", &user_i);
		//loop to take input from the user and makes decsion
		while(user_i != 5){
		
		if(user_i == 1){
			display(List1); //call function to display all library content
		}
		else if(user_i == 2){
			printf("Please Enter the name of the book : ");
			fflush(stdin);
			gets(Bookn); 
			printf("Please Enter the name of the author : ");
			gets(Authorn);
			printf("Please Enter the book price : ");
			scanf("%d",&book_cost);
			printf("\n");
			AddToBack(List1,Bookn,Authorn, book_cost); //add books to the back
			printf("BOOK HAS BEEN ADDED TO LIBRARY SUCCESSFULLY\n");
		}
		else if(user_i == 3){
			//this condition removes the selected book
			u32 del=0 ;
			printf("Which Book Do you want to delete : ");
			scanf("%d",&del);
			if(del == 1){
		RemoveFromFront(List1, &Ret_Value);
		printf("SUCCESSFULLY DELETED FROM LIBRARY\n");
			}
			else if((del == 2)||(del == 3)||(del == 4)||(del == 5)){
			deleteMiddleNode(del,List1);
		}
		/*else if(del > 5){
			RemoveFromBack(List1,&Ret_Value);
		printf("SUCCESSFULLY DELETED FROM LIBRARY\n");
		}*/
		}
		else if(user_i == 4){
			printf("Number of Available Books is : %d\n",List1->Size);
		}
		else{
			//this statement happens if the user enters a number diffrent from (1 - 5)
			printf("!!!!!!PLEASE ENTER A VALID CHOISE !!!!!!!!!\n");
		}
		printf("---------------------------------------------------------\n");
		printf("Choose one of the options:\n");
		printf("To View all books                         Enter(1)\n");
		printf("To Add a new book                         Enter(2)\n");
		printf("To Delete a book                          Enter(3)\n");
		printf("To View number of available books         Enter(4)\n");
		printf("To Exit Library App                       Enter(5)\n");
		printf("---------------------------------------------------------\n");
		printf("----->  Your choise is : ");
		scanf("%d", &user_i); //scan user input again
	}
	//close the program when (user input = 5)
	printf("Thanks for using LIBRARY APP\n");
	printf("This APP is created by: Eng.Shady Magdy Hussein\n");
	printf("                 GOOD BYE\n");
	printf("******************************************************************************\n");
	return 0;
}

