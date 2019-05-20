
#include "GenerateSTLHits.h"
#include "MyRootSTLContainer.h"
#include "MyRootHitv1.h"

#include <TRandom3.h>
#include <TFile.h>
#include <TTree.h>

#include <cmath>
#include <iostream>

using namespace std;

GenerateSTLHits::GenerateSTLHits()

{
  RandomGenerator = new TRandom3(12345);
}

GenerateSTLHits::~GenerateSTLHits()
{
}

int GenerateSTLHits::Init()
{
  g4_hits = new MyRootSTLContainer();
  outfile = new TFile("output.root","RECREATE");
  TT = new TTree("T","STLTree");
  TT->Branch("STLBranch","MyRootSTLContainer",&g4_hits,32000,99);
  return 0;
}

int GenerateSTLHits::Run(const int nevents)
{
  cout << "GenerateSTLHits::process_event -- entered" << endl;
  for (int k=0; k<nevents; ++k)
  {
    int nhits = 1000000;
    for (int j=0; j<nhits; ++j)
    {
      MyRootHit *m_Hit = new MyRootHitv1();
      m_Hit->set_key(j);
      m_Hit->add_edep(RandomGenerator->Rndm(),
		      RandomGenerator->Rndm(),
		      RandomGenerator->Rndm());
      g4_hits->AddScintillatorSlat(m_Hit->get_key(),m_Hit);
    }
    TT->Fill();
//   g4_hits->Write();
    g4_hits->Reset();
  }
  return 0;
}

int GenerateSTLHits::End()
{
  outfile->Write();
  outfile->Close();
  delete outfile;
  return 0;
}

