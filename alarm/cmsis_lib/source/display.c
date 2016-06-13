#include "tm_stm32f4_pcd8544.h"
#include "attributes.h"
#include "tm_stm32f4_rtc.h"
#include "config_button.h"



 TM_RTC_Time_t datatime;


void display_all()
{
    TM_RTC_GetDateTime(&datatime, TM_RTC_Format_BIN);
//konwersja aktualnej godziny i daty do typu int
	int h=datatime.hours;
	char hours[16];
	itoa(h, hours, 10);

	int m=datatime.minutes;
	char minutes[16];
	itoa(m, minutes, 10);

	int s=datatime.seconds;
	char sec[16];
	itoa(s, sec, 10);

	int y=datatime.year + 2000;
	char year[16];
	itoa(y, year, 10);

	int mon=datatime.month;
	char month[16];
	itoa(mon, month, 10);

	int d=datatime.date;
	char day[16];
	itoa(d, day, 10);

	int hour=alarmhours;
	char hours_alarm[16];
	itoa(hour, hours_alarm, 10);

	int min=alarmminutes;
	char minutes_alarm[16];
	itoa(min, minutes_alarm, 10);

//wyswietlanie godziny i daty
	PCD8544_Clear();

	PCD8544_GotoXY(5, 3);
	PCD8544_Puts("TIME:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(30, 3);
	PCD8544_Puts(hours, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(42, 3);
	PCD8544_Puts(":", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(48, 3);
	PCD8544_Puts(minutes, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(60, 3);
	PCD8544_Puts(":", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(66, 3);
	PCD8544_Puts(sec, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

	PCD8544_GotoXY(5, 13);
	PCD8544_Puts("ALARM:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(40, 13);
	PCD8544_Puts(hours_alarm, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(52, 13);
	PCD8544_Puts(":", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(58, 13);
	PCD8544_Puts(minutes_alarm, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

	PCD8544_GotoXY(5, 26);
	PCD8544_Puts("DATE:", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(25, 26);
	PCD8544_Puts(year, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(41, 26);
	PCD8544_Puts("-", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(45, 26);
	PCD8544_Puts(month, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(54, 26);
	PCD8544_Puts("-", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(59, 26);
	PCD8544_Puts(day, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

	PCD8544_GotoXY(5, 32);
	PCD8544_Puts("Alarm state: ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

	if(active==0)
	{
		PCD8544_GotoXY(57, 32);
		PCD8544_Puts("OFF ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
	else
	{
		PCD8544_GotoXY(57, 32);
		PCD8544_Puts("ON ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}

	PCD8544_Refresh();
}
void display_date_hours()
{
			int h=hourstemp;
			char hours[16];
			itoa(h, hours, 10);

			int m=minutestemp;
			char minutes[16];
			itoa(m, minutes, 10);

			int y=yeartemp + 2000;
			char year[16];
			itoa(y, year, 10);

			int mon=monthtemp;
			char month[16];
			itoa(mon, month, 10);

			int d=daytemp;
			char day[16];
			itoa(d, day, 10);

			PCD8544_Clear();

			PCD8544_GotoXY(5, 3);
			PCD8544_Puts("TIME:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			PCD8544_GotoXY(30, 3);
			PCD8544_Puts(hours, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			PCD8544_GotoXY(42, 3);
			PCD8544_Puts(":", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			PCD8544_GotoXY(48, 3);
			PCD8544_Puts(minutes, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

			PCD8544_GotoXY(5, 26);
			PCD8544_Puts("DATE:", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			PCD8544_GotoXY(25, 26);
			PCD8544_Puts(year, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			PCD8544_GotoXY(41, 26);
			PCD8544_Puts("-", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			PCD8544_GotoXY(45, 26);
			PCD8544_Puts(month, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			PCD8544_GotoXY(54, 26);
			PCD8544_Puts("-", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			PCD8544_GotoXY(59, 26);
			PCD8544_Puts(day, PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

}
//wyswietlanie menu alarm
void display_alarm()
{
	int h=alarmhours;
	char hours[16];
	itoa(h, hours, 10);

	int m=alarmminutes;
	char minutes[16];
	itoa(m, minutes, 10);


	PCD8544_Clear();

	PCD8544_GotoXY(5, 3);
	PCD8544_Puts("Alarm:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(41, 3);
	PCD8544_Puts(hours, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(53, 3);
	PCD8544_Puts(":", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(59, 3);
	PCD8544_Puts(minutes, PCD8544_Pixel_Set, PCD8544_FontSize_5x7);


	PCD8544_GotoXY(5, 32);
	PCD8544_Puts("Alarm state: ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

	if(active==0)
	{
		PCD8544_GotoXY(57, 32);
		PCD8544_Puts("OFF ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
	else
	{
		PCD8544_GotoXY(57, 32);
		PCD8544_Puts("ON ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}

}
