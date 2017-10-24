/* Include files */

#include "gate_V32_2016a_Sim_sfun.h"
#include "c20_gate_V32_2016a_Sim.h"
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
#define c20_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c20_IN_closed                  ((uint8_T)1U)
#define c20_IN_closing                 ((uint8_T)2U)
#define c20_IN_init                    ((uint8_T)3U)
#define c20_IN_open                    ((uint8_T)4U)
#define c20_IN_opening                 ((uint8_T)5U)
#define c20_IN_openLeftSide            ((uint8_T)1U)
#define c20_IN_openRightSide           ((uint8_T)2U)
#define c20_IN_AssignPass              ((uint8_T)1U)
#define c20_IN_PassAssignedPreviously  ((uint8_T)2U)
#define c20_IN_idle                    ((uint8_T)3U)
#define c20_IN_MonitoringNumber        ((uint8_T)1U)
#define c20_IN_PassAssigned            ((uint8_T)2U)
#define c20_IN_addToPass               ((uint8_T)3U)
#define c20_IN_KpPassHandler           ((uint8_T)1U)
#define c20_IN_MonitorInput            ((uint8_T)2U)
#define c20_IN_openingGate             ((uint8_T)3U)
#define c20_IN_btnPressed              ((uint8_T)1U)
#define c20_IN_initTrailPass           ((uint8_T)2U)
#define c20_IN_monitorBtnPressed       ((uint8_T)3U)
#define c20_IN_verifyPass              ((uint8_T)4U)
#define c20_IN_initiatePass            ((uint8_T)1U)
#define c20_IN_closingLeftSide         ((uint8_T)1U)
#define c20_IN_closingRightSide        ((uint8_T)2U)
#define c20_b_IN_closing               ((uint8_T)1U)
#define c20_IN_gateOpen                ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void initialize_params_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void enable_c20_gate_V32_2016a_Sim(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void disable_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void set_sim_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c20_st);
static void c20_set_sim_state_side_effects_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void finalize_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void sf_gateway_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void mdl_start_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_chartstep_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void initSimStructsc20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_opening(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_exit_internal_opening(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_enter_atomic_init(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_init(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_exit_internal_init(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_exit_internal_AssignPass(SFc20_gate_V32_2016a_SimInstanceStruct *
  chartInstance);
static void c20_enter_atomic_closed(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_closed(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_exit_internal_closed(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_KpPassHandler(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_exit_internal_KpPassHandler
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_verifyPass(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_closing(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void c20_exit_internal_closing(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void c20_exit_internal_open(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint8_T c20_b_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_opening, const char_T *c20_identifier);
static uint8_T c20_c_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_d_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_trialPass, const char_T *c20_identifier,
  uint8_T c20_y[6]);
static void c20_e_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  uint8_T c20_y[6]);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint16_T c20_f_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_openSideDelay, const char_T
  *c20_identifier);
static uint16_T c20_g_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static boolean_T c20_h_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_bulbPin_BOOL, const char_T
  *c20_identifier);
static boolean_T c20_i_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint32_T c20_j_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_stableTimer, const char_T *c20_identifier);
static uint32_T c20_k_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_l_emlrt_marshallIn
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier);
static const mxArray *c20_m_emlrt_marshallIn
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, int32_T c20_ssid);
static void c20_init_sf_message_store_memory
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  int32_T c20_i0;
  int32_T c20_i1;
  int32_T c20_i2;
  int32_T c20_i3;
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc20_gate_V32_2016a_Sim(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_doSetSimStateSideEffects = 0U;
  chartInstance->c20_setSimStateSideEffectsInfo = NULL;
  chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_closed = 0U;
  chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_KpPassHandler = 0U;
  chartInstance->c20_tp_btnPressed = 0U;
  chartInstance->c20_is_initTrailPass = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_initTrailPass = 0U;
  chartInstance->c20_tp_initiatePass = 0U;
  chartInstance->c20_tp_monitorBtnPressed = 0U;
  chartInstance->c20_tp_verifyPass = 0U;
  chartInstance->c20_tp_MonitorInput = 0U;
  chartInstance->c20_tp_openingGate = 0U;
  chartInstance->c20_is_closing = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_closing = 0U;
  chartInstance->c20_tp_closingLeftSide = 0U;
  chartInstance->c20_tp_closingRightSide = 0U;
  chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_init = 0U;
  chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_AssignPass = 0U;
  chartInstance->c20_tp_MonitoringNumber = 0U;
  chartInstance->c20_tp_PassAssigned = 0U;
  chartInstance->c20_tp_addToPass = 0U;
  chartInstance->c20_tp_PassAssignedPreviously = 0U;
  chartInstance->c20_tp_idle = 0U;
  chartInstance->c20_is_open = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_open = 0U;
  chartInstance->c20_b_tp_closing = 0U;
  chartInstance->c20_tp_gateOpen = 0U;
  chartInstance->c20_is_opening = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_tp_opening = 0U;
  chartInstance->c20_tp_openLeftSide = 0U;
  chartInstance->c20_tp_openRightSide = 0U;
  chartInstance->c20_is_active_c20_gate_V32_2016a_Sim = 0U;
  chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_openingActive = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingActive, 7U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  for (c20_i0 = 0; c20_i0 < 6; c20_i0++) {
    chartInstance->c20_trialPass[c20_i0] = 0U;
  }

  for (c20_i1 = 0; c20_i1 < 6; c20_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_trialPass[c20_i1], 11U, 1U,
                          3U, (int16_T)chartInstance->c20_sfEvent, false);
  }

  chartInstance->c20_counter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_counter, 3U, 1U, 3U, (int16_T)
                        chartInstance->c20_sfEvent, false);
  chartInstance->c20_closing_active = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active, 2U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_initCounter = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_initCounter, 5U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_openSideDelay = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openSideDelay, 6U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_closeSideDelay = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closeSideDelay, 0U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_gotoReady = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_gotoReady, 4U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_passTimer = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_stableTimer = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_closingTimer = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closingTimer, 1U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_openingTimer = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingTimer, 8U, 1U, 3U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c20_leftMotor = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 1U, 3U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c20_rightMotor = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 1U, 3U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c20_bulbPin_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_bulbPin_BOOL, 38U, 1U, 3U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c20_passAssignedRAM_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passAssignedRAM_BOOL, 39U,
                          1U, 3U, (int16_T)chartInstance->c20_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c20_passSuccess = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess, 40U, 1U, 3U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    for (c20_i2 = 0; c20_i2 < 6; c20_i2++) {
      (*chartInstance->c20_passwordRAM_UINT8_6D)[c20_i2] = 0U;
    }

    for (c20_i3 = 0; c20_i3 < 6; c20_i3++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c20_passwordRAM_UINT8_6D)
                            [c20_i3], 41U, 1U, 3U, (int16_T)
                            chartInstance->c20_sfEvent, false);
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    *chartInstance->c20_gateState = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 1U, 3U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  }
}

static void initialize_params_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_gate_V32_2016a_Sim(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  uint32_T c20_prevAniVal;
  c20_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c20_is_active_c20_gate_V32_2016a_Sim == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_opening) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_opening == c20_IN_openLeftSide) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_opening == c20_IN_openRightSide) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_init == c20_IN_AssignPass) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_AssignPass == c20_IN_addToPass) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_AssignPass == c20_IN_MonitoringNumber) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_AssignPass == c20_IN_PassAssigned) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_init == c20_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_init == c20_IN_PassAssignedPreviously) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_closed == c20_IN_openingGate) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_closed == c20_IN_MonitorInput) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_closed == c20_IN_KpPassHandler) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_KpPassHandler == c20_IN_monitorBtnPressed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_KpPassHandler == c20_IN_btnPressed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_KpPassHandler == c20_IN_initTrailPass) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_initTrailPass == c20_IN_initiatePass) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_KpPassHandler == c20_IN_verifyPass) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_closing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_closing == c20_IN_closingRightSide) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_closing == c20_IN_closingLeftSide) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_open == c20_IN_gateOpen) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_open == c20_b_IN_closing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
  }

  _SFD_SET_ANIMATION(c20_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  boolean_T c20_hoistedGlobal;
  boolean_T c20_u;
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  uint8_T c20_c_hoistedGlobal;
  uint8_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  boolean_T c20_d_hoistedGlobal;
  boolean_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  uint8_T c20_e_hoistedGlobal;
  uint8_T c20_e_u;
  const mxArray *c20_f_y = NULL;
  const mxArray *c20_g_y = NULL;
  uint8_T c20_f_hoistedGlobal;
  uint8_T c20_f_u;
  const mxArray *c20_h_y = NULL;
  uint16_T c20_g_hoistedGlobal;
  uint16_T c20_g_u;
  const mxArray *c20_i_y = NULL;
  uint32_T c20_h_hoistedGlobal;
  uint32_T c20_h_u;
  const mxArray *c20_j_y = NULL;
  uint8_T c20_i_hoistedGlobal;
  uint8_T c20_i_u;
  const mxArray *c20_k_y = NULL;
  uint8_T c20_j_hoistedGlobal;
  uint8_T c20_j_u;
  const mxArray *c20_l_y = NULL;
  boolean_T c20_k_hoistedGlobal;
  boolean_T c20_k_u;
  const mxArray *c20_m_y = NULL;
  uint8_T c20_l_hoistedGlobal;
  uint8_T c20_l_u;
  const mxArray *c20_n_y = NULL;
  uint16_T c20_m_hoistedGlobal;
  uint16_T c20_m_u;
  const mxArray *c20_o_y = NULL;
  uint8_T c20_n_hoistedGlobal;
  uint8_T c20_n_u;
  const mxArray *c20_p_y = NULL;
  uint32_T c20_o_hoistedGlobal;
  uint32_T c20_o_u;
  const mxArray *c20_q_y = NULL;
  uint16_T c20_p_hoistedGlobal;
  uint16_T c20_p_u;
  const mxArray *c20_r_y = NULL;
  uint32_T c20_q_hoistedGlobal;
  uint32_T c20_q_u;
  const mxArray *c20_s_y = NULL;
  const mxArray *c20_t_y = NULL;
  uint8_T c20_r_hoistedGlobal;
  uint8_T c20_r_u;
  const mxArray *c20_u_y = NULL;
  uint8_T c20_s_hoistedGlobal;
  uint8_T c20_s_u;
  const mxArray *c20_v_y = NULL;
  uint8_T c20_t_hoistedGlobal;
  uint8_T c20_t_u;
  const mxArray *c20_w_y = NULL;
  uint8_T c20_u_hoistedGlobal;
  uint8_T c20_u_u;
  const mxArray *c20_x_y = NULL;
  uint8_T c20_v_hoistedGlobal;
  uint8_T c20_v_u;
  const mxArray *c20_y_y = NULL;
  uint8_T c20_w_hoistedGlobal;
  uint8_T c20_w_u;
  const mxArray *c20_ab_y = NULL;
  uint8_T c20_x_hoistedGlobal;
  uint8_T c20_x_u;
  const mxArray *c20_bb_y = NULL;
  uint8_T c20_y_hoistedGlobal;
  uint8_T c20_y_u;
  const mxArray *c20_cb_y = NULL;
  uint8_T c20_ab_hoistedGlobal;
  uint8_T c20_ab_u;
  const mxArray *c20_db_y = NULL;
  uint8_T c20_bb_hoistedGlobal;
  uint8_T c20_bb_u;
  const mxArray *c20_eb_y = NULL;
  uint8_T c20_cb_hoistedGlobal;
  uint8_T c20_cb_u;
  const mxArray *c20_fb_y = NULL;
  uint8_T c20_db_hoistedGlobal;
  uint8_T c20_db_u;
  const mxArray *c20_gb_y = NULL;
  boolean_T c20_eb_hoistedGlobal;
  boolean_T c20_eb_u;
  const mxArray *c20_hb_y = NULL;
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(32, 1), false);
  c20_hoistedGlobal = *chartInstance->c20_bulbPin_BOOL;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = *chartInstance->c20_gateState;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_c_hoistedGlobal = *chartInstance->c20_leftMotor;
  c20_c_u = c20_c_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_d_hoistedGlobal = *chartInstance->c20_passAssignedRAM_BOOL;
  c20_d_u = c20_d_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  c20_e_hoistedGlobal = *chartInstance->c20_passSuccess;
  c20_e_u = c20_e_hoistedGlobal;
  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  c20_g_y = NULL;
  sf_mex_assign(&c20_g_y, sf_mex_create("y",
    *chartInstance->c20_passwordRAM_UINT8_6D, 3, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c20_y, 5, c20_g_y);
  c20_f_hoistedGlobal = *chartInstance->c20_rightMotor;
  c20_f_u = c20_f_hoistedGlobal;
  c20_h_y = NULL;
  sf_mex_assign(&c20_h_y, sf_mex_create("y", &c20_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 6, c20_h_y);
  c20_g_hoistedGlobal = chartInstance->c20_closeSideDelay;
  c20_g_u = c20_g_hoistedGlobal;
  c20_i_y = NULL;
  sf_mex_assign(&c20_i_y, sf_mex_create("y", &c20_g_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 7, c20_i_y);
  c20_h_hoistedGlobal = chartInstance->c20_closingTimer;
  c20_h_u = c20_h_hoistedGlobal;
  c20_j_y = NULL;
  sf_mex_assign(&c20_j_y, sf_mex_create("y", &c20_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 8, c20_j_y);
  c20_i_hoistedGlobal = chartInstance->c20_closing_active;
  c20_i_u = c20_i_hoistedGlobal;
  c20_k_y = NULL;
  sf_mex_assign(&c20_k_y, sf_mex_create("y", &c20_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 9, c20_k_y);
  c20_j_hoistedGlobal = chartInstance->c20_counter;
  c20_j_u = c20_j_hoistedGlobal;
  c20_l_y = NULL;
  sf_mex_assign(&c20_l_y, sf_mex_create("y", &c20_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 10, c20_l_y);
  c20_k_hoistedGlobal = chartInstance->c20_gotoReady;
  c20_k_u = c20_k_hoistedGlobal;
  c20_m_y = NULL;
  sf_mex_assign(&c20_m_y, sf_mex_create("y", &c20_k_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 11, c20_m_y);
  c20_l_hoistedGlobal = chartInstance->c20_initCounter;
  c20_l_u = c20_l_hoistedGlobal;
  c20_n_y = NULL;
  sf_mex_assign(&c20_n_y, sf_mex_create("y", &c20_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 12, c20_n_y);
  c20_m_hoistedGlobal = chartInstance->c20_openSideDelay;
  c20_m_u = c20_m_hoistedGlobal;
  c20_o_y = NULL;
  sf_mex_assign(&c20_o_y, sf_mex_create("y", &c20_m_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 13, c20_o_y);
  c20_n_hoistedGlobal = chartInstance->c20_openingActive;
  c20_n_u = c20_n_hoistedGlobal;
  c20_p_y = NULL;
  sf_mex_assign(&c20_p_y, sf_mex_create("y", &c20_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 14, c20_p_y);
  c20_o_hoistedGlobal = chartInstance->c20_openingTimer;
  c20_o_u = c20_o_hoistedGlobal;
  c20_q_y = NULL;
  sf_mex_assign(&c20_q_y, sf_mex_create("y", &c20_o_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 15, c20_q_y);
  c20_p_hoistedGlobal = chartInstance->c20_passTimer;
  c20_p_u = c20_p_hoistedGlobal;
  c20_r_y = NULL;
  sf_mex_assign(&c20_r_y, sf_mex_create("y", &c20_p_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 16, c20_r_y);
  c20_q_hoistedGlobal = chartInstance->c20_stableTimer;
  c20_q_u = c20_q_hoistedGlobal;
  c20_s_y = NULL;
  sf_mex_assign(&c20_s_y, sf_mex_create("y", &c20_q_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 17, c20_s_y);
  c20_t_y = NULL;
  sf_mex_assign(&c20_t_y, sf_mex_create("y", chartInstance->c20_trialPass, 3, 0U,
    1U, 0U, 1, 6), false);
  sf_mex_setcell(c20_y, 18, c20_t_y);
  c20_r_hoistedGlobal = chartInstance->c20_is_active_c20_gate_V32_2016a_Sim;
  c20_r_u = c20_r_hoistedGlobal;
  c20_u_y = NULL;
  sf_mex_assign(&c20_u_y, sf_mex_create("y", &c20_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 19, c20_u_y);
  c20_s_hoistedGlobal = chartInstance->c20_is_c20_gate_V32_2016a_Sim;
  c20_s_u = c20_s_hoistedGlobal;
  c20_v_y = NULL;
  sf_mex_assign(&c20_v_y, sf_mex_create("y", &c20_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 20, c20_v_y);
  c20_t_hoistedGlobal = chartInstance->c20_is_AssignPass;
  c20_t_u = c20_t_hoistedGlobal;
  c20_w_y = NULL;
  sf_mex_assign(&c20_w_y, sf_mex_create("y", &c20_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 21, c20_w_y);
  c20_u_hoistedGlobal = chartInstance->c20_is_init;
  c20_u_u = c20_u_hoistedGlobal;
  c20_x_y = NULL;
  sf_mex_assign(&c20_x_y, sf_mex_create("y", &c20_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 22, c20_x_y);
  c20_v_hoistedGlobal = chartInstance->c20_is_closed;
  c20_v_u = c20_v_hoistedGlobal;
  c20_y_y = NULL;
  sf_mex_assign(&c20_y_y, sf_mex_create("y", &c20_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 23, c20_y_y);
  c20_w_hoistedGlobal = chartInstance->c20_is_KpPassHandler;
  c20_w_u = c20_w_hoistedGlobal;
  c20_ab_y = NULL;
  sf_mex_assign(&c20_ab_y, sf_mex_create("y", &c20_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 24, c20_ab_y);
  c20_x_hoistedGlobal = chartInstance->c20_is_initTrailPass;
  c20_x_u = c20_x_hoistedGlobal;
  c20_bb_y = NULL;
  sf_mex_assign(&c20_bb_y, sf_mex_create("y", &c20_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 25, c20_bb_y);
  c20_y_hoistedGlobal = chartInstance->c20_is_opening;
  c20_y_u = c20_y_hoistedGlobal;
  c20_cb_y = NULL;
  sf_mex_assign(&c20_cb_y, sf_mex_create("y", &c20_y_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 26, c20_cb_y);
  c20_ab_hoistedGlobal = chartInstance->c20_is_open;
  c20_ab_u = c20_ab_hoistedGlobal;
  c20_db_y = NULL;
  sf_mex_assign(&c20_db_y, sf_mex_create("y", &c20_ab_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c20_y, 27, c20_db_y);
  c20_bb_hoistedGlobal = chartInstance->c20_is_closing;
  c20_bb_u = c20_bb_hoistedGlobal;
  c20_eb_y = NULL;
  sf_mex_assign(&c20_eb_y, sf_mex_create("y", &c20_bb_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c20_y, 28, c20_eb_y);
  c20_cb_hoistedGlobal = chartInstance->c20_KpCharPressed_start;
  c20_cb_u = c20_cb_hoistedGlobal;
  c20_fb_y = NULL;
  sf_mex_assign(&c20_fb_y, sf_mex_create("y", &c20_cb_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c20_y, 29, c20_fb_y);
  c20_db_hoistedGlobal = chartInstance->c20_RFPressedOut_UINT8_start;
  c20_db_u = c20_db_hoistedGlobal;
  c20_gb_y = NULL;
  sf_mex_assign(&c20_gb_y, sf_mex_create("y", &c20_db_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c20_y, 30, c20_gb_y);
  c20_eb_hoistedGlobal = chartInstance->c20_passSwitch_start;
  c20_eb_u = c20_eb_hoistedGlobal;
  c20_hb_y = NULL;
  sf_mex_assign(&c20_hb_y, sf_mex_create("y", &c20_eb_u, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c20_y, 31, c20_hb_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  uint8_T c20_uv0[6];
  int32_T c20_i4;
  uint8_T c20_uv1[6];
  int32_T c20_i5;
  c20_u = sf_mex_dup(c20_st);
  *chartInstance->c20_bulbPin_BOOL = c20_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("bulbPin_BOOL", c20_u, 0)), "bulbPin_BOOL");
  *chartInstance->c20_gateState = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("gateState", c20_u, 1)), "gateState");
  *chartInstance->c20_leftMotor = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("leftMotor", c20_u, 2)), "leftMotor");
  *chartInstance->c20_passAssignedRAM_BOOL = c20_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("passAssignedRAM_BOOL", c20_u, 3)),
     "passAssignedRAM_BOOL");
  *chartInstance->c20_passSuccess = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("passSuccess", c20_u, 4)), "passSuccess");
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "passwordRAM_UINT8_6D", c20_u, 5)), "passwordRAM_UINT8_6D", c20_uv0);
  for (c20_i4 = 0; c20_i4 < 6; c20_i4++) {
    (*chartInstance->c20_passwordRAM_UINT8_6D)[c20_i4] = c20_uv0[c20_i4];
  }

  *chartInstance->c20_rightMotor = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("rightMotor", c20_u, 6)), "rightMotor");
  chartInstance->c20_closeSideDelay = c20_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("closeSideDelay", c20_u, 7)), "closeSideDelay");
  chartInstance->c20_closingTimer = c20_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("closingTimer", c20_u, 8)), "closingTimer");
  chartInstance->c20_closing_active = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("closing_active", c20_u, 9)), "closing_active");
  chartInstance->c20_counter = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("counter", c20_u, 10)), "counter");
  chartInstance->c20_gotoReady = c20_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("gotoReady", c20_u, 11)), "gotoReady");
  chartInstance->c20_initCounter = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("initCounter", c20_u, 12)), "initCounter");
  chartInstance->c20_openSideDelay = c20_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("openSideDelay", c20_u, 13)), "openSideDelay");
  chartInstance->c20_openingActive = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("openingActive", c20_u, 14)), "openingActive");
  chartInstance->c20_openingTimer = c20_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("openingTimer", c20_u, 15)), "openingTimer");
  chartInstance->c20_passTimer = c20_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("passTimer", c20_u, 16)), "passTimer");
  chartInstance->c20_stableTimer = c20_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("stableTimer", c20_u, 17)), "stableTimer");
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("trialPass",
    c20_u, 18)), "trialPass", c20_uv1);
  for (c20_i5 = 0; c20_i5 < 6; c20_i5++) {
    chartInstance->c20_trialPass[c20_i5] = c20_uv1[c20_i5];
  }

  chartInstance->c20_is_active_c20_gate_V32_2016a_Sim = c20_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c20_gate_V32_2016a_Sim",
       c20_u, 19)), "is_active_c20_gate_V32_2016a_Sim");
  chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c20_gate_V32_2016a_Sim", c20_u,
       20)), "is_c20_gate_V32_2016a_Sim");
  chartInstance->c20_is_AssignPass = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_AssignPass", c20_u, 21)), "is_AssignPass");
  chartInstance->c20_is_init = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_init", c20_u, 22)), "is_init");
  chartInstance->c20_is_closed = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_closed", c20_u, 23)), "is_closed");
  chartInstance->c20_is_KpPassHandler = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_KpPassHandler", c20_u, 24)),
    "is_KpPassHandler");
  chartInstance->c20_is_initTrailPass = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_initTrailPass", c20_u, 25)),
    "is_initTrailPass");
  chartInstance->c20_is_opening = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_opening", c20_u, 26)), "is_opening");
  chartInstance->c20_is_open = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_open", c20_u, 27)), "is_open");
  chartInstance->c20_is_closing = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_closing", c20_u, 28)), "is_closing");
  chartInstance->c20_KpCharPressed_start = c20_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("KpCharPressed_start", c20_u, 29)),
    "KpCharPressed_start");
  chartInstance->c20_RFPressedOut_UINT8_start = c20_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("RFPressedOut_UINT8_start", c20_u,
       30)), "RFPressedOut_UINT8_start");
  chartInstance->c20_passSwitch_start = c20_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("passSwitch_start", c20_u, 31)),
    "passSwitch_start");
  sf_mex_assign(&chartInstance->c20_setSimStateSideEffectsInfo,
                c20_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c20_u, 32)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c20_u);
  chartInstance->c20_doSetSimStateSideEffects = 1U;
  c20_update_debugger_state_c20_gate_V32_2016a_Sim(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void c20_set_sim_state_side_effects_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  if (chartInstance->c20_doSetSimStateSideEffects != 0) {
    chartInstance->c20_tp_closed = (uint8_T)
      (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_closed);
    chartInstance->c20_tp_KpPassHandler = (uint8_T)(chartInstance->c20_is_closed
      == c20_IN_KpPassHandler);
    chartInstance->c20_tp_btnPressed = (uint8_T)
      (chartInstance->c20_is_KpPassHandler == c20_IN_btnPressed);
    chartInstance->c20_tp_initTrailPass = (uint8_T)
      (chartInstance->c20_is_KpPassHandler == c20_IN_initTrailPass);
    chartInstance->c20_tp_initiatePass = (uint8_T)
      (chartInstance->c20_is_initTrailPass == c20_IN_initiatePass);
    chartInstance->c20_tp_monitorBtnPressed = (uint8_T)
      (chartInstance->c20_is_KpPassHandler == c20_IN_monitorBtnPressed);
    chartInstance->c20_tp_verifyPass = (uint8_T)
      (chartInstance->c20_is_KpPassHandler == c20_IN_verifyPass);
    chartInstance->c20_tp_MonitorInput = (uint8_T)(chartInstance->c20_is_closed ==
      c20_IN_MonitorInput);
    chartInstance->c20_tp_openingGate = (uint8_T)(chartInstance->c20_is_closed ==
      c20_IN_openingGate);
    chartInstance->c20_tp_closing = (uint8_T)
      (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_closing);
    chartInstance->c20_tp_closingLeftSide = (uint8_T)
      (chartInstance->c20_is_closing == c20_IN_closingLeftSide);
    chartInstance->c20_tp_closingRightSide = (uint8_T)
      (chartInstance->c20_is_closing == c20_IN_closingRightSide);
    chartInstance->c20_tp_init = (uint8_T)
      (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_init);
    chartInstance->c20_tp_AssignPass = (uint8_T)(chartInstance->c20_is_init ==
      c20_IN_AssignPass);
    chartInstance->c20_tp_MonitoringNumber = (uint8_T)
      (chartInstance->c20_is_AssignPass == c20_IN_MonitoringNumber);
    chartInstance->c20_tp_PassAssigned = (uint8_T)
      (chartInstance->c20_is_AssignPass == c20_IN_PassAssigned);
    chartInstance->c20_tp_addToPass = (uint8_T)(chartInstance->c20_is_AssignPass
      == c20_IN_addToPass);
    chartInstance->c20_tp_PassAssignedPreviously = (uint8_T)
      (chartInstance->c20_is_init == c20_IN_PassAssignedPreviously);
    chartInstance->c20_tp_idle = (uint8_T)(chartInstance->c20_is_init ==
      c20_IN_idle);
    chartInstance->c20_tp_open = (uint8_T)
      (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_open);
    chartInstance->c20_b_tp_closing = (uint8_T)(chartInstance->c20_is_open ==
      c20_b_IN_closing);
    chartInstance->c20_tp_gateOpen = (uint8_T)(chartInstance->c20_is_open ==
      c20_IN_gateOpen);
    chartInstance->c20_tp_opening = (uint8_T)
      (chartInstance->c20_is_c20_gate_V32_2016a_Sim == c20_IN_opening);
    chartInstance->c20_tp_openLeftSide = (uint8_T)(chartInstance->c20_is_opening
      == c20_IN_openLeftSide);
    chartInstance->c20_tp_openRightSide = (uint8_T)
      (chartInstance->c20_is_opening == c20_IN_openRightSide);
    chartInstance->c20_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c20_setSimStateSideEffectsInfo);
}

