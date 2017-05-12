/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.h
 * Author: drmonkey
 *
 * Created on 29 de marzo de 2017, 12:56
 */

#ifndef NIVEL_H
#define NIVEL_H
#include "Planta.h"
#include <string>
#include "Mapa.h"
#include "Coordenada.h"

using namespace std;

class Nivel {
public:
    Nivel();
    Nivel(unsigned int sem);
    Nivel(const Nivel& orig);  
    void aumentanivel();
    string getSemilla();
    void imprimir();
    void dibujarNivel();
    int getNivel();
    void rellenarHabitaciones();
    bool **getVisitadas();
    void visitar(int i, int j);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int n; //Nivel
    string semilla;
    Planta *pl;
    Mapa *mapa;
    bool **visitadas;
    void crearMapa();
    vector<Coordenada*>* vect;
    int posx; //Posicion del jugador en la matriz de mapas
    int posy;
    sf::Sprite escalera;
};

#endif /* NIVEL_H */

