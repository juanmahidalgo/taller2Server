################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Factories/ConversationFactory.cpp \
../src/Factories/Factory.cpp \
../src/Factories/MessageFactory.cpp \
../src/Factories/UserFactory.cpp 

OBJS += \
./src/Factories/ConversationFactory.o \
./src/Factories/Factory.o \
./src/Factories/MessageFactory.o \
./src/Factories/UserFactory.o 

CPP_DEPS += \
./src/Factories/ConversationFactory.d \
./src/Factories/Factory.d \
./src/Factories/MessageFactory.d \
./src/Factories/UserFactory.d 


# Each subdirectory must supply rules for building sources it contributes
src/Factories/%.o: ../src/Factories/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -lJsoncpp -lopencv_java -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


