#pragma once
#include <cocos2d.h>
using namespace cocos2d;

class Layer : public CCLayer {
	Layer() = default;
	bool init();

	virtual void keyBackClicked(void);
public:
	static Layer* create();
	void returnToMenu(CCObject* sender);
};