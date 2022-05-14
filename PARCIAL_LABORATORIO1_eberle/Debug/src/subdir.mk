################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PARCIAL_LABORATORIO1.c \
../src/bicicleta.c \
../src/color.c \
../src/fecha.c \
../src/input.c \
../src/servicio.c \
../src/tipo.c \
../src/trabajo.c 

C_DEPS += \
./src/PARCIAL_LABORATORIO1.d \
./src/bicicleta.d \
./src/color.d \
./src/fecha.d \
./src/input.d \
./src/servicio.d \
./src/tipo.d \
./src/trabajo.d 

OBJS += \
./src/PARCIAL_LABORATORIO1.o \
./src/bicicleta.o \
./src/color.o \
./src/fecha.o \
./src/input.o \
./src/servicio.o \
./src/tipo.o \
./src/trabajo.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/PARCIAL_LABORATORIO1.d ./src/PARCIAL_LABORATORIO1.o ./src/bicicleta.d ./src/bicicleta.o ./src/color.d ./src/color.o ./src/fecha.d ./src/fecha.o ./src/input.d ./src/input.o ./src/servicio.d ./src/servicio.o ./src/tipo.d ./src/tipo.o ./src/trabajo.d ./src/trabajo.o

.PHONY: clean-src

