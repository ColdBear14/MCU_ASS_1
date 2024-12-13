/*
 * fsm_mode.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#include "fsm_mode.h"

int RED_timer = 5;
int GREEN_timer = 3;
int YELLOW_timer = 2;

int temp =0;

void fsm_mode(){
	switch(statusMode){
	case INIT:
		statusMode = MODE1;
		status_A = AUTO;
		status_B = AUTO;
		break;
	case MODE1:
		if(IsButtonPress(0)==1){
			statusMode=MODE2;
			status_A = 0;
			status_B = 0;
			lcd_clear_display();
		}
		if(IsButtonPress(2) == 1){
			status_manual = MAN;
			lcd_clear_display();
		}
		break;
	case MODE2:
		statusModeTraffic();

		if(IsButtonPress(0)==1){
			statusMode=MODE3;
			temp=0;
			lcd_clear_display();

		}
		if(IsButtonPress(1)==1){
			temp+=1;
		}
		if(IsButtonPress(2)==1){
			RED_timer+=temp;
			temp=0;
		}
		displayTraffic();
		break;
	case MODE3:
		statusModeTraffic();
		if(IsButtonPress(0)==1){
			statusMode=MODE4;
			temp=0;
			lcd_clear_display();

		}
		if(IsButtonPress(1)==1){
			temp+=1;
		}
		if(IsButtonPress(2)==1){
			GREEN_timer+=temp;
			temp=0;
		}
		displayTraffic();
		break;
	case MODE4:
		statusModeTraffic();
		if(IsButtonPress(0)==1){
			temp=0;
			statusMode=MODE1;
			status_A = AUTO;
			status_B = AUTO;
			lcd_clear_display();
		}
		if(IsButtonPress(1)==1){
			temp+=1;
		}
		if(IsButtonPress(2)==1){
			YELLOW_timer+=temp;
			temp=0;
		}
		displayTraffic();
		break;
	default:
		break;
	}
}
