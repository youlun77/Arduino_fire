#include <WiFi.h>
#include <WiFiClientSecure.h>

char SSID[] = "TOTOLINK_N200RE";
char PASSWORD[] = "0935273776";
WiFiClientSecure client;

int sensorPin=14; // select the input pin for the LDR
int led=15;
int sensorValue = HIGH;
char host[]="notify-api.line.me";
String Linetoken = "I8ldiiKangjbd8rGLfFmdpdrmPZGKq8hMcGjnKaD0uA";

void setup() 
{
  Serial.begin(115200);
  Serial.print("Connecting Wifi: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  pinMode(led, OUTPUT);
}

void loop() 
{
  sensorValue = digitalRead(sensorPin);
  if(sensorValue==LOW)
  {
     int n;
     Serial.println("Fire Detected");
     Serial.println("LED on");
     digitalWrite(led,HIGH);
     String message="你家失火";
     n=client.connect(host,443);
     client.setInsecure();
     if (n) 
     {
      int LEN = message.length();
      String url = "/api/notify";
      client.println("POST " + url + " HTTP/1.1");
      client.print("Host: "); client.println(host);
      //權杖
      client.print("Authorization: Bearer "); client.println(Linetoken);
      client.println("Content-Type: application/x-www-form-urlencoded");
      client.print("Content-Length: "); client.println( String((LEN + 8)) );
      client.println();      
      client.print("message="); client.println(message);
      client.println();
      //等候回應
      delay(2000);
      String response = client.readString();
      //顯示傳遞結果
      Serial.println(response);
      client.stop(); //斷線，否則只能傳5次
     }
     else //傳送失敗
      Serial.println("connected fail");
     delay(1000);
     sensorValue=HIGH;
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("No Fire");
    delay(1000);
  }
}
