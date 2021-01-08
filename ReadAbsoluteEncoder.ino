int enA = 4;
int enB = 5;
int enI = 6;
int abss = 7;
int val = 0;
int ontime, offtime, rotations;
float duty, freq, angle, mappedDuty, period;

void setup() {
  // put your setup code here, to run once:
  pinMode(abss, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  ontime = pulseIn(abss, HIGH);
  offtime = pulseIn(abss, LOW);
  period = ontime + offtime;
  freq = 1000000.0 / period;
  duty = (ontime / period) * 100;
  //remap from 0:100 to 0:360
  mappedDuty = map(duty, 0, 100, 0, 360);
  Serial.println(mappedDuty);
  //delay 10 milliseconeds
  delay(10);
}
