// SEGMENTS (A-G)
const int segPins[7] = {21,20,10,9,8,7,6};

// DIGITS (D1-D4 + SINGLE)
const int digitPins[5] = {1,2,3,4,0};

// BUTTON
const int buttonPin = 5;

// Digit patterns (COMMON ANODE)
const int digits[10][7] = {
  {1,1,1,1,1,1,0}, 
  {0,1,1,0,0,0,0}, 
  {1,1,0,1,1,0,1}, 
  {1,1,1,1,0,0,1}, 
  {0,1,1,0,0,1,1}, 
  {1,0,1,1,0,1,1}, 
  {1,0,1,1,1,1,1}, 
  {1,1,1,0,0,0,0}, 
  {1,1,1,1,1,1,1}, 
  {1,1,1,1,0,1,1}  
};

// Time
int hours = 0;
int minutes = 0;
int seconds = 0;

bool running = false;
unsigned long lastUpdate = 0;

// Button timing
unsigned long pressStart = 0;
bool buttonHeld = false;

void setup() {
  // Segments
  for(int i=0;i<7;i++){
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);
  }

  // Digits
  for(int i=0;i<5;i++){
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);
  }

  // Button
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  handleButton();

  // Time update
  if(running && millis() - lastUpdate >= 1000){
    lastUpdate = millis();

    seconds++;
    if(seconds >= 60){
      seconds = 0;
      minutes++;
      if(minutes >= 60){
        minutes = 0;
        hours++;
      }
    }
  }

  refreshDisplay();
}

void handleButton(){
  static bool lastState = HIGH;
  bool currentState = digitalRead(buttonPin);

  // Button pressed
  if(lastState == HIGH && currentState == LOW){
    pressStart = millis();
    buttonHeld = false;
  }

  // Button held
  if(currentState == LOW && (millis() - pressStart > 1000) && !buttonHeld){
    // LONG PRESS → RESET
    hours = 0;
    minutes = 0;
    seconds = 0;
    running = false;
    buttonHeld = true;
  }

  // Button released
  if(lastState == LOW && currentState == HIGH){
    if(!buttonHeld){
      // SHORT PRESS → START/STOP
      running = !running;
    }
  }

  lastState = currentState;
}

void refreshDisplay(){
  int d1 = hours / 10;
  int d2 = hours % 10;
  int d3 = minutes / 10;
  int d4 = minutes % 10;
  int d5 = seconds / 10;

  displayDigit(d1,0);
  displayDigit(d2,1);
  displayDigit(d3,2);
  displayDigit(d4,3);
  displayDigit(d5,4);
}

void displayDigit(int num, int digit){
  digitalWrite(digitPins[digit], HIGH);

  for(int s=0;s<7;s++){
    digitalWrite(segPins[s], digits[num][s]==1 ? LOW : HIGH);
  }

  delayMicroseconds(2000);

  digitalWrite(digitPins[digit], LOW);
}