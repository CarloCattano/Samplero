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

#ifndef _HEAVY_DPF_MYSAMPLERO_H_
#define _HEAVY_DPF_MYSAMPLERO_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_DPF_MYSAMPLERO_PARAM_IN_FREQ = 0x345FC008, // freq
  HV_DPF_MYSAMPLERO_PARAM_IN_GAIN = 0x811CC33F, // gain
  HV_DPF_MYSAMPLERO_PARAM_IN_REC1_TOGGLE = 0x33D6AA29, // rec1_toggle
  HV_DPF_MYSAMPLERO_PARAM_IN_REC2_TOGGLE = 0xB5CF0F0E, // rec2_toggle
  HV_DPF_MYSAMPLERO_PARAM_IN_REC3_TOGGLE = 0xF3D1604, // rec3_toggle
  HV_DPF_MYSAMPLERO_PARAM_IN_REC4_TOGGLE = 0x530C3460, // rec4_toggle
  HV_DPF_MYSAMPLERO_PARAM_IN_TRIGGER1_MOMENTARY = 0x70674774, // trigger1_momentary
  HV_DPF_MYSAMPLERO_PARAM_IN_TRIGGER2_MOMENTARY = 0xFD200675, // trigger2_momentary
  HV_DPF_MYSAMPLERO_PARAM_IN_TRIGGER3_MOMENTARY = 0xFA018A74, // trigger3_momentary
  HV_DPF_MYSAMPLERO_PARAM_IN_TRIGGER4_MOMENTARY = 0x7980BCEC, // trigger4_momentary
} Hv_dpf_mySamplero_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_dpf_mySamplero_new(double sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_dpf_mySamplero_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_DPF_MYSAMPLERO_H_
