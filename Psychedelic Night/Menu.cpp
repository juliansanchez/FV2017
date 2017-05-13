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
    text = new vector<sf::Text*>;
    
    sf::Text* text0 = new sf::Text;
    text0->setFont(fuente);
    text0->setColor(sf::Color::White);
    text0->setString("Continuar");
    text0->setPosition(Vector2f(ancho/2.5, alto/2.5));
    
    sf::Text* text1 = new sf::Text;
    text1->setFont(fuente);
    text1->setColor(sf::Color::Yellow);
    text1->setString("Nueva partida");
    text1->setPosition(Vector2f(ancho/2.7, alto/2));
    text->push_back(text1);
    
    sf::Text* text2 = new sf::Text;
    text2->setFont(fuente);
    text2->setColor(sf::Color::White);
    text2->setString("Opciones");
    text2->setPosition(Vector2f(ancho/2.5, alto/1.7));
    text->push_back(text2);
    
    sf::Text* text3 = new sf::Text;
    text3->setFont(fuente);
    text3->setColor(sf::Color::White);
    text3->setString("Salir");
    text3->setPosition(Vector2f(ancho/2.4, alto/1.45));
    text->push_back(text3);
    text->push_back(text0);
    
    if (!fondo.loadFromFile("resources/menujuegoOficial.jpg")) {
        exit(0);
    }
    dibujo = new Sprite();
    dibujo->setTexture(fondo);
    dibujo->setPosition(0, 0);
     
    selecionarItem=0;
    act = false;
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
    while (!text->empty()){
        delete text->back();
        text->pop_back();
        text->clear();
    }
    delete text;
}


void Menu::Draw(){  
    Motor2D *motor2D = Motor2D::Instance();
    motor2D->pintarSprites(*dibujo);
    for(int i=0;i<text->size();i++){
        motor2D->pintarTexto(*text->at(i));   
    }
}

void Menu::MoveUp(){   
    if(selecionarItem-1>=0){
        text->at(selecionarItem)->setColor(sf::Color::White);
        selecionarItem--;
        text->at(selecionarItem)->setColor(sf::Color::Yellow);  
    }
}
    
void Menu::MoveDown(){   
    if(selecionarItem < text->size()-1){
        text->at(selecionarItem)->setColor(sf::Color::White);
        selecionarItem++;
        text->at(selecionarItem)->setColor(sf::Color::Yellow);  
    }
}

void Menu::actualizar(int g){
    if (!act && g==1){
        delete text->back();
        text->pop_back();
    }
    act = true;
}