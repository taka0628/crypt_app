TARGET := main
OBJECTS += main.o sha1.o
CC	:= g++
CFLAGS	:= -c -Wall -O1
LIBS := -lssl -lcrypto -I.
RM	:= /bin/rm

all:${OBJECTS}
	$(CC) ${OBJECTS} -o ${TARGET} ${LIBS}

%.o: %.cpp
	$(CC) ${CFLAGS} $< -o $@ $(LIBS)

aes.o:../aes_c.cpp
	$(CC) ${CFLAGS} $< -o $@ $(LIBS)

run: $(TARGET)
	./$(TARGET)

debug:
	$(CC) -g -Wall -O0 main.cpp ../aes_c.cpp -o ${TARGET} ${LIBS}

clean:
	rm -rf ${OBJECTS} ${TARGET}