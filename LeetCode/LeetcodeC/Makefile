
# Multi-purpose Makefile for LeetCode Easy (C99)
# Usage examples:
#   make help
#   make list
#   make build PROBLEM=two_sum            # builds src/solutions/two_sum.c -> bin/two_sum
#   make run   PROBLEM=two_sum ARGS="..." # runs bin/two_sum with optional ARGS
#   make run-file FILE=path/to/foo.c      # compile & run a single C file from anywhere
#   make build-all MODE=asan              # build all solutions with Address/UBSan
#   make clean

# ========================= Configuration =========================
CC       ?= gcc
STD     := c99
WARN    := -Wall -Wextra -Wconversion -Wshadow -Wpointer-arith
OPT     := -O2
DBG     := -g

SRC_DIR := src/solutions
INC_DIR ?= .        # directory containing lc_utils.h (default: current dir)
BIN_DIR := bin

# Build modes: release | debug | asan
MODE ?= release

ifeq ($(MODE),release)
  CFLAGS := -std=$(STD) $(WARN) $(OPT)
  LDFLAGS := -lm
endif
ifeq ($(MODE),debug)
  CFLAGS := -std=$(STD) $(WARN) $(DBG)
  LDFLAGS := -lm
endif
ifeq ($(MODE),asan)
  CFLAGS := -std=$(STD) $(WARN) $(DBG) -fsanitize=address,undefined -fno-omit-frame-pointer
  LDFLAGS := -lm -fsanitize=address,undefined
endif

# ========================= Discovery =========================
SOURCES := $(wildcard $(SRC_DIR)/*.c)
TARGETS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SOURCES))

# ========================= Phony targets =========================
.PHONY: help list build run run-file build-all clean dirs

help:
	@echo "\nLeetCode Easy (C99) Makefile — commands:\n"
	@echo "  make list                      # list available problems (from $(SRC_DIR))"
	@echo "  make build PROBLEM=<name>      # build $(SRC_DIR)/<name>.c -> $(BIN_DIR)/<name>"
	@echo "  make run   PROBLEM=<name> ARGS=\"...\" # run built binary with optional ARGS"
	@echo "  make run-file FILE=path/to/foo.c       # build & run a single .c file"
	@echo "  make build-all [MODE=release|debug|asan] # build all problems"
	@echo "  make clean                     # remove bin/"
	@echo "\nVariables: CC=$(CC), MODE=$(MODE), INC_DIR=$(INC_DIR)"
	@echo "CFLAGS=$(CFLAGS)"
	@echo "LDFLAGS=$(LDFLAGS)\n"

list:
	@echo "Available C sources in $(SRC_DIR):"
	@for f in $(SOURCES); do echo "  - $$(basename $$f)"; done || echo "  (none found)"

# Ensure output directory exists
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Pattern rule: src/solutions/foo.c -> bin/foo
$(BIN_DIR)/%: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) $< -o $@ $(LDFLAGS)

# Build specific problem: make build PROBLEM=name
build: dirs
	@if [ -z "$(PROBLEM)" ]; then \
		echo "[ERROR] Please specify PROBLEM=<name> (expects $(SRC_DIR)/<name>.c)"; exit 1; \
	fi
	$(MAKE) $(BIN_DIR)/$(PROBLEM)

# Run specific problem: make run PROBLEM=name ARGS="..."
run: build
	@echo "[RUN] $(BIN_DIR)/$(PROBLEM) $(ARGS)"
	@$(BIN_DIR)/$(PROBLEM) $(ARGS)

# Build & run an arbitrary C file: make run-file FILE=path/to/foo.c
# Output binary name: bin/<basename(FILE)>
run-file: dirs
	@if [ -z "$(FILE)" ]; then \
		echo "[ERROR] Please specify FILE=<path/to/file.c>"; exit 1; \
	fi
	@base=$$(basename $(FILE)); name=$${base%.c}; \
	 echo "[BUILD] $$name from $(FILE)"; \
	 $(CC) $(CFLAGS) -I$(INC_DIR) $(FILE) -o $(BIN_DIR)/$$name $(LDFLAGS); \
	 echo "[RUN] $(BIN_DIR)/$$name $(ARGS)"; \
	 $(BIN_DIR)/$$name $(ARGS)

# Build all problems in src/solutions/
build-all: dirs $(TARGETS)
	@echo "Built: $(TARGETS)"

# Helper to ensure directories exist
dirs: $(BIN_DIR)

clean:
	@rm -rf $(BIN_DIR)
	@echo "Cleaned $(BIN_DIR)/"
