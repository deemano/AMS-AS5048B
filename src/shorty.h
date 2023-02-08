/**************************************************************************/
/*!
    @file     AM5048_AbsDegAngle.ino
    @author   murtdoc (twitterID) [rebuit on top of brentyi's work, BSD]
    @license  OpenSource for non-commercial use only

*/
/**************************************************************************/

#include "ams_as5048b.h"
//#include String

//unit consts
#define U_DEG 3
#define U_RAD 4

  // Construct our AS5048B object with an I2C address of 0x40
AMS_AS5048B mysensor(0x40);

  // Reset everything to ZERO on startup/reset button
bool rst(bool toZero){
  if(toZero = true){
    mysensor.zeroRegW(0x0);
    mysensor.setZeroReg();
    // mysensor.resetMovingAvgExp(); // this carries the average angle value
    } else {};
  return toZero;
  }

// Set units for angle & frequency
uint16_t selectUnit(String unit, int freq) {
    // Angles in degrees
    if(unit == "Deg"){ 
      Serial.print(" " + unit + "rees: ");
      float temp = mysensor.angleR(U_DEG, true);
      if(temp > 359.8){ temp = 0;} // corrects a tiny sensitivity at start-up
      Serial.println(temp);
      }
    // Angle in radians
     else if(unit == "Rad") {
        float rad = (mysensor.angleR(U_RAD, true));
        Serial.println(" " + unit + "ians: " + rad);
     }
     delay(freq);
     return unit, freq;
    }

// Read angle values
int angleVal(int serial, bool cw, bool reset_it) {
  Serial.begin(serial);
  while (!Serial) ;
  mysensor.begin();
  mysensor.setClockWise(cw); 
  mysensor.addressRegW(0x01);
  mysensor.doProg();
  mysensor.zeroRegW(0x0);
  mysensor.setZeroReg();
  // mysensor.resetMovingAvgExp(); // use this with the average above
  return serial, cw, rst(reset_it);
  }
