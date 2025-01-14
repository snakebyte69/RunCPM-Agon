#ifndef AGON_LIGHT_H
#define AGON_LIGHT_H

#include <SPI.h>
#include <SdFat.h>

#define SDMHZ 25
#define LED 13
#define LEDinv 0
#define BOARD "Agon Light"
#define board_agon_light

SdFat SD;
#define SDINIT SdSpiConfig(SS, DEDICATED_SPI, SD_SCK_MHZ(SDMHZ))

void setupAgonLight() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    Serial.begin(115200);
    while (!Serial) {
        digitalWrite(LED, HIGH ^ LEDinv);
        delay(50);
        digitalWrite(LED, LOW ^ LEDinv);
        delay(50);
    }
    SPI.begin();
    if (!SD.begin(SDINIT)) {
        Serial.println("SD card initialization failed!");
        while (1);
    }
    Serial.println("SD card initialized.");
}

#endif