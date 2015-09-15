#ifndef _RED_BLOCK_H_
#define _RED_BLOCK_H_

#include "cocos2d.h"
#include "BlockData.h"
#include "Panel.h"

enum class ObjectType : int;

class RedBlock : public cocos2d::Sprite , public Panel {
	
protected:
	
	RedBlock();
	
	~RedBlock();
	
public:
	
	static RedBlock* create( const std::string& nodeName, const BlockData& data );
	
	bool init( const std::string& nodeName, const BlockData& data );
	
	bool isChange() const;

	void CreatePanel() override;
	
private:
	bool		mIsChanged;
};

#endif