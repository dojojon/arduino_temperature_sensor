// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress insideThermometer;

/*
 * Setup function. Here we do the basics
 */
void setup(void)
{
  // start serial port
  Serial.begin(115200);

  // locate devices on the bus
  Serial.print("Locating devices...");
  sensors.begin();

  // Check to see if we found device
  if (!sensors.getAddress(insideThermometer, 0))
    Serial.println("Unable to find address for Device 0");

}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  // method 1 - slower
  Serial.print("Temp C: ");
  Serial.println(sensors.getTempC(deviceAddress));
//  Serial.print(" Temp F: ");
//  Serial.println(sensors.getTempF(deviceAddress)); 
 
}

void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  // It responds almost immediately. Let's print out the data
  printTemperature(insideThermometer); // Use a simple function to print out the data
}
