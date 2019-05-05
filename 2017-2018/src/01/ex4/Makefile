# Description : University of Minho Imperative Programming 2017/2018 worksheet 1
#               exercise 4 Makefile.
#               Makefile do exercício 4 da ficha 1 de Programação Imperativa
#               2017/2018 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com

.CC             = gcc
.SRC_EXT        = .c
.EXE_EXT        = .elf
.WARN_FLAGS     = --std=c11 -pedantic -W -Wall
.OPTIMIZE_FLAGS = -O2 -march=native
.PROF_FLAGS 	= -pg
.DEBUG_FLAGS    = -g

.SRC_DIR    = .
.BIN_DIR    = ../../../bin/01/$(notdir $(shell pwd))
.PROF_DIR   = ../../../profile/01/$(notdir $(shell pwd))
.DEBUG_DIR  = ../../../debug/01/$(notdir $(shell pwd))

.EXE_HORI  = Triangle.Horizontal$(.EXE_EXT)
.EXE_VERT  = Triangle.Vertical$(.EXE_EXT)

.SRCS_HORI   = $(.SRC_DIR)/horizontal$(.SRC_EXT)
.SRCS_VERT   = $(.SRC_DIR)/vertical$(.SRC_EXT)
.SRCS_COMMON = $(.SRC_DIR)/main$(.SRC_EXT) $(.SRC_DIR)/fputcn$(.SRC_EXT)


all: just_horizontal just_vertical
just_horizontal: mk_$(.BIN_DIR) $(.BIN_DIR)/$(.EXE_HORI)
just_vertical:   mk_$(.BIN_DIR) $(.BIN_DIR)/$(.EXE_VERT)

profile_horizontal: mk_$(.PROF_DIR) $(.PROF_DIR)/$(.EXE_HORI)
	$(call fn_profile,$(.EXE_HORI))
profile_vertical:   mk_$(.PROF_DIR) $(.PROF_DIR)/$(.EXE_VERT)
	$(call fn_profile,$(.EXE_VERT))

debug: debug_horizontal debug_vertical
debug_horizontal: mk_$(.DEBUG_DIR) $(.DEBUG_DIR)/$(.EXE_HORI)
debug_vertical:   mk_$(.DEBUG_DIR) $(.DEBUG_DIR)/$(.EXE_VERT)

memcheck_horizontal: debug_horizontal
	$(call fn_memcheck,$(.EXE_HORI))
memcheck_vertical:   debug_vertical
	$(call fn_memcheck,$(.EXE_VERT))

clean:
	rm -rf $(.BIN_DIR) $(.PROF_DIR) $(.DEBUG_DIR) gmon*



define fn_memcheck
	valgrind --tool=memcheck --leak-check=yes ./$(.DEBUG_DIR)/$(1)
endef

define fn_profile
	./$(.PROF_DIR)/$(1)
	gprof ./$(.PROF_DIR)/$(1)
endef

define fn_srcs_to_objs
	$(patsubst $(.SRC_DIR)/%$(.SRC_EXT), $(1)/%.o, $(2))
endef


mk_$(.BIN_DIR):
	@mkdir -p $(.BIN_DIR)

mk_$(.PROF_DIR):
	@mkdir -p $(.PROF_DIR)

mk_$(.DEBUG_DIR):
	@mkdir -p $(.DEBUG_DIR)


.BIN_OBJS_HORI    = $(call fn_srcs_to_objs,$(.BIN_DIR),$(.SRCS_HORI))
.BIN_OBJS_VERT    = $(call fn_srcs_to_objs,$(.BIN_DIR),$(.SRCS_VERT))
.BIN_OBJS_COMMON  = $(call fn_srcs_to_objs,$(.BIN_DIR),$(.SRCS_COMMON))

.DEBUG_OBJS_HORI   = $(call fn_srcs_to_objs,$(.DEBUG_DIR),$(.SRCS_HORI))
.DEBUG_OBJS_VERT   = $(call fn_srcs_to_objs,$(.DEBUG_DIR),$(.SRCS_VERT))
.DEBUG_OBJS_COMMON = $(call fn_srcs_to_objs,$(.DEBUG_DIR),$(.SRCS_COMMON))

.PROF_OBJS_HORI   = $(call fn_srcs_to_objs,$(.PROF_DIR),$(.SRCS_HORI))
.PROF_OBJS_VERT   = $(call fn_srcs_to_objs,$(.PROF_DIR),$(.SRCS_VERT))
.PROF_OBJS_COMMON = $(call fn_srcs_to_objs,$(.PROF_DIR),$(.SRCS_COMMON))


$(.BIN_DIR)/$(.EXE_HORI): $(.BIN_OBJS_HORI) $(.BIN_OBJS_COMMON)
	$(.CC) $^ -o $@

$(.BIN_DIR)/$(.EXE_VERT): $(.BIN_OBJS_VERT) $(.BIN_OBJS_COMMON)
	$(.CC) $^ -o $@

$(.BIN_OBJS_HORI): $(.BIN_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.OPTIMIZE_FLAGS) $< -o $@

$(.BIN_OBJS_VERT): $(.BIN_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.OPTIMIZE_FLAGS) $< -o $@

$(.BIN_OBJS_COMMON): $(.BIN_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.OPTIMIZE_FLAGS) $< -o $@


$(.PROF_DIR)/$(.EXE_HORI): $(.PROF_OBJS_HORI) $(.PROF_OBJS_COMMON)
	$(.CC) $^ $(.PROF_FLAGS) -o $@

$(.PROF_DIR)/$(.EXE_VERT): $(.PROF_OBJS_VERT) $(.PROF_OBJS_COMMON)
	$(.CC) $^ $(.PROF_FLAGS) -o $@

$(.PROF_OBJS_HORI): $(.PROF_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.PROF_FLAGS) $< -o $@

$(.PROF_OBJS_VERT): $(.PROF_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.PROF_FLAGS) $< -o $@

$(.PROF_OBJS_COMMON): $(.PROF_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.PROF_FLAGS) $< -o $@


$(.DEBUG_DIR)/$(.EXE_HORI): $(.DEBUG_OBJS_HORI) $(.DEBUG_OBJS_COMMON)
	$(.CC) $^ -o $@

$(.DEBUG_DIR)/$(.EXE_VERT): $(.DEBUG_OBJS_VERT) $(.DEBUG_OBJS_COMMON)
	$(.CC) $^ -o $@

$(.DEBUG_OBJS_HORI): $(.DEBUG_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.DEBUG_FLAGS) $< -o $@

$(.DEBUG_OBJS_VERT): $(.DEBUG_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.DEBUG_FLAGS) $< -o $@

$(.DEBUG_OBJS_COMMON): $(.DEBUG_DIR)/%.o : $(.SRC_DIR)/%$(.SRC_EXT)
	@mkdir -p $(dir $@)
	$(.CC) -c $(.WARN_FLAGS) $(.DEBUG_FLAGS) $< -o $@
