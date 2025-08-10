/******************************************************************
 *  AUTHOR : Ahmed Gamal                                          *
 *  Date   : 31 Dec. 2021                                         *
 *  Project: Clinc Project                                        *
 *  Version: v1.4                                                 *
 * ***************************************************************/
#include "LIB/STD_TYPES.h"
#include "stdio.h"
#include <stdlib.h>
/* Externing available slots array to check them */
u8 extern Availabe_Slots[5] ;
u8 extern Taken_Slots   [5] ;

/* Creating Struct of patient */
struct Node
{
	u8 id         ;
	u8 name[20]   ;
	u8 gender     ;
	u8 age        ;
	u8 res        ; 
	u8 *Link      ;
};

/* Creating Head Pointer points to first patient */
struct Node *HeadPointer = NULL ;   // Head Pointer For 



/***********************************************************
| Function Name : LinkedList_AddingNewPatient              *
| Parameters    : ID , NAME , Gender , Age                 *
| Function      : Create LL node and assign data in it     *
***********************************************************/
void LinkedList_AddingNewPatient (u8 Copy_id , u8 Copy_name[] , u8 Copy_gender , u8 Copy_age)
{
	//Reserve Size of(Struct Node) bytes for a New node
	struct Node *NewNode = (struct Node *) malloc(sizeof(struct Node)) ;
	u8 iteratior = 0 ; 
	//checking if the linked list is empty
	if(HeadPointer == NULL )
	{
		//set the headpointer to pointer to the newnode(first Node)
		HeadPointer = NewNode ;
		//change the newnode data
		NewNode -> id = Copy_id ;
		// loop to assign arry of characters
		while(Copy_name[iteratior] != '\0')
		{
			NewNode ->name[iteratior] = Copy_name[iteratior] ;
			iteratior ++  ;
		}	
		NewNode -> gender = Copy_gender ;
		NewNode -> age = Copy_age ;
		NewNode -> res = 0 ;
		//set the pointer of newnode to null
		NewNode -> Link = NULL ;
		/* Printing succes message */
        printf("Patient created \n") ;
	}
	else
	{
		//set a temp pointer to node points to the content of the headpointer
        struct Node *temp = HeadPointer ;
		//loop to find the last object in the list
		while(temp->Link != NULL)
		{
			temp = temp->Link ;
		}
		// set the last object to point to the new node
		temp -> Link = NewNode ;
		//set the pointerToNextNode of the new node to NULL
		NewNode -> Link = NULL ;
		// assigning data into node
		NewNode -> id = Copy_id ;
		// loop to assign arry of characters
		while(Copy_name[iteratior] != '\0')
		{
			NewNode ->name[iteratior] = Copy_name[iteratior] ;
			iteratior ++  ;
		}	
		NewNode -> gender = Copy_gender ;
		NewNode -> age = Copy_age ;
		NewNode -> res = 0 ;
		// Printing success message
		printf("Patient created \n") ;
	}
	
}

/***********************************************************
| Function Name : u8pwcheck					                *
| Return 	    : 1/0 						                *
| Function      : Ask for pw 3 times and check if it's right*
************************************************************/
u8 u8pwcheck() 
{   
	// Decleraing Variables needed
    u16 Local_u8Password ;
    static u16 iterator=0 ;

	//Asking User to Enter Password and scan it
    printf("Please enter Admin Password:");
	//Gives 3 trials for the user to enter password
    for(iterator  ; iterator<3 ; iterator++)
    {	
		scanf("%d",&Local_u8Password) ;
        if(Local_u8Password==1234)
        {
			iterator = 0 ;
            return 1 ;
        }
        if(iterator!=2)printf("Wrong Password Try Again : ") ;
    }
    return 0 ;
}

/***********************************************************************
| Function Name : Print_ReservationTime		               			   *
| Parameters    : ID 					                   			   *
| Function      : Takes res. Num and print the time assigned to it     *
***********************************************************************/

void Print_ReservationTime(u8 Cpy_ReservationID)
{
	// Switch case to print the needed Time 
	switch(Cpy_ReservationID)
	{
		case 0 :
			printf("No Reservation for this patient\n ") ;
			break ;
		case 1:
			printf("2:00 To 2:30");
			break ;
		case 2:
			printf("2:30 To 3:30");
			break ;
		case 3:
			printf("3:00 To 4:00");
			break ;
		case 4:
			printf("4:00 To 4:30");
			break ;
		case 5:
			printf("4:30 To 5:00");
			break ;
		default:
			printf("Error\n") ;
	}
}

/***********************************************************
| Function Name : PrintPatient				               *
| Parameters    : ID 					                   *
| Function      : Print All the date for the given ID      *
***********************************************************/

u8 PrintPatient(u8 ID)
{
	//Decleration of used Variables
	u8 iterator =0 ;
	struct Node *temp = HeadPointer ;
	// Loop until finding needed ID 
	while(temp != NULL )
	{	
		/* Checks if ID of node in Temp corresponding to needed one */
		if(temp->id == ID )
		{
			/* Printing DATA */
			printf("\n\n\n\n\nID    :%d \n",temp->id) ;
			printf("Name  :") ;
			/* Looping to print arry of name */
			for(iterator = 0 ; temp->name[iterator] != '\0' ; iterator ++)
			{
				printf("%c",temp->name[iterator]) ;	
			}
			printf("\nAge   :%d \n",temp->age)    ; 
			printf("Gender:%c \n",temp->gender) ;
			printf("Reservation Time : ")        ;
			Print_ReservationTime(temp->res)     ;
			return 1 ;
		}
		/* Assign to next node */
		temp = temp ->Link ;
	
	}
	/* print Not Found if temp in the last Node */
	if(temp == NULL)
	{
		printf("User Not Found \n ") ;
		return 1 ;
	}
}


