const int greenLEDpin = 9;
const int redLEDpin = 10;
const int blueLEDpin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(greenLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() 
{
  readSensor();

  delay(500);

  writeLED(redVal, greenVal, blueVal);
}

void readSensor()
{
  redSensorVal = analogRead(redSensorPin);
  delay(5);
  greenSensorVal = analogRead(greenSensorPin);
  delay(5);
  blueSensorVal = analogRead(blueSensorPin);
  delay(5);

  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorVal);
  Serial.print("\t green: ");
  Serial.print(greenSensorVal);
  Serial.print("\t blue: ");
  Serial.print(blueSensorVal);

  redVal = redSensorVal / 4;
  greenVal = greenSensorVal / 4;
  blueVal = blueSensorVal / 4;

  Serial.print("\t Mapped Sensor Values \t red: ");
  Serial.print(redVal);
  Serial.print("\t green: ");
  Serial.print(greenVal);
  Serial.print("\t blue: ");
  Serial.println(blueVal);
}

void writeLED(int redVal, int greenVal, int blueVal)
{
  analogWrite(redLEDpin, redVal);
  analogWrite(greenLEDpin, greenVal);
  analogWrite(blueLEDpin, blueVal);
}
