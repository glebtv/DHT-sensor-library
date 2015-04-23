#include "Adht.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <DigiUSB.h>

// the setup function runs once when you press reset or power the board
void setup() {
  dht.begin();
  DigiUSB.begin();
  pinMode(1, OUTPUT);
}

void get_input() {
  int lastRead;
  // when there are no characters to read, or the character isn't a newline
  while (true) { // loop forever
    if (DigiUSB.available()) {
      // something to read
      lastRead = DigiUSB.read();
      DigiUSB.write(lastRead);
      
      if (lastRead == '\n') {
        break; // when we get a newline, break out of loop
      }
    }
    
    // refresh the usb port for 10 milliseconds
    DigiUSB.delay(10);
  }
}

float h = 0;
float t = 0;

// the loop function runs over and over again forever
void loop() {
  DigiUSB.refresh();
  digitalWrite(1, HIGH);
  DigiUSB.refresh();

  if (dht.read()) {
    DigiUSB.refresh();
    h = dht.getHumidity();
    t = dht.getTemperature();
    DigiUSB.refresh();
    // print output
    DigiUSB.print("{\"h\":"); 
    DigiUSB.print(h);
    DigiUSB.print(", \"t\": "); 
    DigiUSB.print(t);
    DigiUSB.println("}"); 
  }
  digitalWrite(1, LOW);
  
  DigiUSB.delay(5000);
}
