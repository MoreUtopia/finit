CROSS_COMPILE ?= 
INIT_PATH ?= /init2
OUT_PATH ?= target/init 

# used for development purposes
LOCAL_ULIBC_PATH ?= external/ulibc

CC := $(CROSS_COMPILE)gcc

SOURCES := $(shell find src -type f -name '*.c')

$(OUT_PATH): $(SOURCES)
	git submodule update --init --recursive
	mkdir -p $(dir $@)
	$(CC) $(shell find $(LOCAL_ULIBC_PATH)/src -type f -name '*.c') $(SOURCES) -static -ffreestanding -nostartfiles -nostdinc -nostdlib -fno-stack-protector -I$(LOCAL_ULIBC_PATH)/include -DINIT_PATH=\"$(INIT_PATH)\" -o $@
