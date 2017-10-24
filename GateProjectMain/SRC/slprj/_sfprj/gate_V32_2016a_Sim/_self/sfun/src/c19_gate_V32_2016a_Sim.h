#ifndef __c19_gate_V32_2016a_Sim_h__
#define __c19_gate_V32_2016a_Sim_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_gate_V32_2016a_SimInstanceStruct
#define typedef_SFc19_gate_V32_2016a_SimInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  uint8_T c19_tp_MonitorChange;
  uint8_T c19_tp_UpdatePins;
  uint8_T c19_is_active_c19_gate_V32_2016a_Sim;
  uint8_T c19_is_c19_gate_V32_2016a_Sim;
  uint8_T c19_doSetSimStateSideEffects;
  const mxArray *c19_setSimStateSideEffectsInfo;
  boolean_T *c19_LeftMotorPin_BOOL;
  boolean_T *c19_ComMotorPin_BOOL;
  boolean_T *c19_RightMotorPin_BOOL;
  uint8_T *c19_leftMotor;
  uint8_T *c19_oldLeft;
  uint8_T *c19_rightMotor;
  uint8_T *c19_oldRight;
  uint8_T *c19_CLOSED;
  uint8_T *c19_CLOSING;
  uint8_T *c19_OPEN;
  uint8_T *c19_OPENING;
} SFc19_gate_V32_2016a_SimInstanceStruct;

#endif                                 /*typedef_SFc19_gate_V32_2016a_SimInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_gate_V32_2016a_Sim_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c19_gate_V32_2016a_Sim_get_check_sum(mxArray *plhs[]);
extern void c19_gate_V32_2016a_Sim_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
