#ifndef _PANEL_DATA_H_
#define _PANEL_DATA_H_

#include "string"

struct PanelData {
	int				panelState;
	int				panelType;
	
	PanelData() {
		panelState = 0;
		panelType = 0;
	}
	
	PanelData( int posX, int posY) {
		panelState = posX;
		panelType = posY;
	}

};

#endif