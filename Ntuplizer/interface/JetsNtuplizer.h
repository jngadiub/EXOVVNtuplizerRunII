#ifndef JetsNtuplizer_H
#define JetsNtuplizer_H

#include "../interface/CandidateNtuplizer.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"
#include "SimDataFormats/JetMatching/interface/JetFlavour.h"

#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"

class JetsNtuplizer : public CandidateNtuplizer {

public:
//   JetsNtuplizer( std::vector<edm::InputTag> labels, std::vector<std::string> jecCA8Labels, std::vector<std::string> jecAK5Labels, NtupleBranches* nBranches );

 JetsNtuplizer( std::vector<edm::EDGetTokenT<pat::JetCollection>> token, std::vector<std::string> jecAK4Labels, std::vector<std::string> jecAK8Labels, std::vector<std::string> jecAK8GroomedLabels, std::vector<std::string> jecAK8PuppiLabels, edm::EDGetTokenT<reco::JetFlavourMatchingCollection> flavourToken, edm::EDGetTokenT<double> rhoToken, edm::EDGetTokenT<reco::VertexCollection> verticeToken, NtupleBranches* nBranches, std::map< std::string, bool >& runFlags );
   ~JetsNtuplizer( void );

  bool looseJetID( const pat::Jet& j );
  bool tightJetID( const pat::Jet& j );

  void fillBranches( edm::Event const & event, const edm::EventSetup& iSetup );
  void initJetCorrFactors( void );
  
  
 private:
  
  std::vector<std::string>                    jecAK8PayloadNames_;
  std::vector<std::string>                    jecAK8GroomedPayloadNames_;
  std::vector<std::string>                    jecAK8PuppiPayloadNames_;
  boost::shared_ptr<FactorizedJetCorrector>   jecAK8_            ;      
  boost::shared_ptr<FactorizedJetCorrector>   jecAK8Groomed_            ;      
  boost::shared_ptr<FactorizedJetCorrector>   jecAK8Puppi_            ;      
  // boost::shared_ptr<JetCorrectionUncertainty> jecAK8Unc_         ;
  
  std::vector<std::string>                    jecAK4PayloadNames_;
  boost::shared_ptr<FactorizedJetCorrector>   jecAK4_            ;
  // boost::shared_ptr<JetCorrectionUncertainty> jecAK4Unc_         ;
  
  
  edm::EDGetTokenT<pat::JetCollection> 					jetInputToken_     		;
  edm::EDGetTokenT<pat::JetCollection> 					fatjetInputToken_  		;
  edm::EDGetTokenT<pat::JetCollection> 					prunedjetInputToken_ 	;
  edm::EDGetTokenT<pat::JetCollection> 					softdropjetInputToken_ 	;
  edm::EDGetTokenT<pat::JetCollection>                                  trimmedjetInputToken_   ;
  edm::EDGetTokenT<pat::JetCollection>                                  puppijetInputToken_   ;
  edm::EDGetTokenT<reco::JetFlavourMatchingCollection> 	flavourToken_   		;
  edm::EDGetTokenT<double> 		   						rhoToken_     			;
  edm::EDGetTokenT<reco::VertexCollection>  			verticeToken_ 			;
  
  edm::Handle<pat::JetCollection>      					jets_      				;
  edm::Handle<pat::JetCollection>      					fatjets_      			;
  edm::Handle<pat::JetCollection>      					prunedjets_      		;
  edm::Handle<pat::JetCollection>      					softdropjets_      		;
  edm::Handle<pat::JetCollection>                                       trimmedjets_                    ;
  edm::Handle<pat::JetCollection>                                       puppijets_                    ;
  
  edm::Handle<reco::JetFlavourMatchingCollection> 		jetMC 					;
  edm::Handle< double >                     			rho_        			;
  edm::Handle<reco::VertexCollection> 	     			vertices_     			;
  
  bool doCorrOnTheFly_;
  bool doAK4Jets_;
  bool doAK8Jets_;
  bool doPruning_;
  bool runOnMC_;
  
};

#endif // JetsNtuplizer_H
