
#include <Arduino.h>
#include <Ds1302.h>

Ds1302 rtc(13, 11, 12);
int arr[5] = {2,3,4,5,6};
int B[4] = {7,8,9,10};

int secounds = 0;
int minutes = 50;
int hours = 12;

void setup() {
  Serial.begin(9600);
  rtc.init();
  for(int i =0;i<5;i++){
    if(i < 5){
        pinMode(B[i],OUTPUT);
    }
    pinMode(arr[i],OUTPUT);
  }
  Serial.begin(9600);
    
}

void dec_to_display(int n){
  int bina[4];
  int m = n;
  int r;
  for(int i = 0;i<4;i++){
    r = m%2;
    bina[i] = r;
    m = m/2;
  }
  for(int i = 0;i<4;i++){
    digitalWrite(B[i],bina[i]);
  }
}
void display_pos(int i){
    digitalWrite(arr[i],1);
    delay(2);
    digitalWrite(arr[i],0);
}
void two_digit_display(int x,int pos_b0){  
  int b1 = x/10;
  int b0 = x - b1*10;
  dec_to_display(b0);
  display_pos(pos_b0);
  dec_to_display(b1);
  display_pos(pos_b0+1);
}
void loop() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);
  two_digit_display(now.hour,3);
  two_digit_display(now.minute,1);
  dec_to_display(now.second/10);
  display_pos(0);
  //dec_to_display(0);
  // digitalWrite(B[0],0);
  // digitalWrite(B[1],0);
  // digitalWrite(B[2],0);
  // digitalWrite(B[3],0);
  // display_pos(1);
  /*
  Serial.print(now.day);
  Serial.print("  ");
  Serial.print(now.month);
  Serial.print("  ");
  Serial.print(now.year);
  Serial.print("  ");
  Serial.print(now.dow);
  Serial.println();
  */
  

}
