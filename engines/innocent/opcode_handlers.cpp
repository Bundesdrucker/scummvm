#include "innocent/inter.h"

#include "common/util.h"

#include "innocent/innocent.h"
#include "innocent/logic.h"
#include "innocent/graphics.h"

namespace Innocent {

enum Debug {
	kOpcodesHit = 2
};

#define OPCODE(name) static void name(Interpreter *self, Argument *args[])

class OpcodeHandlers {
public:
	// 0x12 take bitmask of sound modes and see if they're supported
	OPCODE(testSound) {
		debug(kOpcodesHit, "test_sound(0x%04x) STUB", uint16(*args[0]));
		// stub
		// if no sound self->_abort = 1;
	}

	// 0x2d forget about last error
	OPCODE(decErrors) {
		self->forgetLastError();
	}

	// 0x70
	// assign second arg to first
	OPCODE(assign) {
		debug(kOpcodesHit, "[%p] = 0x%04d", args[0]->_ptr, uint16(*args[1]));
		*args[0] = uint16(*args[1]);
	}

	// 0x72
	// set first argument to 1
	OPCODE(assignOne) {
		*args[0] = byte(1);
	}

	// 0x9d
	static void setProtagonist(Interpreter *self, Argument *args[]) {
		debug(kOpcodesHit, "setProtagonist(0x%04x)", uint16(*args[0]));

		self->_logic->setProtagonistId(*args[0]);
	}

	// 0xc9 set backdrop image id (probably)
	OPCODE(setBackdrop) {
		self->_logic->_engine->_graphics->setBackdrop(*args[0]);
	}

