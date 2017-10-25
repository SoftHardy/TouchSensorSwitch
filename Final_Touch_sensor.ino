#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//String  i;
WiFiServer server(80);

String  httpurl;
HTTPClient http;

/*  pin 16 sync with pin 14 and with variable i;
 *  pin 05 sync with pin 12 and with variable j;
 *  pin 04 sync with pin 13 and with variable k;
 *  pin 02 sync with pin 15 and with variable l;
*/

int i=0;
int j=0;
int k=0;
int l=0;



void setup()
{
  //i = "";

  Serial.begin(9600);

  pinMode(16, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);

  /*pinMode(14, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(15, INPUT);
  */
  WiFi.disconnect();
  delay(2000);
  Serial.println("Start Touch Switch");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  Serial.println("My IP is:");
  Serial.println((WiFi.localIP()));
  server.begin();

}

void loop()
{
  //Serial.println("In the loop");
  WiFiClient client = server.available();
    /*if (!client) { Serial.println("Not Client");
    return; }
    while(!client.available()){Serial.println("Not client available");
    delay(1); }
*/
Serial.println("Before IF");

    if (digitalRead(16))
{
  Serial.println("Cond true");
  if(i%2==0)
  {
  Serial.println("HIGH I");
  
  httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="CHANDELIER_ON";
  http.begin(httpurl);
  http.GET();
  http.end();
  
  i++;
  delay(1000);
  }else{
    Serial.println("LOW I");

    httpurl = "http://";
    httpurl+="192.168.1.107";
    httpurl+="/";
    httpurl+="CHANDELIER_OFF";
    http.begin(httpurl);
    http.GET();
    http.end(); 
    
    i++;
    delay(1000);
  }
  
}

if (digitalRead(5))
{
  Serial.println("Cond true");
  if(j%2==0)
  {
  Serial.println("HIGH J");
  
  httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_16_ON";
  http.begin(httpurl);
  http.GET();
  http.end();
  
  j++;
  delay(1000);
  }else{
    Serial.println("LOW J");
    
    httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_16_OFF";
  http.begin(httpurl);
  http.GET();
  http.end();
  
    j++;
    delay(1000);
  }
  
}

if (digitalRead(4))
{
  Serial.println("Cond true");
  if(k%2==0)
  {
  Serial.println("HIGH K");

  httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_5_ON";
  http.begin(httpurl);
  http.GET();
  http.end();
  
  k++;
  delay(1000);
  }else{
    Serial.println("LOW K");
    
    httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_5_OFF";
  http.begin(httpurl);
  http.GET();
  http.end();
  
    k++;
    delay(1000);
  }
  
}

if (digitalRead(2))
{
  Serial.println("Cond true");
  if(l%2==0)
  {
  Serial.println("HIGH L");

  httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_4_ON";
  http.begin(httpurl);
  http.GET();
  http.end();
  
  l++;
  delay(1000);
  }else{
    Serial.println("LOW L");
    
    httpurl = "http://";
  httpurl+="192.168.1.107";
  httpurl+="/";
  httpurl+="109_4_OFF";
  http.begin(httpurl);
  http.GET();
  http.end();
  
    l++;
    delay(1000);
  }
    
}
//delay(1000);
}
