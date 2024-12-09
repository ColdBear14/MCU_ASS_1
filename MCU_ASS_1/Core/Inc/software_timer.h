/*
 * software_timer.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Hy
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];

void setTimer(int index, int counter);
void timerun();

#endif /* INC_SOFTWARE_TIMER_H_ */
