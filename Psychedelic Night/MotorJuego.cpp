/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MotorJuego.cpp
 * Author: mrmonkey
 * 
 * Created on 10 de mayo de 2017, 12:46
 */

#include "MotorJuego.h"
#include "EstadoJuego.h"
#include "Motor2D.h"


void MotorJuego::Init(const char* titulo, int ancho, int alto, int bpp){   
    ventana = new sf::RenderWindow(sf::VideoMode(ancho, alto, bpp), titulo, sf::Style::Titlebar | sf::Style::Close);
    ventana->setVerticalSyncEnabled (true);
    ventana->setFramerateLimit(60);
    ventana->setKeyRepeatEnabled(false);
    Motor2D*motor2D = Motor2D::Instance();
    motor2D->setWindow(ventana);
    activo = true;
    printf("Inicio MotorJuego\n");
}

void MotorJuego::Limpiar(){
    while (!estados.empty()){
	estados.back()->Limpiar();
	estados.pop_back();
    }
    printf("Limpieza MotorJuego\n");
    ventana->close();
}

void MotorJuego::CambiarEstado(EstadoJuego* estado){
    if (!estados.empty()){
        estados.back()->Limpiar();
	estados.pop_back();
    }
    estados.push_back(estado);
    estados.back()->Init();
}

void MotorJuego::ApilarEstado(EstadoJuego* estado){
    if (!estados.empty())
	estados.back()->Pausar();   
    estados.push_back(estado);
    estados.back()->Init();
}

void MotorJuego::DesapilarEstado(){
    if (!estados.empty()){
	estados.back()->Limpiar();
	estados.pop_back();
    }
    if (!estados.empty())
	estados.back()->Continuar();    
}

void MotorJuego::ManejarEventos(){
    estados.back()->ManejarEventos(this);
}

void MotorJuego::Actualizar(){
    estados.back()->Actualizar(this);
}

void MotorJuego::Dibujar() {
    estados.back()->Dibujar(this);
}

int MotorJuego::getTam(){
    return estados.size();
}

void MotorJuego::Reiniciar(EstadoJuego* estado){
    while (!estados.empty()){
	estados.back()->Limpiar();
	estados.pop_back();
    }
    estados.push_back(estado);
    estados.back()->Init();
}
