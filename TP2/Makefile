############################
# Toolchain
############################
CC      = riscv64-linux-gnu-gcc
CFLAGS  = -O2 -static -fno-lto -std=c99
LDFLAGS = -lm

############################
# gem5 paths (À ADAPTER si besoin)
############################
GEM5_PATH = $(HOME)/gem5
M5_INC    = $(GEM5_PATH)/include
M5_LIB    = $(GEM5_PATH)/util/m5/build/riscv/out/libm5.a

############################
# Targets
############################
BIN = \
	conv_int.riscv \
	conv_float.riscv \
	conv_unrolled.riscv \
	conv_m5.riscv \
	conv_float_m5.riscv \
	conv_unrolled_m5.riscv

all: $(BIN)

############################
# Sans m5 (versions normales)
############################
conv_int.riscv: conv_int.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

conv_float.riscv: conv_float.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

conv_unrolled.riscv: conv_unrolled.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

############################
# Avec m5 (instrumentées)
############################
conv_m5.riscv: conv_m5.c
	$(CC) $(CFLAGS) -I$(M5_INC) $< $(M5_LIB) -o $@ $(LDFLAGS)

conv_float_m5.riscv: conv_float_m5.c
	$(CC) $(CFLAGS) -I$(M5_INC) $< $(M5_LIB) -o $@ $(LDFLAGS)

conv_unrolled_m5.riscv: conv_unrolled_m5.c
	$(CC) $(CFLAGS) -I$(M5_INC) $< $(M5_LIB) -o $@ $(LDFLAGS)

############################
# Nettoyage
############################
clean:
	rm -f *.riscv
