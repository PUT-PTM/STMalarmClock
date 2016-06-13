# STMalarmClock

##OVERVIEW
Simple alarm clock implements on STM32F4. 
##Tools
CooCox CoIDE, Version 1.7.8

##What you need:
- Microcontroler STM32F4xxx
- 1 speaker (which you can connect to STM32F4xxx)
- 5 buttons (which you can connect to STM32F4xxx)
- 1 PCD8544 LCD 

## How to connect 
1. PCD8544 
  1. VCC -> 3V
  2. GND -> GND 
  3. SCE -> PC13
  4. RST -> PC15
  5. D/C -> PC14
  6. DN(MOSI) -> PC3
  7. SCLK -> PB10
  8. LED -> 3V
2. Buttons
  1. button -> PB9
  2. button -> PB11
  3. button -> PB13
  4. button -> PB14
  5. button -> PB12 
3. Speaker 
  1. GND -> GND 
  2. 5V -> 5V
  3. AMP -> PA4

## How to control 
1. First button is used to increase current modified value.
2. Second button is used to change current modified value.
3. Third button is used to decrease current modified value.
4. Fourth button is used to change display information between Time&Data set mode, Alarm Set mode and main mode.  
5. Fifth button is used to turn on or turn off alarm. 

##Libraries by Tilen Majerle 
1. [This is RTC library] (http://stm32f4-discovery.net/2014/07/library-19-use-internal-rtc-on-stm32f4xx-devices/)
2. [This is PCD8544 library] (http://stm32f4-discovery.net/pcd8544-nokia-33105110-lcd-stm32f429-discovery-library/)

## Made by 
 1. Patryk Smól 
 2. Marcin Skorupiński 
 
#### [Short film which presents how it works.] (https://www.youtube.com/watch?edit=vd&v=AwXuFz8WyZg)
