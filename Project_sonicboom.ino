
int gled = 2;
int rled = 4; 
int buzz = 7;

const int trigPin =13;
const int echoPin =12;



// defines variables
long duration;
int distance;
int count = 0;
int total_distance = 0;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(rled, OUTPUT); 
  pinMode(gled, OUTPUT); 
  pinMode(buzz, OUTPUT);   

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  digitalWrite(trigPin, LOW);
  Serial.begin(9600); // Starts the serial communication
}
 
// the loop routine runs over and over again forever:
void loop() {
  
  sound_signal();
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin,HIGH);

  // Calculating the distance
  distance = duration*0.0343/2;

  // Prints the distance on the Serial Monitor

  //Serial.print("Distance:");
  if((distance!=0))
  {
    total_distance += distance;
    count++;

    if(count>100)
    {
      distance = total_distance/count;
      Serial.println(distance); 
      count = 0; total_distance =0;
      if(distance>90)
      {
        gsignal();
        buzzer();
      }
      else
      {
        rsignal();
      }
    }    
  }

}

void rsignal()
{
  digitalWrite(gled, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(rled, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void gsignal()
{
  digitalWrite(rled, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(gled, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void buzzer()
{
  tone(buzz,1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzz);     // Stop sound...
  delay(1000);        // ...for 1sec
}

void sound_signal()
{
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
}
