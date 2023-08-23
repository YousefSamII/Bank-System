/******************************************************
 * File Name		: Definitions.h
 *
 * Description 		: implement header file  for  some definition ofC graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/
#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_


/* =============================================================================
 * 		I'm used '#' This character as string terminator please enter it
 * 		as last character when you enter any string
 * ==============================================================================*/
#include "STD_TYPES.h"

/* =============================
 *	Prototypes for Functions
 * =============================*/
void start(void);

/* =============================
 *		Definitions
 * =============================*/
#define Null  ((void *) 0)		/* Make my own NULL ^_^*/
#define TRUE		1
#define FALSE 		0
#define SIZE_STR				125
#define SIZE_NATIONAL_ID		15
#define SIZE_BANK_ID			11
#define SIZE_PASS				7

typedef enum{
	Closed ,Active,Restricted
}AccountStatus;

typedef enum{
	No ,Yes
}Guardian;


struct Bankaccount{
	s8 Name[SIZE_STR];
	s8 Address[SIZE_STR];
	s8 National_ID[SIZE_NATIONAL_ID];
	s32 Age;
	s8 BankID[SIZE_BANK_ID];
	Guardian guardian;
	s8 guardianID[SIZE_NATIONAL_ID];
	AccountStatus status;
	f64 balance;
	s8 password[SIZE_PASS];
	struct Bankaccount *next;
};

#endif /* DEFINITIONS_H_ */
