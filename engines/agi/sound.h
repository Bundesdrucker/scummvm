/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL$
 * $Id$
 *
 */

#ifndef AGI_SOUND_H
#define AGI_SOUND_H

#include "agi/agi.h"
#include "sound/audiostream.h"
#include "sound/mixer.h"

namespace Agi {

#define BUFFER_SIZE	410

#define SOUND_EMU_NONE	0
#define SOUND_EMU_PC	1
#define SOUND_EMU_TANDY	2
#define SOUND_EMU_MAC	3
#define SOUND_EMU_AMIGA	4
#define SOUND_EMU_APPLE2GS 5

#define WAVEFORM_SIZE   64
#define ENV_ATTACK	10000		/**< envelope attack rate */
#define ENV_DECAY       1000		/**< envelope decay rate */
#define ENV_SUSTAIN     100		/**< envelope sustain level */
#define ENV_RELEASE	7500		/**< envelope release rate */
#define NUM_CHANNELS    7		/**< number of sound channels */

struct IIgsEnvelopeSegment {
	uint8 bp;
	uint16 inc; ///< 8b.8b fixed point, big endian?
};

#define ENVELOPE_SEGMENT_COUNT 8
struct IIgsEnvelope {
	IIgsEnvelopeSegment seg[ENVELOPE_SEGMENT_COUNT];

	/** Reads an Apple IIGS envelope from then given stream. */
	bool read(Common::SeekableReadStream &stream);
};

// 2**(1/12) i.e. the 12th root of 2
#define SEMITONE 1.059463094359295

// Size of the SIERRASTANDARD file (i.e. the wave file i.e. the sample data used by the instruments).
#define SIERRASTANDARD_SIZE 65536

// Maximum number of instruments in an Apple IIGS instrument set.
// Chosen empirically based on Apple IIGS AGI game data, increase if needed.
#define MAX_INSTRUMENTS 28

struct IIgsWaveInfo {
	uint8 top;
	uint addr;
	uint size;
// Oscillator channel
#define OSC_CHANNEL_RIGHT 0
#define OSC_CHANNEL_LEFT  1
	uint channel;
// Oscillator mode
#define OSC_MODE_LOOP     0
#define OSC_MODE_ONESHOT  1
#define OSC_MODE_SYNC_AM  2
#define OSC_MODE_SWAP     3
	uint mode;
	bool halt;
	uint16 relPitch; ///< 8b.8b fixed point, big endian?

	/** Reads an Apple IIGS wave information structure from the given stream. */
	bool read(Common::SeekableReadStream &stream, bool ignoreAddr = false);
	bool finalize(Common::SeekableReadStream &uint8Wave);
};

// Number of waves per Apple IIGS sound oscillator
#define WAVES_PER_OSCILLATOR 2

/** An Apple IIGS sound oscillator. Consists always of two waves. */
struct IIgsOscillator {
	IIgsWaveInfo waves[WAVES_PER_OSCILLATOR];

	bool finalize(Common::SeekableReadStream &uint8Wave);
};

// Maximum number of oscillators in an Apple IIGS instrument.
// Chosen empirically based on Apple IIGS AGI game data, increase if needed.
#define MAX_OSCILLATORS 4

/** An Apple IIGS sound oscillator list. */
struct IIgsOscillatorList {
	uint count; ///< Oscillator count
	IIgsOscillator osc[MAX_OSCILLATORS]; ///< The oscillators

	/** Reads an Apple IIGS oscillator list from the given stream. */
	bool read(Common::SeekableReadStream &stream, uint oscillatorCount, bool ignoreAddr = false);
	bool finalize(Common::SeekableReadStream &uint8Wave);
};

struct IIgsInstrumentHeader {
	IIgsEnvelope env;
	uint8 relseg;
	uint8 bendrange;
	uint8 vibdepth;
	uint8 vibspeed;
	IIgsOscillatorList oscList;

