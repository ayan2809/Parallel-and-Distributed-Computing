## Lab 10 Submissions

The codes of my course Parallel and Distributed Computing using MPI for the various problems


## Description

- **Code 1 -** Let Process 0 has variable A, and Process 1 has a variable B. Write MPI-like pseudocode to exchange these values between the processes. In other words, variable A should be shared to Process 1 and variable B should be shared to Process 0. Process 0 should display value of A and Process 1 should display value of B.
- **Code 2 -** Create four processes P0, P1, P2 and P3. Let each process Pi sends its rank to another process Pj as given below. Let the receiving process Pj prints the sum of its rank and the rank received from Pi.Sending Process Pi Receiving Process Pj
  P0
  P1
  P1
  P2
  P2
  P3
  P4
  P0

- **Code 3 -** Consider four processes with their distributed integer data. Each process will have ‘m’ integer values where ‘m’ differs from one process to another. You can assume any value for ‘m’. Let each individual process performs sum of their ‘m’ numbers and print it. Let each process will share its average (sum of ‘m’ numbers)/m to the process with rank 0. Let the process with rank 0 print the average of all the numbers received. In other words perform sum of the 4 data received and divide it by 4.

## Run Locally

Clone the project

```bash
  git clone https://github.com/ayan2809/Parallel-and-Distributed-Computing
```

Go to the project directory

```bash
  cd Parallel-and-Distributed-Computing
  cd Lab 10
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
![image](https://user-images.githubusercontent.com/42286904/146018686-64757737-e70c-4706-bee4-eb93540338b6.png)

### Code 2
![image](https://user-images.githubusercontent.com/42286904/146018951-02a102fa-f1cb-49e2-be06-9d07a1e7517e.png)

### Code 3
![image](https://user-images.githubusercontent.com/42286904/146019066-2e0933f5-ba01-4a79-8c59-e024e49f650b.png)
