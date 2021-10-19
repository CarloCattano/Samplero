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

#include "HeavyDPF_dpf_mySamplero.hpp"


#define HV_LV2_NUM_PARAMETERS 10

START_NAMESPACE_DISTRHO


HeavyDPF_dpf_mySamplero::HeavyDPF_dpf_mySamplero()
 : Plugin(HV_LV2_NUM_PARAMETERS, 0, 0)
{
    
    _parameters[0] = 500.0f;
    
    _parameters[1] = 0.7f;
    
    _parameters[2] = 0.0f;
    
    _parameters[3] = 0.0f;
    
    _parameters[4] = 0.0f;
    
    _parameters[5] = 0.0f;
    
    _parameters[6] = 0.0f;
    
    _parameters[7] = 0.0f;
    
    _parameters[8] = 0.0f;
    
    _parameters[9] = 0.0f;
    

    _context = new Heavy_dpf_mySamplero(getSampleRate(), 10, 10, 2);
    
    // ensure that the new context has the current parameters
    for (int i = 0; i < HV_LV2_NUM_PARAMETERS; ++i) {
      setParameterValue(i, _parameters[i]);
    }
    
}

HeavyDPF_dpf_mySamplero::~HeavyDPF_dpf_mySamplero() {
  delete _context;
}

void HeavyDPF_dpf_mySamplero::initParameter(uint32_t index, Parameter& parameter)
{
  
  // initialise parameters with defaults
  switch (index)
  {
    
      case paramfreq:
        parameter.name = "freq";
        parameter.symbol = "freq";
        parameter.hints = kParameterIsAutomable
      ;
        parameter.ranges.min = 100.0f;
        parameter.ranges.max = 2000.0f;
        parameter.ranges.def = 500.0f;
        break;
    
      case paramgain:
        parameter.name = "gain";
        parameter.symbol = "gain";
        parameter.hints = kParameterIsAutomable
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.7f;
        break;
    
      case paramrec1_toggle:
        parameter.name = "rec1 toggle";
        parameter.symbol = "rec1_toggle";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsBoolean
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramrec2_toggle:
        parameter.name = "rec2 toggle";
        parameter.symbol = "rec2_toggle";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsBoolean
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramrec3_toggle:
        parameter.name = "rec3 toggle";
        parameter.symbol = "rec3_toggle";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsBoolean
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramrec4_toggle:
        parameter.name = "rec4 toggle";
        parameter.symbol = "rec4_toggle";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsBoolean
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramtrigger1_momentary:
        parameter.name = "trigger1 momentary";
        parameter.symbol = "trigger1_momentary";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsTrigger
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramtrigger2_momentary:
        parameter.name = "trigger2 momentary";
        parameter.symbol = "trigger2_momentary";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsTrigger
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramtrigger3_momentary:
        parameter.name = "trigger3 momentary";
        parameter.symbol = "trigger3_momentary";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsTrigger
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
      case paramtrigger4_momentary:
        parameter.name = "trigger4 momentary";
        parameter.symbol = "trigger4_momentary";
        parameter.hints = kParameterIsAutomable
      
        | kParameterIsTrigger
      ;
        parameter.ranges.min = 0.0f;
        parameter.ranges.max = 1.0f;
        parameter.ranges.def = 0.0f;
        break;
    
  }
  
}

// -------------------------------------------------------------------
// Internal data

float HeavyDPF_dpf_mySamplero::getParameterValue(uint32_t index) const
{
  
  return _parameters[index];
  
}

