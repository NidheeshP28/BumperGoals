// Define Virtual Motor Pins (Matching your layout: D3, D5, D6, D9)
#define LEFT_FORWARD   3  // Clockwise (Wheel Forward)
#define LEFT_BACKWARD  5  // Counter-Clockwise (Wheel Backward)
#define RIGHT_FORWARD  6  // Counter-Clockwise (Wheel Forward)
#define RIGHT_BACKWARD 9  // Clockwise (Wheel Backward)

unsigned long lastStateChange = 0;
int controllerState = 0;

void setup() {
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  stopRobot();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Cycle through your 4 controller conditions every 2.5 seconds
  if (currentTime - lastStateChange >= 2500) {
    lastStateChange = currentTime;
    controllerState = (controllerState + 1) % 4; 
  }
  
  switch (controllerState) {
    case 0: 
      // 1. left_controller = UP (Both Wheels Forward)
      // Left Motor: Clockwise | Right Motor: Counter-Clockwise
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      break;
      
    case 1: 
      // 2. left_controller = DOWN (Both Wheels Backward)
      // Left Motor: Counter-Clockwise | Right Motor: Clockwise
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      break;
      
    case 2: 
      // 3. right_controller = RIGHT (Left Forward, Right Backward -> Spin Right)
      // Left Motor: Clockwise | Right Motor: Clockwise
      digitalWrite(LEFT_FORWARD, HIGH);
      digitalWrite(LEFT_BACKWARD, LOW);
      digitalWrite(RIGHT_FORWARD, LOW);
      digitalWrite(RIGHT_BACKWARD, HIGH);
      break;
      
    case 3: 
      // 4. right_controller = LEFT (Left Backward, Right Forward -> Spin Left)
      // Left Motor: Counter-Clockwise | Right Motor: Counter-Clockwise
      digitalWrite(LEFT_FORWARD, LOW);
      digitalWrite(LEFT_BACKWARD, HIGH);
      digitalWrite(RIGHT_FORWARD, HIGH);
      digitalWrite(RIGHT_BACKWARD, LOW);
      break;
  }
}

void stopRobot() {
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
}