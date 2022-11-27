//cbcpp
#include "CButton.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

CButton::CButton(){
    
}
// constructor por defecto
CButton::CButton(const char *archivo, int x, int y)
{
    press=false;
    this->x=x;
    this->y=y;
    btn = al_load_bitmap(archivo);
    btn_sobre = NULL;
   // btn_sobre1 = NULL;
}

CButton::CButton(const char *archivo, const char *archivoSobre, int x, int y)
{
    press=false;
    this->x=x;
    this->y=y;
    btn = al_load_bitmap(archivo);
    btn_sobre = al_load_bitmap(archivoSobre);
    //btn_sobre1 = al_load_bitmap(archivoSobre);
}


CButton::~CButton()
{
}

void CButton::setPos(int mouse_x, int mouse_y){
    x=mouse_x;
    y=mouse_y;
    
}

void CButton::estaSobre(int mouse_x, int mouse_y){
    int tamx=360;
    int tamy=360;
    if(x<mouse_x && y < mouse_y &&
       mouse_x < (x+tamx) && mouse_y <(y+tamy)){
        esSobre=true;
    }else{
        esSobre=false;
    }
    
}

void CButton::paint(){
    if(esSobre && btn_sobre){
        al_draw_bitmap(btn_sobre, x, y, 0);
    }else{
        al_draw_bitmap(btn, x, y, 0);
    }
    //estaSobre();
   /* textprintf_centre_ex(buffer, font, x, y-10,
                         makecol(195,125,255), -1, "band :%i",esSobre);
    textprintf_centre_ex(buffer, font, x, y+60,
                         makecol(195,125,255),-1,  "press :%i",press);
    
    
    if(!esSobre)
        draw_sprite(buffer, sBtn, x,y );
    else{
        if(mouse_b&1){
            press=true;
        }else{
            press=false;
        }
        draw_sprite(buffer, sBtnSobre, x, y);
    }*/
}

