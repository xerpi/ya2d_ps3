#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

include	$(PSL1GHT)/ppu_rules

#---------------------------------------------------------------------------------
BUILD		:=	build

#---------------------------------------------------------------------------------
ifeq ($(strip $(PLATFORM)),)
#---------------------------------------------------------------------------------
export BASEDIR	:=	$(CURDIR)
export DEPS	:=	$(BASEDIR)/deps
export LIBS	:=	$(BASEDIR)/lib

#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
export LIBDIR	:=	$(LIBS)/$(PLATFORM)
export DEPSDIR	:=	$(DEPS)/$(PLATFORM)

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

LIBRARY		:=	libya2d

#---------------------------------------------------------------------------------
DEFINCS		:=	-I$(PORTLIBS)/include/freetype2 -I$(PORTLIBS)/include/ -I$(PORTLIBS)/include/ya2d -I$(PORTLIBS)/include/ -I$(PSL1GHT)/ppu/include -I$(PSL1GHT)/ppu/include/rsx -I$(PSL1GHT)/ppu/include/lv2 -I$(PSL1GHT)/ppu/include/sys
INCLUDES	:=	$(DEFINCS)

CFLAGS		:=	-O2 -mregnames -Wall -mcpu=cell $(MACHDEP) $(INCLUDES) -Wl,-mcell
CXXFLAGS	:=	$(CFLAGS) 
SOURCES     := source

CFILES		:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES	:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
sFILES		:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.s))
SFILES		:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.S))

CFLAGS		:=	-O2 -mregnames -Wall -mcpu=cell $(MACHDEP) $(INCLUDES) -Wl,-mcell
CXXFLAGS	:=	$(CFLAGS) 

#---------------------------------------------------------------------------------
VPATH		:=	$(BASEDIR)

#---------------------------------------------------------------------------------
OBJS		:= $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(sFILES:.s=.o) $(SFILES:.S=.o)


#---------------------------------------------------------------------------------

all: lib

lib: $(OBJS)
	ppu-ar cru $(LIBRARY).a $(OBJS)
	@echo lib done!
	
%.o: %.cpp
	ppu-gcc $(CXXFLAGS) -c $< -o $@
#---------------------------------------------------------------------------------
%.o: %.c
	ppu-gcc $(CFLAGS) -c $< -o $@


#---------------------------------------------------------------------------------


#---------------------------------------------------------------------------------
install:
#---------------------------------------------------------------------------------
	@[ -d $(PORTLIBS)/include/ya2d] || mkdir -p $(PORTLIBS)/include/ya2d
	@cp -frv include/*.h $(PORTLIBS)/include/ya2d
	@cp -frv $(LIBRARY).a $(PORTLIBS)/lib
	@echo lib installed!
#---------------------------------------------------------------------------------
$(LIBRARY).a: $(OBJS)
#---------------------------------------------------------------------------------

.PHONY: lib

#---------------------------------------------------------------------------------
clean:
#---------------------------------------------------------------------------------
	@echo lib cleaned ...
	@rm -rf $(OBJS)
	@rm -rf $(LIBRARY).a
	

#---------------------------------------------------------------------------------
-include $(DEPSDIR)/*.d
#---------------------------------------------------------------------------------
