/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordenada.h
 * Author: drmonkey
 *
 * Created on 17 de marzo de 2017, 10:15
 */

#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada {
public:
    Coordenada(int i, int j);
    int getX() {return x;};
    int getY() {return y;};
    void setX(int i);
    void setY(int j);
private:
    int x;
    int y;
};

#endif /* COORDENADA_H */

