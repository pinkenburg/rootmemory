#ifndef MYUTILS_GENERATEROOTHITS_H
#define MYUTILS_GENERATEROOTHITS_H


class MyRootContainer;
class TFile;
class TRandom;

class GenerateRootHits
{
 public:
  GenerateRootHits();
  virtual ~GenerateRootHits();

  int Init();
  int Run(const int nevents);
  int End();

 private:
  TRandom *RandomGenerator;
  MyRootContainer *g4_hits;
  TFile *outfile;
};

#endif