static void sf_gateway_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  int32_T c20_i6;
  c20_set_sim_state_side_effects_c20_gate_V32_2016a_Sim(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_MOVING_TIMER, 35U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_INIT, 34U, 1U, 0U, (int16_T)
                        chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passAssignedIn, 33U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  for (c20_i6 = 0; c20_i6 < 6; c20_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c20_passwordIn)[c20_i6], 32U,
                          1U, 0U, (int16_T)chartInstance->c20_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_TIMEOUT, 31U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_PASS_TIMEOUT, 30U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_PASS_INCOMPLETE, 29U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_PASS_ASSIGNED, 28U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_NO_PASS_ASSIG, 27U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_OPEN, 26U, 1U, 0U, (int16_T)
                        chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_CLOSING, 25U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_CLOSED, 24U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_OPENING, 23U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_OPEN_CHAR, 22U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_CLOSE_CHAR, 21U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_PASSWORD_VERIFIED, 20U, 1U,
                        0U, (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_CLOSE_SIDE_VALUE, 19U, 1U,
                        0U, (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_OPEN_SIDE_VALUE, 18U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_WRONG_PASSWORD, 17U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_OPENING_ACTIVE, 16U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_current_sensor, 15U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSwitch, 14U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_RFPressedOut_UINT8, 13U, 1U,
                        0U, (int16_T)chartInstance->c20_sfEvent, false);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_KpCharPressed, 12U, 1U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_gate_V32_2016a_Sim(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_gate_V32_2016a_SimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  c20_init_sf_message_store_memory(chartInstance);
}

static void c20_chartstep_c20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_out;
  boolean_T c20_temp;
  boolean_T c20_b_out;
  boolean_T c20_b_temp;
  boolean_T c20_c_out;
  chartInstance->c20_KpCharPressed_prev = chartInstance->c20_KpCharPressed_start;
  chartInstance->c20_KpCharPressed_start = *chartInstance->c20_KpCharPressed;
  chartInstance->c20_RFPressedOut_UINT8_prev =
    chartInstance->c20_RFPressedOut_UINT8_start;
  chartInstance->c20_RFPressedOut_UINT8_start =
    *chartInstance->c20_RFPressedOut_UINT8;
  chartInstance->c20_passSwitch_prev = chartInstance->c20_passSwitch_start;
  chartInstance->c20_passSwitch_start = *chartInstance->c20_passSwitch;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
  if (chartInstance->c20_is_active_c20_gate_V32_2016a_Sim == 0U) {
    chartInstance->c20_KpCharPressed_prev = *chartInstance->c20_KpCharPressed;
    chartInstance->c20_RFPressedOut_UINT8_prev =
      *chartInstance->c20_RFPressedOut_UINT8;
    chartInstance->c20_passSwitch_prev = *chartInstance->c20_passSwitch;
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_active_c20_gate_V32_2016a_Sim = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_init = 1U;
    c20_enter_atomic_init(chartInstance);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_init = c20_IN_idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_idle = 1U;
    *chartInstance->c20_passAssignedRAM_BOOL = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passAssignedRAM_BOOL, 39U,
                          4U, 18U, (int16_T)chartInstance->c20_sfEvent, false);
  } else {
    switch (chartInstance->c20_is_c20_gate_V32_2016a_Sim) {
     case c20_IN_closed:
      CV_CHART_EVAL(3, 0, 1);
      c20_closed(chartInstance);
      break;

     case c20_IN_closing:
      CV_CHART_EVAL(3, 0, 2);
      c20_closing(chartInstance);
      break;

     case c20_IN_init:
      CV_CHART_EVAL(3, 0, 3);
      c20_init(chartInstance);
      break;

     case c20_IN_open:
      CV_CHART_EVAL(3, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                   chartInstance->c20_sfEvent);
      c20_out = (CV_TRANSITION_EVAL(53U, (int32_T)_SFD_CCP_CALL(53U, 0,
        CV_RELATIONAL_EVAL(5U, 53U, 0, (real_T)chartInstance->c20_closing_active,
                           1.0, 0, 0U, chartInstance->c20_closing_active == 1)
        != 0U, chartInstance->c20_sfEvent)) != 0);
      if (c20_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, chartInstance->c20_sfEvent);
        c20_exit_internal_open(chartInstance);
        chartInstance->c20_tp_open = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closing;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_closing = 1U;
        *chartInstance->c20_gateState = *chartInstance->c20_CLOSING;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 9U,
                              (int16_T)chartInstance->c20_sfEvent, false);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_closing = c20_IN_closingRightSide;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_closingRightSide = 1U;
        *chartInstance->c20_rightMotor = *chartInstance->c20_CLOSING;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U,
                              11U, (int16_T)chartInstance->c20_sfEvent, false);
        chartInstance->c20_closeSideDelay = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closeSideDelay, 0U, 4U,
                              11U, (int16_T)chartInstance->c20_sfEvent, false);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                     chartInstance->c20_sfEvent);
        switch (chartInstance->c20_is_open) {
         case c20_b_IN_closing:
          CV_STATE_EVAL(19, 0, 1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                       chartInstance->c20_sfEvent);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_gateOpen:
          CV_STATE_EVAL(19, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U,
                       chartInstance->c20_sfEvent);
          c20_temp = (_SFD_CCP_CALL(57U, 0,
            chartInstance->c20_KpCharPressed_prev !=
            chartInstance->c20_KpCharPressed_start != 0U,
            chartInstance->c20_sfEvent) != 0);
          if (c20_temp) {
            c20_temp = (_SFD_CCP_CALL(57U, 1, CV_RELATIONAL_EVAL(5U, 57U, 0,
              (real_T)*chartInstance->c20_KpCharPressed, (real_T)
              *chartInstance->c20_CLOSE_CHAR, 0, 0U,
              *chartInstance->c20_KpCharPressed ==
              *chartInstance->c20_CLOSE_CHAR) != 0U, chartInstance->c20_sfEvent)
                        != 0);
          }

          c20_b_out = (CV_TRANSITION_EVAL(57U, (int32_T)c20_temp) != 0);
          if (c20_b_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_gateOpen = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
            chartInstance->c20_is_open = c20_b_IN_closing;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
            chartInstance->c20_b_tp_closing = 1U;
            chartInstance->c20_closing_active = 1U;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active, 2U,
                                  4U, 20U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U,
                         chartInstance->c20_sfEvent);
            c20_b_temp = (_SFD_CCP_CALL(54U, 0,
              chartInstance->c20_RFPressedOut_UINT8_prev !=
              chartInstance->c20_RFPressedOut_UINT8_start != 0U,
              chartInstance->c20_sfEvent) != 0);
            if (c20_b_temp) {
              c20_b_temp = (_SFD_CCP_CALL(54U, 1, CV_RELATIONAL_EVAL(5U, 54U, 0,
                (real_T)*chartInstance->c20_RFPressedOut_UINT8, 1.0, 0, 0U,
                *chartInstance->c20_RFPressedOut_UINT8 == 1) != 0U,
                chartInstance->c20_sfEvent) != 0);
            }

            c20_c_out = (CV_TRANSITION_EVAL(54U, (int32_T)c20_b_temp) != 0);
            if (c20_c_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_tp_gateOpen = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
              chartInstance->c20_is_open = c20_b_IN_closing;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
              chartInstance->c20_b_tp_closing = 1U;
              chartInstance->c20_closing_active = 1U;
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active,
                                    2U, 4U, 20U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                           chartInstance->c20_sfEvent);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c20_sfEvent);
          break;

         default:
          CV_STATE_EVAL(19, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c20_is_open = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
          break;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
      break;

     case c20_IN_opening:
      CV_CHART_EVAL(3, 0, 5);
      c20_opening(chartInstance);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
}

