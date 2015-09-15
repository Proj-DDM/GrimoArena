#include "CustomFollow.h"

USING_NS_CC;

namespace CustomAction{


	CustomFollow::~CustomFollow(){
		CC_SAFE_RELEASE(_followedNode);
	}

	CustomFollow* CustomFollow::create(Node* followNode){
		CustomFollow *follow = new CustomFollow();

        if (follow && follow->initWithTarget(followNode, cocos2d::Rect::ZERO)){

			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}

	CustomFollow* CustomFollow::create(Node* followNode, CustomFollowType type){
		CustomFollow *follow = new CustomFollow();
		follow->mType = type;
		if (follow && follow->initWithTarget(followNode, cocos2d::Rect::ZERO)){
			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}

	CustomFollow* CustomFollow::create(Node* followNode, Node* equalityFollowedNode, CustomFollowType type){
		CustomFollow *follow = new CustomFollow();
		follow->mType = type;
		if (follow && follow->initWithTarget(followNode,equalityFollowedNode, cocos2d::Rect::ZERO)){
			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}

	CustomFollow* CustomFollow::create(Node* followNode, CustomFollowType type, cocos2d::Rect  marginRect){
		CustomFollow *follow = new CustomFollow();
		follow->mType = type;
		follow->mMarginRect = marginRect;

		if (follow && follow->initWithTarget(followNode, marginRect)){
			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}

	CustomFollow* CustomFollow::create(Node* followNode, Node* equalityFollowedNode, CustomFollowType type, cocos2d::Rect  marginRect){
		CustomFollow *follow = new CustomFollow();
		follow->mType = type;
		follow->mMarginRect = marginRect;

		if (follow && follow->initWithTarget(followNode, equalityFollowedNode, marginRect)){
			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}

	CustomFollow* CustomFollow::create(Node* followNode, cocos2d::Rect  marginRect){
		CustomFollow *follow = new CustomFollow();
		follow->mMarginRect = marginRect;
		if (follow && follow->initWithTarget(followNode, cocos2d::Rect::ZERO)){
			follow->autorelease();
			return follow;
		}
		CC_SAFE_DELETE(follow);
		return nullptr;
	}
	
	void CustomFollow::step(float dt){
		
		CC_UNUSED_PARAM(dt);

		if (_boundarySet)
		{
			if (_boundaryFullyCovered)
				return;
			Node* targetNode = _followedNode;

			if (_equalityFollowedNode){
				if (_followedNode->getPosition() < _equalityFollowedNode->getPosition()){
					targetNode = _equalityFollowedNode;
				}
			}

			cocos2d::Point tempPos = _halfScreenSize - targetNode->getPosition();

			float x = clampf(tempPos.x, _leftBoundary, _rightBoundary);
			float y = clampf(tempPos.y, _bottomBoundary, _topBoundary);

			if (mType == CustomFollowXOnly){
				y = _target->getPositionY();
			}
			else if (mType == CustomFollowYOnly){
				x = _target->getPositionX();
			}


			_target->setPosition(cocos2d::Point(x, y));
            
		}
		else
		{
			auto pos = _halfScreenSize - _followedNode->getPosition();

			if (mType == CustomFollowXOnly){
				pos.y = _target->getPositionY();
			}
			else if (mType == CustomFollowYOnly){
				pos.x = _target->getPositionX();
			}

			_target->setPosition(pos);
		}
	}

	CustomFollow* CustomFollow::clone() const
	{
		// no copy constructor
		auto a = new CustomFollow();
		a->initWithTarget(_followedNode, _worldRect);
		a->autorelease();
		return a;
	}

	CustomFollow* CustomFollow::reverse() const
	{
		return clone();
	}

	bool CustomFollow::initWithTarget(Node *followedNode, const cocos2d::Rect& rect/* = Rect::ZERO*/)
	{
		CCASSERT(followedNode != nullptr, "");

		followedNode->retain();
		_followedNode = followedNode;
		_worldRect = rect;
		if (rect.equals(cocos2d::Rect::ZERO))
		{
			_boundarySet = false;
		}
		else
		{
			_boundarySet = true;
		}

		_boundaryFullyCovered = false;

		cocos2d::Size winSize = Director::getInstance()->getWinSize();
		_fullScreenSize = Vec2(winSize.width, winSize.height);
		_halfScreenSize = _fullScreenSize * 0.5f;

		if (_boundarySet)
		{
			_leftBoundary = -((rect.origin.x + rect.size.width) - _fullScreenSize.x);
			_rightBoundary = -rect.origin.x;
			_topBoundary = -rect.origin.y;
			_bottomBoundary = -((rect.origin.y + rect.size.height) - _fullScreenSize.y);

			if (_rightBoundary < _leftBoundary)
			{
				// screen width is larger than world's boundary width
				//set both in the middle of the world
				_rightBoundary = _leftBoundary = (_leftBoundary + _rightBoundary) / 2;
			}
			if (_topBoundary < _bottomBoundary)
			{
				// screen width is larger than world's boundary width
				//set both in the middle of the world
				_topBoundary = _bottomBoundary = (_topBoundary + _bottomBoundary) / 2;
			}

			if ((_topBoundary == _bottomBoundary) && (_leftBoundary == _rightBoundary))
			{
				_boundaryFullyCovered = true;
			}
		}

		return true;
	}

	bool CustomFollow::initWithTarget(cocos2d::Node *followedNode, cocos2d::Node *equalityFollowedNode, const cocos2d::Rect& rect/* = Rect::ZERO*/)
	{
		CCASSERT(followedNode != nullptr, "");

		followedNode->retain();
		_followedNode = followedNode;

		CCASSERT(equalityFollowedNode != nullptr, "");

		equalityFollowedNode->retain();
		_equalityFollowedNode = equalityFollowedNode;

		_worldRect = rect;
		if (rect.equals(cocos2d::Rect::ZERO))
		{
			_boundarySet = false;
		}
		else
		{
			_boundarySet = true;
		}

		_boundaryFullyCovered = false;

		cocos2d::Size winSize = Director::getInstance()->getWinSize();
		_fullScreenSize = Vec2(winSize.width, winSize.height);
		_halfScreenSize = _fullScreenSize * 0.5f;

		if (_boundarySet)
		{
			_leftBoundary = -((rect.origin.x + rect.size.width) - _fullScreenSize.x);
			_rightBoundary = -rect.origin.x;
			_topBoundary = -rect.origin.y;
			_bottomBoundary = -((rect.origin.y + rect.size.height) - _fullScreenSize.y);

			if (_rightBoundary < _leftBoundary)
			{
				// screen width is larger than world's boundary width
				//set both in the middle of the world
				_rightBoundary = _leftBoundary = (_leftBoundary + _rightBoundary) / 2;
			}
			if (_topBoundary < _bottomBoundary)
			{
				// screen width is larger than world's boundary width
				//set both in the middle of the world
				_topBoundary = _bottomBoundary = (_topBoundary + _bottomBoundary) / 2;
			}

			if ((_topBoundary == _bottomBoundary) && (_leftBoundary == _rightBoundary))
			{
				_boundaryFullyCovered = true;
			}
		}

		return true;
	}

	bool CustomFollow::isDone() const
	{
		return (!_followedNode->isRunning());
	}

	void CustomFollow::stop()
	{
		_target = nullptr;
		Action::stop();
	}

	const Vec2& CustomFollow::getCameraPos() const{
		return _target->getPosition();
	}
}