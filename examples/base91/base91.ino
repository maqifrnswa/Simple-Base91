#include <base91.h>

void setup() {
  Serial.begin(9600);
  Serial.flush();
  delay(100);
  Serial.println(F("Base91 Encode/Decode Test"));

  const uint8_t data[] = {0x11, 0x1e, 0x10, 0x55};
  size_t datasize = 4;
  char output[10];
  uint8_t decoding[10];

  Serial.println(F("\nRaw Data: "));
  for (int i = 0; i < datasize; i++) {
    Serial.print(F("0x"));
    Serial.println(data[i], HEX);
  }

  Serial.println(F("\nEncoded string: "));
  size_t n = encodeBase91(data, datasize, output);
  for (int i; i < n; i++) Serial.print(output[i]);
  Serial.println();
  Serial.println(F("\nDecoded HEX:"));

  size_t n2 = decodeBase91(output, n, decoding);
  for (int i = 0; i < n2; i++) {
    Serial.print(F("0x"));
    Serial.println(decoding[i], HEX);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