static void initSimStructsc20_gate_V32_2016a_Sim
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_opening(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_temp;
  boolean_T c20_out;
  boolean_T c20_b_temp;
  boolean_T c20_c_temp;
  boolean_T c20_d_temp;
  boolean_T c20_e_temp;
  boolean_T c20_b_out;
  boolean_T c20_c_out;
  int8_T c20_i7;
  uint64_T c20_u0;
  boolean_T c20_d_out;
  int8_T c20_i8;
  int8_T c20_i9;
  uint64_T c20_u1;
  uint32_T c20_u2;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U, chartInstance->c20_sfEvent);
  c20_temp = (_SFD_CCP_CALL(50U, 0, CV_RELATIONAL_EVAL(5U, 50U, 0, (real_T)
    *chartInstance->c20_current_sensor, 0.0, 0, 0U,
    !*chartInstance->c20_current_sensor) != 0U, chartInstance->c20_sfEvent) != 0);
  if (c20_temp) {
    c20_temp = (_SFD_CCP_CALL(50U, 1, CV_RELATIONAL_EVAL(5U, 50U, 1, (real_T)
      chartInstance->c20_stableTimer, 10.0, 0, 5U,
      chartInstance->c20_stableTimer >= 10U) != 0U, chartInstance->c20_sfEvent)
                != 0);
  }

  c20_out = (CV_TRANSITION_EVAL(50U, (int32_T)c20_temp) != 0);
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, chartInstance->c20_sfEvent);
    c20_exit_internal_opening(chartInstance);
    chartInstance->c20_tp_opening = 0U;
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 50U,
                 chartInstance->c20_sfEvent);
    chartInstance->c20_stableTimer = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 5U, 50U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_open;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_open = 1U;
    *chartInstance->c20_gateState = *chartInstance->c20_OPEN;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 19U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    chartInstance->c20_openingTimer = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingTimer, 8U, 4U, 19U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_open = c20_IN_gateOpen;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_gateOpen = 1U;
    chartInstance->c20_closing_active = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active, 2U, 4U, 21U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    *chartInstance->c20_leftMotor = *chartInstance->c20_OPEN;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U, 21U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    *chartInstance->c20_rightMotor = *chartInstance->c20_OPEN;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U, 21U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U,
                 chartInstance->c20_sfEvent);
    c20_b_temp = (_SFD_CCP_CALL(70U, 0,
      chartInstance->c20_RFPressedOut_UINT8_prev !=
      chartInstance->c20_RFPressedOut_UINT8_start != 0U,
      chartInstance->c20_sfEvent) != 0);
    if (c20_b_temp) {
      c20_b_temp = (_SFD_CCP_CALL(70U, 1, CV_RELATIONAL_EVAL(5U, 70U, 0, (real_T)*
        chartInstance->c20_RFPressedOut_UINT8, 1.0, 0, 0U,
        *chartInstance->c20_RFPressedOut_UINT8 == 1) != 0U,
        chartInstance->c20_sfEvent) != 0);
    }

    c20_c_temp = c20_b_temp;
    if (!c20_c_temp) {
      c20_d_temp = (_SFD_CCP_CALL(70U, 2, CV_RELATIONAL_EVAL(5U, 70U, 1, (real_T)*
        chartInstance->c20_KpCharPressed, (real_T)*chartInstance->c20_OPEN_CHAR,
        0, 0U, *chartInstance->c20_KpCharPressed ==
        *chartInstance->c20_OPEN_CHAR) != 0U, chartInstance->c20_sfEvent) != 0);
      if (c20_d_temp) {
        c20_d_temp = (_SFD_CCP_CALL(70U, 3, CV_RELATIONAL_EVAL(5U, 70U, 2,
          (real_T)chartInstance->c20_KpCharPressed_prev, (real_T)
          chartInstance->c20_KpCharPressed_start, 0, 1U,
          chartInstance->c20_KpCharPressed_prev !=
          chartInstance->c20_KpCharPressed_start) != 0U,
          chartInstance->c20_sfEvent) != 0);
      }

      c20_c_temp = c20_d_temp;
    }

    c20_e_temp = c20_c_temp;
    if (c20_e_temp) {
      c20_e_temp = (_SFD_CCP_CALL(70U, 4, CV_RELATIONAL_EVAL(5U, 70U, 3, (real_T)
        chartInstance->c20_stableTimer, 10.0, 0, 5U,
        chartInstance->c20_stableTimer >= 10U) != 0U, chartInstance->c20_sfEvent)
                    != 0);
    }

    c20_b_out = (CV_TRANSITION_EVAL(70U, (int32_T)c20_e_temp) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, chartInstance->c20_sfEvent);
      c20_exit_internal_opening(chartInstance);
      chartInstance->c20_tp_opening = 0U;
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 70U,
                   chartInstance->c20_sfEvent);
      chartInstance->c20_stableTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 5U, 70U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_open;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_open = 1U;
      *chartInstance->c20_gateState = *chartInstance->c20_OPEN;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 19U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_openingTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingTimer, 8U, 4U, 19U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_open = c20_IN_gateOpen;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_gateOpen = 1U;
      chartInstance->c20_closing_active = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active, 2U, 4U,
                            21U, (int16_T)chartInstance->c20_sfEvent, false);
      *chartInstance->c20_leftMotor = *chartInstance->c20_OPEN;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U, 21U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      *chartInstance->c20_rightMotor = *chartInstance->c20_OPEN;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U, 21U,
                            (int16_T)chartInstance->c20_sfEvent, false);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U,
                   chartInstance->c20_sfEvent);
      c20_c_out = (CV_TRANSITION_EVAL(72U, (int32_T)_SFD_CCP_CALL(72U, 0,
        CV_RELATIONAL_EVAL(5U, 72U, 0, (real_T)chartInstance->c20_openingTimer,
                           (real_T)*chartInstance->c20_MOVING_TIMER, 0, 5U,
                           chartInstance->c20_openingTimer >=
                           *chartInstance->c20_MOVING_TIMER) != 0U,
        chartInstance->c20_sfEvent)) != 0);
      if (c20_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, chartInstance->c20_sfEvent);
        c20_exit_internal_opening(chartInstance);
        chartInstance->c20_tp_opening = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_open;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_open = 1U;
        *chartInstance->c20_gateState = *chartInstance->c20_OPEN;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U,
                              19U, (int16_T)chartInstance->c20_sfEvent, false);
        chartInstance->c20_openingTimer = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingTimer, 8U, 4U,
                              19U, (int16_T)chartInstance->c20_sfEvent, false);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_open = c20_IN_gateOpen;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_gateOpen = 1U;
        chartInstance->c20_closing_active = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closing_active, 2U, 4U,
                              21U, (int16_T)chartInstance->c20_sfEvent, false);
        *chartInstance->c20_leftMotor = *chartInstance->c20_OPEN;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U,
                              21U, (int16_T)chartInstance->c20_sfEvent, false);
        *chartInstance->c20_rightMotor = *chartInstance->c20_OPEN;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U,
                              21U, (int16_T)chartInstance->c20_sfEvent, false);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                     chartInstance->c20_sfEvent);
        c20_i7 = 1;
        if (CV_SATURATION_EVAL(4, 22, 0, 0, c20_i7 < 0)) {
          c20_i7 = 0;
        }

        c20_u0 = (uint64_T)chartInstance->c20_openingTimer + (uint64_T)(uint32_T)
          c20_i7;
        if (CV_SATURATION_EVAL(4, 22, 0, 0, c20_u0 > 4294967295ULL)) {
          c20_u0 = 4294967295ULL;
        }

        chartInstance->c20_openingTimer = (uint32_T)c20_u0;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingTimer, 8U, 4U,
                              22U, (int16_T)chartInstance->c20_sfEvent, false);
        switch (chartInstance->c20_is_opening) {
         case c20_IN_openLeftSide:
          CV_STATE_EVAL(22, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U,
                       chartInstance->c20_sfEvent);
          c20_d_out = (CV_TRANSITION_EVAL(51U, (int32_T)_SFD_CCP_CALL(51U, 0,
            CV_RELATIONAL_EVAL(5U, 51U, 0, (real_T)
                               chartInstance->c20_openSideDelay, (real_T)
                               *chartInstance->c20_OPEN_SIDE_VALUE, 0, 0U,
                               chartInstance->c20_openSideDelay ==
                               *chartInstance->c20_OPEN_SIDE_VALUE) != 0U,
            chartInstance->c20_sfEvent)) != 0);
          if (c20_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_openLeftSide = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
            chartInstance->c20_is_opening = c20_IN_openRightSide;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_openRightSide = 1U;
            *chartInstance->c20_rightMotor = *chartInstance->c20_OPENING;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U,
                                  4U, 24U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                         chartInstance->c20_sfEvent);
            c20_i9 = 1;
            if (CV_SATURATION_EVAL(4, 23, 0, 0, c20_i9 < 0)) {
              c20_i9 = 0;
            }

            c20_u2 = (uint32_T)chartInstance->c20_openSideDelay + (uint32_T)
              (uint16_T)c20_i9;
            if (CV_SATURATION_EVAL(4, 23, 0, 0, c20_u2 > 65535U)) {
              c20_u2 = 65535U;
            }

            chartInstance->c20_openSideDelay = (uint16_T)c20_u2;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openSideDelay, 6U,
                                  4U, 23U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_openRightSide:
          CV_STATE_EVAL(22, 0, 2);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                       chartInstance->c20_sfEvent);
          c20_i8 = 1;
          if (CV_SATURATION_EVAL(4, 24, 0, 0, c20_i8 < 0)) {
            c20_i8 = 0;
          }

          c20_u1 = (uint64_T)chartInstance->c20_stableTimer + (uint64_T)
            (uint32_T)c20_i8;
          if (CV_SATURATION_EVAL(4, 24, 0, 0, c20_u1 > 4294967295ULL)) {
            c20_u1 = 4294967295ULL;
          }

          chartInstance->c20_stableTimer = (uint32_T)c20_u1;
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 4U,
                                24U, (int16_T)chartInstance->c20_sfEvent, false);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c20_sfEvent);
          break;

         default:
          CV_STATE_EVAL(22, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c20_is_opening = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
          break;
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_opening(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c20_is_opening) {
   case c20_IN_openLeftSide:
    CV_STATE_EVAL(22, 1, 1);
    chartInstance->c20_tp_openLeftSide = 0U;
    chartInstance->c20_is_opening = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_openRightSide:
    CV_STATE_EVAL(22, 1, 2);
    chartInstance->c20_tp_openRightSide = 0U;
    chartInstance->c20_is_opening = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(22, 1, 0);
    chartInstance->c20_is_opening = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_enter_atomic_init(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  *chartInstance->c20_passSuccess = *chartInstance->c20_NO_PASS_ASSIG;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess, 40U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_gotoReady = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_gotoReady, 4U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_bulbPin_BOOL = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_bulbPin_BOOL, 38U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_leftMotor = *chartInstance->c20_CLOSED;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_rightMotor = *chartInstance->c20_CLOSED;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_gateState = *chartInstance->c20_INIT;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 12U,
                        (int16_T)chartInstance->c20_sfEvent, false);
}

static void c20_init(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_out;
  boolean_T c20_temp;
  boolean_T c20_b_out;
  boolean_T c20_c_out;
  boolean_T c20_d_out;
  boolean_T c20_e_out;
  boolean_T c20_f_out;
  boolean_T c20_g_out;
  boolean_T c20_h_out;
  boolean_T c20_i_out;
  boolean_T c20_j_out;
  int32_T c20_i10;
  int32_T c20_i11;
  int16_T c20_i12;
  int32_T c20_i13;
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  int32_T c20_i17;
  int32_T c20_i18;
  int32_T c20_i19;
  int32_T c20_i20;
  int32_T c20_i21;
  int32_T c20_i22;
  int32_T c20_i23;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, chartInstance->c20_sfEvent);
  c20_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
    chartInstance->c20_gotoReady != 0U, chartInstance->c20_sfEvent)) != 0);
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
    c20_exit_internal_init(chartInstance);
    chartInstance->c20_tp_init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closed;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_closed = 1U;
    c20_enter_atomic_closed(chartInstance);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_closed = c20_IN_MonitorInput;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_MonitorInput = 1U;
    chartInstance->c20_passTimer = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U,
                 chartInstance->c20_sfEvent);
    c20_temp = (_SFD_CCP_CALL(67U, 0, chartInstance->c20_RFPressedOut_UINT8_prev
      != chartInstance->c20_RFPressedOut_UINT8_start != 0U,
      chartInstance->c20_sfEvent) != 0);
    if (c20_temp) {
      c20_temp = (_SFD_CCP_CALL(67U, 1, CV_RELATIONAL_EVAL(5U, 67U, 0, (real_T)
        *chartInstance->c20_RFPressedOut_UINT8, 1.0, 0, 0U,
        *chartInstance->c20_RFPressedOut_UINT8 == 1) != 0U,
        chartInstance->c20_sfEvent) != 0);
    }

    c20_b_out = (CV_TRANSITION_EVAL(67U, (int32_T)c20_temp) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, chartInstance->c20_sfEvent);
      c20_exit_internal_init(chartInstance);
      chartInstance->c20_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_closed = 1U;
      c20_enter_atomic_closed(chartInstance);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_closed = c20_IN_MonitorInput;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_MonitorInput = 1U;
      chartInstance->c20_passTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                            (int16_T)chartInstance->c20_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c20_sfEvent);
      switch (chartInstance->c20_is_init) {
       case c20_IN_AssignPass:
        CV_STATE_EVAL(12, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c20_sfEvent);
        c20_c_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
          !*chartInstance->c20_passSwitch != 0U, chartInstance->c20_sfEvent)) !=
                     0);
        if (c20_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
          c20_exit_internal_AssignPass(chartInstance);
          chartInstance->c20_tp_AssignPass = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
          chartInstance->c20_is_init = c20_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_idle = 1U;
          *chartInstance->c20_passAssignedRAM_BOOL = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passAssignedRAM_BOOL,
                                39U, 4U, 18U, (int16_T)
                                chartInstance->c20_sfEvent, false);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                       chartInstance->c20_sfEvent);
          switch (chartInstance->c20_is_AssignPass) {
           case c20_IN_MonitoringNumber:
            CV_STATE_EVAL(13, 0, 1);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                         chartInstance->c20_sfEvent);
            c20_f_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
              chartInstance->c20_KpCharPressed_prev !=
              chartInstance->c20_KpCharPressed_start != 0U,
              chartInstance->c20_sfEvent)) != 0);
            guard1 = false;
            if (c20_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 60U,
                           chartInstance->c20_sfEvent);
              c20_j_out = (CV_TRANSITION_EVAL(60U, (int32_T)_SFD_CCP_CALL(60U, 0,
                CV_RELATIONAL_EVAL(5U, 60U, 0, (real_T)
                                   *chartInstance->c20_KpCharPressed, 0.0, 0, 1U,
                                   *chartInstance->c20_KpCharPressed != 0) != 0U,
                chartInstance->c20_sfEvent)) != 0);
              if (c20_j_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U,
                             chartInstance->c20_sfEvent);
                chartInstance->c20_tp_MonitoringNumber = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
                chartInstance->c20_is_AssignPass = c20_IN_addToPass;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
                chartInstance->c20_tp_addToPass = 1U;
                (*chartInstance->c20_passwordRAM_UINT8_6D)[(uint8_T)
                  sf_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 4U, 17, 20, 41U, (int32_T)
                  chartInstance->c20_counter, 0, 5)] =
                  *chartInstance->c20_KpCharPressed;
                for (c20_i15 = 0; c20_i15 < 6; c20_i15++) {
                  _SFD_DATA_RANGE_CHECK((real_T)
                                        (*chartInstance->c20_passwordRAM_UINT8_6D)
                                        [c20_i15], 41U, 4U, 16U, (int16_T)
                                        chartInstance->c20_sfEvent, false);
                }
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1 == true) {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                           chartInstance->c20_sfEvent);
              c20_i_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
                CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
                                   *chartInstance->c20_RFPressedOut_UINT8, 1.0,
                                   0, 0U, *chartInstance->c20_RFPressedOut_UINT8
                                   == 1) != 0U, chartInstance->c20_sfEvent)) !=
                           0);
              if (c20_i_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U,
                             chartInstance->c20_sfEvent);
                chartInstance->c20_tp_MonitoringNumber = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
                chartInstance->c20_is_AssignPass = c20_IN_PassAssigned;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
                chartInstance->c20_tp_PassAssigned = 1U;
                chartInstance->c20_gotoReady = true;
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_gotoReady, 4U,
                                      4U, 15U, (int16_T)
                                      chartInstance->c20_sfEvent, false);
              } else {
                _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                             chartInstance->c20_sfEvent);
              }
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U,
                         chartInstance->c20_sfEvent);
            break;

           case c20_IN_PassAssigned:
            CV_STATE_EVAL(13, 0, 2);
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                         chartInstance->c20_sfEvent);
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U,
                         chartInstance->c20_sfEvent);
            break;

           case c20_IN_addToPass:
            CV_STATE_EVAL(13, 0, 3);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                         chartInstance->c20_sfEvent);
            c20_g_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
              CV_RELATIONAL_EVAL(5U, 5U, 0, (real_T)chartInstance->c20_counter,
                                 5.0, 0, 2U, chartInstance->c20_counter < 5) !=
              0U, chartInstance->c20_sfEvent)) != 0);
            if (c20_g_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_addToPass = 0U;
              chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 5U,
                           chartInstance->c20_sfEvent);
              c20_i12 = (int16_T)(chartInstance->c20_counter + 1);
              if (CV_SATURATION_EVAL(5, 5, 0, 0, c20_i12 < 0)) {
                c20_i12 = 0;
              } else {
                if (c20_i12 > 255) {
                  c20_i12 = 255;
                }
              }

              chartInstance->c20_counter = (uint8_T)c20_i12;
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_counter, 3U, 5U,
                                    5U, (int16_T)chartInstance->c20_sfEvent,
                                    false);
              chartInstance->c20_is_AssignPass = c20_IN_MonitoringNumber;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_MonitoringNumber = 1U;
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                           chartInstance->c20_sfEvent);
              c20_h_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
                CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)chartInstance->c20_counter,
                                   5.0, 0, 0U, chartInstance->c20_counter == 5)
                != 0U, chartInstance->c20_sfEvent)) != 0);
              if (c20_h_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U,
                             chartInstance->c20_sfEvent);
                chartInstance->c20_tp_addToPass = 0U;
                chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 6U,
                             chartInstance->c20_sfEvent);
                *chartInstance->c20_passAssignedRAM_BOOL = true;
                _SFD_DATA_RANGE_CHECK((real_T)
                                      *chartInstance->c20_passAssignedRAM_BOOL,
                                      39U, 5U, 6U, (int16_T)
                                      chartInstance->c20_sfEvent, false);
                *chartInstance->c20_passSuccess =
                  *chartInstance->c20_PASS_ASSIGNED;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess,
                                      40U, 5U, 6U, (int16_T)
                                      chartInstance->c20_sfEvent, false);
                chartInstance->c20_is_AssignPass = c20_IN_PassAssigned;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
                chartInstance->c20_tp_PassAssigned = 1U;
                chartInstance->c20_gotoReady = true;
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_gotoReady, 4U,
                                      4U, 15U, (int16_T)
                                      chartInstance->c20_sfEvent, false);
              } else {
                _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                             chartInstance->c20_sfEvent);
              }
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U,
                         chartInstance->c20_sfEvent);
            break;

           default:
            CV_STATE_EVAL(13, 0, 0);

            /* Unreachable state, for coverage only */
            chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
            break;
          }
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c20_sfEvent);
        break;

       case c20_IN_PassAssignedPreviously:
        CV_STATE_EVAL(12, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                     chartInstance->c20_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c20_sfEvent);
        break;

       case c20_IN_idle:
        CV_STATE_EVAL(12, 0, 3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c20_sfEvent);
        c20_d_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
          *chartInstance->c20_passSwitch != 0U, chartInstance->c20_sfEvent)) !=
                     0);
        if (c20_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_idle = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
          chartInstance->c20_is_init = c20_IN_AssignPass;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_AssignPass = 1U;
          chartInstance->c20_counter = 0U;
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_counter, 3U, 4U, 13U,
                                (int16_T)chartInstance->c20_sfEvent, false);
          (*chartInstance->c20_passwordRAM_UINT8_6D)[0] = 0U;
          for (c20_i10 = 0; c20_i10 < 6; c20_i10++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i10], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          (*chartInstance->c20_passwordRAM_UINT8_6D)[1] = 0U;
          for (c20_i13 = 0; c20_i13 < 6; c20_i13++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i13], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          (*chartInstance->c20_passwordRAM_UINT8_6D)[2] = 0U;
          for (c20_i16 = 0; c20_i16 < 6; c20_i16++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i16], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          (*chartInstance->c20_passwordRAM_UINT8_6D)[3] = 0U;
          for (c20_i18 = 0; c20_i18 < 6; c20_i18++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i18], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          (*chartInstance->c20_passwordRAM_UINT8_6D)[4] = 0U;
          for (c20_i20 = 0; c20_i20 < 6; c20_i20++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i20], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          (*chartInstance->c20_passwordRAM_UINT8_6D)[5] = 0U;
          for (c20_i22 = 0; c20_i22 < 6; c20_i22++) {
            _SFD_DATA_RANGE_CHECK((real_T)
                                  (*chartInstance->c20_passwordRAM_UINT8_6D)
                                  [c20_i22], 41U, 4U, 13U, (int16_T)
                                  chartInstance->c20_sfEvent, false);
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
          chartInstance->c20_is_AssignPass = c20_IN_MonitoringNumber;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_MonitoringNumber = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 69U,
                       chartInstance->c20_sfEvent);
          c20_e_out = (CV_TRANSITION_EVAL(69U, (int32_T)_SFD_CCP_CALL(69U, 0,
            *chartInstance->c20_passAssignedIn != 0U, chartInstance->c20_sfEvent))
                       != 0);
          if (c20_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_idle = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
            chartInstance->c20_is_init = c20_IN_PassAssignedPreviously;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_PassAssignedPreviously = 1U;
            (*chartInstance->c20_passwordRAM_UINT8_6D)[0] =
              (*chartInstance->c20_passwordIn)[0];
            for (c20_i11 = 0; c20_i11 < 6; c20_i11++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i11], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            (*chartInstance->c20_passwordRAM_UINT8_6D)[1] =
              (*chartInstance->c20_passwordIn)[1];
            for (c20_i14 = 0; c20_i14 < 6; c20_i14++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i14], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            (*chartInstance->c20_passwordRAM_UINT8_6D)[2] =
              (*chartInstance->c20_passwordIn)[2];
            for (c20_i17 = 0; c20_i17 < 6; c20_i17++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i17], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            (*chartInstance->c20_passwordRAM_UINT8_6D)[3] =
              (*chartInstance->c20_passwordIn)[3];
            for (c20_i19 = 0; c20_i19 < 6; c20_i19++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i19], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            (*chartInstance->c20_passwordRAM_UINT8_6D)[4] =
              (*chartInstance->c20_passwordIn)[4];
            for (c20_i21 = 0; c20_i21 < 6; c20_i21++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i21], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            (*chartInstance->c20_passwordRAM_UINT8_6D)[5] =
              (*chartInstance->c20_passwordIn)[5];
            for (c20_i23 = 0; c20_i23 < 6; c20_i23++) {
              _SFD_DATA_RANGE_CHECK((real_T)
                                    (*chartInstance->c20_passwordRAM_UINT8_6D)
                                    [c20_i23], 41U, 4U, 17U, (int16_T)
                                    chartInstance->c20_sfEvent, false);
            }

            *chartInstance->c20_passAssignedRAM_BOOL =
              *chartInstance->c20_passAssignedIn;
            _SFD_DATA_RANGE_CHECK((real_T)
                                  *chartInstance->c20_passAssignedRAM_BOOL, 39U,
                                  4U, 17U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
            chartInstance->c20_gotoReady = true;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_gotoReady, 4U, 4U,
                                  17U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                         chartInstance->c20_sfEvent);
          }
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c20_sfEvent);
        break;

       default:
        CV_STATE_EVAL(12, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
        break;
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_init(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c20_is_init) {
   case c20_IN_AssignPass:
    CV_STATE_EVAL(12, 1, 1);
    c20_exit_internal_AssignPass(chartInstance);
    chartInstance->c20_tp_AssignPass = 0U;
    chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_PassAssignedPreviously:
    CV_STATE_EVAL(12, 1, 2);
    chartInstance->c20_tp_PassAssignedPreviously = 0U;
    chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_idle:
    CV_STATE_EVAL(12, 1, 3);
    chartInstance->c20_tp_idle = 0U;
    chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(12, 1, 0);
    chartInstance->c20_is_init = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_exit_internal_AssignPass(SFc20_gate_V32_2016a_SimInstanceStruct *
  chartInstance)
{
  switch (chartInstance->c20_is_AssignPass) {
   case c20_IN_MonitoringNumber:
    CV_STATE_EVAL(13, 1, 1);
    chartInstance->c20_tp_MonitoringNumber = 0U;
    chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_PassAssigned:
    CV_STATE_EVAL(13, 1, 2);
    chartInstance->c20_tp_PassAssigned = 0U;
    chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_addToPass:
    CV_STATE_EVAL(13, 1, 3);
    chartInstance->c20_tp_addToPass = 0U;
    chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(13, 1, 0);
    chartInstance->c20_is_AssignPass = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_enter_atomic_closed(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  *chartInstance->c20_bulbPin_BOOL = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_bulbPin_BOOL, 38U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_leftMotor = *chartInstance->c20_CLOSED;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_rightMotor = *chartInstance->c20_CLOSED;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_rightMotor, 37U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_openingActive = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingActive, 7U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  *chartInstance->c20_gateState = *chartInstance->c20_CLOSED;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
  chartInstance->c20_closingTimer = 0U;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closingTimer, 1U, 4U, 0U,
                        (int16_T)chartInstance->c20_sfEvent, false);
}

static void c20_closed(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_out;
  boolean_T c20_b_out;
  boolean_T c20_c_out;
  boolean_T c20_temp;
  boolean_T c20_d_out;
  boolean_T c20_e_out;
  boolean_T c20_b_temp;
  boolean_T c20_c_temp;
  boolean_T c20_d_temp;
  boolean_T c20_f_out;
  int32_T c20_i24;
  int32_T c20_i25;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, chartInstance->c20_sfEvent);
  c20_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(14U, 0, (int32_T)
    chartInstance->c20_passSwitch_prev != (int32_T)
    chartInstance->c20_passSwitch_start != 0U, chartInstance->c20_sfEvent)) != 0);
  guard1 = false;
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 61U,
                 chartInstance->c20_sfEvent);
    c20_c_out = (CV_TRANSITION_EVAL(61U, (int32_T)_SFD_CCP_CALL(61U, 0,
      *chartInstance->c20_passSwitch != 0U, chartInstance->c20_sfEvent)) != 0);
    if (c20_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, chartInstance->c20_sfEvent);
      c20_exit_internal_closed(chartInstance);
      chartInstance->c20_tp_closed = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_init = 1U;
      c20_enter_atomic_init(chartInstance);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_init = c20_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_idle = 1U;
      *chartInstance->c20_passAssignedRAM_BOOL = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passAssignedRAM_BOOL,
                            39U, 4U, 18U, (int16_T)chartInstance->c20_sfEvent,
                            false);
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c20_sfEvent);
    c20_b_out = (CV_TRANSITION_EVAL(20U, (int32_T)_SFD_CCP_CALL(20U, 0,
      CV_RELATIONAL_EVAL(5U, 20U, 0, (real_T)chartInstance->c20_openingActive,
                         (real_T)*chartInstance->c20_OPENING_ACTIVE, 0, 0U,
                         chartInstance->c20_openingActive ==
                         *chartInstance->c20_OPENING_ACTIVE) != 0U,
      chartInstance->c20_sfEvent)) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
      c20_exit_internal_closed(chartInstance);
      chartInstance->c20_tp_closed = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_opening;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_opening = 1U;
      *chartInstance->c20_bulbPin_BOOL = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_bulbPin_BOOL, 38U, 4U,
                            22U, (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_stableTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 4U, 22U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      *chartInstance->c20_gateState = *chartInstance->c20_OPENING;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_gateState, 42U, 4U, 22U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_opening = c20_IN_openLeftSide;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_openLeftSide = 1U;
      *chartInstance->c20_leftMotor = *chartInstance->c20_OPENING;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U, 23U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_openSideDelay = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openSideDelay, 6U, 4U,
                            23U, (int16_T)chartInstance->c20_sfEvent, false);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c20_sfEvent);
      switch (chartInstance->c20_is_closed) {
       case c20_IN_KpPassHandler:
        CV_STATE_EVAL(0, 0, 1);
        c20_KpPassHandler(chartInstance);
        break;

       case c20_IN_MonitorInput:
        CV_STATE_EVAL(0, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U,
                     chartInstance->c20_sfEvent);
        c20_temp = (_SFD_CCP_CALL(65U, 0,
          chartInstance->c20_RFPressedOut_UINT8_prev !=
          chartInstance->c20_RFPressedOut_UINT8_start != 0U,
          chartInstance->c20_sfEvent) != 0);
        if (c20_temp) {
          c20_temp = (_SFD_CCP_CALL(65U, 1, CV_RELATIONAL_EVAL(5U, 65U, 0,
            (real_T)*chartInstance->c20_RFPressedOut_UINT8, 1.0, 0, 0U,
            *chartInstance->c20_RFPressedOut_UINT8 == 1) != 0U,
            chartInstance->c20_sfEvent) != 0);
        }

        c20_d_out = (CV_TRANSITION_EVAL(65U, (int32_T)c20_temp) != 0);
        if (c20_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_MonitorInput = 0U;
          chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 65U,
                       chartInstance->c20_sfEvent);
          chartInstance->c20_openingActive = *chartInstance->c20_OPENING_ACTIVE;
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingActive, 7U, 5U,
                                65U, (int16_T)chartInstance->c20_sfEvent, false);
          chartInstance->c20_is_closed = c20_IN_openingGate;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_openingGate = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                       chartInstance->c20_sfEvent);
          c20_e_out = (CV_TRANSITION_EVAL(9U, (int32_T)_SFD_CCP_CALL(9U, 0,
            chartInstance->c20_KpCharPressed_prev !=
            chartInstance->c20_KpCharPressed_start != 0U,
            chartInstance->c20_sfEvent)) != 0);
          guard2 = false;
          if (c20_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 62U,
                         chartInstance->c20_sfEvent);
            c20_b_temp = (_SFD_CCP_CALL(62U, 0, CV_RELATIONAL_EVAL(5U, 62U, 0,
              (real_T)*chartInstance->c20_KpCharPressed, 0.0, 0, 1U,
              *chartInstance->c20_KpCharPressed != 0) != 0U,
              chartInstance->c20_sfEvent) != 0);
            if (c20_b_temp) {
              c20_b_temp = (_SFD_CCP_CALL(62U, 1, CV_RELATIONAL_EVAL(5U, 62U, 1,
                (real_T)*chartInstance->c20_KpCharPressed, (real_T)
                *chartInstance->c20_OPEN_CHAR, 0, 1U,
                *chartInstance->c20_KpCharPressed !=
                *chartInstance->c20_OPEN_CHAR) != 0U, chartInstance->c20_sfEvent)
                            != 0);
            }

            c20_c_temp = c20_b_temp;
            if (c20_c_temp) {
              c20_c_temp = (_SFD_CCP_CALL(62U, 2, CV_RELATIONAL_EVAL(5U, 62U, 2,
                (real_T)*chartInstance->c20_KpCharPressed, (real_T)
                *chartInstance->c20_CLOSE_CHAR, 0, 1U,
                *chartInstance->c20_KpCharPressed !=
                *chartInstance->c20_CLOSE_CHAR) != 0U,
                chartInstance->c20_sfEvent) != 0);
            }

            c20_d_temp = c20_c_temp;
            if (c20_d_temp) {
              c20_d_temp = (_SFD_CCP_CALL(62U, 3,
                *chartInstance->c20_passAssignedRAM_BOOL != 0U,
                chartInstance->c20_sfEvent) != 0);
            }

            c20_f_out = (CV_TRANSITION_EVAL(62U, (int32_T)c20_d_temp) != 0);
            if (c20_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_tp_MonitorInput = 0U;
              chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 62U,
                           chartInstance->c20_sfEvent);
              *chartInstance->c20_passSuccess =
                *chartInstance->c20_PASS_INCOMPLETE;
              _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess, 40U,
                                    5U, 62U, (int16_T)chartInstance->c20_sfEvent,
                                    false);
              chartInstance->c20_trialPass[0] =
                *chartInstance->c20_KpCharPressed;
              for (c20_i24 = 0; c20_i24 < 6; c20_i24++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->
                                      c20_trialPass[c20_i24], 11U, 5U, 62U,
                                      (int16_T)chartInstance->c20_sfEvent, false);
              }

              chartInstance->c20_is_closed = c20_IN_KpPassHandler;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_KpPassHandler = 1U;
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_is_KpPassHandler = c20_IN_initTrailPass;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_initTrailPass = 1U;
              chartInstance->c20_initCounter = 1U;
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_initCounter, 5U,
                                    4U, 3U, (int16_T)chartInstance->c20_sfEvent,
                                    false);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U,
                           chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_is_initTrailPass = c20_IN_initiatePass;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_initiatePass = 1U;
              chartInstance->c20_trialPass[(uint8_T)sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 101U, 20, 9, 11U,
                 (int32_T)chartInstance->c20_initCounter, 0, 5)] = 0U;
              for (c20_i25 = 0; c20_i25 < 6; c20_i25++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->
                                      c20_trialPass[c20_i25], 11U, 4U, 4U,
                                      (int16_T)chartInstance->c20_sfEvent, false);
              }
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2 == true) {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                         chartInstance->c20_sfEvent);
          }
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c20_sfEvent);
        break;

       case c20_IN_openingGate:
        CV_STATE_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c20_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c20_sfEvent);
        break;

       default:
        CV_STATE_EVAL(0, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        break;
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_closed(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c20_is_closed) {
   case c20_IN_KpPassHandler:
    CV_STATE_EVAL(0, 1, 1);
    c20_exit_internal_KpPassHandler(chartInstance);
    chartInstance->c20_tp_KpPassHandler = 0U;
    chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_MonitorInput:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c20_tp_MonitorInput = 0U;
    chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_openingGate:
    CV_STATE_EVAL(0, 1, 3);
    chartInstance->c20_tp_openingGate = 0U;
    chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_KpPassHandler(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  boolean_T c20_out;
  boolean_T c20_b_out;
  boolean_T c20_c_out;
  int8_T c20_i26;
  uint32_T c20_u3;
  boolean_T c20_d_out;
  boolean_T c20_e_out;
  boolean_T c20_f_out;
  boolean_T c20_g_out;
  boolean_T c20_h_out;
  boolean_T c20_i_out;
  int16_T c20_i27;
  int16_T c20_i28;
  boolean_T c20_j_out;
  boolean_T c20_k_out;
  boolean_T c20_l_out;
  int32_T c20_i29;
  int32_T c20_i30;
  boolean_T c20_m_out;
  boolean_T c20_n_out;
  boolean_T c20_o_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c20_sfEvent);
  c20_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
    CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)chartInstance->c20_openingActive,
                       (real_T)*chartInstance->c20_OPENING_ACTIVE, 0, 0U,
                       chartInstance->c20_openingActive ==
                       *chartInstance->c20_OPENING_ACTIVE) != 0U,
    chartInstance->c20_sfEvent)) != 0);
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
    c20_exit_internal_KpPassHandler(chartInstance);
    chartInstance->c20_tp_KpPassHandler = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_closed = c20_IN_openingGate;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_openingGate = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c20_sfEvent);
    c20_b_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0,
      CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)*chartInstance->c20_passSuccess,
                         (real_T)*chartInstance->c20_WRONG_PASSWORD, 0, 0U,
                         *chartInstance->c20_passSuccess ==
                         *chartInstance->c20_WRONG_PASSWORD) != 0U,
      chartInstance->c20_sfEvent)) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
      c20_exit_internal_KpPassHandler(chartInstance);
      chartInstance->c20_tp_KpPassHandler = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_closed = c20_IN_MonitorInput;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_MonitorInput = 1U;
      chartInstance->c20_passTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                            (int16_T)chartInstance->c20_sfEvent, false);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                   chartInstance->c20_sfEvent);
      c20_c_out = (CV_TRANSITION_EVAL(68U, (int32_T)_SFD_CCP_CALL(68U, 0,
        CV_RELATIONAL_EVAL(5U, 68U, 0, (real_T)chartInstance->c20_passTimer,
                           (real_T)*chartInstance->c20_PASS_TIMEOUT, 0, 0U,
                           chartInstance->c20_passTimer ==
                           *chartInstance->c20_PASS_TIMEOUT) != 0U,
        chartInstance->c20_sfEvent)) != 0);
      if (c20_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, chartInstance->c20_sfEvent);
        c20_exit_internal_KpPassHandler(chartInstance);
        chartInstance->c20_tp_KpPassHandler = 0U;
        chartInstance->c20_is_closed = c20_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 68U,
                     chartInstance->c20_sfEvent);
        *chartInstance->c20_passSuccess = *chartInstance->c20_TIMEOUT;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess, 40U, 5U,
                              68U, (int16_T)chartInstance->c20_sfEvent, false);
        chartInstance->c20_is_closed = c20_IN_MonitorInput;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_MonitorInput = 1U;
        chartInstance->c20_passTimer = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                              (int16_T)chartInstance->c20_sfEvent, false);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c20_sfEvent);
        c20_i26 = 1;
        if (CV_SATURATION_EVAL(4, 1, 0, 0, c20_i26 < 0)) {
          c20_i26 = 0;
        }

        c20_u3 = (uint32_T)chartInstance->c20_passTimer + (uint32_T)(uint16_T)
          c20_i26;
        if (CV_SATURATION_EVAL(4, 1, 0, 0, c20_u3 > 65535U)) {
          c20_u3 = 65535U;
        }

        chartInstance->c20_passTimer = (uint16_T)c20_u3;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 1U,
                              (int16_T)chartInstance->c20_sfEvent, false);
        switch (chartInstance->c20_is_KpPassHandler) {
         case c20_IN_btnPressed:
          CV_STATE_EVAL(1, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                       chartInstance->c20_sfEvent);
          c20_d_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
            CV_RELATIONAL_EVAL(5U, 15U, 0, (real_T)chartInstance->c20_counter,
                               5.0, 0, 2U, chartInstance->c20_counter < 5) != 0U,
            chartInstance->c20_sfEvent)) != 0);
          if (c20_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_btnPressed = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
            chartInstance->c20_is_KpPassHandler = c20_IN_monitorBtnPressed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_monitorBtnPressed = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                         chartInstance->c20_sfEvent);
            c20_g_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(19U, 0,
              CV_RELATIONAL_EVAL(5U, 19U, 0, (real_T)chartInstance->c20_counter,
                                 5.0, 0, 5U, chartInstance->c20_counter >= 5) !=
              0U, chartInstance->c20_sfEvent)) != 0);
            if (c20_g_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_tp_btnPressed = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
              chartInstance->c20_is_KpPassHandler = c20_IN_verifyPass;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_verifyPass = 1U;
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U,
                           chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                           chartInstance->c20_sfEvent);
              c20_j_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
                CV_RELATIONAL_EVAL(5U, 25U, 0, (real_T)
                                   chartInstance->c20_trialPass[0], (real_T)
                                   (*chartInstance->c20_passwordRAM_UINT8_6D)[0],
                                   0, 1U, chartInstance->c20_trialPass[0] !=
                                   (*chartInstance->c20_passwordRAM_UINT8_6D)[0])
                != 0U, chartInstance->c20_sfEvent)) != 0);
              guard2 = false;
              guard3 = false;
              guard4 = false;
              guard5 = false;
              guard6 = false;
              if (c20_j_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U,
                             chartInstance->c20_sfEvent);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U,
                             chartInstance->c20_sfEvent);
                *chartInstance->c20_passSuccess =
                  *chartInstance->c20_WRONG_PASSWORD;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess,
                                      40U, 5U, 28U, (int16_T)
                                      chartInstance->c20_sfEvent, false);
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U,
                             chartInstance->c20_sfEvent);
                guard6 = true;
              } else {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U,
                             chartInstance->c20_sfEvent);
                _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                             chartInstance->c20_sfEvent);
                c20_k_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U,
                  0, CV_RELATIONAL_EVAL(5U, 27U, 0, (real_T)
                  chartInstance->c20_trialPass[1], (real_T)
                  (*chartInstance->c20_passwordRAM_UINT8_6D)[1], 0, 1U,
                  chartInstance->c20_trialPass[1] !=
                  (*chartInstance->c20_passwordRAM_UINT8_6D)[1]) != 0U,
                  chartInstance->c20_sfEvent)) != 0);
                if (c20_k_out) {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U,
                               chartInstance->c20_sfEvent);
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U,
                               chartInstance->c20_sfEvent);
                  *chartInstance->c20_passSuccess =
                    *chartInstance->c20_WRONG_PASSWORD;
                  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_passSuccess,
                                        40U, 5U, 29U, (int16_T)
                                        chartInstance->c20_sfEvent, false);
                  guard6 = true;
                } else {
                  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U,
                               chartInstance->c20_sfEvent);
                  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 32U,
                               chartInstance->c20_sfEvent);
                  c20_l_out = (CV_TRANSITION_EVAL(32U, (int32_T)_SFD_CCP_CALL
                    (32U, 0, CV_RELATIONAL_EVAL(5U, 32U, 0, (real_T)
                    chartInstance->c20_trialPass[2], (real_T)
                    (*chartInstance->c20_passwordRAM_UINT8_6D)[2], 0, 1U,
                    chartInstance->c20_trialPass[2] !=
                    (*chartInstance->c20_passwordRAM_UINT8_6D)[2]) != 0U,
                     chartInstance->c20_sfEvent)) != 0);
                  if (c20_l_out) {
                    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U,
                                 chartInstance->c20_sfEvent);
                    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U,
                                 chartInstance->c20_sfEvent);
                    *chartInstance->c20_passSuccess =
                      *chartInstance->c20_WRONG_PASSWORD;
                    _SFD_DATA_RANGE_CHECK((real_T)
                                          *chartInstance->c20_passSuccess, 40U,
                                          5U, 40U, (int16_T)
                                          chartInstance->c20_sfEvent, false);
                    guard5 = true;
                  } else {
                    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U,
                                 chartInstance->c20_sfEvent);
                    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                                 chartInstance->c20_sfEvent);
                    c20_m_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL
                      (33U, 0, CV_RELATIONAL_EVAL(5U, 33U, 0, (real_T)
                      chartInstance->c20_trialPass[3], (real_T)
                      (*chartInstance->c20_passwordRAM_UINT8_6D)[3], 0, 1U,
                      chartInstance->c20_trialPass[3] !=
                      (*chartInstance->c20_passwordRAM_UINT8_6D)[3]) != 0U,
                       chartInstance->c20_sfEvent)) != 0);
                    if (c20_m_out) {
                      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U,
                                   chartInstance->c20_sfEvent);
                      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U,
                                   chartInstance->c20_sfEvent);
                      *chartInstance->c20_passSuccess =
                        *chartInstance->c20_WRONG_PASSWORD;
                      _SFD_DATA_RANGE_CHECK((real_T)
                                            *chartInstance->c20_passSuccess, 40U,
                                            5U, 41U, (int16_T)
                                            chartInstance->c20_sfEvent, false);
                      guard4 = true;
                    } else {
                      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U,
                                   chartInstance->c20_sfEvent);
                      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                                   chartInstance->c20_sfEvent);
                      c20_n_out = (CV_TRANSITION_EVAL(35U, (int32_T)
                        _SFD_CCP_CALL(35U, 0, CV_RELATIONAL_EVAL(5U, 35U, 0,
                        (real_T)chartInstance->c20_trialPass[4], (real_T)
                        (*chartInstance->c20_passwordRAM_UINT8_6D)[4], 0, 1U,
                        chartInstance->c20_trialPass[4] !=
                        (*chartInstance->c20_passwordRAM_UINT8_6D)[4]) != 0U,
                                      chartInstance->c20_sfEvent)) != 0);
                      if (c20_n_out) {
                        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U,
                                     chartInstance->c20_sfEvent);
                        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U,
                                     chartInstance->c20_sfEvent);
                        *chartInstance->c20_passSuccess =
                          *chartInstance->c20_WRONG_PASSWORD;
                        _SFD_DATA_RANGE_CHECK((real_T)
                                              *chartInstance->c20_passSuccess,
                                              40U, 5U, 44U, (int16_T)
                                              chartInstance->c20_sfEvent, false);
                        guard3 = true;
                      } else {
                        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U,
                                     chartInstance->c20_sfEvent);
                        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U,
                                     chartInstance->c20_sfEvent);
                        c20_o_out = (CV_TRANSITION_EVAL(36U, (int32_T)
                          _SFD_CCP_CALL(36U, 0, CV_RELATIONAL_EVAL(5U, 36U, 0,
                          (real_T)chartInstance->c20_trialPass[5], (real_T)
                          (*chartInstance->c20_passwordRAM_UINT8_6D)[5], 0, 1U,
                          chartInstance->c20_trialPass[5] !=
                          (*chartInstance->c20_passwordRAM_UINT8_6D)[5]) != 0U,
                                        chartInstance->c20_sfEvent)) != 0);
                        if (c20_o_out) {
                          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U,
                                       chartInstance->c20_sfEvent);
                          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U,
                                       chartInstance->c20_sfEvent);
                          *chartInstance->c20_passSuccess =
                            *chartInstance->c20_WRONG_PASSWORD;
                          _SFD_DATA_RANGE_CHECK((real_T)
                                                *chartInstance->c20_passSuccess,
                                                40U, 5U, 47U, (int16_T)
                                                chartInstance->c20_sfEvent,
                                                false);
                          guard2 = true;
                        } else {
                          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U,
                                       chartInstance->c20_sfEvent);
                          *chartInstance->c20_passSuccess =
                            *chartInstance->c20_PASSWORD_VERIFIED;
                          _SFD_DATA_RANGE_CHECK((real_T)
                                                *chartInstance->c20_passSuccess,
                                                40U, 5U, 38U, (int16_T)
                                                chartInstance->c20_sfEvent,
                                                false);
                        }
                      }
                    }
                  }
                }
              }

              if (guard6 == true) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U,
                             chartInstance->c20_sfEvent);
                guard5 = true;
              }

              if (guard5 == true) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U,
                             chartInstance->c20_sfEvent);
                guard4 = true;
              }

              if (guard4 == true) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U,
                             chartInstance->c20_sfEvent);
                guard3 = true;
              }

              if (guard3 == true) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U,
                             chartInstance->c20_sfEvent);
                guard2 = true;
              }

              if (guard2 == true) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U,
                             chartInstance->c20_sfEvent);
              }

              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U,
                           chartInstance->c20_sfEvent);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                           chartInstance->c20_sfEvent);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_initTrailPass:
          CV_STATE_EVAL(1, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                       chartInstance->c20_sfEvent);
          c20_e_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0,
            CV_RELATIONAL_EVAL(5U, 23U, 0, (real_T)
                               chartInstance->c20_initCounter, 5.0, 0, 0U,
                               chartInstance->c20_initCounter == 5) != 0U,
            chartInstance->c20_sfEvent)) != 0);
          if (c20_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_initiatePass = 0U;
            chartInstance->c20_is_initTrailPass = c20_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_initTrailPass = 0U;
            chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 23U,
                         chartInstance->c20_sfEvent);
            chartInstance->c20_counter = 0U;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_counter, 3U, 5U,
                                  23U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
            chartInstance->c20_is_KpPassHandler = c20_IN_monitorBtnPressed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_monitorBtnPressed = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c20_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                         chartInstance->c20_sfEvent);
            c20_h_out = (CV_TRANSITION_EVAL(21U, (int32_T)_SFD_CCP_CALL(21U, 0,
              CV_RELATIONAL_EVAL(5U, 21U, 0, (real_T)
                                 chartInstance->c20_initCounter, 5.0, 0, 2U,
                                 chartInstance->c20_initCounter < 5) != 0U,
              chartInstance->c20_sfEvent)) != 0);
            if (c20_h_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U,
                           chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_tp_initiatePass = 0U;
              chartInstance->c20_is_initTrailPass = c20_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 21U,
                           chartInstance->c20_sfEvent);
              c20_i28 = (int16_T)(chartInstance->c20_initCounter + 1);
              if (CV_SATURATION_EVAL(5, 21, 0, 0, c20_i28 < 0)) {
                c20_i28 = 0;
              } else {
                if (c20_i28 > 255) {
                  c20_i28 = 255;
                }
              }

              chartInstance->c20_initCounter = (uint8_T)c20_i28;
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_initCounter, 5U,
                                    5U, 21U, (int16_T)chartInstance->c20_sfEvent,
                                    false);
              chartInstance->c20_is_initTrailPass = c20_IN_initiatePass;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_initiatePass = 1U;
              chartInstance->c20_trialPass[(uint8_T)sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 101U, 20, 9, 11U,
                 (int32_T)chartInstance->c20_initCounter, 0, 5)] = 0U;
              for (c20_i30 = 0; c20_i30 < 6; c20_i30++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->
                                      c20_trialPass[c20_i30], 11U, 4U, 4U,
                                      (int16_T)chartInstance->c20_sfEvent, false);
              }
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                           chartInstance->c20_sfEvent);
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U,
                         chartInstance->c20_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_monitorBtnPressed:
          CV_STATE_EVAL(1, 0, 3);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                       chartInstance->c20_sfEvent);
          c20_f_out = (CV_TRANSITION_EVAL(18U, (int32_T)_SFD_CCP_CALL(18U, 0,
            chartInstance->c20_KpCharPressed_prev !=
            chartInstance->c20_KpCharPressed_start != 0U,
            chartInstance->c20_sfEvent)) != 0);
          guard1 = false;
          if (c20_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c20_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                         chartInstance->c20_sfEvent);
            c20_i_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(63U, 0,
              CV_RELATIONAL_EVAL(5U, 63U, 0, (real_T)
                                 *chartInstance->c20_KpCharPressed, 0.0, 0, 1U, *
                                 chartInstance->c20_KpCharPressed != 0) != 0U,
              chartInstance->c20_sfEvent)) != 0);
            if (c20_i_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U,
                           chartInstance->c20_sfEvent);
              chartInstance->c20_tp_monitorBtnPressed = 0U;
              chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
              _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 63U,
                           chartInstance->c20_sfEvent);
              c20_i27 = (int16_T)(chartInstance->c20_counter + 1);
              if (CV_SATURATION_EVAL(5, 63, 0, 0, c20_i27 < 0)) {
                c20_i27 = 0;
              } else {
                if (c20_i27 > 255) {
                  c20_i27 = 255;
                }
              }

              chartInstance->c20_counter = (uint8_T)c20_i27;
              _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_counter, 3U, 5U,
                                    63U, (int16_T)chartInstance->c20_sfEvent,
                                    false);
              chartInstance->c20_is_KpPassHandler = c20_IN_btnPressed;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
              chartInstance->c20_tp_btnPressed = 1U;
              chartInstance->c20_trialPass[(uint8_T)sf_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 56U, 18, 9, 11U,
                 (int32_T)chartInstance->c20_counter, 0, 5)] =
                *chartInstance->c20_KpCharPressed;
              for (c20_i29 = 0; c20_i29 < 6; c20_i29++) {
                _SFD_DATA_RANGE_CHECK((real_T)chartInstance->
                                      c20_trialPass[c20_i29], 11U, 4U, 2U,
                                      (int16_T)chartInstance->c20_sfEvent, false);
              }
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1 == true) {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                         chartInstance->c20_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_verifyPass:
          CV_STATE_EVAL(1, 0, 4);
          c20_verifyPass(chartInstance);
          break;

         default:
          CV_STATE_EVAL(1, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
          break;
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_KpPassHandler
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  switch (chartInstance->c20_is_KpPassHandler) {
   case c20_IN_btnPressed:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c20_tp_btnPressed = 0U;
    chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_initTrailPass:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c20_tp_initiatePass = 0U;
    chartInstance->c20_is_initTrailPass = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_initTrailPass = 0U;
    chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_monitorBtnPressed:
    CV_STATE_EVAL(1, 1, 3);
    chartInstance->c20_tp_monitorBtnPressed = 0U;
    chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_verifyPass:
    CV_STATE_EVAL(1, 1, 4);
    chartInstance->c20_tp_verifyPass = 0U;
    chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_verifyPass(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_temp;
  boolean_T c20_out;
  boolean_T c20_b_temp;
  boolean_T c20_b_out;
  int32_T c20_i31;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, chartInstance->c20_sfEvent);
  c20_temp = (_SFD_CCP_CALL(16U, 0, chartInstance->c20_KpCharPressed_prev !=
    chartInstance->c20_KpCharPressed_start != 0U, chartInstance->c20_sfEvent) !=
              0);
  if (c20_temp) {
    c20_temp = (_SFD_CCP_CALL(16U, 1, CV_RELATIONAL_EVAL(5U, 16U, 0, (real_T)
      *chartInstance->c20_passSuccess, (real_T)
      *chartInstance->c20_PASSWORD_VERIFIED, 0, 0U,
      *chartInstance->c20_passSuccess == *chartInstance->c20_PASSWORD_VERIFIED)
      != 0U, chartInstance->c20_sfEvent) != 0);
  }

  c20_out = (CV_TRANSITION_EVAL(16U, (int32_T)c20_temp) != 0);
  guard1 = false;
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U,
                 chartInstance->c20_sfEvent);
    c20_b_temp = (_SFD_CCP_CALL(64U, 0, CV_RELATIONAL_EVAL(5U, 64U, 0, (real_T)
      *chartInstance->c20_KpCharPressed, (real_T)*chartInstance->c20_OPEN_CHAR,
      0, 0U, *chartInstance->c20_KpCharPressed == *chartInstance->c20_OPEN_CHAR)
      != 0U, chartInstance->c20_sfEvent) != 0);
    if (c20_b_temp) {
      c20_b_temp = (_SFD_CCP_CALL(64U, 1, CV_RELATIONAL_EVAL(5U, 64U, 1, (real_T)*
        chartInstance->c20_KpCharPressed, 0.0, 0, 1U,
        *chartInstance->c20_KpCharPressed != 0) != 0U,
        chartInstance->c20_sfEvent) != 0);
    }

    c20_b_out = (CV_TRANSITION_EVAL(64U, (int32_T)c20_b_temp) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_verifyPass = 0U;
      chartInstance->c20_is_KpPassHandler = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c20_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 64U,
                   chartInstance->c20_sfEvent);
      chartInstance->c20_openingActive = *chartInstance->c20_OPENING_ACTIVE;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_openingActive, 7U, 5U,
                            64U, (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_is_KpPassHandler = c20_IN_initTrailPass;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_initTrailPass = 1U;
      chartInstance->c20_initCounter = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_initCounter, 5U, 4U, 3U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, chartInstance->c20_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_initTrailPass = c20_IN_initiatePass;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_initiatePass = 1U;
      chartInstance->c20_trialPass[(uint8_T)sf_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 101U, 20, 9, 11U,
         (int32_T)chartInstance->c20_initCounter, 0, 5)] = 0U;
      for (c20_i31 = 0; c20_i31 < 6; c20_i31++) {
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_trialPass[c20_i31], 11U,
                              4U, 4U, (int16_T)chartInstance->c20_sfEvent, false);
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c20_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c20_sfEvent);
}

