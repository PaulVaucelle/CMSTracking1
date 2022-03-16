#include <iostream>
#include <TROOT.h>
#include "TVectorD.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraphAsymmErrors.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TEfficiency.h" 
#include "TMath.h" 

void plot()
{
float WP = 0.01;

int stati=0;
bool fit= 0;
bool logy=1;

 TFile *f1, *f2, *f3, *f4;
 TGraphAsymmErrors *gr0, *gr1, *gr2, *gr3, *gr4;
 TGraphAsymmErrors *gr00, *gr10, *gr20, *gr30, *gr40;
 
 f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
 f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");

//  f1 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepCSV.root");
//  f2 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepJet.root");
//  f1 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepCSV.root");
//  f2 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepJet.root");

//  f1 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepJet.root");
//  f2 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2021_realistic_v3_DeepJet.root");
//  f3 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2023_realistic_v3_DeepJet.root");
//  f4 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepJet.root");

//$$
 int nfiles = 2;
//$$

 int color1 = kBlack; 
 int color2 = kBlue;
 int color3 = kGreen+1;
 int color4 = kRed;
 int mark1 = 22; int markc1 = mark1+4;
 int mark2 = 23; int markc2 = 32;
 int mark3 = 20; int markc3 = mark3+4;
 int mark4 = 21; int markc4 = mark4+4;

 if ( nfiles == 2 ) {
   color1 = kBlue;
   color2 = kRed;
   mark1 = 20; markc1 = mark1+4;
   mark2 = 21; markc2 = mark2+4;
 } 

 if ( nfiles == 3 ) {
   color1 = kBlack;
   color2 = kRed;
   color3 = kGreen+1;
   mark1 = 22; markc1 = mark1+4;
   mark2 = 21; markc2 = mark2+4;
   mark3 = 20; markc3 = mark3+4;
 } 

  float eff1 = 100.; 

// *****************************************************************************

TCanvas *c1 = new TCanvas("c1", "plots",200,0,700,700);
c1->SetFillColor(10);
c1->SetFillStyle(4000);
c1->SetBorderSize(2);

TPad* pad1 = new TPad("pad1","This is pad1",0.02,0.02,0.99,0.99,21);

pad1->SetFillColor(0);
pad1->SetBorderMode(0);
pad1->SetFrameFillColor(10);
pad1->Draw();
pad1->SetLogy(logy);
pad1->SetGrid();

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

  int nptbin = 199;
  int nbin = 999;
  TVectorD cont(nbin+1);
  TVectorD beff(nbin+1);
  TVectorD ceff(nbin+1);
  TVectorD leff(nbin+1);
  float x1[1000], ex1[1000], ex1d[1000], ex1u[1000];
  float y1[1000], ey1[1000], ey1d[1000], ey1u[1000];
  float x2[1000], ex2[1000], ex2d[1000], ex2u[1000];
  float y2[1000], ey2[1000], ey2d[1000], ey2u[1000];

  TEfficiency *EfficiencyUtil = new TEfficiency();

// *****************************************************************************

  pad1->cd();

  TH2F* histo = new TH2F("histo","",100,0.4,1.0,100,0.0008,1.);
  histo->GetXaxis()->SetLabelSize(0.038);
  histo->GetYaxis()->SetLabelSize(0.038);
  histo->SetLabelFont(42, "XYZ"); 
  histo->SetTitleFont(42, "XYZ");
  histo->GetXaxis()->SetTitleColor(1);
  histo->GetYaxis()->SetTitleColor(1);
  histo->GetXaxis()->SetTitleSize(0.05);
  histo->GetYaxis()->SetTitleSize(0.05);
  histo->GetXaxis()->SetTitle("b-jet efficiency");
  histo->GetYaxis()->SetTitle("misid. probability");
  histo->SetTitleOffset(0.9,"X");
  histo->SetTitleOffset(1.0,"Y");
//   histo->SetNdivisions(509, "XYZ");
  histo->Draw(); 
  
/////////////////

  // ##### ADD histogramms title here and insert them in the hX definition
   f1->cd();

TString htitle = "hTkSim_pt";
TString htitle2 = "hTkOth_pt";  
// TString xtitle = "track p_T [GeV]"; 
// int nbin = 100; 
// float xmin =  0.;
// float xmax = 100.;
//float ymin = 0.; 
//float ymax = 1.; 
// number of equivalent events
  TH1F* h0 = (TH1F*)gROOT->FindObject(htitle);
  float nequBFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject(htitle2);
  float nequLightFlav = h0->Integral(0,nptbin+1);
  // h0 = (TH1F*)gROOT->FindObject("hCFlav_JetPt_etaLT25");
  // float nequCFlav = h0->Integral(0,nptbin+1);
  
  TH1F* h1 = (TH1F*)gROOT->FindObject("hBFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    beff(k) = cont(k) / nequBFlav;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequBFlav);
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, true);
    //ClopperPearson(total number of events,number of passed event, CL (1 sigma here),True (upper boundary is returned, false->lower))
  }  

  float L = 100.; 
  float B1 = 0., EBD1 = 0., EBU1 = 0.; 
  float bwp = 0., bwpd = 10., bwpu = -10.; 
  float BWP = 0., EBWPD = 0., EBWPU = 0.; 
  int nwp = 0;
  int kWP1 = 0;

  h1 = (TH1F*)gROOT->FindObject("hLightFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    leff(k) = cont(k) / nequLightFlav;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequLightFlav);
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, true);
    if ( TMath::Abs(leff(k) - WP) < TMath::Abs(L - WP) ) {
      L = leff(k);
      BWP = x1[k] - (x1[k]-x1[k-1]) / (L-y1[k-1]) * (L-WP);
      EBWPD = ex1d[k];
      EBWPU = ex1u[k];
      kWP1 = k;
    } 
    if ( y1[k]-ey1d[k] < WP && y1[k]+ey1u[k] > WP ) {
      nwp++;
      bwp += x1[k];
      if ( x1[k] > bwpu ) bwpu = x1[k];
      if ( x1[k] < bwpd ) bwpd = x1[k];
    } 
  }  
  if ( nwp > 0 ) {
    BWP = bwp / nwp;
    EBWPD = TMath::Sqrt(EBWPD*EBWPD + (bwpd - BWP)*(bwpd - BWP));
    EBWPU = TMath::Sqrt(EBWPU*EBWPU + (bwpu - BWP)*(bwpu - BWP));
  }
    B1 =  BWP;
  EBD1 = EBWPD;
  EBU1 = EBWPU;

  h1 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    ceff(k) = cont(k) / nequCFlav;
    y2[k] = 0.00005;
    if ( ceff(k) < 0.001 ) continue;
    y2[k] = ceff(k);
    ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
    ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
    ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  }  

