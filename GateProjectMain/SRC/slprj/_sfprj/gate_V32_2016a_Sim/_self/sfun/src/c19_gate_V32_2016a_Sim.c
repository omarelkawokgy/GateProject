/* Include files */

#include "gate_V32_2016a_Sim_sfun.h"
#include "c19_gate_V32_2016a_Sim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "gate_V32_2016a_Sim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c19_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c19_IN_MonitorChange           ((uint8_T)1U)
#define c19_IN_UpdatePins              ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void initialize_params_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void enable_c19_gate_V32_2016a_Sim(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void disable_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void set_sim_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c19_st);
static void c19_set_sim_state_side_effects_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void finalize_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void sf_gateway_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void mdl_start_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void initSimStructsc19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c19_enter_internal_UpdatePins(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static uint8_T c19_b_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_b_tp_MonitorChange, const char_T
  *c19_identifier);
static uint8_T c19_c_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static boolean_T c19_d_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_b_LeftMotorPin_BOOL, const char_T
  *c19_identifier);
static boolean_T c19_e_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_f_emlrt_marshallIn
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray
   *c19_b_setSimStateSideEffectsInfo, const char_T *c19_identifier);
static const mxArray *c19_g_emlrt_marshallIn
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c19_u,
   const emlrtMsgIdentifier *c19_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, int32_T c19_ssid);
static void c19_init_sf_message_store_memory
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc19_gate_V32_2016a_Sim(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_doSetSimStateSideEffects = 0U;
  chartInstance->c19_setSimStateSideEffectsInfo = NULL;
  chartInstance->c19_tp_MonitorChange = 0U;
  chartInstance->c19_tp_UpdatePins = 0U;
  chartInstance->c19_is_active_c19_gate_V32_2016a_Sim = 0U;
  chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c19_LeftMotorPin_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL, 8U, 1U,
                          2U, (int16_T)chartInstance->c19_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c19_ComMotorPin_BOOL = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL, 9U, 1U,
                          2U, (int16_T)chartInstance->c19_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c19_RightMotorPin_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL, 10U,
                          1U, 2U, (int16_T)chartInstance->c19_sfEvent, false);
  }
}

static void initialize_params_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_gate_V32_2016a_Sim(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  uint32_T c19_prevAniVal;
  c19_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c19_is_active_c19_gate_V32_2016a_Sim == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
  }

  if (chartInstance->c19_is_c19_gate_V32_2016a_Sim == c19_IN_MonitorChange) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
  }

  if (chartInstance->c19_is_c19_gate_V32_2016a_Sim == c19_IN_UpdatePins) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
  }

  _SFD_SET_ANIMATION(c19_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  boolean_T c19_hoistedGlobal;
  boolean_T c19_u;
  const mxArray *c19_b_y = NULL;
  boolean_T c19_b_hoistedGlobal;
  boolean_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  boolean_T c19_c_hoistedGlobal;
  boolean_T c19_c_u;
  const mxArray *c19_d_y = NULL;
  uint8_T c19_d_hoistedGlobal;
  uint8_T c19_d_u;
  const mxArray *c19_e_y = NULL;
  uint8_T c19_e_hoistedGlobal;
  uint8_T c19_e_u;
  const mxArray *c19_f_y = NULL;
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(5, 1), false);
  c19_hoistedGlobal = *chartInstance->c19_ComMotorPin_BOOL;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = *chartInstance->c19_LeftMotorPin_BOOL;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  c19_c_hoistedGlobal = *chartInstance->c19_RightMotorPin_BOOL;
  c19_c_u = c19_c_hoistedGlobal;
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 2, c19_d_y);
  c19_d_hoistedGlobal = chartInstance->c19_is_active_c19_gate_V32_2016a_Sim;
  c19_d_u = c19_d_hoistedGlobal;
  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 3, c19_e_y);
  c19_e_hoistedGlobal = chartInstance->c19_is_c19_gate_V32_2016a_Sim;
  c19_e_u = c19_e_hoistedGlobal;
  c19_f_y = NULL;
  sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 4, c19_f_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c19_st)
{
  const mxArray *c19_u;
  c19_u = sf_mex_dup(c19_st);
  *chartInstance->c19_ComMotorPin_BOOL = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("ComMotorPin_BOOL", c19_u, 0)), "ComMotorPin_BOOL");
  *chartInstance->c19_LeftMotorPin_BOOL = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("LeftMotorPin_BOOL", c19_u, 1)),
    "LeftMotorPin_BOOL");
  *chartInstance->c19_RightMotorPin_BOOL = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("RightMotorPin_BOOL", c19_u, 2)),
    "RightMotorPin_BOOL");
  chartInstance->c19_is_active_c19_gate_V32_2016a_Sim = c19_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c19_gate_V32_2016a_Sim",
       c19_u, 3)), "is_active_c19_gate_V32_2016a_Sim");
  chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c19_gate_V32_2016a_Sim", c19_u,
       4)), "is_c19_gate_V32_2016a_Sim");
  sf_mex_assign(&chartInstance->c19_setSimStateSideEffectsInfo,
                c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c19_u, 5)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c19_u);
  chartInstance->c19_doSetSimStateSideEffects = 1U;
  c19_update_debugger_state_c19_gate_V32_2016a_Sim(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void c19_set_sim_state_side_effects_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  if (chartInstance->c19_doSetSimStateSideEffects != 0) {
    chartInstance->c19_tp_MonitorChange = (uint8_T)
      (chartInstance->c19_is_c19_gate_V32_2016a_Sim == c19_IN_MonitorChange);
    chartInstance->c19_tp_UpdatePins = (uint8_T)
      (chartInstance->c19_is_c19_gate_V32_2016a_Sim == c19_IN_UpdatePins);
    chartInstance->c19_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c19_setSimStateSideEffectsInfo);
}

