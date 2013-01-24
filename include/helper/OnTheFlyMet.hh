#include <vector>
#include <iostream>
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "../base/TreeReader.hh"

class OnTheFlyCorrections {
	public:
		OnTheFlyCorrections (std::string globaltag, bool isdata);
		~OnTheFlyCorrections(){};

		std::vector<JetCorrectorParameters> fJetCorPar;
		FactorizedJetCorrector *fJetCorrector;
		// FactorizedJetCorrector(OnTheFlyCorrections::fJetCorPar) *fJetCorrector;

		std::pair< float, float > getCorrections( float pt, float eta, float phi, float emf, float rho, float area, std::string level = "" );

		float getPx(float pt, float phi){ return pt*cos(phi); };
		float getPy(float pt, float phi){ return pt*sin(phi); };
};

