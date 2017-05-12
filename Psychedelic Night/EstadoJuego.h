/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoJuego.h
 * Author: mrmonkey
 *
 * Created on 10 de mayo de 2017, 12:48
 */

#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H

#include "MotorJuego.h"

class EstadoJuego {
public:
    virtual void Init() = 0;
    virtual void Limpiar() = 0;
    virtual void Pausar() = 0;
    virtual void Continuar() = 0;
    virtual void ManejarEventos(MotorJuego* juego) = 0;
    virtual void Actualizar(MotorJuego* juego) = 0;
    virtual void Dibujar(MotorJuego* juego) = 0;
    void CambiarEstado(MotorJuego* juego, EstadoJuego* estado) {
	juego->CambiarEstado(estado);
    }

protected:
    EstadoJuego() { }
};


#endif /* ESTADOJUEGO_H */

