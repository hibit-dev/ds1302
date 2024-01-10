// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "virtuabotixRTC.h"

#define DS1302_CLK_PIN A5
#define DS1302_DAT_PIN A4
#define DS1302_RST_PIN 13

#define CURRENT_SECONDS 45
#define CURRENT_MINUTES 30
#define CURRENT_HOURS 11
#define CURRENT_DAY_OF_WEEK 1
#define CURRENT_DAY_OF_MONTH 6
#define CURRENT_MONTH 11
#define CURRENT_YEAR 2023

virtuabotixRTC RTC(DS1302_CLK_PIN, DS1302_DAT_PIN, DS1302_RST_PIN);

void setup()
{
  Serial.begin(115200);

  // Once the battery is installed,
  // the module stores the value in memory
  RTC.setDS1302Time(
    CURRENT_SECONDS,
    CURRENT_MINUTES,
    CURRENT_HOURS,
    CURRENT_DAY_OF_WEEK,
    CURRENT_DAY_OF_MONTH,
    CURRENT_MONTH,
    CURRENT_YEAR
  );
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