static void c20_closing(SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  boolean_T c20_temp;
  boolean_T c20_out;
  boolean_T c20_b_temp;
  boolean_T c20_c_temp;
  boolean_T c20_d_temp;
  boolean_T c20_e_temp;
  boolean_T c20_b_out;
  boolean_T c20_c_out;
  int8_T c20_i32;
  uint64_T c20_u4;
  int8_T c20_i33;
  boolean_T c20_d_out;
  uint64_T c20_u5;
  int8_T c20_i34;
  uint32_T c20_u6;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U, chartInstance->c20_sfEvent);
  c20_temp = (_SFD_CCP_CALL(55U, 0, CV_RELATIONAL_EVAL(5U, 55U, 0, (real_T)
    *chartInstance->c20_current_sensor, 0.0, 0, 0U,
    !*chartInstance->c20_current_sensor) != 0U, chartInstance->c20_sfEvent) != 0);
  if (c20_temp) {
    c20_temp = (_SFD_CCP_CALL(55U, 1, CV_RELATIONAL_EVAL(5U, 55U, 1, (real_T)
      chartInstance->c20_stableTimer, 10.0, 0, 5U,
      chartInstance->c20_stableTimer >= 10U) != 0U, chartInstance->c20_sfEvent)
                != 0);
  }

  c20_out = (CV_TRANSITION_EVAL(55U, (int32_T)c20_temp) != 0);
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, chartInstance->c20_sfEvent);
    c20_exit_internal_closing(chartInstance);
    chartInstance->c20_tp_closing = 0U;
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 55U,
                 chartInstance->c20_sfEvent);
    chartInstance->c20_stableTimer = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 5U, 55U,
                          (int16_T)chartInstance->c20_sfEvent, false);
    chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closed;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_closed = 1U;
    c20_enter_atomic_closed(chartInstance);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_closed = c20_IN_MonitorInput;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_MonitorInput = 1U;
    chartInstance->c20_passTimer = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                          (int16_T)chartInstance->c20_sfEvent, false);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 71U,
                 chartInstance->c20_sfEvent);
    c20_b_temp = (_SFD_CCP_CALL(71U, 0,
      chartInstance->c20_RFPressedOut_UINT8_prev !=
      chartInstance->c20_RFPressedOut_UINT8_start != 0U,
      chartInstance->c20_sfEvent) != 0);
    if (c20_b_temp) {
      c20_b_temp = (_SFD_CCP_CALL(71U, 1, CV_RELATIONAL_EVAL(5U, 71U, 0, (real_T)*
        chartInstance->c20_RFPressedOut_UINT8, 1.0, 0, 0U,
        *chartInstance->c20_RFPressedOut_UINT8 == 1) != 0U,
        chartInstance->c20_sfEvent) != 0);
    }

    c20_c_temp = c20_b_temp;
    if (!c20_c_temp) {
      c20_d_temp = (_SFD_CCP_CALL(71U, 2, CV_RELATIONAL_EVAL(5U, 71U, 1, (real_T)*
        chartInstance->c20_KpCharPressed, (real_T)*chartInstance->c20_CLOSE_CHAR,
        0, 0U, *chartInstance->c20_KpCharPressed ==
        *chartInstance->c20_CLOSE_CHAR) != 0U, chartInstance->c20_sfEvent) != 0);
      if (c20_d_temp) {
        c20_d_temp = (_SFD_CCP_CALL(71U, 3, CV_RELATIONAL_EVAL(5U, 71U, 2,
          (real_T)chartInstance->c20_KpCharPressed_prev, (real_T)
          chartInstance->c20_KpCharPressed_start, 0, 1U,
          chartInstance->c20_KpCharPressed_prev !=
          chartInstance->c20_KpCharPressed_start) != 0U,
          chartInstance->c20_sfEvent) != 0);
      }

      c20_c_temp = c20_d_temp;
    }

    c20_e_temp = c20_c_temp;
    if (c20_e_temp) {
      c20_e_temp = (_SFD_CCP_CALL(71U, 4, CV_RELATIONAL_EVAL(5U, 71U, 3, (real_T)
        chartInstance->c20_stableTimer, 10.0, 0, 5U,
        chartInstance->c20_stableTimer >= 10U) != 0U, chartInstance->c20_sfEvent)
                    != 0);
    }

    c20_b_out = (CV_TRANSITION_EVAL(71U, (int32_T)c20_e_temp) != 0);
    if (c20_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, chartInstance->c20_sfEvent);
      c20_exit_internal_closing(chartInstance);
      chartInstance->c20_tp_closing = 0U;
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 71U,
                   chartInstance->c20_sfEvent);
      chartInstance->c20_stableTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 5U, 71U,
                            (int16_T)chartInstance->c20_sfEvent, false);
      chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_closed = 1U;
      c20_enter_atomic_closed(chartInstance);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
      chartInstance->c20_is_closed = c20_IN_MonitorInput;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
      chartInstance->c20_tp_MonitorInput = 1U;
      chartInstance->c20_passTimer = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                            (int16_T)chartInstance->c20_sfEvent, false);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 73U,
                   chartInstance->c20_sfEvent);
      c20_c_out = (CV_TRANSITION_EVAL(73U, (int32_T)_SFD_CCP_CALL(73U, 0,
        CV_RELATIONAL_EVAL(5U, 73U, 0, (real_T)chartInstance->c20_closingTimer,
                           (real_T)*chartInstance->c20_MOVING_TIMER, 0, 5U,
                           chartInstance->c20_closingTimer >=
                           *chartInstance->c20_MOVING_TIMER) != 0U,
        chartInstance->c20_sfEvent)) != 0);
      if (c20_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, chartInstance->c20_sfEvent);
        c20_exit_internal_closing(chartInstance);
        chartInstance->c20_tp_closing = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_gate_V32_2016a_Sim = c20_IN_closed;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_closed = 1U;
        c20_enter_atomic_closed(chartInstance);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_closed = c20_IN_MonitorInput;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_MonitorInput = 1U;
        chartInstance->c20_passTimer = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_passTimer, 9U, 4U, 7U,
                              (int16_T)chartInstance->c20_sfEvent, false);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c20_sfEvent);
        c20_i32 = 1;
        if (CV_SATURATION_EVAL(4, 9, 0, 0, c20_i32 < 0)) {
          c20_i32 = 0;
        }

        c20_u4 = (uint64_T)chartInstance->c20_closingTimer + (uint64_T)(uint32_T)
          c20_i32;
        if (CV_SATURATION_EVAL(4, 9, 0, 0, c20_u4 > 4294967295ULL)) {
          c20_u4 = 4294967295ULL;
        }

        chartInstance->c20_closingTimer = (uint32_T)c20_u4;
        _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closingTimer, 1U, 4U,
                              9U, (int16_T)chartInstance->c20_sfEvent, false);
        switch (chartInstance->c20_is_closing) {
         case c20_IN_closingLeftSide:
          CV_STATE_EVAL(9, 0, 1);
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                       chartInstance->c20_sfEvent);
          c20_i33 = 1;
          if (CV_SATURATION_EVAL(4, 10, 0, 0, c20_i33 < 0)) {
            c20_i33 = 0;
          }

          c20_u5 = (uint64_T)chartInstance->c20_stableTimer + (uint64_T)
            (uint32_T)c20_i33;
          if (CV_SATURATION_EVAL(4, 10, 0, 0, c20_u5 > 4294967295ULL)) {
            c20_u5 = 4294967295ULL;
          }

          chartInstance->c20_stableTimer = (uint32_T)c20_u5;
          _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_stableTimer, 10U, 4U,
                                10U, (int16_T)chartInstance->c20_sfEvent, false);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c20_sfEvent);
          break;

         case c20_IN_closingRightSide:
          CV_STATE_EVAL(9, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 56U,
                       chartInstance->c20_sfEvent);
          c20_d_out = (CV_TRANSITION_EVAL(56U, (int32_T)_SFD_CCP_CALL(56U, 0,
            CV_RELATIONAL_EVAL(5U, 56U, 0, (real_T)
                               chartInstance->c20_closeSideDelay, (real_T)
                               *chartInstance->c20_CLOSE_SIDE_VALUE, -3, 0U,
                               (real32_T)chartInstance->c20_closeSideDelay ==
                               *chartInstance->c20_CLOSE_SIDE_VALUE) != 0U,
            chartInstance->c20_sfEvent)) != 0);
          if (c20_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_closingRightSide = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
            chartInstance->c20_is_closing = c20_IN_closingLeftSide;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
            chartInstance->c20_tp_closingLeftSide = 1U;
            *chartInstance->c20_leftMotor = *chartInstance->c20_CLOSING;
            _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_leftMotor, 36U, 4U,
                                  10U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                         chartInstance->c20_sfEvent);
            c20_i34 = 1;
            if (CV_SATURATION_EVAL(4, 11, 0, 0, c20_i34 < 0)) {
              c20_i34 = 0;
            }

            c20_u6 = (uint32_T)chartInstance->c20_closeSideDelay + (uint32_T)
              (uint16_T)c20_i34;
            if (CV_SATURATION_EVAL(4, 11, 0, 0, c20_u6 > 65535U)) {
              c20_u6 = 65535U;
            }

            chartInstance->c20_closeSideDelay = (uint16_T)c20_u6;
            _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c20_closeSideDelay, 0U,
                                  4U, 11U, (int16_T)chartInstance->c20_sfEvent,
                                  false);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c20_sfEvent);
          break;

         default:
          CV_STATE_EVAL(9, 0, 0);

          /* Unreachable state, for coverage only */
          chartInstance->c20_is_closing = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
          break;
        }
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c20_sfEvent);
}

