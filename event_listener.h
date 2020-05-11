
#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#define CONFIG_PLATAFORM

#include <stdbool.h>
#include <linux/input.h>

#define EVENT_SWITCH_POWER KEY_POWER
#ifdef _def
#else
#define EVENT_SWITCH_VOLUP KEY_VOLUMEUP
#define EVENT_SWITCH_VOLDOWN KEY_VOLUMEDOWN
#endif

int do_listen();
bool power_button_is_pressed(void);

#endif // EVENT_LISTENER_H
