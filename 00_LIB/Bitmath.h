/*
 * Utils.h
 *
 *  Created on: Jul 21, 2021
 *      Author: shire
 */

#ifndef MISC_INC_UTILS_H_
#define MISC_INC_UTILS_H_

#define Set_Bit(Var,BitNo)   	Var |= (1<<BitNo)|Var
#define Clr_Bit(Var,BitNo)   	Var &= (~(1<<BitNo))
#define Toggle_Bit(Var,BitNo)	Var ^=(1<<BitNo))
#define Get_Bit(Var,BitNo)   	((Var>>BitNo)&0x01)

#endif /* MISC_INC_UTILS_H_ */
