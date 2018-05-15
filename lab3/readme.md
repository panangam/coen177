# COEN 177 Lab 2

*Oras Phongpanangam*

Compare performance of disk reading between reading sequentially and jumping all over the file.

## Files

- `seqread.c`: Program for reading sequentially.
- `randread.c`: Program for reading randomly (jumping all over the file). Also check for the file size and read roughly the same amount of data as `seqread`.
- `makefile`: For compiling.

## Usage

After compiling the programs into executables, run the executable and pass the directory+name of the file to read as a command line argument.

Ex: `./seqread /local/weka/random5G`

## Report

|    |seqread|randread|
|----|-------|--------|
|1G  |0m0.511s, 0m0.510s, 0m0.518s|0m21.190s, 0m20.658s, 0m20.846s|
|2.5G|0m1.154s, 0m1.127s, 0m1.146s|0m51.461s, 0m50.914s, 0m51.302s|
|5G  |0m2.189s, 0m2.190s, 0m2.148s|1m45.802s, 1m44.996s, 1m45.781s|

## Analysis

Within the same method of reading (sequential and random), the time it takes to read the file 
