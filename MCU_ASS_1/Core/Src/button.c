/*
 * button.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#include "button.h"

int KeyReg0[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int TimerForKeyPress[3] = {300,300,300};

int button_flag[3];
int button_long_flag[3];

int IsButtonPress(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int IsButtonLongPress(int index) {
	if (button_long_flag[index] == 1) {
		button_long_flag[index] = 0;
		return 1;
	}
	return 0;
}


void subKeyProcess(int index) {
	button_flag[index] = 1;
}

int getIndex(int index) {
	switch(index){
		case 0:
			return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
			break;
		case 1:
			return HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
			break;
		case 2:
			return HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
			break;
		default:
			break;
	}
	return 0;
}

void getKeyInput() {
	for (int i = 0; i < 3; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		KeyReg2[i] = getIndex(i) ;

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			//case short pressed
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESS_STATE) {
					//todo
					subKeyProcess(i);
					HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
					TimerForKeyPress[i] = 300;

				}
			} else { // case long pressed
				TimerForKeyPress[i]--;
				if (TimerForKeyPress[i] == 0) {
					//todo
					button_long_flag[i] = 1;
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
