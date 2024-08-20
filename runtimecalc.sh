#!/bin/bash
## THIS PROGRAM CAN BE USED FOR TAKING AVERAGE TIME THAT A PROGRAM RUNS, APPLICABLE ONLY FOR C, ALSO IT IS MANDATORY THAT YOU INCLUDE AND CHANGE THE PROGRAM SO THAT IT GIVES IS ITS RUN TIME IN Us

##Usage -> takes in two args first one -> the outfile name without .o and the second -> sample size


total_time=0
for(( i = 0; i < $2; i++ ))
do
	indvidual_run_time=$(./$1.o)
	total_time=$(($total_time+$indvidual_run_time))
done

echo "$(($total_time/$2)) us"
