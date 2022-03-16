//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 28 10:17:06 2022 by ROOT version 6.10/08
// from TTree ttree/ttree
// found on file: UDD_bgctau30_smu300_snu250.root
//////////////////////////////////////////////////////////

#ifndef LLTopTree_h
#define LLTopTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//$$
#include <TMath.h>
//$$

// Header file for the classes stored in the TTree if any.
#include "vector"

//$$
using namespace std;
//$$

class LLTopTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runNumber;
   Int_t           eventNumber;
   Int_t           lumiBlock;
   Float_t         tree_bs_PosX;
   Float_t         tree_bs_PosY;//bs beamspot
   Float_t         tree_bs_PosZ;
   vector<float>   *tree_vtx_PosX;//position de tous les vertex primaires : celui qui nous interesse (indice 0) posX[0]
   vector<float>   *tree_vtx_PosY;
   vector<float>   *tree_vtx_PosZ;
   vector<float>   *tree_vtx_NChi2;//chi2dof 
   vector<float>   *tree_vtx_PosXError;
   vector<float>   *tree_vtx_PosYError;
   vector<float>   *tree_vtx_PosZError;
   vector<string>  *tree_trigger_names;
   vector<bool>    *tree_trigger_bits;
   Int_t           tree_NbrOfZCand;//au moins 1, on espere
   vector<bool>    *tree_passesHTFilter;//comme dans papier Ht = sum des Et
   vector<float>   *tree_track_pt;
   vector<float>   *tree_track_outerPt;//outer layers pt
   vector<float>   *tree_track_eta;
   vector<float>   *tree_track_phi;//attention aux diff�rences de phi: voir morceau de code dans .C
   vector<int>     *tree_track_charge;
   vector<int>     *tree_track_nhits;//nombre  de coups qui ont �t� retenu pour reco la trace � regarder car on garde pour de peiits nombres de hits
   vector<float>   *tree_track_NChi2;//
   vector<bool>    *tree_track_isHighQuality;//� regarder
   vector<bool>    *tree_track_isLoose;//� regrder
   vector<bool>    *tree_track_isTight;//� regarder
   vector<float>   *tree_track_dxy;//Par interpolation de la trajectoire jusqu'au plan transverse associ� au PV, calcul l'�cart entre vtx posx[0] et on obtient dxy. puis on regarde par rapprot � l'axe z , pour a voir dz (le calcul n'est pas fait dans l'espace mais dans le plan transverse puis en dz
   vector<float>   *tree_track_dxyError;// � regarder: le rapport de dxy/dxyerror : normalement gaussienne centr� en 0 (et sigma 1) en th�orie, en r�alit� on obsreve guassienne avec des queues
   vector<float>   *tree_track_dz;
   vector<float>   *tree_track_dzError;
   vector<int>     *tree_track_numberOfLostHits;
   vector<int>     *tree_track_numberOfValidHits;
   vector<unsigned int> *tree_track_originalAlgo;//algo pour le tracking 
   vector<unsigned int> *tree_track_algo;
   vector<unsigned short> *tree_track_stopReason;
   vector<bool>    *tree_track_isSimMatched;//trace simul�e coreespont a une trace reco du signal
   vector<int>     *tree_track_numberOfValidPixelHits;//4 couches de pixels soit doble face, limite � 8geV normalement on peut avoir 0 si production lointaine du PV
   vector<int>     *tree_track_numberOfValidStripHits;//Pareil dans silicium, 0 si vu que dans les pixels et pixel + strip donne le nombre de Hits
   vector<int>     *tree_track_numberOfValidStripTIBHits;//inner barrel
   vector<int>     *tree_track_numberOfValidStripTIDHits;//inner detector?
   vector<int>     *tree_track_numberOfValidStripTOBHits;//outer barrel
   vector<int>     *tree_track_numberOfValidStripTECHits;// Tracker Endcap
   vector<int>     *tree_track_numberOfValidPixelBarrelHits;
   vector<int>     *tree_track_numberOfValidPixelEndcapHits;
   vector<int>     *tree_track_hasValidHitInPixelLayer;//? v�rif?
   vector<int>     *tree_track_trackerLayersWithMeasurement;
   vector<int>     *tree_track_pixelLayersWithMeasurement;//v�rif?
   vector<int>     *tree_track_stripTECLayersWithMeasurement;
   vector<int>     *tree_track_stripTIBLayersWithMeasurement;
   vector<int>     *tree_track_stripTIDLayersWithMeasurement;
   vector<int>     *tree_track_stripTOBLayersWithMeasurement;
   vector<float>   *tree_track_vx;//valeur extrapol�  par rapport � zero zero zero
   vector<float>   *tree_track_vy;
   vector<float>   *tree_track_vz;
   vector<float>   *tree_track_firsthit_X;//Quel est leur effet comme crit�re de //s�lection? x in functionof y (avec ten events sinon trop lent)
   vector<float>   *tree_track_firsthit_Y;//Draw("nameleaf_y%nameleaf_x","nameleaf") 
   vector<float>   *tree_track_firsthit_Z;
   vector<float>   *tree_track_firsthit_phi;
   vector<int>     *tree_track_simtrack_charge;
   vector<float>   *tree_track_simtrack_pt;
   vector<float>   *tree_track_simtrack_eta;
   vector<float>   *tree_track_simtrack_phi;
   vector<bool>    *tree_track_simtrack_longLived;//on sait que c'est une trace simul�, on connait sa nature (particuel)//
   vector<int>     *tree_track_simtrack_pdgId;//nature de la particule gr�ce au pdg valeurs n�gatives pour les AP, site web pdg//
   vector<int>     *tree_track_simtrack_isFromLLP;//trace reconstruite associ�e � une trace simul�e: vient ou non d'une LLP , possiblement deux neutralino donc de 0 � 2 : pourdistinguer les deux //neutralions
   vector<int>     *tree_track_simtrack_numberOfTrackerHits;//hits sim? correspond aux track IS SImMatched � 0
   vector<int>     *tree_track_simtrack_numberOfTrackerLayers;//on peut avoir deux hits dans une couche
   vector<float>   *tree_track_simtrack_mass;
   vector<int>     *tree_track_simtrack_status;//compar� les traces qui viennet du point de colliosn � d'autres traces
   vector<float>   *tree_track_genVertexPos_X;//On connait bien la position, si vient du PV, proche du pv, et si LLp, on peut retrouver le point de d�sint�gration du neutralino
   vector<float>   *tree_track_genVertexPos_Y;
   vector<float>   *tree_track_genVertexPos_Z;
   vector<int>     *tree_track_recoVertex_idx;
   vector<int>     *tree_track_recoAK4SlimmedJet_idx;//num�ro de jet associ� � cette trace : le plus efficace
   vector<int>     *tree_track_recoAK4PFJet_idx;
   vector<int>     *tree_track_reco08Jet_idx;
   vector<int>     *tree_track_recoCaloJet_idx;
   vector<double>  *tree_track_MVAval_FromDispTop;// simple BDT voir si d'autres algo sont pas meilleurs neural network and so on??
   
   //A utiliser par la suite
   vector<float>   *tree_secondaryVtx_X;//A comparer avec l'information du vrai neutralino simul�e pour voir si on reconstruit bien lesv == vertx secondaires
   vector<float>   *tree_secondaryVtx_Y;
   vector<float>   *tree_secondaryVtx_Z;
   vector<float>   *tree_secondaryVtx_diff_X;//peut �tre �a mais � v�rifier
   vector<float>   *tree_secondaryVtx_diff_Y;
   vector<float>   *tree_secondaryVtx_diff_Z;
   vector<int>     *tree_secondaryVtx_nTracks;
   vector<int>     *tree_secondaryVtx_isValid;
   vector<float>   *tree_secondaryVtx_NChi2;
   ///
   
   vector<float>   *tree_secondaryVtx_iterative_X;
   vector<float>   *tree_secondaryVtx_iterative_Y;
   vector<float>   *tree_secondaryVtx_iterative_Z;
   vector<int>     *tree_secondaryVtx_iterative_nTracks;
   vector<float>   *tree_secondaryVtx_iterative_NChi2;
   vector<bool>    *tree_secondaryVtx_iterative_isSelected;

   //Not used yet
   vector<int>     *tree_simtrack_simtrack_charge;//efficacit�de reoncutrction de straces � recalculer
   vector<float>   *tree_simtrack_simtrack_pt;//beaucoup de sitrack en desosus de 1Gev qui n'ont pas de sens
   vector<float>   *tree_simtrack_simtrack_eta;
   vector<float>   *tree_simtrack_simtrack_phi;
   vector<bool>    *tree_simtrack_simtrack_longLived;
   vector<int>     *tree_simtrack_simtrack_pdgId;
   vector<float>   *tree_simtrack_simtrack_mass;
   vector<int>     *tree_simtrack_simtrack_status;
   vector<float>   *tree_simtrack_genVertexPos_X;
   vector<float>   *tree_simtrack_genVertexPos_Y;
   vector<float>   *tree_simtrack_genVertexPos_Z;
   vector<bool>    *tree_simtrack_isRecoMatched;//simuler is matched with reconstructed
   vector<float>   *tree_simtrack_pca_dxy;//extrapoler par rapoort � zerozerozero ou au premier vertex g�n�res
   vector<float>   *tree_simtrack_pca_dz;
   //
   vector<vector<int> > *tree_simtrack_trkIdx;//?
   vector<float>   *tree_AK4Slimmedjet_E;//CElui qui nous interesse Ak4slimmed
   vector<float>   *tree_AK4Slimmedjet_pt;
   vector<float>   *tree_AK4Slimmedjet_eta;//au dela de 2.4 il y a quand même des trackeurs
   vector<float>   *tree_AK4Slimmedjet_phi;
   vector<int>     *tree_AK4Slimmedjet_idxTrack;
   
   //////////////////////////////////////////////////
   vector<float>   *tree_AK4PFjet_E;
   vector<float>   *tree_AK4PFjet_pt;
   vector<float>   *tree_AK4PFjet_eta;
   vector<float>   *tree_AK4PFjet_phi;
   vector<int>     *tree_AK4PFjet_idxTrack;
   vector<float>   *tree_CaloJet_E;
   vector<float>   *tree_CaloJet_pt;
   vector<float>   *tree_CaloJet_eta;
   vector<float>   *tree_CaloJet_phi;
   vector<int>     *tree_CaloJet_idxTrack;
   vector<float>   *tree_jet08_E;
   vector<float>   *tree_jet08_pt;
   vector<float>   *tree_jet08_eta;
   vector<float>   *tree_jet08_phi;
   vector<int>     *tree_jet08_idxTrack;
   /////////////////////////////////////////////////////
   
   vector<float>   *tree_PFMet_et;
   vector<float>   *tree_PFMet_phi;
   vector<float>   *tree_PFMet_sig;//erreur sur Et?
   vector<float>   *tree_genParticle_pt;//particle g�n�r�e != simul�e
   vector<float>   *tree_genParticle_eta;
   vector<float>   *tree_genParticle_phi;
   vector<float>   *tree_genParticle_charge;
   vector<float>   *tree_genParticle_pdgId;
   vector<float>   *tree_genParticle_vx;//parr raport � 0
   vector<float>   *tree_genParticle_vy;
   vector<float>   *tree_genParticle_vz;
   vector<float>   *tree_genParticle_mass;
   vector<int>     *tree_genParticle_statusCode;
   vector<int>     *tree_genParticle_mother_pdgId;//interessant !
   vector<float>   *tree_genParticle_mother_pt;
   vector<float>   *tree_genParticle_mother_eta;
   vector<float>   *tree_genParticle_mother_phi;
   vector<float>   *tree_genJet_pt;//� partir de la g�n�ration, on peut faire des jets, compar� gen � recosntruit
   vector<float>   *tree_genJet_eta;
   vector<float>   *tree_genJet_phi;
   vector<float>   *tree_genJet_mass;
   vector<float>   *tree_genJet_energy;
   
   ///////////////
   vector<float>   *tree_ak8GenJet_pt;
   vector<float>   *tree_ak8GenJet_eta;
   vector<float>   *tree_ak8GenJet_phi;
   vector<float>   *tree_ak8GenJet_mass;
   vector<float>   *tree_ak8GenJet_energy;
   ///////////////
   
   vector<float>   *tree_electron_pt;//zonee inefficace, cables
   vector<float>   *tree_electron_eta;
   vector<float>   *tree_electron_phi;
   vector<float>   *tree_electron_vx;//par rapport � zerozerozero
   vector<float>   *tree_electron_vy;
   vector<float>   *tree_electron_vz;
   vector<float>   *tree_electron_energy;
   vector<float>   *tree_slimmedmuon_pt;
   vector<float>   *tree_slimmedmuon_eta;
   vector<float>   *tree_slimmedmuon_phi;
   vector<float>   *tree_slimmedmuon_vx;
   vector<float>   *tree_slimmedmuon_vy;
   vector<float>   *tree_slimmedmuon_vz;
   vector<float>   *tree_slimmedmuon_energy;
   vector<float>   *tree_slimmedmuon_dxy;//par rapport au vertex primaire
   vector<float>   *tree_slimmedmuon_dxyError;
   vector<float>   *tree_slimmedmuon_dz;
   vector<float>   *tree_slimmedmuon_dzError;
   vector<float>   *tree_slimmedmuon_charge;
   vector<bool>    *tree_slimmedmuon_PFisoVeryTight;//crit�res Plusieurs m��thodes: pas sur que ces crit�res soient efficaces, � �tudier??
   vector<bool>    *tree_slimmedmuon_PFisoTight;
   vector<bool>    *tree_slimmedmuon_PFisoMedium;
   vector<bool>    *tree_slimmedmuon_PFisoLoose;
   vector<bool>    *tree_slimmedmuon_MVAisoLoose;
   vector<bool>    *tree_slimmedmuon_MVAisoMedium;
   vector<bool>    *tree_slimmedmuon_MVAisoTight;
   vector<bool>    *tree_slimmedmuon_isGlobalMuon;//recon du muon avec trajectographe et chambre � muons
   vector<bool>    *tree_slimmedmuon_isStandAloneMuon;// chambre � muons seulement, la diff�rence des deux donne le nombre de muons d�tect�s seulement dans le trajectographe
   vector<bool>    *tree_slimmedmuon_CutBasedIdLoose;//� regarder pour le futur, actuellemetn tous sotn utilis�s.
   vector<bool>    *tree_slimmedmuon_CutBasedIdMedium;
   vector<bool>    *tree_slimmedmuon_CutBasedIdMediumPrompt;
   vector<bool>    *tree_slimmedmuon_CutBasedIdTight;
   
   
   //////////////////////////////////////
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_tree_bs_PosX;   //!
   TBranch        *b_tree_bs_PosY;   //!
   TBranch        *b_tree_bs_PosZ;   //!
   TBranch        *b_tree_vtx_PosX;   //!
   TBranch        *b_tree_vtx_PosY;   //!
   TBranch        *b_tree_vtx_PosZ;   //!
   TBranch        *b_tree_vtx_NChi2;   //!
   TBranch        *b_tree_vtx_PosXError;   //!
   TBranch        *b_tree_vtx_PosYError;   //!
   TBranch        *b_tree_vtx_PosZError;   //!
   TBranch        *b_tree_trigger_names;   //!
   TBranch        *b_tree_trigger_bits;   //!
   TBranch        *b_tree_NbrOfZCand;   //!
   TBranch        *b_tree_passesHTFilter;   //!
   TBranch        *b_tree_track_pt;   //!
   TBranch        *b_tree_track_outerPt;   //!
   TBranch        *b_tree_track_eta;   //!
   TBranch        *b_tree_track_phi;   //!
   TBranch        *b_tree_track_charge;   //!
   TBranch        *b_tree_track_nhits;   //!
   TBranch        *b_tree_track_NChi2;   //!
   TBranch        *b_tree_track_isHighQuality;   //!
   TBranch        *b_tree_track_isLoose;   //!
   TBranch        *b_tree_track_isTight;   //!
   TBranch        *b_tree_track_dxy;   //!
   TBranch        *b_tree_track_dxyError;   //!
   TBranch        *b_tree_track_dz;   //!
   TBranch        *b_tree_track_dzError;   //!
   TBranch        *b_tree_track_numberOfLostHits;   //!
   TBranch        *b_tree_track_numberOfValidHits;   //!
   TBranch        *b_tree_track_originalAlgo;   //!
   TBranch        *b_tree_track_algo;   //!
   TBranch        *b_tree_track_stopReason;   //!
   TBranch        *b_tree_track_isSimMatched;   //!
   TBranch        *b_tree_track_numberOfValidPixelHits;   //!
   TBranch        *b_tree_track_numberOfValidStripHits;   //!
   TBranch        *b_tree_track_numberOfValidStripTIBHits;   //!
   TBranch        *b_tree_track_numberOfValidStripTIDHits;   //!
   TBranch        *b_tree_track_numberOfValidStripTOBHits;   //!
   TBranch        *b_tree_track_numberOfValidStripTECHits;   //!
   TBranch        *b_tree_track_numberOfValidPixelBarrelHits;   //!
   TBranch        *b_tree_track_numberOfValidPixelEndcapHits;   //!
   TBranch        *b_tree_track_hasValidHitInPixelLayer;   //!
   TBranch        *b_tree_track_trackerLayersWithMeasurement;   //!
   TBranch        *b_tree_track_pixelLayersWithMeasurement;   //!
   TBranch        *b_tree_track_stripTECLayersWithMeasurement;   //!
   TBranch        *b_tree_track_stripTIBLayersWithMeasurement;   //!
   TBranch        *b_tree_track_stripTIDLayersWithMeasurement;   //!
   TBranch        *b_tree_track_stripTOBLayersWithMeasurement;   //!
   TBranch        *b_tree_track_vx;   //!
   TBranch        *b_tree_track_vy;   //!
   TBranch        *b_tree_track_vz;   //!
   TBranch        *b_tree_track_firsthit_X;   //!
   TBranch        *b_tree_track_firsthit_Y;   //!
   TBranch        *b_tree_track_firsthit_Z;   //!
   TBranch        *b_tree_track_firsthit_phi;   //!
   TBranch        *b_tree_track_simtrack_charge;   //!
   TBranch        *b_tree_track_simtrack_pt;   //!
   TBranch        *b_tree_track_simtrack_eta;   //!
   TBranch        *b_tree_track_simtrack_phi;   //!
   TBranch        *b_tree_track_simtrack_longLived;   //!
   TBranch        *b_tree_track_simtrack_pdgId;   //!
   TBranch        *b_tree_track_simtrack_isFromLLP;   //!
   TBranch        *b_tree_track_simtrack_numberOfTrackerHits;   //!
   TBranch        *b_tree_track_simtrack_numberOfTrackerLayers;   //!
   TBranch        *b_tree_track_simtrack_mass;   //!
   TBranch        *b_tree_track_simtrack_status;   //!
   TBranch        *b_tree_track_genVertexPos_X;   //!
   TBranch        *b_tree_track_genVertexPos_Y;   //!
   TBranch        *b_tree_track_genVertexPos_Z;   //!
   TBranch        *b_tree_track_recoVertex_idx;   //!
   TBranch        *b_tree_track_recoAK4SlimmedJet_idx;   //!
   TBranch        *b_tree_track_recoAK4PFJet_idx;   //!
   TBranch        *b_tree_track_reco08Jet_idx;   //!
   TBranch        *b_tree_track_recoCaloJet_idx;   //!
   TBranch        *b_tree_track_MVAval_FromDispTop;   //!
   TBranch        *b_tree_secondaryVtx_X;   //!
   TBranch        *b_tree_secondaryVtx_Y;   //!
   TBranch        *b_tree_secondaryVtx_Z;   //!
   TBranch        *b_tree_secondaryVtx_diff_X;   //!
   TBranch        *b_tree_secondaryVtx_diff_Y;   //!
   TBranch        *b_tree_secondaryVtx_diff_Z;   //!
   TBranch        *b_tree_secondaryVtx_nTracks;   //!
   TBranch        *b_tree_secondaryVtx_isValid;   //!
   TBranch        *b_tree_secondaryVtx_NChi2;   //!
   TBranch        *b_tree_secondaryVtx_iterative_X;   //!
   TBranch        *b_tree_secondaryVtx_iterative_Y;   //!
   TBranch        *b_tree_secondaryVtx_iterative_Z;   //!
   TBranch        *b_tree_secondaryVtx_iterative_nTracks;   //!
   TBranch        *b_tree_secondaryVtx_iterative_NChi2;   //!
   TBranch        *b_tree_secondaryVtx_iterative_isSelected;   //!
   TBranch        *b_tree_simtrack_simtrack_charge;   //!
   TBranch        *b_tree_simtrack_simtrack_pt;   //!
   TBranch        *b_tree_simtrack_simtrack_eta;   //!
   TBranch        *b_tree_simtrack_simtrack_phi;   //!
   TBranch        *b_tree_simtrack_simtrack_longLived;   //!
   TBranch        *b_tree_simtrack_simtrack_pdgId;   //!
   TBranch        *b_tree_simtrack_simtrack_mass;   //!
   TBranch        *b_tree_simtrack_simtrack_status;   //!
   TBranch        *b_tree_simtrack_genVertexPos_X;   //!
   TBranch        *b_tree_simtrack_genVertexPos_Y;   //!
   TBranch        *b_tree_simtrack_genVertexPos_Z;   //!
   TBranch        *b_tree_simtrack_isRecoMatched;   //!
   TBranch        *b_tree_simtrack_pca_dxy;   //!
   TBranch        *b_tree_simtrack_pca_dz;   //!
   TBranch        *b_tree_simtrack_trkIdx;   //!
   TBranch        *b_tree_AK4Slimmedjet_E;   //!
   TBranch        *b_tree_AK4Slimmedjet_pt;   //!
   TBranch        *b_tree_AK4Slimmedjet_eta;   //!
   TBranch        *b_tree_AK4Slimmedjet_phi;   //!
   TBranch        *b_tree_AK4Slimmedjet_idxTrack;   //!
   TBranch        *b_tree_AK4PFjet_E;   //!
   TBranch        *b_tree_AK4PFjet_pt;   //!
   TBranch        *b_tree_AK4PFjet_eta;   //!
   TBranch        *b_tree_AK4PFjet_phi;   //!
   TBranch        *b_tree_AK4PFjet_idxTrack;   //!
   TBranch        *b_tree_CaloJet_E;   //!
   TBranch        *b_tree_CaloJet_pt;   //!
   TBranch        *b_tree_CaloJet_eta;   //!
   TBranch        *b_tree_CaloJet_phi;   //!
   TBranch        *b_tree_CaloJet_idxTrack;   //!
   TBranch        *b_tree_jet08_E;   //!
   TBranch        *b_tree_jet08_pt;   //!
   TBranch        *b_tree_jet08_eta;   //!
   TBranch        *b_tree_jet08_phi;   //!
   TBranch        *b_tree_jet08_idxTrack;   //!
   TBranch        *b_tree_PFMet_et;   //!
   TBranch        *b_tree_PFMet_phi;   //!
   TBranch        *b_tree_PFMet_sig;   //!
   TBranch        *b_tree_genParticle_pt;   //!
   TBranch        *b_tree_genParticle_eta;   //!
   TBranch        *b_tree_genParticle_phi;   //!
   TBranch        *b_tree_genParticle_charge;   //!
   TBranch        *b_tree_genParticle_pdgId;   //!
   TBranch        *b_tree_genParticle_vx;   //!
   TBranch        *b_tree_genParticle_vy;   //!
   TBranch        *b_tree_genParticle_vz;   //!
   TBranch        *b_tree_genParticle_mass;   //!
   TBranch        *b_tree_genParticle_statusCode;   //!
   TBranch        *b_tree_genParticle_mother_pdgId;   //!
   TBranch        *b_tree_genParticle_mother_pt;   //!
   TBranch        *b_tree_genParticle_mother_eta;   //!
   TBranch        *b_tree_genParticle_mother_phi;   //!
   TBranch        *b_tree_genJet_pt;   //!
   TBranch        *b_tree_genJet_eta;   //!
   TBranch        *b_tree_genJet_phi;   //!
   TBranch        *b_tree_genJet_mass;   //!
   TBranch        *b_tree_genJet_energy;   //!
   TBranch        *b_tree_ak8GenJet_pt;   //!
   TBranch        *b_tree_ak8GenJet_eta;   //!
   TBranch        *b_tree_ak8GenJet_phi;   //!
   TBranch        *b_tree_ak8GenJet_mass;   //!
   TBranch        *b_tree_ak8GenJet_energy;   //!
   TBranch        *b_tree_electron_pt;   //!
   TBranch        *b_tree_electron_eta;   //!
   TBranch        *b_tree_electron_phi;   //!
   TBranch        *b_tree_electron_vx;   //!
   TBranch        *b_tree_electron_vy;   //!
   TBranch        *b_tree_electron_vz;   //!
   TBranch        *b_tree_electron_energy;   //!
   TBranch        *b_tree_slimmedmuon_pt;   //!
   TBranch        *b_tree_slimmedmuon_eta;   //!
   TBranch        *b_tree_slimmedmuon_phi;   //!
   TBranch        *b_tree_slimmedmuon_vx;   //!
   TBranch        *b_tree_slimmedmuon_vy;   //!
   TBranch        *b_tree_slimmedmuon_vz;   //!
   TBranch        *b_tree_slimmedmuon_energy;   //!
   TBranch        *b_tree_slimmedmuon_dxy;   //!
   TBranch        *b_tree_slimmedmuon_dxyError;   //!
   TBranch        *b_tree_slimmedmuon_dz;   //!
   TBranch        *b_tree_slimmedmuon_dzError;   //!
   TBranch        *b_tree_slimmedmuon_charge;   //!
   TBranch        *b_tree_slimmedmuon_PFisoVeryTight;   //!
   TBranch        *b_tree_slimmedmuon_PFisoTight;   //!
   TBranch        *b_tree_slimmedmuon_PFisoMedium;   //!
   TBranch        *b_tree_slimmedmuon_PFisoLoose;   //!
   TBranch        *b_tree_slimmedmuon_MVAisoLoose;   //!
   TBranch        *b_tree_slimmedmuon_MVAisoMedium;   //!
   TBranch        *b_tree_slimmedmuon_MVAisoTight;   //!
   TBranch        *b_tree_slimmedmuon_isGlobalMuon;   //!
   TBranch        *b_tree_slimmedmuon_isStandAloneMuon;   //!
   TBranch        *b_tree_slimmedmuon_CutBasedIdLoose;   //!
   TBranch        *b_tree_slimmedmuon_CutBasedIdMedium;   //!
   TBranch        *b_tree_slimmedmuon_CutBasedIdMediumPrompt;   //!
   TBranch        *b_tree_slimmedmuon_CutBasedIdTight;   //!

   LLTopTree(TTree *tree=0);
   virtual ~LLTopTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
