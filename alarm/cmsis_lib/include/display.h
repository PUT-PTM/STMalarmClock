#ifndef __DISPLAY_H
#define __DISPLAY_H

#ifdef __cplusplus
 extern "C" {
#endif

 extern char buf[50], buf2[50];
 extern int alarmhours, alarmminutes;
 extern int a,b;
 extern int active;
 extern int yeartemp, monthtemp, daytemp, hourstemp, minutestemp;




 void display_all();
 void display_date_hours();
 void display_alarm();


#ifdef __cplusplus
}
#endif

#endif /*__DISPLAY_H */
