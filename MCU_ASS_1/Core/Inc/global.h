/*
 * global.h
 *
 *  Created on: Dec 7, 2024
 *      Author: Hy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"

#define INIT 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

#define AUTO 10
#define AUTO_RED 11
#define AUTO_GREEN 12
#define AUTO_YELLOW 13

#define MAN 20
#define RED_GREEN 21
#define RED_YELLOW 22
#define GREEN_RED 23
#define YELLOW_RED 24

extern int statusMode;

#endif /* INC_GLOBAL_H_ */
