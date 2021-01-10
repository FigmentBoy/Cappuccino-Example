#pragma once
#include <cocos2d.h>
using namespace cocos2d;

class Layer : public CCScene {
	Layer() = default;
	bool init();
public:
	static Layer* create();
	void returnToMenu(CCObject* sender);
};