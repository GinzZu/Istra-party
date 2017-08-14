//
// Created by den on 09.05.17.
//

#include <iostream>
#include "Boom.hpp"

Boom::Boom(float x, float y, int w, int h, std::string name, sf::Image &image) :
        Entity(x,y,0,0,w,h,name,image,0)
{
    CurrentFrame = 0;
    sprite.setScale(1.1,1.1);
    sprite.setTextureRect(sf::IntRect(0,0,35,35));

}

void Boom::update(float Time) {
    CurrentFrame +=  0.25 * Time;
    sprite.setTextureRect(sf::IntRect(35 * int(CurrentFrame),0,35,35));
    if(CurrentFrame > 20)
        life = false;
}

