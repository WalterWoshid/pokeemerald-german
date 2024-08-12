### Build Configuration ###

# Default variables
GAME_VERSION  ?= EMERALD
GAME_REVISION ?= 0
GAME_LANGUAGE ?= ENGLISH
DEBUG         ?= 0
MODERN        ?= 0
COMPARE       ?= 0

# For gbafix
MAKER_CODE := 01

# Version
BUILD_NAME := emerald
TITLE      := POKEMON EMER
GAME_CODE  := BPE

# Language
ifeq ($(GAME_LANGUAGE),ENGLISH)
  BUILD_NAME := $(BUILD_NAME)
  GAME_CODE  := $(GAME_CODE)E
else
ifeq ($(GAME_LANGUAGE),GERMAN)
  BUILD_NAME := $(BUILD_NAME)_de
  GAME_CODE  := $(GAME_CODE)D
else
  $(error unknown language $(GAME_LANGUAGE))
endif
endif

# Revision
ifeq ($(GAME_REVISION), 0)
  BUILD_NAME := $(BUILD_NAME)
else
  $(error unknown revision $(GAME_REVISION))
endif

# Debug
ifeq ($(DEBUG), 1)
  BUILD_NAME := $(BUILD_NAME)_debug
endif

# Modern GCC
ifeq ($(MODERN), 0)
  BUILD_NAME := $(BUILD_NAME)
else
  BUILD_NAME := $(BUILD_NAME)_modern
endif