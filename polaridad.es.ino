
/*////WIRING
PCF8591---NODECMU
  VCC---->3V
  GND---->G
  SDA---->D3
  SLC--->D4


*/

#define DIRECCION_PCF8591 B1001000 // 1 0 0 1 A2 A1 A0
#define DIRECCION_A0 B00
#define DIRECCION_A1 B01
#define DIRECCION_A2 B10
#define DIRECCION_A3 B11
#define ESPERA_LECTURAS 1000

#include <Wire.h>

long cronometro_lecturas=0;
long tiempo_transcurrido;

void setup()
{
  Wire.pins(0, 2); 
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  tiempo_transcurrido=millis()-cronometro_lecturas;
  
  
  if(tiempo_transcurrido>ESPERA_LECTURAS)
  {
    cronometro_lecturas=millis();
    Wire.beginTransmission(DIRECCION_PCF8591);
    Wire.write(DIRECCION_A0);
    Wire.endTransmission();
    Wire.requestFrom(DIRECCION_PCF8591,2); // Pedir dos bytes a la dirección del PCF8591
    Wire.read(); // Ignorar el valor anterior del registro DAC
    Serial.println("A0");
    Serial.println(Wire.read());
     
}

if(tiempo_transcurrido>ESPERA_LECTURAS)
  {
    cronometro_lecturas=millis();
    Wire.beginTransmission(DIRECCION_PCF8591);
    Wire.write(DIRECCION_A1);
    Wire.endTransmission();
    Wire.requestFrom(DIRECCION_PCF8591,2); // Pedir dos bytes a la dirección del PCF8591
    Wire.read(); // Ignorar el valor anterior del registro DAC
    Serial.println("A1");
    Serial.println(Wire.read());
   
}
if(tiempo_transcurrido>ESPERA_LECTURAS)
  {
    cronometro_lecturas=millis();
    Wire.beginTransmission(DIRECCION_PCF8591);
    Wire.write(DIRECCION_A2);
    Wire.endTransmission();
    Wire.requestFrom(DIRECCION_PCF8591,2); // Pedir dos bytes a la dirección del PCF8591
    Wire.read(); // Ignorar el valor anterior del registro DAC
    Serial.println("A2");
    Serial.println(Wire.read());
    
}

  if(tiempo_transcurrido>ESPERA_LECTURAS)
  {
    cronometro_lecturas=millis();
    Wire.beginTransmission(DIRECCION_PCF8591);
    Wire.write(DIRECCION_A3);
    Wire.endTransmission();
    Wire.requestFrom(DIRECCION_PCF8591,2); // Pedir dos bytes a la dirección del PCF8591
    Wire.read(); // Ignorar el valor anterior del registro DAC
    Serial.println("A3");
    Serial.println(Wire.read());
   
}

delay(5000);
 Serial.println();
 Serial.println();

 

}
