This project generates mouse or keyboard events. Its compatibility is for the moment limited to OS X.

### Mouse events
A mouse event can have one of the 4 different types: `MOVE`, `PRESS`, `RELEASE`, `DRAG`.
This mouse event can be operated with 3 different buttons: `LEFT`, `RIGHT`, `CENTER`.
The event is localized at a specific 2D location on the screen ( x, y ).

A new mouse event can be created this way:

`Mouse_event e = Mouse_event( x, y, Mouse_event::TYPE,
                                    Mouse_event::BUTTON );`

### Keyboard events
A keyboard event can have one of the following types: `PRESS`, `RELEASE`. A keyboard event is also defined by its charcode, representing the combination of keys actuated.

A new keyboard event can be created this way:

`Keyboard_event e = Keyboard_event( Keyboard_event::Charcode::CODE,
                                    Keyboard_event::Event_type::TYPE );`

### Install
Type `make` in a terminal to compile the project