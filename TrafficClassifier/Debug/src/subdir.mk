################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Classificator.cpp \
../src/Database.cpp \
../src/Signature.cpp \
../src/TrafficInspect.cpp 

OBJS += \
./src/Classificator.o \
./src/Database.o \
./src/Signature.o \
./src/TrafficInspect.o 

CPP_DEPS += \
./src/Classificator.d \
./src/Database.d \
./src/Signature.d \
./src/TrafficInspect.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/miguel/workspace/FileSystemOperations" -I"/home/miguel/workspace/PCapWrap" -I"/home/miguel/workspace/TrafficInspector" -I"/home/miguel/workspace/TrafficAnalyzer" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


