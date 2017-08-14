//
// Created by fedya on 07.05.17.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Plane.hpp"
#include <list>

#ifndef GAME3_GAME_HPP
#define GAME3_GAME_HPP


class Game {
public:
    void run();
    Game();

private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Image image_p1;
    sf::Image image_p2;
    sf::Image image_p3;
    sf::Image image_p4;
    sf::Image image_bullet;
    sf::Image image_boom;
    sf::Image background;
    sf::SoundBuffer shootBuffer, BoomBuffer;
    sf::Music Music;
    sf::Sound boom;
    sf::Sound shoot;
    sf::Event event;
    sf::Texture texture;
    sf::Sprite back;
    std::list<Entity*> entities;
    std::list<Entity*>::iterator it;
    std::list<Plane*> players;
    std::list<Plane*>::iterator pl;
    int countOfPlayers;
    bool restart;
    bool theENd;
    float Time;
    int rest;

    std::string bullets[4] = {"bullet1", "bullet2",
                              "bullet3", "bullet4"};
    unsigned int MonitorPositionX;
    unsigned int MonitorPositionY;
    void check_bullet_collision();
    void check_players_collision();
    void check_kills();

};


#endif //GAME3_GAME_HPP
