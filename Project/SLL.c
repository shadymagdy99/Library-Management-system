#include "SLL.h"


List_t *Create_List(void)
{
	List_t *ListPtr = (List_t *)malloc(sizeof(List_t));
	ListPtr -> Size = 0;
	ListPtr -> Head = NULL;
	return ListPtr;
}

ErrorState_t  List_Empty(List_t *List, List_State_t *ReturnValue)
{
	ErrorState_t FunctionState = RET_OK;
	if(List != NULL)
	{
		if(List->Size == 0)
		{
			*ReturnValue = LIST_EMPTY;
		}
		else{
			*ReturnValue = LIST_NEMPTY;
		}
	}
	else{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}


ErrorState_t AddToFront(List_t *List,u8 B_n[MAXIN],u8 A_n[MAXIN], s32 Data)
{
	ErrorState_t ReturnState = RET_OK;
	if(NULL != List)
	{
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		if(NULL != NodePtr)
		{
			NodePtr->Value = Data;
			u32 i = 0;
		    for(i=0;(i<MAXIN)&&(B_n[i]!='0');i++){
				NodePtr->BookName[i] = B_n[i];
			}
			for(i=0;(i<MAXIN)&&(A_n[i]!='0');i++){
				NodePtr->AuthorName[i] = A_n[i];
			}
			NodePtr -> Next = List -> Head;
			List -> Head = NodePtr;
			List->Size++;
		}
		else{
			ReturnState = RET_NULL_PTR;
		}
	}
	else{
		ReturnState = RET_NULL_PTR;
	}
	return ReturnState;
}



ErrorState_t RemoveFromFront(List_t *List, s32 *Ret_Data)
{
	ErrorState_t ReturnState = RET_OK;
	List_State_t List_Status = LIST_NEMPTY;
	node_t *BufferPtr = NULL;
	
	if((List != NULL) && (Ret_Data != NULL))
	{
		List_Empty(List, &List_Status);
		if(List_Status == LIST_EMPTY)
		{
			printf("Sorry ! the list is Empty.... \n");
		}
		else{
			*Ret_Data = List->Head->Value;
			BufferPtr = List->Head;
			List->Head = BufferPtr->Next;
			free(BufferPtr);
			List->Size--;
		}
	}
	else{
		ReturnState = RET_NULL_PTR;
	}
	return ReturnState;
}


ErrorState_t AddToBack(List_t *List,u8 B_n[MAXIN],u8 A_n[MAXIN], s32 Data)
{
	ErrorState_t ReturnState = RET_OK;
	node_t *LoopPtr = NULL;
	if(NULL != List)
	{
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		NodePtr->Value = Data;
		u32 i = 0;
		    for(i=0;(i<MAXIN)&&(B_n[i]!='0');i++){
				NodePtr->BookName[i] = B_n[i];
			}
			for(i=0;(i<MAXIN)&&(A_n[i]!='0');i++){
				NodePtr->AuthorName[i] = A_n[i];
			}
			NodePtr->node_number = List->Size + 1;
		NodePtr->Next = NULL;
		LoopPtr = List->Head;
		if(LoopPtr == NULL)
		{
			List->Head = NodePtr;
		}
		else{
			while(LoopPtr->Next != NULL)
			{
				LoopPtr = LoopPtr->Next;
			}
			LoopPtr->Next = NodePtr;
		}
		List->Size++;
	}
	else{
		ReturnState = RET_NULL_PTR;
	}
	return ReturnState;
}


ErrorState_t RemoveFromBack(List_t *List,s32 *Ret_Val)
{
	ErrorState_t ReturnState = RET_OK;
	List_State_t List_State = LIST_NEMPTY;
	node_t *Ptr = NULL;
	
	if((List != NULL) && (Ret_Val != NULL))
	{
		List_Empty(List, &List_State);
		if(List_State == LIST_EMPTY)
		{
			printf("Sorry ! the library is Empty ...\n");
		}
		else{
			if(List->Head->Next == NULL)  /* or this condition (List -> Size == 1)*/
			{
				*Ret_Val = List->Head->Value;
				free(List->Head);
				List->Head = NULL;
				List->Size--;
			}
			else{
				Ptr = List->Head;
				while(Ptr->Next->Next != NULL)
				{
					Ptr = Ptr->Next;
				}
				*Ret_Val = Ptr->Next->Value;
				free(Ptr->Next);
				Ptr->Next = NULL;
				List->Size--;
				
			}
		}
	}
	else{
		ReturnState = RET_NULL_PTR;
	}
	return ReturnState;
}
void display(List_t *List)
{
   if(List -> Head == NULL)
   {
      printf("\nLibrary is Empty there are no books to view \n");
   }
   else
   {
	   
      struct Node *temp = List -> Head;
      printf("\nAvaliable Books are: \n");
	  
      while(temp != NULL)
      {
		printf("Book number (%d) : \n",temp->node_number);
        printf("Book Name : %s\n",temp->BookName);
        printf("Author Name : %s\n",temp->AuthorName);
         printf("Book cost : %d\n",temp->Value);
		 printf("----------------------------------------------\n");
         temp = temp->Next;
      }
   }
}
void deleteMiddleNode(u32 position,List_t *List)
{
    u32 i = 0;
    node_t *toDelete, *prevNode;

    if(List -> Head == NULL)
    {
        printf("Library is already empty.");
    }
    else
    {
        toDelete = List -> Head;
        prevNode = List -> Head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->Next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == List -> Head)
                List -> Head = List -> Head->Next;

            prevNode->Next = toDelete->Next;
            toDelete->Next = NULL;

            /* Delete nth node */
            free(toDelete);
			List->Size --;

            printf("SUCCESSFULLY DELETED LIBRARY\n");
        }
        else
        {
            printf("!!!INVALID BOOK NUMBER UNABLE TO DELETE!!!\n");
        }
    }
}




