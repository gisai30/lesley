#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "main.hpp"
#include "CJuego.hpp"


int main(int argc,char **args) {
    
    CJuego juego = CJuego();
    juego.run();
    
    return 0;
}
