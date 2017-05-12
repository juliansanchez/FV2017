/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: rizado
 * 
 * Created on May 9, 2017, 7:02 PM
 */

#include "Menu.h"
#include "Motor2D.h"


Menu::Menu(float ancho, float alto) {
    if(!fuente.loadFromFile("resources/upheavtt.ttf")){
       // cerr << "Error cargando la fuente";    
    }
    

    text[0].setFont(fuente);
    text[0].setFillColor(sf::Color::Yellow);
    text[0].setString("Jugar");
    text[0].setPosition(Vector2f(ancho/2.3, alto/2.3));
    
    text[1].setFont(fuente);
    text[1].setFillColor(sf::Color::White);
    text[1].setString("Opciones");
    text[1].setPosition(Vector2f(ancho/2.5, alto/1.8));
    
    text[2].setFont(fuente);
    text[2].setFillColor(sf::Color::White);
    text[2].setString("Salir Juego");
    text[2].setPosition(Vector2f(ancho/2.6, alto/1.5));
    
    
    
    if (!fondo.loadFromFile("resources/menujuegoOficial.jpg")) {
        exit(0);
    }
    dibujo = new Sprite();
     dibujo->setTexture(fondo);
     dibujo->setPosition(0, 0);
     
     selecionarItem=0;
    
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}


void Menu::Draw(){
   
    Motor2D *motor2D = Motor2D::Instance();
    motor2D->pintarSprites(*dibujo);
    for(int i=0;i<3;i++){
        motor2D->pintarTexto(text[i]);   
    }
}

void Menu::MoveUp(){
    
    if(selecionarItem-1>=0){
        text[selecionarItem].setFillColor(sf::Color::White);
        selecionarItem--;
        text[selecionarItem].setFillColor(sf::Color::Yellow);
    
    }
}
    
void Menu::MoveDown(){
    
    if(selecionarItem +1 < 3){
        text[selecionarItem].setFillColor(sf::Color::White);
        selecionarItem++;
        text[selecionarItem].setFillColor(sf::Color::Yellow);
    
    }
}