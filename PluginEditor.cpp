/*
 ==============================================================================
 
 This file contains the basic framework code for a JUCE plugin editor.
 
 ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Waylomod2020AudioProcessorEditor::Waylomod2020AudioProcessorEditor (Waylomod2020AudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800,800);
    auto& params = processor.getParameters();
    
    
    juce::AudioParameterFloat* delayTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
    mDelayTimeSlider.setBounds(100, 0 , 200, 200);
    mDelayTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTimeSlider.setRange(delayTimeParameter->range.start, delayTimeParameter->range.end);
    mDelayTimeSlider.setValue(*delayTimeParameter);
    addAndMakeVisible(mDelayTimeSlider);
    mDelayTimeSlider.onValueChange = [this, delayTimeParameter] { *delayTimeParameter = mDelayTimeSlider.getValue(); };
    mDelayTimeSlider.onDragStart = [delayTimeParameter] {delayTimeParameter->beginChangeGesture(); };
    mDelayTimeSlider.onDragEnd = [delayTimeParameter] {delayTimeParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* dryGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(1);
    mDryGainSlider.setBounds(100, 100, 200, 200);
    mDryGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDryGainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDryGainSlider.setRange(dryGainParameter->range.start, dryGainParameter->range.end);
    mDryGainSlider.setValue(*dryGainParameter);
    addAndMakeVisible(mDryGainSlider);
    mDryGainSlider.onValueChange = [this, dryGainParameter] { *dryGainParameter = mDryGainSlider.getValue(); };
    mDryGainSlider.onDragStart = [dryGainParameter] {dryGainParameter->beginChangeGesture(); };
    mDryGainSlider.onDragEnd = [dryGainParameter] {dryGainParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayOneGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(2);
    mDelayOneGainSlider.setBounds(100, 200 , 200, 200);
    mDelayOneGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayOneGainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayOneGainSlider.setRange(delayOneGainParameter->range.start, delayOneGainParameter->range.end);
    mDelayOneGainSlider.setValue(*delayOneGainParameter);
    addAndMakeVisible(mDelayOneGainSlider);
    mDelayOneGainSlider.onValueChange = [this, delayOneGainParameter] { *delayOneGainParameter = mDelayOneGainSlider.getValue(); };
    mDelayOneGainSlider.onDragStart = [delayOneGainParameter] {delayOneGainParameter->beginChangeGesture(); };
    mDelayOneGainSlider.onDragEnd = [delayOneGainParameter] {delayOneGainParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayOneModDpethParameter = (juce::AudioParameterFloat*)params.getUnchecked(3);
    mDelayOneModDepthSlider.setBounds(100, 300 , 200, 200);
    mDelayOneModDepthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayOneModDepthSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayOneGainSlider.setRange(delayOneModDpethParameter->range.start, delayOneModDpethParameter->range.end);
    mDelayOneModDepthSlider.setValue(*delayOneGainParameter);
    addAndMakeVisible(mDelayOneModDepthSlider);
    mDelayOneModDepthSlider.onValueChange = [this, delayOneModDpethParameter] { *delayOneModDpethParameter = mDelayOneModDepthSlider.getValue(); };
    mDelayOneModDepthSlider.onDragStart = [delayOneModDpethParameter] {delayOneModDpethParameter->beginChangeGesture(); };
    mDelayOneModDepthSlider.onDragEnd = [delayOneModDpethParameter] {delayOneModDpethParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayOneModRateParameter = (juce::AudioParameterFloat*)params.getUnchecked(4);
    mDelayOneModRateSlider.setBounds(100, 400 , 200, 200);
    mDelayOneModRateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayOneModRateSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayOneModRateSlider.setRange(delayOneModRateParameter->range.start, delayOneModRateParameter->range.end);
    mDelayOneModRateSlider.setValue(*delayOneGainParameter);
    addAndMakeVisible(mDelayOneModRateSlider);
    mDelayOneModRateSlider.onValueChange = [this, delayOneModRateParameter] { *delayOneModRateParameter = mDelayOneModRateSlider.getValue(); };
    mDelayOneModRateSlider.onDragStart = [delayOneModRateParameter] {delayOneModRateParameter->beginChangeGesture(); };
    mDelayOneModRateSlider.onDragEnd = [delayOneModRateParameter] {delayOneModRateParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayOneFeedbackParameter = (juce::AudioParameterFloat*)params.getUnchecked(5);
    mDelayOneFeedbackSlider.setBounds(100, 500 , 200, 200);
    mDelayOneFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayOneFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayOneFeedbackSlider.setRange(delayOneFeedbackParameter->range.start, delayOneFeedbackParameter->range.end);
    mDelayOneFeedbackSlider.setValue(*delayOneFeedbackParameter);
    addAndMakeVisible(mDelayOneFeedbackSlider);
    mDelayOneFeedbackSlider.onValueChange = [this, delayOneFeedbackParameter] { *delayOneFeedbackParameter = mDelayOneFeedbackSlider.getValue(); };
    mDelayOneFeedbackSlider.onDragStart = [delayOneFeedbackParameter] {delayOneFeedbackParameter->beginChangeGesture(); };
    mDelayOneFeedbackSlider.onDragEnd = [delayOneFeedbackParameter] {delayOneFeedbackParameter->endChangeGesture(); };
    
    
}

Waylomod2020AudioProcessorEditor::~Waylomod2020AudioProcessorEditor()
{
}

//==============================================================================
void Waylomod2020AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Waylomod2020AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
