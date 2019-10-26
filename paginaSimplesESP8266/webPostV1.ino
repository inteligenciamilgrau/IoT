#include "ESP8266WiFi.h"

// caso seja uma rede local, o server será algo que lembra por exemplo 192.168.0.101 de acordo com o IP do servidor
const char server[] = "inteligenciamilgrau.com.br"; 

const char* MY_SSID = "seu_SSID_de_internet";
const char* MY_PWD =  "sua_senha";

WiFiClient client;

void setup()
{
  Serial.begin(115200);
  Serial.print("Connecting to "+*MY_SSID);
  WiFi.begin(MY_SSID, MY_PWD);
  Serial.println("going into wireless connect");

  while (WiFi.status() != WL_CONNECTED) //not connected,  ...waiting to connect
    {
      delay(1000);
      Serial.print(".");
    }
  Serial.println("wireless connected");
  Serial.println("Credentials accepted! Connected to wifi\n ");
}

void loop() {
  int leituraAnalogica = analogRead(A0);

  if (isnan(leituraAnalogica))
  {
    Serial.println("Problemas na leitura!");
    return;
  }
  Serial.println(leituraAnalogica);
  
  if (client.connect(server, 80)) {

    String data = "LeituraAnalogica=" + (String) leituraAnalogica;

     //coloque a URL específica que quer entrar
     client.println("POST /arduino/recebe_dados_arduino.php HTTP/1.1"); 
     //coloque a URL abaixo da página que quer acessar
     client.println("Host: inteligenciamilgrau.com.br");                 
     client.println("User-Agent: ESP8266/1.0");
     client.println("Connection: close"); 
     client.println("Content-Type: application/x-www-form-urlencoded");
     client.print("Content-Length: ");
     client.println(data.length());
     client.println("");
     client.println(data);
     client.stop(); 
          
     delay(100);
    } 
}
