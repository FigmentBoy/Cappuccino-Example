#include "Layer.h"
#include "MenuLayer.h"
#include "CCDirectorModified.h"

void ChangeTextButton::callback(CCObject* pSender) {
	CCDirector* director = CCDirector::sharedDirector();
	CCScene* scene = director->getRunningScene();
	CCLayerGradient* layer = (CCLayerGradient*)scene->getChildByTag(0);
	if (ChangeTextButton::state == 0) {
		CCLabelBMFont* label = (CCLabelBMFont*)layer->getChildByTag(1);
		label->setString("Joe mama! LOL XD");

		ChangeTextButton* btn = (ChangeTextButton*)layer->getChildByTag(3)->getChildByTag(2);
		auto sprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
		btn->setNormalImage(sprite);
		btn->setDisabledImage(sprite);

		btn->stopAllActions();
		btn->setScale(1);

		ChangeTextButton::state = 1;
	}
	else {
		CCLabelBMFont* label = (CCLabelBMFont*)layer->getChildByTag(1);
		label->setString("Who's joe?");

		ChangeTextButton* btn = (ChangeTextButton*)layer->getChildByTag(3)->getChildByTag(2);
		auto sprite = CCSprite::createWithSpriteFrameName("GJ_redoBtn_001.png");
		btn->setNormalImage(sprite);
		btn->setDisabledImage(sprite);

		btn->stopAllActions();
		btn->setScale(1.25);

		ChangeTextButton::state = 0;
	}
}

bool Layer::init() {
	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	this->setTag(0);

	auto label = CCLabelBMFont::create("Who's joe?", "bigFont.fnt");
	label->setPosition(winSize / 2);
	label->setTag(1);

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_redoBtn_001.png");
	auto btn = ChangeTextButton::create(sprite, sprite, this, menu_selector(ChangeTextButton::callback));
	btn->setTag(2);
	btn->setScale(1.25);

	auto btnSize = btn->getScaledContentSize();

	btn->setPositionY(-btnSize.height / 2);
	label->setPositionY((btnSize.height + winSize.height) / 2);
	
	ChangeTextButton::state = 0;

	auto sprite2 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto retnbtn = CCMenuItemSpriteExtra::create(sprite2, sprite2, this, menu_selector(Layer::returnToMenu));

	retnbtn->setPosition((-winSize.width / 2) + 25.0f, (winSize.height / 2) - 25.0f);
	
	auto menu = CCMenu::create();

	menu->setTag(3);

	menu->addChild(btn);
	menu->addChild(retnbtn);
	
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


