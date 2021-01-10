#include "Layer.h"
#include "MenuLayer.h"
#include "CCDirectorModified.h"

bool Layer::init() {
	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	auto label = CCLabelBMFont::create("hello from my CCScene!", "bigFont.fnt");
	label->setPosition(winSize / 2);

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
	auto btn = CCMenuItemSpriteExtra::create(sprite, sprite, this, menu_selector(Layer::returnToMenu));

	btn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	auto menu = CCMenu::createWithItem(btn);

	addChild(menu);
	addChild(label);

	auto transition = CCTransitionFade::create(0.5f, this);

	
	return director->pushScene(transition);
}

void Layer::returnToMenu(CCObject* pSender) {
	CCDirectorModified* director = (CCDirectorModified*)CCDirectorModified::sharedDirector();

	director->replaceScene(
		CCTransitionFade::create(0.5f, director->getPreviousScene())
	);
}

Layer* Layer::create() {
	Layer* l = new Layer();
	if (l && l->init()) {
		l->autorelease();
		return l;
	} else {
		CC_SAFE_DELETE(l);
		return NULL;
	}
}


