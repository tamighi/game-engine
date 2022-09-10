CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17 
DEPFLAGS = -MMD

ENGINE_NAME = Engine.a
SANDBOX_NAME = Sandbox.a
GLFW_NAME = GLFW.a
EXEC_NAME = exec

ENGINE_DIR = Engine/
SANDBOX_DIR = Sandbox/
GLFW_DIR = GLFW/

ifeq ($(OS),Windows_NT)
    detected_OS = Windows
else
    detected_OS = $(shell sh -c 'uname -s 2>/dev/null || echo Unknown')
endif

ifeq ($(OS),Windows_NT)
    ARCH = Windows
else
    ARCH = $(shell sh -c 'uname -m 2>/dev/null || echo Unknown')
endif

BASEOBJDIR = bin-int/
BASEBINDIR = bin/Debug-$(detected_OS)-$(ARCH)/
