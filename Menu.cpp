//
// Created by fedya on 09.05.17.
//

#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Plane.hpp"

using namespace sf;
bool Menu::menu(sf::RenderWindow &window, int &countPlayers) {
    Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuBackground;
    menuTexture1.loadFromFile("111.png");
    menuTexture2.loadFromFile("222.png");
    menuTexture3.loadFromFile("333.png");
    menuTexture4.loadFromFile("444.png");
    menuBackground.loadFromFile("Plane.png");
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),menu4(menuTexture4), menuBg(
            menuBackground);

    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(450, 300);
    menu2.setPosition(450, 350);
    menu3.setPosition(450, 400);
    menu4.setPosition(450, 450);
    menuBg.setPosition(0, 0);

    while (isMenu) {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menu4.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(450, 300, 300, 50).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Blue);
            menuNum = 1;
        }
        if (IntRect(450, 350, 300, 50).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color::Blue);
            menuNum = 2;
        }
        if (IntRect(450, 400, 300, 50).contains(Mouse::getPosition(window))) {
            menu3.setColor(Color::Blue);
            menuNum = 3;
        }
        if (IntRect(450, 450, 300, 50).contains(Mouse::getPosition(window))) {
            menu4.setColor(Color::Blue);
            menuNum = 4;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                countPlayers = 2;
                 isMenu = false;
                    return true;
            }
            if (menuNum == 2) {
                countPlayers = 3;
                    isMenu = false;
                    return true;
            }
            if (menuNum == 3) {
                countPlayers = 4;
                isMenu = false;
                return true;
            }
            if (menuNum == 4) {
                window.close();
                isMenu = false;
                return false;
            }


        }
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);

        window.display();
    }
}

