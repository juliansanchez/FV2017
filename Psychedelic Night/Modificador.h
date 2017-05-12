/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Modificador.h
 * Author: borja
 *
 * Created on 1 de mayo de 2017, 11:47
 */
#include <SFML/Graphics.hpp>
#include "Motor2D.h"
#include <iostream>
#include <vector>
#include "Jugador.h"

#ifndef MODIFICADOR_H
#define MODIFICADOR_H

class Modificador {
public:
    Modificador(int x, int y, int tipo);
    Modificador(int x, int y, sf::Clock relojBomba); // segundo constructor
    Modificador(const Modificador& orig);
    virtual ~Modificador();
    void Modificacion(Jugador* j);
    void pintar();
    void colisionObjeto(Jugador *j);
    void cogerBomba(Jugador *j);
    
    
private:
    int tamSprite;
    int radioSprite;
    int x; //POSX
    int y;//POSY
    bool colision;
    int tipo;
    
    float escala;
    
    sf::Sprite modificador;
    sf::Texture texture;
    sf::Rect<float> hitbox;

    
};

#endif /* MODIFICADOR_H */

