#include <Adafruit_BME280.h>

#define BME_CSB 10   //     CS/CSB Chip Select
#define BME_SDA 11   //     MISO/SDA/SDI Serial Data Out
#define BME_SDO 12   //     MOSI/SDO Serial Data In
#define BME_SCL 13   //     SCK/SCL Serial Clock

#define SeaLevelPressure_hPa (1013.25)

Adafruit_BME280 bme(BME_CSB, BME_SDA, BME_SDO, BME_SCL);

void setup() {
    Serial.begin(9600);
    Serial.println("Adafruit BME280 shield");

    bool status = bme.begin();
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor");
        while (1);
    }
}

void loop() {
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SeaLevelPressure_hPa));
    Serial.println(" m");


    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" ˚C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    delay(1000);
}
