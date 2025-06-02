int dp = 9;
int clk = 11;
int load = 10;


void setup() {
  pinMode(dp,INPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  digitalWrite(clk, LOW);
  digitalWrite(load, HIGH);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void read(){
  digitalWrite(load,  LOW);
  

}
