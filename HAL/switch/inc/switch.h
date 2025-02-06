#ifndef SWITCH_H_
#define SWITCH_H_

#include "switch_cfg.h"

/* Function Prototypes */
SWITCH_enuErrorStatus_t SWITCH_vInit(void);
SWITCH_enuErrorStatus_t SWITCH_u8GetState(u8 SwitchNum, u8 *state);

#endif /* SWITCH_H_ */