	/**
	 * Read an Apple IIGS instrument header from the given stream.
	 * @param stream The source stream from which to read the data.
	 * @param ignoreAddr Should we ignore wave infos' wave address variable's value?
	 * @return True if successful, false otherwise.
	 */
	bool read(Common::SeekableReadStream &stream, bool ignoreAddr = false);
	bool finalize(Common::SeekableReadStream &uint8Wave);
};

struct IIgsSampleHeader {
	uint16 type;
	uint8  pitch; ///< Logarithmic, base is 2**(1/12), unknown multiplier (Possibly in range 1040-1080)
	uint8  unknownByte_Ofs3; // 0x7F in Gold Rush's sound resource 60, 0 in all others.
	uint8  volume; ///< Current guess: Logarithmic in 6 dB steps
	uint8  unknownByte_Ofs5; ///< 0 in all tested samples.
	uint16 instrumentSize; ///< Little endian. 44 in all tested samples. A guess.
	uint16 sampleSize; ///< Little endian. Accurate in all tested samples excluding Manhunter I's sound resource 16.
	IIgsInstrumentHeader instrument;

	/**
	 * Read an Apple IIGS AGI sample header from the given stream.
	 * @param stream The source stream from which to read the data.
	 * @return True if successful, false otherwise.
	 */
	bool read(Common::SeekableReadStream &stream);
	bool finalize(Common::SeekableReadStream &uint8Wave);
};

/**
 * AGI sound note structure.
 */
struct AgiNote {
	uint16 duration;    ///< Note duration
	uint16 freqDiv;     ///< Note frequency divisor (10-bit)
	uint8  attenuation; ///< Note volume attenuation (4-bit)

	/** Reads an AgiNote through the given pointer. */
	void read(const uint8 *ptr) {
		duration = READ_LE_UINT16(ptr);
		uint16 freqByte0 = *(ptr + 2); // Bits 4-9 of the frequency divisor
		uint16 freqByte1 = *(ptr + 3); // Bits 0-3 of the frequency divisor
		// Merge the frequency divisor's bits together into a single variable
		freqDiv = ((freqByte0 & 0x3F) << 4) | (freqByte1 & 0x0F);
		attenuation = *(ptr + 4) & 0x0F;
	}
};

/**
 * AGI engine sound channel structure.
 */
struct ChannelInfo {
#define AGI_SOUND_SAMPLE	0x0001
#define AGI_SOUND_MIDI		0x0002
#define AGI_SOUND_4CHN		0x0008
	uint32 type;
	const uint8 *ptr; // Pointer to the AgiNote data
	int16 *ins;
	int32 size;
	uint32 phase;
#define AGI_SOUND_LOOP		0x0001
#define AGI_SOUND_ENVELOPE	0x0002
	uint32 flags;
#define AGI_SOUND_ENV_ATTACK	3
#define AGI_SOUND_ENV_DECAY	2
#define AGI_SOUND_ENV_SUSTAIN	1
#define AGI_SOUND_ENV_RELEASE	0
	uint32 adsr;
	int32 timer;
	uint32 end;
	uint32 freq;
	uint32 vol;
	uint32 env;
};

class SoundMgr;

/**
 * AGI sound resource structure.
 */
class AgiSound {
public:
	AgiSound(SoundMgr &manager) : _manager(manager), _isPlaying(false), _isValid(false) {}
	virtual ~AgiSound() {}
	virtual void play()      { _isPlaying = true; }
	virtual void stop()      { _isPlaying = false; }
	virtual bool isPlaying() { return _isPlaying; }
	virtual uint16 type() = 0;

