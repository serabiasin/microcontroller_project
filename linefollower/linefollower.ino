//motor Right OFF
void mROFF() {
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  //  analogWrite(3, PWM_SPEED);

}
//motor Right ON
void mRON(int PWM) {
  digitalWrite(7, HIGH);
  digitalWrite(5, LOW);
  analogWrite(3, PWM);

}
//motor Left ON
void mLON(int PWM) {
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(13, PWM);

}

//motor Left OFF
void mLOFF() {
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  //  analogWrite(13, PWM);
}
int sensor[] = {A14, A12, A10, A8, A6, A4, A2, A0};
int analogBuffer[] = {0, 0, 0, 0, 0, 0, 0, 0};
int digitalBuffer[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevState[] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  pinMode(A0, INPUT); // Sensor kanan 4 (paling kanan)
  pinMode(A2, INPUT); //sensor kanan 3
  pinMode(A4, INPUT); //Sensor Kanan 2
  pinMode(A6, INPUT); //sensor kanan 1 (Tengah)

  pinMode(A8, INPUT); //sensor kiri 1(Tengah)
  pinMode(A10, INPUT); //sensor kiri 2
  pinMode(A12, INPUT); //sensor kiri 3
  pinMode(A14, INPUT); //sensor kiri 4
  Serial.begin(9600);


  /*
    MOTOR DRIVER :
    D3 D5 D7 D9 D11 D13
  */
  pinMode(3, OUTPUT); //PWM SIGNAL MOTOR 1
  pinMode(5, OUTPUT); //motor 1 mundur
  pinMode(7, OUTPUT); //motor 1 maju

  pinMode(9, OUTPUT); //motor 2 maju
  pinMode(11, OUTPUT); //motor 2 mundur
  pinMode(13, OUTPUT); //PWM SIGNAL MOTOR 2
}

//int motor_tengah[] = {A6, A8};

void bacaSensor() {
  for (int x = 0; x < 8; x++) {
    analogBuffer[x] = analogRead(sensor[x]);
  }
}

/*Debuggin Purposes*/
void showSensor() {
  Serial.print("Sensor Kiri 1 :"); //paling kiri
  Serial.println(analogBuffer[0]);
  Serial.print("Sensor Kiri 2 :");
  Serial.println(analogBuffer[1]);
  Serial.print("Sensor Kiri 3 :");
  Serial.println(analogBuffer[2]);
  Serial.print("Sensor Tengah Kiri :");
  Serial.println(analogBuffer[3]);

  Serial.print("Sensor Tengah Kanan :");
  Serial.println(analogBuffer[4]);
  Serial.print("Sensor Kanan 3 :");
  Serial.println(analogBuffer[5]);
  Serial.print("Sensor Kanan 2 :");
  Serial.println(analogBuffer[6]);
  Serial.print("Sensor Kanan 1 :");
  Serial.println(analogBuffer[7]);

}

void digitalShow() {
  for (int x = 0; x < 8; x++) {
    Serial.print(digitalBuffer[x]);
    Serial.print(" , ");
  }
  Serial.println();
}

#define THRESHOLD 55

void konversiDigital() {
  for (int x = 0; x < 8; x++) {
    if (analogBuffer[x] > THRESHOLD) {
      digitalBuffer[x] = 1;
    } else {
      digitalBuffer[x] = 0;
    }
  }
}

#define PWM_SIXTY 153
#define PWM_FIFTY 128
#define PWM_TWENTY 51
#define PWM_FORTY 102
#define PWM_FIVE 13
#define PWM_TEN 26
#define PWM_FIFTEEN 38
#define PWM_TFIVE 64
#define PWM_THIRTY 77
int error = 0;


void loop() {
  bacaSensor();
  konversiDigital();
    showSensor();
//  digitalShow();
  char buffer[16];
  sprintf(buffer, "%d%d%d%d%d%d%d%d", digitalBuffer[0], digitalBuffer[1], digitalBuffer[2], digitalBuffer[3], digitalBuffer[4], digitalBuffer[5], digitalBuffer[6], digitalBuffer[7]);
  String test = buffer;
  //  Serial.println(test);
//  kendali(test);


}


void kendali(String test) {

  if (test == "10000000") {
    error = -6;
    mLON(PWM_FIFTY);
    mROFF();
  }
  else if (test == "11000000") {
    error = -5;
    mLON(PWM_FIFTY);
    mRON(PWM_FIVE);
  }
  else if (test == "01000000") {
    error = -4;
    mLON(PWM_FIFTY);
    mRON(PWM_TEN);

  }
  else if (test == "01110000") {
    error = -3;
    mLON(PWM_FIFTY);
    mRON(PWM_FIFTEEN);
  }
  else if (test == "01010000") {
    error = -2;
    mLON(PWM_FIFTY);
    mRON(PWM_TWENTY);
  }
  else if (test == "00110000") {
    error = -1;
    mLON(PWM_FIFTY);
    mRON(PWM_TFIVE);
  }
  else if (test == "00010000") {
    error = 0;
    mLON(PWM_FIFTY);
    mRON(PWM_THIRTY);
  }
  else if (test == "00011000") {
    error = 0;
    mRON(PWM_SIXTY);
    mLON(PWM_SIXTY);
  }
  else if (test == "00001000") {
    error = 0;
    mLON(PWM_THIRTY);
    mRON(PWM_FIFTY);

  }
  else if (test == "00001100") {
    error = 1;
    mRON(PWM_FIFTY);
    mLON(PWM_TFIVE);
  }
  else if (test == "00011100 ") {
    error = 1;
    mRON(PWM_FIFTY);
    mLON(PWM_TFIVE);

  }
  else if (test == "00010100") {
    error = 1;
    mRON(PWM_FIFTY);
    mLON(PWM_TFIVE);


  }
  else if (test == "00000100") {
    error = 2;
    mRON(PWM_FIFTY);
    mLON(PWM_TWENTY);
  }
  else if (test == "00000110") {
    error = 3;

    mLON(PWM_FIFTY);
    mRON(PWM_FIFTEEN);
  }
  else if (test == "00000010") {
    error = 4;

    mLON(PWM_FIFTY);
    mRON(PWM_TEN);
  }
  else if (test == "00000011") {
    error = 5;
    mLON(PWM_FIVE);
    mRON(PWM_FIFTY);
  }
  else if (test == "00000001") {
    error = 6;
    mLOFF();
    mRON(PWM_FIFTY);
  }
  else if (test == "00000000") {
    mLOFF();
    mROFF();
  }
  Serial.println(error);
}

