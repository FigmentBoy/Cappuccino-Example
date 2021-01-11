#include "MenuLayer.h"
#include "Layer.h"
#include "MinHook.h"
#include <Windows.h>

void MoveToNewLayerBtn::callback(CCObject* pSender) {
	Layer* layer = Layer::create();
	CCMenuItemSpriteExtra* btn = (CCMenuItemSpriteExtra*)pSender;
	btn->stopAllActions();
	btn->setScale(1.1);
}

bool __fastcall MenuLayer::initHook(CCLayer* self) {
	

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_backBtn_001.png");

	auto btn = MoveToNewLayerBtn::create(sprite, sprite, self, menu_selector(MoveToNewLayerBtn::callback));

	btn->setScale(1.1);

	bool result = init(self);

	auto children = self->getChildren();

	CCMenu* bottomMenu = (CCMenu*)children->objectAtIndex(3);

	bottomMenu->addChild(btn, 500);

	CCMenuItem* chestBtn = (CCMenuItem*)(bottomMenu->getChildren()->objectAtIndex(4));

	bottomMenu->removeChild(chestBtn, false);
	
	bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

	bottomMenu->addChild(chestBtn);

	return result;
}

void MenuLayer::mem_init() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));
	MH_CreateHook(
		(PVOID)(base + 0x1907b0),
		MenuLayer::initHook,
		(LPVOID*)&MenuLayer::init);
}