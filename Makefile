#
# Module:   Makefile
# Purpose:  to build htangle
# Author:   Steve Gibson
# Date:     4/26/99
#
# RCS:
# $Log$
#
CC=gcc
INCLUDE=.
DEBUG_FLAGS=-g
CFLAGS=-I$(INCLUDE) $(DEBUG_FLAGS)
#
THIS_MAKEFILE=Makefile
SUFFIX=
RM=rm -f
#
#----------------------------------------------------------------------
htangle:  htangle.c
	$(CC) $(CFLAGS) -o htangle htangle.c
#	
#----------------------------------------------------------------------
clean::
	rm htangle
#	
#----------------------------------------------------------------------
install::
	cp htangle /usr/local/bin
	chmod 755 /usr/local/bin/htangle
#----------------------------------------------------------------------
tar::
	tar cvzf htangle.tar.gz Makefile README* *.lsm *.c *.h
#----------------------------------------------------------------------

