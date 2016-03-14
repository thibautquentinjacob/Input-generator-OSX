#include "Mouse_event.h"
#include "Keyboard_event.h"
#include <stdlib.h>
#include <iostream>

// Main loop
int main( int argc, char *argv[] ) {
    
    Keyboard_event e = Keyboard_event( Keyboard_event::Charcode::I, 
                        Keyboard_event::Event_type::PRESS );
    e.send();
    
    for ( int i = 0 ; i < 1440 ; ++i ) {
        for ( int j = 0 ; j < 900 ; ++j ) {
            Mouse_event me = Mouse_event( i, j, Mouse_event::MOVE, 
                                                Mouse_event::LEFT );
            me.send();
//             sleep(1);
        }
    }
    return 0;
}