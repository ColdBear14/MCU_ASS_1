/*
 * fsm_mode.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#ifndef INC_FSM_MODE_H_
#define INC_FSM_MODE_H_

#include "global.h"
#include "control_traffic.h"
#include "i2c_lcd.h"


extern int RED_timer;
extern int GREEN_timer;
extern int YELLOW_timer;
extern int temp;

extern void fsm_mode();

#endif /* INC_FSM_MODE_H_ */
