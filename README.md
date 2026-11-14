# Wish — A Simple Unix Shell

Wish is a lightweight Unix shell written in C that demonstrates process management, command execution, and basic shell functionality.

## Features

- **Command Execution:** Runs external programs using `fork()`, `execv()`, and `wait()`.
- **Interactive Mode:** Accepts commands through the `wish>` prompt.
- **Batch Mode:** Executes commands from a file.
- **Built-in Commands:**
  - `exit` — Terminates the shell.
  - `cd <directory>` — Changes the working directory.
  - `path <directories>` — Sets executable search paths (defaults to `/bin`).
- **Output Redirection:** Uses `>` to redirect both stdout and stderr to a file.
- **Parallel Execution:** Uses `&` to run multiple commands concurrently.
- **Error Handling:** Handles invalid commands, syntax errors, and process failures.

## Usage

**Interactive mode:**

`./wish`

**Batch mode:**

`./wish batch.txt`

## Example Commands

```bash
wish> ls -la
wish> cd /tmp
wish> path /bin /usr/bin
wish> ls > output.txt
wish> ls & pwd
wish> exit
```

## Purpose

Built to explore Unix system calls, process creation, command parsing, and the fundamentals of shell implementation.
