TARGET=main
OBJECT_FILES=main.o

PORT ?= /dev/ttyACM0
AVRDUDE=avrdude
DEVICE = atmega328p
MCU = atmega328p
AVRDUDE_DEVICE = m328p

F_CPU = 20000000


CFLAGS=-g -Wall -mcall-prologues -Os -std=c99 -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(DEVICE_SPECIFIC_CFLAGS)
CC=avr-gcc
OBJ2HEX=avr-objcopy
LDFLAGS=-Wl,-gc-sections -lpololu_$(DEVICE) -Wl,-relax


default: $(TARGET)

clean:
	rm -f *.o *.hex *.obj $(TARGET)

pushbutton_driver.o: pushbutton_driver.c pushbutton_driver.h
	$(CC) -c  $(CFLAGS) pushbutton_driver.c -o pushbutton_driver.o

led_driver.o: led_driver.c led_driver.h
	$(CC) -c  $(CFLAGS) led_driver.c -o led_driver.o

motor_driver.o: motor_driver.c motor_driver.h
	$(CC) -c  $(CFLAGS) motor_driver.c -o motor_driver.o

$(TARGET): led_driver.o pushbutton_driver.o motor_driver.o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c led_driver.o pushbutton_driver.o motor_driver.o

$(TARGET).hex: $(TARGET)
	avr-strip $(TARGET)
	$(OBJ2HEX) -R .eeprom -O ihex $(TARGET) $(TARGET).hex

program: $(TARGET).hex
	$(AVRDUDE) -p $(AVRDUDE_DEVICE) -c avrisp2 -P $(PORT) -U flash:w:$(TARGET).hex
