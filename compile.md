## Build Commands List

*Run inside the `main\` folder*
```bash
g++ executesort.cpp "..\insertion\insertion.cpp" "..\selection\selection.cpp" "judge.cpp" "readfile.cpp" "writefile.cpp" && a.exe
```

Compiling individual files
```bash
g++ insertion.cpp "..\main\writefile.cpp" "..\main\readfile.cpp" && a.exe 
```