/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HUD.h
 * Author: mrmonkey
 *
 * Created on 9 de mayo de 2017, 23:29
 */

#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;
//INCLUDE DEL PERSONAJE

class HUD {
public:
    static HUD *Instance();
    virtual ~HUD();
    void dibujar();
    sf::View getHUD();
private:
    HUD();
    HUD(const HUD& orig);
    sf::View hud;
    sf::Font fuente;
    sf::Texture texvida;
    vector<sf::Sprite*>* vec;
    static HUD *instanciaHUD;
};

#endif /* HUD_H */

