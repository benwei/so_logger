
include ../src/mk.cross
include ../mk.defines

OBJDIR = objs

LIBSO_LOGGER_DIR = ../src/
SOLIB_PATHNAME = $(LIBSO_LOGGER_DIR)/libso_logger-$(REL_VERSION).so

INCS += -I.
INCS += -I$(LIBSO_LOGGER_DIR)

CFLAGS   =  -Wall
CFLAGS   += -std=c99 $(INCS)
CXXFLAGS =  -Wall $(INCS) -std=c++0x
LDFLAGS  =  -lpthread
LIBS     =  -L$(LIBSO_LOGGER_DIR) -lso_logger-$(REL_VERSION)
LDFLAGS  += $(LIBS)

CFILES =
CXXFILES = main.cpp
COBJS    = $(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
CXXOBJS  = $(addprefix $(OBJDIR)/, $(subst .cpp,.o,$(CXXFILES)))
OBJS     = $(COBJS) $(CXXOBJS)

TARGET   = logger_tester

all: prebuild run

prebuild:
	mkdir -p $(OBJDIR)

$(COBJS): $(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(CXXOBJS): $(OBJDIR)/%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(SOLIB_PATHNAME):
	make -C ../src HOST=1

$(TARGET): $(OBJS) $(SOLIB_PATHNAME)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

run: $(TARGET)
	$(RM) *.log
	LD_LIBRARY_PATH=$(LIBSO_LOGGER_DIR) ./$(TARGET) ; sh ./check.sh

check: $(TARGET)
	LD_LIBRARY_PATH=$(LIBSO_LOGGER_DIR) valgrind --leak-check=full ./$^

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(TARGET) $(OBJS)
	$(RM) $(LIBSO_LOGGER_DIR)/objs/*.o
	$(RM) *.log
	make -C ../src HOST=1 clean