static void c20_exit_internal_closing(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c20_is_closing) {
   case c20_IN_closingLeftSide:
    CV_STATE_EVAL(9, 1, 1);
    chartInstance->c20_tp_closingLeftSide = 0U;
    chartInstance->c20_is_closing = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_closingRightSide:
    CV_STATE_EVAL(9, 1, 2);
    chartInstance->c20_tp_closingRightSide = 0U;
    chartInstance->c20_is_closing = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 1, 0);
    chartInstance->c20_is_closing = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c20_sfEvent);
    break;
  }
}

static void c20_exit_internal_open(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c20_is_open) {
   case c20_b_IN_closing:
    CV_STATE_EVAL(19, 1, 1);
    chartInstance->c20_b_tp_closing = 0U;
    chartInstance->c20_is_open = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
    break;

   case c20_IN_gateOpen:
    CV_STATE_EVAL(19, 1, 2);
    chartInstance->c20_tp_gateOpen = 0U;
    chartInstance->c20_is_open = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(19, 1, 0);
    chartInstance->c20_is_open = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c20_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

const mxArray *sf_c20_gate_V32_2016a_Sim_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i35;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i35, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i35;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint8_T c20_b_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_opening, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_opening),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_opening);
  return c20_y;
}

static uint8_T c20_c_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u7;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u7, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u7;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_tp_opening;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_tp_opening = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_opening),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_opening);
  *(uint8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  boolean_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(boolean_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i36;
  const mxArray *c20_y = NULL;
  uint8_T c20_u[6];
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i36 = 0; c20_i36 < 6; c20_i36++) {
    c20_u[c20_i36] = (*(uint8_T (*)[6])c20_inData)[c20_i36];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 3, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_d_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_trialPass, const char_T *c20_identifier,
  uint8_T c20_y[6])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_trialPass), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_trialPass);
}

