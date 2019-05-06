# Description : University of Minho Imperative Programming 2017/2018 worksheet 1
#               exercise 4 Makefile.
#               Makefile do exercício 4 da ficha 1 de Programação Imperativa
#               2017/2018 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com

_CC             = gcc
_SRC_EXT        = .c
_EXE_EXT        = .elf
_WARN_FLAGS     = --std=c11 -pedantic -W -Wall
_OPTIMIZE_FLAGS = -O2 -march=native
_PROF_FLAGS 	= -pg
_DEBUG_FLAGS    = -g

_SRC_DIR    = .
_BIN_DIR    = ../../../bin/01/$(notdir $(shell pwd))
_PROF_DIR   = ../../../profile/01/$(notdir $(shell pwd))
_DEBUG_DIR  = ../../../debug/01/$(notdir $(shell pwd))

_EXE_HORI  = Triangle.Horizontal$(_EXE_EXT)
_EXE_VERT  = Triangle.Vertical$(_EXE_EXT)

_SRCS_HORI   = $(_SRC_DIR)/horizontal$(_SRC_EXT)
_SRCS_VERT   = $(_SRC_DIR)/vertical$(_SRC_EXT)
_SRCS_COMMON = $(_SRC_DIR)/main$(_SRC_EXT) $(_SRC_DIR)/fputcn$(_SRC_EXT)


all: build_horizontal build_vertical
build_horizontal: _mk_$(_BIN_DIR) $(_BIN_DIR)/$(_EXE_HORI)
build_vertical:   _mk_$(_BIN_DIR) $(_BIN_DIR)/$(_EXE_VERT)

profile_horizontal: _mk_$(_PROF_DIR) $(_PROF_DIR)/$(_EXE_HORI)
	$(call fn_profile,$(_EXE_HORI))
profile_vertical:   _mk_$(_PROF_DIR) $(_PROF_DIR)/$(_EXE_VERT)
	$(call fn_profile,$(_EXE_VERT))

debug: debug_horizontal debug_vertical
debug_horizontal: _mk_$(_DEBUG_DIR) $(_DEBUG_DIR)/$(_EXE_HORI)
debug_vertical:   _mk_$(_DEBUG_DIR) $(_DEBUG_DIR)/$(_EXE_VERT)

memcheck_horizontal: debug_horizontal
	$(call fn_memcheck,$(_EXE_HORI))
memcheck_vertical:   debug_vertical
	$(call fn_memcheck,$(_EXE_VERT))

clean:
	rm -rf $(_BIN_DIR) $(_PROF_DIR) $(_DEBUG_DIR) gmon*



define fn_memcheck
	valgrind --tool=memcheck --leak-check=yes ./$(_DEBUG_DIR)/$(1)
endef

define fn_profile
	./$(_PROF_DIR)/$(1)
	gprof ./$(_PROF_DIR)/$(1)
endef

define fn_srcs_to_objs
	$(patsubst $(_SRC_DIR)/%$(_SRC_EXT), $(1)/%.o, $(2))
endef


_mk_$(_BIN_DIR):
	@mkdir -p $(_BIN_DIR)

_mk_$(_PROF_DIR):
	@mkdir -p $(_PROF_DIR)

_mk_$(_DEBUG_DIR):
	@mkdir -p $(_DEBUG_DIR)


_BIN_OBJS_HORI    = $(call fn_srcs_to_objs,$(_BIN_DIR),$(_SRCS_HORI))
_BIN_OBJS_VERT    = $(call fn_srcs_to_objs,$(_BIN_DIR),$(_SRCS_VERT))
_BIN_OBJS_COMMON  = $(call fn_srcs_to_objs,$(_BIN_DIR),$(_SRCS_COMMON))

_DEBUG_OBJS_HORI   = $(call fn_srcs_to_objs,$(_DEBUG_DIR),$(_SRCS_HORI))
_DEBUG_OBJS_VERT   = $(call fn_srcs_to_objs,$(_DEBUG_DIR),$(_SRCS_VERT))
_DEBUG_OBJS_COMMON = $(call fn_srcs_to_objs,$(_DEBUG_DIR),$(_SRCS_COMMON))

_PROF_OBJS_HORI   = $(call fn_srcs_to_objs,$(_PROF_DIR),$(_SRCS_HORI))
_PROF_OBJS_VERT   = $(call fn_srcs_to_objs,$(_PROF_DIR),$(_SRCS_VERT))
_PROF_OBJS_COMMON = $(call fn_srcs_to_objs,$(_PROF_DIR),$(_SRCS_COMMON))


$(_BIN_DIR)/$(_EXE_HORI): $(_BIN_OBJS_HORI) $(_BIN_OBJS_COMMON)
	$(_CC) $^ -o $@

$(_BIN_DIR)/$(_EXE_VERT): $(_BIN_OBJS_VERT) $(_BIN_OBJS_COMMON)
	$(_CC) $^ -o $@

$(_BIN_OBJS_HORI): $(_BIN_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@

$(_BIN_OBJS_VERT): $(_BIN_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@

$(_BIN_OBJS_COMMON): $(_BIN_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@


$(_PROF_DIR)/$(_EXE_HORI): $(_PROF_OBJS_HORI) $(_PROF_OBJS_COMMON)
	$(_CC) $^ $(_PROF_FLAGS) -o $@

$(_PROF_DIR)/$(_EXE_VERT): $(_PROF_OBJS_VERT) $(_PROF_OBJS_COMMON)
	$(_CC) $^ $(_PROF_FLAGS) -o $@

$(_PROF_OBJS_HORI): $(_PROF_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_PROF_FLAGS) $< -o $@

$(_PROF_OBJS_VERT): $(_PROF_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_PROF_FLAGS) $< -o $@

$(_PROF_OBJS_COMMON): $(_PROF_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_PROF_FLAGS) $< -o $@


$(_DEBUG_DIR)/$(_EXE_HORI): $(_DEBUG_OBJS_HORI) $(_DEBUG_OBJS_COMMON)
	$(_CC) $^ -o $@

$(_DEBUG_DIR)/$(_EXE_VERT): $(_DEBUG_OBJS_VERT) $(_DEBUG_OBJS_COMMON)
	$(_CC) $^ -o $@

$(_DEBUG_OBJS_HORI): $(_DEBUG_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_DEBUG_FLAGS) $< -o $@

$(_DEBUG_OBJS_VERT): $(_DEBUG_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_DEBUG_FLAGS) $< -o $@

$(_DEBUG_OBJS_COMMON): $(_DEBUG_DIR)/%.o : $(_SRC_DIR)/%$(_SRC_EXT)
	@mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_DEBUG_FLAGS) $< -o $@
