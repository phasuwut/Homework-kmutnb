#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);


int pin_pir_input=0;
int pin_pir_output=2;
int pin_buzzer=12;

int pin_LED_IN=13;
int pin_LED_OUT=15;

int valInput = 0;
int valOutput = 0;

int dataInput=0;
int dataOutput=0;

int count=0;
void setup() {
  pinMode(pin_pir_input, INPUT);
  pinMode(pin_pir_output, INPUT);  
  
  pinMode(pin_buzzer, OUTPUT); // sets the pin as output

  pinMode(pin_LED_IN, OUTPUT); // sets the pin as output
  pinMode(pin_LED_OUT, OUTPUT); // sets the pin as output

  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

  Serial.begin(9600);
}
   
void loop() {
  valInput = digitalRead(pin_pir_input); 
  valOutput = digitalRead(pin_pir_output); 


    if (valInput == 1) { // ค่า เป็น 0 ตรวจจับเจอวัตถุ สั่งให้ไฟ LED ติด
        beep(500);
        count=count+1;
        dataInput=1;
    }

    lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
    lcd.print("count");
    lcd.setCursor(6, 1); // ไปที่ตัวอักษรที่ 6 แถวที่ 2
    lcd.print(count);

  //delay(100);
}




// buzzer
void beep(unsigned char delayms){
  analogWrite(pin_buzzer, 20); // Almost any value can be used except 0 and 255
  // experiment to get the best tone
  delay(delayms); // wait for a delayms ms
  analogWrite(pin_buzzer, 0); // 0 turns it off
  delay(delayms); // wait for a delayms ms
}

void openBuzzer(){
  tone(pin_buzzer, 500);
  delay(500);
  tone(pin_buzzer, 1000);
  delay(500);
}
