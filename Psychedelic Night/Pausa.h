/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pausa.h
 * Author: rizado
 *
 * Created on May 11, 2017, 4:18 PM
 */

#ifndef PAUSA_H
#define PAUSA_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Pausa {
public:
    Pausa(float ancho, float alto);
    Pausa(const Pausa& orig);
    virtual ~Pausa();
    
    void Draw();
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selecionarItem;}
private:
    int selecionarItem;
    sf::Font fuente;
    sf::Text text[4];
};

#endif /* PAUSA_H */




