

/*
Tricorder by Kit Farman. Built heavily on example coded provided by Arduino.cc.
Uses TFT, Neopixels, and a sound module to enhance a toy tricorder.

 */

// include the necessary libraries
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library
#include <Adafruit_NeoPixel.h>

// pin definition for the Uno
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1

TFT TFTscreen = TFT(lcd_cs, dc, rst);

// this variable represents the image to be drawn on screen
PImage logo;


void setup() {
  // initialize the GLCD and show a message
  // asking the user to open the serial line
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);

  // initialize the serial port: it will be used to
  // print some diagnostic info
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial line to be ready
  }

  // clear the GLCD screen before starting
  TFTscreen.background(0, 0, 0);

  // try to access the SD card. If that fails (e.g.
  // no card present), the setup process will stop.
  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(sd_cs)) {
    Serial.println(F("failed!"));
    return;
  }
  Serial.println(F("OK!"));

  // initialize and clear the GLCD screen
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);

  // now that the SD card can be access, try to load the
  // image file.
  logo = TFTscreen.loadImage("LCARS5.bmp");
  if (!logo.isValid()) {
    Serial.println(F("error while loading arduino.bmp"));
  }
    // don't do anything if the image wasn't loaded correctly.
  if (logo.isValid() == false) {
    return;
  }

  Serial.println(F("drawing image"));

  // get a random location where to draw the image.
  // To avoid the image to be draw outside the screen,
  // take into account the image size.

  // draw the image to the screen
  TFTscreen.image(logo, 0, 0);
  
    // set the fill color to grey
  TFTscreen.fill(155,0,155);

  // first graph line
  TFTscreen.rect(110, 7, 10, 30);
  TFTscreen.rect(90, 7, 10, 40);
  TFTscreen.rect(70, 7, 10, 55);
  TFTscreen.rect(50, 7, 10, 45);
  TFTscreen.rect(30, 7, 10, 50);
  TFTscreen.rect(10, 7, 10, 85);

}

void loop() {

}
