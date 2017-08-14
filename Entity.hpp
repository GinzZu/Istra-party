//
// Created by den on 07.05.17.
//

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP


#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Entity {
public:
    double y; //Начальное положение
    double x; // Начальное положение
    double dy; // Скорость
    double dx; // Скорость
    double initDx, initDy;
    double inRot;
    int countWin;
    float CurrentFrame;
    int w,h;
    std::string name;
    bool life;
    sf::Texture texture;
    sf::Sprite sprite;
    Entity(float X, float Y, double dx, double dy, int w, int h, std::string name, sf::Image &image, double);
    virtual void update(float Time) {};
    virtual void barier(int MonitorPositionX, int MonitorPositionY) {};
    sf::FloatRect getRect();

};


#endif //GAME_ENTITY_HPP
