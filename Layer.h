#pragma once
#include <cocos2d.h>
using namespace cocos2d;

class Layer : public CCLayerGradient {
	Layer() = default;
	bool init();

	virtual void keyBackClicked(void);
public:
	static Layer* create();
	void returnToMenu(CCObject* sender);
};

class ChangeTextButton : public CCMenuItemSpriteExtra {
public:
	void callback(CCObject* pSender);
	inline static int state;
};