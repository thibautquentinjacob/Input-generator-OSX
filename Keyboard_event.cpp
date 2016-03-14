#include "Keyboard_event.h"

/**
 * Keyboard_event constructor
 * 
 * Initialize Keyboard_event object
 * @param Keyboard_event::Charcode representing the key pressed, event type 
 * Keyboard_event::Event_type ( PRESS, RELEASE ).
 * @return Nothing
 */
Keyboard_event::Keyboard_event( const Charcode code, const Event_type type ) {
    this->code = code;
    this->type = type;
}

/**
 * Dispatch key event
 * 
 * Creates a CGEventType out of instance attributes and dispatch it to the system
 * @param Nothing
 * @return void
 */
const void Keyboard_event::send() {
    CGEventRef event = CGEventCreateKeyboardEvent ( 
        NULL, (CGKeyCode)this->code, this->type == Keyboard_event::Event_type::PRESS );
    if ( this->command ) {
        CGEventSetFlags( event, kCGEventFlagMaskCommand );
    }
    if ( this->alt ) {
        CGEventSetFlags( event, kCGEventFlagMaskAlternate );
    }
    if ( this->shift ) {
        CGEventSetFlags( event, kCGEventFlagMaskShift );
    }
    if ( this->control ) {
        CGEventSetFlags( event, kCGEventFlagMaskControl );
    }
    CGEventPost( kCGSessionEventTap, event );
    CFRelease( event );
//     CGEventRef release_event = CGEventCreateKeyboardEvent ( 
//         NULL, (CGKeyCode)this->code, this->type == Keyboard_event::Event_type::RELEASE );
//     CGEventPost( kCGSessionEventTap, release_event );
//     CFRelease( release_event );
}

void Keyboard_event::use_control( const bool state ) {
    this->control = state;
}

void Keyboard_event::use_alt( const bool state ) {
    this->alt = state;
}

void Keyboard_event::use_shift( const bool state ) {
    this->shift = state;
}

void Keyboard_event::use_command( const bool state ) {
    this->command = state;
}