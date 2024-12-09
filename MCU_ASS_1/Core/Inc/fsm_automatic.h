/*
 * fsm_automatic.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "button.h"
#include "control_traffic.h"
#include "fsm_mode.h"

extern int status_A;
extern int status_B;

extern int count_Down_A;
extern int count_Down_B;

void fsm_automatic_run_A();
void fsm_automatic_run_B();
extern void fsm_automatic_run();

#endif /* INC_FSM_AUTOMATIC_H_ */
