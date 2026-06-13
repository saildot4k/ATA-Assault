IOP_BIN = ../usbd.irx

# DEV9
DEV9_SKIP_SMAP_INIT ?= 0
DEV9_PSX_SUPPORT ?= 1
DEV9_GAMESTAR_WORKAROUND ?= 1
DEV9_ENABLE_AIF ?= 0

ifeq ($(DEV9_SKIP_SMAP_INIT),1)
IOP_CFLAGS += -DDEV9_SKIP_SMAP_INIT=1
endif

ifeq ($(DEV9_PSX_SUPPORT),1)
IOP_CFLAGS += -DDEV9_PSX_SUPPORT=1
endif

ifeq ($(DEV9_GAMESTAR_WORKAROUND),1)
IOP_CFLAGS += -DDEV9_GAMESTAR_WORKAROUND=1
endif

ifeq ($(DEV9_ENABLE_AIF),1)
IOP_CFLAGS += -DDEV9_ENABLE_AIF=1
endif

# BDM
BDM_OBJS = bdm.o part_driver.o part_driver_mbr.o part_driver_gpt.o
IOP_LIBS += ../libbdm/lib/libbdm.a
IOP_CFLAGS += -Iinclude -I../libbdm/include/ -I../bdm/include -Wno-strict-aliasing

# BDMFS_FATFS
BDMFS_FATFS_OBJS = ff.o ffsystem.o ffunicode.o fs_driver.o diskio.o main.o
IOP_LIBS += -static-libgcc -lgcc

IOP_OBJS = ps2dev9.o ata_bdm_main.o $(addprefix bdm_,$(BDM_OBJS)) $(addprefix bdmfs_,$(BDMFS_FATFS_OBJS)) imports.o exports.o

ifeq ($(DEBUG), 1)
  IOP_CFLAGS += -DDEBUG -DDEBUG_EXTREME
  IOP_BIN = ../usbd_debug.irx
endif

include ../global.make
IOP_SRC_DIR =
vpath %.c src/
vpath %.lst src/
vpath %.tab src/
vpath %.c ../__bdm_assault/src/bdm/
vpath %.c ../__bdm_assault/src/bdmfs/

$(IOP_OBJS_DIR)%.o: src/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@

$(IOP_OBJS_DIR)%.o: ../__bdm_assault/src/bdm/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@

$(IOP_OBJS_DIR)%.o: ../__bdm_assault/src/bdmfs/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@
