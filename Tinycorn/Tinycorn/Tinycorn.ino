//Cameron Acton
//BitsyBoard Petting Zoo
//Tinycorn

//Libraries to enable capacitive touch and NeoPixel strip
#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

CapacitiveSensor horn = CapacitiveSensor(3, 4); //Capacitive touch for unicorn horn
const int led = 2; //Pin used forNeoPixel strip
const int count = 4; //Number of NeoPixels on strip

//Declaring NeoPixel strip
Adafruit_NeoPixel strip(count, led, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // Initiialize NeoPixel strip

  // Turn turns of all NeoPixels at beginning of program
  strip.clear();
  strip.show();
              
  strip.setBrightness(20); // Set brightness of strip to 20 (out of 255)
}

void loop() {
  int sense =  horn.capacitiveSensor(30);

  //Statement to check capacitive touch value
  //If value is over 50 (more touch) then NeoPixels begin displaying rainbow
  if (sense > 50) {
    rainbow();  // Flowing rainbow cycle along the whole strip
    
    //Turns strip off after displaying rainbow
    strip.clear(); 
    strip.show();
  }
}

// Rainbow cycle along whole strip.
// Influenced heavily from "strandtest" in NeoPixel Library Examples
void rainbow() {
  for (long hue = 0; hue < 5 * 65536; hue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = hue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
  }
}
