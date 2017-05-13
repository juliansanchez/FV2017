/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boss.cpp
 * Author: rizado
 * 
 * Created on May 13, 2017, 4:08 PM
 */

#include "Boss.h"

Boss::Boss(int posX, int posY) {
    this->posMatrix_x= posX;
    this->posMatrix_y=posY;
    
    Texture *textura3;
    textura3 = new Texture();
    if (!textura3->loadFromFile("resources/boss.png")) {
        cerr << "Error cargando la imagen";
        exit(0);
    }
    SpriteGame c(*textura3,14,67,65,129);
    SpriteGame c1(*textura3,89,152,9,60);
    SpriteGame c2(*textura3,6,73,9,60);
    SpriteGame c3(*textura3,86,155,71,125);

    this->enemigo=new Sprite*[4];
    for(int i=0; i<4;i++){
        this->enemigo[i]= new Sprite ();
     }
    *this->enemigo[0]=c.GetSprite();
    *this->enemigo[1]=c1.GetSprite();
    *this->enemigo[2]=c2.GetSprite();
    *this->enemigo[3]=c3.GetSprite();
    
    for(int i=0; i<4;i++){
        this->enemigo[i]->setScale(3.5,3.5);
     }

    this->num_sprites=4;
    this->numCambio=16;
    this->cambio_sprite=0;   
    this->dispara=0;
    this->rangoDisparo = 1;
    contador_vueltas=0;
    retraso=0;
    retraso2=7;
    balas= new std::vector<Bala*>;
    bicho=new std::vector<NPC*>;
    
}

Boss::Boss(const Boss& orig) {
}

Boss::~Boss() {
}

int Boss::getPosMatrix_x(){
    return this->posMatrix_x;
}

int Boss::getPosMatrix_y(){
    return this->posMatrix_y;
    
}

float Boss::getX(){
    return enemigo[cambio_sprite]->getPosition().x;
}

float Boss::getY(){
    return enemigo[cambio_sprite]->getPosition().y;  
}

void Boss::dibujarBoss(){
    Motor2D *motor2D = Motor2D::Instance();
    motor2D->pintarSprites(*this->enemigo[cambio_sprite]);
    for(int i = 0 ; i<balas->size(); i++){
        if(balas->at(i)){
           motor2D->pintarSprites(balas->at(i)->getSprite());
         }
    }
    for(int i = 0 ; i<bicho->size(); i++){
        if(bicho->at(i)){
           bicho->at(i)->dibujarEnemigo();
         }
    }
}


void Boss::movBoss(Clock clock2, Time tiempo){
    
    float direcx =  12+static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2));
    float direcy =  12+static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2));
    float signox =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    float signoy =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    if (signox >= 0.5)
        signox = signox * (-1);
    if (signoy >= 0.5)
        signoy = signoy * (-1);
    
    if(contador_vueltas%this->numCambio==0){
        cambio_sprite=(cambio_sprite+1)%(this->num_sprites-2);
        for(int i=0; i<4;i++){
            this->enemigo[i]->move(signox*25,signoy*25);
        }
        
        if(retraso==7){
            cambio_sprite=2;
            for(int i=0;i<2;i++){
                balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,signox*direcx,signoy*direcy,rangoDisparo));
                balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,signoy*direcy,signox* direcx,rangoDisparo));
                balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,-signox*direcx,-signoy*direcy,rangoDisparo));
                balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,-signoy*direcy,-signox* direcx,rangoDisparo));
                
                if (signox <0){
                    signox = 1;
                }else{
                    signox = -1;
                }
                if (signoy < 0){
                    signoy =1;
                }else{
                    signox = -1;
                }
                dispara++;
            }
            retraso=0;
        }
        if(retraso2==18){
            cambio_sprite=3;
            for(int i=0;i<3;i++){
                bicho->push_back(new NPC(13,3,3));
            }
            for(int i = bicho->size()-3 ; i<bicho->size(); i++){
                if(bicho->at(i)){
                    bicho->at(i)->posicionAleatoria();                      
                }   
            }
            retraso2=0;
        }
        retraso++;
        retraso2++;
    } 
    this->ActualizarDisparo();
    for(int i = 0 ; i<bicho->size(); i++){
        if(bicho->at(i)){
            bicho->at(i)->nextSprite(contador_vueltas); 
            bicho->at(i)->movMosquito();                      
        }   
    }
    contador_vueltas++;
}


void Boss::ActualizarDisparo(){
    
        // actualizo posicion de la bala
        for(int i = 0 ; i<balas->size(); i++){
            if(balas->at(i)){
                balas->at(i)->actualiza(); // actualizo posicion de la bala
                if(balas->at(i)->destruirBala){
                    delete balas->at(i); // borramos la bala del vector
                    balas->erase(balas->begin()+i); // libero memoria de pos del vector
                }        
            }
        }

}