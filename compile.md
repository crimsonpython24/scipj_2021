## Build Commands List

*Run inside the `main\` folder*
```bash
g++ executesort.cpp "..\insertion\insertion.cpp" "..\selection\selection.cpp" "..\merge\merge.cpp" "..\quick\quick.cpp" "..\bubble\bubble.cpp" "judge.cpp" "readfile.cpp" "writefile.cpp" "utils.cpp" && a.exe
```

Compile two exe's without running nothing
```bash
g++ executesort.cpp "..\insertion\insertion.cpp" "..\selection\selection.cpp" "judge.cpp" "readfile.cpp" "writefile.cpp" "utils.cpp" && g++ -Wall -pedantic executesort.cpp "..\insertion\insertion.cpp" "..\selection\selection.cpp" "judge.cpp" "readfile.cpp" "writefile.cpp" "utils.cpp" -o build.exe
```

Build a main executable
```bash
g++ -Wall -pedantic executesort.cpp "..\insertion\insertion.cpp" "..\selection\selection.cpp" "judge.cpp" "readfile.cpp" "writefile.cpp" "utils.cpp" -o build.exe
```

Compiling individual files
```bash
g++ insertion.cpp "..\main\writefile.cpp" "..\main\readfile.cpp" "..\main\judge.cpp" && a.exe 
cd insertion && g++ insertion.cpp "..\main\writefile.cpp" "..\main\readfile.cpp" "..\main\judge.cpp" && a.exe & cd .. // full
```

### Miscellaneous
**GPG not working**: `gpg: can't connect to the agent: IPC connect call failed`
```bash
gpg-connect-agent --verbose
```