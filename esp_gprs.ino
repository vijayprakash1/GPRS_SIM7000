In this project we are going to Interface ESP32 with SIM7000 module to send data on the server with help of gprs TCP/IP 
#include <HardwareSerial.h>
#define IP "www.google.com"         // ip address
#define APN "airtelgprs.com"     // Network APN
bool ModuleInit()
{
  Serial2.print("AT\r\n");           // SIM7000 AT commands
  delay(300);
  Serial2.print("AT+CPIN?\r\n");    // To check SIM status
  delay(300);
  Serial2.print("AT+CSQ\r\n");     // to check network strength
  delay(300);
  Serial2.print("AT+CREG?\r\n");   // Network registration
  delay(300);
  Serial2.print("AT+CGATT?\r\n"); // attached gprs 
  return true;
  }

bool TCP_IP_Activate()
{

   delay(200);
   Serial2.print("AT+CSTT=\"");      // to set APN
   Serial2.print(APN);
   Serial2.print("\"\r");
   delay(3000);
   Serial2.print("AT+CIICR\r\n");    //  GPRS activation
   delay(3000);
   Serial2.print("AT+CIFSR\r\n");   // to check local IP address
   delay(2000);
   Serial2.print("AT+CIPSTART =\"TCP\",\"");   // to send IP addresss
   Serial2.print(IP);
   Serial2.print("\",\"80\"\r\n");
   delay(3000);
   Serial2.print("AT+CIPSEND\r\n");
   while (Serial2.available())                //If data is received through Serial 2
    {    
       Serial.find(">");        //Show data on Serial Monitor 0
    
    }
    Serial2.print("Hello world\r\n");
    while (Serial2.available())                //If data is received through Serial 2
    {    
       Serial.find("SEND OK");        //Show data on Serial Monitor 0
       
    }
    delay(20000);
    Serial2.print("AT+CIPCLOSE=1\r\n");  // Close GPRS after sending the data
    delay(5000);  
    return true;
  }
  
  void setup() 
{
  // initialize serial:
  Serial.begin(115200);
  Serial2.begin(115200,SERIAL_8N1, 16, 17);
  ModuleInit();
  get_gps();
  TCP_IP_Activate();
  delay(2000);
}


void loop() 
{
  
  //add your own code
}

  
  
  
  
