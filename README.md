# rootmemory
Test code showing memory usage for STL compared to TClonesArrays for ROOT developers

massif output from: </br>
valgrind --tool=massif --time-unit=B --detailed-freq=1 root.exe


Saving an STL Map in a TTree branch:
![STL Object](STLMap.png)

Saving the same information in a TClonesArray in a TTree branch:
![TClonesArray](TClonesArray.png)
