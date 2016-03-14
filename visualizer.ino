/*
 * Ivelin Slavchev
 */
int sensorValue = 0;
int led = 8;   
int led2 = 7;
int led3 = 6;
int led4 = 5;
int led5 = 4;

/*
 * Lyubomir Yankov
 */
void lightUp(int value) {
  digitalWrite(led, HIGH);
  switch (value) {
    case 586 ... 1023:
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      break;
    case 570 ... 585:
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      break;
    case 550 ...  569:      
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      break;
    case 510 ... 549:
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
      break;
    case 0 ... 509:
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      break;
  }
}

/*
 * Ivelin Slavchev
 */
void setup() { 
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  sensorValue = analogRead(0);
  Serial.println(sensorValue);
  lightUp(sensorValue);
  delay(5);
}
