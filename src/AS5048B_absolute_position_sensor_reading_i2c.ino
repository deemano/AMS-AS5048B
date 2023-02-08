/**************************************************************************/
/*!
    @file     AM5048_AbsDegAngle.ino
    @author   murtdoc (twitterID) [rebuit on top of brentyi's work, BSD]
    @license  OpenSource for non-commercial use only

*/
/**************************************************************************/

#include "ams_as5048b.h"
#include "shorty.h"
  
void setup() {

	// angleVal(serial port [int], clockwise [bool], reset [bool])
	angleVal(9600, true, true);

}

void loop() {
  
  // slectUnit("Deg/Rad", frequency)
  selectUnit("Deg", 100);

}
