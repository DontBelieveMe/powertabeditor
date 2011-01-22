/////////////////////////////////////////////////////////////////////////////
// Name:            generalmidi.cpp
// Purpose:         General MIDI macros, constants and functions
// Author:          Brad Larsen
// Modified by:
// Created:         Dec 9, 2004
// RCS-ID:
// Copyright:       (c) Brad Larsen
// License:         wxWindows license
/////////////////////////////////////////////////////////////////////////////

#include "generalmidi.h"
#include "macros.h"

namespace midi
{
    // MIDI Channel Functions
    /// Determines if a MIDI channel is valid
    /// @param MIDI channel to validate
    /// @return True if the MIDI channel is valid, false if not
    bool IsValidMidiChannel(uint8_t channel)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (channel <= LAST_MIDI_CHANNEL);
    }

    bool IsValidMidiChannelVolume(uint8_t volume)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (volume <= MAX_MIDI_CHANNEL_VOLUME);
    }

    /// Determines if a MIDI channel effect level is valid
    /// @param level MIDI channel effect level to validate
    /// @return True if the MIDI channel effect level is valid, false if not
    bool IsValidMidiChannelEffectLevel(uint8_t level)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (level <= MAX_MIDI_CHANNEL_EFFECT_LEVEL);
    }

    // MIDI Note Functions
    /// Determines if a MIDI note value is valid
    /// @param note MIDI note to validate
    /// @return True if the MIDI note value is valid, false if not
    bool IsValidMidiNote(uint8_t note)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (note <= MAX_MIDI_NOTE);
    }

    /// Gets the text representation of a MIDI note
    /// @param note MIDI note to get the text representation for
    /// @param sharps True to get the sharp representation of the note, false to get
    /// the flat representation of the note
    /// @return A text representation of the MIDI note
    std::string GetMidiNoteText(uint8_t note, bool sharps)
    {
        //------Last Checked------//
        // - Dec 14, 2004
        CHECK_THAT(IsValidMidiNote(note), "");
        uint8_t pitch = GetMidiNotePitch(note);

        std::string notes[12];

        if (sharps)
        {
            notes[0] = "C";
            notes[1] = "C#";
            notes[2] = "D";
            notes[3] = "D#";
            notes[4] = "E";
            notes[5] = "F";
            notes[6] = "F#";
            notes[7] = "G";
            notes[8] = "G#";
            notes[9] = "A";
            notes[10] = "A#";
            notes[11] = "B";
        }
        else
        {
            notes[0] = "C";
            notes[1] = "Db";
            notes[2] = "D";
            notes[3] = "Eb";
            notes[4] = "E";
            notes[5] = "F";
            notes[6] = "Gb";
            notes[7] = "G";
            notes[8] = "Ab";
            notes[9] = "A";
            notes[10] = "Bb";
            notes[11] = "B";
        }

        return (notes[pitch]);
    }

    /// Offsets a MIDI note by an offset
    /// @param note MIDI note to offset
    /// @param offset Amount to offset the note
    /// @return The offset note
    uint8_t OffsetMidiNote(uint8_t note, int8_t offset)
    {
        //------Last Checked------//
        // - Dec 14, 2004
        int32_t temp = note + offset;

        if (temp < MIN_MIDI_NOTE)
            temp = MIN_MIDI_NOTE;
        else if (temp > MAX_MIDI_NOTE)
            temp = MAX_MIDI_NOTE;

        return ((uint8_t)(temp));
    }

    /// Determines if a MIDI note key is valid
    /// @param key MIDI note key to validate
    /// @return True if the MIDI note key is valid, false if not
    bool IsValidMidiNoteKey(uint8_t key)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (key <= MAX_MIDI_NOTE_KEY);
    }

    /// Gets the pitch value for a MIDI note
    /// @param note MIDI note to get the pitch value for
    /// @return The pitch value for the MIDI note
    uint8_t GetMidiNotePitch(uint8_t note)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (note % 12);
    }

    /// Gets the octave value for a MIDI note
    /// @param note MIDI note to get the octave value for
    /// @return The octave value for the MIDI note
    int32_t GetMidiNoteOctave(uint8_t note)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return ((note / 12) - 1);
    }

    /// Determines if a MIDI note volume is valid
    /// @param volume MIDI note volume to validate
    /// @return True if the MIDI note volume is valid, false if not
    bool IsValidMidiNoteVolume(uint8_t volume)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (volume <= MAX_MIDI_NOTE_VOLUME);
    }

    // MIDI Preset Functions
    /// Determines if a MIDI preset is valid
    /// @param preset MIDI preset to validate
    /// @return True if the MIDI preset is valid, false if not
    bool IsValidMidiPreset(uint8_t preset)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (preset <= LAST_MIDI_PRESET);
    }

    // MIDI Percussion Preset Functions
    /// Determines if a MIDI percussion preset is valid
    /// @param preset MIDI percussion preset to validate
    /// @return True if the MIDI percussion preset is valid, false if not
    bool IsValidMidiPercussionPreset(uint8_t preset)
    {
        //------Last Checked------//
        // - Dec 9, 2004
        return (preset <= LAST_MIDI_PERCUSSION_PRESET);
    }
}
