/******************************************************
 * File Name		: admin.h
 *
 * Description 		: implement admin header file for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/

#ifndef ADMIN_H_
#define ADMIN_H_
#include "common_functions.h"
/* =============================================================================
 * 		I'm used '#' This character as string terminator please enter it
 * 		as last character when you enter any string
 * ==============================================================================*/
/* =============================
 *	Prototypes for Functions
 * =============================*/
void adminMenu(void);
void createNewAcc(struct Bankaccount *ptr_to_newAcc);
s8 *create_pass(s8 *randomString,u32 length,u8 passStatus);
void openExistingAcc();
void insertNewAcc(struct Bankaccount **ptr_toInsert_newAcc);
u8 findAccInBankSystem(s8 id [],f64 deposite_to_specific_acc);
struct Bankaccount * getAddressStruct(s8 id[]);

#endif /* ADMIN_H_ */

