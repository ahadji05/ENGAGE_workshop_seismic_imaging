#!/bin/bash

#SBATCH --job-name=PPT
#SBATCH --exclusive
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=16
#SBATCH --partition=p100
#SBATCH --time=00:05:00
#SBATCH --error=job.%j.err
#SBATCH --output=job.%j.out
#SBATCH -A engage

export OMP_PLACES=cores
export OMP_PROC_BIND=close

start=$SECONDS
export OMP_NUM_THREADS=16
bash run_omp.sh
duration=$(( SECONDS - start ))

echo "Completed in $duration seconds."

