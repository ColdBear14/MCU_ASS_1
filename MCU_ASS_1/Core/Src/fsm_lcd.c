/*
 * fsm_lcd.c
 *
 *  Created on: Dec 9, 2024
 *      Author: Hy
 */

#include "fsm_lcd.h"

void fsm_lcd_run(){
	switch(statusMode){
	case MODE1:
		if(status_A == AUTO_RED){
			lcd_goto_XY(1, 0);
			lcd_send_string("RED A:");
			if(count_Down_A == 0 ) lcd_clear_display();
		}
		if(status_A == AUTO_GREEN){
			lcd_goto_XY(1, 0);
			lcd_send_string("GREEN A:");
			if(count_Down_A == 0 ) lcd_clear_display();
		}
		if(status_A == AUTO_YELLOW){
			lcd_goto_XY(1, 0);
			lcd_send_string("YELLOW A:");
			if(count_Down_A == 0 ) lcd_clear_display();
		}
		if(status_B == AUTO_RED){
			lcd_goto_XY(2, 0);
			lcd_send_string("RED B:");
			if(count_Down_B == 0 ) lcd_clear_display();
		}
		if(status_B == AUTO_GREEN){
			lcd_goto_XY(2, 0);
			lcd_send_string("GREEN B:");
			if(count_Down_B == 0 ) lcd_clear_display();
		}
		if(status_B == AUTO_YELLOW){
			lcd_goto_XY(2, 0);
			lcd_send_string("YELLOW B:");
			if(count_Down_B == 0 ) lcd_clear_display();
		}
		lcd_display_value(1, 10, count_Down_A);
		lcd_display_value(2, 10, count_Down_B);

		break;
	case MODE2:
		lcd_goto_XY(1, 0);
		lcd_send_string("SET TIMER RED");
		lcd_goto_XY(2, 1);
		lcd_send_string("DURATION:");
		lcd_display_value(2, 10, RED_timer + temp);
		break;
	case MODE3:
		lcd_goto_XY(1, 0);
		lcd_send_string("SET TIMER GREEN");
		lcd_goto_XY(2, 1);
		lcd_send_string("DURATION:");
		lcd_display_value(2, 10, GREEN_timer + temp);
		break;
	case MODE4:
		lcd_goto_XY(1, 0);
		lcd_send_string("SET TIMER YELLOW");
		lcd_goto_XY(2, 1);
		lcd_send_string("DURATION:");
		lcd_display_value(2, 10, YELLOW_timer + temp);
		break;
	case MODE5:
		break;


	default:
		break;
	}
}
