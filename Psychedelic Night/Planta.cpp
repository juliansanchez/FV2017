/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Planta.cpp
 * Author: drmonkey
 * 
 * Created on 28 de marzo de 2017, 9:23
 */
#include <stdio.h>
#include <stdlib.h> //Para el rand

//#include <queue> 
#include "Planta.h"
//#include "Coordenada.h"

using namespace std;

/*class Coordenada{
public:
    Coordenada(int i, int j) {
        x = i;
        y = j;
    }
    void setX(int i){x = i;}
    void setY(int j){y = j;}
    int getX() {return x;};
    int getY() {return y;};
private:
    int x, y;    
};*/

Planta::Planta(int n) {
    NHab = n;
    matriz = new int*[NHab];
    for (int i = 0; i<NHab; i++){
        matriz[i] = new int [NHab];
        for (int j = 0; j<NHab; j++)
            matriz[i][j] = 0;        
    }
    NHabitaciones = (int)NHab + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/((NHab*2)-NHab)));  
    int habitaciones = NHabitaciones;
    matriz [NHab/2][NHab/2] = 2; //Hab inicio
    NHabitaciones++;
    queue<Coordenada*> avance;
    Coordenada *ini = new Coordenada (NHab/2, NHab/2);
    avance.push(ini);
    creahabitacion (habitaciones, avance);
    while (!avance.empty()){
        Coordenada *co=avance.front();
        delete co;
        avance.pop();
    }
    anyadirboss(); //Anyado habitacion boss 
    anyadirtesoro();     
}

Planta::Planta(const Planta& orig) {
}

Planta::~Planta() {
    for (int i = 0; i<NHab; i++){
        //for (int j = 0; j<NHab; j++){
           // delete[] matriz[i][j];
        //}
        delete[] matriz[i];
    }
    delete[] matriz; 
}

void Planta::compruebahabitacion (int x, int y, vector<Coordenada*>* vect){   
    if (x-1 >= 0 && matriz[x-1][y] == 0)
        vect->push_back(new Coordenada (x-1, y));  
    if (x+1 < NHab && matriz[x+1][y] == 0)
        vect->push_back(new Coordenada (x+1, y));       
    if (y-1 >= 0 && matriz[x][y-1] == 0)
        vect->push_back(new Coordenada (x, y-1));           
    if (y+1 < NHab && matriz[x][y+1] == 0)
        vect->push_back(new Coordenada (x, y+1));           
}

void Planta::creahabitacion (int& h, queue<Coordenada*> a){
    if(!a.empty() && h>0){       
        int r= -1;
        float incprob = 0; 
        Coordenada* empiezo; 
        
        Coordenada *c = a.front();
        a.pop();
        //if (matriz[c->getX()][c->getY()]!=2)
            //matriz[c->getX()][c->getY()] = 1;              
        vector<Coordenada*>* vect = new vector<Coordenada*>;
        compruebahabitacion (c->getX(), c->getY(), vect);

        if (vect->size()>0){
            r= (int) static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/vect->size()));
            empiezo = vect->at(r);
        }
        
        if (r!=-1){
            while (vect->size()>0 && h>0){ //Mientras tenga vecinas y aun queden habitaciones por colocar  
                vect->erase(vect->begin() + r); //Esto va bien
                float fi = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                if (fi > incprob){                                  
                    a.push(empiezo);
                    matriz[empiezo->getX()][empiezo->getY()] = 1;
                    h--;
                    incprob=incprob + 0.45;                                               
                }
                else
                    matriz[empiezo->getX()][empiezo->getY()] = 3; //Habitacion inaccesible
                
                if (vect->size()>0 && h>0){
                    r= (int) static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/vect->size()));
                    //delete empiezo;
                    empiezo = vect->at(r);
                }            
            }
        }
        for (vector<Coordenada*>::iterator f = vect->begin() ; f != vect->end(); ++f)
            delete *f;
        delete vect;
        creahabitacion (h, a);
    }    
}

bool Planta::compruebauno (int x, int y){
    int contador = 0;
    if (x-1>=0 && matriz[x-1][y] == 1)
        contador++;
    if (x+1<NHab && matriz[x+1][y] == 1)
        contador++;
    if (y-1>=0 && matriz[x][y-1] == 1)
        contador++;
    if (y+1<NHab && matriz[x][y+1] == 1)
        contador++;
    if (contador == 1)
        return true;
    else
        return false;
}

void Planta::anyadirtesoro (){
    vector<Coordenada*>* vecto = new vector<Coordenada*>;
    for (int i = 0; i<NHab; i++){
        for (int j = 0; j<NHab; j++){
            if (matriz[i][j] == 0 && compruebauno(i, j)){
                vecto->push_back(new Coordenada (i,j));
            }
        }
    }
    if (vecto->size()!=0){
       int r= (int) static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/vecto->size()));
        Coordenada* gt = vecto->at(r);
        matriz[gt->getX()][gt->getY()] = 5; 
        while (!vecto->empty()){
            delete vecto->back();
            vecto->pop_back();
            vecto->clear();
        } 
        NHabitaciones++;
    }   
}

void Planta::anyadirboss (){
    int distmax = 0;
    vector<Coordenada*>* vect = new vector<Coordenada*>;
    for (int i = 0; i<NHab; i++){
        for (int j = 0; j<NHab; j++){
            if (matriz[i][j]==1){
                int dist = abs(NHab/2 - i) + abs(NHab/2 - j);
                if (dist>distmax){
                    while (!vect->empty()){
                        delete vect->back();
                        vect->pop_back();
                        vect->clear();
                    }
                    vect->push_back(new Coordenada(i,j));
                    distmax = dist;
                }
                else if (dist==distmax)
                    vect->push_back(new Coordenada(i,j));               
            }
        }
    }
    
    if (vect->size()!=0){
        int r= (int) static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/vect->size())); //Cojo aleatoriamente una de las posiciones mas alejadas
        bool anyadida = false;
        Coordenada* cord = vect->at(r);
        Coordenada* origen = vect->at(r);
        while (!vect->empty()){
            delete vect->back();
            vect->pop_back();
            vect->clear();
        }
        compruebahabitacion (cord->getX(), cord->getY(), vect);
        if (vect->size()==0)
            matriz[cord->getX()][cord->getY()] = 4;
        
        else{
            while (vect->size()>0 && !anyadida){                
                int r= (int) static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/vect->size()));
                cord = vect->at(r);
                if (compruebauno(cord->getX(), cord->getY())){ //Compruebo si hay alguna posicion adyacente a las lejana disponible
                    anyadida = true;
                    matriz[cord->getX()][cord->getY()] = 4;
                }
                vect->erase(vect->begin() + r);
                //delete cord;
            }
        }
        if (!anyadida) //Si no se ha podido anyadir en una posicion contigua a la posicion mas lejana, lo sustituyo por esa
            matriz[origen->getX()][origen->getY()] = 4; 
        while (!vect->empty()){
            delete vect->back();
            vect->pop_back();
            vect->clear();
        }
        delete vect; 
        NHabitaciones++;
    }   
}

void Planta::imprimir (){
    printf("-----------------------------------------\n");
     for (int i = 0; i<NHab; i++){
        for (int j = 0; j<NHab; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
} 

int Planta::getTam(){
    return NHab;
}

int Planta::getHabitaciones(){
    return NHabitaciones;
}

/*void Planta::rellenarMatriz(int mat[NHab][NHab]){
    for (int i = 0; i<NHab; i++){
        for (int j = 0; j<NHab; j++){
            mat[i][j] = matriz[i][j];
        }
    }
}*/

int** Planta::getMatriz(){
    return matriz;
}