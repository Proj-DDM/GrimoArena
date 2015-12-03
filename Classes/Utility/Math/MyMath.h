#ifndef MATH_H
#define MATH_H

#include "cocos2d.h"

//����Math(����clamp�̂�)
namespace MyMath{
	namespace{
		//�͈͐���(float)
		float clamp(float val, float minVal, float maxVal){
			if (val < minVal) return minVal;
			if (val > maxVal) return maxVal;
			return val;
		};
		//�͈͐���(int)
		int clamp(int val, int minVal, int maxVal){
			if (val < minVal) return minVal;
			if (val > maxVal) return maxVal;

			return val;
		};

#define USE_ECLIPSE

#ifdef USE_ECLIPSE // Eclipse
		cocos2d::Vec2 clamp(cocos2d::Vec2 val, cocos2d::Vec2 minVal, cocos2d::Vec2 maxVal){
			float x = clamp(val.x, minVal.x, maxVal.x);
			float y = clamp(val.y, minVal.y, maxVal.y);

			return cocos2d::Vec2(x, y);
		};

#endif

#ifdef USE_VISUAL_STUDIO	// VisualStudio�Ȃ�
		cocos2d::Vec2 clamp(cocos2d::Vec2 val, cocos2d::Vec2 minVal, cocos2d::Vec2 maxVal){
			float x = clamp(val.x, minVal.x, maxVal.x);
			float y = clamp(val.y, minVal.y, maxVal.y);

			return cocos2d::Vec2(x, y);
		};

#endif

	}
};
#endif
