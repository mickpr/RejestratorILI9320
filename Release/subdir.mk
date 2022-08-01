################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fat32.c \
../font.c \
../graphics.c \
../i2c.c \
../ili9320.c \
../main.c \
../mcp4725.c \
../pcf8583.c \
../sd.c \
../spi.c \
../uart.c 

OBJS += \
./fat32.o \
./font.o \
./graphics.o \
./i2c.o \
./ili9320.o \
./main.o \
./mcp4725.o \
./pcf8583.o \
./sd.o \
./spi.o \
./uart.o 

C_DEPS += \
./fat32.d \
./font.d \
./graphics.d \
./i2c.d \
./ili9320.d \
./main.d \
./mcp4725.d \
./pcf8583.d \
./sd.d \
./spi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Programs\AVR\WinAVR\avr\include" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=11059200UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


