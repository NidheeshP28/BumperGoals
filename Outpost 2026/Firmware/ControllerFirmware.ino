int joy1X = 0;
int joy1Y = 0;

int joy2X = 0;
int joy2Y = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pinA0 = analogRead(A0);
  int pinA1 = analogRead(A1);
  int pinA2 = analogRead(A2);
  int pinA3 = analogRead(A3);

  if (pinA0 > 570) {
    Serial.println("COMMAND: Forward | Left Motor: CW | Right Motor: CCW");
  }
  else if (pinA0 < 450) {
    Serial.println("COMMAND: Backward | Left Motor: CCW | Right Motor: CW");
  }
  else if (pinA3 > 570) {
   Serial.println("COMMAND: Turn Right | Left Motor: CW | Right Motor: CW");    
  }
  else if (pinA3 < 450) {
   Serial.println("COMMAND: Turn Left | Left Motor: CCW | Right Motor: CCW");
  }
  else {
    Serial.println("COMMAND: Coast / Stop");
  }

  delay(100);
}

struct DataPacket {
  int leftY; 
  int rightX;
};

#define LEFT_MOTOR_A 3
#define LEFT_MOTOR_B 4
#define RIGHT_MOTOR_A 5
#define RIGHT_MOTOR_B 6




