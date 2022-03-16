#include <iostream>
#include <TROOT.h>
#include "TVectorD.h"
#include "TH1.h"
#include "TEfficiency.h" 

void plot()
{
  //Test change via VSCode
int stati=0;
bool fit= 1;
bool logy=0;

 TFile *f1, *f2, *f3, *f4;
 TGraphAsymmErrors *gr0, *gr1, *gr2, *gr3, *gr4;
 
 f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
 f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");                               
//  TString htitle = "hBFlav_TrackTime";                                        
//  TString xtit20ReRECOMiniAOD-PU200_113X_mcRun4_realistic_T15_nt_DeepJet.root");

//  f1 = new TFile("../outputUP/TT_TuneCP5_14TeV-powheg-pythia8_Phase2HLTTDRSummer20ReRECOMiniAOD-PU200_111X_mcRun4_realistic_T15_v1_wt_DeepJet_IPsigGT3_PV1SV1JT2.root");
//  f2 = new TFile("../outputUP/RelValTTbar_14TeV_CMSSW_11_1_2_patch3-PU_110X_mcRun4_realistic_v3_2026D49PU200_BSzpz35_wt_DeepJet_IPsigGT3_PV1SV1JT2.root");
//  f3 = new TFile("../outputUP/TT_TuneCP5_14TeV-powheg-pythia8_Phase2HLTTDRSummer20ReRECOMiniAOD-PU140_111X_mcRun4_realistic_T15_v1_wt_DeepJet_IPsigGT3_PV1SV1JT2.root");

//  f1 = new TFile("../outputUP/TT_TuneCP5_14TeV-powheg-pythia8_Phase2HLTTDRSummer20ReRECOMiniAOD-PU200_111X_mcRun4_realistic_T15_v1_wt_DeepJet_IPsigGT3_PV1SV1JT2.root");
//  f2 = new TFile("../outputUP/TT_TuneCP5_14TeV-powheg-pythia8_Phase2HLTTDRSummer20ReRECOMiniAOD-NoPU_111X_mcRun4_realistic_T15_v1_wt_DeepJet_IPsigGT3_PV1SV1JT2.root");


//##########BDT vairables#################
//keep ymin and ymax commented
TString htitle = "hTkSim_pt";
TString htitle2 = "hTkOth_pt";  
TString xtitle = "track p_T [GeV]"; 
int nbin = 100; 
float xmin =  0.;
float xmax = 100.;
//float ymin = 0.; 
//float ymax = 1.; 

//  TString htitle = "hTkSim_eta";
//  TString htitle2 = "hTkOth_eta"; 
//  TString xtitle = "eta"; 
//  int nbin = 50; 
//  float xmin = -2.5;
//  float xmax = 2.5;
//  float ymin = 0.; 
//  float ymax = 0.1; 

//  TString htitle = "hTkSim_dr";
//  TString htitle2 = "hTkOth_dr"; 
//  TString xtitle = "dr"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 10;
//  float ymin = 0.; 
//  float ymax = 0.08; 

//  TString htitle = "hTkSim_dz";
//  TString htitle2 = "hTkOth_dz";
//  TString xtitle = "dz"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 50;
//  float ymin = 0.; 
//  float ymax = 0.07; 

//  TString htitle = "hTkSim_dd";
//  TString htitle2 = "hTkOth_dd";
//  TString xtitle = "dd"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 50;
//  float ymin = 0.; 
//  float ymax = 0.07; 

//  TString htitle = "hTkSim_drSig";
//  TString htitle2 = "hTkOth_drSig";
//  TString xtitle = "drSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.1; 

//  TString htitle = "hTkSim_dzSig";
//  TString htitle2 = "hTkOth_dzSig";
//  TString xtitle = "dzSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.1;

//  TString htitle = "hTkSim_ddSig";
//  TString htitle2 = "hTkOth_ddSig";
//  TString xtitle = "ddSig"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 1000;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_inJet";
//  TString htitle2 = "hTkOth_inJet";
//  TString xtitle = "inJet"; 
//  int nbin = 2; 
//  float xmin = -0.5;
//  float xmax = 1.5;
//  float ymin = 0.; 
//  float ymax = 1;

//  TString htitle = "hTkSim_pix";
//  TString htitle2 = "hTkOth_pix";
//  TString xtitle = "pix"; 
//  int nbin = 30; 
//  float xmin = -0.5;
//  float xmax = 25;
//  float ymin = 0.; 
//  float ymax = 0.5;


//  TString htitle = "hTkSim_hit";
//  TString htitle2 = "hTkOth_hit";
//  TString xtitle = "hit"; 
//  int nbin = 30; 
//  float xmin = -0.5;
//  float xmax = 29.5;
//  float ymin = 0.; 
//  float ymax = 0.2;

//  TString htitle = "hTkSim_chi";
//  TString htitle2 = "hTkOth_chi";
//  TString xtitle = "chi"; 
//  int nbin = 50; 
//  float xmin = 0.;
//  float xmax = 10.;
//  float ymin = 0.; 
//  float ymax = 0.65;

//  TString htitle = "hTkSim_r1";
//  TString htitle2 = "hTkOth_r1";
//  TString xtitle = "r1"; 
//  int nbin = 200; 
//  float xmin = 0.;
//  float xmax = 100.;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_z1";
//  TString htitle2 = "hTkOth_z1";
//  TString xtitle = "z1"; 
//  int nbin = 200; 
//  float xmin = 0;
//  float xmax = 100;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_at10";
//  TString htitle2 = "hTkOth_at10";
//  TString xtitle = "at10"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_at20";
//  TString htitle2 = "hTkOth_at20";
//  TString xtitle = "at20"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_at30";
//  TString htitle2 = "hTkOth_at30";
//  TString xtitle = "at30"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;

//  TString htitle = "hTkSim_at40";
//  TString htitle2 = "hTkOth_at40";
//  TString xtitle = "at40"; 
//  int nbin = 101; 
//  float xmin = -0.5;
//  float xmax = 100.5;
//  float ymin = 0.; 
//  float ymax = 0.07;


// *****************************************************************************

TCanvas *c1 = new TCanvas("c1", "plots",200,0,700,700);
c1->SetFillColor(10);
c1->SetFillStyle(4000);
c1->SetBorderSize(2);

TPad* pad1 = new TPad("pad1","This is pad1",0.04,0.02,0.99,0.99,21);

pad1->SetFillColor(0);
pad1->SetBorderMode(0);
pad1->SetFrameFillColor(10);
pad1->Draw();
pad1->SetLogy(logy);
pad1->SetGrid();
//    pad1->SetTopMargin(0.06);
//    pad1->SetBottomMargin(0.16);
//    pad1->SetRightMargin(0.05);
pad1->SetLeftMargin(0.12);

gStyle->SetOptDate(0);
gStyle->SetStatColor(0);
gStyle->SetTitleFont(62);
gStyle->SetTitleColor(1);
gStyle->SetTitleTextColor(1);
gStyle->SetTitleFillColor(10);
gStyle->SetTitleFontSize(0.05);
gStyle->SetTitleW(0.4);
gStyle->SetTitleH(0.09);
// gStyle->SetTitleX(0); // Set the position of the title box
// gStyle->SetTitleY(0.985); // Set the position of the title box
// gStyle->SetTitleStyle(Style_t style = 1001);
// gStyle->SetTitleBorderSize(2);
gStyle->SetOptStat(stati);
gStyle->SetPadTickX(1); gStyle->SetPadTickY(1);
// gStyle->SetPadGridX(true); gStyle->SetPadGridY(true);

if (fit) {
gStyle->SetStatW(0.3);
gStyle->SetStatH(0.1);
gStyle->SetOptFit(111);
} else {
gStyle->SetStatW(0.3);
gStyle->SetStatH(0.2);
gStyle->SetOptFit(0);
}

// *****************************************************************************

  pad1->cd();
	
 f1->cd();
 //std::cout<< "Error b4 g1"<< std::endl;
 TH1F* g1 = (TH1F*)gROOT->FindObject(htitle);//<-g1 is not affected to an histogram
//std::cout<< "Error After g1 : g1 is "<< g1->isA()<< std::endl;
 
       g1->Sumw2();
       TH1F* h1 = new TH1F("h1","",nbin,xmin,xmax);
       h1->Add(g1,h1,1/g1->Integral(1,nbin),0);
       h1->Draw("EHF"); 
       h1->SetLineColor(kGreen+1);
       h1->SetFillColor(kGreen+1);
       h1->SetFillStyle(3345);
       h1->SetLineStyle(1);
       h1->SetLineWidth(3);
       h1->SetTickLength(0.03, "YZ");
//        h1->SetTickLength(-0.03,"X");
//        h1->SetLabelOffset(0.023,"X");
       h1->SetTickLength(0.03,"X");
       h1->SetLabelOffset(0.007,"X");
       h1->SetLabelOffset(0.007,"Y");
       h1->SetLabelSize(0.035, "XYZ");
       h1->SetLabelFont(42, "XYZ"); 
       h1->SetTitleFont(42, "XYZ");
       h1->SetTitleSize(0.04, "XYZ"); 
       h1->SetTitleOffset(1.1,"X"); 
       h1->SetTitleOffset(1.5,"Y");
       h1->GetXaxis()->SetTitle(xtitle);
       h1->GetXaxis()->SetTitleColor(1);
       h1->GetXaxis()->SetNdivisions(509);
       h1->GetYaxis()->SetTitle("a.u");
       h1->GetYaxis()->SetTitleColor(1);
       h1->GetYaxis()->SetNdivisions(509);
       h1->SetNdivisions(509,"XYZ");
       if ( !logy ) h1->SetMinimum(0.); 
//        h1->SetMaximum(0.05); 
//        h1->SetMaximum(0.07); 
//        h1->SetMaximum(0.20); 
//        h1->SetMaximum(0.30); 

 f2->cd();
// std::cout<< "Error b4 g2"<< std::endl;
 TH1F* g2 = (TH1F*)gROOT->FindObject(htitle2);
 //std::cout<< "Error After g2 : g2 is "<< g1->isA()<< std::endl;
       g2->Sumw2();
 TH1F* h2 = new TH1F("h2","",nbin,xmin,xmax);
       h2->Add(g2,h2,1/g2->Integral(1,nbin),0);

       h2->Draw("EHFsame"); 
       h2->SetLineColor(kRed);
       h2->SetFillColor(kRed);
//        h2->SetLineColor(kBlack);
//        h2->SetFillColor(kBlack);
       h2->SetFillStyle(3354);
       h2->SetLineStyle(1);
       h2->SetLineWidth(3);

//  f3->cd();
//  TH1F* g3 = (TH1F*)gROOT->FindObject(htitle);
//        g3->Sumw2();
//  TH1F* h3 = new TH1F("h3","",nbin,xmin,xmax);
//        h3->Add(g3,h3,1/g3->Integral(1,nbin),0);
//        h3->Draw("EHsame"); 
//        h3->SetLineColor(kBlack);
//        h3->SetLineStyle(1);
//        h3->SetLineWidth(3);
//        h1->Draw("EHFsame"); 
//        h2->Draw("EHFsame"); 
  
  TLegend* leg;
  
  leg = new TLegend(0.76,0.91,0.90,0.95);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.045);
  leg->SetHeader("14 TeV");
  leg->Draw();

