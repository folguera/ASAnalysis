#ifndef LeptJetMultAnalyzer_hh
#define LeptJetMultAnalyzer_hh

#include <TTree.h>
#include <TStyle.h>

#include "base/TreeAnalyzerBase.hh"
#include "base/TreeReader.hh"
#include "MultiplicityAnalysis.hh"
#include "MassAnalysis.hh"
#include "RatioAnalysis.hh"



class LeptJetMultAnalyzer : public TreeAnalyzerBase {
public:
	LeptJetMultAnalyzer(TTree *tree = 0);
	virtual ~LeptJetMultAnalyzer();
	void BeginJob(TString filename="Multiplicity.root" , TString setofcuts="default", float lumi=-999.99);
	void EndJob();
	void Loop();
	void SetMaxEvents(int a){fMaxEvents=a;}

private:
	MultiplicityAnalysis     *fMultiplicityAnalysis;
	MassAnalysis             *fMassAnalysis;
	RatioAnalysis            *fRatioAnalysis;		
  	int fMaxEvents;
};
#endif
