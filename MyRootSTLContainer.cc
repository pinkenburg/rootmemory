#include "MyRootSTLContainer.h"

#include <cstdlib>

using namespace std;

MyRootSTLContainer::MyRootSTLContainer()
{
}

void
MyRootSTLContainer::Reset()
{
   while(slatmap.begin() != slatmap.end())
     {
       delete slatmap.begin()->second;
       slatmap.erase(slatmap.begin());
     }
  return;
}


void
MyRootSTLContainer::AddScintillatorSlat(const unsigned int key, MyRootHit *newslat)
{
  if(slatmap.find(key)!=slatmap.end())
   {
     cout << "MyRootSTLContainer::AddScintillatorSlatSpecifyKey: duplicate key: " << key << " exiting now" << endl;
     exit(1);
   }
  newslat->set_key(key);
  slatmap[key] = newslat;
  return;
}
