AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I`root-config --incdir`

lib_LTLIBRARIES = \
  libmemsizetest.la

AM_CXXFLAGS = \
  -Werror

AM_LDFLAGS = \
  -L$(libdir) \
  `root-config --libs`

pkginclude_HEADERS = \
  GenerateTCHits.h \
  GenerateSTLHits.h \
  MyRootSTLContainer.h \
  MyRootTCContainer.h \
  MyRootHit.h \
  MyRootHitv1.h

ROOTDICTS = \
  MyRootSTLContainer_Dict.cc \
  MyRootTCContainer_Dict.cc \
  MyRootHit_Dict.cc \
  MyRootHitv1_Dict.cc

if MAKEROOT6
  pcmdir = $(libdir)
  nobase_dist_pcm_DATA = \
    MyRootSTLContainer_Dict_rdict.pcm \
    MyRootTCContainer_Dict_rdict.pcm \
    MyRootHit_Dict_rdict.pcm \
    MyRootHitv1_Dict_rdict.pcm
endif

libmemsizetest_la_SOURCES = \
  $(ROOTDICTS) \
  $(ROOT5_DICTS) \
  GenerateTCHits.cc \
  GenerateSTLHits.cc \
  MyRootSTLContainer.cc \
  MyRootTCContainer.cc \
  MyRootHitv1.cc


# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests

noinst_PROGRAMS = \
  testexternals

BUILT_SOURCES = testexternals.cc

testexternals_SOURCES = testexternals.cc
testexternals_LDADD = libmemsizetest.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
