/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.cpp
 * Author: juli
 * 
 * Created on 25 de marzo de 2017, 11:47
 */
#include "Bala.h"
#include <stdio.h>
#include <iostream>

Bala::Bala(int x,int y,int velx, int vely, float rangoDisparo) {
    // posicion de inicio de la bal que coincide con jugador
    posx = x;
    posy = y;
    // dirección y velocidad de la bala
    this->velx=velx;
    this->vely=vely;
    this->rangoDisparo = rangoDisparo;
    destruirBala = false;
    
    clock.restart();
    
    if(!textura.loadFromFile("resources/bala.png")){
        std::cerr << "Error while loading texture ISAAC" << std::endl;
        return;
    };
    
    sprite = sf::Sprite(textura);
    sprite.setTextureRect(sf::IntRect(16, 16, 32, 32));
    // fijar centroide
    sprite.setOrigin(16,16); 
    sprite.setScale(0.5,0.5);
    
}

Bala::~Bala() {}

void Bala::setPosicion(int x, int y){     }
void Bala::colisionar(){       }

void Bala::actualiza(){
    posx+=velx;
    posy+=vely;

    if(clock.getElapsedTime().asSeconds()< rangoDisparo){
        sprite.setPosition(posx,posy);  
    }
    else
        destruirBala = true;
    
}
int Bala::getX(){
    return posx;
}

int Bala::getY(){
    return posy;
}


sf::Sprite Bala::getSprite(){
    return sprite;
}

