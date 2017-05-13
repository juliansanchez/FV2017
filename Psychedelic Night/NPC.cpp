/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPC.cpp
 * Author: rizado
 * 
 * Created on May 1, 2017, 11:31 AM
 */

#include "NPC.h"
#include "EstadoJugando.h"



NPC::NPC(int tipo, int posX, int posY) {
    
    this->tipo=tipo;
    this->posMatrix_x= posX;
    this->posMatrix_y=posY;
    contadorvueltas = 0;
    if(tipo==0){

        Texture *textura1;
        textura1 = new Texture();
        if (!textura1->loadFromFile("resources/topo.png")) {
            cerr << "Error cargando la imagen";
            exit(0);
        }
        SpriteGame t(*textura1,3,28,0,31);
        SpriteGame t1(*textura1,35,60,0,31);
        SpriteGame t2(*textura1,67,92,0,31);
        SpriteGame t3(*textura1,3,28,32,63);
        SpriteGame t4(*textura1,35,60,32,63);
        SpriteGame t5(*textura1,67,92,32,63);
        SpriteGame t6(*textura1,3,28,64,95);
        
        
        

        this->enemigo=new Sprite*[8];
        for(int i=0; i<8;i++){
            this->enemigo[i]= new Sprite ();
        }
        *this->enemigo[0]=t.GetSprite();
        *this->enemigo[1]=t1.GetSprite();
        *this->enemigo[2]=t3.GetSprite();
        *this->enemigo[3]=t4.GetSprite();
        *this->enemigo[4]=t5.GetSprite();
        *this->enemigo[5]=t2.GetSprite();
        *this->enemigo[6]=t6.GetSprite();
        *this->enemigo[7]=t2.GetSprite();
        
        this->alto= t.getAlto();
        this->ancho=t.getAncho();
        
        this->num_sprites=8;
        this->numCambio=4; 
        
        this->retraso=12;
    }
    
    if(tipo==1){
        Texture *textura2;
        textura2 = new Texture();
        if (!textura2->loadFromFile("resources/mosquito.png")) {
            cerr << "Error cargando la imagen";
            exit(0);
        }
        
        SpriteGame m(*textura2,7,25,10,19);
        SpriteGame m2(*textura2,41,53,5,19);
        this->enemy=new SpriteGame*[2];

        this->alto= m.getAlto();
        this->ancho=m.getAncho();
         
        this->enemigo= new Sprite*[2];
        this->enemigo[0]= new Sprite ();
        this->enemigo[1]= new Sprite ();
        *this->enemigo[0]=m.GetSprite();
        *this->enemigo[1]=m2.GetSprite();
        
        this->num_sprites=2;
        this->numCambio=2;
        this->angle=0;
    }
            
                   
    if(tipo==2){
        Texture *textura3;
        textura3 = new Texture();
        if (!textura3->loadFromFile("resources/cabezon.png")) {
            cerr << "Error cargando la imagen";
            exit(0);
        }
        SpriteGame c(*textura3,5,75,0,75);
        SpriteGame c1(*textura3,85,155,0,75);
        SpriteGame c2(*textura3,165,235,0,75);
        SpriteGame c3(*textura3,245,315,0,75);
        
        this->enemigo=new Sprite*[4];
        for(int i=0; i<4;i++){
            this->enemigo[i]= new Sprite ();
         }
        *this->enemigo[0]=c.GetSprite();
        *this->enemigo[1]=c1.GetSprite();
        *this->enemigo[2]=c2.GetSprite();
        *this->enemigo[3]=c3.GetSprite();
        this->alto= c.getAlto();
        this->ancho=c.getAncho();
        
        this->num_sprites=4;
        this->numCambio=12;
    }
    
    if(tipo==13){
        Texture *textura13;
        textura13 = new Texture();
        if (!textura13->loadFromFile("resources/mosquito2.png")) {
            cerr << "Error cargando la imagen";
            exit(0);
        }
        
        SpriteGame m(*textura13,7,25,10,19);
        SpriteGame m2(*textura13,41,53,5,19);
        this->enemy=new SpriteGame*[2];

       
         
        this->enemigo= new Sprite*[2];
        this->enemigo[0]= new Sprite ();
        this->enemigo[1]= new Sprite ();
        *this->enemigo[0]=m.GetSprite();
        *this->enemigo[1]=m2.GetSprite();
        
        this->enemigo[0]->setScale(2,2);
        this->enemigo[1]->setScale(2,2);
        this->alto= m.getAlto();
        this->ancho=m.getAncho();
        
        
        this->num_sprites=2;
        this->numCambio=2;
        this->angle=0;
    }
    
    this->cambio_sprite=0;
    this->dispara=0;
    this->velx = 0;
    this->rangoDisparo = 1;
    
    balas= new std::vector<Bala*>;
    this->posicionAleatoria();
}

