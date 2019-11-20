CC = gcc
DEL_FILE = rm -f
COPY_FILE = cp -f
CFLAGS = -Wno-pointer-to-int-cast -Wno-format -Wno-int-conversion -Wno-incompatible-pointer-types

SRCDIR = src
INCDIR = src
TEMPDIR = .tmp

DEPS = bool Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game
SOURCES = Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game
DRIV = List_driver
HEADERS = $(patsubst %,$(INCDIR)/*/%.h,$(DEPS))
OBJS =  $(patsubst %,$(TEMPDIR)/%.o,$(SOURCES))
INCPATH = -I$(INCDIR)

all: wrgmavow

drivers: List_driver

temp:
	test -d $(TEMPDIR) || mkdir $(TEMPDIR)

$(TEMPDIR)/main.o: temp
	$(CC) -c -O1 -o $(TEMPDIR)/main.o $(SRCDIR)/main.c $(INCPATH) $(CFLAGS)

List_driver: $(TEMPDIR)/List_driver.o $(TEMPDIR)/List.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

$(TEMPDIR)/%.o: $(SRCDIR)/*/%.c $(HEADERS) temp
	$(CC) -c -O1 -o $@ $< $(INCPATH) $(CFLAGS)

wrgmavow: $(TEMPDIR)/main.o $(OBJS)
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TEMPDIR)/*.o
