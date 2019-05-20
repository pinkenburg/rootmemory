#ifndef MYUTILS_GENERATESTLHITS_H
#define MYUTILS_GENERATESTLHITS_H


class MyRootSTLContainer;
class TFile;
class TRandom;
class TTree;

class GenerateSTLHits
{
 public:
  GenerateSTLHits();
  virtual ~GenerateSTLHits();

  int Init();
  int Run(const int nevents);
  int End();

 private:
  TRandom *RandomGenerator;
  MyRootSTLContainer *g4_hits;
  TFile *outfile;
  TTree *TT;
};

#endif
