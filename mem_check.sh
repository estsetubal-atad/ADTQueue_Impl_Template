#!/bin/sh

# Use only in Linux environment and if valgrind is installed and available

# All directives include debug symbols
# make debug
valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./prog
