# 💻 Programming Laboratories - CS Project

## ℹ️ About

This is a small project developed in the programming laboratories class, at the first cycle of my computer science bachelors course.

The project consists of a small program that initially writes an array of N (defined **macro** at "functions.h" headers file) elements, given by the user, which are stored to perform certain mathematical operations over them (elements) or the array as a whole.

Please note that the program itself is written in Portuguese.

## 🗃️ Installation

To install this project on your machine, clone the repository using HTTPS, SSH or GitHub CLI into a local directory or, alternatively, download the files directly.

## ⚙️ Automated Compilation and Execution (using Makefile)

- **Note:** Make sure to have both *C compiler* and *make* installed: `sudo apt install build-essential`.

After cloning the repository, access the folder named "**src**" (source code) and follow the instructions bellow:

| Compile | Compile and execute   | Execute                                                                                 |
|:-------:|:---------------------:|:---------------------------------------------------------------------------------------:|
| `make`  | `make execute`        | `make execute` (ignores the compilation process if the output file is already existing) |

## 🔧 Manual Compilation and Execution:

- **Note:** Make sure to have the *C compiler* installed: `sudo apt install build-essential`.

After cloning the repository, access the folder named "**src**" (source code) and follow the instructions bellow:

1. **Linking:** `gcc -c main.c functions.c`
2. **Compiling:** `gcc main.o functions.o -o program.exe -lm -Wall`
3. **Executing:** `./program.exe`

## 🆘 Help page

Run `make help` at the "**src**" (source code) folder to check the helping page. This command will link, compile and execute the program using the flag "**--help**".

An helping page can also be found at the main menu of the program.

## 🧹 Clean output files from the compilation process (using Makefile)

Run `make clean` at the "**src**" (source code) folder to remove every output file. This command will remove every file whose extension is ".o" ".exe" or ".out". 
