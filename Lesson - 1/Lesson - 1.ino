// first motor input pins & speed control pin.
int In1 = 2;
int In2 = 3;
int ENA = 9;

// second motor input pins & speed control pin.
int In3 = 4;
int In4 = 5;
int ENB = 10;


int DEFAULT_SPEED = 100;
int state1 = HIGH; 
int state2 = LOW;

// Rotary Encoder:
int CLK = 6;
int DT = 7;
int SW = 11;

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;


void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(CLK,INPUT);
	pinMode(DT,INPUT);
	pinMode(SW, INPUT_PULLUP);

  analogWrite(ENA, DEFAULT_SPEED);
  analogWrite(ENB, DEFAULT_SPEED);

  Serial.begin(9600);
  lastStateCLK = digitalRead(CLK);

}


void loop()
{   
  	currentStateCLK = digitalRead(CLK); // read current CLK state

    analogWrite(ENA, DEFAULT_SPEED);
    analogWrite(ENB, DEFAULT_SPEED);

    digitalWrite(In1, state1);
    digitalWrite(In2, state2);

    digitalWrite(In3, state1);
    digitalWrite(In4, state2);
  
    // if last and curr state are different, then a pulse occured.
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
        if (digitalRead(DT) != currentStateCLK) {
          if (DEFAULT_SPEED > 200)
            Serial.print("Reached maximum speed.");
        
          else {
			      DEFAULT_SPEED ++;
          }
		 }
     
     else {

			if (DEFAULT_SPEED < 0)
        Serial.print("Speed is currently 0.");
      
      else{
        DEFAULT_SPEED --; 
      }


		}
    Serial.print("Changed motor's speed to: ");
      Serial.print(DEFAULT_SPEED);
      Serial.print("\n");
    }

    lastStateCLK = currentStateCLK;

    int btnState = digitalRead(SW);

    if (btnState == LOW) {
      if (millis() - lastButtonPress > 50) {
        Serial.println("Switching direction!");
        if (state1 == HIGH && state2 == LOW){
          state1 = LOW;
          state2 = HIGH;
        }
        else if (state1 == LOW && state2 == HIGH){
          state1 = HIGH;
          state2 = LOW;
        }
      
      }

      lastButtonPress = millis();
    }

}