int in1 = 8; //Declaring where our module is wired
int in2 = 9;
int ConA = 10;// Don't forget this is a PWM DI/DO
int speed1;

void setup() {
Serial.begin(9600);
pinMode(2, INPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT); 
pinMode(10, OUTPUT);
}

void TurnMotorA1(){ //A function to control the direction and speed in one direction

digitalWrite(in1, LOW); //Switch between these HIGH and LOW states to change direction
digitalWrite(in2, HIGH);
float analogvalue = analogRead(A0); // declaring and reading an analog voltage value from the pin
int PWMvalue = map(analogvalue, 0, 1023, 0, 255); // mapping the analog readings to change 
// range from 0-1023 to 0-255 to divide the value by 4 to get a PWM value
analogWrite(ConA, PWMvalue);// To activate the DC motor
}

void TurnMotorA2(){ //A function to control the direction and speed in another direction

digitalWrite(in1, HIGH); //Switch between these HIGH and LOW states to change direction
digitalWrite(in2, LOW);
float analogvalue = analogRead(A0); // declaring and reading an analog voltage value from the pin
int PWMvalue = map(analogvalue, 0, 1023, 0, 255); // mapping the analog readings to change 
// range from 0-1023 to 0-255 to divide the value by 4 to get a PWM value
analogWrite(ConA, PWMvalue);// To activate the DC motor
}


void loop() {
float analogvalue = analogRead(A0); // declaring and reading an analog voltage value from the pin
int PWMvalue = map(analogvalue, 0, 1023, 0, 255); // mapping the analog readings to change 
// range from 0-1023 to 0-255 to divide the value by 4 to get a PWM value

Serial.print("Digital Value = ");
Serial.print(PWMvalue);        //print digital value on serial monitor
//convert digital value to analog voltage
float analogVoltage = (PWMvalue *5.00)/255.00;
Serial.print("Analog Voltage = ");
Serial.println(analogvalue);

if (digitalRead(2) == LOW){

TurnMotorA1();   // function that keeps looping to run the motor continuously
//you can add another one with a different direction or stop
}

else if (digitalRead(2) == HIGH){
TurnMotorA2();
}

}
