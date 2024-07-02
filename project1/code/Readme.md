This file will guide you in creating an executable program and running it to obtain results
# Performance Measurement

## content 
```
D:.
│  
├─code
│      plot.py  # used for drawing
│      README.md
│      search.c # test performance of each function
│      
└─documents
        readme.md
        report.pdf #report
```
## Compile and Run


To turn this program,you need a C compiler installed on your computer.If you don't have one,you can install a compiler like GCC or use an online compiler.

This code has been run successfully on Windows and Linux on three computers.If you really have some problems,you could also to ask help from your classmates.

To compile and run,you shoule open a terminal and naviget to the correct dictory:

<center><b> Make Sure you are in the correct dictory!</b></center>

### For Linux Users
```
cd ./code/
gcc search.c -o search
./search
```
### For Windows Users
```
cd .\code\
gcc search.c -o search
.\search.exe
```

## Inputs and Output
You can input the N when run the program.

The results might have some difference between reports,for the constant `CLK_TCK` have diffirent values on different environment.(the data in the report is from windows).And for some versions of `time.h`libary, `CLOCK_PER_SEC`replaced `CLK_TCK`in the libary,so you might have some compile errors.Just replace it in the output.




