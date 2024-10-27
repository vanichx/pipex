**Pipex**

### Description

**Pipex** is a C program that replicates the behavior of a shell pipeline, allowing the output of one command to be directly passed as input to another. Given two files (`file1` and `file2`) and two commands (`cmd1` and `cmd2`), Pipex executes the commands in sequence, emulating the shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

This project provides hands-on experience with process creation, inter-process communication, and file handling through UNIX system calls.

### Key Features

- **Basic Pipeline**: Takes an input file, processes it with `cmd1`, and pipes the output to `cmd2`, which writes the result to the output file.
- **Error Handling**: Ensures stability and manages errors gracefully, avoiding unexpected crashes and memory leaks.
- **Extended Functionality** (Bonus):
  - **Multiple Commands**: Supports a series of commands in a chained pipeline (`cmd1 | cmd2 | cmd3 ... | cmdn`).
  - **Here Document**: Implements `<<` and `>>` for custom input and output handling with a limiter, enabling usage such as `./pipex here_doc LIMITER cmd cmd1 file`.

### Usage

To use **Pipex**:

1. Compile the program with `make`:
   ```bash
   make
   ```

2. Execute **Pipex** by specifying the input file, commands, and output file:
   ```bash
   ./pipex file1 "cmd1" "cmd2" file2
   ```

   **Example**:
   ```bash
   ./pipex infile "ls -l" "wc -l" outfile
   ```
   This example replicates: `< infile ls -l | wc -l > outfile`.

### Required Arguments

- **file1**: Input file name.
- **cmd1**: First shell command with parameters.
- **cmd2**: Second shell command with parameters.
- **file2**: Output file name.
