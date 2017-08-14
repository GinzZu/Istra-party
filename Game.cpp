//
// Created by fedya on 07.05.17.
//

#include "Game.hpp"
#include "Menu.hpp"
#include "Boom.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Plane.hpp"
#include "Bullet.hpp"
#include <vector>
#include <list>

void Game::run() {
    window.create(sf::VideoMode(MonitorPositionX, MonitorPositionY), "Istra Party!!!");
    window.setFramerateLimit(60);

    Music.play();
    Music.setLoop(true);

    sf::Font font;
    font.loadFromFile("Sansation.ttf");
    sf::Text text("Press to F for start game\n ", font, 4);
    sf::Text text2("Winner:\n       Press to Space  ", font, 4);
    sf::Text score("Score", font, 5);
    score.setCharacterSize(20);
    score.setPosition(500, 5);
    text.setCharacterSize(50);
    text.setPosition(300, 350);
    text2.setCharacterSize(50);
    text2.setPosition(200, 450);

    while (Menu::menu(window, countOfPlayers)) {
        restart = true;
        sf::Text *scorePlane = new sf::Text[countOfPlayers];
        for (int i = 0; i < countOfPlayers; i++) {
            scorePlane[i] = sf::Text("Orange", font, 4);
            scorePlane[i].setCharacterSize(20);
            scorePlane[0].setColor(sf::Color::Blue);
            scorePlane[1].setColor(sf::Color::Red);
            if (countOfPlayers > 2)
                scorePlane[2].setColor(sf::Color::Green);
            scorePlane[i].setPosition(490 + 20 * i, 40);
        }
        players.clear();
        entities.clear();
        for (int i = 0; i < countOfPlayers; i++) {
            if (i == 0)
                players.push_back(new Plane(900, 600, 0, -1, 40, 40, "plane1", image_p1, 0));
            if (i == 1)
                players.push_back(new Plane(100, 100, 0, 1, 40, 40, "plane2", image_p2, 180));
            if (i == 2)
                players.push_back(new Plane(900, 100, -1, 0, 40, 40, "plane3", image_p3, -90));
            if (i == 3)
                players.push_back(new Plane(100, 600, 1, 0, 40, 40, "plane4", image_p4, 90));
        }
        rest = countOfPlayers;
        int i = 0;
        for (pl = players.begin(); pl != players.end(); pl++, i++) {
            (*(pl))->countWin = -1;
        }
        while (window.isOpen()) {
            theENd = false;
            Time = clock.getElapsedTime().asMicroseconds();
            Time = Time / 16000;

            for (pl = players.begin(); pl != players.end(); pl++) {
                (*pl)->shot_time += Time;
                (*pl)->reload();
            }

            clock.restart();

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) { //нажимаем на кнопку закрыть
                    window.close();
                }
                for (pl = players.begin(); pl != players.end(); pl++) {
                    (*pl)->shoot(entities, image_bullet, shoot);
                }
            }

            check_players_collision();

            check_bullet_collision();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                break;

            for (pl = players.begin(); pl != players.end(); pl++) {
                (*pl)->update(Time);
                (*pl)->barier(MonitorPositionX, MonitorPositionY);
            }

            check_kills();
            for (it = entities.begin(); it != entities.end();) {
                Entity *b = *it; // Для удобства
                b->update(Time);
                b->barier(MonitorPositionX, MonitorPositionY);
                if (!(b->life)) {
                    it = entities.erase(it);
                    delete b;
                } else
                    it++;

            }

            window.clear(sf::Color::Black);
            window.draw(back);
            if (restart) {
                for (pl = players.begin(); pl != players.end(); pl++) {
                    (*pl)->inOriginPos();
                    if ((*pl)->life)
                        (*pl)->plusWin();
                    else
                        (*pl)->life = true;
                }
                entities.clear();
                rest = countOfPlayers;
                window.clear(sf::Color::Black);
                window.draw(text);
                int i = 0;
                for (pl = players.begin(); pl != players.end(); pl++, i++) {
                    if ((*(pl))->countWin == 2)
                        theENd = true;
                    scorePlane[i].setString(std::to_string((*(pl))->countWin));
                }
                if (theENd) {
                    window.clear(sf::Color::Black);
                    window.draw(text2);
                    for (pl = players.begin(); pl != players.end(); pl++, i++) {
                        if ((*(pl))->countWin == 2) {
                            (*pl)->nameWin.setCharacterSize(50);
                            (*pl)->nameWin.setPosition(550, 450);
                            window.draw((*pl)->nameWin);
                        }
                    }
                    window.display();
                    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { };
                    break;
                }
                window.display();
                while (!sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { };
                clock.restart();
            }
            for (it = entities.begin(); it != entities.end(); it++) {
                window.draw((*it)->sprite);
            }
            for (pl = players.begin(); pl != players.end(); pl++) {
                if ((*pl)->life)
                    window.draw((*pl)->sprite);
            }
            window.draw(score);
            for (int i = 0; i < countOfPlayers; i++)
                window.draw(scorePlane[i]);
            window.display();
            restart = false;

        }
        window.display();
        delete[] scorePlane;

    }
}

