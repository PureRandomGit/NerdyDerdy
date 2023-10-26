// Button pin
const int button = 12;

// Solenoid Pin
const int solenoid = 2;

// RGB light Pins
const int red1 = 7; const int green1 = 8; const int end1 = 9; //Lane 1
const int red2 = 5; const int green2 = 6; const int end2 = 10; //Lane 2
const int red3 = 3; const int green3 = 4; const int end3 = 11; //Lane 3

int place = 1;
 
bool racing = false;
bool lane1Finished = false;
bool lane2Finished = false;
bool lane3Finished = false;


void setup() {
    pinMode(button, INPUT_PULLUP);

    pinMode(solenoid, OUTPUT);
    
    pinMode(red1, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(red3, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(green3, OUTPUT);

    pinMode(end1, INPUT_PULLUP);
    pinMode(end2, INPUT_PULLUP);
    pinMode(end3, INPUT_PULLUP);
    Serial.begin(9600);
    digitalWrite(solenoid, LOW);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW); 
    digitalWrite(red3, LOW); 
    digitalWrite(green1, LOW); 
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
}

void loop() {
    if(digitalRead(button)==LOW && !racing) {
        lane1("red");
        lane2("red");
        lane3("red");
        Serial.println("Three");
        delay(1000);
        lane1("yellow");
        lane2("yellow");
        lane3("yellow");
        Serial.println("Two");
        delay(1000);
        lane1("green");
        lane2("green");
        lane3("green");
        digitalWrite(solenoid, HIGH);
        Serial.println("One");
        Serial.println("Start");
        delay(3000);
        lane1("off");
        lane2("off");
        lane3("off");
        digitalWrite(solenoid, LOW);
        Serial.println("Solenoid Off");
        place = 0;
    } else {
        if (digitalRead(end1)==LOW && !(lane1Finished)) {
            if(place==1) {
                lane1("green");
                place++;
            }
            else if(place == 2) {
                lane1("yellow");
                place++;
            }
            else if(place == 3) {
                lane1("red");
                place++;
            }
            lane1Finished = true;
        }

        if (!digitalRead(end2)==LOW && !(lane2Finished)) {
            if(place==1) {
                lane2("green");
                place++;
            }
            else if(place == 2) {
                lane2("yellow");
                place++;
            }
            else if(place == 3) {
                lane2("red");
                place++;
            }
            lane2Finished = true;
        }

        if (!digitalRead(end3)==LOW && !(lane3Finished)) {
            if(place==1) {
                lane3("green");
                place++;
            }
            else if(place == 2) {
                lane3("yellow");
                place++;
            }
            else if(place == 3) {
                lane3("red");
                place++;
            }
            lane3Finished = true;
        }
    }
}

// Takes color as input and sets lane to color
void lane1(char color[]) {
    if (color == "red") {
      digitalWrite(red1, HIGH);
      digitalWrite(green1, LOW);
    }
    if (color == "yellow") {
      digitalWrite(red1, HIGH);
      digitalWrite(green1, HIGH);
    }
    if (color == "green") {
      digitalWrite(red1, LOW);
      digitalWrite(green1, HIGH);
    }
    if (color == "off") {
      digitalWrite(red1, LOW);
      digitalWrite(green1, LOW);
    }
}
void lane2(char color[]) {
    if (color == "red") {
      digitalWrite(red2, HIGH);
      digitalWrite(green2, LOW);
    }
    if (color == "yellow") {
      digitalWrite(red2, HIGH);
      digitalWrite(green2, HIGH);
    }
    if (color == "green") {
      digitalWrite(red2, LOW);
      digitalWrite(green2, HIGH);
    }
    if (color == "off") {
      digitalWrite(red2, LOW);
      digitalWrite(green2, LOW);
    }
}
void lane3(char color[]) {
    if (color == "red") {
      digitalWrite(red3, HIGH);
      digitalWrite(green3, LOW);
    }
    if (color == "yellow") {
      digitalWrite(red3, HIGH);
      digitalWrite(green3, HIGH);
    }
    if (color == "green") {
      digitalWrite(red3, LOW);
      digitalWrite(green3, HIGH);
    }
    if (color == "off") {
      digitalWrite(red3, LOW);
      digitalWrite(green3, LOW);
    }
}
