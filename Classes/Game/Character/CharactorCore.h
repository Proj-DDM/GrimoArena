#ifndef CHARACTORCORE_H
#define CHARACTORCORE_H

#define ICONSIZE 120

#define ICON_RENDER_HEIGHT 135

namespace CharactorCore
{
	static int convertPositonToNumber(int x, int y)
	{
		return ((x - 60) / 120) + ((y - 360) / 120 * 9);
	}
}

#endif