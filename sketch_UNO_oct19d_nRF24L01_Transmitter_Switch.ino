//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  //_ER
  pinMode(LED_BUILTIN, OUTPUT);//
  pinMode(A0, INPUT);
  pinMode(A0, INPUT_PULLUP);  // set pull-up on analog pin 0

  //digitalRead(A0);
  //_ER_
    radio.begin();
  
    radio.setPALevel(RF24_PA_MAX); //_ER
    //set the address
    radio.openWritingPipe(address);
  
    //Set module as transmitter
    radio.stopListening();

}
void loop()
{

  
  byte by = 1;
  by = digitalRead(A0);
// Serial.write("abc\n");
  if (by == 0)
  { digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.write("abc1\n");
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW}
    Serial.write("abc2\n");
    delay(1000);

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.write("abc3\n");
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW}
    Serial.write("abc4  \n");

    delay(1000);
    //Send message to receiver
    const char text[] = "Hello World";
    Serial.write("abc5\n");
    radio.write(&text, sizeof(text));
    Serial.write("abc6\n");
    delay(1000);
  }
}
