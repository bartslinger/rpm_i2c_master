#include <Wire.h>
#include <stdint.h>

const unsigned int interval = 100; // [ms]

void setup() {
  Wire.begin();
  Serial.begin(115200);
  delay(100);
}

void loop() {
  Wire.requestFrom(8, 8); // request 8 bytes
  uint32_t rpm[2] = {0};

  uint8_t buf[8];
  for (uint8_t i = 0; i < 8; i++) {
    buf[i] = Wire.read();
  }
  memcpy(rpm, buf, 8);
  
  char serbuf[100];
  uint16_t len;
  len = sprintf(serbuf, "%" PRIu32 ",%" PRIu32 "\n", rpm[0], rpm[1]);
  Serial.write(serbuf, len);

  delay(interval);
}
