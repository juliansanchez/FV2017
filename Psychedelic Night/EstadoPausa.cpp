/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoPausa.cpp
 * Author: drmonkey
 * 
 * Created on 11 de mayo de 2017, 11:36
 */
#include "MotorJuego.h"
#include "EstadoJuego.h"
#include "EstadoPausa.h"
#include "EstadoIntro.h"
#include "Motor2D.h"
#include "EstadoJugando.h"
#include "Vistas.h"
#include "Minimapa.h"
#include "HUD.h"


EstadoPausa EstadoPausa::estpausa;

void EstadoPausa::Init(){
    paus = new Pausa(900, 540);
    printf("EstadoPausa Init\n");
    rec.setFillColor(sf::Color(0,0,0, 200));
}

void EstadoPausa::Limpiar(){
    delete paus;
    printf("Limpieza EstadoPausa\n");
}

void EstadoPausa::Pausar(){
    printf("Pausa EstadoPausa\n");
}

void EstadoPausa::Continuar(){
    printf("Continuar EstadoPausa\n");
}

void EstadoPausa::ManejarEventos(MotorJuego* juego){
    sf::Event event;
    if (juego->ventana->pollEvent(event)){
        if (event.type == sf::Event::Closed) 
            juego->Salir();
        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code){
                case sf::Keyboard::Escape:
                   juego->DesapilarEstado(); 
                break;
                case sf::Keyboard::Up:
                    paus->MoveUp();
                break;
                case sf::Keyboard::Down:
                    paus->MoveDown();
                break;            
                case sf::Keyboard::Space:
                    switch (paus->GetPressedItem()){
                        case 0:
                            juego->DesapilarEstado(); 
                        break;
                        case 1:
                            std::cout<<"has pulsaldo el boton de opciones"<< std::endl;
                        break;
                        case 2:
                            juego->CambiarEstado(EstadoIntro::Instance());
                        break;                            
                    }
                break;
            }           
        }		
    }
}

void EstadoPausa::Actualizar(MotorJuego* juego) {
}

void EstadoPausa::Dibujar(MotorJuego* juego) {
    EstadoJugando* estjue = EstadoJugando::Instance();
    Motor2D* motor2D = Motor2D::Instance();
    motor2D->limpiarVentana();
    Vistas* general = Vistas::Instance();
    juego->ventana->setView(general->getGeneral());
    estjue->getNiveles()->dibujarNivel();
    estjue->getPersonaje()->pintarbalas();
     estjue->getPersonaje()->pintar();
    HUD* hud = HUD::Instance();
    juego->ventana->setView(hud->getHUD());
    hud->dibujar();
    Minimapa* minimapa = Minimapa::Instance();
    juego->ventana->setView(minimapa->getMinimapa());
    minimapa->dibujar();
    juego->ventana->setView(juego->ventana->getDefaultView());
    rec.setSize(juego->ventana->getDefaultView().getSize());
    motor2D->pintarRectShape(rec);
    paus->Draw();
    motor2D->pintarVentana();
}
