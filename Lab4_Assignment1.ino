#include <TimerOne.h>
#include <MsTimer2.h>

/******** Constants ********/
#define PWMOUT 5
#define ADC_CHANNEL A0


// Sine Wave Generation 
const int SINE_FREQ = 23;                     // Sine wave's frequency to be generated. Hz.
const int SINE_GEN_FREQ = 500;                // Frequency of the sine wave generation system. Hz.
const float SINE_AMP = 2.5;                   // Sine wave's amplitude to be generated. Volts.
const float SINE_OFFSET = 2.5;                // Sine wave's offset to be generated. Volts.

// Sampling
const int SAMPLING_FREQ = 120;
const float TOTAL_SAMPLE_TIME = 1;

const float SINE_COEFF    = SINE_FREQ*TWO_PI/SINE_GEN_FREQ;
const float SINE_AMP_A    = SINE_AMP/5.00*255;
const float SINE_OFFSET_A = SINE_OFFSET/5.00*255;
const int NUMBER_OF_SAMPLES=TOTAL_SAMPLE_TIME*SAMPLING_FREQ;

int DUTY_CYCLE, SAMPLES[NUMBER_OF_SAMPLES];
long SINE_GEN_COUNTER, SAMPLING_COUNTER;
bool FINISHED=false;
void setup () {
  for (int i = 0 ; i < NUMBER_OF_SAMPLES ; i++) {
    SAMPLES [i] =- 1;
  }
  TCCR0B = TCCR0B & B11111000 | B00000001;
  pinMode(PWMOUT, OUTPUT);

  Serial.begin(57600);
  Serial.begin(57600);

  MsTimer2::set(1000/SINE_GEN_FREQ, PWM_DT) ;
  MsTimer2::start();

  Timer1.initialize(1e6/SAMPLING_FREQ);
  Timer1.attachInterrupt(SAMPLING);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (FINISHED) {
    for (int i = 0 ; i < NUMBER_OF_SAMPLES ; i++) {
      Serial.println(SAMPLES[i] ) ;
    }
    FINISHED=false;
  }
}


void PWM_DT () {
  DUTY_CYCLE = SINE_AMP_A * sin (SINE_COEFF*SINE_GEN_COUNTER) + SINE_OFFSET_A;
  analogWrite (PWMOUT, DUTY_CYCLE) ;
  SINE_GEN_COUNTER++;
}
void SAMPLING () {
if (SAMPLING_COUNTER == NUMBER_OF_SAMPLES) {
  MsTimer2::stop();
Timer1.detachInterrupt() ;
FINISHED=true;
}else {
SAMPLES [SAMPLING_COUNTER]=analogRead(ADC_CHANNEL);
SAMPLING_COUNTER++;
}
}
