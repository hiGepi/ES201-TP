#!/bin/bash
set -e

GEM5="$HOME/gem5/build/RISCV/gem5.opt"
CFG="$HOME/ES201-TP/se_fu.py"
BASE="$HOME/ES201-TP/TP3/PageRank"

for N in min med max; do
  BIN="$BASE/pagerank_${N}.riscv"
  for M in 1 2 4 8; do
    OUT="m5out_${N}_M${M}"
    $GEM5 -d "$OUT" "$CFG" \
      --cmd="$BIN" \
      --cpu-type=O3 --caches \
      --ialu=$M --imult=$M --fpalu=$M --fpmult=$M --memport=2
  done
done
