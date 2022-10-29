
## brainfuck-utils

This is a repo intended to house all of my brainfuck related projects.

Currently there are three:
- an interpreter. (interprets).
	- obs.: no safety checks (eg. index out of bounds / segmentation fault).
- a compressor. (turns sequences of n repeating characters into n followed by the character). may be extended in the future.
	- obs.: hardcoded filenames. doesn't work.
- a decompressor. (turns compressed brainfuck into regular brainfuck code). may be extended in the future.
	- obs.: hardcoded filenames.  


Planned additions:
- a debugger (likely the only one with a nonzero chance of getting implemented) 
- a compiler (let's see...)
- brainfuck generator.
- different versions (eg. named variables, absolute pointers, etc)  