//   leg = new TLegend(0.14,0.80,0.34,0.84);
  leg = new TLegend(0.16,0.82,0.26,0.86);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.038);
  leg->SetHeader("t#bar{t}, <PU> = 200");
  leg->Draw();
  
//   leg = new TLegend(0.16,0.76,0.26,0.80);
//   leg->SetBorderSize(0);
//   leg->SetFillColor(kWhite);
//   leg->SetTextFont(42);
//   leg->SetTextSize(0.038);
// //   leg->SetHeader("all tracks at PV");
//   leg->SetHeader("tracks in b jets");
//   leg->Draw();
//   
//   leg = new TLegend(0.14,0.70,0.46,0.74);
//   leg->SetBorderSize(0);
//   leg->SetFillColor(kWhite);
//   leg->SetTextFont(42);
//   leg->SetTextSize(0.038);
//   leg->SetHeader("dist.-to-jet < 0.7 mm");
//   leg->Draw();
  
//   leg = new TLegend(0.50,0.68,0.85,0.84);
//   leg->SetBorderSize(0);
//   leg->SetFillColor(kWhite);
//   leg->SetTextFont(42);
//   leg->SetTextSize(0.034);
//   leg->SetHeader("beam spot");
//   leg->AddEntry(h3,"<PU> = 140 default","F");
//   leg->AddEntry(h1,"<PU> = 200 default","F");
//   leg->AddEntry(h2,"<PU> = 200 narrow","F");
//   leg->Draw();
  
// //   leg = new TLegend(0.53,0.72,0.88,0.84);
//   leg = new TLegend(0.61,0.72,0.88,0.84);
//   leg->SetBorderSize(0);
//   leg->SetFillColor(kWhite);
//   leg->SetTextFont(42);
//   leg->SetTextSize(0.034);
//   leg->SetHeader("beam spot (default)");
//   leg->AddEntry(h2,"no PU","F");
//   leg->AddEntry(h1,"<PU> = 200","F");
//   leg->Draw();
  
  leg = new TLegend(0.71,0.72,0.88,0.84);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.034);
//   leg->SetHeader("beam spot (default)");
  leg->AddEntry(h2," NotFromLLP","F");
  leg->AddEntry(h1," isFromLLP","F");
  leg->Draw();

  c1->Update();
}
