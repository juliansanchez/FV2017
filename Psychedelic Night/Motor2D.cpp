/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.cpp
 * Author: juli
 * 
 * Created on 25 de abril de 2017, 9:54
 */

#include "Motor2D.h"
using namespace std;

// declaramos instancia para el motor
Motor2D* Motor2D::instanciaMotor = 0;

Motor2D::Motor2D() {}

// nuevo cons que crea una instancia de la clase motor
Motor2D* Motor2D::Instance(){ 
    
    if(instanciaMotor == 0){
        instanciaMotor = new Motor2D;
    }
   
    return instanciaMotor;
}
void Motor2D::setWindow(sf::RenderWindow *ventana){
    this->ventana = ventana;
    
    
}

void Motor2D::pintarVentana(){
    
    ventana->display();
}

void Motor2D::pintarSprites(sf::Sprite sprite){
    
    ventana->draw(sprite);    
}

void Motor2D::pintarRectShape(sf::RectangleShape shape){
    ventana->draw(shape);
}

void Motor2D::pintarTexto(sf::Text texto){
    ventana->draw(texto);
}

void Motor2D::limpiarVentana(){
    ventana->clear(sf::Color(0,127,127));
}

