// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "virtuabotixRTC.h"

#define DS1302_CLK_PIN A5
#define DS1302_DAT_PIN A4
#define DS1302_RST_PIN 13

virtuabotixRTC RTC(DS1302_CLK_PIN, DS1302_DAT_PIN, DS1302_RST_PIN);

void setup()
{
  Serial.begin(115200);

  // Set sketch compiling time
  setDateTime(RTC, __DATE__, __TIME__);
}

void loop()
{
  // Allow updates of variables
  RTC.updateTime();
  
  Serial.print("Current Date and time: ");

  Serial.print(RTC.year);
  Serial.print("/");
  Serial.print(RTC.month);
  Serial.print("/");
  Serial.print(RTC.dayofmonth);

  Serial.print(" ");

  Serial.print(RTC.hours);
  Serial.print(":");
  Serial.print(RTC.minutes);
  Serial.print(":");
  Serial.print(RTC.seconds);

  // New line
  Serial.println();

  // Add one second delay between iterations
  delay(1000);
}
