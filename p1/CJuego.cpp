//cjuegocpp
#include "CJuego.hpp"
#include "CButton.hpp"
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

CJuego::CJuego (void){
    timer=NULL;
    queue=NULL;
    display = NULL;
    font = NULL;
    
    posX=0;
    
    init();
    
    done = false;
    redraw = true;
    boton=CButton("Kc.png",520,20);
    botona=CButton("Qd.png",550,20);
    boton1=CButton("Jt.png",154,154);
    boton2=CButton("10p.png",164,164);
    boton3= CButton("azul.png","9t.png",520,520);
    //boton3= CButton("siguiente.png","siguiente.png",225,225);
    
    
    al_start_timer(timer);
}

CJuego::~CJuego(){
    deinit();
}

void CJuego::run(){
    
    while(1)
    {
        al_wait_for_event(queue, &event);
        
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // logica del juego.
                redraw = true;
                break;
            case ALLEGRO_EVENT_MOUSE_AXES:
            //case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                logicaMouse();
                break;
            case ALLEGRO_EVENT_KEY_CHAR:
            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_KEY_UP:
                logicaTeclado();
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
                
        }
        
        if(done)
            break;
        
        if(redraw && al_is_event_queue_empty(queue))
        {
            pintar();
            redraw = false;
        }
    }
}

void CJuego::pintar(){
    //Limpiamos lienzo para pintar
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Pintamos texto
    al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");
    //Pintamos imagen
    //al_draw_bitmap(uaa, 10+posX, 10, 0);
    
    al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 20, 0, "PosX:%i",posX);
    
    boton.paint();
    botona.paint();
    boton1.paint();
    boton2.paint();
    boton3.paint();
    
    
    al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 20, 0, "Mouse (%i,%i)",msestate.x,msestate.y);
    al_draw_bitmap(cursor, msestate.x, msestate.y, 0);
    
    for (int i = 1; i <= NUM_BUTTONS; i++) {
        draw_mouse_button(i, al_mouse_button_down(&msestate, i));
    }
    
    /*al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0));
     al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
     al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);*/
     //al_draw_line(725, 200, 725, 38, al_map_rgb_f(1, 0, 0), 1);
     //al_draw_line(725, 200, 725, 38, al_map_rgb_f(1, 0, 0), 1);
     //al_draw_line(818, 200, 844, 35, al_map_rgb_f(1, 1, 0), 1);
    
    //mandamos a pantalla
    al_flip_display();
}

void CJuego::logicaMouse(){
    al_get_mouse_state(&msestate);
   // boton.estaSobre(msestate.x, msestate.y);
    //boton1.estaSobre(msestate.x, msestate.y);
    //boton2.estaSobre(msestate.x, msestate.y);
    //boton3.estaSobre(msestate.x, msestate.y);
    //botona.estaSobre(msestate.x, msestate.y);
     	if (al_mouse_button_down(&msestate, 1) && boton.esSobre){
        boton.setPos(msestate.x-100, msestate.y-100);
    }
     if (al_mouse_button_down(&msestate, 1) && botona.esSobre){
        botona.setPos(msestate.x-100, msestate.y-80);
    } 
     if(al_mouse_button_down(&msestate,1)&& boton1.esSobre){
        boton1.setPos(msestate.x-100, msestate.y-60);
      }
    	if (al_mouse_button_down(&msestate, 1) && boton2.esSobre){
        boton2.setPos(msestate.x-100, msestate.y-40);
    }
    if (al_mouse_button_down(&msestate, 1) && boton3.esSobre){
        boton3.setPos(msestate.x-100, msestate.y-20);
    }
   
}

void CJuego::logicaTeclado(){
    if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        posX++;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
        posX--;
    }
}

void CJuego::draw_mouse_button(int but, bool down)
{
    const int offset[NUM_BUTTONS] = {0, 70, 35};
    ALLEGRO_COLOR grey;
    ALLEGRO_COLOR black;
    int x;
    int y;
    
    x = 10 + offset[but-1];
    y = 50;
    
    grey = al_map_rgb(0xe0, 0xe0, 0xe0);
    black = al_map_rgb(0, 0, 0);
    
    al_draw_filled_rectangle(x, y, x + 27, y + 42, grey);
    al_draw_rectangle(x + 0.5, y + 0.5, x + 26.5, y + 41.5, black, 0);
    if (down) {
        al_draw_filled_rectangle(x + 2, y + 2, x + 25, y + 40, black);
    }
}

int CJuego::init() {
    //inicializamos allegro
    if(!al_init())
    {
        printf("couldn't initialize allegro\n");
        return 1;
    }
    //Inicializamos teclado
    if(!al_install_keyboard())
    {
        printf("couldn't initialize keyboard\n");
        return 1;
    }
    //Inicializamos timer y event_queue para garantizar
    //consistencia en la velocidad
    timer = al_create_timer(1.0 / 30.0);
    if(!timer)
    {
        printf("couldn't initialize timer\n");
        return 1;
    }
    
    //Create Keybord queue
    queue = al_create_event_queue();
    if(!queue)
    {
        printf("couldn't initialize queue\n");
        return 1;
    }
    
    //Inicializamos parntalla de 640x480
    //display = al_create_display(1600, 1200);
    display = al_create_display(1350, 640);
    //display = al_create_display(640, 480);
    if(!display)
    {
        printf("couldn't initialize display\n");
        return 1;
    }
    
    
    /* add other initializations here */
    
    font = al_create_builtin_font();
    if(!font)
    {
        printf("couldn't initialize font\n");
        return 1;
    }
    
    if(!al_init_image_addon())
    {
        printf("couldn't initialize image addon\n");
        return 1;
    }
    
    if(!al_init_primitives_addon())
    {
        printf("couldn't initialize primitives\n");
        return 1;
    }
    
    
    //Inicializamos mouse
    al_install_mouse();
    al_hide_mouse_cursor(display);
    
    //cursor = al_load_bitmap("cursor.tga");
    cursor = al_load_bitmap("cursor.png");
    if (!cursor) {
        printf("Error loading cursor.png\n");
    }
    
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());
    
    return 0;
}

void CJuego::deinit() {
    
    //al_destroy_bitmap(uaa);
    al_destroy_bitmap(cursor);
    //al_clear_keybuf();
    /* add other deinitializations here */
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