	/**
	 * A named constructor for creating different types of AgiSound objects
	 * from a raw sound resource.
	 *
	 * NOTE: This function should take responsibility for freeing the raw resource
	 * from memory using free() or delegate the responsibility onwards to some other
	 * function!
	 */
	static AgiSound *createFromRawResource(uint8 *data, uint32 len, int resnum, SoundMgr &manager);

protected:
	SoundMgr &_manager; ///< AGI sound manager object
	bool _isPlaying;    ///< Is the sound playing?
	bool _isValid;      ///< Is this a valid sound object?
};

class PCjrSound : public AgiSound {
public:
	PCjrSound(uint8 *data, uint32 len, int resnum, SoundMgr &manager);
	~PCjrSound() { if (_data != NULL) free(_data); }
	virtual uint16 type() { return _type; }
	const uint8 *getVoicePointer(uint voiceNum);
protected:
	uint8 *_data; ///< Raw sound resource data
	uint32 _len;  ///< Length of the raw sound resource
	uint16 _type; ///< Sound resource type
};

class IIgsMidi : public AgiSound {
public:
	IIgsMidi(uint8 *data, uint32 len, int resnum, SoundMgr &manager);
	~IIgsMidi() { if (_data != NULL) free(_data); }
	virtual uint16 type() { return _type; }
protected:
	uint8 *_data; ///< Raw sound resource data
	uint32 _len; ///< Length of the raw sound resource
	uint16 _type; ///< Sound resource type
};

class IIgsSample : public AgiSound {
public:
	IIgsSample(uint8 *data, uint32 len, int resnum, SoundMgr &manager);
	~IIgsSample() { delete[] _sample; }
	virtual uint16 type() { return _header.type; }
protected:
	IIgsSampleHeader _header; ///< Apple IIGS AGI sample header
	int16 *_sample;           ///< Sample data (16-bit signed format)
};

/** Apple IIGS AGI instrument set information. */
struct instrumentSetInfo {
	uint byteCount;          ///< Length of the whole instrument set in bytes
	uint instCount;          ///< Amount of instrument in the set
	const char *md5;         ///< MD5 hex digest of the whole instrument set
	const char *waveFileMd5; ///< MD5 hex digest of the wave file (i.e. the sample data used by the instruments)
};

/** Apple IIGS AGI executable file information. */
struct IIgsExeInfo {
	enum AgiGameID gameid;            ///< Game ID
	const char *exePrefix;            ///< Prefix of the Apple IIGS AGI executable (e.g. "SQ", "PQ", "KQ4" etc)
	uint agiVer;                      ///< Apple IIGS AGI version number, not strictly needed
	uint exeSize;                     ///< Size of the Apple IIGS AGI executable file in bytes
	uint instSetStart;                ///< Starting offset of the instrument set inside the executable file
	const instrumentSetInfo &instSet; ///< Information about the used instrument set
};

class AgiEngine;

class SoundMgr : public Audio::AudioStream {
	AgiEngine *_vm;

public:
	SoundMgr(AgiEngine *agi, Audio::Mixer *pMixer);
	~SoundMgr();
	virtual void setVolume(uint8 volume);

	// AudioStream API
	int readBuffer(int16 *buffer, const int numSamples) {
		premixerCall(buffer, numSamples / 2);
		return numSamples;
	}

	bool isStereo() const {
		return false;
	}

	bool endOfData() const {
		return false;
	}

	int getRate() const {
		// FIXME: Ideally, we should use _sampleRate.
		return 22050;
	}

private:
	Audio::Mixer *_mixer;
	Audio::SoundHandle _soundHandle;
	uint32 _sampleRate;

	void premixerCall(int16 *buf, uint len);

public:
	void unloadSound(int);
	void playSound();
	int initSound();
	void deinitSound();
	void startSound(int, int);
	void stopSound();
	void stopNote(int i);
	void playNote(int i, int freq, int vol);
	void playAgiSound();
	uint32 mixSound();
	bool loadInstruments();
	void playMidiSound();
	void playSampleSound();
	bool finalizeInstruments(Common::SeekableReadStream &uint8Wave);
	Audio::AudioStream *makeIIgsSampleStream(Common::SeekableReadStream &stream, int resnum = -1);
	const IIgsExeInfo *getIIgsExeInfo(enum AgiGameID gameid) const;
	bool loadInstrumentHeaders(const Common::String &exePath, const IIgsExeInfo &exeInfo);
	bool convertWave(Common::SeekableReadStream &source, int16 *dest, uint length);
	Common::MemoryReadStream *loadWaveFile(const Common::String &wavePath, const IIgsExeInfo &exeInfo);
};

} // End of namespace Agi

#endif /* AGI_SOUND_H */
