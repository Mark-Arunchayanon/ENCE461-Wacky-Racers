RF_DIR = $(DRIVER_DIR)/rf

VPATH += $(RF_DIR)
SRC += nrf24.c

PERIPHERALS += spi

INCLUDES += -I$(RF_DIR)

