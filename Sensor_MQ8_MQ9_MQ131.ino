//--------------------------------------------------------------
//--------------------------------------------------------------
//        Single-Zone-Horizontal-Tube-Furnace
//        Menggunakan Jenis Sensor MQ
//        MQ-9   => (Carbon Monoxide(CO)        
//        MQ-8   => (Hydrogen(H)       
//        MQ-131 => (Sensor Oxygen(O2))
//---------------------------------------------------------------
//---------------------------------------------------------------
//          Universitas Negeri Medan
//          Jurusan Fisika
//          Laboratorium Fisika
//---------------------------------------------------------------
//---------------------------------------------------------------

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  
                      // LiquidCrystal_I2C lcd(0x3F,20,4);


const int PIN_ANALOG1 = 0;
const int PIN_ANALOG2 = 1;
const int PIN_ANALOG3 = 2;

void setup()
{
  Serial.begin(9600); //Starts the serial communication     
  lcd.init();
  lcd.backlight();        
  lcd.begin(20,4);              
  lcd.clear();
  
  lcd.setCursor(5,0);
  lcd.print("Sensor Gas");
  
  lcd.setCursor(0,1);
  lcd.print ("O2 =");
  
  lcd.setCursor(0,2);
  lcd.print ("CO =");
  
  lcd.setCursor(0,3);
  lcd.print ("H  =");
  
  lcd.setCursor(9,1);
  lcd.print ("ppm");                 

  lcd.setCursor(9,2);
  lcd.print ("ppm");

  lcd.setCursor(9,3);
  lcd.print ("ppm"); 
    
}
void loop()
{
  int A0 = analogRead(PIN_ANALOG1);
  int A1 = analogRead(PIN_ANALOG2);
  int A2 = analogRead(PIN_ANALOG3);
  
  lcd.setCursor(5,1);
  lcd.print(A0);
  
  lcd.setCursor(5,2);
  lcd.print(A1);

  lcd.setCursor(5,3);
  lcd.print(A2);
  
  delay(2000);
}
