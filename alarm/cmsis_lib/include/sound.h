#ifndef __SOUND_H
#define __SOUND_H

#ifdef __cplusplus
 extern "C" {
#endif

 extern float i;
 extern	int increase;

void DACinit();
void Delay(__IO uint32_t nCount);
void Play();


#ifdef __cplusplus
}
#endif

#endif /*__SOUND_H */
