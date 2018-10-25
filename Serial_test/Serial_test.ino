int waiting = 0; //timer counter
int receive = 0; //receive data
int ledpin=13; //13 is builtin LED port in nano and UNO

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    receive = Serial.read();
    if(receive==0){
      digitalWrite(ledpin,HIGH);
    }else{
      digitalWrite(ledpin,LOW);
    }
    Serial.println(receive, BIN); //send converted data
    Serial.write(receive); //send raw data like echo
  }else{
    waiting++;
    if(waiting>50){
      waiting=0;
      Serial.write(0); //0=.?
      //digitalWrite(ledpin,LOW); //turn off LED
    }
    delay(100);
  }
}
