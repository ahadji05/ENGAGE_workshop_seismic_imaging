#!/bin/bash

#SBATCH --job-name=PPT
#SBATCH --exclusive
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=20
#SBATCH --partition=a100
#SBATCH --time=00:05:00
#SBATCH --error=job.%j.err
#SBATCH --output=job.%j.out
#SBATCH -A simea

nthreads="1 2 4 8 16 20"
export OMP_PLACES=cores
export OMP_PROC_BIND=close

for nth in $nthreads
do
echo "OMP_THREADS($nth)"
start=$SECONDS
OMP_NUM_THREADS=$nth ./main_exe
duration=$(( SECONDS - start ))
echo "Completed in $duration seconds."
done

