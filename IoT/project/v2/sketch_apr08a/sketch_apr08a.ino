/*
 * iot-temp for iot 
 {"data": {"temp":"22", "humid":44}}
 */


#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 

// wifi
const char* publish_topic_total = "@msg/door/total";
const char* publish_topic_day = "@msg/door/day";


const char* ssid = "phasuwut";
const char* password = "0909791498";

// MQTT
const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "af5376d8-b8e2-45db-82e4-0a11e6f4ad2f";
const char* mqtt_username = "gmJFjvwBYgwKxgQA3dW35waQDSfJ8y3i";
const char* mqtt_password = "4GAW1LYp2#EWxGUCx0NDZ43MP1FY8N-u";

WiFiClient espClient;
PubSubClient client(espClient);
LiquidCrystal_I2C lcd(0x27, 16, 2);

long lastMsg = 0;
char msg_fb[100];
char msgTotal[50]; 
char msgDay[50]; 


// board
int pin_pir_input=0;
int pin_pir_output=2;
int pin_buzzer=12;
int pin_LED_IN=13;
int pin_LED_OUT=15;
int valInput = 0;
int valOutput = 0;
int dataInput=0;
int dataOutput=0;
int day=0;
int total=0;






void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection…");
    if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) {
      Serial.println("connected");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // MQTT
  client.setServer(mqtt_server, mqtt_port);


  // board
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


  
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

    // input 
    valInput = digitalRead(pin_pir_input); 
    Serial.print("valInput = ");
    Serial.println(valInput);
    if (valInput == 0) {
      digitalWrite(pin_LED_IN, LOW);
    }
    else {
        digitalWrite(pin_LED_IN, HIGH);
        day=day+1;
        total=total+1;
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
        day=day-1;
        beep(500);
    }


  // LED
  lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print(total);
  lcd.setCursor(0, 1); // ไปที่ตัวอักษรที่ 6 แถวที่ 2
  lcd.print(day);
 



  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    // MQTT
    //String total = String(random(15,100));
    //String day = String(random(20,70));
    String data = "{\"total\":"+String(total)+",\"day\":"+String(day)+"}";
    String payload = "{\"data\":" + data + "}";
    Serial.println(payload);
    payload.toCharArray(msg_fb, (payload.length() + 1));
    client.publish("@shadow/data/update", msg_fb);

    // Publish
    snprintf (msgTotal, 50, "Total #%ld",total);  //เตรียมข้อมูลก่อนที่จะ Publish
    client.publish(publish_topic_total, msgTotal); 
    snprintf (msgDay, 50, "Day %ld", day);  //เตรียมข้อมูลก่อนที่จะ Publish
    client.publish(publish_topic_day, msgDay); 
 
  }
 // delay(10); 
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
