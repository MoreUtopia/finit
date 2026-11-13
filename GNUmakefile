CROSS_COMPILE ?= 
INIT_PATH ?= /init2
OUT_PATH ?= target/init 

CC := $(CROSS_COMPILE)gcc

SOURCES := $(shell find src -type f -name '*.c')

$(OUT_PATH): $(SOURCES)
	mkdir -p $(dir $@)
	$(CC) $(SOURCES) -static -ffreestanding -nostartfiles -nostdlib -fno-stack-protector -DINIT_PATH=\"$(INIT_PATH)\" -o $@
