//Cameron Acton
//BitsyBoard Petting Zoo
//Cockatrice

//Constants:
const int buz = 0;   //Piezo Buzzer, for Cock-a-doodle-doo
const int phot = A2; //Photoresistor for "rising sun" detection

int pause = 300; //interval between tones for Cock-a-doodle-doo
int value; //photoresistor read value

void setup() {
  //Initialize buzzer as a digital output
  pinMode(buz, OUTPUT);
}

void loop() {
  //Read photoresistor value
  value = analogRead(phot);

  //Threshold statement for photoresistor
  //if more than an analog value of 500 (more light) then sound buzzer
  if (value > 500) {  
    chirp();
  } else {
    noTone();
  }
}

//Function to sound tones meant to try and replicate the sound of a rooster Cock-a-doodle-doo
void chirp() {
  tone(buz, 1000);
  delay(pause);
  tone(buz, 500);
  delay(pause);
  tone(buz, 1000);
  delay(pause);
  tone(buz, 500);
  delay(pause);
  tone(buz, 1000);
  delay(pause + 1000);
}
