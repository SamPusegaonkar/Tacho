/*
 * A tachometer is a device used to mesure the rpm of a motor or any other rotating device. The following code is the implementation of the same.
 */

int ledPin = 13,rpm,rev;                // IR LED connected to digital pin 13
unsigned long timeold;
int redPin= 7;
int greenPin = 6;
int bluePin = 5;
void interrupt(){
      rev++;
}
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
void setup(){
   attachInterrupt(0, interrupt, FALLING);
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, HIGH);
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   rev = 0;
   rpm = 0;
   timeold = 0;
}
void loop(){
   delay(1000); //Update RPM every second
   detachInterrupt(0);
   rpm = 30*1000/(millis() - timeold)*rev; //Compute
   timeold = millis();
   rev = 0;
   
   if(rpm>0 && rpm <=10)
    setColor(255, 255, 255);
   else if(rpm>10 && rpm <=20)
    setColor(255, 192, 203);
   else if(rpm>20 && rpm <=30)
    setColor(255, 0, 0);
   else if(rpm>30 && rpm <=40)
    setColor(255, 99, 71);
   else if(rpm>40 && rpm <=50)
    setColor(255, 255, 0);
   else if(rpm>50 && rpm <=60)
    setColor(0, 0, 255);
   else if(rpm>60 && rpm <=70)
    setColor(230, 230, 250);
   else if(rpm>70 && rpm <=80)
    setColor(0, 255, 0);
   else if(rpm>80 && rpm <=90)
    setColor(165, 42, 42);
   else if(rpm>90 && rpm <=100)
    setColor(173, 216, 230);
   attachInterrupt(0, interrupt, FALLING); //Restart the interrupt processing
}
