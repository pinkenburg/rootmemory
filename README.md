# rootmemory
Test code showing memory usage for STL compared to TClonesArrays for ROOT developers. It is run under SL7.3

usage:
It needs the auto tools (autoconf, automake and libtool from the SL7.3 disribution), ROOTSYS has to be set, root tools need to be in your path</br></br>
<p>

git clone https://github.com/pinkenburg/rootmemory</br>
cd rootmemory</br>
mkdir build</br>
cd build</br>
../autogen.sh --prefix=<install area></br>
</verbatim>
set ROOT_INCLUDE_PATH to <install area>/include/memsizetest</br>
<p>
start root, on the prompt for the STL Example:</br></br>


#include "GenerateSTLHits.h"</br>
R__LOAD_LIBRARY(libmemsizetest.so)</br>
  GenerateSTLHits *gen = new GenerateSTLHits();</br>
  gen->Init();</br>
  gen->Run(5);</br>
  gen->End();</br>
  gSystem->Exit(0);</br>


<p>
for the TClonesArray Example:</br></br>


#include "GenerateTCHits.h"</br>
R__LOAD_LIBRARY(libmemsizetest.so)</br>
  GenerateTCHits *gen = new GenerateTCHits();</br>
  gen->Init();</br>
  gen->Run(5);</br>
  gen->End();</br>
  gSystem->Exit(0);</br>

<p>
running this under massif the output from massif-visualizer under ubuntu 16.04.6: </br>
valgrind --tool=massif --time-unit=B --detailed-freq=1 root.exe


Saving an STL Map in a TTree branch:
![STL Object](STLMap.png)

Saving the same information in a TClonesArray in a TTree branch:
![TClonesArray](TClonesArray.png)
