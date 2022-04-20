#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#
# Modified by Wasted Audio
#

include dpf/Makefile.base.mk

all: libs plugin gen

define MISSING_SUBMODULES_ERROR

Cannot find DGL! Please run "make submodules" to clone the missing submodules, then retry building the plugin.

endef

# --------------------------------------------------------------
submodules:
	git submodule update --init --recursive

libs:

plugin: libs
	$(MAKE) all -C plugin/source

gen: plugins dpf/utils/lv2_ttl_generator
	@$(CURDIR)/dpf/utils/generate-ttl.sh
ifeq ($(MACOS),true)
	@$(CURDIR)/dpf/utils/generate-vst-bundles.sh
endif

dpf/utils/lv2_ttl_generator:
	$(MAKE) -C dpf/utils/lv2-ttl-generator

# --------------------------------------------------------------

clean:
	$(MAKE) clean -C dpf/utils/lv2-ttl-generator
	$(MAKE) clean -C plugin/source

# --------------------------------------------------------------

.PHONY: plugins