include Makefile.in

DIRS=$(shell find -type d -name "d*")

.PHONY: all $(DIRS)

all: $(DIRS)

