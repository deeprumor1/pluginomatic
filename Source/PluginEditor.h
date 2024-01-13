/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/

class LibrarySidebar : public juce::Component {
public:
    LibrarySidebar() {
        populateDSPList(); // Populate the DSP list on creation
        
        // Initialize your DSP block library here
    }

    void paint(juce::Graphics& g) override {
        g.fillAll(juce::Colours::darkgrey); // Sidebar background color
        // You can add code here to draw the list of DSP blocks
    }

    void populateDSPList() {
        dspEffectNames.add("SimpleGain"); // Replace with actual names
        
        // Add other effect names
    }

private:
    juce::StringArray dspEffectNames;

    // Add more methods for interactivity if needed
};


class NewPageComponent : public juce::Component
{
public:
    NewPageComponent() {
        addAndMakeVisible(librarySidebar);
    }

    void resized() override {
        auto sidebarWidth = 200; // Adjust the width as needed
        librarySidebar.setBounds(0, 0, sidebarWidth, getHeight());
        //
    }

    private:
    LibrarySidebar librarySidebar;

    void paint(juce::Graphics& g) override
    {
        g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    }
    // Add more functionality as needed
};

class PluginomaticAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Button::Listener
{
public:
    PluginomaticAudioProcessorEditor (PluginomaticAudioProcessor&);
    ~PluginomaticAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button) override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginomaticAudioProcessor& audioProcessor;

    juce::TextButton pmButton;
    NewPageComponent newPage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginomaticAudioProcessorEditor)
};



