#!/bin/sh
echo `date` > time

#./condensed_edge -K 31 -1 /home/xuqing/data/SRR_1_filter.fastq -2 /home/xuqing/data/SRR_2_filter.fastq

#glpsol --mincost min_cost_flow.DIMACS -o min_out.txt

#./copy_num.py

#./sim_real.py

#./linearization -K 31 -e 50 -c cdbg_cp_num.txt -1 /home/xuqing/data/SRR_1_filter.fastq -2 /home/xuqing/data/SRR_2_filter.fastq -B 1000 -p 15 

dir="/home/xuqing/TopDown"
training="UniqEdgeForTraining.fa"
file="multi_gap_seq_to_PerM.fa"

#./Gap_Filling -K 31 -O 21

echo "map uniqEdgeForTraining" >> time
echo `date` >> time

./perm10K ${dir}/${training} -v 10 -a  -1 /home/xuqing/data/SRR_1_filter.fq -2 /home/xuqing/data/SRR_2_filter.fq -s ${dir}/${training}.index --outputFormat sam -o ${training}.sam
#./perm10K ${training} -1 /home/xuqing/data/SRR_1_filter.fq -2 /home/xuqing/data/SRR_2_filter.fq -s -o ${training}.sam


echo "map UniqEdgeForTraining end" >> time
echo `date` >> time

echo "map multi_gap_seq_to_PerM" >> time
echo `date` >> time

#./perm10K ${file} -v 10 -a -1 /home/xuqing/data/SRR_1_filter.fq -2 /home/xuqing/data/SRR_2_filter.fq -s ${file}.index -o ${file}.sam

echo "map multi_gap_seq_to_PerM end" >> time
echo `date` >> time


echo "score" >> time
echo `date` >> time
#./Gap_Filling -K 25 -O 15
#./score 
echo "score end" >> time
echo `date` >> time
