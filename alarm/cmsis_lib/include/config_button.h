#ifndef __CONFIG_BUTTON_H
#define __CONFIG_BUTTON_H

#ifdef __cplusplus
 extern "C" {
#endif


 extern char buf[50], buf2[50];
 extern int alarmhours, alarmminutes;
 extern int a,b;
 extern int active;
 extern int yeartemp, monthtemp, daytemp, hourstemp, minutestemp;


 void timer();
 void Configure_PB9(void);
 void Configure_PB11(void);
 void Configure_PB12(void);
 void Configure_PB13(void);
 void Configure_PB14(void);
 void Configure_PB15(void);

 void EXTI9_5_IRQHandler(void);
 void EXTI15_10_IRQHandler(void);

 void graj();
 void TM_RTC_RequestHandler();

#ifdef __cplusplus
}
#endif

#endif /*__CONFIG_BUTTON_H */
