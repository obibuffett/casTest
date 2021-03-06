# The "Clean And Simple Test" (CAST) software framework, tools, and
# documentation are distributed under the terms of the MIT license a
# copy of which is included with this package (see the file "LICENSE"
# in the CAS poject tree's root directory).  CAST may be used for any
# purpose, including commercial purposes, at absolutely no cost. No
# paperwork, no royalties, no GNU-like "copyleft" restrictions, either.
# Just download it and use it.
# 
# Copyright (c) 2015 Randall Lee White

TGT := casTest

SRCS := \
    aboutCmd.cpp \
    addTestSuiteCmd.cpp \
    casStdLib.cpp \
    casTest.cpp \
    castCmd.cpp \
    castCmdExec.cpp \
    castUtil.cpp \
    cmdFactory.cpp \
    cmdLine.cpp \
    dynLibUtil.cpp \
    fileFactory.cpp \
    runTests.cpp \
    testLib.cpp \
    testSummary.cpp \
    tsMakefile.cpp \
    usage.cpp \
    usageCmd.cpp \
    verCmd.cpp \
    version.cpp

GENFILES := *.gcov

INCLUDES := -I.

UNAME_S := $(shell uname -s)

LIBS := -ldl
LFLAGS := -Wl,-R -Wl,.

ifeq ($(UNAME_S),Darwin)
    LFLAGS := -Wl,-L -Wl,.
endif

CFLAGS := -g -Wall
PFLAGS := -ftest-coverage -fprofile-arcs

##include $(CAST_DIR)/rules.make/makefile.exec##
include $(CAST_DIR)/rules.make/makefile.exec

