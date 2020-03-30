#include "GameObject.h"


GameObject::GameObject(int cXpos, int cYpos, int cWidth,int cHeight, Sprite* cSprite )
{
    xpos= cXpos;
    ypos= cYpos;
    width=cWidth;
    height= cHeight;
    objectSprite = cSprite;
}
