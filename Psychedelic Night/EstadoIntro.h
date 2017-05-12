/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoIntro.h
 * Author: mrmonkey
 *
 * Created on 10 de mayo de 2017, 13:20
 */

#ifndef ESTADOINTRO_H
#define ESTADOINTRO_H
#include <SFML/Audio.hpp>
#include "EstadoJuego.h"
#include "Menu.h"

class EstadoIntro : public EstadoJuego{
public:
    void Init();
    void Limpiar();
    void Pausar();
    void Continuar();
    void ManejarEventos(MotorJuego* juego);
    void Actualizar(MotorJuego* juego);
    void Dibujar(MotorJuego* Juego);
    static EstadoIntro* Instance() {
	return &estintro;
    }

protected:
    EstadoIntro(){}
private:
    static EstadoIntro estintro;
    Menu* menu;
    sf::Music music;
    sf::SoundBuffer efecto_click;
    sf::SoundBuffer efecto_paso;
    sf::Sound aceptar;
    sf::Sound pasar;
};

#endif /* ESTADOINTRO_H */

