/*
 * iot-temp for iot 
 {"data": {"temp":"22", "humid":44}}
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// wifi
const char* publish_topic = "@msg/door";
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

long lastMsg = 0;

char msg_fb[100];

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
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    String total = String(random(15,100));
    String day = String(random(20,70));
    String data = "{\"total\":"+total+",\"day\":"+day+"}";
    String payload = "{\"data\":" + data + "}";
    Serial.println(payload);
    payload.toCharArray(msg_fb, (payload.length() + 1));
    client.publish("@shadow/data/update", msg_fb);
 
  }
  delay(10); 
}
