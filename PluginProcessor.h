/*
 ==============================================================================
 
 This file contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#pragma once

#include <JuceHeader.h>
#define MAX_DELAY_TIME 2

//==============================================================================
/**
 */
class Waylomod2020AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    Waylomod2020AudioProcessor();
    ~Waylomod2020AudioProcessor() override;
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
#endif
    
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    
    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    
    //==============================================================================
    const juce::String getName() const override;
    
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    
    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float linInterp(float sample_x, float sample_x1, float inPhase);
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Waylomod2020AudioProcessor)
    
    float mDelayTimeInSamples;
    float mDelayReadHead;
    //float dryGain;
    //float delayLevel;
    float feedback;
    //float delayTime;
    float mLFOphase;
    float mLFOrate;
    float mLFOdepth;
   juce::AudioParameterFloat* mDelayTimeParameter;
   juce::AudioParameterFloat* mDryGainParameter;
   juce::AudioParameterFloat* mDelayOneGainParameter;
   
    //juce::AudioParameterFloat* mModDepthParameter;
   // juce::AudioParameterFloat* mModRateParameter;
    
    float mLastInputGain  = 0.0f;
    float mDelayTimeSmoothed; 
    
    float* mCircularBufferRight;
    float* mCircularBufferLeft;
    
    int mCircularBufferWriteHead;
    
    int mCircularBufferLength;
    
    float mfeedbackLeft;
    float mfeedbackRight;
    
};
