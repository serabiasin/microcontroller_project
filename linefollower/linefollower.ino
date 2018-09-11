#define WHITE_VAL_KIRI 25
#define BLACK_VAL_KIRI 40
#define PWM_SPEED 120

#define WHITE_VAL_KANAN 25
#define BLACK_VAL_KANAN 51


#define SENSOR_TENGAH_HITAM 110



/*
  MOTOR 1 KANAN KE ARAH PINTU LAB
*/

void motor_kanan_mundur() {
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
  analogWrite(3, PWM_SPEED);

}
void motor_kanan_maju() {
  digitalWrite(7, HIGH);
  digitalWrite(5, LOW);
  analogWrite(3, PWM_SPEED);

}

void motor_kiri_maju() {
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  analogWrite(13, PWM_SPEED);

}

void motor_kiri_mundur() {
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  analogWrite(13, PWM_SPEED);
}

void setup() {
  pinMode(A0, INPUT); // Sensor kanan 4 (paling kanan)
  pinMode(A2, INPUT); //sensor kanan 3
  pinMode(A4, INPUT); //Sensor Kanan 2
  pinMode(A6, INPUT); //sensor kanan 1

  pinMode(A8, INPUT); //sensor kiri 1
  pinMode(A10, INPUT); //sensor kiri 2
  pinMode(A12, INPUT); //sensor kiri 3
  pinMode(A14, INPUT); //sensor kiri 1
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
int motor_kiri[] = {A10, A12, A14};
int motor_kanan[] = {A0, A2, A4};
int motor_tengah[] = {A6, A8};
void loop() {
  //  Serial.print("Sensor Kanan 1 : ");
  //  Serial.println(analogRead(A0));
  //  Serial.print("Sensor Kanan 2 : ");
  //  Serial.println(analogRead(A2));
  //  Serial.print("Sensor Kanan 3 : ");
  //  Serial.println(analogRead(A4));
  //  Serial.print("Sensor Kanan 4 : ");
  //  Serial.println(analogRead(A6));
  //  Serial.println(analogRead(A8));

  //peripheral sensor kiri
  int total_kiri = 0;

  for (int x = 0; x < 3; x++) {
    total_kiri += analogRead(motor_kiri[x]);
  }
  total_kiri = total_kiri / 4;
  //  Serial.println(total_kiri);

  int total_kanan = 0;

  for (int x = 0; x < 3; x++) {
    total_kanan += analogRead(motor_kanan[x]);
  }
  total_kanan = total_kanan / 4;

  int total_tengah = 0;
  for (int x = 0; x < 2; x++) {
    total_tengah += analogRead(motor_tengah[x]);
  }
  total_tengah = total_tengah / 2;
  //  Serial.print("Sensor Kanan : ");
  //  Serial.println(total_kanan);
    Serial.print("Sensor Kiri : ");
    Serial.println(total_kiri);
//    Serial.print("Sensor Tengah : ");
//    Serial.println(total_tengah);


  int hasil = 0;
  /*Sensor Tengah Hitam MOTOR 1-MOTOR 2 MAJU*/
  if (total_tengah >= SENSOR_TENGAH_HITAM) {
    hasil=99;
    motor_kanan_maju();
    motor_kiri_maju();
  }
  /*SENSOR KIRI*/
  else if (total_kiri >= BLACK_VAL_KIRI && total_kanan <= WHITE_VAL_KANAN) {
    hasil = 1;
    motor_kanan_maju();
    motor_kiri_mundur();
  }
  //SENSOR KANAN
  else if (total_kiri <= BLACK_VAL_KANAN && total_kanan <= BLACK_VAL_KANAN ) {
    hasil = 2;
    motor_kanan_mundur();
    motor_kiri_maju();
  }
  else if (total_kiri <= WHITE_VAL_KIRI && total_kanan <= WHITE_VAL_KANAN ) {
    hasil = 3;
    motor_kiri_mundur();
    motor_kanan_mundur();
  }
  //  delay(100);
}
