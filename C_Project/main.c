/******************************************************
 * File Name		: main.c
 *
 * Description 		: implement main function for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/
#include <stdio.h>
#include "admin.h"
#include "client.h"
#include "Definitions.h"
#include <string.h>
/* =============================================================================
 * 		I'm used '#' This character as string terminator please enter it
 * 		as last character when you enter any string
 * ==============================================================================*/
int main(void)
{

	start();
	return 0;
}
/*
 * Function Name : start ()
 * Description   : Start the implementation of code
 */
void start(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	s32 ch;
	s8 ID[SIZE_BANK_ID], pass[SIZE_PASS];
	u8 flagID,flagPass;
	for(;;)
	{
		printf("--------------------------\n");
		printf("Main Menu		\n");
		printf("--------------------------\n");
		printf("1.Admin Mode\n");
		printf("2.Client Mode\n");
		printf("--------------------------\n");
		printf("Please Enter your Choice here : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			adminMenu();
			break;
		case 2:
			do{printf("Please Enter Your ID here - 10 digits - : ");
			getString(ID);
			}while(strlen(ID) != 10);

			flagID=findAccInBankSystem(ID,0.0);
			if(flagID==0)
			{
				do{printf("Please Enter Your Pass here - 6 character -: ");
				getString(pass);
				}while(strlen(pass) != 6);
				flagPass=checkPass(pass);
				if(flagPass == 0)
				{
					clientMenu(ID,pass);
				}
				else
				{
					printf("Sorry !! Wrong Password\n");
				}
			}
			else
				printf("Sorry!! Wrong ID \n");

			break;
		default:
			printf("Invalid Choice ,Try again\n");
			break;
		}
	}

}

