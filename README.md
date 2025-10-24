# 🖨️ Custom `printf` Implementation in C 🖨️

## 📖 Overview

This project is a **complete reimplementation of the standard C `printf` function**, built entirely from scratch in C.  
It aims to reproduce the behavior of the original `printf`, including support for **flags**, **width**, **precision**, and **length modifiers**, with a clean and modular design.  

The project is organized as a **static library** (`libmy.a`) that can be reused in other C programs.

---

## 🛠️ Compilation & Makefile Rules 🛠️

All compilation and testing operations are handled through the **Makefile**.  
Here are the available commands:

| Command          | Description                                                                                                    |
|------------------|----------------------------------------------------------------------------------------------------------------|
| `make`           | Compiles all source files and builds the `libmy.a` static library.                                             |
| `make clean`     | Removes all generated object files (`.o`, `.gcno`, `.gcda`, etc...).                                           |
| `make fclean`    | Removes all object files and the compiled library (`libmy.a`).                                                 |
| `make re`        | Performs a full rebuild (equivalent to `make fclean && make`).                                                 |
| `make tests_run` | Builds and runs **unit tests**, generating a **code coverage report** using *gcovr*.                           |
| `make manu_test` | Compiles and runs the program with `main.c` for **manual testing**. (you have to make your own `main.c` file ) |
| `make help`      | Displays all available Makefile rules with explanations.                                                       |

---

## ⚙️ Project Structure ⚙️

```
printf_project/
├── include/              # Header files
│   ├── formats.h
│   └── my.h
│
├── lib/                  # Compiled static library and source folder
│   ├── libmy.a
│   └── my/
│       ├── my.h and formats.h ( header files respectively to include prototypes and for structures )
│       ├── my_putnbr_base.c
│       ├── my_printf.c           # Core printf implementation
│       ├── my_putchar.c
│       ├── specifier_d.c
│       ├── specifier_s.c
│       ├── specifier_x.c
│       └── ... (etc.)            # all teh diferents function taht are called in my_printf.c
│
├── tests/                # Unit testing files
│   └── unit_tests.c
│                         # add a main.c file here to manualy tests functions and use "make manu_tests" to compil and run 
├── Makefile              # Build, test management and debuging see make help
└── libmy.a               # Compiled library output
```

---

## 💻⚙️ Usage ⚙️💻

### Including and Using the Function

To use your custom `printf`, include the header file:

```c
#include "my.h"
```

Then call it like a normal `printf`:

```c
my_printf("Hello %s! You scored %d points.\n", "Sacha", 100);
```

### Example Build and Execution

```bash
make manu_test
```
(don't forget to create a main first to call the function)
---

## 🧪 Testing & Debugging

### 🧷 Unit Tests

Run automated unit tests and view coverage:

```bash
make tests_run
```

This will compile all test files (from the `tests/` directory) and execute them, displaying detailed results and generating a **coverage report** using **gcovr**.

---

### 👷🏻‍♀️ Manual Testing 👷🏻‍♀️

Run your custom test program:

(don't forget to create a main first to call the function)

```bash
make manu_test
```

This compiles and runs the project using `main.c`, allowing you to manually check formatting behavior.

---

### 🧰 Help

To display all available build and test commands:

```bash
make help
```

This lists each rule with a short explanation, making it easy to remember available options.

---

## ✨ Features ✨

### Implemented Specifiers

- `%d`, `%i` — Signed integers  
- `%u` — Unsigned integers  
- `%x`, `%X` — Hexadecimal  
- `%o` — Octal  
- `%s` — Strings  
- `%c` — Characters  
- `%p` — Pointers  
- `%%` — Literal `%`

---

### Flags

| Flag    | Description                                                        |
|---------|--------------------------------------------------------------------|
| `#`     | Adds prefixes like `0x`, `0`, or forces a decimal point for floats |
| `+`     | Forces display of the `+` sign for positive numbers                |
| `-`     | Left-aligns the output within the given width                      |
| (space) | Adds a space before positive numbers if no sign is printed         |
| `'`     | Adds locale-based digit grouping (if supported)                    |

---

### Width & Precision

- **Width:** Defines the minimum printed field width.  
- **Precision:** Controls number of digits (for numbers) or characters (for strings).  

---

### Length Modifiers

| Modifier      | Effect                                     |
|---------------|--------------------------------------------|
| `h`, `hh`     | Converts argument to `short` or `char`     |
| `l`, `ll`     | Converts argument to `long` or `long long` |
| `z`, `j`, `t` | Handles platform-dependent integer sizes   |

---

## 👤 Author
## Pinkie Pie squad

**Sacha Le Moign-Avalos & Erwan Lo-Presti**  
📍 Nice, France  
💻 Custom `printf` Project — 2025