void HeavyDPF_dpf_mySamplero::setParameterValue(uint32_t index, float value)
{
  
  switch (index) {
    
    case 0: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::FREQ,
          value);
      break;
    }
    
    case 1: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::GAIN,
          value);
      break;
    }
    
    case 2: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::REC1_TOGGLE,
          value);
      break;
    }
    
    case 3: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::REC2_TOGGLE,
          value);
      break;
    }
    
    case 4: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::REC3_TOGGLE,
          value);
      break;
    }
    
    case 5: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::REC4_TOGGLE,
          value);
      break;
    }
    
    case 6: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::TRIGGER1_MOMENTARY,
          value);
      break;
    }
    
    case 7: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::TRIGGER2_MOMENTARY,
          value);
      break;
    }
    
    case 8: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::TRIGGER3_MOMENTARY,
          value);
      break;
    }
    
    case 9: {
      _context->sendFloatToReceiver(
          Heavy_dpf_mySamplero::Parameter::In::TRIGGER4_MOMENTARY,
          value);
      break;
    }
    
    default: return;
  }
  _parameters[index] = value;
  
}


// -------------------------------------------------------------------
// Process

// void HeavyDPF_dpf_mySamplero::activate()
// {

// }

// void HeavyDPF_dpf_mySamplero::deactivate()
// {

// }

void HeavyDPF_dpf_mySamplero::run(const float** inputs, float** outputs, uint32_t frames, const MidiEvent* midiEvents, uint32_t midiEventCount)
{
  uint32_t framesDone = 0;
  uint32_t curEventIndex = 0;

  _context->process((float**)inputs, outputs, frames);

  while (framesDone < frames)
  {
    while (curEventIndex < midiEventCount && framesDone == midiEvents[curEventIndex].frame)
    {
      if (midiEvents[curEventIndex].size > MidiEvent::kDataSize)
          continue;

      int status = midiEvents[curEventIndex].data[0];
      int command = status & 0xF0;
      int channel = status & 0x0F;
      int data1   = midiEvents[curEventIndex].data[1];
      int data2   = midiEvents[curEventIndex].data[2];

      switch (command) {
        case 0x80:   // note off
        case 0x90: { // note on
          _context->sendMessageToReceiverV(0x67E37CA3, // __hv_notein
              1000.0*frames/getSampleRate(), "fff",
              (float) data1, // pitch
              (float) data2, // velocity
              (float) channel);
          break;
        }
        case 0xB0: { // control change
          _context->sendMessageToReceiverV(0x41BE0F9C, // __hv_ctlin
              1000.0*frames/getSampleRate(), "fff",
              (float) data2, // value
              (float) data1, // controller number
              (float) channel);
          break;
        }
        case 0xC0: { // program change
          _context->sendMessageToReceiverV(0x2E1EA03D, // __hv_pgmin,
              1000.0*frames/getSampleRate(), "ff",
              (float) data1,
              (float) channel);
          break;
        }
        case 0xD0: { // aftertouch
          _context->sendMessageToReceiverV(0x553925BD, // __hv_touchin
              1000.0*frames/getSampleRate(), "ff",
              (float) data1,
              (float) channel);
          break;
        }
        case 0xE0: { // pitch bend
          hv_uint32_t value = (((hv_uint32_t) data2) << 7) | ((hv_uint32_t) data1);
          _context->sendMessageToReceiverV(0x3083F0F7, // __hv_bendin
              1000.0*frames/getSampleRate(), "ff",
              (float) value,
              (float) channel);
          break;
        }
        default: break;
      }
      curEventIndex++;
    }
    framesDone++;
  }
}

// -------------------------------------------------------------------
// Callbacks

void HeavyDPF_dpf_mySamplero::sampleRateChanged(double newSampleRate)
{
  delete _context;
  _context = new Heavy_dpf_mySamplero(newSampleRate, 10, 10, 2);

  
  // ensure that the new context has the current parameters
  for (int i = 0; i < HV_LV2_NUM_PARAMETERS; ++i) {
    setParameterValue(i, _parameters[i]);
  }
  
}

// -----------------------------------------------------------------------
/* Plugin entry point, called by DPF to create a new plugin instance. */

Plugin* createPlugin()
{
    return new HeavyDPF_dpf_mySamplero();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO