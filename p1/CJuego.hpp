//cjuegohpp
#ifndef CJuego_hpp
#define CJuego_hpp

#include "CButton.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define NUM_BUTTONS  3

class CJuego{

private:

    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT* font;
    ALLEGRO_EVENT event;
    bool done;
    bool redraw;
    ALLEGRO_BITMAP* uaa;
    
    ALLEGRO_BITMAP *cursor;
    ALLEGRO_MOUSE_STATE msestate;
    
    CButton boton;
    CButton boton1;
    CButton boton2;
    CButton boton3;
    CButton botona;
    int posX;
    
public:
    //constructor
    CJuego(void);

    //Metodos
    int init();
    void deinit();
    void pintar();
    void logicaTeclado();
    
    void logicaMouse();
    
    
    
    void draw_mouse_button(int but, bool down);
    
    void run();
    
    //Destructor
    ~CJuego();
};
#endif 
