/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: drmonkey
 * 
 * Created on 29 de marzo de 2017, 12:56
 */
#include <iostream>
#include <stdlib.h>
#include <time.h> //Para la semilla
//#include <string>
#include "Nivel.h"

using namespace std;

Nivel::Nivel() {
    unsigned int e = static_cast <unsigned> (time(0));
    semilla = to_string(e);
    unsigned int semi = stoi(semilla);
    srand (semi);
    n = 1;
    pl = new Planta(n+5);
    posx = (n+5)/2;
    posy = (n+5)/2;
    visitadas = new bool*[n+5];
    for (int i = 0; i<n+5; i++){
        visitadas[i] = new bool [n+5];
        for (int j = 0; j<n+5; j++)
            visitadas[i][j] = false;        
    }
    crearMapa();
}

Nivel::Nivel(unsigned int sem){
    semilla = to_string(sem);
    srand(sem);
    n = 1;
    pl = new Planta(n+5);
    posx = (n+5)/2;
    posy = (n+5)/2;
    for (int i = 0; i<n+5; i++){
        visitadas[i] = new bool [n+5];
        for (int j = 0; j<n+5; j++)
            visitadas[i][j] = false;        
    }
    crearMapa();   
}

Nivel::Nivel(const Nivel& orig) {
}

void Nivel::crearMapa(){
    mapa = new Mapa();
    int p = pl->getHabitaciones();
    mapa->leerMapa(p);
    int c = 0;
    int** matriz = pl->getMatriz();
    
    for (int i = 0; i<pl->getTam(); i++){
        for (int j = 0; j<pl->getTam(); j++){
            if (matriz[i][j] == 1 || matriz[i][j] == 2 || matriz[i][j] == 4 || matriz[i][j] == 5){
                mapa->setPosition(c, j, i);
                c++;
            }/*
            if (matriz[i][j] == 5){ //Carga tesoro
                sf::Sprite tesoro;
                tesoro.setPosition(39*20*i + 39*20/2, 23*20*j + 23*20/2); //Lo pone en el centro de la hab
            }
            else if (matriz[i][j] == 2){
                sf::Sprite personaje;
                personaje.setPosition(39*20*i + 39*20/2, 23*20*j + 23*20/2);           
            }*/
            if (matriz[i][j] == 4){
                escalera.setPosition(39*20*i + 39*20/2, 23*20*j + 23*20/2);
            }
        }
    }
}

void Nivel::dibujarNivel(){
    mapa->dibuja(pl->getHabitaciones());
}

void Nivel::aumentanivel(){   
    delete pl;
    delete mapa;
    for (int i = 0; i<n+5; i++)
        delete[] visitadas[i];   
    delete[] visitadas; 
    
    n++;
    pl = new Planta (n+5);
    posx = (n+5)/2;
    posy = (n+5)/2;
    crearMapa();
    for (int i = 0; i<n+5; i++){
        visitadas[i] = new bool [n+5];
        for (int j = 0; j<n+5; j++)
            visitadas[i][j] = false;        
    }
}

string Nivel::getSemilla(){
    return semilla;
}

void Nivel::imprimir(){
    pl->imprimir();
}

int Nivel::getNivel(){
    return n;
}

void Nivel::rellenarHabitaciones(){
    vect = new vector<Coordenada*>;
    int **matriz = pl->getMatriz();
    for (int i = 0; i<pl->getTam(); i++){
        for (int j = 0; j <pl->getTam(); j++){
            if (matriz[i][j] == 1 || matriz[i][j] == 2 ||  matriz[i][j] == 4 || matriz[i][j] == 5){
                vect->push_back(new Coordenada(i, j));
            }
        }
    }
}

bool **Nivel::getVisitadas(){
    return visitadas;
}

void Nivel::visitar(int i, int j){
    visitadas[i][j] = true;
    setX(i);
    setY(j);
}

int Nivel::getX(){
    return posx;
}

int Nivel::getY(){
    return posy;
}

void Nivel::setX(int x) {
    posx = x;
}

void Nivel::setY(int y){
    posy = y;
}