//   gr10 = new TGraphErrors(nbin,x1,y2,ex1,ey2);
  gr10 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  gr10->SetLineColor(color1);
  gr10->SetLineWidth(1);
  gr10->SetMarkerColor(color1);
  gr10->SetMarkerStyle(markc1);
  gr10->SetMarkerSize(1.0);
  gr10->Draw("P"); 

//   gr1 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr1 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr1->SetLineColor(color1);
  gr1->SetLineWidth(1);
  gr1->SetMarkerColor(color1);
  gr1->SetMarkerStyle(mark1);
  gr1->SetMarkerSize(1.0);
  gr1->Draw("P"); 

/////////////////

  gr00 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  gr00->SetLineColor(kBlack);
  gr00->SetLineWidth(1);
  gr00->SetMarkerColor(kBlack);
  gr00->SetMarkerStyle(24);
  gr00->SetMarkerSize(1.0);

  gr0 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr0->SetLineColor(kBlack);
  gr0->SetLineWidth(1);
  gr0->SetMarkerColor(kBlack);
  gr0->SetMarkerStyle(20);
  gr0->SetMarkerSize(1.0);

/////////////////

  f2->cd();
// number of equivalent events
  h0 = (TH1F*)gROOT->FindObject(htitle);
  nequBFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject(htitle2);
  nequLightFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject("hCFlav_JetPt_etaLT25");
  nequCFlav = h0->Integral(0,nptbin+1);

  h1 = (TH1F*)gROOT->FindObject("hBFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    beff(k) = cont(k) / nequBFlav;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequBFlav);
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, true);
  }  

  L = 100.; 
  float B2 = 0., EBD2 = 0., EBU2 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  int kWP2 = 0;
  nwp = 0;
  h1 = (TH1F*)gROOT->FindObject("hLightFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    leff(k) = cont(k) / nequLightFlav;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequLightFlav);
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, true);
    if ( TMath::Abs(leff(k) - WP) < TMath::Abs(L - WP) ) {
      L = leff(k);
        BWP = x1[k] - (x1[k]-x1[k-1]) / (L-y1[k-1]) * (L-WP);
      EBWPD = ex1d[k];
      EBWPU = ex1u[k];
      kWP2 = k;
    } 
    if ( y1[k]-ey1d[k] < WP && y1[k]+ey1u[k] > WP ) {
      nwp++;
      bwp += x1[k];
      if ( x1[k] > bwpu ) bwpu = x1[k];
      if ( x1[k] < bwpd ) bwpd = x1[k];
    } 
  }  
  if ( nwp > 0 ) {
    BWP = bwp / nwp;
    EBWPD = TMath::Sqrt(EBWPD*EBWPD + (bwpd - BWP)*(bwpd - BWP));
    EBWPU = TMath::Sqrt(EBWPU*EBWPU + (bwpu - BWP)*(bwpu - BWP));
  }
    B2 =  BWP;
  EBD2 = EBWPD;
  EBU2 = EBWPU;

  h1 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    ceff(k) = cont(k) / nequCFlav;
    y2[k] = 0.00005;
    if ( ceff(k) < 0.001 ) continue;
    y2[k] = ceff(k);
    ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
    ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
    ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  }  

