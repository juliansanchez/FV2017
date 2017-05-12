/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Planta.h
 * Author: drmonkey
 *
 * Created on 28 de marzo de 2017, 9:23
 */

#ifndef PLANTA_H
#define PLANTA_H
#include <queue>
#include <vector>
#include "Coordenada.h"
using namespace std;

class Planta {
public:
    Planta(int n);
    Planta(const Planta& orig);
    virtual ~Planta();
    void anyadirtesoro ();
    void anyadirboss ();
    void imprimir ();
    int getHabitaciones();
    int getTam();
    //void rellenarMatriz(int mat[NHab][NHab]);
    int** getMatriz();
private:
    int NHab;
    int NHabitaciones;
    int **matriz;
    void compruebahabitacion (int x, int y, vector<Coordenada*>* vect);
    void creahabitacion (int& h, queue<Coordenada*> a);
    bool compruebauno (int x, int y);
};

#endif /* PLANTA_H */

