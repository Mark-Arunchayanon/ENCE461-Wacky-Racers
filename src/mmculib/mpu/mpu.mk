MPU_DIR = $(DRIVER_DIR)/mpu

VPATH += $(MPU_DIR)
SRC += mpu9250.c

PERIPHERALS += twi

INCLUDES += -I$(MPU_DIR)

