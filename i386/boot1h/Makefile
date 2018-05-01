#
# File: RevoBoot/i386/boot2/Makefile
#
# Updates:
#
#		- Support for self compiled libcc_kext.a added (PikerAlpha, October 2012).
#		- Major cleanup (PikerAlpha, October 2012).
#		- Fixed clang compilation (dgsga, November 2012. Credits to Evan Lojewski for original work).
#		- BOOT2ADDR moved to RevoBoot/i386/util/segsize.c (PikerAlpha, November 2012).
#		- Simplified calls to RevoBoot/i386/util/segsize (PikerAlpha, November 2012).
#		- Reformatted output, include directory dependency lifted (PikerAlpha, November 2012).
#		- BOOT2ADDR removed, static compilation and some white space changes (PikerAlpha, November 2012).
#


include ../MakePaths.dir

VPATH = $(OBJROOT):$(SYMROOT)

#
# The order of object filenames below is important;
#
OBJS =

DIRS_NEEDED = $(OBJROOT) $(SYMROOT)

$(MAKEGOAL): $(DIRS_NEEDED) boot1h

boot1h:	$(OBJS)

include ../MakeInc.dir
