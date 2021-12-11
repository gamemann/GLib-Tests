# We want to use Clang to build this project.
CC = clang

# We'll be using `pkg-config` to obtain the GLib include paths along with linker libraries.
PKG_CONFIG := pkg-config

# Specify build and source directories.
BUILD_DIR := build
SRC_DIR := src

# GLib structures project source and out files.
GLIB_STRUCTS_SRC := glib_structs.c
GLIB_STRUCTS_OUT := glib_structs

# Global flags.
GLOBAL_FLAGS := -O2

# GLib flags/linkers.
GLIB_FLAGS := $(shell $(PKG_CONFIG) --cflags --libs glib-2.0)

# All chain contains all projects we need.
all: mk_build_dir projects

# Chain that creates the build directory if it doesn't already exist.
mk_build_dir:
	mkdir -p $(BUILD_DIR)

# Builds all projects.
projects:
	$(CC) $(GLOBAL_FLAGS) $(GLIB_FLAGS) -o $(BUILD_DIR)/$(GLIB_STRUCTS_OUT) $(SRC_DIR)/$(GLIB_STRUCTS_SRC)

# Cleans the build directory.
clean:
	rm -f $(BUILD_DIR)/*

# Default should be the all chain.
.DEFAULT: all


