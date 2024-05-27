# Project Settings
debug ?= 0
NAME := clox
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include
LIB_DIR := lib
TESTS_DIR := tests
BIN_DIR := bin

# Generate paths for all object files
OBJS := $(patsubst %.c,%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIB_DIR)/**/*.c))

TESTS_FILES := $(wildcard $(TESTS_DIR)/*.c)
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
EXCLUDED_PATTERN := src/clox.c

# Compiler settings
CC := clang-17
LINTER := clang-tidy-18
FORMATTER := clang-format-17

# Compiler and Linker flags Settings:
# 	-std=gnu17: Use the GNU17 standard
# 	-D _GNU_SOURCE: Use GNU extensions
# 	-D __STDC_WANT_LIB_EXT1__: Use C11 extensions
# 	-Wall: Enable all warnings
# 	-Wextra: Enable extra warnings
# 	-pedantic: Enable pedantic warnings
# 	-lm: Link to libm
CFLAGS := -std=gnu17 -D _GNU_SOURCE -D __STDC_WANT_LIB_EXT1__ -Wall -Wextra -pedantic
LDFLAGS := -lm

ifeq ($(debug), 1)
	CFLAGS := $(CFLAGS) -g -O0
else
	CFLAGS := $(CFLAGS) -Oz
endif

# Targets

# Build executable
$(NAME): dir $(OBJS)
	@echo "============================================"
	@echo "Build executable"
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_DIR)/$@ $(patsubst %, build/%, $(OBJS))

# Build object files and third-party libraries
$(OBJS): dir
	@echo "============================================"
	@echo "Build object files and third-party libraries"
	@mkdir -p $(BUILD_DIR)/$(@D)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ -c $*.c

# Run CUnit tests
test: dir
	@echo "Run CUnit tests"
	@$(CC) $(CFLAGS) -lcunit -o $(BIN_DIR)/$(NAME)_test $(TESTS_FILES) $(filter-out $(EXCLUDED_PATTERN), $(SOURCE_FILES))
	@$(BIN_DIR)/$(NAME)_test


# Run formatter on source directories
format:
	@$(FORMATTER) -style=file -i $(SRC_DIR)/* $(INCLUDE_DIR)/*

# Setup dependencies for build and development
setup:
	# Update apt and upgrade packages
	@sudo apt update

	# Install CUnit testing framework
	@sudo apt install -y libcunit1 libcunit1-doc libcunit1-dev

# Setup build and bin directories
dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Clean build and bin directories
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)


.PHONY: format dir clean setup bear