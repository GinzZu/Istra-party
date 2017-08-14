//
// Created by den on 09.05.17.
//

#ifndef GAME_BOOM_HPP
#define GAME_BOOM_HPP


#include "Entity.hpp"

class Boom : public Entity{
private:
    float CurrentFrame;
public:
    Boom(float x, float y, int w, int h, std::string name, sf::Image &image);
    void update(float Time);
};


#endif //GAME_BOOM_HPP
