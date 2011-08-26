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
 */

#ifndef CRUISE_MOUSE_H
#define CRUISE_MOUSE_H

#include "common/keyboard.h"
#include "common/events.h"
namespace Cruise {

enum CursorType {
	CURSOR_NORMAL = 0,
	CURSOR_DISK = 1,
	CURSOR_CROSS = 2,
	CURSOR_NOMOUSE = 3,
	CURSOR_WALK = 4,
	CURSOR_EXIT = 5,
	CURSOR_MAGNIFYING_GLASS = 6,
	CURSOR_MAX = 7
};

enum MouseButton {
	CRS_MB_LEFT = 1,
	CRS_MB_RIGHT = 2,
	CRS_MB_MIDDLE = 4,
	CRS_MB_BOTH = CRS_MB_LEFT | CRS_MB_RIGHT
};

struct MouseCursor {
	int hotspotX;
	int hotspotY;
	const byte *bitmap;
};

class Mouse {
private:
	static const MouseCursor mouseCursors[];
	static const byte cursorPalette[];

public:
	int _coordinateX;
	int _coordinateY;
	int _button;
	CursorType _cursor;

	Mouse();

	void reset() {_button = 0;}
	void restore() {changeCursor(_cursor);}
	void manageEvent(Common::Event event);
	void getStatus(int16 *pMouseX, int16 *pMouseButton, int16 *pMouseY);
	void changeCursor(CursorType eType);

	static void mouseOff();
	static void mouseOn();
};




} // End of namespace Cruise

#endif
