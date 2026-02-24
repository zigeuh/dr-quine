# 📘 dr-quine

The goal of this project is to create a program that outputs its **own source code** without reading it from a file 📜.  
This exercise is designed to teach **self-replicating programs** 🧠, **creative problem solving** 💡, and **deep understanding of the language syntax** ⚙️.  
It challenges students to think **recursively** 🔁 and to master **string manipulation and code structure** 🧩.

For every quine, we have to do it in 2 differents languages (mandatory):
- C
- ASM

And a third language for the bonuses. I chose to use **Python**.

## 🌀 Colleen Queen
<details>
<summary> Explanations</summary>

###

This quine demonstrates **embedding comments and code together** while still reproducing the full source code 📜.  

- **Technique:** Uses a **format string with placeholders** (`%s`, `%c`) to print the source, including multi-line comments.  
- **Highlights:**  
  - Preserves **comments inside and outside** the program (`/* ... */`).  
  - Calls a **dummy function `if_one()`** to show code execution without affecting output.  
  - Demonstrates **careful escaping of quotes and newlines** (`34` = `"`, `10` = newline, `9` = tab).  
- **Learning points:**  
  - Managing complex **format strings**.  
  - Mixing **executable code** and **comments** in a quine.  
  - Understanding how **printf can replicate the full source** including special characters.

</details>

## 🖋️ Grace Quine
<details>
<summary> Explanations</summary>

###

This quine demonstrates how a program can **reproduce itself into a separate file** instead of just printing to stdout 📄.  

- **Technique:**  
  - Uses **`open` and `dprintf`** to write its source code to a file (`Grace_kid.c`).  
  - Encodes the program in a **macro (`STR`)** with placeholders for **newlines** (`10`) and **quotes** (`34`).  
  - Leverages **preprocessor macros** (`#define`) to make the code compact and self-referential.  

- **Highlights:**  
  - Produces a **new file containing the exact source code** of the quine.  
  - Demonstrates how **C macros and file I/O** can be combined for self-replication.  
  - No execution of extra code is needed beyond writing the file.  

- **Learning points:**  
  - Understanding **macro expansion** and **format strings**.  
  - Using **system calls for file creation** (`open`, `O_CREAT`, `O_TRUNC`, `O_WRONLY`).  
  - Managing **self-referential code** without reading the source from disk.
</details>

## 🔁 Sully Quine
<details>
<summary> Explanations</summary>

###

This quine demonstrates a **countdown self-replicating program**.  

- **Technique:**  
  - Creates **copies of itself with a decreasing counter** (`count`) embedded in the filename (`Sully4.c`, `Sully3.c`, etc.).  
  - Uses **file I/O (`open` and `dprintf`)** to write each new version.  
  - Automatically **compiles and executes** each copy using `system()` and `clang`.  

- **Highlights:**  
  - Produces a **chain of self-replicating files** that decrease a counter until 0.  
  - Demonstrates **dynamic filename generation** based on the counter.  
  - Integrates **string formatting, system calls, and compilation** in a single program.  

- **Learning points:**  
  - Managing **recursive self-replication with a counter**.  
  - Combining **file operations, format strings, and subprocess execution**.  
  - Understanding **how quines can evolve into multiple versions autonomously**.
</details>
