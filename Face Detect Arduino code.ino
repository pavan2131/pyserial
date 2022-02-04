#include <Servo.h>
Servo myservo;
int pos = 0; 

int ledPin = 13; // LED connected to digital pin 13
int buzzerPin = 11; //buzzer connected to digital pin 11
char incomingBit;    // for incoming serial data
 
void setup() {
  
  pinMode(ledPin, OUTPUT);  
  myservo.attach(9);// sets the digital pin 9 as output for servo
  pinMode(buzzerPin,OUTPUT);//sts the digital pin 11 as output for buzzer
  
  Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
}
void loop() {
  
  if (Serial.available() > 0) {
    
        // read the incoming byte:
        incomingBit = Serial.read();
        Serial.println(incomingBit);
                if(incomingBit == 'Y' || incomingBit == 'y') {
                  
                    //Sets Led  ON 
                    digitalWrite(ledPin, HIGH);

                    //Sets Buzzer ON for 1 sec
                    tone(11,1700);
                    delay(1000);
                    noTone(11);
                    
                    //Open Door for 10 sec
                    for(pos = 0;pos<=50;pos += 1)//open Door using servo 
                    {
                     myservo.write(pos);
                     delay(15);//wait 15ms 
                    }
                    delay(10000);//let door be open for 10 sec
          
                }
                else 
                {
                  //Sets led OFF if no face detected 
                  digitalWrite(ledPin, LOW); 

                  //close door if no face detected   
                  for(pos  = 50;pos>=0;pos -=1)
                  {
                  myservo.write(pos);
                  delay(15);//wait 15ms
                  }
                }
    }
}
