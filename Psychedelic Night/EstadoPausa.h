/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoPausa.h
 * Author: drmonkey
 *
 * Created on 11 de mayo de 2017, 11:36
 */

#ifndef ESTADOPAUSA_H
#define ESTADOPAUSA_H

#include "EstadoJuego.h"
#include "Pausa.h"

class EstadoPausa : public EstadoJuego{
public:
    void Init();
    void Limpiar();
    void Pausar();
    void Continuar();
    void ManejarEventos(MotorJuego* juego);
    void Actualizar(MotorJuego* juego);
    void Dibujar(MotorJuego* juego);
    static EstadoPausa* Instance(){
	return &estpausa;
    }

protected:
    EstadoPausa() { }

private:
    static EstadoPausa estpausa;
    Pausa* paus;
    sf::RectangleShape rec;
};

#endif /* ESTADOPAUSA_H */

