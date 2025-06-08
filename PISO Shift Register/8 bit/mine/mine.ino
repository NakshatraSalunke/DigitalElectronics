#define dp 9
#define clk 11
#define load 10
uint8_t data = 0;


void setup() {
  Serial.begin(9600);
  pinMode(dp,INPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  digitalWrite(clk, LOW);
  digitalWrite(load, HIGH);

  


  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  read();
}
void read(){
  data = 0;
  digitalWrite(load,  LOW);
  //Serial.println("Load pin LOW");
  delay(100);

  digitalWrite(load, HIGH);
  //Serial.println("load pin HIGH");
  delay(100);

  for(int j=0;j<12;j++){
   
    data <<= 1;
    data |= digitalRead(dp);
       
    digitalWrite(clk, HIGH);
    //Serial.println("Clk pin HIGH");
    delay(10);
    digitalWrite(clk, LOW);
    //Serial.println("Clk pin LOW");
    delay(10);

  }
  //shifting (n-1) because we have to compare the MSB first and shifting by n will remove that too
  for(int j=11 ; j>=0 ; j--){
    Serial.print((data >> j) & 1);
  }
  Serial.print("\n");
  
}
