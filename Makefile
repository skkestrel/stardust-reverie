WFLAGS = -Wcast-align \
-Wcast-qual -Wconversion \
-Wdisabled-optimization \
-Wfloat-equal -Wformat=2 \
-Wformat-nonliteral -Wformat-security  \
-Wformat-y2k \
-Wimport  -Winit-self \
-Winvalid-pch   \
-Wmissing-field-initializers -Wmissing-format-attribute   \
-Wmissing-include-dirs -Wmissing-noreturn \
-Wpointer-arith \
-Wstack-protector \
-Wstrict-aliasing=2 -Wswitch-default \
-Wswitch-enum \
-Wunreachable-code -Wunused \
-Wunused-parameter \
-Wvariadic-macros \
-Wwrite-strings

default:
		nvcc *.cpp *.cu -lineinfo -g -maxrregcount 64 -arch=sm_35 --std=c++11 --compiler-options "-Wall -Wextra -Wconversion ${WFLAGS}" -O3
