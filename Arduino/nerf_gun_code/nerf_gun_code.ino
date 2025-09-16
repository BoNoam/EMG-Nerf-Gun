#include <Servo.h>

int limit_switch = 2;
int launch_pin = 4;

int servo_state = 1;

Servo s;

void setup() {

  pinMode(launch_pin, INPUT);
  pinMode(limit_switch, INPUT);
  s.attach(9);
  delay(1000);

}

void loop() {

  if (digitalRead(reset)) {
    s.write(45);
    delay(500);
  }

  int loaded = digitalRead(limit_switch);

  while (loaded) {

    if (!digitalRead(limit_switch)) {
      loaded = 0;
      break;
    }

    /*
      EMG reading code
    */

  }

    int launch = digitalRead(launch_pin);

    if (launch) {

      if (servo_state) {

        s.write(135);
        digitalWrite(led_pin, HIGH);
        delay(500);
        digitalWrite(led_pin, LOW);
        servo_state = 0;

      } else {

        s.write(45);
        digitalWrite(led_pin, HIGH);
        delay(500);
        digitalWrite(led_pin, LOW);
        servo_state = 1;

      }

      delay(1500);
    }

    delay(1);
  }

  delay(1);
}
