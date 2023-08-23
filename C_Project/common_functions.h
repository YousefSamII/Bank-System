/******************************************************
 * File Name		: common_functions.h
 *
 * Description 		: implement common functions for C graduation project
 *
 * Author 			: Yousef Sami
 *
 * Date 			: 18/08/2023
 *********************************************************/

#ifndef COMMON_FUNCTIONS_H_
#define COMMON_FUNCTIONS_H_
#include "Definitions.h"
/* =============================
 *	Prototypes for Functions
 * =============================*/
u8 getCash(f64 *ptr_to_balance);
void getString(s8 str []);
void depositCash(f64 *ptr_to_balance);
u8 checkState(struct Bankaccount *ptr_to_exAcc);
struct Bankaccount * getAddressStruct(s8 id[]);
u8 checkPass(s8 pass_want_to_check[]);
struct Bankaccount * getAddressStruct(s8 id[]);
u8 findAccInBankSystem(s8 id [],f64 deposite_to_specific_acc);
void insertNewAcc(struct Bankaccount **ptr_toInsert_newAcc);

#endif /* COMMON_FUNCTIONS_H_ */
