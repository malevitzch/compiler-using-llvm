# compiler-using-llvm
The goal of this project is to explore LLVM code generation and create a compiler that can generate object files straight from user code so that it does not rely on an NASM assembler being installed on the system.
# plan
1. Creating an AST
2. Basic code generation (variables and a print statement)
3. Control flow
4. Functions
# todo
- link parser to the project in cmake
- create an internal representation for operators (or use one provided by llvm)
- implemented an LR parser
