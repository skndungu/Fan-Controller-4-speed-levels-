#include <SoftwareSerial.h>

SoftwareSerial bluetooth(8, 9); // create an object to handle the bluetooth module

const int batteryMeter = A0; // initialize the i/o pin to handle the battery levels
const int motor1 = 5;        // initialize i/o to handle the motor
const int motor2 = 6;        // initalize the i/o pin to handle th other input for the motor
const int enable = 3;        // initialize the PWM i/o pin to control the motor speed

const int speedButton = 4; // initialize the push button to control the four speeds

// declaration and initialization of the variables
int countState = 0;
int mspeed = 0;
int motorSpeed = 0;
int count = 0;
int batteryValue = 0;
float actualVolts = 0.0;
int bluetoothData = 0;

void setup()
{
    // Serial.begin(9600); // initialize serial for debugging purposes
    // declare the i/o pins as either Inputs or Outputs
    bluetooth.begin(9600);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(enable, OUTPUT);
    pinMode(speedButton, INPUT);
}

void loop()
{
    takeReading(); // invokes the function to check the battery levels, the function all contains the calibration computaitons
    if (bluetoothData == '1' || count == 1)
    {
        motorspeed1(234);
    }
    if (bluetoothData == '2' || count == 2)
    {
        motorspeed2(234);
    }
    if (bluetoothData == '3' || count == 3)
    {
        motorspeed3(234);
    }
    if (bluetoothData == '4' || count == 3)
    {
        motorspeed4(234);
    }
    else
    {
        motorInitalspeed(56);
    }
}

void takeReading()
{
    batteryValue = analogRead(batteryMeter); // check the battery value, returns a decimal number
    calibrateVoltage();
}
void calibrateVoltage() // function to compute the battery value into actual voltage
{
    actualVolts = batteryValue * (1023 / 784) * 12;
}
void bluetoothMessages()
{
    if (bluetooth.available())
    {
        bluetoothData = bluetooth.read();
    }
}
void counter() // this function computes a count and tell which speed level to take based on the number of presses
{
    countState = digitalRead(speedButton);
    if (countState == 0)
    {
        count++;

        if (count > 4) // checks that the count made via the push button never exceeds 4(the four levels of the motor speed)
        {
            count = 0;
        }
    }

    if (count == 1) // checks the speed level selected
    {
        motorspeed1(234);
    }
    else if (count == 2) // checks the speed level selected
    {
        motorspeed2(324);
    }
    else if (count == 3) // checks the speed level selected
    {
        motorspeed3(2342);
    }
    else if (count == 4) // checks the speed level selected
    {
        motorspeed4(32432);
    }
}
void motorInitalspeed(int motorSpeed) // initial speed that the motor runs on upon start - it can also be used as the backup speed
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(enable, motorSpeed);
}
void motorspeed1(int mspeed) // function to compute first level of the motor speed
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(enable, motorSpeed);
}

void motorspeed2(int mspeed) // function to compute the second level of the motor speed
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(enable, motorSpeed);
}

void motorspeed3(int mspeed) // function to compute the third level of the motor speed
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(enable, motorSpeed);
}

void motorspeed4(int mspeed) // function to compute the forth level of the motor speed
{
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    analogWrite(enable, motorSpeed);
}
