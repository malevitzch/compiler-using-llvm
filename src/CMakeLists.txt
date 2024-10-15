# Now build our tools
add_executable(compiler main.cpp lexer.cpp trie.cpp ast.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

target_include_directories(compiler PRIVATE ${CMAKE_SOURCE_DIR}/include)
# Link against LLVM libraries
target_link_libraries(compiler ${llvm_libs})
