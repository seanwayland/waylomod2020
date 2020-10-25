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
    setSize (1000,1000);
    auto& params = processor.getParameters();
    
    
    juce::AudioParameterFloat* delayTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
    mDelayTimeSlider.setBounds(100, 100 , 200, 200);
    mDelayTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTimeSlider.setRange(delayTimeParameter->range.start, delayTimeParameter->range.end);
    mDelayTimeSlider.setValue(*delayTimeParameter);
    addAndMakeVisible(mDelayTimeSlider);
    mDelayTimeSlider.onValueChange = [this, delayTimeParameter] { *delayTimeParameter = mDelayTimeSlider.getValue(); };
    mDelayTimeSlider.onDragStart = [delayTimeParameter] {delayTimeParameter->beginChangeGesture(); };
    mDelayTimeSlider.onDragEnd = [delayTimeParameter] {delayTimeParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* dryGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(1);
    mDryGainSlider.setBounds(400, 0, 200, 200);
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
    
    
  
    
    juce::AudioParameterFloat* delayTwoTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(6);
    mDelayTwoTimeSlider.setBounds(300, 100 , 200, 200);
    mDelayTwoTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTwoTimeSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTwoTimeSlider.setRange(delayTwoTimeParameter->range.start, delayTwoTimeParameter->range.end);
    mDelayTwoTimeSlider.setValue(*delayTwoTimeParameter);
    addAndMakeVisible(mDelayTwoTimeSlider);
    mDelayTwoTimeSlider.onValueChange = [this, delayTwoTimeParameter] { *delayTwoTimeParameter = mDelayTwoTimeSlider.getValue(); };
    mDelayTwoTimeSlider.onDragStart = [delayTwoTimeParameter] {delayTwoTimeParameter->beginChangeGesture(); };
    mDelayTwoTimeSlider.onDragEnd = [delayTwoTimeParameter] {delayTwoTimeParameter->endChangeGesture(); };
    

    
    juce::AudioParameterFloat* delayTwoGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(7);
    mDelayTwoGainSlider.setBounds(300, 200 , 200, 200);
    mDelayTwoGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTwoGainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTwoGainSlider.setRange(delayTwoGainParameter->range.start, delayTwoGainParameter->range.end);
    mDelayTwoGainSlider.setValue(*delayTwoGainParameter);
    addAndMakeVisible(mDelayTwoGainSlider);
    mDelayTwoGainSlider.onValueChange = [this, delayTwoGainParameter] { *delayTwoGainParameter = mDelayTwoGainSlider.getValue(); };
    mDelayTwoGainSlider.onDragStart = [delayTwoGainParameter] {delayTwoGainParameter->beginChangeGesture(); };
    mDelayTwoGainSlider.onDragEnd = [delayTwoGainParameter] {delayTwoGainParameter->endChangeGesture(); };
    

    
    juce::AudioParameterFloat* delayTwoModDpethParameter = (juce::AudioParameterFloat*)params.getUnchecked(8);
    mDelayTwoModDepthSlider.setBounds(300, 300 , 200, 200);
    mDelayTwoModDepthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTwoModDepthSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTwoModDepthSlider.setRange(delayTwoModDpethParameter->range.start, delayTwoModDpethParameter->range.end);
    mDelayTwoModDepthSlider.setValue(*delayTwoModDpethParameter);
    addAndMakeVisible(mDelayTwoModDepthSlider);
    mDelayTwoModDepthSlider.onValueChange = [this, delayTwoModDpethParameter] { *delayTwoModDpethParameter = mDelayTwoModDepthSlider.getValue(); };
    mDelayTwoModDepthSlider.onDragStart = [delayTwoModDpethParameter] {delayTwoModDpethParameter->beginChangeGesture(); };
    mDelayTwoModDepthSlider.onDragEnd = [delayTwoModDpethParameter] {delayTwoModDpethParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayTwoModRateParameter = (juce::AudioParameterFloat*)params.getUnchecked(9);
    mDelayTwoModRateSlider.setBounds(300, 400 , 200, 200);
    mDelayTwoModRateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTwoModRateSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTwoModRateSlider.setRange(delayTwoModRateParameter->range.start, delayTwoModRateParameter->range.end);
    mDelayTwoModRateSlider.setValue(*delayTwoModRateParameter);
    addAndMakeVisible(mDelayTwoModRateSlider);
    mDelayTwoModRateSlider.onValueChange = [this, delayTwoModRateParameter] { *delayTwoModRateParameter = mDelayTwoModRateSlider.getValue(); };
    mDelayTwoModRateSlider.onDragStart = [delayTwoModRateParameter] {delayTwoModRateParameter->beginChangeGesture(); };
    mDelayTwoModRateSlider.onDragEnd = [delayTwoModRateParameter] {delayTwoModRateParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayTwoFeedbackParameter = (juce::AudioParameterFloat*)params.getUnchecked(10);
    mDelayTwoFeedbackSlider.setBounds(300, 500 , 200, 200);
    mDelayTwoFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayTwoFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayTwoFeedbackSlider.setRange(delayTwoFeedbackParameter->range.start, delayTwoFeedbackParameter->range.end);
    mDelayTwoFeedbackSlider.setValue(*delayTwoFeedbackParameter);
    addAndMakeVisible(mDelayTwoFeedbackSlider);
    mDelayTwoFeedbackSlider.onValueChange = [this, delayTwoFeedbackParameter] { *delayTwoFeedbackParameter = mDelayTwoFeedbackSlider.getValue(); };
    mDelayTwoFeedbackSlider.onDragStart = [delayTwoFeedbackParameter] {delayTwoFeedbackParameter->beginChangeGesture(); };
    mDelayTwoFeedbackSlider.onDragEnd = [delayTwoFeedbackParameter] {delayTwoFeedbackParameter->endChangeGesture(); };
    
    
    
    juce::AudioParameterFloat* delayThreeTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(11);
    mDelayThreeTimeSlider.setBounds(500, 100 , 200, 200);
    mDelayThreeTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayThreeTimeSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayThreeTimeSlider.setRange(delayThreeTimeParameter->range.start, delayThreeTimeParameter->range.end);
    mDelayThreeTimeSlider.setValue(*delayThreeTimeParameter);
    addAndMakeVisible(mDelayThreeTimeSlider);
    mDelayThreeTimeSlider.onValueChange = [this, delayThreeTimeParameter] { *delayThreeTimeParameter = mDelayThreeTimeSlider.getValue(); };
    mDelayThreeTimeSlider.onDragStart = [delayThreeTimeParameter] {delayThreeTimeParameter->beginChangeGesture(); };
    mDelayThreeTimeSlider.onDragEnd = [delayThreeTimeParameter] {delayThreeTimeParameter->endChangeGesture(); };
    
    
    
    juce::AudioParameterFloat* delayThreeGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(12);
    mDelayThreeGainSlider.setBounds(500, 200 , 200, 200);
    mDelayThreeGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayThreeGainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayThreeGainSlider.setRange(delayThreeGainParameter->range.start, delayThreeGainParameter->range.end);
    mDelayThreeGainSlider.setValue(*delayThreeGainParameter);
    addAndMakeVisible(mDelayThreeGainSlider);
    mDelayThreeGainSlider.onValueChange = [this, delayThreeGainParameter] { *delayThreeGainParameter = mDelayThreeGainSlider.getValue(); };
    mDelayThreeGainSlider.onDragStart = [delayThreeGainParameter] {delayThreeGainParameter->beginChangeGesture(); };
    mDelayThreeGainSlider.onDragEnd = [delayThreeGainParameter] {delayThreeGainParameter->endChangeGesture(); };
    
    
    
    juce::AudioParameterFloat* delayThreeModDpethParameter = (juce::AudioParameterFloat*)params.getUnchecked(13);
    mDelayThreeModDepthSlider.setBounds(500, 300 , 200, 200);
    mDelayThreeModDepthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayThreeModDepthSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayThreeModDepthSlider.setRange(delayThreeModDpethParameter->range.start, delayThreeModDpethParameter->range.end);
    mDelayThreeModDepthSlider.setValue(*delayThreeModDpethParameter);
    addAndMakeVisible(mDelayThreeModDepthSlider);
    mDelayThreeModDepthSlider.onValueChange = [this, delayThreeModDpethParameter] { *delayThreeModDpethParameter = mDelayThreeModDepthSlider.getValue(); };
    mDelayThreeModDepthSlider.onDragStart = [delayThreeModDpethParameter] {delayThreeModDpethParameter->beginChangeGesture(); };
    mDelayThreeModDepthSlider.onDragEnd = [delayThreeModDpethParameter] {delayThreeModDpethParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayThreeModRateParameter = (juce::AudioParameterFloat*)params.getUnchecked(14);
    mDelayThreeModRateSlider.setBounds(500, 400 , 200, 200);
    mDelayThreeModRateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayThreeModRateSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayThreeModRateSlider.setRange(delayThreeModRateParameter->range.start, delayThreeModRateParameter->range.end);
    mDelayThreeModRateSlider.setValue(*delayThreeModRateParameter);
    addAndMakeVisible(mDelayThreeModRateSlider);
    mDelayThreeModRateSlider.onValueChange = [this, delayThreeModRateParameter] { *delayThreeModRateParameter = mDelayThreeModRateSlider.getValue(); };
    mDelayThreeModRateSlider.onDragStart = [delayThreeModRateParameter] {delayThreeModRateParameter->beginChangeGesture(); };
    mDelayThreeModRateSlider.onDragEnd = [delayThreeModRateParameter] {delayThreeModRateParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayThreeFeedbackParameter = (juce::AudioParameterFloat*)params.getUnchecked(15);
    mDelayThreeFeedbackSlider.setBounds(500, 500 , 200, 200);
    mDelayThreeFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayThreeFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayThreeFeedbackSlider.setRange(delayThreeFeedbackParameter->range.start, delayThreeFeedbackParameter->range.end);
    mDelayThreeFeedbackSlider.setValue(*delayThreeFeedbackParameter);
    addAndMakeVisible(mDelayThreeFeedbackSlider);
    mDelayThreeFeedbackSlider.onValueChange = [this, delayThreeFeedbackParameter] { *delayThreeFeedbackParameter = mDelayThreeFeedbackSlider.getValue(); };
    mDelayThreeFeedbackSlider.onDragStart = [delayThreeFeedbackParameter] {delayThreeFeedbackParameter->beginChangeGesture(); };
    mDelayThreeFeedbackSlider.onDragEnd = [delayThreeFeedbackParameter] {delayThreeFeedbackParameter->endChangeGesture(); };
    
    
    juce::AudioParameterFloat* delayFourTimeParameter = (juce::AudioParameterFloat*)params.getUnchecked(16);
    mDelayFourTimeSlider.setBounds(700, 100 , 200, 200);
    mDelayFourTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayFourTimeSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayFourTimeSlider.setRange(delayFourTimeParameter->range.start, delayFourTimeParameter->range.end);
    mDelayFourTimeSlider.setValue(*delayFourTimeParameter);
    addAndMakeVisible(mDelayFourTimeSlider);
    mDelayFourTimeSlider.onValueChange = [this, delayFourTimeParameter] { *delayFourTimeParameter = mDelayFourTimeSlider.getValue(); };
    mDelayFourTimeSlider.onDragStart = [delayFourTimeParameter] {delayFourTimeParameter->beginChangeGesture(); };
    mDelayFourTimeSlider.onDragEnd = [delayFourTimeParameter] {delayFourTimeParameter->endChangeGesture(); };
    
    
    
    juce::AudioParameterFloat* delayFourGainParameter = (juce::AudioParameterFloat*)params.getUnchecked(17);
    mDelayFourGainSlider.setBounds(700, 200 , 200, 200);
    mDelayFourGainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayFourGainSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayFourGainSlider.setRange(delayFourGainParameter->range.start, delayFourGainParameter->range.end);
    mDelayFourGainSlider.setValue(*delayFourGainParameter);
    addAndMakeVisible(mDelayFourGainSlider);
    mDelayFourGainSlider.onValueChange = [this, delayFourGainParameter] { *delayFourGainParameter = mDelayFourGainSlider.getValue(); };
    mDelayFourGainSlider.onDragStart = [delayFourGainParameter] {delayFourGainParameter->beginChangeGesture(); };
    mDelayFourGainSlider.onDragEnd = [delayFourGainParameter] {delayFourGainParameter->endChangeGesture(); };
    
    
    
    juce::AudioParameterFloat* delayFourModDpethParameter = (juce::AudioParameterFloat*)params.getUnchecked(18);
    mDelayFourModDepthSlider.setBounds(700, 300 , 200, 200);
    mDelayFourModDepthSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayFourModDepthSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayFourModDepthSlider.setRange(delayFourModDpethParameter->range.start, delayFourModDpethParameter->range.end);
    mDelayFourModDepthSlider.setValue(*delayFourModDpethParameter);
    addAndMakeVisible(mDelayFourModDepthSlider);
    mDelayFourModDepthSlider.onValueChange = [this, delayFourModDpethParameter] { *delayFourModDpethParameter = mDelayFourModDepthSlider.getValue(); };
    mDelayFourModDepthSlider.onDragStart = [delayFourModDpethParameter] {delayFourModDpethParameter->beginChangeGesture(); };
    mDelayFourModDepthSlider.onDragEnd = [delayFourModDpethParameter] {delayFourModDpethParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayFourModRateParameter = (juce::AudioParameterFloat*)params.getUnchecked(19);
    mDelayFourModRateSlider.setBounds(700, 400 , 200, 200);
    mDelayFourModRateSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayFourModRateSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayFourModRateSlider.setRange(delayFourModRateParameter->range.start, delayFourModRateParameter->range.end);
    mDelayFourModRateSlider.setValue(*delayFourModRateParameter);
    addAndMakeVisible(mDelayFourModRateSlider);
    mDelayFourModRateSlider.onValueChange = [this, delayFourModRateParameter] { *delayFourModRateParameter = mDelayFourModRateSlider.getValue(); };
    mDelayFourModRateSlider.onDragStart = [delayFourModRateParameter] {delayFourModRateParameter->beginChangeGesture(); };
    mDelayFourModRateSlider.onDragEnd = [delayFourModRateParameter] {delayFourModRateParameter->endChangeGesture(); };
    
    juce::AudioParameterFloat* delayFourFeedbackParameter = (juce::AudioParameterFloat*)params.getUnchecked(20);
    mDelayFourFeedbackSlider.setBounds(700, 500 , 200, 200);
    mDelayFourFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mDelayFourFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 100, 50);
    mDelayFourFeedbackSlider.setRange(delayFourFeedbackParameter->range.start, delayFourFeedbackParameter->range.end);
    mDelayFourFeedbackSlider.setValue(*delayFourFeedbackParameter);
    addAndMakeVisible(mDelayFourFeedbackSlider);
    mDelayFourFeedbackSlider.onValueChange = [this, delayFourFeedbackParameter] { *delayFourFeedbackParameter = mDelayFourFeedbackSlider.getValue(); };
    mDelayFourFeedbackSlider.onDragStart = [delayFourFeedbackParameter] {delayFourFeedbackParameter->beginChangeGesture(); };
    mDelayFourFeedbackSlider.onDragEnd = [delayFourFeedbackParameter] {delayFourFeedbackParameter->endChangeGesture(); };
     
     
    
    
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
