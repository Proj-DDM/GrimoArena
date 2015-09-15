#ifndef _BLOCK_DATA_H_
#define _BLOCK_DATA_H_

#include "string"

struct BlockData
{
	std::string		pointTextureName;
	int				panelState;
	int				panelType;
	
	BlockData()
	{
		pointTextureName = "";
		panelState = 0;
		panelType = 0;
	}
	
	BlockData( const std::string& block, int posX, int posY )
	{
		pointTextureName = block;
		panelState = posX;
		panelType = posY;
	}

};

#endif