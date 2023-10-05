#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    addAndMakeVisible(frequencySlider);
    frequencySlider.setRange(50, 5000);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.addListener(this);
    frequencySlider.setNumDecimalPlacesToDisplay(0);
    addAndMakeVisible(durationSlider);
    durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
    durationSlider.setTextValueSuffix(" s");
    durationSlider.addListener(this);
    durationSlider.setNumDecimalPlacesToDisplay(4);
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", juce::dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);
    addAndMakeVisible(durationLabel);
    durationLabel.setText("Duration", juce::dontSendNotification);
    durationLabel.attachToComponent(&durationSlider, true);

    frequencySlider.setValue(500.0);
    frequencySlider.setSkewFactorFromMidPoint(500);
    durationSlider.setSkewFactorFromMidPoint(0.002);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    
}

void MainComponent::resized()
{
    const int border = 120;
    
    frequencySlider.setBounds(border, 20, getWidth()-border, 20);
    durationSlider.setBounds(border, 50, getWidth() - border, 50);
}