	// 0xf9
	// turn sound on/off
	// first arg - 1=music, 2=sfx
	// second arg - 1=on, 0=off
	OPCODE(setSound) {
		debug(kOpcodesHit, "setSound(): turning %s %s", uint16(*args[0]) == 1 ? "music" : "sfx", uint16(*args[1]) ? "on" : "off");
		warning("setSound(): opcode STUB");
	}
};

Interpreter::OpcodeHandler Interpreter::_handlers[] = {
	/* opcode 00 */ 0,
	/* opcode 01 */ 0,
	/* opcode 02 */ 0,
	/* opcode 03 */ 0,
	/* opcode 04 */ 0,
	/* opcode 05 */ 0,
	/* opcode 06 */ 0,
	/* opcode 07 */ 0,
	/* opcode 08 */ 0,
	/* opcode 09 */ 0,
	/* opcode 0a */ 0,
	/* opcode 0b */ 0,
	/* opcode 0c */ 0,
	/* opcode 0d */ 0,
	/* opcode 0e */ 0,
	/* opcode 0f */ 0,
	/* opcode 10 */ 0,
	/* opcode 11 */ 0,
	/* opcode 12 */ OpcodeHandlers::testSound,
	/* opcode 13 */ 0,
	/* opcode 14 */ 0,
	/* opcode 15 */ 0,
	/* opcode 16 */ 0,
	/* opcode 17 */ 0,
	/* opcode 18 */ 0,
	/* opcode 19 */ 0,
	/* opcode 1a */ 0,
	/* opcode 1b */ 0,
	/* opcode 1c */ 0,
	/* opcode 1d */ 0,
	/* opcode 1e */ 0,
	/* opcode 1f */ 0,
	/* opcode 20 */ 0,
	/* opcode 21 */ 0,
	/* opcode 22 */ 0,
	/* opcode 23 */ 0,
	/* opcode 24 */ 0,
	/* opcode 25 */ 0,
	/* opcode 26 */ 0,
	/* opcode 27 */ 0,
	/* opcode 28 */ 0,
	/* opcode 29 */ 0,
	/* opcode 2a */ 0,
	/* opcode 2b */ 0,
	/* opcode 2c */ 0,
	/* opcode 2d */ OpcodeHandlers::decErrors,
	/* opcode 2e */ 0,
	/* opcode 2f */ 0,
	/* opcode 30 */ 0,
	/* opcode 31 */ 0,
	/* opcode 32 */ 0,
	/* opcode 33 */ 0,
	/* opcode 34 */ 0,
	/* opcode 35 */ 0,
	/* opcode 36 */ 0,
	/* opcode 37 */ 0,
	/* opcode 38 */ 0,
	/* opcode 39 */ 0,
	/* opcode 3a */ 0,
	/* opcode 3b */ 0,
	/* opcode 3c */ 0,
	/* opcode 3d */ 0,
	/* opcode 3e */ 0,
	/* opcode 3f */ 0,
	/* opcode 40 */ 0,
	/* opcode 41 */ 0,
	/* opcode 42 */ 0,
	/* opcode 43 */ 0,
	/* opcode 44 */ 0,
	/* opcode 45 */ 0,
	/* opcode 46 */ 0,
	/* opcode 47 */ 0,
	/* opcode 48 */ 0,
	/* opcode 49 */ 0,
	/* opcode 4a */ 0,
	/* opcode 4b */ 0,
	/* opcode 4c */ 0,
	/* opcode 4d */ 0,
	/* opcode 4e */ 0,
	/* opcode 4f */ 0,
	/* opcode 50 */ 0,
	/* opcode 51 */ 0,
	/* opcode 52 */ 0,
	/* opcode 53 */ 0,
	/* opcode 54 */ 0,
	/* opcode 55 */ 0,
	/* opcode 56 */ 0,
	/* opcode 57 */ 0,
	/* opcode 58 */ 0,
	/* opcode 59 */ 0,
	/* opcode 5a */ 0,
	/* opcode 5b */ 0,
	/* opcode 5c */ 0,
	/* opcode 5d */ 0,
	/* opcode 5e */ 0,
	/* opcode 5f */ 0,
	/* opcode 60 */ 0,
	/* opcode 61 */ 0,
	/* opcode 62 */ 0,
	/* opcode 63 */ 0,
	/* opcode 64 */ 0,
	/* opcode 65 */ 0,
	/* opcode 66 */ 0,
	/* opcode 67 */ 0,
	/* opcode 68 */ 0,
	/* opcode 69 */ 0,
	/* opcode 6a */ 0,
	/* opcode 6b */ 0,
	/* opcode 6c */ 0,
	/* opcode 6d */ 0,
	/* opcode 6e */ 0,
	/* opcode 6f */ 0,
	/* opcode 70 */ OpcodeHandlers::assign,
	/* opcode 71 */ 0,
	/* opcode 72 */ OpcodeHandlers::assignOne,
	/* opcode 73 */ 0,
	/* opcode 74 */ 0,
	/* opcode 75 */ 0,
	/* opcode 76 */ 0,
	/* opcode 77 */ 0,
	/* opcode 78 */ 0,
	/* opcode 79 */ 0,
	/* opcode 7a */ 0,
	/* opcode 7b */ 0,
	/* opcode 7c */ 0,
	/* opcode 7d */ 0,
	/* opcode 7e */ 0,
	/* opcode 7f */ 0,
	/* opcode 80 */ 0,
	/* opcode 81 */ 0,
	/* opcode 82 */ 0,
	/* opcode 83 */ 0,
	/* opcode 84 */ 0,
	/* opcode 85 */ 0,
	/* opcode 86 */ 0,
	/* opcode 87 */ 0,
	/* opcode 88 */ 0,
	/* opcode 89 */ 0,
	/* opcode 8a */ 0,
	/* opcode 8b */ 0,
	/* opcode 8c */ 0,
	/* opcode 8d */ 0,
	/* opcode 8e */ 0,
	/* opcode 8f */ 0,
	/* opcode 90 */ 0,
	/* opcode 91 */ 0,
	/* opcode 92 */ 0,
	/* opcode 93 */ 0,
	/* opcode 94 */ 0,
	/* opcode 95 */ 0,
	/* opcode 96 */ 0,
	/* opcode 97 */ 0,
	/* opcode 98 */ 0,
	/* opcode 99 */ 0,
	/* opcode 9a */ 0,
	/* opcode 9b */ 0,
	/* opcode 9c */ 0,
	/* opcode 9d */ OpcodeHandlers::setProtagonist,
	/* opcode 9e */ 0,
	/* opcode 9f */ 0,
	/* opcode a0 */ 0,
	/* opcode a1 */ 0,
	/* opcode a2 */ 0,
	/* opcode a3 */ 0,
	/* opcode a4 */ 0,
	/* opcode a5 */ 0,
	/* opcode a6 */ 0,
	/* opcode a7 */ 0,
	/* opcode a8 */ 0,
	/* opcode a9 */ 0,
	/* opcode aa */ 0,
	/* opcode ab */ 0,
	/* opcode ac */ 0,
	/* opcode ad */ 0,
	/* opcode ae */ 0,
	/* opcode af */ 0,
	/* opcode b0 */ 0,
	/* opcode b1 */ 0,
	/* opcode b2 */ 0,
	/* opcode b3 */ 0,
	/* opcode b4 */ 0,
	/* opcode b5 */ 0,
	/* opcode b6 */ 0,
	/* opcode b7 */ 0,
	/* opcode b8 */ 0,
	/* opcode b9 */ 0,
	/* opcode ba */ 0,
	/* opcode bb */ 0,
	/* opcode bc */ 0,
	/* opcode bd */ 0,
	/* opcode be */ 0,
	/* opcode bf */ 0,
	/* opcode c0 */ 0,
	/* opcode c1 */ 0,
	/* opcode c2 */ 0,
	/* opcode c3 */ 0,
	/* opcode c4 */ 0,
	/* opcode c5 */ 0,
	/* opcode c6 */ 0,
	/* opcode c7 */ 0,
	/* opcode c8 */ 0,
	/* opcode c9 */ OpcodeHandlers::setBackdrop,
	/* opcode ca */ 0,
	/* opcode cb */ 0,
	/* opcode cc */ 0,
	/* opcode cd */ 0,
	/* opcode ce */ 0,
	/* opcode cf */ 0,
	/* opcode d0 */ 0,
	/* opcode d1 */ 0,
	/* opcode d2 */ 0,
	/* opcode d3 */ 0,
	/* opcode d4 */ 0,
	/* opcode d5 */ 0,
	/* opcode d6 */ 0,
	/* opcode d7 */ 0,
	/* opcode d8 */ 0,
	/* opcode d9 */ 0,
	/* opcode da */ 0,
	/* opcode db */ 0,
	/* opcode dc */ 0,
	/* opcode dd */ 0,
	/* opcode de */ 0,
	/* opcode df */ 0,
	/* opcode e0 */ 0,
	/* opcode e1 */ 0,
	/* opcode e2 */ 0,
	/* opcode e3 */ 0,
	/* opcode e4 */ 0,
	/* opcode e5 */ 0,
	/* opcode e6 */ 0,
	/* opcode e7 */ 0,
	/* opcode e8 */ 0,
	/* opcode e9 */ 0,
	/* opcode ea */ 0,
	/* opcode eb */ 0,
	/* opcode ec */ 0,
	/* opcode ed */ 0,
	/* opcode ee */ 0,
	/* opcode ef */ 0,
	/* opcode f0 */ 0,
	/* opcode f1 */ 0,
	/* opcode f2 */ 0,
	/* opcode f3 */ 0,
	/* opcode f4 */ 0,
	/* opcode f5 */ 0,
	/* opcode f6 */ 0,
	/* opcode f7 */ 0,
	/* opcode f8 */ 0,
	/* opcode f9 */ OpcodeHandlers::setSound,
	/* opcode fa */ 0,
	/* opcode fb */ 0,
	/* opcode fc */ 0,
	/* opcode fd */ 0
};

} // End of namespace Innocent
