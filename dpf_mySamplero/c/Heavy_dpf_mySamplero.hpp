/**
 * Copyright (c) 2021 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_DPF_MYSAMPLERO_HPP_
#define _HEAVY_CONTEXT_DPF_MYSAMPLERO_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvMath.h"
#include "HvControlSlice.h"
#include "HvControlDelay.h"
#include "HvSignalLine.h"
#include "HvControlPack.h"
#include "HvControlSystem.h"
#include "HvControlBinop.h"
#include "HvControlCast.h"
#include "HvControlVar.h"
#include "HvSignalTabwrite.h"
#include "HvSignalTabread.h"

class Heavy_dpf_mySamplero : public HeavyContext {

 public:
  Heavy_dpf_mySamplero(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_dpf_mySamplero();

  const char *getName() override { return "dpf_mySamplero"; }
  int getNumInputChannels() override { return 2; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        FREQ = 0x345FC008, // freq
        GAIN = 0x811CC33F, // gain
        REC1_TOGGLE = 0x33D6AA29, // rec1_toggle
        REC2_TOGGLE = 0xB5CF0F0E, // rec2_toggle
        REC3_TOGGLE = 0xF3D1604, // rec3_toggle
        REC4_TOGGLE = 0x530C3460, // rec4_toggle
        TRIGGER1_MOMENTARY = 0x70674774, // trigger1_momentary
        TRIGGER2_MOMENTARY = 0xFD200675, // trigger2_momentary
        TRIGGER3_MOMENTARY = 0xFA018A74, // trigger3_momentary
        TRIGGER4_MOMENTARY = 0x7980BCEC, // trigger4_momentary
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cSwitchcase_j66ANK1N_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_ky4TAS31_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Px1u29Y2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XHizWjns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0ZYggQYq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1zdu4wQp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GF5QN9rh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_zpssyOA9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_R0k0pSC7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eFGf2KQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BGvoCImn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_keZ13qQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_puTU60sI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_8kB4EAsk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WbztnlbA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_baep4P0u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_q03z6Cjy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_odWzxl6H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_H8LGGIsq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rfztlgok_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7YNIcdb7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eoHhLTZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hxPv4h3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_j6a4dGip_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Hl4R2v6x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0pACdymS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HIqZb2vi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_BUV9CEYk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zcrITdsi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_khsKrMjT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_gNHBEscv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_UxkiqCGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z73B0n3F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0YsQSKmJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9uKjmAdK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qfoIeCKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GQEnBozI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QjgVqioY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_zFx4QRas_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8BGkIpL8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mqaQE3F5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cyDbkJKJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P0DznO7W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_044q4xjv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_g7RfJS7F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_SQBAmMRm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gGQsoUMa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MMJcPu0q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D9tkUM0G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_d2DobD1D_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_SPrypYZK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BNTF6tDa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GrGfVIAu_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_z6c2OWEK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mgGVQDvQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CqDRMauj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_g33Mr9Ps_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_W57N1Gvq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mBInjndi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TjQ1irLz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9miDGI8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fsiyK0ev_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MmMTDar2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YsDOM7zf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_74n32LzO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6dVbMyQ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r6pG00YS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mWzRfIGr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZRE4ydoX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Owli4whr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yIo0y4LM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eYx0O0cz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vyDuxrJg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qm0VtRYD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UxDqlvPL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_VKe4VvUx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_G5CikRfl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BOCpXvoh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_AahpbyKz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_LCjkqmyR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0T0k81hy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AoHIkjYr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iL0cPeZi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_tYDEb62g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xQ6uKreq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BeXS9Mwo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oq5SoWdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qMhrgxTF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w0r7JrTQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4QOZfVzE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Zcc8yS6v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PiHpJIZk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9MIH7e3h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eZMwVKLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Mf8guly5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZFuO6t3D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8C0zYbtX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ddCsU5BM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_C2YYmS6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3oCW9gi9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dBB934Te_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_0m7f1otp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_T3m9bhnE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MiwqlwPh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5aNpsV0B_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_ByKHnlry_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2eWqoC7K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kBUsAWeu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5ZtFMGvK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_ALvbayIa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SsSZ0MVu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rJqXTuOe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Wa9EKzUr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SLQG7kXh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3c0L2KZx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2KEZh6Xp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_p0fnihXU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AJiQ8WyK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xo6gwzC1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rhE7WNQK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fCo44adU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qVdUctYG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aTH07eG0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CSKj8hap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_REhg8eKo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_62GhIfIQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rU0pO0wS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_uZvVOptI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_02DdSQDq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PqKBGiAj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QOtcwQwd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jRIoQHcs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Lu4lu6NZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_MJUl8sNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_oQRU9laO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_cGpVnbZJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_UYuMGMUt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_6CQCGFSK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_gFQdGa6A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_NR4EHkQT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aRu7mELL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lVeqKF9R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fxwpbsFY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_CJYkCaGB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7eCnqAwY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_AA0ihQXx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TJExZDqM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_1foPAEx1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kRB8p61s_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_IsQ06vKi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4XfhVeL4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_D7v3tyKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YvcKtr0J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FL6asQcl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gT9at0TD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nUukadkl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_U0K87U5r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sE1pYUG4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1dk738vo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jWEDPcFd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GvEBU2gF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_l3estB5O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GYh6vrKb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_A2cytthK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cUyMqrk6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_oxKMzTbw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nxZ8p7s9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nb7ymfSH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_tbrUa6Mr_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_pBwO8Btk;
  SignalTabwrite sTabwrite_tR42lPIv;
  SignalTabwrite sTabwrite_XKnsYU99;
  SignalTabwrite sTabwrite_cdyt4VbA;
  SignalLine sLine_KuxloZJc;
  SignalTabread sTabread_pWkXz109;
  SignalLine sLine_BzpQpMKo;
  SignalTabread sTabread_xCNietCy;
  SignalLine sLine_JaLzrnQr;
  SignalTabread sTabread_HZkKKA70;
  SignalLine sLine_3zuxJdjp;
  SignalTabread sTabread_4KQZ4FRv;
  ControlVar cVar_ky4TAS31;
  ControlSlice cSlice_0ZYggQYq;
  ControlBinop cBinop_1zdu4wQp;
  SignalVarf sVarf_vu0wRpW0;
  ControlVar cVar_zpssyOA9;
  ControlSlice cSlice_BGvoCImn;
  ControlBinop cBinop_keZ13qQX;
  SignalVarf sVarf_le7NxzhH;
  ControlVar cVar_8kB4EAsk;
  ControlSlice cSlice_q03z6Cjy;
  ControlBinop cBinop_odWzxl6H;
  SignalVarf sVarf_AgW4bYec;
  ControlVar cVar_eoHhLTZH;
  ControlBinop cBinop_hxPv4h3T;
  ControlDelay cDelay_BUV9CEYk;
  ControlDelay cDelay_UxkiqCGV;
  ControlVar cVar_Z73B0n3F;
  ControlSlice cSlice_0YsQSKmJ;
  ControlSlice cSlice_9uKjmAdK;
  ControlBinop cBinop_qfoIeCKt;
  ControlBinop cBinop_GQEnBozI;
  ControlBinop cBinop_mqaQE3F5;
  ControlBinop cBinop_cyDbkJKJ;
  ControlVar cVar_MMJcPu0q;
  ControlBinop cBinop_D9tkUM0G;
  ControlDelay cDelay_z6c2OWEK;
  ControlDelay cDelay_W57N1Gvq;
  ControlVar cVar_mBInjndi;
  ControlSlice cSlice_TjQ1irLz;
  ControlSlice cSlice_9miDGI8H;
  ControlBinop cBinop_fsiyK0ev;
  ControlBinop cBinop_MmMTDar2;
  ControlBinop cBinop_r6pG00YS;
  ControlBinop cBinop_mWzRfIGr;
  ControlVar cVar_Qm0VtRYD;
  ControlBinop cBinop_UxDqlvPL;
  ControlDelay cDelay_LCjkqmyR;
  ControlDelay cDelay_tYDEb62g;
  ControlVar cVar_xQ6uKreq;
  ControlSlice cSlice_BeXS9Mwo;
  ControlSlice cSlice_oq5SoWdG;
  ControlBinop cBinop_qMhrgxTF;
  ControlBinop cBinop_w0r7JrTQ;
  ControlBinop cBinop_9MIH7e3h;
  ControlBinop cBinop_eZMwVKLt;
  ControlVar cVar_3oCW9gi9;
  ControlBinop cBinop_dBB934Te;
  ControlDelay cDelay_ByKHnlry;
  ControlDelay cDelay_ALvbayIa;
  ControlVar cVar_SsSZ0MVu;
  ControlSlice cSlice_rJqXTuOe;
  ControlSlice cSlice_Wa9EKzUr;
  ControlBinop cBinop_SLQG7kXh;
  ControlBinop cBinop_3c0L2KZx;
  ControlBinop cBinop_xo6gwzC1;
  ControlBinop cBinop_rhE7WNQK;
  ControlVar cVar_uZvVOptI;
  ControlSlice cSlice_QOtcwQwd;
  ControlBinop cBinop_jRIoQHcs;
  SignalVarf sVarf_Me7eUfgj;
  HvTable hTable_Lu4lu6NZ;
  HvTable hTable_MJUl8sNn;
  HvTable hTable_oQRU9laO;
  HvTable hTable_cGpVnbZJ;
  ControlPack cPack_UYuMGMUt;
  ControlPack cPack_6CQCGFSK;
  ControlPack cPack_gFQdGa6A;
  ControlPack cPack_NR4EHkQT;
  ControlVar cVar_aRu7mELL;
  ControlVar cVar_lVeqKF9R;
  SignalVarf sVarf_4RG7z1Ua;
};

#endif // _HEAVY_CONTEXT_DPF_MYSAMPLERO_HPP_
