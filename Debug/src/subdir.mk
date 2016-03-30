################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Conversation.cpp \
../src/Database.cpp \
../src/HttpRequest.cpp \
../src/HttpRequestHandler.cpp \
../src/Message.cpp \
../src/Server.cpp \
../src/User.cpp \
../src/jsoncpp.cpp \
../src/match.cpp 

C_SRCS += \
../src/mongoose.c 

OBJS += \
./src/Conversation.o \
./src/Database.o \
./src/HttpRequest.o \
./src/HttpRequestHandler.o \
./src/Message.o \
./src/Server.o \
./src/User.o \
./src/jsoncpp.o \
./src/match.o \
./src/mongoose.o 

CPP_DEPS += \
./src/Conversation.d \
./src/Database.d \
./src/HttpRequest.d \
./src/HttpRequestHandler.d \
./src/Message.d \
./src/Server.d \
./src/User.d \
./src/jsoncpp.d \
./src/match.d 

C_DEPS += \
./src/mongoose.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -lJsoncpp -lopencv_java -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -LDFLAGS= -pthread -lpthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


