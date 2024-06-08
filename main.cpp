#include "mbed.h"
#include "non_Blocking_Delay.h"
//#include "arm_book_lib.h"
//#include "mbed2/323/TARGET_NUCLEO_F042K6/TARGET_STM/TARGET_STM32F0/TARGET_NUCLEO_F042K6/PinNames.h"

#define LATENCY 10
/*******************************************************************************

  EXAMPLE DESCRIPTION
  
  Initialize ticker that periodically Turn off and ond onboard LED and other as Digital Out
*******************************************************************************/

Ticker tick; // Ticker definition

Serial uartUsb(USBTX, USBRX, 9600 ); // debug only
 //     int write(const uint8_t *buffer, int length, const event_callback_t& callback, int event = SERIAL_EVENT_TX_COMPLETE);
DigitalOut LED(LED1);  // definition of digital out pin
DigitalOut LEDB(PB_4 );  // PB_4 definition of digital out pin
nonBlockingDelay delay (LATENCY );
char StringToSend [15] = "Hola Mundo!\n";




int main() {
    LED = 1;
    LEDB = 0;
    while (true) {

        if( delay.read()) {
            uartUsb.printf(StringToSend );
            LED = !LED;
            LEDB = !LEDB;
        }   
    }
}