//$$
//$$   virtual void   Loop();
   virtual void   Loop(Int_t    aNN = 0, 
                  Float_t  aTagCut = 0.01, 
                  Float_t  aPtMin = 20., 
                  Float_t  aPtMax = 1000., 
                  Float_t  aEtaMin = 0., 
                  Float_t  aEtaMax = 10., 
                  Float_t  aFreeCut = 0., 
                  Int_t    aIntCut = 0, 
                  TString  afilename = "output.root");
//$$
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LLTopTree_cxx
LLTopTree::LLTopTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("UDD_bgctau30_smu300_snu250.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("UDD_bgctau30_smu300_snu250.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("UDD_bgctau30_smu300_snu250.root:/trackingPerf");
      dir->GetObject("ttree",tree);

   }
   Init(tree);
}

LLTopTree::~LLTopTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LLTopTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LLTopTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LLTopTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   tree_vtx_PosX = 0;
   tree_vtx_PosY = 0;
   tree_vtx_PosZ = 0;
   tree_vtx_NChi2 = 0;
   tree_vtx_PosXError = 0;
   tree_vtx_PosYError = 0;
   tree_vtx_PosZError = 0;
   tree_trigger_names = 0;
   tree_trigger_bits = 0;
   tree_passesHTFilter = 0;
   tree_track_pt = 0;
   tree_track_outerPt = 0;
   tree_track_eta = 0;
   tree_track_phi = 0;
   tree_track_charge = 0;
   tree_track_nhits = 0;
   tree_track_NChi2 = 0;
   tree_track_isHighQuality = 0;
   tree_track_isLoose = 0;
   tree_track_isTight = 0;
   tree_track_dxy = 0;
   tree_track_dxyError = 0;
   tree_track_dz = 0;
   tree_track_dzError = 0;
   tree_track_numberOfLostHits = 0;
   tree_track_numberOfValidHits = 0;
   tree_track_originalAlgo = 0;
   tree_track_algo = 0;
   tree_track_stopReason = 0;
   tree_track_isSimMatched = 0;
   tree_track_numberOfValidPixelHits = 0;
   tree_track_numberOfValidStripHits = 0;
   tree_track_numberOfValidStripTIBHits = 0;
   tree_track_numberOfValidStripTIDHits = 0;
   tree_track_numberOfValidStripTOBHits = 0;
   tree_track_numberOfValidStripTECHits = 0;
   tree_track_numberOfValidPixelBarrelHits = 0;
   tree_track_numberOfValidPixelEndcapHits = 0;
   tree_track_hasValidHitInPixelLayer = 0;
   tree_track_trackerLayersWithMeasurement = 0;
   tree_track_pixelLayersWithMeasurement = 0;
   tree_track_stripTECLayersWithMeasurement = 0;
   tree_track_stripTIBLayersWithMeasurement = 0;
   tree_track_stripTIDLayersWithMeasurement = 0;
   tree_track_stripTOBLayersWithMeasurement = 0;
   tree_track_vx = 0;
   tree_track_vy = 0;
   tree_track_vz = 0;
   tree_track_firsthit_X = 0;
   tree_track_firsthit_Y = 0;
   tree_track_firsthit_Z = 0;
   tree_track_firsthit_phi = 0;
   
   tree_track_simtrack_charge = 0;
   tree_track_simtrack_pt = 0;
   tree_track_simtrack_eta = 0;
   tree_track_simtrack_phi = 0;
   tree_track_simtrack_longLived = 0;
   tree_track_simtrack_pdgId = 0;
   tree_track_simtrack_isFromLLP = 0;
   tree_track_simtrack_numberOfTrackerHits = 0;
   tree_track_simtrack_numberOfTrackerLayers = 0;
   tree_track_simtrack_mass = 0;
   tree_track_simtrack_status = 0;
   
   tree_track_genVertexPos_X = 0;
   tree_track_genVertexPos_Y = 0;
   tree_track_genVertexPos_Z = 0;
   tree_track_recoVertex_idx = 0;
   tree_track_recoAK4SlimmedJet_idx = 0;
   tree_track_recoAK4PFJet_idx = 0;
   tree_track_reco08Jet_idx = 0;
   tree_track_recoCaloJet_idx = 0;
   tree_track_MVAval_FromDispTop = 0;
   tree_secondaryVtx_X = 0;
   tree_secondaryVtx_Y = 0;
   tree_secondaryVtx_Z = 0;
   tree_secondaryVtx_diff_X = 0;
   tree_secondaryVtx_diff_Y = 0;
   tree_secondaryVtx_diff_Z = 0;
   tree_secondaryVtx_nTracks = 0;
   tree_secondaryVtx_isValid = 0;
   tree_secondaryVtx_NChi2 = 0;
   tree_secondaryVtx_iterative_X = 0;
   tree_secondaryVtx_iterative_Y = 0;
   tree_secondaryVtx_iterative_Z = 0;
   tree_secondaryVtx_iterative_nTracks = 0;
   tree_secondaryVtx_iterative_NChi2 = 0;
   tree_secondaryVtx_iterative_isSelected = 0;
   
   ///Not used tree_simtrack
   tree_simtrack_simtrack_charge = 0;
   tree_simtrack_simtrack_pt = 0;
   tree_simtrack_simtrack_eta = 0;
   tree_simtrack_simtrack_phi = 0;
   tree_simtrack_simtrack_longLived = 0;
   tree_simtrack_simtrack_pdgId = 0;
   tree_simtrack_simtrack_mass = 0;
   tree_simtrack_simtrack_status = 0;
   tree_simtrack_genVertexPos_X = 0;
   tree_simtrack_genVertexPos_Y = 0;
   tree_simtrack_genVertexPos_Z = 0;
   tree_simtrack_isRecoMatched = 0;
   tree_simtrack_pca_dxy = 0;
   tree_simtrack_pca_dz = 0;
   tree_simtrack_trkIdx = 0;
   ////////////
   tree_AK4Slimmedjet_E = 0;
   tree_AK4Slimmedjet_pt = 0;
   tree_AK4Slimmedjet_eta = 0;
   tree_AK4Slimmedjet_phi = 0;
   tree_AK4Slimmedjet_idxTrack = 0;
   tree_AK4PFjet_E = 0;
   tree_AK4PFjet_pt = 0;
   tree_AK4PFjet_eta = 0;
   tree_AK4PFjet_phi = 0;
   tree_AK4PFjet_idxTrack = 0;
   tree_CaloJet_E = 0;
   tree_CaloJet_pt = 0;
   tree_CaloJet_eta = 0;
   tree_CaloJet_phi = 0;
   tree_CaloJet_idxTrack = 0;
   tree_jet08_E = 0;
   tree_jet08_pt = 0;
   tree_jet08_eta = 0;
   tree_jet08_phi = 0;
   tree_jet08_idxTrack = 0;
   tree_PFMet_et = 0;
   tree_PFMet_phi = 0;
   tree_PFMet_sig = 0;
   tree_genParticle_pt = 0;
   tree_genParticle_eta = 0;
   tree_genParticle_phi = 0;
   tree_genParticle_charge = 0;
   tree_genParticle_pdgId = 0;
   tree_genParticle_vx = 0;
   tree_genParticle_vy = 0;
   tree_genParticle_vz = 0;
   tree_genParticle_mass = 0;
   tree_genParticle_statusCode = 0;
   tree_genParticle_mother_pdgId = 0;
   tree_genParticle_mother_pt = 0;
   tree_genParticle_mother_eta = 0;
   tree_genParticle_mother_phi = 0;
   tree_genJet_pt = 0;
   tree_genJet_eta = 0;
   tree_genJet_phi = 0;
   tree_genJet_mass = 0;
   tree_genJet_energy = 0;
   tree_ak8GenJet_pt = 0;
   tree_ak8GenJet_eta = 0;
   tree_ak8GenJet_phi = 0;
   tree_ak8GenJet_mass = 0;
   tree_ak8GenJet_energy = 0;
   tree_electron_pt = 0;
   tree_electron_eta = 0;
   tree_electron_phi = 0;
   tree_electron_vx = 0;
   tree_electron_vy = 0;
   tree_electron_vz = 0;
   tree_electron_energy = 0;
   tree_slimmedmuon_pt = 0;
   tree_slimmedmuon_eta = 0;
   tree_slimmedmuon_phi = 0;
   tree_slimmedmuon_vx = 0;
   tree_slimmedmuon_vy = 0;
   tree_slimmedmuon_vz = 0;
   tree_slimmedmuon_energy = 0;
   tree_slimmedmuon_dxy = 0;
   tree_slimmedmuon_dxyError = 0;
   tree_slimmedmuon_dz = 0;
   tree_slimmedmuon_dzError = 0;
   tree_slimmedmuon_charge = 0;
   tree_slimmedmuon_PFisoVeryTight = 0;
   tree_slimmedmuon_PFisoTight = 0;
   tree_slimmedmuon_PFisoMedium = 0;
   tree_slimmedmuon_PFisoLoose = 0;
   tree_slimmedmuon_MVAisoLoose = 0;
   tree_slimmedmuon_MVAisoMedium = 0;
   tree_slimmedmuon_MVAisoTight = 0;
   tree_slimmedmuon_isGlobalMuon = 0;
   tree_slimmedmuon_isStandAloneMuon = 0;
   tree_slimmedmuon_CutBasedIdLoose = 0;
   tree_slimmedmuon_CutBasedIdMedium = 0;
   tree_slimmedmuon_CutBasedIdMediumPrompt = 0;
   tree_slimmedmuon_CutBasedIdTight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("tree_bs_PosX", &tree_bs_PosX, &b_tree_bs_PosX);
   fChain->SetBranchAddress("tree_bs_PosY", &tree_bs_PosY, &b_tree_bs_PosY);
   fChain->SetBranchAddress("tree_bs_PosZ", &tree_bs_PosZ, &b_tree_bs_PosZ);
   fChain->SetBranchAddress("tree_vtx_PosX", &tree_vtx_PosX, &b_tree_vtx_PosX);
   fChain->SetBranchAddress("tree_vtx_PosY", &tree_vtx_PosY, &b_tree_vtx_PosY);
   fChain->SetBranchAddress("tree_vtx_PosZ", &tree_vtx_PosZ, &b_tree_vtx_PosZ);
   fChain->SetBranchAddress("tree_vtx_NChi2", &tree_vtx_NChi2, &b_tree_vtx_NChi2);
   fChain->SetBranchAddress("tree_vtx_PosXError", &tree_vtx_PosXError, &b_tree_vtx_PosXError);
   fChain->SetBranchAddress("tree_vtx_PosYError", &tree_vtx_PosYError, &b_tree_vtx_PosYError);
   fChain->SetBranchAddress("tree_vtx_PosZError", &tree_vtx_PosZError, &b_tree_vtx_PosZError);
   fChain->SetBranchAddress("tree_trigger_names", &tree_trigger_names, &b_tree_trigger_names);
   fChain->SetBranchAddress("tree_trigger_bits", &tree_trigger_bits, &b_tree_trigger_bits);
   fChain->SetBranchAddress("tree_NbrOfZCand", &tree_NbrOfZCand, &b_tree_NbrOfZCand);
   fChain->SetBranchAddress("tree_passesHTFilter", &tree_passesHTFilter, &b_tree_passesHTFilter);
   fChain->SetBranchAddress("tree_track_pt", &tree_track_pt, &b_tree_track_pt);
   fChain->SetBranchAddress("tree_track_outerPt", &tree_track_outerPt, &b_tree_track_outerPt);
   fChain->SetBranchAddress("tree_track_eta", &tree_track_eta, &b_tree_track_eta);
   fChain->SetBranchAddress("tree_track_phi", &tree_track_phi, &b_tree_track_phi);
   fChain->SetBranchAddress("tree_track_charge", &tree_track_charge, &b_tree_track_charge);
   fChain->SetBranchAddress("tree_track_nhits", &tree_track_nhits, &b_tree_track_nhits);
   fChain->SetBranchAddress("tree_track_NChi2", &tree_track_NChi2, &b_tree_track_NChi2);
   fChain->SetBranchAddress("tree_track_isHighQuality", &tree_track_isHighQuality, &b_tree_track_isHighQuality);
   fChain->SetBranchAddress("tree_track_isLoose", &tree_track_isLoose, &b_tree_track_isLoose);
   fChain->SetBranchAddress("tree_track_isTight", &tree_track_isTight, &b_tree_track_isTight);
   fChain->SetBranchAddress("tree_track_dxy", &tree_track_dxy, &b_tree_track_dxy);
   fChain->SetBranchAddress("tree_track_dxyError", &tree_track_dxyError, &b_tree_track_dxyError);
   fChain->SetBranchAddress("tree_track_dz", &tree_track_dz, &b_tree_track_dz);
   fChain->SetBranchAddress("tree_track_dzError", &tree_track_dzError, &b_tree_track_dzError);
   fChain->SetBranchAddress("tree_track_numberOfLostHits", &tree_track_numberOfLostHits, &b_tree_track_numberOfLostHits);
   fChain->SetBranchAddress("tree_track_numberOfValidHits", &tree_track_numberOfValidHits, &b_tree_track_numberOfValidHits);
   fChain->SetBranchAddress("tree_track_originalAlgo", &tree_track_originalAlgo, &b_tree_track_originalAlgo);
   fChain->SetBranchAddress("tree_track_algo", &tree_track_algo, &b_tree_track_algo);
   fChain->SetBranchAddress("tree_track_stopReason", &tree_track_stopReason, &b_tree_track_stopReason);
   fChain->SetBranchAddress("tree_track_isSimMatched", &tree_track_isSimMatched, &b_tree_track_isSimMatched);
   fChain->SetBranchAddress("tree_track_numberOfValidPixelHits", &tree_track_numberOfValidPixelHits, &b_tree_track_numberOfValidPixelHits);
   fChain->SetBranchAddress("tree_track_numberOfValidStripHits", &tree_track_numberOfValidStripHits, &b_tree_track_numberOfValidStripHits);
   fChain->SetBranchAddress("tree_track_numberOfValidStripTIBHits", &tree_track_numberOfValidStripTIBHits, &b_tree_track_numberOfValidStripTIBHits);
   fChain->SetBranchAddress("tree_track_numberOfValidStripTIDHits", &tree_track_numberOfValidStripTIDHits, &b_tree_track_numberOfValidStripTIDHits);
   fChain->SetBranchAddress("tree_track_numberOfValidStripTOBHits", &tree_track_numberOfValidStripTOBHits, &b_tree_track_numberOfValidStripTOBHits);
   fChain->SetBranchAddress("tree_track_numberOfValidStripTECHits", &tree_track_numberOfValidStripTECHits, &b_tree_track_numberOfValidStripTECHits);
   fChain->SetBranchAddress("tree_track_numberOfValidPixelBarrelHits", &tree_track_numberOfValidPixelBarrelHits, &b_tree_track_numberOfValidPixelBarrelHits);
   fChain->SetBranchAddress("tree_track_numberOfValidPixelEndcapHits", &tree_track_numberOfValidPixelEndcapHits, &b_tree_track_numberOfValidPixelEndcapHits);
   fChain->SetBranchAddress("tree_track_hasValidHitInPixelLayer", &tree_track_hasValidHitInPixelLayer, &b_tree_track_hasValidHitInPixelLayer);
   fChain->SetBranchAddress("tree_track_trackerLayersWithMeasurement", &tree_track_trackerLayersWithMeasurement, &b_tree_track_trackerLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_pixelLayersWithMeasurement", &tree_track_pixelLayersWithMeasurement, &b_tree_track_pixelLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_stripTECLayersWithMeasurement", &tree_track_stripTECLayersWithMeasurement, &b_tree_track_stripTECLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_stripTIBLayersWithMeasurement", &tree_track_stripTIBLayersWithMeasurement, &b_tree_track_stripTIBLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_stripTIDLayersWithMeasurement", &tree_track_stripTIDLayersWithMeasurement, &b_tree_track_stripTIDLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_stripTOBLayersWithMeasurement", &tree_track_stripTOBLayersWithMeasurement, &b_tree_track_stripTOBLayersWithMeasurement);
   fChain->SetBranchAddress("tree_track_vx", &tree_track_vx, &b_tree_track_vx);
   fChain->SetBranchAddress("tree_track_vy", &tree_track_vy, &b_tree_track_vy);
   fChain->SetBranchAddress("tree_track_vz", &tree_track_vz, &b_tree_track_vz);
   fChain->SetBranchAddress("tree_track_firsthit_X", &tree_track_firsthit_X, &b_tree_track_firsthit_X);
   fChain->SetBranchAddress("tree_track_firsthit_Y", &tree_track_firsthit_Y, &b_tree_track_firsthit_Y);
   fChain->SetBranchAddress("tree_track_firsthit_Z", &tree_track_firsthit_Z, &b_tree_track_firsthit_Z);
   fChain->SetBranchAddress("tree_track_firsthit_phi", &tree_track_firsthit_phi, &b_tree_track_firsthit_phi);
   fChain->SetBranchAddress("tree_track_simtrack_charge", &tree_track_simtrack_charge, &b_tree_track_simtrack_charge);
   fChain->SetBranchAddress("tree_track_simtrack_pt", &tree_track_simtrack_pt, &b_tree_track_simtrack_pt);
   fChain->SetBranchAddress("tree_track_simtrack_eta", &tree_track_simtrack_eta, &b_tree_track_simtrack_eta);
   fChain->SetBranchAddress("tree_track_simtrack_phi", &tree_track_simtrack_phi, &b_tree_track_simtrack_phi);
   fChain->SetBranchAddress("tree_track_simtrack_longLived", &tree_track_simtrack_longLived, &b_tree_track_simtrack_longLived);
   fChain->SetBranchAddress("tree_track_simtrack_pdgId", &tree_track_simtrack_pdgId, &b_tree_track_simtrack_pdgId);
   fChain->SetBranchAddress("tree_track_simtrack_isFromLLP", &tree_track_simtrack_isFromLLP, &b_tree_track_simtrack_isFromLLP);
   fChain->SetBranchAddress("tree_track_simtrack_numberOfTrackerHits", &tree_track_simtrack_numberOfTrackerHits, &b_tree_track_simtrack_numberOfTrackerHits);
   fChain->SetBranchAddress("tree_track_simtrack_numberOfTrackerLayers", &tree_track_simtrack_numberOfTrackerLayers, &b_tree_track_simtrack_numberOfTrackerLayers);
   fChain->SetBranchAddress("tree_track_simtrack_mass", &tree_track_simtrack_mass, &b_tree_track_simtrack_mass);
   fChain->SetBranchAddress("tree_track_simtrack_status", &tree_track_simtrack_status, &b_tree_track_simtrack_status);
   fChain->SetBranchAddress("tree_track_genVertexPos_X", &tree_track_genVertexPos_X, &b_tree_track_genVertexPos_X);
   fChain->SetBranchAddress("tree_track_genVertexPos_Y", &tree_track_genVertexPos_Y, &b_tree_track_genVertexPos_Y);
   fChain->SetBranchAddress("tree_track_genVertexPos_Z", &tree_track_genVertexPos_Z, &b_tree_track_genVertexPos_Z);
   fChain->SetBranchAddress("tree_track_recoVertex_idx", &tree_track_recoVertex_idx, &b_tree_track_recoVertex_idx);
   fChain->SetBranchAddress("tree_track_recoAK4SlimmedJet_idx", &tree_track_recoAK4SlimmedJet_idx, &b_tree_track_recoAK4SlimmedJet_idx);
   fChain->SetBranchAddress("tree_track_recoAK4PFJet_idx", &tree_track_recoAK4PFJet_idx, &b_tree_track_recoAK4PFJet_idx);
   fChain->SetBranchAddress("tree_track_reco08Jet_idx", &tree_track_reco08Jet_idx, &b_tree_track_reco08Jet_idx);
   fChain->SetBranchAddress("tree_track_recoCaloJet_idx", &tree_track_recoCaloJet_idx, &b_tree_track_recoCaloJet_idx);
   fChain->SetBranchAddress("tree_track_MVAval_FromDispTop", &tree_track_MVAval_FromDispTop, &b_tree_track_MVAval_FromDispTop);
   fChain->SetBranchAddress("tree_secondaryVtx_X", &tree_secondaryVtx_X, &b_tree_secondaryVtx_X);
   fChain->SetBranchAddress("tree_secondaryVtx_Y", &tree_secondaryVtx_Y, &b_tree_secondaryVtx_Y);
   fChain->SetBranchAddress("tree_secondaryVtx_Z", &tree_secondaryVtx_Z, &b_tree_secondaryVtx_Z);
   fChain->SetBranchAddress("tree_secondaryVtx_diff_X", &tree_secondaryVtx_diff_X, &b_tree_secondaryVtx_diff_X);
   fChain->SetBranchAddress("tree_secondaryVtx_diff_Y", &tree_secondaryVtx_diff_Y, &b_tree_secondaryVtx_diff_Y);
   fChain->SetBranchAddress("tree_secondaryVtx_diff_Z", &tree_secondaryVtx_diff_Z, &b_tree_secondaryVtx_diff_Z);
   fChain->SetBranchAddress("tree_secondaryVtx_nTracks", &tree_secondaryVtx_nTracks, &b_tree_secondaryVtx_nTracks);
   fChain->SetBranchAddress("tree_secondaryVtx_isValid", &tree_secondaryVtx_isValid, &b_tree_secondaryVtx_isValid);
   fChain->SetBranchAddress("tree_secondaryVtx_NChi2", &tree_secondaryVtx_NChi2, &b_tree_secondaryVtx_NChi2);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_X", &tree_secondaryVtx_iterative_X, &b_tree_secondaryVtx_iterative_X);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_Y", &tree_secondaryVtx_iterative_Y, &b_tree_secondaryVtx_iterative_Y);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_Z", &tree_secondaryVtx_iterative_Z, &b_tree_secondaryVtx_iterative_Z);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_nTracks", &tree_secondaryVtx_iterative_nTracks, &b_tree_secondaryVtx_iterative_nTracks);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_NChi2", &tree_secondaryVtx_iterative_NChi2, &b_tree_secondaryVtx_iterative_NChi2);
   fChain->SetBranchAddress("tree_secondaryVtx_iterative_isSelected", &tree_secondaryVtx_iterative_isSelected, &b_tree_secondaryVtx_iterative_isSelected);
   fChain->SetBranchAddress("tree_simtrack_simtrack_charge", &tree_simtrack_simtrack_charge, &b_tree_simtrack_simtrack_charge);
   fChain->SetBranchAddress("tree_simtrack_simtrack_pt", &tree_simtrack_simtrack_pt, &b_tree_simtrack_simtrack_pt);
   fChain->SetBranchAddress("tree_simtrack_simtrack_eta", &tree_simtrack_simtrack_eta, &b_tree_simtrack_simtrack_eta);
   fChain->SetBranchAddress("tree_simtrack_simtrack_phi", &tree_simtrack_simtrack_phi, &b_tree_simtrack_simtrack_phi);
   fChain->SetBranchAddress("tree_simtrack_simtrack_longLived", &tree_simtrack_simtrack_longLived, &b_tree_simtrack_simtrack_longLived);
   fChain->SetBranchAddress("tree_simtrack_simtrack_pdgId", &tree_simtrack_simtrack_pdgId, &b_tree_simtrack_simtrack_pdgId);
   fChain->SetBranchAddress("tree_simtrack_simtrack_mass", &tree_simtrack_simtrack_mass, &b_tree_simtrack_simtrack_mass);
   fChain->SetBranchAddress("tree_simtrack_simtrack_status", &tree_simtrack_simtrack_status, &b_tree_simtrack_simtrack_status);
   fChain->SetBranchAddress("tree_simtrack_genVertexPos_X", &tree_simtrack_genVertexPos_X, &b_tree_simtrack_genVertexPos_X);
   fChain->SetBranchAddress("tree_simtrack_genVertexPos_Y", &tree_simtrack_genVertexPos_Y, &b_tree_simtrack_genVertexPos_Y);
   fChain->SetBranchAddress("tree_simtrack_genVertexPos_Z", &tree_simtrack_genVertexPos_Z, &b_tree_simtrack_genVertexPos_Z);
   fChain->SetBranchAddress("tree_simtrack_isRecoMatched", &tree_simtrack_isRecoMatched, &b_tree_simtrack_isRecoMatched);
   fChain->SetBranchAddress("tree_simtrack_pca_dxy", &tree_simtrack_pca_dxy, &b_tree_simtrack_pca_dxy);
   fChain->SetBranchAddress("tree_simtrack_pca_dz", &tree_simtrack_pca_dz, &b_tree_simtrack_pca_dz);
   fChain->SetBranchAddress("tree_simtrack_trkIdx", &tree_simtrack_trkIdx, &b_tree_simtrack_trkIdx);
   fChain->SetBranchAddress("tree_AK4Slimmedjet_E", &tree_AK4Slimmedjet_E, &b_tree_AK4Slimmedjet_E);
   fChain->SetBranchAddress("tree_AK4Slimmedjet_pt", &tree_AK4Slimmedjet_pt, &b_tree_AK4Slimmedjet_pt);
   fChain->SetBranchAddress("tree_AK4Slimmedjet_eta", &tree_AK4Slimmedjet_eta, &b_tree_AK4Slimmedjet_eta);
   fChain->SetBranchAddress("tree_AK4Slimmedjet_phi", &tree_AK4Slimmedjet_phi, &b_tree_AK4Slimmedjet_phi);
   fChain->SetBranchAddress("tree_AK4Slimmedjet_idxTrack", &tree_AK4Slimmedjet_idxTrack, &b_tree_AK4Slimmedjet_idxTrack);
   fChain->SetBranchAddress("tree_AK4PFjet_E", &tree_AK4PFjet_E, &b_tree_AK4PFjet_E);
   fChain->SetBranchAddress("tree_AK4PFjet_pt", &tree_AK4PFjet_pt, &b_tree_AK4PFjet_pt);
   fChain->SetBranchAddress("tree_AK4PFjet_eta", &tree_AK4PFjet_eta, &b_tree_AK4PFjet_eta);
   fChain->SetBranchAddress("tree_AK4PFjet_phi", &tree_AK4PFjet_phi, &b_tree_AK4PFjet_phi);
   fChain->SetBranchAddress("tree_AK4PFjet_idxTrack", &tree_AK4PFjet_idxTrack, &b_tree_AK4PFjet_idxTrack);
   fChain->SetBranchAddress("tree_CaloJet_E", &tree_CaloJet_E, &b_tree_CaloJet_E);
   fChain->SetBranchAddress("tree_CaloJet_pt", &tree_CaloJet_pt, &b_tree_CaloJet_pt);
   fChain->SetBranchAddress("tree_CaloJet_eta", &tree_CaloJet_eta, &b_tree_CaloJet_eta);
   fChain->SetBranchAddress("tree_CaloJet_phi", &tree_CaloJet_phi, &b_tree_CaloJet_phi);
   fChain->SetBranchAddress("tree_CaloJet_idxTrack", &tree_CaloJet_idxTrack, &b_tree_CaloJet_idxTrack);
   fChain->SetBranchAddress("tree_jet08_E", &tree_jet08_E, &b_tree_jet08_E);
   fChain->SetBranchAddress("tree_jet08_pt", &tree_jet08_pt, &b_tree_jet08_pt);
   fChain->SetBranchAddress("tree_jet08_eta", &tree_jet08_eta, &b_tree_jet08_eta);
   fChain->SetBranchAddress("tree_jet08_phi", &tree_jet08_phi, &b_tree_jet08_phi);
   fChain->SetBranchAddress("tree_jet08_idxTrack", &tree_jet08_idxTrack, &b_tree_jet08_idxTrack);
   fChain->SetBranchAddress("tree_PFMet_et", &tree_PFMet_et, &b_tree_PFMet_et);
   fChain->SetBranchAddress("tree_PFMet_phi", &tree_PFMet_phi, &b_tree_PFMet_phi);
   fChain->SetBranchAddress("tree_PFMet_sig", &tree_PFMet_sig, &b_tree_PFMet_sig);
   fChain->SetBranchAddress("tree_genParticle_pt", &tree_genParticle_pt, &b_tree_genParticle_pt);
   fChain->SetBranchAddress("tree_genParticle_eta", &tree_genParticle_eta, &b_tree_genParticle_eta);
   fChain->SetBranchAddress("tree_genParticle_phi", &tree_genParticle_phi, &b_tree_genParticle_phi);
   fChain->SetBranchAddress("tree_genParticle_charge", &tree_genParticle_charge, &b_tree_genParticle_charge);
   fChain->SetBranchAddress("tree_genParticle_pdgId", &tree_genParticle_pdgId, &b_tree_genParticle_pdgId);
   fChain->SetBranchAddress("tree_genParticle_vx", &tree_genParticle_vx, &b_tree_genParticle_vx);
   fChain->SetBranchAddress("tree_genParticle_vy", &tree_genParticle_vy, &b_tree_genParticle_vy);
   fChain->SetBranchAddress("tree_genParticle_vz", &tree_genParticle_vz, &b_tree_genParticle_vz);
   fChain->SetBranchAddress("tree_genParticle_mass", &tree_genParticle_mass, &b_tree_genParticle_mass);
   fChain->SetBranchAddress("tree_genParticle_statusCode", &tree_genParticle_statusCode, &b_tree_genParticle_statusCode);
   fChain->SetBranchAddress("tree_genParticle_mother_pdgId", &tree_genParticle_mother_pdgId, &b_tree_genParticle_mother_pdgId);
   fChain->SetBranchAddress("tree_genParticle_mother_pt", &tree_genParticle_mother_pt, &b_tree_genParticle_mother_pt);
   fChain->SetBranchAddress("tree_genParticle_mother_eta", &tree_genParticle_mother_eta, &b_tree_genParticle_mother_eta);
   fChain->SetBranchAddress("tree_genParticle_mother_phi", &tree_genParticle_mother_phi, &b_tree_genParticle_mother_phi);
   fChain->SetBranchAddress("tree_genJet_pt", &tree_genJet_pt, &b_tree_genJet_pt);
   fChain->SetBranchAddress("tree_genJet_eta", &tree_genJet_eta, &b_tree_genJet_eta);
   fChain->SetBranchAddress("tree_genJet_phi", &tree_genJet_phi, &b_tree_genJet_phi);
   fChain->SetBranchAddress("tree_genJet_mass", &tree_genJet_mass, &b_tree_genJet_mass);
   fChain->SetBranchAddress("tree_genJet_energy", &tree_genJet_energy, &b_tree_genJet_energy);
   fChain->SetBranchAddress("tree_ak8GenJet_pt", &tree_ak8GenJet_pt, &b_tree_ak8GenJet_pt);
   fChain->SetBranchAddress("tree_ak8GenJet_eta", &tree_ak8GenJet_eta, &b_tree_ak8GenJet_eta);
   fChain->SetBranchAddress("tree_ak8GenJet_phi", &tree_ak8GenJet_phi, &b_tree_ak8GenJet_phi);
   fChain->SetBranchAddress("tree_ak8GenJet_mass", &tree_ak8GenJet_mass, &b_tree_ak8GenJet_mass);
   fChain->SetBranchAddress("tree_ak8GenJet_energy", &tree_ak8GenJet_energy, &b_tree_ak8GenJet_energy);
   fChain->SetBranchAddress("tree_electron_pt", &tree_electron_pt, &b_tree_electron_pt);
   fChain->SetBranchAddress("tree_electron_eta", &tree_electron_eta, &b_tree_electron_eta);
   fChain->SetBranchAddress("tree_electron_phi", &tree_electron_phi, &b_tree_electron_phi);
   fChain->SetBranchAddress("tree_electron_vx", &tree_electron_vx, &b_tree_electron_vx);
   fChain->SetBranchAddress("tree_electron_vy", &tree_electron_vy, &b_tree_electron_vy);
   fChain->SetBranchAddress("tree_electron_vz", &tree_electron_vz, &b_tree_electron_vz);
   fChain->SetBranchAddress("tree_electron_energy", &tree_electron_energy, &b_tree_electron_energy);
   fChain->SetBranchAddress("tree_slimmedmuon_pt", &tree_slimmedmuon_pt, &b_tree_slimmedmuon_pt);
   fChain->SetBranchAddress("tree_slimmedmuon_eta", &tree_slimmedmuon_eta, &b_tree_slimmedmuon_eta);
   fChain->SetBranchAddress("tree_slimmedmuon_phi", &tree_slimmedmuon_phi, &b_tree_slimmedmuon_phi);
   fChain->SetBranchAddress("tree_slimmedmuon_vx", &tree_slimmedmuon_vx, &b_tree_slimmedmuon_vx);
   fChain->SetBranchAddress("tree_slimmedmuon_vy", &tree_slimmedmuon_vy, &b_tree_slimmedmuon_vy);
   fChain->SetBranchAddress("tree_slimmedmuon_vz", &tree_slimmedmuon_vz, &b_tree_slimmedmuon_vz);
   fChain->SetBranchAddress("tree_slimmedmuon_energy", &tree_slimmedmuon_energy, &b_tree_slimmedmuon_energy);
   fChain->SetBranchAddress("tree_slimmedmuon_dxy", &tree_slimmedmuon_dxy, &b_tree_slimmedmuon_dxy);
   fChain->SetBranchAddress("tree_slimmedmuon_dxyError", &tree_slimmedmuon_dxyError, &b_tree_slimmedmuon_dxyError);
   fChain->SetBranchAddress("tree_slimmedmuon_dz", &tree_slimmedmuon_dz, &b_tree_slimmedmuon_dz);
   fChain->SetBranchAddress("tree_slimmedmuon_dzError", &tree_slimmedmuon_dzError, &b_tree_slimmedmuon_dzError);
   fChain->SetBranchAddress("tree_slimmedmuon_charge", &tree_slimmedmuon_charge, &b_tree_slimmedmuon_charge);
   fChain->SetBranchAddress("tree_slimmedmuon_PFisoVeryTight", &tree_slimmedmuon_PFisoVeryTight, &b_tree_slimmedmuon_PFisoVeryTight);
   fChain->SetBranchAddress("tree_slimmedmuon_PFisoTight", &tree_slimmedmuon_PFisoTight, &b_tree_slimmedmuon_PFisoTight);
   fChain->SetBranchAddress("tree_slimmedmuon_PFisoMedium", &tree_slimmedmuon_PFisoMedium, &b_tree_slimmedmuon_PFisoMedium);
   fChain->SetBranchAddress("tree_slimmedmuon_PFisoLoose", &tree_slimmedmuon_PFisoLoose, &b_tree_slimmedmuon_PFisoLoose);
   fChain->SetBranchAddress("tree_slimmedmuon_MVAisoLoose", &tree_slimmedmuon_MVAisoLoose, &b_tree_slimmedmuon_MVAisoLoose);
   fChain->SetBranchAddress("tree_slimmedmuon_MVAisoMedium", &tree_slimmedmuon_MVAisoMedium, &b_tree_slimmedmuon_MVAisoMedium);
   fChain->SetBranchAddress("tree_slimmedmuon_MVAisoTight", &tree_slimmedmuon_MVAisoTight, &b_tree_slimmedmuon_MVAisoTight);
   fChain->SetBranchAddress("tree_slimmedmuon_isGlobalMuon", &tree_slimmedmuon_isGlobalMuon, &b_tree_slimmedmuon_isGlobalMuon);
   fChain->SetBranchAddress("tree_slimmedmuon_isStandAloneMuon", &tree_slimmedmuon_isStandAloneMuon, &b_tree_slimmedmuon_isStandAloneMuon);
   fChain->SetBranchAddress("tree_slimmedmuon_CutBasedIdLoose", &tree_slimmedmuon_CutBasedIdLoose, &b_tree_slimmedmuon_CutBasedIdLoose);
   fChain->SetBranchAddress("tree_slimmedmuon_CutBasedIdMedium", &tree_slimmedmuon_CutBasedIdMedium, &b_tree_slimmedmuon_CutBasedIdMedium);
   fChain->SetBranchAddress("tree_slimmedmuon_CutBasedIdMediumPrompt", &tree_slimmedmuon_CutBasedIdMediumPrompt, &b_tree_slimmedmuon_CutBasedIdMediumPrompt);
   fChain->SetBranchAddress("tree_slimmedmuon_CutBasedIdTight", &tree_slimmedmuon_CutBasedIdTight, &b_tree_slimmedmuon_CutBasedIdTight);
   Notify();
}

Bool_t LLTopTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LLTopTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LLTopTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
//DeltaR utile pour recontruire les jets de paticules, voir le sparticlues qu isont � cot�s: lego plot avec en vertical du plan Deta Dphi, l'energie transverse
//$$
double DeltaR(double eta1, double phi1, double eta2, double phi2) {
  double DeltaPhi = TMath::Abs(phi2 - phi1);
  if (DeltaPhi > 3.141593 ) DeltaPhi = 2.*3.141593 - DeltaPhi;
  return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}
double DeltaPhi(double phi1, double phi2) {
  double DeltaPhi = phi1 - phi2;
  if (abs(DeltaPhi) > 3.141593 ) {
    DeltaPhi = 2.*3.141593 - abs(DeltaPhi);
    DeltaPhi = -DeltaPhi * (phi1 - phi2) / abs(phi1 - phi2);
  }
  return DeltaPhi;
}
//$$

#endif // #ifdef LLTopTree_cxx
