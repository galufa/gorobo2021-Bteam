#include <Wire.h>
#include "LoopCycleController.h"
const int lis[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
byte a; byte b;
LoopCycleController loopCtrl(1000);

void setup(){
  for(int i=0;i<12;i++){
    pinMode(lis[i],INPUT_PULLUP);
  }
  Wire.begin(9);
  Wire.onRequest(okuru);
}

void loop(){
  for(int n=0;n<12;n++){
    if(digitalRead(lis[n])==0){
      if(n<8){bitWrite(a,n,0);}
      if(9<n){bitWrite(b,n,0);}
      }
    else {
      if(n<8){bitWrite(a,n,1);}
      if(9<n){bitWrite(b,n,1);}
      }
  }
  loopCtrl.Update();
}

void okuru(){
  Wire.write(a);
  Wire.write(b);
}
