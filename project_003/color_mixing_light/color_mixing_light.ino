const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int blueSensorPin = A2;
const int greenSensorPin = A1;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  Serial.print("\t Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin, greenValue);
//  delay(1000);
//  analogWrite(redLEDPin, 0);
//  analogWrite(blueLEDPin, 0);
//  analogWrite(greenLEDPin, 127);
//  delay(1000);
//  analogWrite(redLEDPin, 0);
//  analogWrite(blueLEDPin, 127);
//  analogWrite(greenLEDPin, 0);
//  delay(1000);
//  analogWrite(redLEDPin, 127);
//  analogWrite(blueLEDPin, 127);
//  analogWrite(greenLEDPin, 0);
//  delay(1000);
//  analogWrite(redLEDPin, 127);
//  analogWrite(blueLEDPin, 0);
//  analogWrite(greenLEDPin, 127);
//  delay(1000);
//  analogWrite(redLEDPin, 0);
//  analogWrite(blueLEDPin, 127);
//  analogWrite(greenLEDPin, 127);
//  delay(1000);
//  analogWrite(redLEDPin, 127);
//  analogWrite(blueLEDPin, 127);
//  analogWrite(greenLEDPin, 127);
//  delay(1000);

//  for(int i = 0; i<127; i++){
//    for(int j = 0; j<127; j++){
//      for(int k = 0; k<127; k++){
//        analogWrite(redLEDPin, i);
//        analogWrite(blueLEDPin, j);
//        analogWrite(greenLEDPin, k);
//        delay(1);
//      }
//    }
//  }
}
