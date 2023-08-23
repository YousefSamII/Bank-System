/******************************************************
 * File Name		: admin.c
 *
 * Description 		: implement admin functions for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/
/* =============================================================================
 * 		I'm used '#' This character as string terminator please enter it
 * 		as last character when you enter any string
 * ==============================================================================*/
#include <stdio.h>
#include "admin.h"
#include <stdlib.h>
#include<string.h>
#include<time.h>	// to get Current Time and generate srand() function
#include <unistd.h>	// to access on process id of the running process  using getpid() function



/*
 * Function Name : adminMenu()
 * Description   : Display menu and get operations from user
 */
void adminMenu(void)
{
	s32 n ;
	s8 exID[SIZE_STR],chec;
	printf("\n\n============ IMPORTANT NOTE =================\n");
	printf("1.Please enter A \'#\' This character when you finished of entire any string only(not with age)\n");
	printf("I'm used it as terminator character \n2. Must Enter The number of character as Required\n");
	printf("============================================\n\n");
	printf("--------------------------\n");
	printf("  Admin Operations \n");
	printf("--------------------------\n");
	printf("1. Create a New Account \n");
	printf("2. Open Existing Account \n");
	printf("3. Exist System \n");
	printf("--------------------------\n");
	printf("Please Enter your Choice here : ");
	scanf("%d",&n);
	switch(n)
	{
	case 1:
	{
		struct Bankaccount newAcc;

		createNewAcc(&newAcc);
	}
	break;
	case 2:
		printf("Please Enter your ID : ");
		getString(exID);
		chec=findAccInBankSystem(exID,0.0);
		if(chec==0)
		{
			openExistingAcc(getAddressStruct(exID));
		}
		else
		{
			printf("Not Founded , Try again\n");

		}
		break;
	case 3:
		exit(0);
		break;
	default:
		printf("Invalid Choice ,Try agein \n");
		break;

	}
}
/*
 * Function Name : createNewAcc()
 * Description 	 : Create a new bank account
 */
void createNewAcc(struct Bankaccount *ptr_to_newAcc)
{
	struct Bankaccount *newAccount =(struct Bankaccount *)malloc(sizeof(struct Bankaccount));
	ptr_to_newAcc=newAccount;
	ptr_to_newAcc->balance=0.0;
	ptr_to_newAcc->status=Active;
	create_pass(ptr_to_newAcc->BankID,10,0);

	do{printf("-at least 6 character- - with last character '#' - \nPlease Enter Your Full Name : ");
	getString(ptr_to_newAcc->Name);
	}while(strlen(ptr_to_newAcc->Name) <6);

	printf("Please Enter Your Address - with last character '#' -: ");
	getString(ptr_to_newAcc->Address);

	do{
		printf("Enter your Age - between 16 to 100 year - :");
		scanf("%d",&(ptr_to_newAcc->Age));
	}while((ptr_to_newAcc->Age < 16) || (ptr_to_newAcc->Age >=100));
	if((ptr_to_newAcc->Age) <= 20)
	{
		ptr_to_newAcc->guardian=Yes;
		do{printf("Please Enter National ID of Guardian -14 digits-  - with last character '#' - : ");
		getString(ptr_to_newAcc->guardianID);
		}while(strlen(ptr_to_newAcc->guardianID) !=14);
	}

	do{printf("Please Enter Your National ID -14 digits- - with last character '#' -: ");
	getString(ptr_to_newAcc->National_ID);
	}while(strlen(ptr_to_newAcc->National_ID) != 14);

	create_pass(ptr_to_newAcc->password,6,0);
	printf("\n\n--------------------------\n");
	printf("Welcome Sir %s ^_^",ptr_to_newAcc->Name);
	printf("\nYour ID : %s\n",ptr_to_newAcc->BankID);
	printf("Your Password : %s\n",ptr_to_newAcc->password);
	printf("Your Balance : %lf $\n",ptr_to_newAcc->balance);

	printf("Your Current Account Status : Active (check every time before make operation )\n");

	printf("--------------------------\n");
	insertNewAcc(&ptr_to_newAcc);
}

/*
 * Function Name :create_pass()
 * Description   : Generate a random password
 */
