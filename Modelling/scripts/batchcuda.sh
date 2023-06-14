#!/bin/bash

#SBATCH --job-name=PPT
#SBATCH --exclusive
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=a100
#SBATCH --time=00:05:00
#SBATCH --error=job.%j.err
#SBATCH --output=job.%j.out
#SBATCH -A simea

start=$SECONDS
./main_exe
duration=$(( SECONDS - start ))
echo "Completed in $duration seconds."

