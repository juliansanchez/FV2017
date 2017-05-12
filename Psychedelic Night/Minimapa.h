/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Minimapa.h
 * Author: drmonkey
 *
 * Created on 9 de mayo de 2017, 14:40
 */

#ifndef MINIMAPA_H
#define MINIMAPA_H
#include "Motor2D.h"
#include "Nivel.h"

using namespace std;

class Minimapa {
public:
    static Minimapa *Instance();
    virtual ~Minimapa();
    sf::View getMinimapa();
    void dibujar();
private:
    Minimapa();
    Minimapa(const Minimapa& orig);
    sf::View minimapa;
    sf::RectangleShape rec;
    vector<sf::RectangleShape*>* vec;
    static Minimapa *instanciaMinimapa;
};

#endif /* MINIMAPA_H */

