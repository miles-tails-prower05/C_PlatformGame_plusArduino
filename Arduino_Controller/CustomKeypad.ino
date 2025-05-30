/* @file EventSerialKeypad.pde
 || @version 1.0
 || @author Alexander Brevig
 || @contact alexanderbrevig@gmail.com
 ||
 || @description
 || | Demonstrates using the KeypadEvent.
 || #
 */
#include <Keypad.h>
#include "Keyboard.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'u','u','r','r'},
    {'u','u','p','p'},
    {'d','d','p','p'},
    {'d','d','l','l'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

boolean blink = false;
boolean ledPin_state;

void setup(){
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

    Keyboard.begin();
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == 'u') {
            //digitalWrite(ledPin,!digitalRead(ledPin));
            //ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            Keyboard.write(KEY_UP_ARROW);
        }

        if (key == 'd') {
            //digitalWrite(ledPin,!digitalRead(ledPin));
            //ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            Keyboard.write(KEY_DOWN_ARROW);
        }

        if (key == 'r') {
            //digitalWrite(ledPin,!digitalRead(ledPin));
            //ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            Keyboard.write(KEY_RIGHT_ARROW);
        }

        if (key == 'l') {
            //digitalWrite(ledPin,!digitalRead(ledPin));
            //ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            Keyboard.write(KEY_LEFT_ARROW);
        }

        if (key == 'p') {
            //digitalWrite(ledPin,!digitalRead(ledPin));
            //ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
            Keyboard.write(' ');
        }
        break;

    /* case RELEASED:
        if (key == 'b') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == 'b') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break; */
    }
}
