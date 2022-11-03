// first motor input pins & speed control pin.
int In1 = 2;
int In2 = 3;
int ENA = 9;

// second motor input pins & speed control pin.
int In3 = 4;
int In4 = 5;
int ENB = 10;


int ENA_DEFAULT = 100;
int ENB_DEFAULT = 200;

void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, ENA_DEFAULT);
  analogWrite(ENB , ENB_DEFAULT);

}


void loop()
{
  analogWrite(ENA, ENA_DEFAULT);
  analogWrite(ENB, ENB_DEFAULT);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);

  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  delay(1000);

  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);

  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  delay(1000);


}