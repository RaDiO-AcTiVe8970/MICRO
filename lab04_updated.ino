const int SwitchPin = 8;
unsigned long PreviousTime = 0;
int SwitchState = 0;
int PrevSwitchState =0;
int led=2;
long interval =1000;
void setup() {
  // put your setup code here, to run once:
for(int x = 2;x<8;x++){
  pinMode(x,OUTPUT);
  }
  pinMode(SwitchPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long CurrentTime = millis();
if(CurrentTime - PreviousTime > interval){
  PreviousTime = CurrentTime;
  digitalWrite(led,HIGH);
  led++;
  if(led==7){
    }
  }
  SwitchState = digitalRead(SwitchPin);
  if(SwitchState != PrevSwitchState){
    for(int x = 2;x<8;x++){
      digitalWrite(x,LOW);
      }
      led = 2;
      PreviousTime = CurrentTime;
      
    }
    PrevSwitchState = SwitchState;
}
