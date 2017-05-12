/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mrmonkey
 *
 * Created on 10 de mayo de 2017, 12:32
 */

#include <cstdlib>
#include "MotorJuego.h"
#include "EstadoIntro.h"

using namespace std;

int main() {
    MotorJuego juego;
    juego.Init("Psychedelic Night");
    juego.CambiarEstado(EstadoIntro::Instance());
    
    while (juego.Activo()){
        juego.ManejarEventos();
        juego.Actualizar();
        juego.Dibujar();
    }
    juego.Limpiar();
    return 0;
}

