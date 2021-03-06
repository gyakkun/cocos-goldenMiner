#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg_sky = Sprite::create("menu-background-sky.jpg");
	bg_sky->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 150));
	this->addChild(bg_sky, 0);

	auto bg = Sprite::create("menu-background.png");
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 60));
	this->addChild(bg, 0);

	auto miner = Sprite::create("menu-miner.png");
	miner->setPosition(Vec2(150 + origin.x, visibleSize.height / 2 + origin.y - 60));
	this->addChild(miner, 1);

	auto leg = Sprite::createWithSpriteFrameName("miner-leg-0.png");
	Animate* legAnimate = Animate::create(AnimationCache::getInstance()->getAnimation("legAnimation"));
	leg->runAction(RepeatForever::create(legAnimate));
	leg->setPosition(110 + origin.x, origin.y + 102);
	this->addChild(leg, 1);

	auto gameTitle = Sprite::create("gold-miner-text.png");
	gameTitle->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y - 87));
	this->addChild(gameTitle, 1);

	auto startGold = Sprite::create("menu-start-gold.png");
	startGold->setPosition(Vec2(640 + origin.x, 190 + origin.y));
	this->addChild(startGold, 1);

	auto jumpItem = MenuItemImage::create("start-0.png", "start-1.png", CC_CALLBACK_1(MenuScene::startMenuCallback, this));
	auto startBtn = Menu::create(jumpItem, NULL);
	startBtn->setPosition(Vec2(640 + origin.x, 190 + origin.y));
	this->addChild(startBtn, 1);

    return true;
}

//Jump to Gamescene
void MenuScene::startMenuCallback(cocos2d::Ref* pSender) {
	auto gameScene = GameSence::createScene();
	Director::getInstance()->replaceScene(gameScene);
}