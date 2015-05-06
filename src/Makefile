RM  ?= rm -vf

include mk.cross
include ../mk.defines

OBJDIR  =  objs

INCS    += -I.

CFLAGS  =  -Wall -std=c99 -fPIC -DREL_VERSION=\"$(REL_VERSION)\" $(INCS)
LDFLAGS =  -shared -lpthread $(LIBS)

CFILES  =  so_logger.c
OBJS    =  $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))

LIB_SONAME := so_logger
LIB_TARGET := lib$(LIB_SONAME)-$(REL_VERSION).so

LINK.c := $(CC) $(CFLAGS)

.PHONY: all

all: prebuild $(LIB_TARGET)

prebuild:
	@mkdir -p $(OBJDIR)

$(OBJS): $(OBJDIR)/%.o: %.c
	$(LINK.c) -c -o $@ $<

$(LIB_TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

check: $(TARGET)
	valgrind --leak-check=full ./$^

clean:
	@$(RM) -rf $(OBJDIR)
	@$(RM) $(LIB_TARGET) $(OBJS)
