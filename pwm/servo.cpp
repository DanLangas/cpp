;******************************************************************
;  // setup PWM for a 50-usec period (8-MHz INTOSC, Timer 2
;  // prescale 1:1, and PR2 = 99)
;
;  char duty1 = 50;             // 20-KHz duty cycle, 25 or 50
;  char duty2 = 1;              // 2-KHz duty cycle, 1..9 (10%..90%)
;  char pwm2 = 9;               // preset 2-KHz duty cycle counter
;
;  void interrupt()             // 50-usec interrupt intervals
;  { pir1.TMR2IF = 0;           // clear timer 2 interrupt flag
;    ccpr1l = duty1;            // update PWM1 (20-KHz) duty cycle
;    pwm2++;                    // increment PWM2 period counter
;    if(pwm2 == 10)             // if end of 500-usec period
;    { pwm2 = 0; gpio.1 = 1;    // reset counter, turn output "on"
;    }                          //
;    if(duty2 == pwm2)          // if PWM2 duty cycle match
;      gpio.1 = 0;              // turn PWM2 output "off"
;  }                            //
;
