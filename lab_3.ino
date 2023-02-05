#define RED_PIN 8
#define YELLOW_PIN 10
#define GREEN_PIN 12

int red_on= 3000;
int red_yellow_on=1000;
int green_on=8000;
int green_blink=500;
int yellow_on=9000;

int delay_timer(int miliseconds)
{
  int count=0;
  while(1)
  {
    if(TCNT0>=4)
    {
      TCNT0=0;
      count++;
      if(count==miliseconds)
      {
        count=0;
        break;
        }
      }
    }
  return 0;
  }
void setup() {
  pinMode(RED_PIN,OUTPUT);
  pinMode(YELLOW_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);

  TCCR0A= 0b00000000;
  TCCR0B=0b00000101;
  TCNT0=0;
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(RED_PIN, HIGH);
delay_timer(red_on);
digitalWrite(YELLOW_PIN, HIGH);
delay_timer(red_yellow_on);

digitalWrite(RED_PIN, LOW);
digitalWrite(YELLOW_PIN,LOW);
digitalWrite(GREEN_PIN,HIGH);
delay_timer(green_on);
digitalWrite(GREEN_PIN,LOW);
for(int i=0;i<5; i=i+1)
{
  delay_timer(green_blink);
  digitalWrite(GREEN_PIN,HIGH);
  delay_timer(green_blink);
  digitalWrite(GREEN_PIN,LOW);
}
  digitalWrite(YELLOW_PIN,HIGH);
  delay_timer(yellow_on);
  digitalWrite(YELLOW_PIN,LOW);
}
