#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <iostream>

class Mouse_event {
    public:
        enum Event_type { MOVE, PRESS, RELEASE, DRAG };
        enum Mouse_button { LEFT = 0, RIGHT = 1, CENTER = 2 };
                     Mouse_event( const int x, const int y, 
                                  const Event_type type,
                                  const Mouse_button button );
        const void   send();
    private:
        int          x;
        int          y;
        Event_type   type;
        Mouse_button button;
};

#endif // MOUSE_EVENT_H