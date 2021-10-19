NAME = dpf_mySamplero

FILES_DSP = $(wildcard *.cpp)
FILES_DSP += $(wildcard *.c)

include ../../dpf/Makefile.plugins.mk

LINK_FLAGS += -lpthread


	
TARGETS += lv2_dsp
	
TARGETS += vst
	
TARGETS += jack
	


all: $(TARGETS)