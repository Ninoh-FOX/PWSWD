
#ifndef SHORTCUT_HANDLER_H
#define SHORTCUT_HANDLER_H

#define CONFIG_PLATAFORM

#define NB_MAX_KEYS 4

#define BUTTON_A KEY_LEFTCTRL
#define BUTTON_B KEY_LEFTALT
#ifdef _def
#define BUTTON_L KEY_TAB
#define BUTTON_R KEY_BACKSPACE
#else
#define BUTTON_L1 KEY_TAB
#define BUTTON_R1 KEY_BACKSPACE
#endif
#define BUTTON_UP KEY_UP
#define BUTTON_DOWN KEY_DOWN
#define BUTTON_LEFT KEY_LEFT
#define BUTTON_RIGHT KEY_RIGHT
#define BUTTON_START KEY_ENTER
#define BUTTON_SELECT KEY_ESC
#define BUTTON_POWER KEY_HOME
#define BUTTON_HOLD KEY_PAUSE
#ifdef _def
#else
#ifdef _pg2
#define BUTTON_L2 KEY_RIGHTSHIFT
#define BUTTON_R2 KEY_RIGHTALT
#define BUTTON_MENU KEY_RIGHTCTRL
#endif
#ifdef _rg350
#define BUTTON_L2 KEY_PAGEUP
#define BUTTON_R2 KEY_PAGEDOWN
#define BUTTON_L3 KEY_KPSLASH
#define BUTTON_R3 KEY_KPDOT
#endif
#ifdef _pg2v2
#define BUTTON_MENU KEY_RIGHTCTRL
#endif
#endif

#define BUTTON_VOLUP KEY_VOLUMEUP
#define BUTTON_VOLDOWN KEY_VOLUMEDOWN

#ifdef WITH_REVERSED_X_Y
#define BUTTON_X KEY_SPACE
#define BUTTON_Y KEY_LEFTSHIFT
#else
#define BUTTON_X KEY_LEFTSHIFT
#define BUTTON_Y KEY_SPACE
#endif

enum event_type {
	reboot, poweroff, suspend, hold,
	volup, voldown,
	brightup, brightdown,
	sharpup, sharpdown,
	mouse, tvout, screenshot,
	kill, ratiomode, dpad, dpadmouse,
	noanalog
};

struct button {
	const char *name;
	size_t name_len;
	unsigned short id;
	unsigned short state;
};

extern struct button buttons[];
extern unsigned int nb_buttons;


struct shortcut {
	enum event_type action;
	struct button * keys[NB_MAX_KEYS];
	int nb_keys;
	struct shortcut *prev;
};


int read_conf_file(const char *filename);
const struct shortcut * getShortcuts();
void deinit();

#endif // SHORTCUT_HANDLER_H
