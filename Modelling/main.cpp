
#include "ppt/algorithms/WaveSimulator.hpp"
#include <iostream>

// SELECT EXECUTION-SPACE BASED ON COMPILE-TIME CHOICE
#if defined(PPT_ENABLE_CUDA_BACKEND)
using exec_space = ppt::ExecutionSpaceCuda;
#elif defined(PPT_ENABLE_HIP_BACKEND)
using exec_space = ppt::ExecutionSpaceHip;
#elif defined(PPT_ENABLE_OPENMP_BACKEND)
using exec_space = ppt::ExecutionSpaceOpenMP;
#else
using exec_space = ppt::ExecutionSpaceSerial;
#endif

int main()
{
    // Define the WaveSimulator based on the exec_space
    WaveSimulator<exec_space> Sim;

    // Set modelling parameters
    Sim.set_time_step(0.001);
    Sim.set_number_of_time_steps(1001);
    Sim.set_dimensions(501, 2001);
    Sim.set_space_step(5.0);
    Sim.set_source_position_z(2);
    Sim.set_source_position_x(1000);
    Sim.make_ricker(10);

    // Set the background velocity and add layers of different velocities
    Sim.set_vmin(1500);
    // Sim.set_velocity_layer(50, 75, 3000);
    // Sim.set_velocity_layer(75, 100, 2000);
    // Sim.set_velocity_layer(100, 501, 3000);

    // Compute and print the Courant-Friedricks-Lewy stability condition
    Sim.print_CFL_condition();

    // run simulation for all time-steps
    Sim.run();

    // Output velocity model and final wavefield in plain binary files
    Sim.store_velmodel("velocity_model.npy");
    Sim.store_wavefield("wavefield.npy");
    Sim.store_recorded_data("seish.npy");

    return 0;
}