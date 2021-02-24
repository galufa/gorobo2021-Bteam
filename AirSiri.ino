//エアシリンダァ,０のときちぢむ,１のときのびる
#include<Wire.h>
#include"LoopCycleController.h"
LoopCycleController loopCtrl(1000);
const int Siri = 10;
int onof ;

void setup() {
  delay(1000);
  onof =0;
  Wire.begin(4);
  Serial.begin(115200);
  Wire.onReceive(receiveEvent);
  pinMode(Siri, INPUT_PULLUP);
  digitalWrite(10, LOW);
}

void loop() {
    digitalWrite(10, onof);
  loopCtrl.Update();
}

void receiveEvent(int Howmany) {
  while (Wire.available()) {
    onof = Wire.read();
  }
}
