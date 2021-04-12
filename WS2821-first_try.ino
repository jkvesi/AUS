#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN 6 
#define NUMPIXELS 4 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); 

#define DELAYVAL 500

void setup() {
 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
 
  pixels.begin();
}

void loop() {
  pixels.clear(); 
  
  for(int i=0; i<NUMPIXELS; i++) {
    for(int j=0; j<250; j++){
    pixels.setPixelColor(i, pixels.Color(j, 150, 0));

    pixels.show();
    delay(DELAYVAL); 
  }
  }
  for(int i=0;i<NUMPIXELS; i++){
     pixels.setPixelColor(i, pixels.Color(255, 150, 0));
  }
  for(int i=0;i<NUMPIXELS; i++){
    if(i%2==0){pixels.show();}
  }
  delay(500);
 
   for(int i=0;i<NUMPIXELS; i++){
    if(i%2!=0){pixels.show();}
  }

  delay(1000);
}
