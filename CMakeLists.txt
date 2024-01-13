cmake_minimum_required(VERSION 3.15)
project(Pluginomatic VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory(JUCE)

add_subdirectory(JUCE/extras)

juce_add_plugin(Pluginomatic
    COMPANY_NAME "dubgrade"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT TRUE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE DBGD
    PLUGIN_CODE Plgn
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "Pluginomatic")

file(GLOB SRC_FILES Source/*.cpp Source/*.h)

target_sources(Pluginomatic PRIVATE ${SRC_FILES})

target_compile_definitions(Pluginomatic PUBLIC JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(Pluginomatic PRIVATE
    juce_audio_utils
    juce_audio_processors
    juce_dsp
    juce_recommended_config_flags
    juce_recommended_lto_flags
    juce_recommended_warning_flags
)

juce_generate_juce_header(Pluginomatic)