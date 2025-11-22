# FAITH ONLINE BANKING SYSTEM (C)

A simple console-based banking application written in C. It persists account data to a local binary file and provides common operations like register, deposit, withdraw, transfer, change password, and display account details.

## Overview
- Stores accounts in `bank_accounts.dat` using a binary `Account` struct.
- Currency is `ZMW`.
- Runs as a menu-driven CLI program.

## Features
- Register a new account
- Login and deposit funds
- Login and withdraw funds
- Login and transfer funds to another account
- Login and change password
- Login and display account details

## Project Structure
- `onlinebaking.c` — source code
- `ONLINEBAKING.exe` — compiled Windows executable (may be present)
- `bank_accounts.dat` — data file created at runtime in the working directory

## Build (Windows)
You can build with either GCC (MinGW) or MSVC.

### GCC (MinGW)
```powershell
gcc -O2 -Wall -o ONLINEBAKING.exe onlinebaking.c
```

### MSVC (Developer Command Prompt)
```powershell
cl /W3 /O2 /Fe:ONLINEBAKING.exe onlinebaking.c
```

## Run
```powershell
./ONLINEBAKING.exe
```

## Data & Persistence
- Data file: `bank_accounts.dat` (created automatically on first write)
- Stored fields: name, account number, password, balance
- To reset the system, delete `bank_accounts.dat` from the project directory

## Usage Flow
- Launch the program and choose an option from the menu:
  1. Register Account
  2. Login & Deposit
  3. Login & Withdraw
  4. Login & Transfer
  5. Login & Change Password
  6. Login & Display Account
  7. Exit
- Follow the prompts. For names, the program accepts spaces; for account numbers and passwords, it reads single tokens.

## Notes
- Passwords are stored in plaintext within a local binary file; this is for learning purposes and is not secure for production use.
- Input validation is basic; non-numeric menu input is handled, but amounts must be positive numbers.
- The program prints the student number in the banner.

## References in Code
- Data file name: `onlinebaking.c:5`
- Currency code: `onlinebaking.c:6`
- Menu and main loop: `onlinebaking.c:30`
- Register account: `onlinebaking.c:150`
- Deposit: `onlinebaking.c:194`
- Withdraw: `onlinebaking.c:230`
- Transfer: `onlinebaking.c:270`
- Change password: `onlinebaking.c:333`
- Display account: `onlinebaking.c:379`
- File I/O helpers: `onlinebaking.c:80`, `onlinebaking.c:92`, `onlinebaking.c:110`