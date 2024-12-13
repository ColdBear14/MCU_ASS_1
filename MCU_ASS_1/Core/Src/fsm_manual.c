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
	case MAN:
		status_manual_mode();
		break;
	case RED_GREEN:
		statusManTraffic();
		lcd_goto_XY(1, 1);
		lcd_send_string("RED");
		lcd_goto_XY(2, 1);
		lcd_send_string("GREEN");
		if(IsButtonPress(2)== 1){
			status_manual = RED_YELLOW;
			lcd_clear_display();
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_RED;
			status_B = AUTO_GREEN;
			setTimer(0, 1000);
			setTimer(1, 1000);
			count_Down_A = RED_timer;
			count_Down_B = GREEN_timer;
		}
		displayTraffic();
		break;
	case RED_YELLOW:
		statusManTraffic();
		lcd_goto_XY(1, 1);
		lcd_send_string("RED");
		lcd_goto_XY(2, 1);
		lcd_send_string("YELLOW");
		if(IsButtonPress(2)== 1){
			status_manual = GREEN_RED;
			lcd_clear_display();
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_RED;
			status_B = AUTO_YELLOW;
			setTimer(0, 1000);
			setTimer(1, 1000);
			count_Down_A = RED_timer;
			count_Down_B = YELLOW_timer;
		}
		displayTraffic();
		break;
	case GREEN_RED:
		statusManTraffic();
		lcd_goto_XY(1, 1);
		lcd_send_string("GREEN");
		lcd_goto_XY(2, 1);
		lcd_send_string("RED");
		if(IsButtonPress(2)== 1){
			status_manual = YELLOW_RED;
			lcd_clear_display();
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_GREEN;
			status_B = AUTO_RED;
			setTimer(0, 1000);
			setTimer(1, 1000);
			count_Down_A = GREEN_timer;
			count_Down_B = RED_timer;
		}
		displayTraffic();
		break;
	case YELLOW_RED:
		statusManTraffic();
		lcd_goto_XY(1, 1);
		lcd_send_string("YELLOW");
		lcd_goto_XY(2, 1);
		lcd_send_string("RED");
		if(IsButtonPress(2)== 1){
			status_manual = RED_GREEN;
			lcd_clear_display();
		}
		if(IsButtonPress(3)==1 ){
			status_A = AUTO_YELLOW;
			status_B = AUTO_RED;
			setTimer(0, 1000);
			setTimer(1, 1000);
			count_Down_A = YELLOW_timer;
			count_Down_B = RED_timer;
		}
		displayTraffic();
		break;
	default:
		break;
	}
}