Game::Game() :
        Time(0),
        MonitorPositionX(1024),
        MonitorPositionY(720),
        boom(BoomBuffer),
        shoot(shootBuffer),
        restart(true),
        theENd(false)
{

    image_bullet.loadFromFile("bullet.png");
    image_p1.loadFromFile("plane1.png");
    image_p2.loadFromFile("plane2.png");
    image_p3.loadFromFile("plane3.png");
    image_p4.loadFromFile("plane4.png");
    image_boom.loadFromFile("boom.png");

    background.loadFromFile("fon.png");
    texture.loadFromImage(background);
    back.setTexture(texture);

    shootBuffer.loadFromFile("piu.wav");
    BoomBuffer.loadFromFile("boom.wav");
    Music.openFromFile("nintendo.ogg");

}

void Game::check_bullet_collision() {
    for (it = entities.begin(); it != entities.end(); it++) {
        for (auto it2 = entities.begin(); it2 != entities.end(); it2++) {
            if ((*it2)->getRect() == (*it)->getRect()) {
                continue;
            }
            if ((*it)->getRect().intersects((*it2)->getRect()) && (*it)->life && (*it2)->life &&
                (*it2)->name != "Boom") {
                (*it)->life = false;
                (*it2)->life = false;
            }
        }
    }
}

void Game::check_players_collision() {
    for (pl = players.begin(); pl != players.end(); pl++) {
        for (auto pl2 = players.begin(); pl2 != players.end(); pl2++) {
            if ((*pl2)->getRect() == (*pl)->getRect()) {
                continue;
            }
            if ((*pl)->getRect().intersects((*pl2)->getRect()) && (*pl)->life && (*pl2)->life) {
                rest -= 2;

                entities.push_back(
                        new Boom((*pl2)->getPosX() - 20, (*pl2)->getPosY() - 20, 1024, 35, "Boom", image_boom));
                boom.play();
                (*pl)->life = false;
                (*pl2)->life = false;
                if (rest == 1 || rest == 0) {
                        restart = true;
                }
            }
        }
    }
}

void Game::check_kills() {
    for (it = entities.begin(); it != entities.end(); it++) {
        if ((*it)->name != "Boom") {
            int i = 0;
            for (pl = players.begin(); pl != players.end(); pl++) {
                if ((*it)->getRect().intersects((*pl)->getRect()) && (*it)->name != bullets[i] && (*pl)->life) {
                        rest--;
                    entities.push_back(
                            new Boom((*pl)->getPosX() - 20, (*pl)->getPosY() - 20, 1024, 35, "Boom", image_boom));
                    boom.play();
                    (*it)->life = false;
                    (*pl)->life = false;
                    if (rest == 1 || rest == 0) {
                            restart = true;
                    }
                }
                i++;
            }
        }
    }
}