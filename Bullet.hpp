//
// Created by den on 07.05.17.
//

#ifndef GAME_BULLET_HPP
#define GAME_BULLET_HPP


#include "Entity.hpp"
#include "Plane.hpp"

class Bullet : public Entity {
public:
    Bullet(float X, float Y, float dx, float dy, int w, int h, std::string name, sf::Image &image);

    void update(float Time) override;

    void barier(int MonitorPositionX, int MonitorPositionY) override;

};


#endif //GAME_BULLET_HPP
