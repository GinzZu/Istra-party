//
// Created by den on 07.05.17.
//

#include <iostream>
#include "Bullet.hpp"

Bullet::Bullet(float X, float Y, float dx, float dy, int w, int h, std::string name, sf::Image &image) :
 Entity(X,Y,dx,dy,w,h,name,image, 0)
{
        sprite.setScale(0.5,0.5);
}

void Bullet::update(float Time) {
    sprite.move ((float) (7 * dx * Time), (float) (7 * dy * Time));
}

void Bullet::barier(int MonitorPositionX, int MonitorPositionY) {
    if(sprite.getPosition().x <= 0 && sprite.getPosition().y <= 0)
        life = false;
    else if (sprite.getPosition().x >= MonitorPositionX - 0 && sprite.getPosition().y <= 0)
        life = false;
    else if (sprite.getPosition().x <= 0 && sprite.getPosition().y >= MonitorPositionY - 0)
        life = false;
    else if (sprite.getPosition().x >= MonitorPositionX - 0 && sprite.getPosition().y >= MonitorPositionY - 0)
        life = false;
    else if (sprite.getPosition().x <= 0)
        life = false;
    else if (sprite.getPosition().y <= 0)
        life = false;
    else if (sprite.getPosition().x >= MonitorPositionX - 0)
        life = false;
    else if (sprite.getPosition().y >= MonitorPositionY - 0)
        life = false;
    else if (sprite.getPosition().x >= MonitorPositionX - 0 && sprite.getPosition().y <= 0)
        life = false;
    else if (sprite.getPosition().x <= 0 && sprite.getPosition().y >= MonitorPositionY - 0)
        life = false;
}

