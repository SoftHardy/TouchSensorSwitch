#include <CapacitiveSensor.h>
int i=0;
CapacitiveSensor   cs= CapacitiveSensor(6,7);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  long cslv=cs.capacitiveSensor(80);
  if(cslv>1000){
    if(i%2==0){
    Serial.println("Pressed");
    Serial.println(cslv);
    i++;
    delay(1000);
  }else{
    Serial.println("Pressed Again");
    Serial.println(cslv);
    i++;
    delay(1000);
  }
  }
  // put your main code here, to run repeatedly:
//Serial.println(cslv);
//delay(500);
}
