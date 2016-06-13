#ifndef __CONFIG_BUTTON_H
#define __CONFIG_BUTTON_H

#ifdef __cplusplus
 extern "C" {
#endif


 extern int alarmhours, alarmminutes; // zmienne przechowujace godzine i minuty ustawionego alarmu
 extern int a,b; // a - aktualnie wyswietlany pulpit ( 0 - pulpit glowny, 1 - ustawianie daty i godziny, 2 -ustawianie alarmu
 extern int active; //zmienna przechowujaca stan alarmu
 extern int yeartemp, monthtemp, daytemp, hourstemp, minutestemp;
//zmienne przechowujace tymczasowa date i godzine podczas edycji daty i godziny

 void timer();
 void Configure_PB9(void);
 void Configure_PB11(void);
 void Configure_PB12(void);
 void Configure_PB13(void);
 void Configure_PB14(void);


 void EXTI9_5_IRQHandler(void);
 void EXTI15_10_IRQHandler(void);

 void play();
 void TM_RTC_RequestHandler();

#ifdef __cplusplus
}
#endif

#endif /*__CONFIG_BUTTON_H */
