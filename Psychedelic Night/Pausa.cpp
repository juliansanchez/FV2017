/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pausa.cpp
 * Author: rizado
 * 
 * Created on May 11, 2017, 4:18 PM
 */

#include "Pausa.h"
#include "Motor2D.h"
#include "Nivel.h"
#include "EstadoJugando.h"


Pausa::Pausa(float ancho, float alto) {
    if(!fuente.loadFromFile("resources/upheavtt.ttf")){
       // cerr << "Error cargando la fuente";  
    }
    text[0].setFont(fuente);
    text[0].setColor(sf::Color::Yellow);
    text[0].setString("Continuar");
    text[0].setPosition(sf::Vector2f(ancho/2.6, alto/2.3));
    
    text[1].setFont(fuente);
    text[1].setColor(sf::Color::White);
    text[1].setString("Opciones");
    text[1].setPosition(sf::Vector2f(ancho/2.5, alto/1.8));
    
    text[2].setFont(fuente);
    text[2].setColor(sf::Color::White);
    text[2].setString("Salir menu");
    text[2].setPosition(sf::Vector2f(ancho/2.6, alto/1.5));
    
    EstadoJugando* estjue = EstadoJugando::Instance();
    Nivel* n = estjue->getNiveles();
    
    text[3].setFont(fuente);
    text[3].setColor(sf::Color::Green);
    text[3].setString("SEED: " + n->getSemilla());
    text[3].setCharacterSize(45);
    text[3].setPosition(sf::Vector2f(ancho/3.5, alto/4));

     
     selecionarItem=0;
}

Pausa::Pausa(const Pausa& orig) {
}

Pausa::~Pausa() {
}



void Pausa::Draw(){ 
    Motor2D *motor2D = Motor2D::Instance();
    for(int i=0;i<4;i++){
        motor2D->pintarTexto(text[i]);   
    }
}

void Pausa::MoveUp(){   
    if(selecionarItem-1>=0){
        text[selecionarItem].setColor(sf::Color::White);
        selecionarItem--;
        text[selecionarItem].setColor(sf::Color::Yellow);    
    }
}
    
void Pausa::MoveDown(){   
    if(selecionarItem +1 < 3){
        text[selecionarItem].setColor(sf::Color::White);
        selecionarItem++;
        text[selecionarItem].setColor(sf::Color::Yellow);    
    }
}

