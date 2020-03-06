#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "Definitions.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();

    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MainMenuSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("Background.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite);

    auto titleSprite = Sprite::create("Title8X8.png");
        titleSprite->setPosition(Point(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height)));

        this->addChild(titleSprite);

    auto playItem = MenuItemImage::create("PlayButton.png","PlayButtonClicked.png", CC_CALLBACK_1
    (MainMenuScene::GoToGameScene,this));
    playItem->setPosition(Point(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y)));


    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref* sender) {
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


