//
// Created by den on 24.04.17.
//

#include "Plane.hpp"
#include <cmath>
#include "iostream"
#include "Bullet.hpp"

Plane::Plane(float X, float Y, double dx, double dy, int w, int h, std::string name, sf::Image &image, double inRot) :
        Entity(X, Y, dx, dy, w, h, name, image, inRot) ,
        nameWin(name,font,4)

{
    font.loadFromFile("Sansation.ttf");
    isShoot = 0;
//    sf::Text nameWin (name,font,4);
    if (name == "plane1") {
        bullet_name = "bullet1";
    } else if (name == "plane2") {
        sprite.rotate(180);
        bullet_name = "bullet2";
    } else if (name == "plane3"){
        sprite.rotate(-90);
        bullet_name = "bullet3";
    } else if (name == "plane4"){
        sprite.rotate(90);
        bullet_name = "bullet4";
    }
}

void Plane::update(float Time) {
    if (name == "plane1") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            phis(Time);
        }
    } else if (name == "plane2") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            phis(Time);
        }
    } else if (name == "plane3") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            phis(Time);
        }
    } else if (name == "plane4") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
            phis(Time);
        }
    }
    sprite.move ((float) (3 * dx * Time), (float) (3 * dy * Time));

}

void Plane::plusWin(){
    countWin++;
}

void Plane::barier(int MonitorPositionX, int MonitorPositionY) {
    if (sprite.getPosition().x <= 10 && sprite.getPosition().y <= 10)
        sprite.setPosition(10, 10);
    else if (sprite.getPosition().x >= MonitorPositionX - 10 && sprite.getPosition().y <= 10)
        sprite.setPosition(MonitorPositionX - 10, 10);
    else if (sprite.getPosition().x <= 10 && sprite.getPosition().y >= MonitorPositionY - 10)
        sprite.setPosition(10, MonitorPositionY - 10);
    else if (sprite.getPosition().x >= MonitorPositionX - 10 && sprite.getPosition().y >= MonitorPositionY - 10)
        sprite.setPosition(MonitorPositionX - 10, MonitorPositionY - 10);
    else if (sprite.getPosition().x <= 10)
        sprite.setPosition(10, sprite.getPosition().y);
    else if (sprite.getPosition().y <= 10)
        sprite.setPosition(sprite.getPosition().x, 10);
    else if (sprite.getPosition().x >= MonitorPositionX - 10)
        sprite.setPosition(MonitorPositionX - 10, sprite.getPosition().y);
    else if (sprite.getPosition().y >= MonitorPositionY - 10)
        sprite.setPosition(sprite.getPosition().x, MonitorPositionY - 10);
    else if (sprite.getPosition().x >= MonitorPositionX - 10 && sprite.getPosition().y <= 10)
        sprite.setPosition(MonitorPositionX - 10, 10);
    else if (sprite.getPosition().x <= 10 && sprite.getPosition().y >= MonitorPositionY - 10)
        sprite.setPosition(10, MonitorPositionY - 10);
}

void Plane::phis(float Time) {

    sprite.rotate(-3);
    sprite.move((float) (0.25 * (-dx) * Time), (float) (0.25 * (-dy) * Time));
    if (sprite.getRotation() > 0 && sprite.getRotation() < 90) {
        dx = sin(sprite.getRotation() * M_PI / 180); //+
        dy = -cos(sprite.getRotation() * M_PI / 180);//-
    } else if (sprite.getRotation() == 90) {
        dx = 1;
        dy = 0;
    } else if (sprite.getRotation() > 90 && sprite.getRotation() < 180) {
        dx = sin(sprite.getRotation() * M_PI / 180); // +
        dy = -cos(sprite.getRotation() * M_PI / 180); // +
    } else if (sprite.getRotation() == 180) {
        dx = 0;
        dy = 1;
    } else if (sprite.getRotation() > 180 && sprite.getRotation() < 270) {
        dx = sin(sprite.getRotation() * M_PI / 180); // -
        dy = -cos(sprite.getRotation() * M_PI / 180); // +
    } else if (sprite.getRotation() == 270) {
        dx = -1;
        dy = 0;
    } else if (sprite.getRotation() > 270 && sprite.getRotation() < 360) {
        dx = sin(sprite.getRotation() * M_PI / 180); // -
        dy = -cos(sprite.getRotation() * M_PI / 180); // +
    } else if (sprite.getRotation() == 0) {
        dx = 0;
        dy = -1;
    }
}

float Plane::getPosX() {
    return sprite.getPosition().x;
}

float Plane::getPosY() {
    return sprite.getPosition().y;
}

void Plane::inOriginPos(){
    sprite.setPosition(x, y);
    dy = initDy;
    dx = initDx;
    sprite.setRotation(inRot);
};
void Plane::shoot(std::list<Entity *> &entities, sf::Image &image_bullet, sf::Sound &shoot) {
    if (name == "plane1") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isShoot != 0 && life) {
            shoot_phis(entities, image_bullet);
            shoot.play();
        }
    } else if (name == "plane2") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && isShoot != 0 && life) {
            shoot_phis(entities, image_bullet);
            shoot.play();
        }
    } else if (name == "plane3") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && isShoot != 0 && life) {
            shoot_phis(entities, image_bullet);
            shoot.play();
        }
    } else if (name == "plane4") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && isShoot != 0 && life) {
            shoot_phis(entities, image_bullet);
            shoot.play();
        }
    }
}

void Plane::reload() {
    if (shot_time > 40 && isShoot == 0)
        isShoot = 1;
    if (shot_time > 80 && isShoot == 1)
        isShoot = 2;
    if (shot_time > 120 && isShoot == 2) {
        isShoot = 3;
        shot_time = 0;
    }
}

void Plane::shoot_phis(std::list<Entity *> &entities, sf::Image &image_bullet) {
    if (isShoot == 1) {
        entities.push_back(new Bullet(getPosX(), getPosY(), dx, dy, 32, 32, bullet_name, image_bullet));
        isShoot = 0;
        shot_time = 0;
    } else if (isShoot == 2) {
        entities.push_back(new Bullet(getPosX(), getPosY(), dx, dy, 32, 32, bullet_name, image_bullet));
        isShoot = 1;
        shot_time = 40;
    } else if (isShoot == 3) {
        entities.push_back(new Bullet(getPosX(), getPosY(), dx, dy, 32, 32, bullet_name, image_bullet));
        isShoot = 2;
        shot_time = 80;
    }
}

    sf::FloatRect Plane::getRect() {
        return sf::FloatRect(getPosX(), getPosY(), w / 2, h / 2);
    }

