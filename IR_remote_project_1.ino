#include <IRremote.h>
#define PIN 2
#define Relay1 13
#define Relay2 4
#define Relay3 5
#define Relay4 6
#define Relay5 7
#define Relay6 8
#define Relay7 9
#define Relay8 10
IRrecv irrecv(PIN);
decode_results results;

 
#define remotevalue1 16724175  

 
 
byte relay1 = 0;
long value;
 
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Relay1, OUTPUT);
  
 
  for (int a = 3; a <= 10; a++ ) {
    digitalWrite(a, HIGH);
  }
 
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    value = (results.value);
    irrecv.resume();
  }
  delay(400);
 
  if (value == remotevalue1  && relay1 == 0 ) {
    digitalWrite(Relay1, LOW);
    relay1 = 1;
    value = 0;
  } else if (value == remotevalue1 && relay1 == 1 ) {
    digitalWrite(Relay1, HIGH);
    relay1 = 0;
    value = 0;
  }
}
