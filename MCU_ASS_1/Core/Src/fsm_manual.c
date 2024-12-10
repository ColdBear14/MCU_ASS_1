/*
 * fsm_manual.c
 *
 *  Created on: Dec 10, 2024
 *      Author: Hy
 */

#include "fsm_manual.h"

int status_manual;

void status_manual_mode(){
	if(status_A == AUTO_RED && status_B == AUTO_GREEN){
		status_manual = RED_GREEN;
	}
	if(status_A == AUTO_RED && status_B == AUTO_YELLOW){
		status_manual = RED_YELLOW;
	}
	if(status_A == AUTO_GREEN && status_B == AUTO_RED){
		status_manual = GREEN_RED;
	}
	if(status_A == AUTO_YELLOW && status_B == AUTO_RED){
		status_manual = YELLOW_RED;
	}
}

void fsm_manual_run(){
	switch(status_manual){
	case RED_GREEN:
		if(IsButtonPress(2)== 1){
			status_manual = RED_YELLOW;
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_RED;
			status_B = AUTO_GREEN;
		}
		break;
	case RED_YELLOW:
		if(IsButtonPress(2)== 1){
			status_manual = GREEN_RED;
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_RED;
			status_B = AUTO_YELLOW;
		}
		break;
	case GREEN_RED:
		if(IsButtonPress(2)== 1){
			status_manual = YELLOW_RED;
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_GREEN;
			status_B = AUTO_RED;
		}
		break;
	case YELLOW_RED:
		if(IsButtonPress(2)== 1){
			status_manual = RED_GREEN;
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_YELLOW;
			status_B = AUTO_RED;
		}
		break;
	default:
		break;
	}
}
