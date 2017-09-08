

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
#include <Bounce2.h>
#include <Bounce2.cpp>

#define RF_BUTTON 10
#define SW_BUTTON 9

// Instantiate a Bounce object
Bounce RF_Bouncer = Bounce(); 
Bounce SW_Bouncer = Bounce();

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
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
extern "C" void Button_Lib_Outputs_wrapper(boolean_T *RFInput,
			boolean_T *passSw)
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
static bool flag = true;

if(flag)
{
  // Setup the button with an internal pull-up :
  pinMode(RF_BUTTON, INPUT_PULLUP);
  pinMode(SW_BUTTON, INPUT_PULLUP);

  // After setting up the button, setup the Bounce instance :
  RF_Bouncer.attach(RF_BUTTON);
  RF_Bouncer.interval(5); // interval in ms
  
  SW_Bouncer.attach(SW_BUTTON);
  SW_Bouncer.interval(5); // interval in ms
  flag = false;
}

RF_Bouncer.update();
SW_Bouncer.update();
  // Get the updated value :
  int RfValue = RF_Bouncer.read();
  int SwValue = SW_Bouncer.read();

  // Turn on or off the LED as determined by the state :
  if (RfValue == HIGH) 
  {
      *RFInput = true;
  }
  else
  {
      *RFInput = false;
  }
  
  if(SwValue == HIGH)
  {
      *passSw = true;
  }
  else
  {
      *passSw = false;
  }
  #endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
