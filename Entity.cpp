//
// Created by den on 07.05.17.
//

#include "Entity.hpp"

Entity::Entity(float X, float Y, double dx, double dy, int w, int h, std::string name, sf::Image &image, double inRot):
        x(X),
        y(Y),
        name(name),
        dx(dx),
        dy(dy),
        initDx(dx),
        initDy(dy),
        life(true),
        w(w),
        h(h),
        inRot(inRot),
        countWin(-1)
{
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    if (name != "Boom") {
        texture.setSmooth(true);
        sprite.setOrigin(sf::Vector2f(w / 2, h / 2));
    }
    sprite.setPosition(X,Y);
}

sf::FloatRect Entity::getRect() {
    return sf::FloatRect(sprite.getPosition().x, sprite.getPosition().y, w / 2, h / 2);
}
