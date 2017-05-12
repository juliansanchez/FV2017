/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vistas.cpp
 * Author: drmonkey
 * 
 * Created on 8 de mayo de 2017, 11:10
 */

#include <SFML/Graphics/View.hpp>

#include "Vistas.h"
#include "Nivel.h"

Vistas* Vistas::instanciaVistas = 0;

Vistas::Vistas() {
    general.setSize(780, 460);    
    general.setViewport(sf::FloatRect(0, 0, 1, 1)); 
    contador = 0;
    movx = 0;
    movy = 0;
}

Vistas::Vistas(const Vistas& orig) {
}

Vistas::~Vistas() {
}

Vistas* Vistas::Instance(){
    if(instanciaVistas == 0)
        instanciaVistas = new Vistas;  
    return instanciaVistas;
}

void Vistas::centrarGeneral(int n){
    general.setCenter(39*20*((n+5)/2)+ 39*20/2, 23*20*((n+5)/2)+ 23*20/2);
}

sf::View Vistas::getGeneral(){
    return general;
}

void Vistas::moverVista(int x, int y){
    movx = x;
    movy = y;
    actualizarVista();
}

void Vistas::actualizarVista(){
    general.move(movx/Division, movy/Division);
    contador++;
    if (contador == Division){
        contador = 0;
    }
}

bool Vistas::getEstado(){
    if (contador == 0)
        return true;
    else
        return false;
}

