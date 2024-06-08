#include "mbed.h"
//#include "mbed2/323/TARGET_NUCLEO_F042K6/TARGET_STM/TARGET_STM32F0/TARGET_NUCLEO_F042K6/PinNames.h"

/*******************************************************************************

  EXAMPLE DESCRIPTION
  
  Initialize ticker that periodically (100 ms) calls function that toggles 
  onboard LED.
  
*******************************************************************************/

Ticker tick; // Ticker definition

DigitalOut LED(LED1);  // definition of digital out pin
DigitalOut LEDB(PB_4 );  // PB_4 definition of digital out pin

// Toggles LED
void toggleLED() {
    LED = !LED;
    LEDB = !LEDB;

}

int main() {
  
    tick.attach(&toggleLED, 1); // Init the ticker with the address of the 
                                   // function (toggle_led) to be attached and 
                                   // the interval (100 ms)
    while (true) {
        // main programm loop - can do other things
    }
}
