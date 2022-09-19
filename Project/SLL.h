#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ERROR_STATE.h"
#define MAXIN 20

typedef struct Node{
	u8 BookName[MAXIN];
	u8 AuthorName[MAXIN];
	s32 Value;
	s32 node_number;
	struct Node *Next;
}node_t;


typedef struct List{
	u32 Size;
	node_t *Head;
	//node_t *counter;
}List_t;

typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}List_State_t;



List_t *Create_List(void);
ErrorState_t  List_Empty(List_t *List, List_State_t *ReturnValue);
ErrorState_t AddToFront(List_t *List,u8 B_n[MAXIN],u8 A_n[MAXIN], s32 Data);
ErrorState_t RemoveFromFront(List_t *List, s32 *Ret_Data);
ErrorState_t AddToBack(List_t *List,u8 B_n[MAXIN],u8 A_n[MAXIN], s32 Data);
ErrorState_t RemoveFromBack(List_t *List,s32 *Ret_Val);
void display(List_t *List);
void deleteMiddleNode(u32 position,List_t *List);



#endif