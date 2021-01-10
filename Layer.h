#pragma once
#include <cocos2d.h>
using namespace cocos2d;

class Layer : public CCScene, public CCKeyboardDelegate {
	Layer() = default;
	bool init();

	void update(float idk);
public:
	static Layer* create();
	void returnToMenu(CCObject* sender);
};