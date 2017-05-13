/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boss.h
 * Author: rizado
 *
 * Created on May 13, 2017, 4:07 PM
 */

#ifndef BOSS_H
#define BOSS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "SpriteGame.h"
#include "Motor2D.h"
#include "Bala.h"
#include "NPC.h"

using namespace std;
using namespace sf;

class Boss {
public:
    Boss(int posX, int posY);
    Boss(const Boss& orig);
    virtual ~Boss();
    
    void nextSprite(int contadorVueltas);
    void dibujarBoss();
    float getX();
    float getY();
    void movBoss(Clock clock2,Time tiempo);
    void DisparoEnemigo(Clock clockbala);
    void ActualizarDisparo();

    void pintarDisparo();


    int getPosMatrix_x();
    int getPosMatrix_y();
private:
    int tipo;
    int vida;
    int velocidad;
    SpriteGame **enemy;
    Sprite **enemigo;
    int num_sprites;
    int cambio_sprite;
    int numCambio;
    
    float angle;
    int retraso;
    int retraso2;
    
    vector <Bala*>* balas;
    vector <NPC*>* bicho;
    int dispara;
    float rangoDisparo ; 
    
    int posMatrix_x;
    int posMatrix_y;
    
    int contador_vueltas;

};

#endif /* BOSS_H */