static void sf_gateway_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c19_temp;
  boolean_T c19_b_temp;
  boolean_T c19_c_temp;
  boolean_T c19_out;
  c19_set_sim_state_side_effects_c19_gate_V32_2016a_Sim(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_OPENING, 7U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_OPEN, 6U, 1U, 0U, (int16_T)
                        chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_CLOSING, 5U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_CLOSED, 4U, 1U, 0U, (int16_T)
                        chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_oldRight, 3U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_rightMotor, 2U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_oldLeft, 1U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_leftMotor, 0U, 1U, 0U,
                        (int16_T)chartInstance->c19_sfEvent, false);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
  if (chartInstance->c19_is_active_c19_gate_V32_2016a_Sim == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
    chartInstance->c19_is_active_c19_gate_V32_2016a_Sim = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
    chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_IN_MonitorChange;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
    chartInstance->c19_tp_MonitorChange = 1U;
  } else {
    switch (chartInstance->c19_is_c19_gate_V32_2016a_Sim) {
     case c19_IN_MonitorChange:
      CV_CHART_EVAL(2, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c19_sfEvent);
      c19_temp = (_SFD_CCP_CALL(1U, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
        *chartInstance->c19_leftMotor, (real_T)*chartInstance->c19_oldLeft, 0,
        1U, *chartInstance->c19_leftMotor != *chartInstance->c19_oldLeft) != 0U,
        chartInstance->c19_sfEvent) != 0);
      if (!c19_temp) {
        c19_temp = (_SFD_CCP_CALL(1U, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, (real_T)
          *chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_oldRight,
          0, 1U, *chartInstance->c19_rightMotor != *chartInstance->c19_oldRight)
          != 0U, chartInstance->c19_sfEvent) != 0);
      }

      c19_b_temp = c19_temp;
      if (!c19_b_temp) {
        c19_c_temp = (_SFD_CCP_CALL(1U, 2, CV_RELATIONAL_EVAL(5U, 1U, 2, (real_T)*
          chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_CLOSED, 0,
          0U, *chartInstance->c19_rightMotor == *chartInstance->c19_CLOSED) !=
          0U, chartInstance->c19_sfEvent) != 0);
        if (c19_c_temp) {
          c19_c_temp = (_SFD_CCP_CALL(1U, 3, CV_RELATIONAL_EVAL(5U, 1U, 3,
            (real_T)*chartInstance->c19_leftMotor, (real_T)
            *chartInstance->c19_CLOSED, 0, 0U, *chartInstance->c19_leftMotor == *
            chartInstance->c19_CLOSED) != 0U, chartInstance->c19_sfEvent) != 0);
        }

        c19_b_temp = c19_c_temp;
      }

      c19_out = (CV_TRANSITION_EVAL(1U, (int32_T)c19_b_temp) != 0);
      if (c19_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_MonitorChange = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
        chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_IN_UpdatePins;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_UpdatePins = 1U;
        c19_enter_internal_UpdatePins(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c19_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c19_sfEvent);
      break;

     case c19_IN_UpdatePins:
      CV_CHART_EVAL(2, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c19_sfEvent);
      chartInstance->c19_tp_UpdatePins = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
      chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_IN_MonitorChange;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
      chartInstance->c19_tp_MonitorChange = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c19_sfEvent);
      break;

     default:
      CV_CHART_EVAL(2, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c19_is_c19_gate_V32_2016a_Sim = c19_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_gate_V32_2016a_SimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  c19_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc19_gate_V32_2016a_Sim
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c19_enter_internal_UpdatePins(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  boolean_T c19_temp;
  boolean_T c19_b_temp;
  boolean_T c19_out;
  boolean_T c19_c_temp;
  boolean_T c19_d_temp;
  boolean_T c19_b_out;
  boolean_T c19_e_temp;
  boolean_T c19_f_temp;
  boolean_T c19_c_out;
  boolean_T c19_g_temp;
  boolean_T c19_h_temp;
  boolean_T c19_d_out;
  boolean_T c19_i_temp;
  boolean_T c19_e_out;
  boolean_T c19_j_temp;
  boolean_T c19_f_out;
  boolean_T c19_k_temp;
  boolean_T c19_l_temp;
  boolean_T c19_m_temp;
  boolean_T c19_g_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c19_sfEvent);
  c19_temp = (_SFD_CCP_CALL(3U, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
    *chartInstance->c19_leftMotor, (real_T)*chartInstance->c19_OPENING, 0, 0U,
    *chartInstance->c19_leftMotor == *chartInstance->c19_OPENING) != 0U,
    chartInstance->c19_sfEvent) != 0);
  if (c19_temp) {
    c19_b_temp = (_SFD_CCP_CALL(3U, 1, CV_RELATIONAL_EVAL(5U, 3U, 1, (real_T)
      *chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_CLOSED, 0, 0U,
      *chartInstance->c19_rightMotor == *chartInstance->c19_CLOSED) != 0U,
      chartInstance->c19_sfEvent) != 0);
    if (!c19_b_temp) {
      c19_b_temp = (_SFD_CCP_CALL(3U, 2, CV_RELATIONAL_EVAL(5U, 3U, 2, (real_T)
        *chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_OPEN, 0, 0U,
        *chartInstance->c19_rightMotor == *chartInstance->c19_OPEN) != 0U,
        chartInstance->c19_sfEvent) != 0);
    }

    c19_temp = c19_b_temp;
  }

  c19_out = (CV_TRANSITION_EVAL(3U, (int32_T)c19_temp) != 0);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  if (c19_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c19_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c19_sfEvent);
    *chartInstance->c19_LeftMotorPin_BOOL = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL, 8U, 5U,
                          5U, (int16_T)chartInstance->c19_sfEvent, false);
    *chartInstance->c19_ComMotorPin_BOOL = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL, 9U, 5U,
                          5U, (int16_T)chartInstance->c19_sfEvent, false);
    *chartInstance->c19_RightMotorPin_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL, 10U,
                          5U, 5U, (int16_T)chartInstance->c19_sfEvent, false);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c19_sfEvent);
    guard6 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c19_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 chartInstance->c19_sfEvent);
    c19_c_temp = (_SFD_CCP_CALL(6U, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
      *chartInstance->c19_leftMotor, (real_T)*chartInstance->c19_CLOSING, 0, 0U,
      *chartInstance->c19_leftMotor == *chartInstance->c19_CLOSING) != 0U,
      chartInstance->c19_sfEvent) != 0);
    if (c19_c_temp) {
      c19_d_temp = (_SFD_CCP_CALL(6U, 1, CV_RELATIONAL_EVAL(5U, 6U, 1, (real_T)
        *chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_CLOSED, 0,
        0U, *chartInstance->c19_rightMotor == *chartInstance->c19_CLOSED) != 0U,
        chartInstance->c19_sfEvent) != 0);
      if (!c19_d_temp) {
        c19_d_temp = (_SFD_CCP_CALL(6U, 2, CV_RELATIONAL_EVAL(5U, 6U, 2, (real_T)*
          chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_OPEN, 0, 0U,
          *chartInstance->c19_rightMotor == *chartInstance->c19_OPEN) != 0U,
          chartInstance->c19_sfEvent) != 0);
      }

      c19_c_temp = c19_d_temp;
    }

    c19_b_out = (CV_TRANSITION_EVAL(6U, (int32_T)c19_c_temp) != 0);
    if (c19_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c19_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c19_sfEvent);
      *chartInstance->c19_LeftMotorPin_BOOL = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL, 8U,
                            5U, 8U, (int16_T)chartInstance->c19_sfEvent, false);
      *chartInstance->c19_ComMotorPin_BOOL = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL, 9U, 5U,
                            8U, (int16_T)chartInstance->c19_sfEvent, false);
      *chartInstance->c19_RightMotorPin_BOOL = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL, 10U,
                            5U, 8U, (int16_T)chartInstance->c19_sfEvent, false);
      guard6 = true;
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c19_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c19_sfEvent);
      c19_e_temp = (_SFD_CCP_CALL(9U, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, (real_T)
        *chartInstance->c19_rightMotor, (real_T)*chartInstance->c19_CLOSING, 0,
        0U, *chartInstance->c19_rightMotor == *chartInstance->c19_CLOSING) != 0U,
        chartInstance->c19_sfEvent) != 0);
      if (c19_e_temp) {
        c19_f_temp = (_SFD_CCP_CALL(9U, 1, CV_RELATIONAL_EVAL(5U, 9U, 1, (real_T)*
          chartInstance->c19_leftMotor, (real_T)*chartInstance->c19_CLOSED, 0,
          0U, *chartInstance->c19_leftMotor == *chartInstance->c19_CLOSED) != 0U,
          chartInstance->c19_sfEvent) != 0);
        if (!c19_f_temp) {
          c19_f_temp = (_SFD_CCP_CALL(9U, 2, CV_RELATIONAL_EVAL(5U, 9U, 2,
            (real_T)*chartInstance->c19_leftMotor, (real_T)
            *chartInstance->c19_OPEN, 0, 0U, *chartInstance->c19_leftMotor ==
            *chartInstance->c19_OPEN) != 0U, chartInstance->c19_sfEvent) != 0);
        }

        c19_e_temp = c19_f_temp;
      }

      c19_c_out = (CV_TRANSITION_EVAL(9U, (int32_T)c19_e_temp) != 0);
      if (c19_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c19_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c19_sfEvent);
        *chartInstance->c19_LeftMotorPin_BOOL = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL, 8U,
                              5U, 10U, (int16_T)chartInstance->c19_sfEvent,
                              false);
        *chartInstance->c19_ComMotorPin_BOOL = false;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL, 9U,
                              5U, 10U, (int16_T)chartInstance->c19_sfEvent,
                              false);
        *chartInstance->c19_RightMotorPin_BOOL = false;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL,
                              10U, 5U, 10U, (int16_T)chartInstance->c19_sfEvent,
                              false);
        guard5 = true;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c19_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                     chartInstance->c19_sfEvent);
        c19_g_temp = (_SFD_CCP_CALL(15U, 0, CV_RELATIONAL_EVAL(5U, 15U, 0,
          (real_T)*chartInstance->c19_rightMotor, (real_T)
          *chartInstance->c19_OPENING, 0, 0U, *chartInstance->c19_rightMotor == *
          chartInstance->c19_OPENING) != 0U, chartInstance->c19_sfEvent) != 0);
        if (c19_g_temp) {
          c19_h_temp = (_SFD_CCP_CALL(15U, 1, CV_RELATIONAL_EVAL(5U, 15U, 1,
            (real_T)*chartInstance->c19_leftMotor, (real_T)
            *chartInstance->c19_CLOSED, 0, 0U, *chartInstance->c19_leftMotor == *
            chartInstance->c19_CLOSED) != 0U, chartInstance->c19_sfEvent) != 0);
          if (!c19_h_temp) {
            c19_h_temp = (_SFD_CCP_CALL(15U, 2, CV_RELATIONAL_EVAL(5U, 15U, 2,
              (real_T)*chartInstance->c19_leftMotor, (real_T)
              *chartInstance->c19_OPEN, 0, 0U, *chartInstance->c19_leftMotor == *
              chartInstance->c19_OPEN) != 0U, chartInstance->c19_sfEvent) != 0);
          }

          c19_g_temp = c19_h_temp;
        }

        c19_d_out = (CV_TRANSITION_EVAL(15U, (int32_T)c19_g_temp) != 0);
        if (c19_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c19_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c19_sfEvent);
          *chartInstance->c19_LeftMotorPin_BOOL = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL,
                                8U, 5U, 18U, (int16_T)chartInstance->c19_sfEvent,
                                false);
          *chartInstance->c19_ComMotorPin_BOOL = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL, 9U,
                                5U, 18U, (int16_T)chartInstance->c19_sfEvent,
                                false);
          *chartInstance->c19_RightMotorPin_BOOL = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL,
                                10U, 5U, 18U, (int16_T)
                                chartInstance->c19_sfEvent, false);
          guard4 = true;
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c19_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                       chartInstance->c19_sfEvent);
          c19_i_temp = (_SFD_CCP_CALL(17U, 0, CV_RELATIONAL_EVAL(5U, 17U, 0,
            (real_T)*chartInstance->c19_rightMotor, (real_T)
            *chartInstance->c19_OPENING, 0, 0U, *chartInstance->c19_rightMotor ==
            *chartInstance->c19_OPENING) != 0U, chartInstance->c19_sfEvent) != 0);
          if (c19_i_temp) {
            c19_i_temp = (_SFD_CCP_CALL(17U, 1, CV_RELATIONAL_EVAL(5U, 17U, 1,
              (real_T)*chartInstance->c19_leftMotor, (real_T)
              *chartInstance->c19_OPENING, 0, 0U, *chartInstance->c19_leftMotor ==
              *chartInstance->c19_OPENING) != 0U, chartInstance->c19_sfEvent) !=
                          0);
          }

          c19_e_out = (CV_TRANSITION_EVAL(17U, (int32_T)c19_i_temp) != 0);
          if (c19_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c19_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c19_sfEvent);
            *chartInstance->c19_LeftMotorPin_BOOL = true;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_LeftMotorPin_BOOL,
                                  8U, 5U, 19U, (int16_T)
                                  chartInstance->c19_sfEvent, false);
            *chartInstance->c19_ComMotorPin_BOOL = true;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL,
                                  9U, 5U, 19U, (int16_T)
                                  chartInstance->c19_sfEvent, false);
            *chartInstance->c19_RightMotorPin_BOOL = true;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_RightMotorPin_BOOL,
                                  10U, 5U, 19U, (int16_T)
                                  chartInstance->c19_sfEvent, false);
            guard3 = true;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c19_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                         chartInstance->c19_sfEvent);
            c19_j_temp = (_SFD_CCP_CALL(20U, 0, CV_RELATIONAL_EVAL(5U, 20U, 0,
              (real_T)*chartInstance->c19_rightMotor, (real_T)
              *chartInstance->c19_CLOSING, 0, 0U, *chartInstance->c19_rightMotor
              == *chartInstance->c19_CLOSING) != 0U, chartInstance->c19_sfEvent)
                          != 0);
            if (c19_j_temp) {
              c19_j_temp = (_SFD_CCP_CALL(20U, 1, CV_RELATIONAL_EVAL(5U, 20U, 1,
                (real_T)*chartInstance->c19_leftMotor, (real_T)
                *chartInstance->c19_CLOSING, 0, 0U,
                *chartInstance->c19_leftMotor == *chartInstance->c19_CLOSING) !=
                0U, chartInstance->c19_sfEvent) != 0);
            }

            c19_f_out = (CV_TRANSITION_EVAL(20U, (int32_T)c19_j_temp) != 0);
            if (c19_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U,
                           chartInstance->c19_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U,
                           chartInstance->c19_sfEvent);
              *chartInstance->c19_LeftMotorPin_BOOL = false;
              _SFD_DATA_RANGE_CHECK((real_T)
                                    *chartInstance->c19_LeftMotorPin_BOOL, 8U,
                                    5U, 22U, (int16_T)chartInstance->c19_sfEvent,
                                    false);
              *chartInstance->c19_ComMotorPin_BOOL = false;
              _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c19_ComMotorPin_BOOL,
                                    9U, 5U, 22U, (int16_T)
                                    chartInstance->c19_sfEvent, false);
              *chartInstance->c19_RightMotorPin_BOOL = false;
              _SFD_DATA_RANGE_CHECK((real_T)
                                    *chartInstance->c19_RightMotorPin_BOOL, 10U,
                                    5U, 22U, (int16_T)chartInstance->c19_sfEvent,
                                    false);
              guard2 = true;
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U,
                           chartInstance->c19_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                           chartInstance->c19_sfEvent);
              c19_k_temp = (_SFD_CCP_CALL(27U, 0, CV_RELATIONAL_EVAL(5U, 27U, 0,
                (real_T)*chartInstance->c19_rightMotor, (real_T)
                *chartInstance->c19_CLOSED, 0, 0U,
                *chartInstance->c19_rightMotor == *chartInstance->c19_CLOSED) !=
                0U, chartInstance->c19_sfEvent) != 0);
              if (!c19_k_temp) {
                c19_k_temp = (_SFD_CCP_CALL(27U, 1, CV_RELATIONAL_EVAL(5U, 27U,
                  1, (real_T)*chartInstance->c19_rightMotor, (real_T)
                  *chartInstance->c19_OPEN, 0, 0U,
                  *chartInstance->c19_rightMotor == *chartInstance->c19_OPEN) !=
                  0U, chartInstance->c19_sfEvent) != 0);
              }

              c19_l_temp = c19_k_temp;
              if (c19_l_temp) {
                c19_m_temp = (_SFD_CCP_CALL(27U, 2, CV_RELATIONAL_EVAL(5U, 27U,
                  2, (real_T)*chartInstance->c19_leftMotor, (real_T)
                  *chartInstance->c19_CLOSED, 0, 0U,
                  *chartInstance->c19_leftMotor == *chartInstance->c19_CLOSED)
                  != 0U, chartInstance->c19_sfEvent) != 0);
                if (!c19_m_temp) {
                  c19_m_temp = (_SFD_CCP_CALL(27U, 3, CV_RELATIONAL_EVAL(5U, 27U,
                    3, (real_T)*chartInstance->c19_leftMotor, (real_T)
                    *chartInstance->c19_OPEN, 0, 0U,
                    *chartInstance->c19_leftMotor == *chartInstance->c19_OPEN)
                    != 0U, chartInstance->c19_sfEvent) != 0);
                }

                c19_l_temp = c19_m_temp;
              }

              c19_g_out = (CV_TRANSITION_EVAL(27U, (int32_T)c19_l_temp) != 0);
              if (c19_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U,
                             chartInstance->c19_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U,
                             chartInstance->c19_sfEvent);
                *chartInstance->c19_LeftMotorPin_BOOL = false;
                _SFD_DATA_RANGE_CHECK((real_T)
                                      *chartInstance->c19_LeftMotorPin_BOOL, 8U,
                                      5U, 28U, (int16_T)
                                      chartInstance->c19_sfEvent, false);
                *chartInstance->c19_ComMotorPin_BOOL = true;
                _SFD_DATA_RANGE_CHECK((real_T)
                                      *chartInstance->c19_ComMotorPin_BOOL, 9U,
                                      5U, 28U, (int16_T)
                                      chartInstance->c19_sfEvent, false);
                *chartInstance->c19_RightMotorPin_BOOL = false;
                _SFD_DATA_RANGE_CHECK((real_T)
                                      *chartInstance->c19_RightMotorPin_BOOL,
                                      10U, 5U, 28U, (int16_T)
                                      chartInstance->c19_sfEvent, false);
                guard1 = true;
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U,
                             chartInstance->c19_sfEvent);
              }
            }
          }
        }
      }
    }
  }

  if (guard6 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c19_sfEvent);
    guard5 = true;
  }

  if (guard5 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c19_sfEvent);
    guard4 = true;
  }

  if (guard4 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c19_sfEvent);
    guard3 = true;
  }

  if (guard3 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c19_sfEvent);
    guard2 = true;
  }

  if (guard2 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c19_sfEvent);
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c19_sfEvent);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c19_sfEvent);
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

