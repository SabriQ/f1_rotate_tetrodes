int pul = 2;
int dir = 3;
int env = 4;
int on_off = 5;
int rot = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(pul, OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(env,OUTPUT);
  pinMode(on_off,INPUT);
  pinMode(rot,INPUT);

  digitalWrite(on_off,LOW);
//  pinMode(power_on,OUTPUT);
//  pinMode(signal_on,INPUT);
//  pinMode(signal_dir,INPUT);
//  digitalWrite(power_on,HIGH);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:  
  int on_off_signal = digitalRead(on_off);
  int rot_signal = digitalRead(rot);
  if (on_off_signal==1){ 
    digitalWrite(env,LOW);
    if (rot_signal ==1){
      digitalWrite(dir,LOW);
      pulse_stepper(pul,4.5);
      // freq = less than 5; 
      //4.5 for clockwise 
      //3.2 for countclockwise
      //800 PULSE/rev s1 ON s2 OFF s3 OFF 
    }else{
      digitalWrite(dir,HIGH);
      pulse_stepper(pul,3);
    }
  }else{
    digitalWrite(env,HIGH);
  }
}

//pulse_stepper for control stepper motor in main loop
void pulse_stepper(int port_out,float Freq)
{
  digitalWrite(port_out,HIGH);
  delayMicroseconds(int((500000/Freq)/800));
  //delayMicroseconds(483);
  digitalWrite(port_out,LOW);
  delayMicroseconds(int((500000/Freq)/800));      
  //delayMicroseconds(483);
}
