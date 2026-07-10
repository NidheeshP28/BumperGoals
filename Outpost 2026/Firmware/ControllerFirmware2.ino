#define JOY_FORWARD_PIN A0 
#define JOY_TURN_PIN A3 

const int JOY_CENTER = 512;
const int DEADZONE = 50;
const int MAX_SPEED = 255;

int forwardPrev = 0;
int turnPrev = 0;

struct ControlPacket {
  int forward;      // f
  int turn;         // t
  int leftMotor;    // l
  int rightMotor;   // r
};

ControlPacket packet;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int rawForward = analogRead(JOY_FORWARD_PIN);
  int forwardRawCentered = rawForward - JOY_CENTER;


  if (abs(forwardRawCentered) < DEADZONE) {
    forwardRawCentered = 0;
  }

  int forward = forwardRawCentered / 2;

  int rawTurn = analogRead(JOY_TURN_PIN);
  int turnRawCentered = rawTurn - JOY_CENTER;  


  if (abs(turnRawCentered) < DEADZONE) {
    turnRawCentered = 0;
  }
  
  int turn = turnRawCentered / 2;

  forward = (forwardPrev + forward) / 2;
  turn    = (turnPrev + turn) / 2;

  forwardPrev = forward;
  turnPrev    = turn;

  int leftMotor  = forward + turn;
  int rightMotor = forward - turn;

  leftMotor  = constrain(leftMotor,  -MAX_SPEED, MAX_SPEED);
  rightMotor = constrain(rightMotor, -MAX_SPEED, MAX_SPEED);

  packet.forward   = forward;
  packet.turn      = turn;
  packet.leftMotor = leftMotor;
  packet.rightMotor= rightMotor;

  Serial.print("F:");
  Serial.print(packet.forward);
  Serial.print("  T:");
  Serial.print(packet.turn);
  Serial.print("  L:");
  Serial.print(packet.leftMotor);
  Serial.print("  R:");
  Serial.println(packet.rightMotor);

  delay(100);
  
}




