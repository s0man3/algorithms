BINDIR = bin
LIBDIR = include
SRCDIR = src

LIB = $(wildcard $(LIBDIR)/*.cpp)
SRC = $(wildcard $(SRCDIR)/*.cpp)
TARGETS = $(subst .cpp,,$(notdir $(SRC)))

LIBOBJ = $(subst .cpp,.o,$(LIB))

CC = g++
CFLAGS = -I$(LIBDIR)

all: $(TARGETS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(addprefix $(BINDIR)/, $(TARGETS)): $(BINDIR)/%: $(SRCDIR)/%.o $(LIBOBJ)
	$(eval obj=$(notdir $@))
	$(CC) $(CFLAGS) -o $@ $(SRCDIR)/$(obj).o $(LIBOBJ)

$(TARGETS): %: $(BINDIR)/%

clean:
	rm -f $(SRCDIR)/*.o $(LIBDIR)/*.o $(LIBDIR)/*.gch $(BINDIR)/*
