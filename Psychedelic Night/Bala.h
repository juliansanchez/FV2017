/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.h
 * Author: juli
 *
 * Created on 25 de marzo de 2017, 11:47
 */

#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>

class Bala {
public:
    Bala(int x,int y,int velx, int vely, float rangoDisparo);
    Bala(const Bala& orig);
    ~Bala();
    
    void colisionar();
    void setPosicion(int x, int y);
    void actualiza();
    int getX();
    int getY();
    bool destruirBala = false;
    sf::Sprite getSprite();      
private:    
    int posx;
    int posy;
    int velx;
    int vely;
    float rangoDisparo;
    
    sf::Texture textura;
    sf::Sprite sprite;
    sf::Clock clock; // controlar vida de la bala
};

#endif /* BALA_H */