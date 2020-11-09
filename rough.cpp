//==============================================================================
void Waylomod2020AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    /**
     addParameter(mDelayTwoTimeParameter = new juce::AudioParameterFloat("delay two delaytime", "Delay Two Delay Time", 0.0001, MAX_DELAY_TIME, 0.5));
     addParameter(mDelayTwoGainParameter = new juce::AudioParameterFloat("delaytowgain", "Delay Two Gain", 0.0, 1.0, 0.5));
     addParameter(mDelayTwoModDepthParameter = new juce::AudioParameterFloat("delaytwomodDepth", "Delay Two Mod Depth", 0, 1, 0.5));
     addParameter(mDelayTwoModRateParameter = new juce::AudioParameterFloat("delaytwomodDepth", "Delay Two Mod Depth", 0, 1, 0.5));
     addParameter(mDelayTwoFeedbackParameter = new juce::AudioParameterFloat("feedbacktwo", "Feedback Two", 0.0, 0.98, 0.5));
     **/
    
    /***
    std::unique_ptr<juce::XmlElement> xml(new juce::XmlElement ("waylomod2020"));
    xml->setAttribute("drygain", *mDryGainParameter);
    xml->setAttribute("delayonetime", *mDelayOneTimeParameter);
    xml->setAttribute("delayonegain", *mDelayOneGainParameter);
    xml->setAttribute("delayonedepth", *mDelayOneModDepthParameter);
    xml->setAttribute("delayonerate", *mDelayOneModRateParameter);
    xml->setAttribute("delayonefeedback", *mDelayOneFeedbackParameter);
    xml->setAttribute("delaytwotime", *mDelayTwoTimeParameter);
    xml->setAttribute("delaytwogain", *mDelayTwoGainParameter);
    xml->setAttribute("delaytwodepth", *mDelayTwoModDepthParameter);
    xml->setAttribute("delaytworate", *mDelayTwoModRateParameter);
    xml->setAttribute("delaytwofeedback", *mDelayTwoFeedbackParameter);
    xml->setAttribute("delaythreetime", *mDelayThreeTimeParameter);
    xml->setAttribute("delaythreegain", *mDelayThreeGainParameter);
    xml->setAttribute("delaythreedepth", *mDelayThreeModDepthParameter);
    xml->setAttribute("delaythreerate", *mDelayThreeModRateParameter);
    xml->setAttribute("delaythreefeedback", *mDelayThreeFeedbackParameter);
    xml->setAttribute("delayfourtime", *mDelayFourTimeParameter);
    xml->setAttribute("delayfourgain", *mDelayFourGainParameter);
    xml->setAttribute("delayfourdepth", *mDelayFourModDepthParameter);
    xml->setAttribute("delayfourrate", *mDelayFourModRateParameter);
    xml->setAttribute("delayfourfeedback", *mDelayFourFeedbackParameter);
    xml->setAttribute("delayfivetime", *mDelayFiveTimeParameter);
    xml->setAttribute("delayfivegain", *mDelayFiveGainParameter);
    xml->setAttribute("delayfivedepth", *mDelayFiveModDepthParameter);
    xml->setAttribute("delayfiverate", *mDelayFiveModRateParameter);
    xml->setAttribute("delayfivefeedback", *mDelayFiveFeedbackParameter);
    xml->setAttribute("delaysixtime", *mDelaySixTimeParameter);
    xml->setAttribute("delaysixgain", *mDelaySixGainParameter);
    xml->setAttribute("delaysixdepth", *mDelaySixModDepthParameter);
    xml->setAttribute("delaysixrate", *mDelaySixModRateParameter);
    xml->setAttribute("delaysixfeedback", *mDelaySixFeedbackParameter);
    xml->setAttribute("delayseventime", *mDelaySevenTimeParameter);
    xml->setAttribute("delaysevengain", *mDelaySevenGainParameter);
    xml->setAttribute("delaysevendepth", *mDelaySevenModDepthParameter);
    xml->setAttribute("delaysevenrate", *mDelaySevenModRateParameter);
    xml->setAttribute("delaysevenfeedback", *mDelaySevenFeedbackParameter);
    xml->setAttribute("delayeighttime", *mDelayEightTimeParameter);
    xml->setAttribute("delayeightgain", *mDelayEightGainParameter);
    xml->setAttribute("delayeightdepth", *mDelayEightModDepthParameter);
    xml->setAttribute("delayeightrate", *mDelayEightModRateParameter);
    xml->setAttribute("delayeightfeedback", *mDelayEightFeedbackParameter);
    
    
    copyXmlToBinary(*xml, destData);
     
     ***/
    
    
}

