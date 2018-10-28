#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
 
TMRpcm tmrpcm;   // create an object for use in this sketch
 int SW1; 
<<<<<<< HEAD
 int old_SW1=0;

void setup(){
 Serial.begin(9600);
 Serial.println("Start");
 pinMode(6,INPUT);  //Define A0 as digital input.
=======

void setup(){
 pinMode(14,INPUT);  //Define A0 as digital input.
>>>>>>> master

 
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
<<<<<<< HEAD
    Serial.println("no SDCard");
  return;   // don't do anything more if not
  }
 
 tmrpcm.setVolume(5);
 tmrpcm.volume(1);

 
}
 
void loop(){  
 SW1=digitalRead(6); 

     if ((SW1 == LOW) && (SW1!=old_SW1)) { //if SW1 pressed then play file "6.wav"
      Serial.println("Playing:");
      Serial.print(SW1);
      tmrpcm.play("356er.wav");
    }
    old_SW1=SW1; 
=======
  return;   // don't do anything more if not
  }
 tmrpcm.volume(1);
 tmrpcm.play("1.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
}
 
void loop(){  
 SW1=digitalRead(14); 

     if (SW1 == LOW) { //if SW1 pressed then play file "6.wav"
      tmrpcm.play("356er.wav");
    } 
>>>>>>> master
  
}
