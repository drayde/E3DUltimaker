#ifndef ULTI_LCD2_H
#define ULTI_LCD2_H

#include "Configuration.h"

#ifdef ENABLE_ULTILCD2
#include "UltiLCD2_low_lib.h"

void lcd_init();
void lcd_update();
FORCE_INLINE void lcd_setstatus(const char* message) {}
void lcd_buttons_update();
FORCE_INLINE void lcd_reset_alert_level() {}
FORCE_INLINE void lcd_buzz(long duration,uint16_t freq) {}

void doCooldown();

#define LCD_MESSAGEPGM(x)
#define LCD_ALERTMESSAGEPGM(x)

extern unsigned long lastSerialCommandTime;
extern uint8_t hotend_fan_pwm_level;
extern uint8_t hotend_fan_mode;
extern float dsp_temperature[EXTRUDERS];
extern float dsp_temperature_bed;
#define HOTEND_FAN_MODE_ALWAYS_ON      0
#define HOTEND_FAN_MODE_ALWAYS_OFF     1
#define HOTEND_FAN_MODE_WHILE_PRINTING 2

void lcd_menu_main();

#endif

#endif//ULTI_LCD2_H
