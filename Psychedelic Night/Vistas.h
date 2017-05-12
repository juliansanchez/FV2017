/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vistas.h
 * Author: drmonkey
 *
 * Created on 8 de mayo de 2017, 11:10
 */

#ifndef VISTAS_H
#define VISTAS_H
#define Division 10

class Vistas {
public:
    static Vistas *Instance();
    virtual ~Vistas();
    void centrarGeneral(int n);
    sf::View getGeneral();
    void moverVista(int x, int y);
    void actualizarVista();
    bool getEstado();
private:
    Vistas();
    Vistas(const Vistas& orig);
    sf::View general;
    int contador;
    int movx;
    int movy;
    
    static Vistas *instanciaVistas;
};

#endif /* VISTAS_H */

