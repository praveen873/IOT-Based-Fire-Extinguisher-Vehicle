int baselineTemp1 = 40;
int baselineTemp2 = 40;
int celsius = 0;
int fahrenheit = 0;
bool buzzerActivated = false;

// Define flame sensor pins
const int flameSensorPin1 = A1;
const int flameSensorPin2 = A2;

void setup() {
  
  pinMode(flameSensorPin1, INPUT);
  pinMode(flameSensorPin2, INPUT);
  pinMode(flameSensorPin3, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
sxz  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Reset buzzer activation flag
  buzzerActivated = false;

  // Read flame sensor values and convert to temperature
  int flameValue1 = analogRead(flameSensorPin1);
  celsius = map(((flameValue1 - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  
  Serial.print("Sensor 1: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");

  if (celsius >= baselineTemp1) {
    digitalWrite(2, HIGH);
    buzzerActivated = true;
    Serial.println("Flame detected by Sensor 1");

    
  } else {
    digitalWrite(2, LOW);
  }

  int flameValue2 = analogRead(flameSensorPin2);
  celsius = map(((flameValue2 - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  
  Serial.print("Sensor 2: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");

  if (celsius >= baselineTemp2) {
    digitalWrite(3, HIGH);
    buzzerActivated = true;
    Serial.println("Flame detected by Sensor 2");

  } else {
    digitalWrite(3, LOW);
  }

  int flameValue3 = analogRead(flameSensorPin3);
  celsius = map(((flameValue3 - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  
  Serial.print("Sensor 3: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");

  if (celsius >= baselineTemp3) {
    digitalWrite(4, HIGH);
    buzzerActivated = true;
    Serial.println("Flame detected by Sensor 3");

  } else {
    digitalWrite(4, LOW);
  }

  // Activate buzzer if any sensor triggers it
  if (buzzerActivated) {
    tone(7, 220, 100);
    delay(100);
  }
  
  delay(1000); 
}