#include <Arduino.h>
#include <SSD1306Wire.h>

SSD1306Wire  display(0x3c, SDA , SCL, GEOMETRY_128_64);

void setup(){

    display.init();
    display.setFont(ArialMT_Plain_24);
    display.flipScreenVertically();
    display.drawString(0, 0, "Test Ecran");
    display.drawString(0, 32, "Ligne 2");
    display.display();
}

void loop(){
}
