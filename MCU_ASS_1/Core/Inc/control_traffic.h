/*
 * control_traffic.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#ifndef INC_CONTROL_TRAFFIC_H_
#define INC_CONTROL_TRAFFIC_H_

#include "global.h"
#include "fsm_automatic.h"
#include  "fsm_manual.h"

int status_RED_A;
int status_GREEN_A;
int status_YELLOW_A;

int status_RED_B;
int status_GREEN_B;
int status_YELLOW_B;

void clearStatus_A();
void clearStatus_B();
void clearStatus();

extern void displayTraffic();
extern void statusModeTraffic();
extern void statusManTraffic();
extern void statusTraffic_A();
extern void statusTraffic_B();

#endif /* INC_CONTROL_TRAFFIC_H_ */
