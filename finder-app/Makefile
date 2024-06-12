CC:= gcc
CFLAGS:= -g -Wall

SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)

CROSS_COMPILE ?= 

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	-rm -f *.o $(TARGET) *.elf *.map
