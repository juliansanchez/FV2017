/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mapa.h
 * Author: Miguel y Luis
 *
 * Created on 19 de abril de 2016, 9:17
 */

#ifndef MAPA_H
#define MAPA_H
#include <SFML/Graphics.hpp>
#include "Motor2D.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <SFML/System.hpp>

class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    
    void leerMapa(int NH);
    void dibuja(int habs);
    
    int _width;
    int _height;
    int _tileWidth;
    int activeLayer;
    int getWidth();
    int getAnchoT();
    int getAltoT();
    int getHeight();
    void setActiveLayer(int layer);
    void setPosition(int h, int ancho, int alto);
    //bool devolverColision(int posX, int posY);
    
private:

    int ***_tilemap;
    int _numLayers;
    int _numObject;
    int _tileHeigth;
    
    int _widthCollider;
    int _heightCollider;
    int _xCollider;
    int _yCollider;
    int _rotCollider;
    
    sf::Sprite *****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    sf::Sprite *_tilesetSpriteobj;
    sf::Sprite te;
    sf::Sprite *_roca;
    sf::Sprite _fuego;
    sf::Sprite _pinchos;
    
    sf::Texture _tilesetTexture;
    sf::Texture m_tileset;
    sf::Texture roca;
    sf::Texture fuego;
    sf::Texture pinchos;
     
    sf::VertexArray m_vertices;
};

#endif /* MAPA_H */

