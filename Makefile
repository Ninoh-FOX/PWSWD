ifeq ($(CONFIG),)
CONFIGS:=$(foreach CFG,$(wildcard config-*.mk),$(CFG:config-%.mk=%))
$(error Please specify CONFIG, possible values: $(CONFIGS))
endif

include config-$(CONFIG).mk

TARGET = pwswd

CC = $(CROSS_COMPILE)gcc

DEFAULT_MIXER ?= "\"PCM\""

CONFIG_PLATAFORM ?= _def

LIBS = -lini -lpthread
OBJS = event_listener.o shortcut_handler.o main.o

ifdef BACKEND_VOLUME
	OBJS += backend$(CONFIG_PLATAFORM)/volume/volume.o
	CFLAGS += -DBACKEND_VOLUME -DDEFAULT_MIXER=$(DEFAULT_MIXER)
	LIBS += -lasound
endif

ifdef BACKEND_BRIGHTNESS
	OBJS += backend$(CONFIG_PLATAFORM)/brightness/brightness.o
	CFLAGS += -DBACKEND_BRIGHTNESS
endif

ifdef BACKEND_SHARPNESS
	OBJS += backend$(CONFIG_PLATAFORM)/sharpness/sharpness.o
	CFLAGS += -DBACKEND_SHARPNESS
endif


ifdef BACKEND_POWEROFF
	OBJS += backend$(CONFIG_PLATAFORM)/poweroff/poweroff.o
	CFLAGS += -DBACKEND_POWEROFF
endif

ifdef BACKEND_REBOOT
	OBJS += backend$(CONFIG_PLATAFORM)/reboot/reboot.o
	CFLAGS += -DBACKEND_REBOOT
endif

ifdef BACKEND_SCREENSHOT
	OBJS += backend$(CONFIG_PLATAFORM)/screenshot/screenshot.o
	CFLAGS += -DBACKEND_SCREENSHOT
	LIBS += -lpng
endif

ifdef BACKEND_TVOUT
	OBJS += backend$(CONFIG_PLATAFORM)/tvout/tvout.o
	CFLAGS += -DBACKEND_TVOUT
endif

ifdef BACKEND_SUSPEND
	OBJS += backend$(CONFIG_PLATAFORM)/suspend/suspend.o
	CFLAGS += -DBACKEND_SUSPEND
endif

ifdef BACKEND_KILL
	OBJS += backend$(CONFIG_PLATAFORM)/kill/kill.o
	CFLAGS += -DBACKEND_KILL
endif

ifdef BACKEND_RATIOMODE
	OBJS += backend$(CONFIG_PLATAFORM)/ratiomode/ratiomode.o
	CFLAGS += -DBACKEND_RATIOMODE
endif


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
