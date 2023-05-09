int trig = 9;
int echo = 8;

int ENA = 10;
int mtrA1 = 2;
int mtrA2 = 3;

int ENB = 11;
int mtrB1 = 4;
int mtrB2 = 5;


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(mtrA1, OUTPUT);
  pinMode(mtrA2, OUTPUT);
  pinMode(mtrB1, OUTPUT);
  pinMode(mtrB2, OUTPUT);

  Serial.begin(9600);
}

int sayac = 0;
void loop() {
  int msf = Mesafe();
  Serial.println(msf);
  ileri();

  if(msf <= 5 && msf > 0 && sayac%2 == 0){
    sayac++;
    dur();
    sag();
    }
    
  else if(msf <= 5 && msf > 0 && sayac%2 == 1){
    sayac++;
    dur();
    sol();
    }
}


int Mesafe(){
  digitalWrite(trig,1); delay(1);
  digitalWrite(trig,0);
  int sure = pulseIn(echo,1);
  int msf = (sure/2)/28.97;
  return msf;
}

void ileri(){
  analogWrite(ENA , 200);
  digitalWrite(mtrA1,1);
  digitalWrite(mtrA2,0);

  analogWrite(ENB , 200);
  digitalWrite(mtrB1,1);
  digitalWrite(mtrB2,0);
}


void sag(){
  digitalWrite(mtrA1,1);
  digitalWrite(mtrA2,0);

  digitalWrite(mtrB1,0);
  digitalWrite(mtrB2,1);

  delay(1000);   
}

void sol(){
  digitalWrite(mtrA1,0);
  digitalWrite(mtrA2,1);

  digitalWrite(mtrB1,1);
  digitalWrite(mtrB2,0);

  delay(1000);
}


void dur(){
  digitalWrite(mtrA1,0);
  digitalWrite(mtrA2,0);

  digitalWrite(mtrB1,0);
  digitalWrite(mtrB2,0);

  delay(1000);
}
