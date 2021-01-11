#include "Layer.h"
#include "MenuLayer.h"
#include "CCDirectorModified.h"

bool Layer::init() {
	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	auto label = CCLabelBMFont::create("Hello from my CCScene!", "bigFont.fnt");
	label->setPosition(winSize / 2);

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto btn = CCMenuItemSpriteExtra::create(sprite, sprite, this, menu_selector(Layer::returnToMenu));

	btn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	auto menu = CCMenu::createWithItem(btn);
	
	addChild(menu, 2);
	addChild(label);
	

	auto topLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto topRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");

	topLeft->setFlipY(true);
	topRight->setFlipY(true);
	topRight->setFlipX(true);
	bottomRight->setFlipX(true);

	CCSize size = bottomLeft->getScaledContentSize();

	bottomLeft->setPosition({ size.width / 2, size.height / 2 });

	topLeft->setPosition({ size.width / 2, (winSize.height) - (size.height / 2) });

	topRight->setPosition({ (winSize.width) - (size.width / 2), (winSize.height) - (size.height / 2) });

	bottomRight->setPosition({ (winSize.width) - (size.width / 2), size.height / 2 });

	addChild(topLeft, 1);
	addChild(bottomLeft, 1);
	addChild(topRight, 1);
	addChild(bottomRight, 1);

	this->setKeypadEnabled(true);

	CCScene* wrapperScene = CCScene::create();

	wrapperScene->addChild(this);

	auto transition = CCTransitionFade::create(0.5f, wrapperScene);

	return director->pushScene(transition);
}

void Layer::keyBackClicked(void) {
	Layer::returnToMenu(nullptr);
}

void Layer::returnToMenu(CCObject* pSender) {
	CCDirectorModified* director = (CCDirectorModified*)CCDirectorModified::sharedDirector();

	director->replaceScene(
		CCTransitionFade::create(0.5f, director->getPreviousScene())
	);
}

Layer* Layer::create() {
	Layer* l = new Layer();
	l->initWithColor({ 0, 101, 253, 255 }, { 0, 46, 115, 255 });
	if (l && l->init()) {
		l->autorelease();
		return l;
	} else {
		CC_SAFE_DELETE(l);
		return NULL;
	}
}


