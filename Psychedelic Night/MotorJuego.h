/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MotorJuego.h
 * Author: mrmonkey
 *
 * Created on 10 de mayo de 2017, 12:46
 */

#ifndef MOTORJUEGO_H
#define MOTORJUEGO_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class EstadoJuego;

class MotorJuego {
public:
    void Init(const char* titulo, int ancho=900, int alto=540, int bpp=32);
    void Limpiar();
    void CambiarEstado(EstadoJuego* estado);
    void ApilarEstado(EstadoJuego* estado);
    void DesapilarEstado();
    void ManejarEventos();
    void Actualizar();
    void Dibujar();
    bool Activo() { return activo; }
    void Salir() { activo = false; }
    sf::RenderWindow* ventana;
    int getTam();
    void Reiniciar(EstadoJuego* estado);

private:
    vector<EstadoJuego*> estados;
    bool activo;
};

#endif /* MOTORJUEGO_H */

