#include <GSM.h>
// initialize the library instance
GSM gsmAccess; // include a 'true' parameter for debug enabled
GSM_SMS sms;

// char array of the telephone number to send SMS
char remoteNumber[20]= "+254779159711";  

// char array of the message
char txtMsg[200]="water level saturation";

int sensorValue = analogRead(A0);
int led=13;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  int sensor_Messaging_Value=260;
if (sensor_Messaging_Value>260){
  Serial.println("water level has reached optimum level");  
  sendSMS();  //initialize function to send sms 
}
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(500);        // delay in between reads for stability in microseconds 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
  delay(500);        // delay in between reads for stability
}
void sendSMS(){

  Serial.print("Message to mobile number: ");
  Serial.println(remoteNumber);

  // sms text
  Serial.println("SENDING");
  Serial.println();
  Serial.println("Message:");
  Serial.println(txtMsg);

  // send the message
  sms.beginSMS(remoteNumber);
  sms.print(txtMsg);
  sms.endSMS();   
}
