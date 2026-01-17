#!/bin/bash

OUTFILE=results.txt

printf "%-20s %-15s %-15s\n" "RUN" "numCycles" "CPI" > "$OUTFILE"

for d in m5out_*; do
  [ -f "$d/stats.txt" ] || continue

  CYCLES=$(grep -m1 "system.cpu.numCycles" "$d/stats.txt" | awk '{print $2}')
  CPI=$(grep -m1 "system.cpu.cpi" "$d/stats.txt" | awk '{print $2}')

  printf "%-20s %-15s %-15s\n" "$d" "${CYCLES:-NA}" "${CPI:-NA}" >> "$OUTFILE"
done
