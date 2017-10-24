#ifndef __c20_gate_V32_2016a_Sim_h__
#define __c20_gate_V32_2016a_Sim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_gate_V32_2016a_SimInstanceStruct
#define typedef_SFc20_gate_V32_2016a_SimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  uint8_T c20_tp_opening;
  uint8_T c20_tp_openLeftSide;
  uint8_T c20_tp_openRightSide;
  uint8_T c20_tp_init;
  uint8_T c20_tp_AssignPass;
  uint8_T c20_tp_addToPass;
  uint8_T c20_tp_MonitoringNumber;
  uint8_T c20_tp_PassAssigned;
  uint8_T c20_tp_idle;
  uint8_T c20_tp_PassAssignedPreviously;
  uint8_T c20_tp_closed;
  uint8_T c20_tp_openingGate;
  uint8_T c20_tp_MonitorInput;
  uint8_T c20_tp_KpPassHandler;
  uint8_T c20_tp_monitorBtnPressed;
  uint8_T c20_tp_btnPressed;
  uint8_T c20_tp_initTrailPass;
  uint8_T c20_tp_initiatePass;
  uint8_T c20_tp_verifyPass;
  uint8_T c20_tp_closing;
  uint8_T c20_tp_closingRightSide;
  uint8_T c20_tp_closingLeftSide;
  uint8_T c20_tp_open;
  uint8_T c20_tp_gateOpen;
  uint8_T c20_b_tp_closing;
  uint8_T c20_is_active_c20_gate_V32_2016a_Sim;
  uint8_T c20_is_c20_gate_V32_2016a_Sim;
  uint8_T c20_is_opening;
  uint8_T c20_is_init;
  uint8_T c20_is_AssignPass;
  uint8_T c20_is_closed;
  uint8_T c20_is_KpPassHandler;
  uint8_T c20_is_initTrailPass;
  uint8_T c20_is_closing;
  uint8_T c20_is_open;
  uint8_T c20_openingActive;
  uint8_T c20_trialPass[6];
  uint8_T c20_counter;
  uint8_T c20_closing_active;
  uint8_T c20_initCounter;
  uint16_T c20_openSideDelay;
  uint16_T c20_closeSideDelay;
  boolean_T c20_gotoReady;
  uint16_T c20_passTimer;
  uint32_T c20_stableTimer;
  uint32_T c20_closingTimer;
  uint32_T c20_openingTimer;
  uint8_T c20_KpCharPressed_prev;
  uint8_T c20_KpCharPressed_start;
  uint8_T c20_RFPressedOut_UINT8_prev;
  uint8_T c20_RFPressedOut_UINT8_start;
  boolean_T c20_passSwitch_prev;
  boolean_T c20_passSwitch_start;
  uint8_T c20_doSetSimStateSideEffects;
  const mxArray *c20_setSimStateSideEffectsInfo;
  uint8_T *c20_KpCharPressed;
  uint8_T *c20_RFPressedOut_UINT8;
  boolean_T *c20_passSwitch;
  boolean_T *c20_current_sensor;
  uint8_T *c20_leftMotor;
  uint8_T *c20_rightMotor;
  boolean_T *c20_bulbPin_BOOL;
  uint8_T *c20_OPENING_ACTIVE;
  uint8_T *c20_WRONG_PASSWORD;
  uint16_T *c20_OPEN_SIDE_VALUE;
  real32_T *c20_CLOSE_SIDE_VALUE;
  uint8_T *c20_PASSWORD_VERIFIED;
  uint8_T *c20_CLOSE_CHAR;
  uint8_T *c20_OPEN_CHAR;
  uint8_T *c20_OPENING;
  uint8_T *c20_CLOSED;
  uint8_T *c20_CLOSING;
  uint8_T *c20_OPEN;
  boolean_T *c20_passAssignedRAM_BOOL;
  uint8_T *c20_passSuccess;
  uint8_T *c20_NO_PASS_ASSIG;
  uint8_T *c20_PASS_ASSIGNED;
  uint8_T *c20_PASS_INCOMPLETE;
  uint16_T *c20_PASS_TIMEOUT;
  uint8_T *c20_TIMEOUT;
  uint8_T (*c20_passwordRAM_UINT8_6D)[6];
  uint8_T (*c20_passwordIn)[6];
  boolean_T *c20_passAssignedIn;
  uint8_T *c20_gateState;
  uint8_T *c20_INIT;
  uint32_T *c20_MOVING_TIMER;
} SFc20_gate_V32_2016a_SimInstanceStruct;

#endif                                 /*typedef_SFc20_gate_V32_2016a_SimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_gate_V32_2016a_Sim_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c20_gate_V32_2016a_Sim_get_check_sum(mxArray *plhs[]);
extern void c20_gate_V32_2016a_Sim_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