static void c20_e_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  uint8_T c20_y[6])
{
  uint8_T c20_uv2[6];
  int32_T c20_i37;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_uv2, 1, 3, 0U, 1, 0U, 1, 6);
  for (c20_i37 = 0; c20_i37 < 6; c20_i37++) {
    c20_y[c20_i37] = c20_uv2[c20_i37];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_trialPass;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y[6];
  int32_T c20_i38;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_trialPass = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_trialPass), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_b_trialPass);
  for (c20_i38 = 0; c20_i38 < 6; c20_i38++) {
    (*(uint8_T (*)[6])c20_outData)[c20_i38] = c20_y[c20_i38];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint16_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint16_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint16_T c20_f_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_openSideDelay, const char_T
  *c20_identifier)
{
  uint16_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_openSideDelay),
    &c20_thisId);
  sf_mex_destroy(&c20_b_openSideDelay);
  return c20_y;
}

static uint16_T c20_g_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint16_T c20_y;
  uint16_T c20_u8;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u8, 1, 5, 0U, 0, 0U, 0);
  c20_y = c20_u8;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_openSideDelay;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint16_T c20_y;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_openSideDelay = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_openSideDelay),
    &c20_thisId);
  sf_mex_destroy(&c20_b_openSideDelay);
  *(uint16_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static boolean_T c20_h_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_bulbPin_BOOL, const char_T
  *c20_identifier)
{
  boolean_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_bulbPin_BOOL),
    &c20_thisId);
  sf_mex_destroy(&c20_b_bulbPin_BOOL);
  return c20_y;
}

