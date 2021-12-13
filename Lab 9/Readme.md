## Lab 9 Submissions

The codes of my course Parallel and Distributed Computing using MPI for the various communication protocols


## Description

- **Code 1 -** To gain an understanding about the working of the receive and send communication methods in mpi using master and slave
- **Code 2 -** Implement a MPI program to use the MPI_Scatter
- **Code 3 -** Implement a MPI program to generate random numbers by each worker node and store it into a global array variable and gather them using MPI_Gather and then print it. 


## Run Locally

Clone the project

```bash
  git clone https://github.com/ayan2809/Parallel-and-Distributed-Computing
```

Go to the project directory

```bash
  cd Parallel-and-Distributed-Computing
  cd Lab 9
```

Run Commands

```bash
  mpicc code1.c 
```


```bash
  mpirun -np 6 a.out 
```

  
## Tech Stack

**IDE:** VS Code

**Language:** C and Openmp library

  
## Code Outputs

### Code 1
![image](https://user-images.githubusercontent.com/42286904/145857009-58ddb5d5-e617-4012-9852-05dce01f0cce.png)


### Code 2
![image](https://user-images.githubusercontent.com/42286904/145857084-706efffe-6285-4b6c-bfd3-72fd8e9ccf82.png)

### Code 3
![image](https://user-images.githubusercontent.com/42286904/145857206-3c869cf8-8add-4401-ba13-169663f5969d.png)
