/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Modificador.cpp
 * Author: borja
 * 
 * Created on 1 de mayo de 2017, 11:48
 */

#include "Modificador.h"

using namespace std;
Modificador::Modificador(int x, int y, int tipo) {
    
    if(tipo == 1 && texture.loadFromFile("resources/seta.png")){
        cout<<"es una seta"<<endl;
        this->tipo=tipo;
    }
    
    if(tipo == 2 && texture.loadFromFile("resources/jeringa.png")){
        cout<<"es una seta"<<endl;
        this->tipo=tipo;
    }
    colision = false;
    tamSprite = 32;
    radioSprite = tamSprite/2;
    escala=1.5;
    
    this->x= x;
    this->y = y;
    
    modificador.setTexture(texture);
    modificador.setOrigin(tamSprite/2,tamSprite/2);
    modificador.setTextureRect(sf:: IntRect(0*tamSprite, 0*tamSprite, tamSprite, tamSprite));  
    modificador.setPosition(x, y);   
    modificador.setScale(escala,escala); 
    
}

// contructor por sobrecarga para la bomba
Modificador::Modificador(int x, int y, sf::Clock relojBomba) {
    colision = false;
    tamSprite = 32;
    radioSprite = tamSprite/2;
    escala=1.5;
    
    this->x= x;
    this->y = y;
 
    if (!texture.loadFromFile("resources/bomba.png"))
    {
        std::cerr << "Error while loading texture modificador" << std::endl;
    }
    
    modificador.setTexture(texture);
    modificador.setOrigin(tamSprite/2,tamSprite/2);
    modificador.setTextureRect(sf:: IntRect(0*tamSprite, 0*tamSprite, tamSprite, tamSprite));  
    modificador.setPosition(x, y);   
    modificador.setScale(escala,escala); 
    
}


Modificador::Modificador(const Modificador& orig) {
    
}

Modificador::~Modificador() {
    
}


void Modificador::Modificacion(Jugador* j){
    /*if(colision de hitbox){
        int num=rand()%2;
        switch (num){
                case '0': {;
                    int numero1=rand()%3;
                    j->CambiarAtaque(numero1);
                    break;
                }  
                case '1': {;
                    int numero2=rand()%3;
                    j->CambiarSpeed(numero2);  
                    break;
                }
        }
        //destruir Objeto
    //}*/
    // pintar();
}

void Modificador::pintar(){
    Motor2D*motor2D = Motor2D::Instance();
    motor2D->pintarSprites(modificador);
   
}

// colisiones con volumenes Bounding
// si cojo la seta aumento danyo en 1
void Modificador::colisionObjeto(Jugador *j){
     
    if(!colision && (j->getX()+ 32) > this->x && (j->getY()+ 42) > this->y &&
            (this->x +32)> j->getX() && (this->y+32) > j->getY()){
            cout<<"Entro a colision"<<endl;
            colision=true;
          
            if(tipo == 1){
                j->aumentarDanyo();
            }
            
            if(tipo == 2){
                j->aumentarVida();
                j->aumentarVidaActual();
            }
            
            // Esto es una chapuza, hay que eliminar el objeto
            modificador.setTextureRect(sf:: IntRect(0*tamSprite, 0*tamSprite, 0, 0)); 
            modificador.setPosition(0, 0);
    }

}

// colisiones con volumenes Bounding
void Modificador::cogerBomba(Jugador *j){
    
    if(!colision && (j->getX()+ 32) > this->x && (j->getY()+ 42) > this->y &&
            (this->x +32)> j->getX() && (this->y+32) > j->getY()){
            cout<<"Cojo la bomba"<<endl;
            colision=true;
                       
            j->anyadirBomba();
            // Esto es una chapuza, hay que eliminar el objeto
            modificador.setTextureRect(sf:: IntRect(0*tamSprite, 0*tamSprite, 0, 0)); 
            modificador.setPosition(0, 0);
     
    }

}