void Waylomod2020AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    /***
    
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    
    if (xml.get() != nullptr && xml->hasTagName("waylomod2020"))
    {
        *mDryGainParameter = xml->getDoubleAttribute("drygain");
        
        *mDelayOneTimeParameter = xml->getDoubleAttribute("delayonetime");
        *mDelayOneGainParameter = xml->getDoubleAttribute("delayonegain");
        *mDelayOneModDepthParameter = xml->getDoubleAttribute("delayonedepth");
        *mDelayOneModRateParameter = xml->getDoubleAttribute("delayonerate");
        *mDelayOneFeedbackParameter = xml->getDoubleAttribute("delayonefeedback");
        
        *mDelayTwoTimeParameter = xml->getDoubleAttribute("delaytwotime");
        *mDelayTwoGainParameter = xml->getDoubleAttribute("delaytwogain");
        *mDelayTwoModDepthParameter = xml->getDoubleAttribute("delaytwodepth");
        *mDelayTwoModRateParameter = xml->getDoubleAttribute("delaytworate");
        *mDelayTwoFeedbackParameter = xml->getDoubleAttribute("delayonefeedback");
        
        *mDelayThreeTimeParameter = xml->getDoubleAttribute("delaythreetime");
        *mDelayThreeGainParameter = xml->getDoubleAttribute("delaythreegain");
        *mDelayThreeModDepthParameter = xml->getDoubleAttribute("delaythreedepth");
        *mDelayThreeModRateParameter = xml->getDoubleAttribute("delaythreerate");
        *mDelayThreeFeedbackParameter = xml->getDoubleAttribute("delaythreefeedback");
        
        *mDelayFourTimeParameter = xml->getDoubleAttribute("delayfourtime");
        *mDelayFourGainParameter = xml->getDoubleAttribute("delayfourgain");
        *mDelayFourModDepthParameter = xml->getDoubleAttribute("delayfourdepth");
        *mDelayFourModRateParameter = xml->getDoubleAttribute("delayfourrate");
        *mDelayFourFeedbackParameter = xml->getDoubleAttribute("delayfourfeedback");
        
        *mDelayFiveTimeParameter = xml->getDoubleAttribute("delayfivetime");
        *mDelayFiveGainParameter = xml->getDoubleAttribute("delayfivegain");
        *mDelayFiveModDepthParameter = xml->getDoubleAttribute("delayfivedepth");
        *mDelayFiveModRateParameter = xml->getDoubleAttribute("delayfiverate");
        *mDelayFiveFeedbackParameter = xml->getDoubleAttribute("delayfivefeedback");
        
        *mDelaySixTimeParameter = xml->getDoubleAttribute("delaysixtime");
        *mDelaySixGainParameter = xml->getDoubleAttribute("delaysixgain");
        *mDelaySixModDepthParameter = xml->getDoubleAttribute("delaysixdepth");
        *mDelaySixModRateParameter = xml->getDoubleAttribute("delaysixrate");
        *mDelaySixFeedbackParameter = xml->getDoubleAttribute("delaysixfeedback");
        
        *mDelaySevenTimeParameter = xml->getDoubleAttribute("delayseventime");
        *mDelaySevenGainParameter = xml->getDoubleAttribute("delaysevengain");
        *mDelaySevenModDepthParameter = xml->getDoubleAttribute("delaysevendepth");
        *mDelaySevenModRateParameter = xml->getDoubleAttribute("delaysevenrate");
        *mDelayOneFeedbackParameter = xml->getDoubleAttribute("delaysevenfeedback");
        
        *mDelayEightTimeParameter = xml->getDoubleAttribute("delayeighttime");
        *mDelayEightGainParameter = xml->getDoubleAttribute("delayeightgain");
        *mDelayEightModDepthParameter = xml->getDoubleAttribute("delayeightdepth");
        *mDelayEightModRateParameter = xml->getDoubleAttribute("delayeightrate");
        *mDelayEightFeedbackParameter = xml->getDoubleAttribute("delayeightfeedback");
        

        
    }
        **/
}
