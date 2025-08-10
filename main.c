/******************************************************************
 *  AUTHOR : Ahmed Gamal                                          *
 *  Date   : 31 Dec. 2021                                         *
 *  Project: Clinc Project                                        *
 *  Version: v1.3                                                 *
 * ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LIB/STD_TYPES.h"

/****************************** Functions prototypes ********************************/
void LinkedList_AddingNewPatient (u8 Copy_id , u8 Copy_name[] , u8 Copy_gender , u8 Copy_age) ;

u8   u8pwcheck            		 ()  														  ;
u8 	 ID_CheckAvailablity  		 (u8 ID)													  ;
void Print_ReservationTime		 (u8 Cpy_ReservationID)										  ;

u8 	 EditPatient          		 (u8 ID)													  ;
void Reserve              		 (u8 ID , u8 Slot)											  ;
void Cancle_Reservation   		 (u8 Copy_u8ID)												  ;

u8	 PrintPatient         		 (u8 ID)													  ;
void Today_reservation			 ()															  ;



/*Decleraing Variable Needed hts2al leh global h2olak el optmizer byms7hom :)*/
u8 choice ;
u8 id_ ;
u8 gender_ ;
u8 age_ ;
u8 name[20];
u8 mode ;
u8 Availabe_Slots[5]={1,1,1,1,1} ;
u8 Taken_Slots[5]={0,0,0,0,0} ;
u8 iterator=0 ;
u8 Reservation_Number;

void main()
{       

    //Welcome Message and asking for Mode settings and scan it
    while(1)
	{
		printf("\n\n\n\n**************** Welcome To Ahmed Gamal's Clinc ****************** \n\t\t Press 1 for admin Login Mood\n\t\t Press 2 for user Mode\n") ;
		scanf("%d",&mode) ;
		
		//switch on admin or user moods
		switch(mode)
		{
			case 1:
				if(u8pwcheck()) 
				{
					/* Admin Mode Options */
					printf("\n\n\nYou have logged in Admin Mode Select Feature \n")	;
					printf("-)Press 1 for\t Adding New Patient\n")  				;
					printf("-)Press 2 for\t Editting patient record\n") 			;
					printf("-)Press 3 for\t reserve slot with the doctor\n") 		;
					printf("-)Press 4 for\t Cancling reservition\n") 				;
					scanf("%d",&choice) 											;
					
					switch(choice)
					{
						case 1 :
						/* Scanning New Patient Data */
						printf("please enter ID: ")  		;
						scanf("%d",&id_)			 		;
						/* Pooling until entering new ID if ID is Already excited */ 
						while(ID_CheckAvailablity(id_))
						{
							printf("ID Already Exist enter another id :") ;
							scanf("%d",&id_) ;
						}
						printf("please enter gender: ") 	;
						scanf("%s",&gender_)		    	;
						
						printf("please enter age : ")   	;
						scanf("%d",&age_) 					;
						
						printf("Please enter His name :")	;
						scanf("\n")							;
						scanf("%[^\n]%*c", name)			;
						
						/*Sending data to function to add it as LL*/
						LinkedList_AddingNewPatient(id_,name,gender_,age_) ;
						
						break ;
						
						case 2 :
						/* Scanning Id To Edit  */
						printf("Please enter ID to edit : ");
						scanf("%d",&id_) ;
						/* Sending ID to edit for edditing Function */
						EditPatient(id_)  ;					
						break ;	
						
						case 3 :
						/* Reservation Case */
						printf("Please enter ID to reserve for : ");
						scanf("%d",&id_) ;
						/*Checks if ID is Available*/
						if(ID_CheckAvailablity(id_))
						{
							/* For Loop To Check what Slots is available*/
							for (iterator =0 ; iterator < 5 ; iterator ++)
							{
								if(Availabe_Slots[iterator] == 1 )
								{
									if(iterator==0)
									{
										printf("press 1 to reserve for 2:00 to 2:30 Slot\n") ;
									}
									else if(iterator==1)
									{
										printf("press 2 to reserve for 2:30 to 3:00 Slot\n") ;
									}
									else if(iterator==2)
									{
										printf("press 3 to reserve for 3:00 to 3:30 Slot\n") ;
									}
									else if(iterator==3)
									{
										printf("press 4 to reserve for 3:30 to 4:00 Slot\n") ;
									}	
									else if(iterator==4)
									{
										printf("press 5 to reserve for 4:00 to 4:00 Slot\n") ;
									}							
								}
							}
							/* Scan reservation slot and reserve it for specified patient */
							scanf("%d",&Reservation_Number) ;
							Reserve(id_,Reservation_Number) ;
						}
						else
						{	
							/*Failed Message*/
							printf("ID Not Found \n") ;
						}
						break ;	
						
						case 4 :
							/* Cancel Reservation Case */
							printf("Please enter ID to cancle reservation for : ");
							scanf("%d",&id_) ;
							/* Check if ID is excited */
							if(ID_CheckAvailablity(id_))
							{	
								/* Cancling the reservation Handling*/
								Cancle_Reservation(id_) ;	
							}
							else
							{
								/*Failed Message*/
								printf("No ID Found\n") ;
							}
						break ;	

						default :
							/* Error Message */
							printf("Wrong Choice returing... \n");
			
					}
				}
			break;
			case 2:
				/* Main Menu of User Mood */
				printf("-)Press 1 for\t Printing patient record \n") 		;
				printf("-)Press 2 for\t Viewing Today Reservation \n")		;
				scanf("%d",&choice) 										;
				
				switch(choice)
				{
					case  1:
						/* Scanning ID To Search For */
						printf("Please enter ID to search : ")  ;
						scanf("%d",&id_) 						;
						/*Printing ID's content      */
						PrintPatient(id_) 						;
						break ;
					case  2:
						Today_reservation();
						break ;
					
				}
			break;

			default :
			 printf("Wrong Choice returning... :) \n") ;
		}
	}
}