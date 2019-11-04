/*
 * taskConfig.h
 *
 *  Created on: Nov. 2, 2019
 *      Author: andres
 */

#include "stdbool.h"

#ifndef INC_TASKCONFIG_H_
#define INC_TASKCONFIG_H_

#endif /* INC_TASKCONFIG_H_ */

struct taskConfiguration
{
	bool LedRed;
	bool LedGreen;
	bool LedBlue;
	int tick_One;
	int tick_Two;
	int tick_Three;
};

typedef struct taskConfiguration LedConfig;
