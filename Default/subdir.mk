################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CommandOptions.cpp \
../Main.cpp \
../User.cpp 

OBJS += \
./CommandOptions.o \
./Main.o \
./User.o 

CPP_DEPS += \
./CommandOptions.d \
./Main.d \
./User.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I/usr/local/boost_1_63_0 -I/home/stanley/Documents/stanDB -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


