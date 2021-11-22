//left motor
int Enable34 = 9;
int input1_l = 10;
int input2_l = 11;

//right motor
int Enable12 = 5;
int input1_r = 6;
int input2_r = 7;

// Sensors
int LeftSensor;
int RightSensor;


int initialiseMotor(int pin1, int pin2, int activation)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(activation, OUTPUT);

  //Start the motor
  digitalWrite(activation, HIGH);
}

int rotateMotor(int pin1, int pin2, bool clockwise = true)
{
  if(clockwise)                             // rotates the motor clockwise
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
  else                                     // wont rotate the motor
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
}

void setup() {
  initialiseMotor(input1_l,input2_l,Enable34);
  initialiseMotor(input1_r,input2_r,Enable12);
  pinMode(4, INPUT);  // for left Sensor
  pinMode(3, INPUT);  // for right Sensor
}

void loop() {
  LeftSensor = digitalRead(4);
  RightSensor = digitalRead(3);

  if(LeftSensor == 1 && RightSensor == 1)
  {
    rotateMotor(input1_l, input2_l, true);
    rotateMotor(input1_r, input2_r, true);
  }
  else if (LeftSensor == 1 && RightSensor == 0)
  {
    rotateMotor(input1_l, input2_l, true);
    rotateMotor(input1_r, input2_r, false);
  }
  else if (LeftSensor == 0 && RightSensor == 1)
  {
    rotateMotor(input1_r, input2_r, true);
    rotateMotor(input1_l, input2_l, false);
    
  }  
  else
  {
    rotateMotor(input1_r, input2_r, false);
    rotateMotor(input1_l, input2_l, false);
    
  }
}
