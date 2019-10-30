CC = gcc
DEL_FILE = rm -f
COPY_FILE = cp -f
CFLAGS = -lm -Wno-pointer-to-int-cast -Wno-format -Wno-int-conversion

SRCDIR = src
INCDIR = headers
INCPATH = -I$(INCDIR)
TEMPDIR = .tmp

DEPS = bool List Stack Queue Matrix
SOURCES = main List Stack Queue Matrix

HEADERS = $(patsubst %,$(INCDIR)/%.h,$(DEPS))
OBJS =  $(patsubst %,$(TEMPDIR)/%.o,$(SOURCES))

all: wrgmavow

temp:
	test -d $(TEMPDIR) || mkdir $(TEMPDIR)

$(TEMPDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) temp
	$(CC) -c -O1 -o $@ $< $(INCPATH) $(CFLAGS)

wrgmavow: $(OBJS)
	$(CC) -o $@ $^ $(INCPATH) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TEMPDIR)/*.o
