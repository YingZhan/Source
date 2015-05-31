/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ReverbAudioProcessor::ReverbAudioProcessor(float mix):_mix(mix)
{
    //int fs = 44100;
    _reverb = new FDNReverb();
}


ReverbAudioProcessor::~ReverbAudioProcessor()
{
}

//==============================================================================
const String ReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int ReverbAudioProcessor::getNumParameters()
{
    return 0;
}

float ReverbAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void ReverbAudioProcessor::setParameter (int index, float newValue)
{
}

const String ReverbAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String ReverbAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String ReverbAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String ReverbAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool ReverbAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool ReverbAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool ReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ReverbAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double ReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ReverbAudioProcessor::getNumPrograms()
{
    return 0;
}

int ReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String ReverbAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void ReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void ReverbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    int buffersize = buffer.getNumSamples();
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getSampleData (channel);
        _reverb -> ProcessByBuffer(channelData, channelData, buffersize);
        // ..do something to the data...
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool ReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ReverbAudioProcessor::createEditor()
{
    return new ReverbAudioProcessorEditor (this);
}

//==============================================================================
void ReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ReverbAudioProcessor();
}
