CC = gcc
DEL_FILE = rm -f
COPY_FILE = cp -f
CFLAGS = -Wno-pointer-to-int-cast -Wno-format -Wno-int-conversion -Wno-incompatible-pointer-types

SRCDIR = src
INCDIR = src
TEMPDIR = .tmp

DEPS = bool Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game Command GameState
SOURCES = Art List Stack Queue  pcolor CharProcessor WordProcessor Building Loader ArrayDin Graph GameMap Player Game Command GameState
DRIV = List_driver Queue_driver Stack_driver pcolor_driver Art_driver Point_driver Graph_driver Building_driver Loader_driver Game_driver ArrayDin_driver
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

Art_driver: $(TEMPDIR)/Art_driver.o $(TEMPDIR)/Art.o $(TEMPDIR)/pcolor.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Graph_driver: $(TEMPDIR)/Graph_driver.o $(TEMPDIR)/Graph.o $(TEMPDIR)/List.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

pcolor_driver: $(TEMPDIR)/pcolor_driver.o $(TEMPDIR)/pcolor.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Point_driver: $(TEMPDIR)/Point_driver.o $(TEMPDIR)/Point.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Building_driver: $(TEMPDIR)/Building_driver.o $(TEMPDIR)/Building.o $(TEMPDIR)/Point.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

ArrayDin_driver: $(TEMPDIR)/ArrayDin_driver.o $(TEMPDIR)/ArrayDin.o $(TEMPDIR)/Building.o $(TEMPDIR)/Point.o
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Loader_driver: $(TEMPDIR)/Loader_driver.o $(TEMPDIR)/Loader.o $(TEMPDIR)/WordProcessor.o $(TEMPDIR)/CharProcessor.o $(TEMPDIR)/ArrayDin.o $(TEMPDIR)/GameMap.o $(TEMPDIR)/Building.o $(TEMPDIR)/Player.o $(TEMPDIR)/List.o $(TEMPDIR)/Graph.o $(TEMPDIR)/Queue.o $(TEMPDIR)/Art.o  $(TEMPDIR)/pcolor.o 
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

Game_driver: $(TEMPDIR)/Game_driver.o $(TEMPDIR)/Game.o $(TEMPDIR)/Loader.o $(TEMPDIR)/WordProcessor.o $(TEMPDIR)/CharProcessor.o $(TEMPDIR)/ArrayDin.o $(TEMPDIR)/GameMap.o $(TEMPDIR)/Building.o $(TEMPDIR)/Player.o $(TEMPDIR)/List.o $(TEMPDIR)/Graph.o $(TEMPDIR)/Queue.o $(TEMPDIR)/Art.o  $(TEMPDIR)/pcolor.o $(TEMPDIR)/Stack.o $(TEMPDIR)/GameState.o $(TEMPDIR)/Command.o  
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)


$(TEMPDIR)/%.o: $(SRCDIR)/*/%.c $(HEADERS) temp
	$(CC) -c -o $@ $< $(INCPATH) $(CFLAGS)

wrgmavow: $(TEMPDIR)/main.o $(OBJS)
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TEMPDIR)/*.o
