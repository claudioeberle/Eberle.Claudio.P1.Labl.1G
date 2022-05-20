################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PARCIAL_LABO.c \
../src/bicicleta.c \
../src/cliente.c \
../src/color.c \
../src/fecha.c \
../src/informes.c \
../src/input.c \
../src/servicio.c \
../src/tipo.c \
../src/trabajo.c 

C_DEPS += \
./src/PARCIAL_LABO.d \
./src/bicicleta.d \
./src/cliente.d \
./src/color.d \
./src/fecha.d \
./src/informes.d \
./src/input.d \
./src/servicio.d \
./src/tipo.d \
./src/trabajo.d 

OBJS += \
./src/PARCIAL_LABO.o \
./src/bicicleta.o \
./src/cliente.o \
./src/color.o \
./src/fecha.o \
./src/informes.o \
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
	-$(RM) ./src/PARCIAL_LABO.d ./src/PARCIAL_LABO.o ./src/bicicleta.d ./src/bicicleta.o ./src/cliente.d ./src/cliente.o ./src/color.d ./src/color.o ./src/fecha.d ./src/fecha.o ./src/informes.d ./src/informes.o ./src/input.d ./src/input.o ./src/servicio.d ./src/servicio.o ./src/tipo.d ./src/tipo.o ./src/trabajo.d ./src/trabajo.o

.PHONY: clean-src

