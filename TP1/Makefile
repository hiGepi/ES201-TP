############################
# Toolchain
############################
CC      = riscv64-linux-gnu-gcc
CFLAGS  = -O2 -static -fno-lto -std=c99
LDFLAGS = -lm

############################
# gem5 paths (À ADAPTER)
############################
GEM5_PATH = $(HOME)/gem5
M5_INC    = $(GEM5_PATH)/include
M5_LIB    = $(GEM5_PATH)/util/m5/build/riscv/out/libm5.a

############################
# Targets
############################
BIN = \
	vadd.riscv \
	vadd_m5.riscv

all: $(BIN)

############################
# Sans m5
############################
vadd.riscv: vadd.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

############################
# Avec m5
############################
vadd_m5.riscv: vadd_m5.c
	$(CC) $(CFLAGS) -I$(M5_INC) $< $(M5_LIB) -o $@ $(LDFLAGS)

############################
# Nettoyage
############################
clean:
	rm -f *.riscv
