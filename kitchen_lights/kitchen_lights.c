
unsigned long keyPrevMillis = 0;
const unsigned long keySampleIntervalMs = 25;
byte longKeyPressCountMax = 80;    // 80 * 25 = 2000 ms
byte longKeyPressCount = 0;

byte prevKeyState = HIGH;         // button is active low
const byte keyPin = 2;            // button is connected to pin 2 and GND

const unsigned long startLedValue = 256;
byte ledState = HIGH;
unsigned long ledValue = 0;
const byte ledPin = 9;


// called when button is kept pressed for less than 2 seconds
// This will turn the lights on or off
void shortKeyPress() {
    Serial.println("short");
    if (ledState == HIGH) {
        ledState = LOW;
    } else if (ledState == LOW) {
        ledState = HIGH;
    }
}


// called when button is kept pressed for more than 2 seconds
// This will increase the brighness, with loop around fast flash
// when going back to low
void longKeyPress() {
    Serial.println("long");
    if (ledState == HIGH) {
        while (digitalRead(keyPin) == LOW) {
            ledValue+=1;
            delay(5);
            if (ledValue > 255) {
                analogWrite(ledPin, 0);
                delay(10);
                analogWrite(ledPin, 255);
                delay(10);
                ledValue = 1;
            }
            analogWrite(ledPin, ledValue);
        }
    }
}


// called when key goes from not pressed to pressed
void keyPress() {
    Serial.println("key press");
    longKeyPressCount = 0;
}


// called when key goes from pressed to not pressed
void keyRelease() {
    Serial.println("key release");
   
    if (longKeyPressCount >= longKeyPressCountMax) {
        longKeyPress();
    }
    else {
        shortKeyPress();
    }
}


void setup() {
    Serial.begin(115200);
    pinMode(keyPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    ledValue = startLedValue;
}


void loop() {
    // key management section
    if (millis() - keyPrevMillis >= keySampleIntervalMs) {
        keyPrevMillis = millis();
       
        byte currKeyState = digitalRead(keyPin);
       
        if ((prevKeyState == HIGH) && (currKeyState == LOW)) {
            keyPress();
        }
        else if ((prevKeyState == LOW) && (currKeyState == HIGH)) {
            keyRelease();
        }
        else if (currKeyState == LOW) {
            longKeyPressCount++;
            if (longKeyPressCount >= longKeyPressCountMax) {
                longKeyPress();
            }
        }
       
        prevKeyState = currKeyState;
    }

    if (ledState == HIGH) {
        analogWrite(ledPin, ledValue);
    }
    // other code goes here
}