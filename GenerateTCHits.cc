
#include "GenerateTCHits.h"
#include "MyRootTCContainer.h"
#include "MyRootHitv1.h"

#include <TRandom3.h>
#include <TFile.h>
#include <TTree.h>

#include <cmath>
#include <iostream>

using namespace std;

GenerateTCHits::GenerateTCHits()

{
  RandomGenerator = new TRandom3(12345);
}

GenerateTCHits::~GenerateTCHits()
{
}

int GenerateTCHits::Init()
{
  g4_hits = new MyRootTCContainer();
  outfile = new TFile("TCoutput.root","RECREATE");
  TT = new TTree("T","TCTree");
  TT->Branch("TCBranch","MyRootTCContainer",&g4_hits,32000,99);
  return 0;
}

int GenerateTCHits::Run(const int nevents)
{
  cout << "GenerateTCHits::process_event -- entered" << endl;
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
      delete m_Hit;
    }
    TT->Fill();
//    g4_hits->Write();
    g4_hits->Reset();
  }
  return 0;
}

int GenerateTCHits::End()
{
  outfile->Write();
  outfile->Close();
  delete outfile;
  return 0;
}

