

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

#define ARDUINO 100
#include <Arduino.h>
#include "EEPROM.cpp"
#include "EEPROM.h"

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 6
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
extern "C" void myEEPROM_Handler_Outputs_wrapper(const uint8_T *passwordIn,
			const boolean_T *readReq,
			const boolean_T *oldReadReq,
			const boolean_T *clearReq,
			const boolean_T *oldClearReq,
			const boolean_T *writeReq,
			const boolean_T *oldWriteReq,
			const boolean_T *passAssignedIn,
			uint8_T *passwordOut,
			boolean_T *readComplete,
			boolean_T *writeComplete,
			boolean_T *clearComplete,
			boolean_T *passAssignedOut)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
//Serial.println("enterEEPROM");
if((*readReq != *oldReadReq) && (*readReq == true))
{
#ifdef MIL
    passwordOut[0] = 48;
    passwordOut[1] = 49;
    passwordOut[2] = 50;
    passwordOut[3] = 51;
    passwordOut[4] = 52;
    passwordOut[5] = 53;
    *passAssignedOut = false;
#else
    
    passwordOut[0] = EEPROM.read(0);
    passwordOut[1] = EEPROM.read(1);
    passwordOut[2] = EEPROM.read(2);
    passwordOut[3] = EEPROM.read(3);
    passwordOut[4] = EEPROM.read(4);
    passwordOut[5] = EEPROM.read(5);
    *passAssignedOut = EEPROM.read(6);
    //Serial.println(*passAssignedOut);
     
#endif
    *readComplete = true;
}
else if((*writeReq != *oldWriteReq) && (*writeReq == true))
{
#ifdef MIL
    passwordOut[0] = passwordIn[0];
    passwordOut[1] = passwordIn[1];
    passwordOut[2] = passwordIn[2];
    passwordOut[3] = passwordIn[3];
    passwordOut[4] = passwordIn[4];
    passwordOut[5] = passwordIn[5];
    //*passAssignedIn = true;
#else
    
    EEPROM.write(0, passwordIn[0]);
    EEPROM.write(1, passwordIn[1]);
    EEPROM.write(2, passwordIn[2]);
    EEPROM.write(3, passwordIn[3]);
    EEPROM.write(4, passwordIn[4]);
    EEPROM.write(5, passwordIn[5]);
    EEPROM.write(6, true);
     
#endif
    *writeComplete = true;
}
else if((*clearReq != *oldClearReq) && (*clearReq == true))
{
#ifdef MIL
    passwordOut[0] = 0;
    passwordOut[1] = 0;
    passwordOut[2] = 0;
    passwordOut[3] = 0;
    passwordOut[4] = 0;
    passwordOut[5] = 0;
    *passAssignedOut = false;
#else
    
    EEPROM.write(0,0);
    EEPROM.write(1,0);
    EEPROM.write(2,0);
    EEPROM.write(3,0);
    EEPROM.write(4,0);
    EEPROM.write(5,0);
    EEPROM.write(6,0);
    passwordOut[0] = 0;
    passwordOut[1] = 0;
    passwordOut[2] = 0;
    passwordOut[3] = 0;
    passwordOut[4] = 0;
    passwordOut[5] = 0;
    *passAssignedOut = false;
#endif
    *clearComplete = true;
}
else
{
    *readComplete = false;
    *writeComplete = false;
    *clearComplete = false;
}
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