NPC::NPC(const NPC& orig) {
}

NPC::~NPC() {
    
}

int NPC::getTipo(){
    return this->tipo;
}

void NPC::nextSprite(int contadorVueltas){   
     if(contadorVueltas%this->numCambio==0){
            cambio_sprite=(cambio_sprite+1)%this->num_sprites;
        }
}

void NPC::movMosquito(){  
    
    //float distancia, distancia_x,distancia_y;
    float lenght=0;
    float x,y;
    float distancia_x,distancia_y,distancia;
    
    EstadoJugando* estandoJugando= EstadoJugando::Instance();
    
    distancia_x= (this->getX()) - (estandoJugando->getPersonaje()->getX());
    distancia_y= (this->getY()) - (estandoJugando->getPersonaje()->getY());
    distancia= sqrt(pow(distancia_x,2)+pow(distancia_x,2) );

    if(distancia>200){
    angle+=0.1;
    x= (2*cos(angle)+ lenght);
    y= (2*sin(angle)+lenght);
    enemigo[0]->move(x,y);
    enemigo[1]->move(x,y);
    }else{
       enemigo[0]->move(-distancia_x/15,-distancia_y/15);
       enemigo[1]->move(-distancia_x/15,-distancia_y/15);
        
    }
    
    
    /* CODIGO PARA PERSEGUIR PERSONAJE (HACER PARA VER X E Y PERSONAJE)
        distancia_x= m.GetSprite().getPosition().x-p.GetSprite().getPosition().x;
        distancia_y= m.GetSprite().getPosition().y-p.GetSprite().getPosition().y;
        distancia= sqrt(pow(distancia_x,2)+pow(distancia_x,2) );
        
        
            angle+=0.1;
            x= (2*cos(angle)+ lenght);
            y= (2*sin(angle)+lenght);
       
            m.Mover(x,y);
            m2.Mover(x,y);
            *mosquito[0]=m.GetSprite();
            *mosquito[1]=m2.GetSprite();
        }else{
            m.Mover(-distancia_x/60,-distancia_y/60);
            m2.Mover(-distancia_x/60,-distancia_y/60);
            *mosquito[0]=m.GetSprite();
            *mosquito[1]=m2.GetSprite();
        }
     
     
     */
}

void NPC::movTopo(Time tiempo, int cont_vueltas){  
    
    float x_topo=0;
    float y_topo=0;
    if(cont_vueltas%this->numCambio==0){
            
        if(retraso>12){
            cambio_sprite=(cambio_sprite+1)%this->num_sprites;
            if(cambio_sprite==6){
            retraso=0;
            }    
        }

        if(retraso==6){
           x_topo = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/350));
            y_topo = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/180));
            float signox =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
            float signoy =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
            if (signox >= 0.5)
                x_topo = x_topo * (-1);
            if (signoy >= 0.5)
                y_topo = y_topo * (-1);
            //x_topo=static_cast <float> (random())/static_cast <float> (5);
            for(int i=0; i<8;i++){
                enemigo[i]->setPosition(posMatrix_x*39*20 + 39*20/2 + x_topo,posMatrix_y*23*20 + 23*20/2 + y_topo);
            }
        }
        retraso++;
    }   
}

void NPC::dibujarEnemigo(){ 
    Motor2D* motor2D = Motor2D::Instance();
    motor2D->pintarSprites(*this->enemigo[cambio_sprite]);
}

void NPC::posicionAleatoria(){
    float px = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/350));
    float py = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/180));
    float signox =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    float signoy =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
    if (signox >= 0.5)
        px = px * (-1);
    if (signoy >= 0.5)
        py = py * (-1);
    int initX =posMatrix_x*39*20 + 39*20/2 + px;
    int initY =posMatrix_y*23*20 + 23*20/2 + py;
    for(int i=0;i<num_sprites;i++){
        this->enemigo[i]->setPosition(initX,initY);
    }   
}

