//manual 
/*Entradas y colas de eventos
La entrada proviene de múltiples fuentes: teclado, mouse, joystick, temporizadores, etc. 
Las colas de eventos se agregan
eventos de todas estas fuentes, puede consultar la cola de eventos.
Cree una cola de eventos con al_create_event_queue, luego dígale a las fuentes de entrada que coloquen
nuevos eventos en esa cola usando al_register_event_source. Las fuentes de eventos de entrada habituales 
se pueden recuperar con al_get_keyboard_event_source, al_get_mouse_event_source y 
al_get_joystick_event_source.
Los eventos se pueden recuperar con al_wait_for_event o al_get_next_event. 
Compruebe el tipo de evento y otros
campos de ALLEGRO_EVENT para reaccionar a la entrada.
Las pantallas también son orígenes de eventos, que emiten eventos cuando se les cambia el tamaño. 
Deberá configurar el ALLEGRO_RESIZABLE marca con al_set_new_display_flags antes de crear la pantalla,
luego registre el
pantalla con una cola de eventos. 
Cuando obtenga un evento de cambio de tamaño, llame al_acknowledge_resize.
Los temporizadores son fuentes de eventos que "marcan" periódicamente, lo que hace que se 
inserte un evento en las colas que
el temporizador está registrado. Crea algunos con al_create_timer.
al_get_time y al_rest son formas más directas de lidiar con el tiempo*/
