/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.h
 * Author: juli
 *
 * Created on 25 de abril de 2017, 9:54
 */

#include <SFML/Graphics.hpp>
#ifndef MOTOR2D_H
#define MOTOR2D_H

class Motor2D {
public:
    static Motor2D *Instance();
    void setWindow(sf::RenderWindow *ventana);
    void pintarVentana();
    void pintarSprites(sf::Sprite sprite);
    void pintarRectShape(sf::RectangleShape shape);
    void limpiarVentana();
    void pintarTexto(sf::Text texto);
    
private:
    Motor2D(); // para arrays de objetos, sin parametros
    Motor2D(const Motor2D& orig); // cons q hace copia de clase motor2D
    
    
    static Motor2D *instanciaMotor;
    sf::RenderWindow *ventana;

};



#endif /* MOTOR2D_H */

