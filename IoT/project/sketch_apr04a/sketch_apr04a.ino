#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Set the LCD address to 0x27 or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
int num=0;

void setup(){
  pinMode(pin_pir_input, INPUT);
  pinMode(pin_pir_output, INPUT);  
  pinMode(pin_buzzer, OUTPUT); // sets the pin as output

  pinMode(pin_LED_IN, OUTPUT); // sets the pin as output
  pinMode(pin_LED_OUT, OUTPUT); // sets the pin as output
  digitalWrite(pin_LED_OUT, LOW); 
  digitalWrite(pin_LED_OUT, LOW);
   
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();

  Serial.begin(9600);
 
}
void loop() {

    // input 
    valInput = digitalRead(pin_pir_input); 
    Serial.print("valInput = ");
    Serial.println(valInput);
    if (valInput == 0) {
      digitalWrite(pin_LED_IN, LOW);
    }
    else {
        digitalWrite(pin_LED_IN, HIGH);
        count=count+1;
        num=num+1;
        beep(500);
    }


    // Out
    valOutput = digitalRead(pin_pir_output);
    Serial.print("valOutput = ");
    Serial.println( valOutput); 
    if (valOutput == 0) {
      digitalWrite(pin_LED_OUT, LOW);
    }
    else {
        digitalWrite(pin_LED_OUT, HIGH);
        count=count-1;
        beep(500);
    }


  // LED
  lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print(num);
  lcd.setCursor(0, 1); // ไปที่ตัวอักษรที่ 6 แถวที่ 2
  lcd.print(count);
  

  Serial.println(count); 
  Serial.println(""); 
  delay(500);

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
