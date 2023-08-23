/******************************************************
 * File Name		: common_functions.c
 *
 * Description 		: implement common functions for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/
#include "common_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Bankaccount *Head = Null;
struct Bankaccount *current = Null;
/*
 * Function Name :getCash()
 * Description   : Get Cash value from acc to user
 */
u8 getCash(f64 *ptr_to_balance)
{
	f64 amount;
	u8 check;
	printf("Enter the cash amount you want to withdraw \n");
	scanf("%lf",&amount);
	if(amount <= *ptr_to_balance )
	{
		printf("Total amount Before withdraw : %lf $\n",*ptr_to_balance);
		*ptr_to_balance -= amount;
		printf("Total amount After withdraw : %lf $\n",*ptr_to_balance);
		check =TRUE;
	}
	else
	{
		printf("Sorry !! your cash Amount less than which you want \n");
		check =FALSE;
	}
	return check;
}
/*
 * Function Name :depositCash()
 * Description   : make deposit operation on Account
 */
void depositCash(f64 *ptr_to_balance)
{
	f64 amount;
	printf("Enter the cash amount you want to Deposit \n");
	scanf("%lf",&amount);
	printf("Your Balance Before Deposite : %lf $\n",*ptr_to_balance);

	*ptr_to_balance += amount;
	printf("Your Balance After Deposite : %lf $\n",*ptr_to_balance);
	printf("Deposite operation Done \n");
}
/*
 * Function Name : checkState()
 * Description   : check the state in Bank Account
 */
u8 checkState(struct Bankaccount *ptr_to_exAcc)
{
	u8 res;
	if(ptr_to_exAcc->status == Active)
	{
		res=1;
	}
	else if(ptr_to_exAcc->status==Closed)
	{
		res =0;
	}
	else if(ptr_to_exAcc->status == Restricted)
	{
		res=2;
	}
	return res;
}
/*
 * Function Name : checkPass()
 * Description   :check if old pass is true or not
 */
u8 checkPass(s8 pass_want_to_check[])
{
	u8 res=1;
	if(Head==NULL)
	{
		printf("There no are any accounts\n");
		return 1;
	}
	// start checking
	current = Head;
	while(current != NULL)
	{
		res=strcmp(pass_want_to_check,current->password);
		if(res == 0)
		{
			return res;
		}
		current = current->next;

	}
	// item not found in the list
	printf("\nWrong Pass\n");
	return 1;
}

/*
 * Function Name : getString()
 * Description   : Take string as input from user with terminator character #
 */
void getString(s8 str [])
{
	s8 i;
	s8 buffer[SIZE_STR];
	s8 c;
	for(i=0;i<SIZE_STR;i++)
	{
		scanf(" %c",&c);

		if(c=='#')
		{
			break;
		}
		buffer[i]=c;
	}
	buffer[i] ='\0';
	strcpy(str,buffer);
}
/*
 * Function Name :insertNewAcc()
 * Description   : Add new Account to another accounts
 */
void insertNewAcc(struct Bankaccount **ptr_toInsert_newAcc)
{
	struct Bankaccount *newAcc = (struct Bankaccount*) malloc(sizeof(struct Bankaccount));

	newAcc->Age =(*ptr_toInsert_newAcc)->Age;
	strcpy(newAcc->BankID,(*ptr_toInsert_newAcc)->BankID);
	strcpy(newAcc->Address,(*ptr_toInsert_newAcc)->Address);
	strcpy(newAcc->Name,(*ptr_toInsert_newAcc)->Name);
	strcpy(newAcc->National_ID,(*ptr_toInsert_newAcc)->National_ID);
	strcpy(newAcc->guardianID,(*ptr_toInsert_newAcc)->guardianID);
	strcpy(newAcc->password,(*ptr_toInsert_newAcc)->password);
	newAcc->balance =(*ptr_toInsert_newAcc)->balance;
	newAcc->guardian=(*ptr_toInsert_newAcc)->guardian;
	newAcc->status =(*ptr_toInsert_newAcc)->status;

	newAcc->next = Head;
	Head = newAcc;
}

/*
 * Function Name : findAccInBankSystem()
 * Desctiption   : Check if this acc is there or isn't
 */
u8 findAccInBankSystem(s8 id [],f64 deposite_to_specific_acc)
{
	u8 res=1;
	if(Head==NULL)
	{
		printf("There no are any accounts\n");
		return 1;
	}
	// start checking
	current = Head;
	while(current != NULL)
	{
		res=strcmp(id,current->BankID);
		if(res == 0)
		{
			current->balance += deposite_to_specific_acc;
			return res;
		}
		current = current->next;

	}
	// item not found in the list
	printf("\n%s This id not exist in bank system\n", id);
	return 1;

}
/*
 * Function Name : getAddressStruct()
 * Description   : return address of structure
 */

struct Bankaccount * getAddressStruct(s8 id[])
{
	u8 k;
	if(Head==NULL)
	{
		printf("There no are any accounts\n");
		return NULL;
	}
	current=Head;
	while(current != NULL)
	{
		k=strcmp(id , current->BankID);
		if(k == 0)
		{
			return current;
		}

		current =current ->next;
	}
	printf("SORRY !! NOT FOUNDED\n");
	return NULL;
}