void NPC::DisparoEnemigo(Clock clockbala){
    
    // creamos una nueva bala y la metemos en el vector
    balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,velx,-10,rangoDisparo));
    balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x,enemigo[cambio_sprite]->getPosition().y,velx, 10,rangoDisparo));
    balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x-5,enemigo[cambio_sprite]->getPosition().y,-10,0,rangoDisparo));
    balas->push_back(new Bala(enemigo[cambio_sprite]->getPosition().x+5,enemigo[cambio_sprite]->getPosition().y,10,0,rangoDisparo));
    dispara++;
    //clockbala.restart();

    

    
}

void NPC::ActualizarDisparo(){
    
        // actualizo posicion de la bala
        for(int i = 0 ; i<balas->size(); i++){
            if(balas->at(i)){
                balas->at(i)->actualiza(); // actualizo posicion de la bala
                if(balas->at(i)->destruirBala){
                    delete balas->at(i); // borramos la bala del vector
                    balas->erase(balas->begin()+i); // libero memoria de pos del vector
                }        
            }
        }

}


vector<Bala*>  NPC::GetBala(){
    return *balas;

}

void NPC::pintarDisparo(){   
    Motor2D *motor2D = Motor2D::Instance();
    if(tipo==2){
       for(int i = 0 ; i<balas->size(); i++){
           if(balas->at(i)){
               motor2D->pintarSprites(balas->at(i)->getSprite());
              //motor2D->PintarSprites(*balas->at(i));
            }
        }
    }  
}

void NPC::accionesEnemigo(Clock reloj2, Time tiempo){
    
    if(tipo==1){
        this->nextSprite(contadorvueltas);
        this->movMosquito();
    }
    if(tipo==0){
        this->movTopo(tiempo,contadorvueltas);
    }
    if(tipo==2 || tipo==13){
        if(contadorvueltas%49==0){  
            this->DisparoEnemigo(reloj2);
        }
        this->ActualizarDisparo();
        this->nextSprite(contadorvueltas);
    }
    contadorvueltas++;
}

void NPC::colisionPersonaje(){
    
     EstadoJugando* estandoJugando= EstadoJugando::Instance();
     /*
    cout<<"personaje x"<<estandoJugando->getPersonaje()->getX()<<endl;
    cout<<"personaje y"<<estandoJugando->getPersonaje()->getY()<<endl;
    
    cout<<"enemigo x"<<this->getX()<<endl;
    cout<<"enemigo y"<<this->getY()<<endl;
    */
     
    if((estandoJugando->getPersonaje()->getX()+32) > (this->getX()-ancho/4)&&  
            (estandoJugando->getPersonaje()->getY()+42) > (this->getY()-alto/4) &&
            (this->getX()+ancho/1.5)> (estandoJugando->getPersonaje()->getX()) &&
            (this->getY()+alto/1.5)> (estandoJugando->getPersonaje()->getY())){
         
         estandoJugando->getPersonaje()->quitarVida();
         cout<<estandoJugando->getPersonaje()->getVidaActual()<<endl; 
    }
     
     /*
    if((estandoJugando->getPersonaje()->getX()+32) >= (this->getX()-ancho/2)  
            && (estandoJugando->getPersonaje()->getY()+42) > (this->getY()-alto/2) &&
            (this->getX()-ancho/2)> (estandoJugando->getPersonaje()->getX()+32) &&
            (this->getY()-alto/2)> (estandoJugando->getPersonaje()->getY()+32)){
         
         estandoJugando->getPersonaje()->quitarVida();
         cout<<estandoJugando->getPersonaje()->getVidaActual()<<endl;
     
     }
     
      if((estandoJugando->getPersonaje()->getX()+32) >= (this->getX()-ancho/2) && (this->getX()-ancho/2)>= (estandoJugando->getPersonaje()->getX())){
          estandoJugando->getPersonaje()->quitarVida();
         cout<<estandoJugando->getPersonaje()->getVidaActual()<<endl;
      
      }
     
     */
     
     /*
     if((estandoJugando->getPersonaje()->getX()+32) >= (this->getX()-ancho/2)
        || (this->getX()-ancho/2)>= (estandoJugando->getPersonaje()->getX()+32)){
         
        // estandoJugando->getPersonaje()->quitarVida();
         cout<<estandoJugando->getPersonaje()->getVidaActual()<<endl;
         cout<<"LOOOOOOCCCCOOOOOO"<<endl;
     
     }
     */

}




int NPC::getX(){
    return enemigo[cambio_sprite]->getPosition().x;
}

int NPC::getY(){
    return enemigo[cambio_sprite]->getPosition().y;
    
}

int NPC::getPosMatrix_x(){
    return posMatrix_x;
}

int NPC::getPosMatrix_y(){
    return posMatrix_y;
}

