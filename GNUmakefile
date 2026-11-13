CROSS_COMPILE ?= 
INIT_PATH ?= /init2
OUT_PATH ?= target/init 

CC := $(CROSS_COMPILE)gcc

SOURCES := $(shell find src -type f -name '*.c')

$(OUT_PATH): $(SOURCES)
	git submodule update --init --recursive
	mkdir -p $(dir $@)
	$(CC) $(shell find external/ulibc/src -type f -name '*.c') $(SOURCES) -static -ffreestanding -nostartfiles -nostdlib -fno-stack-protector -Iexternal/ulibc/include -DINIT_PATH=\"$(INIT_PATH)\" -o $@