static boolean_T c20_i_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  boolean_T c20_y;
  boolean_T c20_b0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_b0, 1, 11, 0U, 0, 0U, 0);
  c20_y = c20_b0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_bulbPin_BOOL;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  boolean_T c20_y;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_bulbPin_BOOL = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_bulbPin_BOOL),
    &c20_thisId);
  sf_mex_destroy(&c20_b_bulbPin_BOOL);
  *(boolean_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint32_T c20_j_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_b_stableTimer, const char_T *c20_identifier)
{
  uint32_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_stableTimer),
    &c20_thisId);
  sf_mex_destroy(&c20_b_stableTimer);
  return c20_y;
}

static uint32_T c20_k_emlrt_marshallIn(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint32_T c20_y;
  uint32_T c20_u9;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u9, 1, 7, 0U, 0, 0U, 0);
  c20_y = c20_u9;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_stableTimer;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint32_T c20_y;
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)chartInstanceVoid;
  c20_b_stableTimer = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  c20_y = c20_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_stableTimer),
    &c20_thisId);
  sf_mex_destroy(&c20_b_stableTimer);
  *(uint32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_l_emlrt_marshallIn
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier)
{
  const mxArray *c20_y = NULL;
  emlrtMsgIdentifier c20_thisId;
  c20_y = NULL;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_thisId.bParentIsCell = false;
  sf_mex_assign(&c20_y, c20_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_setSimStateSideEffectsInfo), &c20_thisId), false);
  sf_mex_destroy(&c20_b_setSimStateSideEffectsInfo);
  return c20_y;
}

static const mxArray *c20_m_emlrt_marshallIn
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId)
{
  const mxArray *c20_y = NULL;
  (void)chartInstance;
  (void)c20_parentId;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_duplicatearraysafe(&c20_u), false);
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance, int32_T c20_ssid)
{
  (void)chartInstance;
  (void)c20_ssid;
  return NULL;
}

static void c20_init_sf_message_store_memory
  (SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc20_gate_V32_2016a_SimInstanceStruct
  *chartInstance)
{
  chartInstance->c20_KpCharPressed = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c20_RFPressedOut_UINT8 = (uint8_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c20_passSwitch = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c20_current_sensor = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_leftMotor = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c20_rightMotor = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c20_bulbPin_BOOL = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_OPENING_ACTIVE = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c20_WRONG_PASSWORD = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c20_OPEN_SIDE_VALUE = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c20_CLOSE_SIDE_VALUE = (real32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c20_PASSWORD_VERIFIED = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c20_CLOSE_CHAR = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c20_OPEN_CHAR = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c20_OPENING = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c20_CLOSED = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c20_CLOSING = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c20_OPEN = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c20_passAssignedRAM_BOOL = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c20_passSuccess = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c20_NO_PASS_ASSIG = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c20_PASS_ASSIGNED = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c20_PASS_INCOMPLETE = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 17);
  chartInstance->c20_PASS_TIMEOUT = (uint16_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c20_TIMEOUT = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 19);
  chartInstance->c20_passwordRAM_UINT8_6D = (uint8_T (*)[6])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 6);
  chartInstance->c20_passwordIn = (uint8_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 20);
  chartInstance->c20_passAssignedIn = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 21);
  chartInstance->c20_gateState = (uint8_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c20_INIT = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 22);
  chartInstance->c20_MOVING_TIMER = (uint32_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 23);
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

void sf_c20_gate_V32_2016a_Sim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2265712924U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(29750776U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(708246737U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2603560089U);
}

mxArray* sf_c20_gate_V32_2016a_Sim_get_post_codegen_info(void);
mxArray *sf_c20_gate_V32_2016a_Sim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zQ7cgIKIZhNVlf9ZLEldeE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,24,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c20_gate_V32_2016a_Sim_get_post_codegen_info
      ();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_gate_V32_2016a_Sim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_gate_V32_2016a_Sim_jit_fallback_info(void)
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