//   gr20 = new TGraphErrors(nbin,x1,y2,ex1,ey2);
  gr20 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  gr20->SetLineColor(color2);
  gr20->SetLineWidth(1);
  gr20->SetMarkerColor(color2);
  gr20->SetMarkerStyle(markc2);
  gr20->SetMarkerSize(1.0);
  gr20->Draw("P"); 

//   gr2 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr2 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr2->SetLineColor(color2);
  gr2->SetLineWidth(1);
  gr2->SetMarkerColor(color2);
  gr2->SetMarkerStyle(mark2);
  gr2->SetMarkerSize(1.0);
  gr2->Draw("P"); 

//#################################End of my scope : 2 files######################################################///
/////////////////

  float B3, EBD3, EBU3; 
  if ( nfiles >= 3 ) {
  f3->cd();
// number of equivalent events
  h0 = (TH1F*)gROOT->FindObject("hBFlav_JetPt_etaLT25");
  nequBFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject("hLightFlav_JetPt_etaLT25");
  nequLightFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject("hCFlav_JetPt_etaLT25");
  nequCFlav = h0->Integral(0,nptbin+1);

  h1 = (TH1F*)gROOT->FindObject("hBFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    beff(k) = cont(k) / nequBFlav;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequBFlav);
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, true);
  }  

  L = 100.; 
  B3 = 0.; EBD3 = 0.; EBU3 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  nwp = 0;
  h1 = (TH1F*)gROOT->FindObject("hLightFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    leff(k) = cont(k) / nequLightFlav;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequLightFlav);
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, true);
    if ( TMath::Abs(leff(k) - WP) < TMath::Abs(L - WP) ) {
      L = leff(k);
        BWP = x1[k] - (x1[k]-x1[k-1]) / (L-y1[k-1]) * (L-WP);
      EBWPD = ex1d[k];
      EBWPU = ex1u[k];
    } 
    if ( y1[k]-ey1d[k] < WP && y1[k]+ey1u[k] > WP ) {
      nwp++;
      bwp += x1[k];
      if ( x1[k] > bwpu ) bwpu = x1[k];
      if ( x1[k] < bwpd ) bwpd = x1[k];
    } 
  }  
  if ( nwp > 0 ) {
    BWP = bwp / nwp;
    EBWPD = TMath::Sqrt(EBWPD*EBWPD + (bwpd - BWP)*(bwpd - BWP));
    EBWPU = TMath::Sqrt(EBWPU*EBWPU + (bwpu - BWP)*(bwpu - BWP));
  }
    B3 =  BWP;
  EBD3 = EBWPD;
  EBU3 = EBWPU;

  h1 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    ceff(k) = cont(k) / nequCFlav;
    y2[k] = 0.00005;
    if ( ceff(k) < 0.001 ) continue;
    y2[k] = ceff(k);
    ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
    ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
    ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  }  

  gr30 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  gr30->SetLineColor(color3);
  gr30->SetLineWidth(1);
  gr30->SetMarkerColor(color3);
  gr30->SetMarkerStyle(markc3);
  gr30->SetMarkerSize(1.0);
  gr30->Draw("P"); 

  gr3 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr3->SetLineColor(color3);
  gr3->SetLineWidth(1);
  gr3->SetMarkerColor(color3);
  gr3->SetMarkerStyle(mark3);
  gr3->SetMarkerSize(1.0);
  gr3->Draw("P"); 
  }

/////////////////

  if ( nfiles == 4 ) {
  f4->cd();
// number of equivalent events
  h0 = (TH1F*)gROOT->FindObject("hBFlav_JetPt_etaLT25");
  nequBFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject("hLightFlav_JetPt_etaLT25");
  nequLightFlav = h0->Integral(0,nptbin+1);
  h0 = (TH1F*)gROOT->FindObject("hCFlav_JetPt_etaLT25");
  nequCFlav = h0->Integral(0,nptbin+1);

  h1 = (TH1F*)gROOT->FindObject("hBFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    beff(k) = cont(k) / nequBFlav;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequBFlav);
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequBFlav, cont(k), 0.683, true);
  }  

  h1 = (TH1F*)gROOT->FindObject("hLightFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    leff(k) = cont(k) / nequLightFlav;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequLightFlav);
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequLightFlav, cont(k), 0.683, true);
  }  

  h1 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  cont(0) = h1->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    ceff(k) = cont(k) / nequCFlav;
    y2[k] = 0.00005;
    if ( ceff(k) < 0.001 ) continue;
    y2[k] = ceff(k);
    ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
    ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
    ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  }  

  gr40 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  gr40->SetLineColor(color4);
  gr40->SetLineWidth(1);
  gr40->SetMarkerColor(color4);
  gr40->SetMarkerStyle(markc4);
  gr40->SetMarkerSize(1.0);
  gr40->Draw("P"); 

  gr4 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr4->SetLineColor(color4);
  gr4->SetLineWidth(1);
  gr4->SetMarkerColor(color4);
  gr4->SetMarkerStyle(mark4);
  gr4->SetMarkerSize(1.0);
  gr4->Draw("P"); 
  }

