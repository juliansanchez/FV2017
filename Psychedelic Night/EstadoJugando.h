/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoJugando.h
 * Author: drmonkey
 *
 * Created on 11 de mayo de 2017, 10:42
 */

#ifndef ESTADOJUGANDO_H
#define ESTADOJUGANDO_H

#include "EstadoJuego.h"
#include "Nivel.h"
#include "Jugador.h"

class EstadoJugando : public EstadoJuego {
public:
    //static EstadoJugando *Instance();
    void Init();
    void Limpiar();
    void Pausar();
    void Continuar();
    void ManejarEventos(MotorJuego* juego);
    void Actualizar(MotorJuego* juego);
    void Dibujar(MotorJuego* juego);
    
    static EstadoJugando* Instance(){
	return &estjugando;
    }
    Nivel* getNiveles();
    Jugador* getPersonaje();

protected:
    EstadoJugando() { }

private:
    //static EstadoJugando *instanciaEstadoJugando;
    static EstadoJugando estjugando;
    Nivel* niveles;
    Jugador* personaje;
    sf::Clock reloj; 
    sf::Clock relojSprite;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Time timeStartUpdate;
    sf::Time tiempo;
};

#endif /* ESTADOJUGANDO_H */

