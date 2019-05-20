# rootmemory
Test code showing memory usage for STL compared to TClonesArrays for ROOT developers

massif output from: </br>
valgrind --tool=massif --time-unit=B --detailed-freq=1 root.exe

![STL Object](STLMap.png)

![TClonesArray](TClonesArray.png)