/////////////////

  TLegend* leg = new TLegend(0.10,0.90,0.72,0.95);
//   TLegend* leg = new TLegend(0.12,0.82,0.72,0.87);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.038);
//   leg->SetHeader("TTbar, jet p_{T}>30 etaLT25");
  leg->SetHeader("TTbar, 55<PU<76, jet p_{T}>30 |#eta|<2.5");
//   leg->SetHeader("Phase-2 TTbar, jet p_{T}>30 etaLT25, DeepCSV");
  leg->Draw();
  
//   leg = new TLegend(0.15,0.75,0.40,0.85);
//   leg->SetBorderSize(0);
//   leg->SetFillColor(kWhite);
//   leg->SetTextFont(42);
//   leg->SetTextSize(0.028);
//   if ( nfiles == 2 ) leg->SetTextSize(0.032);
// //   leg->SetHeader("");
//   leg->AddEntry(gr00,"c-jet misid.","P");
//   leg->AddEntry(gr0,"udsg-jet misid.","P");
//   leg->Draw();
  
  if ( nfiles != 2 ) leg = new TLegend(0.62,0.14,0.85,0.30);
  else               leg = new TLegend(0.62,0.14,0.85,0.26);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.028);
  if ( nfiles == 2 ) leg->SetTextSize(0.035);
//   leg->AddEntry(gr1,"DeepCSV","P");
//   leg->AddEntry(gr2,"DeepJet","P");
//   if ( nfiles >= 3 ) leg->AddEntry(gr3,"2018","P");
  leg->SetHeader("DeepJet");
  leg->AddEntry(gr1,"Run2 2018","P");
  leg->AddEntry(gr2,"Run3 2021","P");
  if ( nfiles >= 3 ) leg->AddEntry(gr3,"Run3 2023","P");
  if ( nfiles >= 4 ) leg->AddEntry(gr4,"Run3 2024","P");
//   leg->SetHeader("DeepJet 2018");
//   leg->AddEntry(gr1,"<PU>=35","P");
//   leg->AddEntry(gr2,"<PU>=59","P");
  leg->Draw();
  
  float EB1 = (EBD1+EBU1)/2.;
  float EB2 = (EBD2+EBU2)/2.;
  float EB3 = (EBD3+EBU3)/2.;
//   float ww = 1./EB1/EB1 + 1./EB2/EB2 + 1./EB3/EB3;
//   B4 = (B1/EB1/EB1 + B2/EB2/EB2 + B3/EB3/EB3) / ww;
//   EB4 = 1. / TMath::Sqrt( ww );  

   float WP1 =  kWP1 / 1000.;
   float WP2 =  kWP2 / 1000.;
   
   float gain = B3 / B2;
   float alpha = (B3 -B2) / (B1 - B2);

  cout << endl;
  cout << " working point " << WP << " gain " << gain << " alpha " << alpha << endl;
  cout << "DeepCSV " << B1 << "+_" << EB1 << "	WP " << kWP1 << " " << WP1 << endl;
  cout << "DeepJET " << B2 << "+_" << EB2 << "	WP " << kWP2 << " " << WP2 << endl;
//   cout << "PU300 " << B3 << "+_" << EB3 << endl;
  cout << endl;

//   cout << "cMVAv2  " << B3 << "+_" << EB3 << endl;
// //   cout << "rho=0      " << B1 << "+_" << EB1 << "   WP " << kWP1 << " " << WP1 << endl;
// //   cout << "rho=1      " << B2 << "+_" << EB2 << "   WP " << kWP2 << " " << WP2 << endl;
// //   cout << "rho=2      " << B3 << "+_" << EB3 << endl;
// //   cout << "rho=3      " << B1 << "+_" << EB1 << endl;
// //   cout << "rho=4      " << B2 << "+_" << EB2 << endl;
// //   cout << "rho=5      " << B3 << "+_" << EB3 << endl;
//   cout << "z<2cm      " << B1 << "+_" << EB1 << endl;
//   cout << "2<z<4      " << B2 << "+_" << EB2 << endl;
//   cout << "4<z<6      " << B3 << "+_" << EB3 << endl;

  c1->Update();
}
