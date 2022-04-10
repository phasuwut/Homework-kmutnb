#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Set the LCD address to 0x27 or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


int pin_LED_IN=13;
int pin_LED_OUT=15;

void setup() {
  // put your setup code here, to run once:
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // LED

  // print a random number from 10 to 19
  int randNumber = random(-50, 50);
  Serial.println(randNumber);


  lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("total");
  
  lcd.setCursor(0, 1);
  char buffer_2 [16]; // a few bytes larger than your LCD line
  sprintf (buffer_2, "Total = %d ", randNumber); // send data to the buffer
  lcd.print (buffer_2); // display line on buffer






 delay(1000);

}
