#include <PeakDetection.h> // import lib

PeakDetection peakDetection; // create PeakDetection object

void setup() {
  Serial.begin(9600); // set the data rate for the Serial communication
  pinMode(A0, INPUT); // analog pin used to connect the sensor
  peakDetection.begin(48, 3, 0.6); // sets the lag, threshold and influence
}

void loop() {
    double data = (double)analogRead(A0)/512-1; // reads the value of the sensor and converts to a range between -1 and 1
    peakDetection.add(data); // adds a new data point
    int peak = peakDetection.getPeak(); // returns 0, 1 or -1
    double filtered = peakDetection.getFilt(); // moving average
    Serial.print(data); // print data
    Serial.print(",");
    Serial.print(peak); // print peak status
    Serial.print(",");
    Serial.println(filtered); // print moving average
}