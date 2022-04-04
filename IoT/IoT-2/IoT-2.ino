#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 

int pin_pir_input=0;
int pin_pir_output=2;
int pin_buzzer=12;

int count=0;
void setup() {
  pinMode(pin_pir_input, INPUT);
  pinMode(pin_pir_output, INPUT);  
  
  pinMode(pin_buzzer, OUTPUT); // sets the pin as output

  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

  Serial.begin(9600);
}
   
void loop() {
 
}
