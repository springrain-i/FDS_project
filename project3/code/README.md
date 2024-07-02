This file will guide you in creating an executable program and running it to obtain results
# Dijkstra Sequence

## Content
```
D:.
│  
├─code
│  │  Dijkstra_Sequence.c
│  │  README.md
│  │
│  └─data
│          data1.in
│          data2.in
│          data3.in
│          data4.in
│          data5.in
│          data6.in
│          data7.in
│          data8.in
│
└─document
        readme.md
        report.pdf
```
## Compile and Run
To run this program,you need a C compiler installed on your computer.If you don't have one,you can install a compiler like GCC or use an online compiler.

To compile and run,you shoule open a terminal and naviget to the correct dictory:

<center><b> Make Sure you are in the correct dictory!</b></center>
<center><b> The Number is the testcase in data</b></center>

**Example**:
In Wondows
```c
cd ./code/
gcc Dijkstra_Sequence.c -o Dijkstra_Sequence
./Dijkstra_Sequence.exe -w -8
```
Then you can see the data8.out in the data folder which is the output.
### For Linux Users
If you are using Linux, you can use the following commands to compile and run the program.
```
cd ./code/
gcc Dijkstra_Sequence.c -o Dijkstra_Sequence
./Dijkstra_Sequence -l -(NUMBER)
```
### For Windows Users
If you are using Windows, you can use the following commands to compile and run the program.
```
cd .\code\
gcc Dijkstra_Sequence.c -o Dijkstra_Sequence
.\Dijkstra_Sequence -w -(NUMBER)
```

## Inputs and Output
You can input the testcase according to the requirements of the question.

And I have provided some testcases in the Data folder, you can use them to test the program.

You can replace the input files by naming `x.in` in `.\data `
But it can't be more than 10
> Tips
> Some testcases may be too large to be copied,so you need to be patient to wait the input.And the output may be also very slow and large,so would you mind waiting a little longer.