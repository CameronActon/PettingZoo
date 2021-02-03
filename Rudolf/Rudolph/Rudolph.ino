//Cameron Acton
//BitsyBoard Petting Zoo
//Rudolph

//Constants:
const int led = 2; //led for the blinking nose
const int flexPin = 3; //pin used for flex sensor for "petting"

int value; //flex sensor read value

long sT = millis(); //Variable to track the "starting time" a timer
boolean lit = true; //Controlls the lit status of an led in the blinking state

void setup() {
  //Initialize led as a digital output
  pinMode(led, OUTPUT);
}

void loop() {
  //Read flex sensor value
  value = analogRead(flexPin);

  //Threshold statement for flex sensor
  //if more than an analog value of 950 (more flex) then change blink speed
  //
  if (value > 950) {
    startBlink(100); //blinking with a pause of 100 ms
  } else {
    startBlink(800); //blinking with a pause of 800 ms
  }
}

//Function meant to blink an led
//Pass in a value in ms for time between on state of led
void startBlink(int inter) {
  //Millis timer to control state boolean
  if (millis() - sT > inter) {
    if (lit) {
      lit = !lit;
    } else {
      lit = !lit;
    }
    sT = millis();
  }

  //If statement to control status of LED based on status boolean
  if (lit) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
