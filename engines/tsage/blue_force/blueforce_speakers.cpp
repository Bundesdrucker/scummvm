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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "tsage/blue_force/blueforce_speakers.h"
#include "tsage/scenes.h"
#include "tsage/tsage.h"
#include "tsage/graphics.h"
#include "tsage/staticres.h"

namespace TsAGE {

namespace BlueForce {

VisualSpeaker::VisualSpeaker(): Speaker() {
	_textWidth = 312;
	_color1 = 19;
	_hideObjects = false;
	_removeObject1 = false;
	_removeObject2 = false;
	_xp = 160;
	_fontNumber = 4;
	_color2 = 82;
	_offsetPos = Common::Point(4, 170);
	_numFrames = 0;
}

void VisualSpeaker::remove() {
	if (_removeObject2)
		_object2.remove();
	if (_removeObject1)
		_object1.remove();

	Speaker::remove();
}

void VisualSpeaker::synchronize(Serializer &s) {
	Speaker::synchronize(s);
	
	s.syncAsByte(_removeObject1);
	s.syncAsByte(_removeObject2);
	s.syncAsSint16LE(_xp);
	s.syncAsSint16LE(_numFrames);
	s.syncAsSint16LE(_offsetPos.x);
	s.syncAsSint16LE(_offsetPos.y);
}

void VisualSpeaker::proc12(Action *action) {
	Speaker::proc12(action);
	_textPos = Common::Point(_offsetPos.x + BF_GLOBALS._sceneManager._scene->_sceneBounds.left,
		_offsetPos.y + BF_GLOBALS._sceneManager._scene->_sceneBounds.top);
	_numFrames = 0;
}

void VisualSpeaker::setText(const Common::String &msg) {
	_objectList.draw();
	BF_GLOBALS._sceneObjects->draw();

	_sceneText._color1 = _color1;
	_sceneText._color2 = _color2;
	_sceneText._color3 = _color3;
	_sceneText._width = _textWidth;
	_sceneText._fontNumber = _fontNumber;
	_sceneText._textMode = _textMode;
	_sceneText.setup(msg);

	// Get the string bounds
	GfxFont f;
	f.setFontNumber(_fontNumber);
	Rect bounds;
	f.getStringBounds(msg.c_str(), bounds, _textWidth);

	// Set the position for the text
	switch (_textMode) {
	case ALIGN_LEFT:
	case ALIGN_JUSTIFIED:
		_sceneText.setPosition(_textPos);
		break;
	case ALIGN_CENTER:
		_sceneText.setPosition(Common::Point(_textPos.x + (_textWidth - bounds.width()) / 2, _textPos.y));
		break;
	case ALIGN_RIGHT:
		_sceneText.setPosition(Common::Point(_textPos.x + _textWidth - bounds.width(), _textPos.y));
		break;
	default:
		break;
	}

	// Ensure the text is in the foreground
	_sceneText.fixPriority(256);

	// Count the number of words (by spaces) in the string
	const char *s = msg.c_str();
	int spaceCount = 0;
	while (*s) {
		if (*s++ == ' ')
			++spaceCount;
	}

	_numFrames = spaceCount * 3 + 2;
}

/*--------------------------------------------------------------------------*/

SpeakerGameText::SpeakerGameText(): VisualSpeaker() {
	_speakerName = "GAMETEXT";
	_color1 = 8;
	_color2 = 19;
}

/*--------------------------------------------------------------------------*/

SpeakerSutter::SpeakerSutter() {
	_speakerName = "SUTTER";
	_color1 = 20;
	_color2 = 22;
	_textMode = ALIGN_CENTER;
}

void SpeakerSutter::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(329);
	_object1.setStrip2(2);
	_object1.fixPriority(254);
	_object1.changeZoom(100);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 45,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.setVisage(329);
	_object2.setStrip2(1);
	_object2.fixPriority(255);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 45,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerDoug::SpeakerDoug(): VisualSpeaker() {
	_color1 = 32;
	_speakerName = "DOUG";
}

/*--------------------------------------------------------------------------*/

SpeakerJakeNoHead::SpeakerJakeNoHead(): VisualSpeaker() {
	_color1 = 13;
	_speakerName = "JAKE_NO_HEAD";
}

/*--------------------------------------------------------------------------*/

SpeakerHarrison::SpeakerHarrison(): VisualSpeaker() {
	_color1 = 32;
	_speakerName = "HARRISON";
}

void SpeakerHarrison::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(325);
	_object1.setStrip2(7);
	_object1.fixPriority(254);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 277,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.fixPriority(255);
	_object2.setVisage(325);
	_object2.setStrip2(6);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 277,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerJakeJacket::SpeakerJakeJacket(): VisualSpeaker() {
	_color1 = 13;
	_color2 = 7;
	_speakerName = "JAKEJACKET";
}

void SpeakerJakeJacket::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(1001);
	_object1.setStrip2(4);
	_object1.fixPriority(254);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + _xp,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.setVisage(1001);
	_object2.setStrip2(1);
	_object2.fixPriority(255);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + _xp,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerJakeUniform::SpeakerJakeUniform(): VisualSpeaker() {
	_color1 = 13;
	_color2 = 7;
	_speakerName = "JAKEUNIFORM";
}

void SpeakerJakeUniform::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(1001);
	_object1.setStrip2(3);
	_object1.fixPriority(254);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 45,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.setVisage(1001);
	_object2.setStrip2(1);
	_object2.fixPriority(255);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 45,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerJailer::SpeakerJailer(): VisualSpeaker() {
	_color1 = 13;
	_color2 = 7;
	_speakerName = "JAILER";
}

void SpeakerJailer::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(395);
	_object1.setStrip(6);
	_object1.fixPriority(254);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 40,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.setVisage(395);
	_object2.setStrip(5);
	_object2.fixPriority(255);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + 40,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerPSutter::SpeakerPSutter(): VisualSpeaker() {
	_color1 = 20;
	_color2 = 22;
	_speakerName = "PSUTTER";
}

void SpeakerPSutter::setText(const Common::String &msg) {
	_removeObject2 = true;

	_object2.postInit();
	_object2.setVisage(335);
	_object2.setStrip2(3);
	_object2.fixPriority(200);
	_object2.setPosition(Common::Point(202, 48));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

/*--------------------------------------------------------------------------*/

SpeakerJakeRadio::SpeakerJakeRadio(): VisualSpeaker() {
	_color1 = 13;
	_color2 = 7;
	_speakerName = "JAKE_RADIO";
}

/*--------------------------------------------------------------------------*/

SpeakerLyleHat::SpeakerLyleHat(): VisualSpeaker() {
	_color1 = 29;
	_color2 = 89;
	_xp = 75;
	_speakerName = "LYLEHAT";
}

void SpeakerLyleHat::setText(const Common::String &msg) {
	_removeObject1 = _removeObject2 = true;

	_object1.postInit();
	_object1.setVisage(278);
	_object1.setStrip2(4);
	_object1.fixPriority(254);
	_object1.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + _xp,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	_object2.postInit();
	_object2.setVisage(278);
	_object2.setStrip2(2);
	_object2.fixPriority(255);
	_object2.setPosition(Common::Point(BF_GLOBALS._sceneManager._scene->_sceneBounds.left + _xp,
		BF_GLOBALS._sceneManager._scene->_sceneBounds.top + 166));

	VisualSpeaker::setText(msg);
	_object2.fixCountdown(8, _numFrames);
}

} // End of namespace BlueForce

} // End of namespace TsAGE
