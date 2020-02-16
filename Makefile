CC = g++


vpath %.h common/hdr
vpath %.h library/jsoncpp/json/
vpath %.h movie/hdr/

OBJDIR := OBJ
SRCS := $(shell find . -name '*.cpp')
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

CPPFLAGS =  \
		-Ilibrary/ \
		-Icommon/hdr \
		-I movie/hdr \
		-I/usr/local/include \
		-I/usr/local/lib \

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

all : buildrepo $(TARGET)

$(TARGET) : $(OBJS)
	@echo "Building $@..."
	@echo "@$(CC) $(OBJECTS) $(LDFLAGS) -o $@ $(LINK_LIBRARY)"
	cd $(OBJDIR) && $(CC) $(OBJECTS) $(LDFLAGS) -o $@ $(LINK_LIBRARY)

$(OBJDIR)/%.o: %.cpp
	@echo "Compiling $<..."
	$(CC) $(CPPFLAGS) -c $< -o $(OBJDIR)/$(notdir $@)


buildrepo:
	mkdir -p $(OBJDIR)

clean : 
	rm -rf */*.o \
	rm -rf *.o
	rm -rf OBJ
