
#set path to Libraries installation
MKLROOT=/opt/intel/oneapi/mkl/latest

# NO NEED TO EDIT BELOW THIS LINE
#################################

# path(s) to include directorie(s)
# --------------------------------
INC = ./include/
INC_MKL=$(MKLROOT)/include/

# path(s) to librarie(s)
# ----------------------
MKLLIB=-Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_ilp64.a \
${MKLROOT}/lib/intel64/libmkl_gnu_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a \
-Wl,--end-group -lgomp -lpthread -lm -ldl

# set compilers and flag(s)
# -------------------------
CXX = g++
CXXFLAGS = -Wall -O3 --fast-math -std=c++14 -fPIC -fopenmp

SRC = ./kernels/cpu/

2dPWM_mkl: interpolation.o prep_operators.o phase_shifts.o imaging_conditions.o mkl_fft.o
	$(CXX) -shared $(CXXFLAGS) *.o PWM_cpu.cpp -o PWM_cpu.so -I$(INC) -I$(INC_MKL) $(MKLLIB)

mkl_fft.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)mkl_fft.cpp -I$(INC) -I$(INC_MKL)

imaging_conditions.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)imaging_conditions.cpp -I$(INC)

interpolation.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)interpolation.cpp -I$(INC)

prep_operators.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)prep_operators.cpp -I$(INC)

phase_shifts.o:
	$(CXX) $(CXXFLAGS) -c $(SRC)phase_shifts.cpp -I$(INC)

remake: clean all

clean:
	rm *.o PWM_cpu.so