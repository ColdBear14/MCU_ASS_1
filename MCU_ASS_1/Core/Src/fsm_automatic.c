/*
 * fsm_automatic.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#include "fsm_automatic.h"

int status_A = 10;
int status_B = 10;

int count_Down_A;
int count_Down_B;

void fsm_automatic_run() {
	fsm_automatic_run_A();
	fsm_automatic_run_B();
}

void fsm_automatic_run_A() {
	switch (status_A) {
	case AUTO:
		status_A = AUTO_RED;
		count_Down_A = RED_timer;
		break;
	case AUTO_RED:
		statusTraffic_A();
		if (count_Down_A <= 0) {
			status_A = AUTO_GREEN;
			count_Down_A = GREEN_timer;
		}
		count_Down_A--;
		break;
	case AUTO_GREEN:
		statusTraffic_A();
		if (count_Down_A <= 0) {
			status_A = AUTO_YELLOW;
			count_Down_A = YELLOW_timer;
		}
		count_Down_A--;
		break;
	case AUTO_YELLOW:
		statusTraffic_A();
		if (count_Down_A <= 0) {
			status_A = AUTO_RED;
			count_Down_A = RED_timer;
		}
		count_Down_A--;
		break;
	default:
		break;
	}
}

void fsm_automatic_run_B() {
	switch (status_B) {
	case AUTO:
		status_B = AUTO_GREEN;
		count_Down_B = GREEN_timer;
		break;
	case AUTO_RED:
		statusTraffic_B();
		if (count_Down_B <= 0) {
			status_B = AUTO_GREEN;
			count_Down_B = GREEN_timer;
		}
		displayTraffic();
		count_Down_B--;
		break;
	case AUTO_GREEN:
		statusTraffic_B();
		if (count_Down_B <= 0) {
			status_B = AUTO_YELLOW;
			count_Down_B = YELLOW_timer;
		}
		displayTraffic();
		count_Down_B--;
		break;
	case AUTO_YELLOW:
		statusTraffic_B();
		if (count_Down_B <= 0) {
			status_B = AUTO_GREEN;
			count_Down_B = GREEN_timer;
		}
		displayTraffic();
		count_Down_B--;
		break;
	default:
		break;
	}
}