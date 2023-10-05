#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;
    
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override{
        if (slider == &frequencySlider)
            durationSlider.setValue(1.0 / frequencySlider.getValue());
        else if (slider == &durationSlider)
            frequencySlider.setValue(1.0 / durationSlider.getValue());
    }
private:
    
    juce::Slider frequencySlider;
    juce::Slider durationSlider;
    juce::Label frequencyLabel;
    juce::Label durationLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
