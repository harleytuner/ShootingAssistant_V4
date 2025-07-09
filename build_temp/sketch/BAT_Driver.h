#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\BAT_Driver.h"
#pragma once
#include <Arduino.h> 

#define BAT_ADC_PIN   8
#define Measurement_offset 0.990476   

extern float BAT_analogVolts;

void BAT_Init(void);
float BAT_Get_Volts(void);