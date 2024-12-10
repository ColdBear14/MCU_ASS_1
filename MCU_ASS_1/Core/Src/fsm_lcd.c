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
		lcd_goto_XY(1, 0);
		lcd_send_string("TIMER A:");
		lcd_display_value(1, 9, count_Down_A);
		lcd_goto_XY(2, 0);
		lcd_send_string("TIMER B:");
		lcd_display_value(2, 9, count_Down_B);

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


	default:
		break;
	}
}