const mxArray *sf_c19_gate_V32_2016a_Sim_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i0, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  uint8_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(uint8_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static uint8_T c19_b_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_b_tp_MonitorChange, const char_T
  *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_tp_MonitorChange), &c19_thisId);
  sf_mex_destroy(&c19_b_tp_MonitorChange);
  return c19_y;
}

static uint8_T c19_c_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_tp_MonitorChange;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  uint8_T c19_y;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_b_tp_MonitorChange = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_tp_MonitorChange), &c19_thisId);
  sf_mex_destroy(&c19_b_tp_MonitorChange);
  *(uint8_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  boolean_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(boolean_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static boolean_T c19_d_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_b_LeftMotorPin_BOOL, const char_T
  *c19_identifier)
{
  boolean_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_LeftMotorPin_BOOL), &c19_thisId);
  sf_mex_destroy(&c19_b_LeftMotorPin_BOOL);
  return c19_y;
}

static boolean_T c19_e_emlrt_marshallIn(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  boolean_T c19_y;
  boolean_T c19_b0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_b0, 1, 11, 0U, 0, 0U, 0);
  c19_y = c19_b0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_LeftMotorPin_BOOL;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  boolean_T c19_y;
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c19_b_LeftMotorPin_BOOL = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_LeftMotorPin_BOOL), &c19_thisId);
  sf_mex_destroy(&c19_b_LeftMotorPin_BOOL);
  *(boolean_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_f_emlrt_marshallIn
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray
   *c19_b_setSimStateSideEffectsInfo, const char_T *c19_identifier)
{
  const mxArray *c19_y = NULL;
  emlrtMsgIdentifier c19_thisId;
  c19_y = NULL;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  sf_mex_assign(&c19_y, c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_setSimStateSideEffectsInfo), &c19_thisId), false);
  sf_mex_destroy(&c19_b_setSimStateSideEffectsInfo);
  return c19_y;
}

