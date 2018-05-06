#include <Base64.h>

/*
 Base64 Encode/Decode example
 
 Encodes the text "Hello world" to "SGVsbG8gd29ybGQA" and decodes "Zm9vYmFy" to "foobar"

 Created 29 April 2015
 by Nathan Friedly - http://nfriedly.com/
 
 This example code is in the public domain.

 */


void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  Serial.println("Base64 example");
  
  // encoding
  char input[] = "Hello world";
  //int inputLen = sizeof(input) - 1; // don't count the trailing \0 of srings
  int inputLen = strlen(input);
  
  int encodedLen = base64_enc_len(inputLen);
  char encoded[encodedLen + 1]; // add +1 for terminating /0
  
  // note input is consumed in this step: it will be empty afterwards
  base64_encode(encoded, input, inputLen); 

  // moved print to after encode function to validate that the input is not corrcupted
  Serial.print(input); Serial.print(" = ");
  Serial.println(encoded);
  
  Serial.print("Input length = "); Serial.println(inputLen); 
  Serial.print("Encoded length = "); Serial.println(encodedLen); 

  // check if the last character is \0
  Serial.print("last: ");
  Serial.println(byte(encoded[encodedLen]));
  
  // decoding previously encoded string
  
  int decodedLen = base64_dec_len(encoded, encodedLen);
  int input2Len = sizeof(encoded) - 1; // don't count the trailing \0 of srings
  char decoded[decodedLen + 1]; // add +1 for terminating /0 os the string
  
  base64_decode(decoded, encoded, input2Len);
  
  Serial.print(encoded); Serial.print(" = "); Serial.println(decoded);

  Serial.print("Input2 length = "); Serial.println(input2Len); 
  Serial.print("Decoded length = "); Serial.println(decodedLen); 

  // check if the last character is \0
  Serial.print("last: ");
  Serial.println(byte(decoded[decodedLen]));

  Serial.println();
   // decoding
  char input3[] = "Zm9vYmFy";
  int input3Len = sizeof(input3) - 1; // don't count the trailing \0 of srings
  
  int decoded2Len = base64_dec_len(input3, input3Len);
  char decoded2[decodedLen + 1]; // add +1 for terminating /0
  
  base64_decode(decoded2, input3, input3Len);
  
  Serial.print(input3); Serial.print(" = "); Serial.println(decoded2);
  Serial.print("Input3 length = "); Serial.println(input3Len); 
  Serial.print("Decoded2 length = "); Serial.println(decoded2Len); 
}


void loop()
{
  
}

