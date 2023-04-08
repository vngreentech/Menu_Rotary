#include <Arduino.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int phaA = 2;
int phaB = 3;
int nutnhan = 7; int gtnutnhan;

int dem = 0; int hientai; int bandau; 
int dem_moi; int dem_cu;
  
void setup() 
{ 
   Serial.begin (9600);
   
   pinMode(phaA,INPUT);
   pinMode(phaB,INPUT);
   pinMode(nutnhan, INPUT);
      
   bandau = digitalRead(phaA);   
} 

void loop() 
{ 
   gtnutnhan = digitalRead(nutnhan); 
   //Serial.print("Nút nhấn: "); Serial.println(gtnutnhan);
   
   hientai = digitalRead(phaA);   
   if (hientai != bandau)
   {     
     if (digitalRead(phaB) != hientai) 
     { 
       dem ++;
       dem_moi = dem / 10;
       if(dem_moi >= 5)
       {
         dem_moi = 5;
       }
     } 
     else 
     {
       dem --;
       dem_moi = dem / 10;
       if(dem_moi <= 0)
       {
         dem_moi = 0;
       }
     }
     Serial.print("Đếm: "); Serial.print(dem); Serial.print("   ");
     Serial.print("Mới: "); Serial.println(dem_moi);
   } 
   bandau = hientai;
//Serial.print("Giá trị: "); Serial.println(dem);
}