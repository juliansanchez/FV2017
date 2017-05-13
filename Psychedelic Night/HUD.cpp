/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HUD.cpp
 * Author: mrmonkey
 * 
 * Created on 9 de mayo de 2017, 23:29
 */

#include "HUD.h"
#include "Motor2D.h"
#include "EstadoJugando.h"

HUD* HUD::instanciaHUD = 0;

HUD::HUD() {
    hud.setViewport(sf::FloatRect(0.f, 0.f, 0.25f, 0.25f));   
    if (!fuente.loadFromFile("resources/game_over.ttf")){
        std::cerr << "Error cargando la fuente";
    }
    
    /*sf::Text ganada;
    ganada.setString("HAS GANADO");
    ganada.setFont(fuente);
    ganada.setFillColor(sf::Color::White);
    ganada.setCharacterSize(30);*/
    
    if (!texvida.loadFromFile("resources/vida.png"))
    {
        std::cerr << "Error cargando la imagen vida.png";
    }       
    vec = new vector<sf::Sprite*>;    
}

HUD::HUD(const HUD& orig) {
}

HUD::~HUD() {
    while (!vec->empty()){
        delete vec->back();
        vec->pop_back();
        vec->clear();
    } 
    delete vec;
}

HUD* HUD::Instance(){
    if(instanciaHUD == 0)
        instanciaHUD = new HUD;  
    return instanciaHUD;
}

void HUD::dibujar(){
    Motor2D*motor2D = Motor2D::Instance();
    EstadoJugando* estjue = EstadoJugando::Instance();
    int vidaact = estjue->getPersonaje()->getVidaActual()/1;
    float medvida = fmodf(estjue->getPersonaje()->getVidaActual(), 1);
    while (!vec->empty()){
        delete vec->back();
        vec->pop_back();
        vec->clear();
    } 
    for (int i = 0; i<estjue->getPersonaje()->getVida(); i++){
        if (i<vidaact){
            sf::Sprite* vida = new sf::Sprite(texvida);
            vida->setOrigin(15/2, 15/2);
            vida->setTextureRect(sf::IntRect(0, 0, 15, 15));
            vida->setPosition(15*12 + 15*i*12, 15*14);
            vida->setScale(12,14);
            vec->push_back(vida);
            motor2D->pintarSprites(*vida);
        }
        else if (medvida!=0){
            sf::Sprite* mediavida = new sf::Sprite(texvida);
            mediavida->setOrigin(15/2, 15/2);
            mediavida->setTextureRect(sf::IntRect(15, 0, 15, 15));
            mediavida->setPosition(15*12 + 15*i*12, 15*14);
            mediavida->setScale(12,14);
            vec->push_back(mediavida);
            medvida = 0;
            motor2D->pintarSprites(*mediavida);
        }
        else{
            sf::Sprite* vidavacia = new sf::Sprite(texvida);
            vidavacia->setOrigin(15/2,15/2);
            vidavacia->setTextureRect(sf::IntRect(30, 0, 15, 15));
            vidavacia->setPosition(15*12 + 15*i*12, 15*14);
            vidavacia->setScale(12,14);
            vec->push_back(vidavacia);
            motor2D->pintarSprites(*vidavacia);
        }
    }
}

sf::View HUD::getHUD(){
    return hud;
}