mxArray *sf_c20_gate_V32_2016a_Sim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c20_gate_V32_2016a_Sim_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c20_gate_V32_2016a_Sim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[195],T\"bulbPin_BOOL\",},{M[1],M[374],T\"gateState\",},{M[1],M[191],T\"leftMotor\",},{M[1],M[80],T\"passAssignedRAM_BOOL\",},{M[1],M[72],T\"passSuccess\",},{M[1],M[75],T\"passwordRAM_UINT8_6D\",},{M[1],M[192],T\"rightMotor\",},{M[3],M[216],T\"closeSideDelay\",},{M[3],M[380],T\"closingTimer\",},{M[3],M[90],T\"closing_active\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[79],T\"counter\",},{M[3],M[267],T\"gotoReady\",},{M[3],M[103],T\"initCounter\",},{M[3],M[190],T\"openSideDelay\",},{M[3],M[71],T\"openingActive\",},{M[3],M[381],T\"openingTimer\",},{M[3],M[359],T\"passTimer\",},{M[3],M[373],T\"stableTimer\",},{M[3],M[77],T\"trialPass\",},{M[8],M[0],T\"is_active_c20_gate_V32_2016a_Sim\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[0],T\"is_c20_gate_V32_2016a_Sim\",},{M[9],M[6],T\"is_AssignPass\",},{M[9],M[22],T\"is_init\",},{M[9],M[32],T\"is_closed\",},{M[9],M[62],T\"is_KpPassHandler\",},{M[9],M[97],T\"is_initTrailPass\",},{M[9],M[183],T\"is_opening\",},{M[9],M[197],T\"is_open\",},{M[9],M[206],T\"is_closing\",},{M[12],M[69],T\"KpCharPressed_start\",}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[12],M[70],T\"RFPressedOut_UINT8_start\",},{M[12],M[73],T\"passSwitch_start\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 32, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_gate_V32_2016a_Sim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc20_gate_V32_2016a_SimInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance =
      (SFc20_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _gate_V32_2016a_SimMachineNumber_,
           20,
           25,
           74,
           0,
           43,
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
          _SFD_SET_DATA_PROPS(0,0,0,0,"closeSideDelay");
          _SFD_SET_DATA_PROPS(1,0,0,0,"closingTimer");
          _SFD_SET_DATA_PROPS(2,0,0,0,"closing_active");
          _SFD_SET_DATA_PROPS(3,0,0,0,"counter");
          _SFD_SET_DATA_PROPS(4,0,0,0,"gotoReady");
          _SFD_SET_DATA_PROPS(5,0,0,0,"initCounter");
          _SFD_SET_DATA_PROPS(6,0,0,0,"openSideDelay");
          _SFD_SET_DATA_PROPS(7,0,0,0,"openingActive");
          _SFD_SET_DATA_PROPS(8,0,0,0,"openingTimer");
          _SFD_SET_DATA_PROPS(9,0,0,0,"passTimer");
          _SFD_SET_DATA_PROPS(10,0,0,0,"stableTimer");
          _SFD_SET_DATA_PROPS(11,0,0,0,"trialPass");
          _SFD_SET_DATA_PROPS(12,1,1,0,"KpCharPressed");
          _SFD_SET_DATA_PROPS(13,1,1,0,"RFPressedOut_UINT8");
          _SFD_SET_DATA_PROPS(14,1,1,0,"passSwitch");
          _SFD_SET_DATA_PROPS(15,1,1,0,"current_sensor");
          _SFD_SET_DATA_PROPS(16,1,1,0,"OPENING_ACTIVE");
          _SFD_SET_DATA_PROPS(17,1,1,0,"WRONG_PASSWORD");
          _SFD_SET_DATA_PROPS(18,1,1,0,"OPEN_SIDE_VALUE");
          _SFD_SET_DATA_PROPS(19,1,1,0,"CLOSE_SIDE_VALUE");
          _SFD_SET_DATA_PROPS(20,1,1,0,"PASSWORD_VERIFIED");
          _SFD_SET_DATA_PROPS(21,1,1,0,"CLOSE_CHAR");
          _SFD_SET_DATA_PROPS(22,1,1,0,"OPEN_CHAR");
          _SFD_SET_DATA_PROPS(23,1,1,0,"OPENING");
          _SFD_SET_DATA_PROPS(24,1,1,0,"CLOSED");
          _SFD_SET_DATA_PROPS(25,1,1,0,"CLOSING");
          _SFD_SET_DATA_PROPS(26,1,1,0,"OPEN");
          _SFD_SET_DATA_PROPS(27,1,1,0,"NO_PASS_ASSIG");
          _SFD_SET_DATA_PROPS(28,1,1,0,"PASS_ASSIGNED");
          _SFD_SET_DATA_PROPS(29,1,1,0,"PASS_INCOMPLETE");
          _SFD_SET_DATA_PROPS(30,1,1,0,"PASS_TIMEOUT");
          _SFD_SET_DATA_PROPS(31,1,1,0,"TIMEOUT");
          _SFD_SET_DATA_PROPS(32,1,1,0,"passwordIn");
          _SFD_SET_DATA_PROPS(33,1,1,0,"passAssignedIn");
          _SFD_SET_DATA_PROPS(34,1,1,0,"INIT");
          _SFD_SET_DATA_PROPS(35,1,1,0,"MOVING_TIMER");
          _SFD_SET_DATA_PROPS(36,2,0,1,"leftMotor");
          _SFD_SET_DATA_PROPS(37,2,0,1,"rightMotor");
          _SFD_SET_DATA_PROPS(38,2,0,1,"bulbPin_BOOL");
          _SFD_SET_DATA_PROPS(39,2,0,1,"passAssignedRAM_BOOL");
          _SFD_SET_DATA_PROPS(40,2,0,1,"passSuccess");
          _SFD_SET_DATA_PROPS(41,2,0,1,"passwordRAM_UINT8_6D");
          _SFD_SET_DATA_PROPS(42,2,0,1,"gateState");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,9);
          _SFD_CH_SUBSTATE_INDEX(2,12);
          _SFD_CH_SUBSTATE_INDEX(3,19);
          _SFD_CH_SUBSTATE_INDEX(4,22);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,7);
          _SFD_ST_SUBSTATE_INDEX(0,2,8);
          _SFD_ST_SUBSTATE_COUNT(1,4);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,5);
          _SFD_ST_SUBSTATE_INDEX(1,3,6);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,1);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,2);
          _SFD_ST_SUBSTATE_INDEX(9,0,10);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,3);
          _SFD_ST_SUBSTATE_INDEX(12,0,13);
          _SFD_ST_SUBSTATE_INDEX(12,1,17);
          _SFD_ST_SUBSTATE_INDEX(12,2,18);
          _SFD_ST_SUBSTATE_COUNT(13,3);
          _SFD_ST_SUBSTATE_INDEX(13,0,14);
          _SFD_ST_SUBSTATE_INDEX(13,1,15);
          _SFD_ST_SUBSTATE_INDEX(13,2,16);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,2);
          _SFD_ST_SUBSTATE_INDEX(19,0,20);
          _SFD_ST_SUBSTATE_INDEX(19,1,21);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,2);
          _SFD_ST_SUBSTATE_INDEX(22,0,23);
          _SFD_ST_SUBSTATE_INDEX(22,1,24);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
        }

        _SFD_CV_INIT_CHART(5,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,4,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 18 };

          static unsigned int sEndSaturateMap[] = { 29 };

          _SFD_CV_INIT_STATE_SATURATION(1,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,1,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 40 };

          static unsigned int sEndSaturateMap[] = { 54 };

          _SFD_CV_INIT_STATE_SATURATION(9,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 48 };

          static unsigned int sEndSaturateMap[] = { 65 };

          _SFD_CV_INIT_STATE_SATURATION(10,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 74 };

          static unsigned int sEndSaturateMap[] = { 90 };

          _SFD_CV_INIT_STATE_SATURATION(11,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(12,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,2,1,1,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 78 };

          static unsigned int sEndSaturateMap[] = { 92 };

          _SFD_CV_INIT_STATE_SATURATION(22,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 68 };

          static unsigned int sEndSaturateMap[] = { 83 };

          _SFD_CV_INIT_STATE_SATURATION(23,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartSaturateMap[] = { 47 };

          static unsigned int sEndSaturateMap[] = { 64 };

          _SFD_CV_INIT_STATE_SATURATION(24,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(61,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 32 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(20,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 32 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(20,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 38 };

          static unsigned int sEndGuardMap[] = { 31, 64 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(67,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 38 };

          static unsigned int sEndRelationalopMap[] = { 64 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(67,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 29 };

          static unsigned int sEndGuardMap[] = { 21, 46 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(55,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29 };

          static unsigned int sEndRelationalopMap[] = { 21, 46 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 0, 5, 0, 5, 0, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(55,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 29 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(73,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 29 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(73,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 40, 78, 114, 149 };

          static unsigned int sEndGuardMap[] = { 33, 66, 105, 139, 166 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2, 4, -3 };

          _SFD_CV_INIT_TRANS(71,5,&(sStartGuardMap[0]),&(sEndGuardMap[0]),9,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 40, 78, 114, 149 };

          static unsigned int sEndRelationalopMap[] = { 66, 105, 139, 166 };

          static int sRelationalopEps[] = { 0, 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 1, 5, 0, 0, 1, 5, 0, 0, 1, 5
          };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(71,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 40, 78, 113, 148 };

          static unsigned int sEndGuardMap[] = { 33, 66, 104, 138, 165 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2, 4, -3 };

          _SFD_CV_INIT_TRANS(70,5,&(sStartGuardMap[0]),&(sEndGuardMap[0]),9,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 40, 78, 113, 148 };

          static unsigned int sEndRelationalopMap[] = { 66, 104, 138, 165 };

          static int sRelationalopEps[] = { 0, 0, 0, 0 };

          static int sRelationalopType[] = { 0, 0, 1, 5, 0, 0, 1, 5, 0, 0, 1, 5
          };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(70,4,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 29 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(72,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 29 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(72,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 30 };

          static unsigned int sEndGuardMap[] = { 21, 47 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(50,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 30 };

          static unsigned int sEndRelationalopMap[] = { 21, 47 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 0, 5, 0, 5, 0, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(50,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(53,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(53,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(69,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 19 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(60,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 19 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(60,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 14 };

          static unsigned int sEndSaturateMap[] = { 23 };

          _SFD_CV_INIT_TRANSITION_SATURATION(5,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(5,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 27 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 13 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(6,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 36 };

          static unsigned int sEndGuardMap[] = { 31, 62 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(65,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 36 };

          static unsigned int sEndRelationalopMap[] = { 62 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(65,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(68,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2 };

          static unsigned int sEndRelationalopMap[] = { 27 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(68,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 32 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 32 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(8,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(9,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 31 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2 };

          static unsigned int sEndRelationalopMap[] = { 31 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(10,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 29, 63, 98 };

          static unsigned int sEndGuardMap[] = { 20, 55, 90, 118 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_TRANS(62,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 29, 63 };

          static unsigned int sEndRelationalopMap[] = { 20, 55, 90 };

          static int sRelationalopEps[] = { 0, 0, 0 };

          static int sRelationalopType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(62,3,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(18,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 19 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(63,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 22 };

          static unsigned int sEndSaturateMap[] = { 31 };

          _SFD_CV_INIT_TRANSITION_SATURATION(63,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 19 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(63,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 17 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(23,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 12 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(15,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 38 };

          static unsigned int sEndGuardMap[] = { 28, 56 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(64,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 2, 38 };

          static unsigned int sEndRelationalopMap[] = { 28, 56 };

          static int sRelationalopEps[] = { 0, 0 };

          static int sRelationalopType[] = { 0, 1, 0, 1, 0, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(64,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 13 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 5, 5, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(19,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 31 };

          static unsigned int sEndGuardMap[] = { 26, 63 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(16,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 31 };

          static unsigned int sEndRelationalopMap[] = { 63 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(16,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartSaturateMap[] = { 22 };

          static unsigned int sEndSaturateMap[] = { 35 };

          _SFD_CV_INIT_TRANSITION_SATURATION(21,1,&(sStartSaturateMap[0]),
            &(sEndSaturateMap[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 16 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(21,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(25,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(27,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(32,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(32,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(33,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(35,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(35,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 40 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(36,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 40 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 1, 1, 1 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(36,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 33 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(51,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 33 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(51,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 35 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(56,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 35 };

          static int sRelationalopEps[] = { -3 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(56,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 31 };

          static unsigned int sEndGuardMap[] = { 26, 58 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(57,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 31 };

          static unsigned int sEndRelationalopMap[] = { 58 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(57,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 36 };

          static unsigned int sEndGuardMap[] = { 31, 62 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(54,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 36 };

          static unsigned int sEndRelationalopMap[] = { 62 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(54,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_g_sf_marshallOut,(MexInFcnForType)
          c20_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)
          c20_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_g_sf_marshallOut,(MexInFcnForType)
          c20_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_g_sf_marshallOut,(MexInFcnForType)
          c20_f_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
            c20_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)
          c20_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)
          c20_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(41,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
            c20_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(42,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
          c20_b_sf_marshallIn);
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
    SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance =
      (SFc20_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c20_KpCharPressed);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c20_RFPressedOut_UINT8);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c20_openingActive);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c20_passSwitch);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c20_trialPass);
        _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c20_counter);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c20_closing_active);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c20_current_sensor);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c20_initCounter);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c20_openSideDelay);
        _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c20_leftMotor);
        _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c20_rightMotor);
        _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c20_bulbPin_BOOL);
        _SFD_SET_DATA_VALUE_PTR(0U, &chartInstance->c20_closeSideDelay);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c20_OPENING_ACTIVE);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c20_WRONG_PASSWORD);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c20_OPEN_SIDE_VALUE);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c20_CLOSE_SIDE_VALUE);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c20_PASSWORD_VERIFIED);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c20_CLOSE_CHAR);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c20_OPEN_CHAR);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c20_OPENING);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c20_CLOSED);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c20_CLOSING);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c20_OPEN);
        _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c20_passAssignedRAM_BOOL);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c20_gotoReady);
        _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c20_passSuccess);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c20_NO_PASS_ASSIG);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c20_PASS_ASSIGNED);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c20_PASS_INCOMPLETE);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c20_PASS_TIMEOUT);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c20_passTimer);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c20_TIMEOUT);
        _SFD_SET_DATA_VALUE_PTR(41U, *chartInstance->c20_passwordRAM_UINT8_6D);
        _SFD_SET_DATA_VALUE_PTR(32U, *chartInstance->c20_passwordIn);
        _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c20_passAssignedIn);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c20_stableTimer);
        _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c20_gateState);
        _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c20_INIT);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c20_closingTimer);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c20_openingTimer);
        _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c20_MOVING_TIMER);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s5h2guPLCaNOlxIYjvWa3ZB";
}

static void sf_opaque_initialize_c20_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_gate_V32_2016a_Sim
    ((SFc20_gate_V32_2016a_SimInstanceStruct*) chartInstanceVar);
  initialize_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  enable_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  disable_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  sf_gateway_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c20_gate_V32_2016a_Sim(SimStruct*
  S)
{
  return get_sim_state_c20_gate_V32_2016a_Sim
    ((SFc20_gate_V32_2016a_SimInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c20_gate_V32_2016a_Sim(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c20_gate_V32_2016a_Sim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_gate_V32_2016a_SimInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_gate_V32_2016a_Sim_optimization_info();
    }

    finalize_c20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
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
  initSimStructsc20_gate_V32_2016a_Sim((SFc20_gate_V32_2016a_SimInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_gate_V32_2016a_Sim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_gate_V32_2016a_Sim
      ((SFc20_gate_V32_2016a_SimInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c20_gate_V32_2016a_Sim(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_gate_V32_2016a_Sim_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 20);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 17, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 18, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 19, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 20, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 21, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 22, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 23, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,24);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,7);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=7; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 24; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2865101701U));
  ssSetChecksum1(S,(266216146U));
  ssSetChecksum2(S,(787756595U));
  ssSetChecksum3(S,(2574497799U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_gate_V32_2016a_Sim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c20_gate_V32_2016a_Sim(SimStruct *S)
{
  SFc20_gate_V32_2016a_SimInstanceStruct *chartInstance;
  chartInstance = (SFc20_gate_V32_2016a_SimInstanceStruct *)utMalloc(sizeof
    (SFc20_gate_V32_2016a_SimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc20_gate_V32_2016a_SimInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_gate_V32_2016a_Sim;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_gate_V32_2016a_Sim;
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
  mdl_start_c20_gate_V32_2016a_Sim(chartInstance);
}

void c20_gate_V32_2016a_Sim_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_gate_V32_2016a_Sim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_gate_V32_2016a_Sim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_gate_V32_2016a_Sim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_gate_V32_2016a_Sim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
