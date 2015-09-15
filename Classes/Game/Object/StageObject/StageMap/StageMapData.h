#ifndef _STAGE_MAP_DATA_H_
#define _STAGE_MAP_DATA_H_

struct StageMapData {
	int		splitX;
	int		splitY;

	StageMapData() {
		splitX = 0;
		splitY = 0;
	}

	StageMapData(int spX, int spY) {
		splitX = spX;
		splitY = spY;
	}
};

#endif