/*
 * control_traffic.c
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#include "control_traffic.h"

int status_RED_A = 1;
int status_GREEN_A = 0;
int status_YELLOW_A = 0;

int status_RED_B = 0;
int status_GREEN_B = 1;
int status_YELLOW_B = 0;

void clearStatus_A(){
	status_RED_A = 0;
	status_GREEN_A = 0;
	status_YELLOW_A = 0;
}
void clearStatus_B(){
	status_RED_B = 0;
	status_GREEN_B = 0;
	status_YELLOW_B = 0;
}

void clearStatus(){
	status_RED_A = 0;
		status_GREEN_A = 0;
		status_YELLOW_A = 0;
	status_RED_B = 0;
	status_GREEN_B = 0;
	status_YELLOW_B = 0;
}

void displayTraffic() {
	//group a
	if (status_RED_A == 1) {
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	}
	if (status_YELLOW_A == 1) {
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	}
	if (status_GREEN_A == 1) {
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	}
	//group b
	if (status_RED_B == 1) {
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
	}
	if (status_YELLOW_B == 1) {
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
	}
	if (status_GREEN_B == 1) {
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	}
}

void statusModeTraffic(){
	clearStatus();
	if(statusMode == MODE2){
		status_RED_A=1;
		status_RED_B=1;
	}
	if(statusMode == MODE3){
		status_GREEN_A=1;
		status_GREEN_B=1;
	}
	if(statusMode == MODE4){
		status_YELLOW_A=1;
		status_YELLOW_B=1;
	}
}

void statusTraffic_A(){
	clearStatus_A();
	if(status_A == AUTO_RED){
		status_RED_A=1;
	}
	if(status_A == AUTO_GREEN){
		status_GREEN_A=1;
	}
	if(status_A == AUTO_YELLOW){
		status_YELLOW_A=1;
	}
}

void statusTraffic_B(){
	clearStatus_B();
	if(status_B == AUTO_RED){
		status_RED_B=1;
	}
	if(status_B == AUTO_GREEN){
		status_GREEN_B=1;
	}
	if(status_B == AUTO_YELLOW){
		status_YELLOW_B=1;
	}
}
