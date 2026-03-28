#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "your_wifi_ssid";       
const char* password = "your_wifi_password";       
const char* udpAddress = "your_pc_ip"; 
const int udpPort = 4210;

WiFiUDP udp;

const int potPin = 36;   
const int trigPin = 5;   
const int echoPin = 18;  

void setup() {
  Serial.begin(115200);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Conectat!");
}

void loop() {
  int throttleRaw = analogRead(potPin); 
  int throttlePercent = map(throttleRaw, 0, 4095, 0, 100); 

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); 
  int distanceCm = duration * 0.034 / 2;
  
  if(distanceCm == 0) distanceCm = 999; 

  char packetBuffer[50];
  sprintf(packetBuffer, "ACCEL:%d%%,DIST:%dcm", throttlePercent, distanceCm);

  udp.beginPacket(udpAddress, udpPort);
  udp.print(packetBuffer);
  udp.endPacket();

  Serial.println(packetBuffer);
  
  delay(60); 
}
