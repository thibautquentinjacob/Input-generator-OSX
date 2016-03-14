#ifndef KEYBOARD_EVENT_H
#define KEYBOARD_EVENT_H

#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>
#include <iostream>

class Keyboard_event {
    public:
        enum Event_type { PRESS, RELEASE };
        enum Charcode { 
            A                = 0x00,
            S                = 0x01,
            D                = 0x02,
            F                = 0x03,
            H                = 0x04,
            G                = 0x05,
            Z                = 0x06,
            X                = 0x07,
            C                = 0x08,
            V                = 0x09,
            B                = 0x0B,
            Q                = 0x0C,
            W                = 0x0D,
            E                = 0x0E,
            R                = 0x0F,
            Y                = 0x10,
            T                = 0x11,
            K_1              = 0x12,
            K_2              = 0x13,
            K_3              = 0x14,
            K_4              = 0x15,
            K_5              = 0x16,
            K_6              = 0x17,
            EQUAL            = 0x18,
            K_9              = 0x19,
            K_7              = 0x1A,
            MINUS            = 0x1B,
            K_8              = 0x1C,
            K_0              = 0x1D,
            RIGHT_BRACKET    = 0x1E,
            O                = 0x1F,
            U                = 0x20,
            LEFT_BRACKET     = 0x21,
            I                = 0x22,
            P                = 0x23,
            L                = 0x25,
            J                = 0x26,
            QUOTE            = 0x27,
            K                = 0x28,
            SEMI_COLON       = 0x29,
            BACKSLASH        = 0x2A,
            COMMA            = 0x2B,
            SLASH            = 0x2C,
            N                = 0x2D,
            M                = 0x2E,
            PERIOD           = 0X2F,
            GRAVE            = 0X32,
            KEYPAD_DECIMAL   = 0X41,
            KEYPAD_MULTIPLY  = 0X43,
            KEYPAD_PLUS      = 0X45,
            KEYPAD_CLEAR     = 0X47,
            KEYPAD_DIVIDE    = 0X4B,
            KEYPAD_ENTER     = 0X4C,
            KEYPAD_MINUS     = 0X4E,
            KEYPAD_EQUALS    = 0X51,
            KEYPAD_0         = 0X52,
            KEYPAD_1         = 0X53,
            KEYPAD_2         = 0X54,
            KEYPAD_3         = 0X55,
            KEYPAD_4         = 0X56,
            KEYPAD_5         = 0X57,
            KEYPAD_6         = 0X58,
            KEYPAD_7         = 0X59,
            KEYPAD_8         = 0X5B,
            KEYPAD_9         = 0X5C,
            RETURN           = 0X24,
            TAB              = 0X30,
            SPACE            = 0X31,
            DELETE           = 0X33,
            ESCAPE           = 0X35,
            COMMAND          = 0X37,
            SHIFT            = 0X38,
            CAPSLOCK         = 0X39,
            OPTION           = 0X3A,
            CONTROL          = 0X3B,
            RIGHT_SHIFT      = 0X3C,
            RIGHT_OPTION     = 0X3D,
            RIGHT_CONTROL    = 0X3E,
            FUNCTION         = 0X3F,
            F17              = 0X40,
            VOLUME_UP        = 0X48,
            VOLUME_DOWN      = 0X49,
            MUTE             = 0X4A,
            F18              = 0X4F,
            F19              = 0X50,
            F20              = 0X5A,
            F5               = 0X60,
            F6               = 0X61,
            F7               = 0X62,
            F3               = 0X63,
            F8               = 0X64,
            F9               = 0X65,
            F11              = 0X67,
            F13              = 0X69,
            F16              = 0X6A,
            F14              = 0X6B,
            F10              = 0X6D,
            F12              = 0X6F,
            F15              = 0X71,
            HELP             = 0X72,
            HOME             = 0X73,
            PAGE_UP          = 0X74,
            FORWARD_DELETE   = 0X75,
            F4               = 0X76,
            END              = 0X77,
            F2               = 0X78,
            PAGE_DOWN        = 0X79,
            F1               = 0X7A,
            LEFT_ARROW       = 0X7B,
            RIGHT_ARROW      = 0X7C,
            DOWN_ARROW       = 0X7D,
            UP_ARROW         = 0x7E
        };
                       Keyboard_event( const Charcode code, const Event_type type );
        const void     send();
        void           use_command( const bool state );
        void           use_alt( const bool state );
        void           use_shift( const bool state );
        void           use_control( const bool state );
    private:
        Event_type     type;
        Charcode       code;
        bool           command;
        bool           alt;
        bool           shift;
        bool           control;
};

#endif // KEYBOARD_EVENT_H