/*
 ==============================================================================
 
 This file contains the basic framework code for a JUCE plugin processor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Waylomod2020AudioProcessor::Waylomod2020AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
: AudioProcessor (BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
                  .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
#endif
                  .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
#endif
                  )
#endif
{
    addParameter(mDelayOneTimeParameter = new juce::AudioParameterFloat("delay one delaytime", "Delay One Delay Time", 0.0001, MAX_DELAY_TIME, 0.5));
    addParameter(mDryGainParameter = new juce::AudioParameterFloat("drygain", "Dry Gain", 0.0, 1.0 , 0.5));
    addParameter(mDelayOneGainParameter = new juce::AudioParameterFloat("delayonegain", "Delay One Gain", 0.0, 1.0 , 0.5));
    addParameter(mDelayOneModDepthParameter = new juce::AudioParameterFloat("delayonemodDepth", "Delay One Mod Depth", 0, 1, 0.5));
    addParameter(mDelayOneModRateParameter = new juce::AudioParameterFloat("delayonemodRate", "Delay One Mod Rate", 0, 1, 0.5));
    addParameter(mDelayOneFeedbackParameter = new juce::AudioParameterFloat("feedbackone", "Feedback One", 0.0, 0.98, 0.5));
    
    addParameter(mDelayTwoTimeParameter = new juce::AudioParameterFloat("delay two delaytime", "Delay Two Delay Time", 0.0001, MAX_DELAY_TIME, 0.5));
    addParameter(mDelayTwoGainParameter = new juce::AudioParameterFloat("delaytowgain", "Delay Two Gain", 0.0, 1.0, 0.5));
    addParameter(mDelayTwoModDepthParameter = new juce::AudioParameterFloat("delaytwomodDepth", "Delay Two Mod Depth", 0, 1, 0.5));
    addParameter(mDelayTwoModRateParameter = new juce::AudioParameterFloat("delaytwomodDepth", "Delay Two Mod Depth", 0, 1, 0.5));
    addParameter(mDelayTwoFeedbackParameter = new juce::AudioParameterFloat("feedbacktwo", "Feedback Two", 0.0, 0.98, 0.5));
    

    mCircularBufferLeft = nullptr;
    mCircularBufferRight = nullptr;
    mCircularBufferWriteHead = 0;
    mCircularBufferLength = 0;
    mDelayTimeInSamples = 0.0;
    mDelayReadHead = 0.0;


    feedback = 0.5;
    mfeedbackLeft = 0.0;
    mDelayTimeSmoothed = 1;
    mLFOphase = 0;
    mLFOrate = 0.3f;

    
}

Waylomod2020AudioProcessor::~Waylomod2020AudioProcessor()
{
    if (mCircularBufferLeft != nullptr ) {
        delete [] mCircularBufferLeft;
        mCircularBufferLeft = nullptr;
    }
    
    
    
    if (mCircularBufferRight != nullptr ) {
        delete [] mCircularBufferRight;
        mCircularBufferRight = nullptr;
    }
    
}

//==============================================================================
const juce::String Waylomod2020AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Waylomod2020AudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool Waylomod2020AudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool Waylomod2020AudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double Waylomod2020AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Waylomod2020AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int Waylomod2020AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Waylomod2020AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Waylomod2020AudioProcessor::getProgramName (int index)
{
    return {};
}

void Waylomod2020AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

float Waylomod2020AudioProcessor::linInterp(float sample_x, float sample_x1, float inPhase)
{
    return (1 - inPhase) * sample_x + inPhase * sample_x1;
    
}

//==============================================================================
void Waylomod2020AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mLFOphase = 0;
    mLFOrate = 0.3f;
    //mLFOdepth = 0.5f;
    
    
    
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mCircularBufferLength = sampleRate*MAX_DELAY_TIME;

    
    
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    if (mCircularBufferLeft != nullptr ) {
        delete [] mCircularBufferLeft;
        mCircularBufferLeft = nullptr;
    }
    
    if (mCircularBufferLeft == nullptr ) {
        mCircularBufferLeft = new float[mCircularBufferLength];
    }
    
    if (mCircularBufferRight != nullptr ) {
        delete [] mCircularBufferRight;
        mCircularBufferRight = nullptr;
    }
    
    if (mCircularBufferRight == nullptr ) {
        mCircularBufferRight = new float[mCircularBufferLength];
    }
    
    mCircularBufferWriteHead = 0;
    //mDelayTimeSmoothed = *mDelayOneTimeParameter;
    mDelayTimeSmoothed = 0.5;
    
    //dryGain = *mDryGainParameter;
    
    
}

void Waylomod2020AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Waylomod2020AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    
    // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif
    
    return true;
#endif
}
#endif

void Waylomod2020AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    
    // grab pointer to the input buffer for left and right channel
    
    float* LeftChannel = buffer.getWritePointer(0);
    float* RightChannel = buffer.getWritePointer(1);
    
    
    
    for (int i = 0; i < buffer.getNumSamples(); ++i)
    {
        
        // generate the next LFO value
        
        float lfoOut = sin(2*M_PI * mLFOphase);
        
        // move the LFO phase thru the sine wave

        mLFOphase += *mDelayOneModRateParameter / getSampleRate();
        
        // LFO phase is moving between zero and one
        if ( mLFOphase > 1){
            mLFOphase -= 1;
        }
        // attenuate the "depth" of the modulaton
        lfoOut *= *mDelayOneModDepthParameter;
        
        // convert -1 to 1 to changes in delay time of .005 min and .03 max
        float lfoOutMapped = juce::jmap(lfoOut,-1.f,1.f,0.005f, 0.03f);
        
        
        // smoothly change the dely time
        mDelayTimeSmoothed = mDelayTimeSmoothed - 0.001*(mDelayTimeSmoothed - lfoOutMapped);
        // get the value of the delay time knob as an in in samples
        int dtime = static_cast<int>(*mDelayOneTimeParameter*getSampleRate());
        // add the modulated delay time to the value the delay time is set to with the slider
        mDelayTimeInSamples = dtime + getSampleRate() * mDelayTimeSmoothed ;
        
        // shove some of the input into the circular buffer also add some of the feedback
        mCircularBufferLeft[mCircularBufferWriteHead] = LeftChannel[i];
        mCircularBufferRight[mCircularBufferWriteHead] = RightChannel[i] + mfeedbackRight;
        


        // move the read head on the circular to the new delay position
        mDelayReadHead = mCircularBufferWriteHead - mDelayTimeInSamples;
        
        // if read head is below zero wrap around
        if (mDelayReadHead < 0){
            mDelayReadHead += mCircularBufferLength;
        }
        
        // get the integer part of the read head
        int readHeadX = (int)mDelayReadHead;
        // get the part of the readHead after the decimal point
        float readHeadFloat = mDelayReadHead - readHeadX;
        // next integer sample position
        int readHeadX1 = readHeadX + 1;
        
        // if next sample position is outside the buffer
        if ( readHeadX1 >= mCircularBufferLength){
            readHeadX1 -= mCircularBufferLength;
        }
        
        // get the interpolated value of the delayed sample from the circular buffer
        float delay_sample_Left = Waylomod2020AudioProcessor::linInterp(mCircularBufferLeft[readHeadX], mCircularBufferLeft[readHeadX1], readHeadFloat);
        float delay_sample_Right = Waylomod2020AudioProcessor::linInterp(mCircularBufferRight[readHeadX], mCircularBufferRight[readHeadX1], readHeadFloat);
        
        // store some delay for feedback
        mfeedbackRight = delay_sample_Right* *mDelayOneFeedbackParameter;
        
        // add delay into live audio buffer
        
        buffer.setSample(0, i, buffer.getSample(0, i)* *mDryGainParameter);
        buffer.setSample(1, i, buffer.getSample(1, i)* *mDryGainParameter + delay_sample_Right* *mDelayOneGainParameter);
 
        // increment the buffer write head
        mCircularBufferWriteHead ++;
        
        // wrap around if needed
        if (mCircularBufferWriteHead == mCircularBufferLength){
            mCircularBufferWriteHead = 0;
        }
    }
}



//==============================================================================
bool Waylomod2020AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Waylomod2020AudioProcessor::createEditor()
{
    return new Waylomod2020AudioProcessorEditor (*this);
}

//==============================================================================
void Waylomod2020AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Waylomod2020AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Waylomod2020AudioProcessor();
}
