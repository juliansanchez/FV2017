/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpriteGame.cpp
 * Author: rizado
 * 
 * Created on April 26, 2017, 5:10 PM
 */


#include "SpriteGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace sf;
using namespace std;

SpriteGame::SpriteGame(Texture &tex,int xi, int xf, int yi, int yf) {
    this->inicio.x = xi;
    this->inicio.y = yi;
    this->fin.x = xf;
    this->fin.y = yf;
    
    dibujo = new Sprite();
    dibujo->setTexture(tex);

    this->dimension.x = this->fin.x - this->inicio.x;
    this->dimension.y = this->fin.y - this->inicio.y;

    this->centro.x = this->dimension.x / 2;
    this->centro.y = this->dimension.y / 2;


    Init();
   
      
}

void SpriteGame::Init() {
    

    int initX =200;
    int initY =300;
    
    
    //Centroide
    this->dibujo->setOrigin(this->centro.x, this->centro.y);
    
    //Cojo el sprite que me interesa por defecto del sheet
    IntRect palaRect = IntRect(this->inicio.x, this->inicio.y, this->dimension.x, this->dimension.y);
    dibujo->setTextureRect(palaRect);

    // Colocar el sprite en la pantalla
    this->dibujo->setPosition(initX, initY);
    
}



Sprite SpriteGame::GetSprite(){
    return *dibujo;
}


void SpriteGame::Mover(float x, float y){
    //v=e/t---> e=v*t
    dibujo->move(x,y);
}

void SpriteGame::Espejo(){
    dibujo->scale(-1,1);
}


float SpriteGame::getAncho(){
    return dimension.x;
}
float SpriteGame::getAlto(){
    return dimension.y;
}




SpriteGame::SpriteGame(const SpriteGame& orig) {
}

SpriteGame::~SpriteGame() {
}

