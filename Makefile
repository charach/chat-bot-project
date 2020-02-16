CPP = g++
vpath %.cpp common/src/
vpath %.cpp library/jsoncpp/
vpath %.cpp movie/src/

vpath %.h common/hdr
vpath %.h library/jsoncpp/json/
vpath %.h movie/hdr/

CPPFLAGS =  \
		-I library/ \
		-I common/hdr \
		-I movie/hdr \
		-I/usr/local/include \
		-L/usr/local/lib \

INCLUDE = \
		-I/usr/local/include \
		-L/usr/local/lib \
		-I library/ \
		-I common/hdr \
		-I movie/hdr \

LINK_LIBRARY = \
		-lcurl			

OBJECTS = \
	commonLog.o \
	commonMsg.o \
	commonRest.o \
	movieMsg.o \
	movieRest.o \
	jsoncpp.o \
	main.o \

TARGET = chatbot

all : $(TARGET)
	
$(TARGET) : $(OBJECTS)
	$(CPP) -Wall -Wextra -o $@ $^ $(LINK_LIBRARY)
	
clean : 
	rm -rf */*.o \
	rm -rf *.o
