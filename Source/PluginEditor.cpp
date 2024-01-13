/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginomaticAudioProcessorEditor::PluginomaticAudioProcessorEditor (PluginomaticAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (900, 500);

    pmButton.setButtonText("PMt");
    pmButton.addListener(this);
    addAndMakeVisible(pmButton);

    addAndMakeVisible(newPage); // Add this line
    newPage.setVisible(false);  // Initially hiddens

    newPage.setBounds(getLocalBounds());

}

PluginomaticAudioProcessorEditor::~PluginomaticAudioProcessorEditor()
{
}

void PluginomaticAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &pmButton)
    {
        
        // Calculate the new Y position for newPage, just below the PM button
        int newPageYPos = pmButton.getY() + pmButton.getHeight();

        // Set the bounds for newPage to start just below the PM button
        newPage.setBounds(0, newPageYPos, getWidth(), getHeight() - newPageYPos);

        addAndMakeVisible(newPage); // Make the newPage visible

        newPage.setVisible(true); // Make the newPage visible here

    }
}

//==============================================================================
void PluginomaticAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
}


void PluginomaticAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    pmButton.setBounds(150, 10, 100, 30); // x, y, width, height

    if (newPage.isVisible()) {
        int newPageYPos = pmButton.getY() + pmButton.getHeight();
        int newPageHeight = getHeight() - newPageYPos - 55; // 30 pixels shorter
        newPage.setBounds(0, newPageYPos, getWidth(), newPageHeight);
    }
}


