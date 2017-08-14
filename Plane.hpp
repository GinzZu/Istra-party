//
// Created by den on 24.04.17.
//

#ifndef ISTRAPARTY_PLANE_HPP
#define ISTRAPARTY_PLANE_HPP

#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <list>
#include <SFML/Audio/Sound.hpp>

class Plane : public Entity {
public:

    Plane(float x, float y, double dx, double dy, int w, int h, std::string F, sf::Image &image, double);

    void update(float Time) override; // Запуск полета самолета

    void barier(int MonitorPositionX, int MonitorPositionY) override; // Не вылетает за границы экрана

    float getPosX();

    float getPosY();

    unsigned int isShoot;

    float shot_time;

    void plusWin();

    void shoot(std::list<Entity*> &entities, sf::Image &image_bullet, sf::Sound &shoot);

    void reload();

    sf::FloatRect getRect();

    void inOriginPos();

  sf::Text nameWin;
    sf::Font font;


private:
    std::string bullet_name;
    void shoot_phis(std::list<Entity*> &entities, sf::Image &image_bullet);
    void phis(float Time);
};


#endif //ISTRAPARTY_PLANE_HPP
