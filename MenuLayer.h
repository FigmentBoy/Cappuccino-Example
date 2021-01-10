#pragma once
#include <cocos2d.h>
#include "MinHook.h"

using namespace cocos2d;
namespace MenuLayer {
    inline bool(__thiscall* init)(CCLayer* self);
    bool __fastcall initHook(CCLayer* self);

    CCLayer* create();

    void mem_init();
}

class MenuButton {
public:
    void btnCallback(CCObject* pSender);
};