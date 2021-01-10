#include "MenuLayer.h"
#include "Layer.h"
#include "MinHook.h"
#include <Windows.h>

void MenuButton::btnCallback(CCObject* pSender) {
	Layer* l = Layer::create();
}

bool __fastcall MenuLayer::initHook(CCLayer* self) {
	bool result = init(self);

	auto sprite = CCSprite::createWithSpriteFrameName("GJ_backBtn_001.png");

	auto btn = CCMenuItemSpriteExtra::create(sprite, sprite, self, menu_selector(MenuButton::btnCallback));

	btn->setScale(1.1);

	auto children = self->getChildren();

	CCMenu* bottomMenu = (CCMenu*)children->objectAtIndex(3);

	bottomMenu->addChild(btn, 500);

	CCMenuItem* chestBtn = (CCMenuItem*)(bottomMenu->getChildren()->objectAtIndex(4));

	bottomMenu->removeChild(chestBtn, false);
	
	auto menu = CCMenu::createWithItem(chestBtn);

	menu->setPositionY(45);

	bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

	self->addChild(menu, 100);

	return result;
}

void MenuLayer::mem_init() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));
	MH_CreateHook(
		(PVOID)(base + 0x1907b0),
		MenuLayer::initHook,
		(LPVOID*)&MenuLayer::init);
}