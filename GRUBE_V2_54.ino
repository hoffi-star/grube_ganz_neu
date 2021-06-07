#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);








/* -----------------pinbelegung--------------------------------------------------------------
D1-leer
D2-leer
D3-leer
D4-leer
D5-leer
D6-leer
D7-leer
D8-leer
D9- sens 4
D10-sens 3
D11-sens 2
D12-sens 1

A1-leer
A2-leer
A3-leer
A4-DISPLAY
A5-DISPLAY
-------------------------------------------------------------------------------------*/


int SENS4 = 9; //Arduino Pin 9
int SENS3 = 10; //Arduino Pin 10
int SENS2 = 11; //Arduino Pin 11
int SENS1 = 12; //Arduino Pin 12
int warte =20 ;
int vari = 0 ;

int senssta1=0;
int senssta2=0;
int senssta3=0;
int senssta4=0;

void setup() {

Serial.begin(9600);                                      // Starte die kommunikation 

lcd.init();
lcd.backlight();
delay(250);
lcd.noBacklight();
delay(250);
lcd.backlight();
delay(500);

pinMode(SENS1, INPUT);
pinMode(SENS2, INPUT);
pinMode(SENS3, INPUT);
pinMode(SENS4, INPUT);

}


void loop() 
{

int senssta1=0;
int senssta2=0;
int senssta3=0;
int senssta4=0;
delay (50);

/*senssta1=digitalRead(SENS1);
senssta2=digitalRead(SENS2);
senssta3=digitalRead(SENS3);
senssta4=digitalRead(SENS4);*/
/*---------------Neu----------------------------------------*/

 if (digitalRead(SENS4) == HIGH)
  {
    Serial.println("übervoll"); // **************************************************************
    delay (5000) ; // ****************************************************************************
    goto label4;
  }
if (digitalRead(SENS3) == HIGH)
  {
    Serial.println("voll"); // **************************************************************
    delay (5000) ; // ****************************************************************************
   goto label3;
  }
  if (digitalRead(SENS2) == HIGH)
  {
    Serial.println("halbvoll"); // **************************************************************
    delay (5000) ; // ****************************************************************************
  
   goto label2;
  }
  if (digitalRead(SENS1) == HIGH)
  Serial.println("25%"); // **************************************************************
    delay (5000) ; // ****************************************************************************
  {
   goto label1 ;
  }

/*------------------------------neu end------------------------*/

/*if (senssta4 == 1 ){ goto label4;}
if (senssta3 == 1 ){ goto label3;}
if (senssta2 == 1 ){ goto label2;}
if (senssta1 == 1 ){ goto label1;}*/




delay (200) ;
goto end2;

/*-------------------------------------------------------------*/
label4:
lcd.setCursor(0, 0);
lcd.print("                          ");
lcd.setCursor(0, 0);
lcd.print("!!!Ueberfuellt!!!");
delay (150) ;
goto end1 ;
/*------------------------------------------------------------------*/
label3:
lcd.setCursor(0, 0);
lcd.print("                          ");
lcd.setCursor(0, 0);
lcd.print("!!!VOLL!!!");
delay (150) ;
goto end1 ;
/*---------------------------------------------------------------*/
label2:
lcd.setCursor(0, 0);
lcd.print("                          ");
lcd.setCursor(0, 0);
lcd.print("HALB VOLL");
delay (150) ;
goto end1 ;
/*----------------------------------------------------------*/
label1:
lcd.setCursor(0, 0);
lcd.print("                          ");
lcd.setCursor(0, 0);
lcd.print("25% VOLL");
delay (150) ;
goto end1 ;



end2:
lcd.setCursor(0, 0);
lcd.print("                          ");
lcd.setCursor(0, 0);
lcd.print("0% VOLL");
delay (150) ;
end1: ;



}
