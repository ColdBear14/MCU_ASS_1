/*
 * button.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESS_STATE GPIO_PIN_RESET

int button_flag[3];
int button_long_flag[3];

int IsButtonPress(int index);
int IsButtonLongPress(int index);
void subKeyProcess(int index);
int getIndex(int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
