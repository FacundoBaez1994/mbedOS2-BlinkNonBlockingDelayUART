//=====[#include guards - begin]===============================================

#ifndef _NON_BLOCKING_DELAY_H_
#define _NON_BLOCKING_DELAY_H_

//==================[Libraries]===============================================

#include "mbed.h"

//=====[Declaration of public data types]======================================

typedef uint64_t tick_t;

//=====[Declaration of public classes]=========================================
/*
 * Class implementation for a delay that not block the rest of the rutine of the microcontroller 
 * Uses a ticker to count time (hardware)
 */
class nonBlockingDelay {
public:

//=====[Declaration of public methods]=========================================
    nonBlockingDelay ( tick_t durationValue);
    bool read( void );
    void write(  tick_t durationValue );

private:
//=====[Declaration of privates atributes]=========================================
    tick_t startTime;
    tick_t duration;
    bool isRunning;
    Ticker ticker;

//=====[Declaration of privates methods]=========================================
    void tickInit();
};


//=====[Declarations (prototypes) of public functions]=========================

//=====[#include guards - end]=================================================

#endif // _NON_BLOCKING_DELAY_H