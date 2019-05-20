#ifndef MYROOTSTLCONTAINER_H__
#define MYROOTSTLCONTAINER_H__

#include "MyRootHit.h"

#include <TObject.h>

#include <map>
#include <set>

class MyRootSTLContainer: public TObject
{

  public:

  MyRootSTLContainer();

  virtual ~MyRootSTLContainer() {}

  void Reset();

  void AddScintillatorSlat(const unsigned int key, MyRootHit *newscintillatorSlat);
  
  unsigned int size( void ) const
  { return slatmap.size(); }

 protected:
  std::map<unsigned int,MyRootHit *> slatmap;

  ClassDef(MyRootSTLContainer,1)
};

#endif
