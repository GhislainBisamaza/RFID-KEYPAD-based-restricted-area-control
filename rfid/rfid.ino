#include <AltSoftSerial.h>// Rx =8, Tx= 9
AltSoftSerial altSerial;
String tag;
int forward=4;
int reverse=5;
int x;
void setup()
{
 
  Serial.begin(9600);
 
 altSerial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
}

char c;

void loop(){
    while(altSerial.available()>0){
    c=altSerial.read();
    tag += c;
  }
tag=tag.substring(0,13);
while(tag.length()>0)
{
Serial.println(tag);


if(tag=="00001610696F") {
  x=0;
  while(x<1){
  digitalWrite(4,HIGH);
digitalWrite(5,LOW);
delay(5000);
digitalWrite(4,LOW);
 digitalWrite(5,HIGH);
 delay(5000);
 digitalWrite(5,LOW);
 x+=1;
 
}
}
tag="";
delay(200);

tag="";
}
delay(200);
tag="";
}


