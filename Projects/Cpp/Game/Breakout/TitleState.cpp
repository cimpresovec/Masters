#include "TitleState.h"
#include "AssetManager.h"
#include <raylib.h>
#include "easings.h"

TitleState::TitleState()
{

}

void TitleState::handleEvents()
{
    int lastKeyPress = GetKeyPressed();
    if (lastKeyPress != -1) changeGameState(STATE_MAINMENU);
}

void TitleState::handleLogic(float deltaTime)
{
    //Simple fading animation
    timer += deltaTime;
    if (timer < 1)
    {
        alpha = EaseSineInOut(timer, 0, 255, 1);
    }
    else if (timer < 3)
    {
        alpha = EaseSineInOut(timer - 1, 255, -255, 2);
    }
    else
    {
        changeGameState(STATE_MAINMENU);
    }
}

void TitleState::handleRendering()
{
    DrawTexture(AssetManager::getInstance().getTexture("logo"),
                1280 / 2 - AssetManager::getInstance().getRectangle("logo").width / 2,
                720 / 2 - AssetManager::getInstance().getRectangle("logo").height / 2,
                Color{255, 255, 255, u_char(alpha)});
}
