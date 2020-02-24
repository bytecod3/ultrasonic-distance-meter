// define setup constants
int red_led = 9;
int blue_led = 10;
int green_led = 11;

int trigger = 2;
int echo = 3;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);


  //set the trigger pin on high state for 10 microsecnds
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // read the pin and return the wave travel time in kicroseconds
  duration = pulseIn(echo, HIGH);

  // calculating the distance
  distance = duration*0.034/2;

  // control LEDS for varius distances

  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  digitalWrite(red_led, LOW);

  if (distance > 10){
    digitalWrite(green_led, HIGH);
    // print the distance on the serial monitor
    Serial.print("Distance in cm: ");
    
    Serial.println(distance);

  }

  else if (distance < 10 && distance > 5){
    digitalWrite(blue_led, HIGH);
    // print the distance on the serial monitor
    Serial.print("Distance in cm: ");
    Serial.println(distance);
  }

  else{
    digitalWrite(red_led, HIGH);
    // print the distance on the serial monitor
    Serial.print("Distance in cm: ");
    Serial.println(distance);
  }
   

}
