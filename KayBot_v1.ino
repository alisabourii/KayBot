int trig = 9;
int echo = 8;

int mtrA1 = 2;
int mtrA2 = 3;

int mtrB1 = 4;
int mtrB2 = 5;


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

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

  if(msf <= 15 && sayac%2 == 0){
    sag();}
    
  else if(msf <= 15 && sayac%2 == 1){
    sol();}

  //delay(500);
  /*ileri();
  delay(5000);
  geri();
  delay(5000);*/
}


int Mesafe(){
  digitalWrite(trig,1); delay(1);
  digitalWrite(trig,0);
  int sure = pulseIn(echo,1);
  int msf = (sure/2)/28.97;
  return msf;
}

void ileri(){
  digitalWrite(mtrA1,1);
  digitalWrite(mtrA2,0);

  digitalWrite(mtrB1,1);
  digitalWrite(mtrB2,0);
}

void geri(){
  digitalWrite(mtrA1,0);
  digitalWrite(mtrA2,1);

  digitalWrite(mtrB1,0);
  digitalWrite(mtrB2,1);
}

void sag(){
  digitalWrite(mtrA1,1);
  digitalWrite(mtrA2,0);

  digitalWrite(mtrB1,0);
  digitalWrite(mtrB2,1);
}

void sol(){
  digitalWrite(mtrA1,0);
  digitalWrite(mtrA2,1);

  digitalWrite(mtrB1,1);
  digitalWrite(mtrB2,0);
}