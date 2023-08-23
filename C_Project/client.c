/******************************************************
 * File Name		: client.c
 *
 * Description 		: implement client functions for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/
#include "client.h"
#include <stdio.h>
#include <string.h>
/*
 * Function Name : clientMenu()
 * Description   : Make Client operations
 */
void clientMenu(s8 client_id[] ,s8 pass[])
{
	s32 n;
	if(getAddressStruct(client_id)==NULL)
	{
		printf("NULL\n");
	}
	struct Bankaccount *ptr_to_client =getAddressStruct(client_id);
	f64 *ptr = &(ptr_to_client->balance);
	u8 r;
	s8 str_to_id[SIZE_BANK_ID];
	s8 oldPass[SIZE_PASS],newPass[SIZE_PASS];
	f64 amount;
	printf("\n\n============ IMPORTANT NOTE =================\n");
	printf("1.Please enter A \'#\' This character when you finished of entire any string only(not with age)\n");
	printf("I'm used it as terminator character \n2. Must Enter The number of character as Required\n");
	printf("============================================\n\n");
	printf("--------------------------\n");
	printf("  Client Operations \n");
	printf("--------------------------\n");
	printf("1. Make Transaction\n");
	printf("2. Change Account Password\n");
	printf("3. Get Cash\n");
	printf("4. Deposit in Account\n");
	printf("5. Return To main menu\n");
	printf("--------------------------\n");
	printf("Please Enter Your Choice here : ");
	scanf("%d",&n);
	switch(n)
	{
	case 1 :
		do{printf("Enter the Bank Account ID you want to transfer money to - with last character '#' -: ");
		getString(str_to_id);
		}while(strlen(str_to_id)!= 10);
		printf("Enter amount of money to transfer it to the this account :");
		scanf("%lf",&amount);
		r=findAccInBankSystem(str_to_id,0.0);
		if(r==0)
		{
			if((amount<= (ptr_to_client->balance)) && (ptr_to_client->status)== Active && checkState(ptr_to_client)== 1)
			{
				printf("Your Balance before make transaction : %lf $\n",(ptr_to_client->balance));
				ptr_to_client->balance -= amount;
				findAccInBankSystem(str_to_id,amount);	/* deposite also*/
				printf("Your Balance after make transaction : %lf $\n",(ptr_to_client->balance));

			}
			else
			{
				printf("Error !!,Check if Two Accounts are in Active mode ,Try again.\n");
			}
		}
		else
		{
			printf("Try again \n");
		}
		break;
	case 2:

		do{printf("Enter Your old pass -6 character - - with last character '#' - : ");
		getString(oldPass);
		}while(strlen(oldPass) != 6);
		if(checkPass(oldPass) == 0)
		{
			do{printf("Enter Your new pass -6 Character - - with last character '#' - : ");
			getString(newPass);
			}while(strlen(newPass) !=6);
			strcpy(ptr_to_client->password ,newPass);
		}
		else
		{
			printf("Wrong Password , Try again\n");
		}
		break;
	case 3 :
		if(getCash(ptr) == TRUE)
		{
			printf("Withdraw Operation is done ^_^ \n");
		}
		else
		{
			printf("Try again \n");
		}
		break;
	case 4 :
		depositCash(ptr);
		break;
	case 5 :
		/* Do no Thing*/
		break;
	default :
		printf("Invalid Choice , Try Again \n");
	}



}