s8 *create_pass(s8 *randomString,u32 length,u8 passStatus)
{
	u32 i;
	s8 digits[10] ="0123456789";
	//s32 digits_length = 50;//strlen(digits);
	s8 lowers[30] ="abcdefghjklmnbvxzwertyuiop";
	//s32 lowers_length = 50;//strlen(lowers);
	s8 uppers[30] ="QWERTYUIOPASDFGHJKLZXCVBNM";
	//s32 uppers_length =50;//strlen(uppers);
	s8 symbols[10] ="!@#$%^&*_";
	//	s32 symbols_length = 50;//strlen(symbols);
	srand(time(NULL) * getpid());	/* we need to pass a value which change each run time
    						this is the reason for pass time(0) multiple by process id to make it more unique*/
	for(i=0;i<length;i++)
	{
		/*
		 *  We Have four types using in password
		 */
		s8 char_types;
		if(passStatus==0)
		{
			char_types=0;
		}
		else
		{
			char_types = rand() %4;	// return integer number between 0 to 3
		}
		switch(char_types)
		{
		case 0:
			randomString[i]=digits[rand() % 10];	// obtain random index from 0to digits length -1
			break;
		case 1:
			randomString[i]=lowers[rand() % 30];
			break;
		case 2:
			randomString[i]=uppers[rand() % 30];
			break;
		case 3:
			randomString[i]=symbols[rand() % 10];
			break;
		}

	}
	randomString[i] ='\0';
	return randomString;
}
/*
 * Function Name : openExistingAcc()
 * Description   : make operation on Exist account
 */
void openExistingAcc(struct Bankaccount *ptr_to_exAcc)
{
	s32 ch;
	u8 j;
	s8 str_to_id[SIZE_BANK_ID];
	u8 r;
	f64 amount;
	f64 *ptr;
	exAcc:
	ptr=&(ptr_to_exAcc->balance);
	printf("--------------------------\n");
	printf("  Existing Account Operations \n");
	printf("--------------------------\n");
	printf("1. Make Transaction \n");
	printf("2. Change Account status \n");
	printf("3. Get Cash \n");
	printf("4. Deposit in Account \n");
	printf("5. Return to Main Menu \n");
	printf("--------------------------\n");
	printf("Please Enter your Choice here : ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:

		do{printf("Enter the Bank Account ID you want to transfer money to- 10 digits- - with last character '#' - : ");
		getString(str_to_id);
		}while(strlen(str_to_id) != 10);
		printf("Enter amount of money to transfer it to the this account :");
		scanf("%lf",&amount);
		r=findAccInBankSystem(str_to_id,0.0);
		if(r==0)
		{
			if((amount<= (ptr_to_exAcc->balance)) && (ptr_to_exAcc->status)== Active && checkState(ptr_to_exAcc)== 1)
			{
				printf("Your Balance before make transaction : %lf $\n",(ptr_to_exAcc->balance));
				ptr_to_exAcc->balance -= amount;
				findAccInBankSystem(str_to_id,amount);	/* deposite also*/
				printf("Your Balance after make transaction : %lf $\n",(ptr_to_exAcc->balance));

			}
			else
			{
				printf("Error !!,Check if Two Accounts are in Active mode or your balance ,Try again.\n");
			}
		}
		else
		{
			printf("Try again \n");
		}
		goto exAcc;
		break;
	case 2:
		state:
		printf("1.Active\n2.Restricted\n3.Closed\n");
	j=checkState(ptr_to_exAcc);
	if(j==1)
	{
		printf("Your Current Account Status : Active\n");
	}
	else if(j == 2)
	{
		printf("Your Current Account Status : Restricted\n");
	}
	else if(j == 0)
	{
		printf("Your Current Account Status : Closed\n");
	}
	printf("Please enter the Bank Account Status, you want for this account : ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		ptr_to_exAcc->status= Active;
		break;
	case 2:
		ptr_to_exAcc->status=Restricted;
		break;
	case 3:
		ptr_to_exAcc->status =Closed;
		break;
	default :
		printf("Invalid Choice , Try again \n");
		goto state;
		break;
	}
	goto exAcc;
	break;
	case 3:
		if(getCash(ptr) == TRUE)
		{
			printf("Withdraw Operation is done ^_^ \n");
		}
		else
		{
			printf("Try again \n");
		}
		goto exAcc;
		break;
	case 4:
		depositCash(ptr);
		goto exAcc;
		break;
	case 5:
		/* Do no thing*/
		break;
	default :
		printf("Invalid choice , Try again\n");
		goto exAcc;
		break;
	}
}




