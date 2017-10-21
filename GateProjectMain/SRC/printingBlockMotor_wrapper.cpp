

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

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
extern "C" void printingBlockMotor_Outputs_wrapper(const uint8_T *leftMotor,
			const uint8_T *rightMotor,
			const uint8_T *leftCurr,
			const uint8_T *rightCurr,
			const uint16_T *rightCurrRaw,
			const uint16_T *leftCurrRaw)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
#ifndef MATLAB_MEX_FILE
static bool x = true;
if(x)
{
    Serial.begin(9600);
    x = false;
}
Serial.print("leftMotor: ");
Serial.print(*leftMotor);
Serial.print("  leftCurr: ");
Serial.print(*leftCurr);
Serial.print(" leftCurrRaw: ");
Serial.print(*leftCurrRaw);

Serial.print("  rightMotor: ");
Serial.print(*rightMotor);
Serial.print("  rightCurr: ");
Serial.print(*rightCurr);
Serial.print(" rightCurrRaw: ");
Serial.println(*rightCurrRaw);
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
