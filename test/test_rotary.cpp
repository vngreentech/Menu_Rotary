/* Read Quadrature Encoder
   Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.

   Sketch by max wolf / www.meso.net
   v. 0.1 - very basic functions - mw 20061220

*/
#include <Arduino.h> 
#include <Wire.h>

int phaA = 2; int phaB = 3;
int dem = 0; int dem2 = 0;
int phaA_last = LOW;
int n = LOW;

void setup() 
{
  pinMode (phaA, INPUT);
  pinMode (phaB, INPUT);
  Serial.begin (9600);
}

void loop() 
{
  n = digitalRead(phaA);

  if ((phaA_last == LOW) && (n == HIGH)) 
  {
    if (digitalRead(phaB) == LOW) 
    {
      dem ++;
      dem2 ++;
    } 
    else 
    {
      dem --;
      dem2 --;
    }
    Serial.print (dem); Serial.print ("   ");   Serial.println (dem2); 
  }
  phaA_last = n;
}