/***********************************************************
| Function Name : EditPatient				               *
| Parameters    : ID						               *
| Function      : Edit All data corresponding to given ID  *
***********************************************************/

u8 EditPatient(u8 ID)
{	
	//Defination of Used Variables
	struct Node *temp = HeadPointer ;
	u8 id_=0 ;
	u8 gender_=0 ;
	u8 age_=0 ;
	u8 name[20]={0};
	u8 iteratior =0 ;
	
	//Looping till finding ID to edit
	while(temp != NULL)
	{
		if(temp->id == ID )
		{
			//Scanning New Data
			printf("Please Enter New ID    : ") ;
			scanf("%d",&id_) ;
			printf("Please Enter New gender: ") ;
			scanf("%s",&gender_) ;
			printf("Please Enter New age   : ") ;
			scanf("%d",&age_) ;
			printf("Please Enter New Name  :");
			scanf("%s",&name);
			//assiginting Value to Data
			temp -> id = id_ ;
			while(name[iteratior] != '\0')
			{
				temp ->name[iteratior] = name[iteratior] ;
				iteratior ++  ;
			}		
			temp -> gender = gender_ ;
			temp -> age = age_ ;
			
			//Printing Succes Message 
			printf("Patient updated succsfully <3 \n") ;
			break ;
		}
		// Updating Link 
		temp  = temp->Link ;
	}
	
	if(temp == NULL)
	{
		printf("Patient Not Found \n") ;
		return 0 ;
	}
}

/***********************************************************
| Function Name : ID_CheckAvailablity		               *
| Parameters    : ID						               *
| Function      : Check if ID exist or not			       *
| Return		: 1/0									   *
***********************************************************/
u8 ID_CheckAvailablity(u8 ID)
{
	struct Node *temp = HeadPointer ;
	// Loop Until Finding the ID or Temp in the last node 
	while(temp != NULL)
	{
		// Check if we are in the current Node
		if(temp->id == ID)
		{
			//return 1 if ID found
			return 1 ;
		}
		//Goes to next Node
		temp = temp -> Link ;
	}
	//return 0 if failed to find the ID
	return 0 ;
}
/***********************************************************
| Function Name : Reserve					               *
| Parameters    : ID , Slot						           *
| Function      : Assign reservation to corresponding ID   *
***********************************************************/
void Reserve(u8 ID , u8 Slot)
{
	// Check if the The Slot is available or reserved
	if(Availabe_Slots[Slot-1]==1)
	{

		struct Node *temp = HeadPointer ;
		//Finding the ID to reserve for in the LL
		while(temp != NULL)
		{
			if(temp->id == ID)
			{
				//Check if That ID has previous reservation
				if(temp->res == 0 )
				{
					//Reserve 
					temp->res = Slot ;
					Availabe_Slots[Slot-1]= 0 ;
					Taken_Slots   [Slot-1]= 1 ;
					// Printing Succes Message 
					printf("Reservation Done (y) \n") ;
				}
				else
				{
					printf("Patient Already Reserved please cancle reservation first \n") ;
				}
			}
			// Updating Link
			temp = temp -> Link ;
		}
	}
	else
	{
		printf("Enterd Wrong Number\n") ;
	}
}


/***********************************************************
| Function Name : Cancle_Reservation		               *
| Parameters    : ID 					                   *
| Function      : Cancle Reservation for corresponding ID  *
***********************************************************/

void Cancle_Reservation(u8 Copy_u8ID)
{
		struct Node *temp = HeadPointer ;
		// Finding the ID in the LL
		while(temp != NULL)
		{
			if(temp->id == Copy_u8ID)
			{
				//Check if he has a reservation or not
				if(temp->res != 0  )
				{
					//Cancling the reservation
					Availabe_Slots[temp->res-1]= 1 ;
					Taken_Slots   [temp->res-1]= 0 ;
					temp->res = 0 ;
					printf("Reservation Cancled Done (y) \n") ;
				}
				else
				{
					printf("Patient Not Reserved please assign reservation first \n") ;
				}
			}
			// Updating Link
			temp = temp -> Link ;
		}
}


/***********************************************************
| Function Name : Today_reservation			               *
| Parameters    : NONE					                   *
| Function      : Print all reservations for today 	       *
***********************************************************/
void Today_reservation()
{
	struct Node *temp = HeadPointer ;
	// Creating flag if no reseravtion found
	u8 flag = 0 ;
	while(temp != NULL)
	{
		//Check Current Node if it has a reservation 
		if (temp -> res != 0)
		{
			//Printing reservation Data 
			printf("Patient ID : %d reserved at \n\n\n",temp->id) ;
			//Print Time of reservation
			Print_ReservationTime(temp->res) ;
			printf("\n") ;
			// Assign flag into 1
			flag = 1 ;
		}
		// Update Link
		temp = temp -> Link ;
	}
	if(flag == 0)
	{
		printf("No reservation for today :) \n") ;
	}
}