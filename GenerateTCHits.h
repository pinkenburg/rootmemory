#ifndef MYUTILS_GENERATETCHITS_H
#define MYUTILS_GENERATETCHITS_H


class MyRootTCContainer;
class TFile;
class TRandom;
class TTree;

class GenerateTCHits
{
 public:
  GenerateTCHits();
  virtual ~GenerateTCHits();

  int Init();
  int Run(const int nevents);
  int End();

 private:
  TRandom *RandomGenerator;
  MyRootTCContainer *g4_hits;
  TFile *outfile;
  TTree *TT;
};

#endif
