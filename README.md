# compiler-using-llvm
The goal of this project is to explore LLVM code generation and create a compiler that can generate object files straight from user code so that it does not rely on an NASM assembler being installed on the system.
# plan
1. Devising a decent grammar for the language
2. Creating an AST using the LR parser
3. Basic code generation (variables and a print statement)
4. Control flow
5. Functions
# todo
- link parser to the project in cmake
- use an LR(1) parser rather than writing my own since that would be too much work for nothing
- create an internal representation for operators (or use one provided by llvm)
- implemented an LR parser
