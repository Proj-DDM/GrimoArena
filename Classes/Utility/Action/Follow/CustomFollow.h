#ifndef CUSTOMFOLLOW_H
#define CUSTOMFOLLOW_H

#include "cocos2d.h"

namespace CustomAction{

	enum CustomFollowType{
		CustomFollowNone,
		CustomFollowXOnly,
		CustomFollowYOnly

	};

	class CustomFollow : public cocos2d::Action
	{
	private:
		CustomFollowType mType;
		cocos2d::Rect mMarginRect;

	public:
		static CustomFollow* create(cocos2d::Node* followedNode);
		static CustomFollow* create(cocos2d::Node* followedNode, CustomFollowType type);
		static CustomFollow* create(cocos2d::Node* followedNode, cocos2d::Node* equalityFollowedNode, CustomFollowType type);

		static CustomFollow* create(cocos2d::Node* followedNode, CustomFollowType type, cocos2d::Rect marginRect);
		static CustomFollow* create(cocos2d::Node* followedNode, cocos2d::Node* equalityFollowedNode, CustomFollowType type, cocos2d::Rect marginRect);
		static CustomFollow* create(cocos2d::Node* followedNode, cocos2d::Rect marginRect);

		inline bool isBoundarySet() const { return _boundarySet; }
		/** alter behavior - turn on/off boundary */
		inline void setBoudarySet(bool value) { _boundarySet = value; }

		//
		// Override
		//
		virtual CustomFollow* clone() const override;
		virtual CustomFollow* reverse() const override;
		virtual void step(float dt) override;
		virtual bool isDone() const override;
		virtual void stop() override;

		const cocos2d::Vec2& getCameraPos() const;

	CC_CONSTRUCTOR_ACCESS:
		/**
		* @js ctor
		*/
		CustomFollow()
			: _followedNode(nullptr)
			, _equalityFollowedNode(nullptr)
			, _boundarySet(false)
			, _boundaryFullyCovered(false)
			, _leftBoundary(0.0)
			, _rightBoundary(0.0)
			, _topBoundary(0.0)
			, _bottomBoundary(0.0)
			, _worldRect(cocos2d::Rect::ZERO)
		{}
		/**
		* @js NA
		* @lua NA
		*/
		virtual ~CustomFollow();

		/**
		* Initializes the action with a set boundary or with no boundary.
		*
		* @param followedNode  The node to be followed.
		* @param rect  The boundary. If \p rect is equal to Rect::ZERO, it'll work
		*              with no boundary.
		*/
		bool initWithTarget(cocos2d::Node *followedNode, const cocos2d::Rect& rect = cocos2d::Rect::ZERO);

		bool initWithTarget(cocos2d::Node *followedNode, cocos2d::Node *equalityFollowedNode, const cocos2d::Rect& rect = cocos2d::Rect::ZERO);

	protected:
		// node to follow
		cocos2d::Node *_followedNode;

		cocos2d::Node *_equalityFollowedNode;

		// whether camera should be limited to certain area
		bool _boundarySet;

		// if screen size is bigger than the boundary - update not needed
		bool _boundaryFullyCovered;

		// fast access to the screen dimensions
		cocos2d::Vec2 _halfScreenSize;
		cocos2d::Vec2 _fullScreenSize;

		// world boundaries
		float _leftBoundary;
		float _rightBoundary;
		float _topBoundary;
		float _bottomBoundary;
		cocos2d::Rect _worldRect;

	private:
		CC_DISALLOW_COPY_AND_ASSIGN(CustomFollow);
	};
}
#endif