static const mxArray *c19_g_emlrt_marshallIn
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c19_u,
   const emlrtMsgIdentifier *c19_parentId)
{
  const mxArray *c19_y = NULL;
  (void)chartInstance;
  (void)c19_parentId;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_duplicatearraysafe(&c19_u), false);
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance, int32_T c19_ssid)
{
  (void)chartInstance;
  (void)c19_ssid;
  return NULL;
}

static void c19_init_sf_message_store_memory
  (SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc19_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  chartInstance->c19_LeftMotorPin_BOOL = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c19_ComMotorPin_BOOL = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c19_RightMotorPin_BOOL = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c19_leftMotor = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c19_oldLeft = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_rightMotor = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c19_oldRight = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c19_CLOSED = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c19_CLOSING = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c19_OPEN = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c19_OPENING = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c19_gate_V32_2016a_Sim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3218346585U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1391925798U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2834063109U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3733815056U);
}

mxArray* sf_c19_gate_V32_2016a_Sim_get_post_codegen_info(void);
mxArray *sf_c19_gate_V32_2016a_Sim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JhH4zlfbzDnlqNXyXUBeOH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c19_gate_V32_2016a_Sim_get_post_codegen_info
      ();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_gate_V32_2016a_Sim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_gate_V32_2016a_Sim_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c19_gate_V32_2016a_Sim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c19_gate_V32_2016a_Sim_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c19_gate_V32_2016a_Sim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[26],T\"ComMotorPin_BOOL\",},{M[1],M[25],T\"LeftMotorPin_BOOL\",},{M[1],M[60],T\"RightMotorPin_BOOL\",},{M[8],M[0],T\"is_active_c19_gate_V32_2016a_Sim\",},{M[9],M[0],T\"is_c19_gate_V32_2016a_Sim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_gate_V32_2016a_Sim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc19_gate_V32_2016a_SimInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance =
      (SFc19_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _gate_V32_2016a_SimMachineNumber_,
           19,
           2,
           33,
           0,
           11,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_gate_V32_2016a_SimMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_gate_V32_2016a_SimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _gate_V32_2016a_SimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"leftMotor");
          _SFD_SET_DATA_PROPS(1,1,1,0,"oldLeft");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rightMotor");
          _SFD_SET_DATA_PROPS(3,1,1,0,"oldRight");
          _SFD_SET_DATA_PROPS(4,1,1,0,"CLOSED");
          _SFD_SET_DATA_PROPS(5,1,1,0,"CLOSING");
          _SFD_SET_DATA_PROPS(6,1,1,0,"OPEN");
          _SFD_SET_DATA_PROPS(7,1,1,0,"OPENING");
          _SFD_SET_DATA_PROPS(8,2,0,1,"LeftMotorPin_BOOL");
          _SFD_SET_DATA_PROPS(9,2,0,1,"ComMotorPin_BOOL");
          _SFD_SET_DATA_PROPS(10,2,0,1,"RightMotorPin_BOOL");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 32, 64, 90 };

          static unsigned int sEndGuardMap[] = { 22, 54, 84, 109 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, 3, -3, -2 };

          _SFD_CV_INIT_TRANS(1,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 32, 64, 90 };

          static unsigned int sEndRelationalopMap[] = { 22, 54, 84, 109 };

          static int sRelationalopEps[] = { 0, 0, 0, 0 };

          static int sRelationalopType[] = { 1, 1, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 29, 55 };

          static unsigned int sEndGuardMap[] = { 22, 49, 73 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(3,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29, 55 };

          static unsigned int sEndRelationalopMap[] = { 22, 49, 73 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(3,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 29, 55 };

          static unsigned int sEndGuardMap[] = { 22, 49, 73 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(6,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29, 55 };

          static unsigned int sEndRelationalopMap[] = { 22, 49, 73 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 30, 55 };

          static unsigned int sEndGuardMap[] = { 23, 49, 72 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(9,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 30, 55 };

          static unsigned int sEndRelationalopMap[] = { 23, 49, 72 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(9,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 30, 55 };

          static unsigned int sEndGuardMap[] = { 23, 49, 72 };

          static int sPostFixPredicateTree[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_TRANS(15,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 30, 55 };

          static unsigned int sEndRelationalopMap[] = { 23, 49, 72 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(15,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 29 };

          static unsigned int sEndGuardMap[] = { 23, 49 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(17,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29 };

          static unsigned int sEndRelationalopMap[] = { 23, 49 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(17,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 29 };

          static unsigned int sEndGuardMap[] = { 23, 49 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(20,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29 };

          static unsigned int sEndRelationalopMap[] = { 23, 49 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(20,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 3, 29, 59, 84 };

          static unsigned int sEndGuardMap[] = { 23, 47, 78, 101 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, 3, -2, -3 };

          _SFD_CV_INIT_TRANS(27,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 3, 29, 59, 84 };

          static unsigned int sEndRelationalopMap[] = { 23, 47, 78, 101 };

          static int sRelationalopEps[] = { 0, 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(27,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)
          c19_c_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _gate_V32_2016a_SimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance =
      (SFc19_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c19_LeftMotorPin_BOOL);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c19_ComMotorPin_BOOL);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c19_RightMotorPin_BOOL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c19_leftMotor);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c19_oldLeft);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c19_rightMotor);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c19_oldRight);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c19_CLOSED);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c19_CLOSING);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c19_OPEN);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c19_OPENING);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sW1lWyO5q41hKGuVOln4FYC";
}

static void sf_opaque_initialize_c19_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_gate_V32_2016a_Sim
    ((SFc19_gate_V32_2016a_SimInstanceStruct*) chartInstanceVar);
  initialize_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c19_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  enable_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c19_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  disable_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c19_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  sf_gateway_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c19_gate_V32_2016a_Sim(SimStruct*
  S)
{
  return get_sim_state_c19_gate_V32_2016a_Sim
    ((SFc19_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c19_gate_V32_2016a_Sim(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c19_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_gate_V32_2016a_SimInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_gate_V32_2016a_Sim_optimization_info();
    }

    finalize_c19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_gate_V32_2016a_Sim((SFc19_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_gate_V32_2016a_Sim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_gate_V32_2016a_Sim
      ((SFc19_gate_V32_2016a_SimInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c19_gate_V32_2016a_Sim(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_gate_V32_2016a_Sim_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 19);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(188231244U));
  ssSetChecksum1(S,(1879623935U));
  ssSetChecksum2(S,(3803357313U));
  ssSetChecksum3(S,(3811946086U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_gate_V32_2016a_Sim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c19_gate_V32_2016a_Sim(SimStruct *S)
{
  SFc19_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc19_gate_V32_2016a_SimInstanceStruct *)utMalloc(sizeof
    (SFc19_gate_V32_2016a_SimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc19_gate_V32_2016a_SimInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_gate_V32_2016a_Sim;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c19_gate_V32_2016a_Sim(chartInstance);
}

void c19_gate_V32_2016a_Sim_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_gate_V32_2016a_Sim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_gate_V32_2016a_Sim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_gate_V32_2016a_Sim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_gate_V32_2016a_Sim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
