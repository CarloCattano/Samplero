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

#ifndef _HEAVY_LV2_DPF_MYSAMPLERO_
#define _HEAVY_LV2_DPF_MYSAMPLERO_

#include "DistrhoPlugin.hpp"
#include "Heavy_dpf_mySamplero.hpp"

START_NAMESPACE_DISTRHO

class HeavyDPF_dpf_mySamplero : public Plugin
{
public:
  enum Parameters
  {
    
      paramfreq,
    
      paramgain,
    
      paramrec1_toggle,
    
      paramrec2_toggle,
    
      paramrec3_toggle,
    
      paramrec4_toggle,
    
      paramtrigger1_momentary,
    
      paramtrigger2_momentary,
    
      paramtrigger3_momentary,
    
      paramtrigger4_momentary,
    
  };

  HeavyDPF_dpf_mySamplero();
  ~HeavyDPF_dpf_mySamplero() override;

protected:
  // -------------------------------------------------------------------
  // Information

  const char* getLabel() const noexcept override
  {
    return "dpf_mySamplero";
  }


  const char* getDescription() const override
  {
    return "PUREDATA Sampler test patch";
  }


  const char* getMaker() const noexcept override
  {

    return "Carlo";

  }


  const char* getHomePage() const override
  {
    return "https://charly.audio/plugin/dpf_mySamplero";
  }


  const char* getLicense() const noexcept override
  {

    return "WTFPL";

  }

  uint32_t getVersion() const noexcept override
  {

    return d_version(6, 6, 6);

  }

  int64_t getUniqueId() const noexcept override
  {
    return int64_t( 0xAB2EFA60 );
  }

  // -------------------------------------------------------------------
  // Init

  void initParameter(uint32_t index, Parameter& parameter) override;

  // -------------------------------------------------------------------
  // Internal data

  float getParameterValue(uint32_t index) const override;
  void  setParameterValue(uint32_t index, float value) override;

  // -------------------------------------------------------------------
  // Process

  // void activate() override;
  // void deactivate() override;
  void run(const float** inputs, float** outputs, uint32_t frames, const MidiEvent* midiEvents, uint32_t midiEventCount) override;

  // -------------------------------------------------------------------
  // Callbacks

  void sampleRateChanged(double newSampleRate) override;

  // -------------------------------------------------------------------

private:
  
  // parameters
  float _parameters[10]; // in range of [0,1]
  

  // heavy context
  HeavyContextInterface *_context;

  // HeavyDPF_dpf_mySamplero<float> fdpf_mySamplero;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HeavyDPF_dpf_mySamplero)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // _HEAVY_LV2_DPF_MYSAMPLERO_
