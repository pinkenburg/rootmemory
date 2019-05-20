
#include "GenerateRootHits.h"
#include "MyRootContainer.h"
#include "MyRootHitv1.h"

#include <TRandom3.h>
#include <TFile.h>

#include <cmath>
#include <iostream>

using namespace std;

GenerateRootHits::GenerateRootHits()

{
  RandomGenerator = new TRandom3(12345);
}

GenerateRootHits::~GenerateRootHits()
{
}

int GenerateRootHits::Init()
{
  g4_hits = new MyRootContainer();
  outfile = new TFile("output.root","RECREATE");
  return 0;
}

int GenerateRootHits::Run(const int nevents)
{
  cout << "GenerateRootHits::process_event -- entered" << endl;
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
    g4_hits->Write();
    g4_hits->Reset();
  }
  return 0;
}

int GenerateRootHits::End()
{
  outfile->Write();
  outfile->Close();
  delete outfile;
  return 0;
}

