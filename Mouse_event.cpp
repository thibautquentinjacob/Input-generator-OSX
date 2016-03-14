#include "Mouse_event.h"

/**
 * Mouse_event constructor
 * 
 * Initialize Mouse_event object
 * @param int mouse x position, int mouse y position, event type 
 * Mouse_event::Event_type ( MOVE, PRESS, RELEASE, DRAG ), button identifier
 * Mouse_event::Mouse_button ( LEFT, RIGHT, CENTER ).
 * @return Nothing
 */
Mouse_event::Mouse_event( const int x, const int y, 
                          Event_type type, Mouse_button button ) {
    this->x      = x;
    this->y      = y;
    this->type   = type;
    this->button = button;
}

/**
 * Dispatch mouse event
 * 
 * Creates a CGEventType out of instance attributes and dispatch it to the system
 * @param Nothing
 * @return void
 */
const void Mouse_event::send() {
    CGEventType event_type = kCGEventNull;
    switch ( this->type ) {
        case MOVE:
            event_type = kCGEventMouseMoved;
            break;
        case PRESS:
            if ( this->button == Mouse_event::LEFT ) {
                event_type = kCGEventLeftMouseDown;
            } else if ( this->button == Mouse_event::RIGHT ) {
                event_type = kCGEventRightMouseDown;
            } else {
                std::cout << "Center button not handled" << std::endl; 
            }
            break;
        case RELEASE:
            if ( this->button == Mouse_event::LEFT ) {
                event_type = kCGEventLeftMouseUp;
            } else if ( this->button == Mouse_event::RIGHT ) {
                event_type = kCGEventRightMouseUp;
            } else {
                std::cout << "Center button not handled" << std::endl; 
            }
            break;
        case DRAG:
            if ( this->button == Mouse_event::LEFT ) {
                event_type = kCGEventLeftMouseDragged;
            } else if ( this->button == Mouse_event::RIGHT ) {
                event_type = kCGEventRightMouseDragged;
            } else {
                std::cout << "Center button not handled" << std::endl; 
            }
            break;
        default:
            std::cout << "Unknown event: " << this->type << std::endl;
            break;
    }
    CGEventRef event = CGEventCreateMouseEvent(
        NULL, event_type,
        CGPointMake( this->x , this->y ),
        (CGMouseButton)this->button
    );
    CGEventPost( kCGHIDEventTap, event );
}