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

void MOS_send(uint8* message) {
    Serial.write(message);
}

uint8 MOS_receive() {
    while (!Serial.available());
    return Serial.read();
}

void MOS_communicate(uint8* message) {
    MOS_send(message);
    uint8 response = MOS_receive();
    Serial.write(response);
}

#endif
