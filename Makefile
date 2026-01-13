# This is a temporary makefile

BUILD=./build
SRC=./src
EXAMPLE=./example
GENERAL_FLAGS=-Wall -Werror -g
SHARED_FLAGS=-shared -fPIC 
EXAMPLE_FLAGS=-L$(BUILD)/sobj -Wl,-rpath=$(BUILD)/sobj/

.PHONY: all clean setup w_example


all: setup libw_nfGA.so libx_nfGA.so w_example.o x_example.o


setup: 
	mkdir -p $(BUILD)/{obj,sobj}

clean:
	rm -r $(BUILD)

libw_nfGA.so: $(SRC)/main.c $(SRC)/nfGGI_impl/wayland_nfGGI.c $(SRC)/nfBRR.c
	cc $(GENERAL_FLAGS) $(SHARED_FLAGS) \
		-lwayland-client \
		$(SRC)/main.c $(SRC)/nfGGI_impl/wayland_nfGGI.c $(SRC)/nfBRR.c\
		-o $(BUILD)/sobj/libw_nfGA.so

libx_nfGA.so: $(SRC)/main.c $(SRC)/nfGGI_impl/wayland_nfGGI.c $(SRC)/nfBRR.c
	cc $(GENERAL_FLAGS) $(SHARED_FLAGS) \
		$(SRC)/main.c $(SRC)/nfGGI_impl/xorg_nfGGI.c $(SRC)/nfBRR.c\
		-o $(BUILD)/sobj/libx_nfGA.so

w_example.o: $(SRC)/main.c $(SRC)/nfGGI_impl/wayland_nfGGI.c
	cc $(GENERAL_FLAGS) $(EXAMPLE_FLAGS) \
		-lw_nfGA \
		$(EXAMPLE)/main.c \
		-o $(BUILD)/obj/w_example.o

x_example.o: $(SRC)/main.c $(SRC)/nfGGI_impl/xorg_nfGGI.c
	cc $(GENERAL_FLAGS) $(EXAMPLE_FLAGS) \
		-lx_nfGA \
		$(EXAMPLE)/main.c \
		-o $(BUILD)/obj/x_example.o

