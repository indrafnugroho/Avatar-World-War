CC = gcc
DEL_FILE = rm -f
COPY_FILE = cp -f
CFLAGS = -Wno-pointer-to-int-cast -Wno-format -Wno-int-conversion -Wno-incompatible-pointer-types

SRCDIR = src
INCDIR = src
TEMPDIR = .tmp

DEPS = bool Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game
SOURCES = Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game
DRIV = List_driver Queue_driver Stack_driver
HEADERS = $(patsubst %,$(INCDIR)/*/%.h,$(DEPS))
OBJS =  $(patsubst %,$(TEMPDIR)/%.o,$(SOURCES))
INCPATH = -I$(INCDIR)

all: wrgmavow

drivers: $(DRIV)

temp:
	test -d $(TEMPDIR) || mkdir $(TEMPDIR)

$(TEMPDIR)/main.o: temp
	$(CC) -c -o $(TEMPDIR)/main.o $(SRCDIR)/main.c $(INCPATH) $(CFLAGS)

List_driver: $(TEMPDIR)/List_driver.o $(TEMPDIR)/List.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Queue_driver: $(TEMPDIR)/Queue_driver.o $(TEMPDIR)/Queue.o $(TEMPDIR)/List.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Stack_driver: $(TEMPDIR)/Stack_driver.o $(TEMPDIR)/Stack.o $(TEMPDIR)/List.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

$(TEMPDIR)/%.o: $(SRCDIR)/*/%.c $(HEADERS) temp
	$(CC) -c -O2 -o $@ $< $(INCPATH) $(CFLAGS)

wrgmavow: $(TEMPDIR)/main.o $(OBJS)
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TEMPDIR)/*.o
