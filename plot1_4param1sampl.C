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
#include "TGraph.h"

///############Toujours changer le nombre de bins,noms des histos,, ATTENTION au FILE PATH###############//
void plot()
{
float WP = 0.01;

int stati=0;
bool fit= 0;
bool logy=0;

 TFile *f1, *f2, *f3, *f4;
 TGraphAsymmErrors *gr0, *gr1, *gr2, *gr3, *gr4;
 TGraphAsymmErrors *gr00, *gr10, *gr20, *gr30, *gr40; 
 double Inte0, Inte1, Inte2, Inte3;
 
//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");
//  f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

//  f1 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepCSV.root");
//  f2 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepJet.root");
//  f1 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepCSV.root");
//  f2 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepJet.root");

//===================1 param for 4 samples display=============================//
//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
// //  f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
// //  f3 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau30_smu300_snu250.root");
// //  f4 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

//===================4 param for 1 sample display=============================//
f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
f3 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
f4 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
//$$
 int nfiles = 4;
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

//===================always check for the bin number when changing the variable==================//
  
  int nbin1 =100;//1st parameter
  int nbin2 =100;//2nd parameter
  int nbin3 =100;//3rd parameter
  int nbin4 =100;//4th parameter
  
  TVectorD cont1(nbin1+1);
  TVectorD cont2(nbin2+1);
  TVectorD cont3(nbin3+1);
  TVectorD cont4(nbin4+1);
  TVectorD beff1(nbin1+1);
  TVectorD beff2(nbin2+1);
  TVectorD beff3(nbin3+1);
  TVectorD beff4(nbin4+1);
  // TVectorD ceff(nbin+1);
  TVectorD leff1(nbin1+1);
  TVectorD leff2(nbin2+1);
  TVectorD leff3(nbin3+1);
  TVectorD leff4(nbin4+1);
  float x1[1000], ex1[1000], ex1d[1000], ex1u[1000];
  float y1[1000], ey1[1000], ey1d[1000], ey1u[1000];
  float x2[1000], ex2[1000], ex2d[1000], ex2u[1000];
  float y2[1000], ey2[1000], ey2d[1000], ey2u[1000];

  TEfficiency *EfficiencyUtil = new TEfficiency();

// *****************************************************************************

  pad1->cd();

  TH2F* histo = new TH2F("histo","",100,0.,1.0,100,0.0008,1.);
  histo->GetXaxis()->SetLabelSize(0.038);
  histo->GetYaxis()->SetLabelSize(0.038);
  histo->SetLabelFont(42, "XYZ"); 
  histo->SetTitleFont(42, "XYZ");
  histo->GetXaxis()->SetTitleColor(1);
  histo->GetYaxis()->SetTitleColor(1);
  histo->GetXaxis()->SetTitleSize(0.05);
  histo->GetYaxis()->SetTitleSize(0.05);
  histo->GetXaxis()->SetTitle("IsFromLLP");
  histo->GetYaxis()->SetTitle("NotFromLLP");
  histo->SetTitleOffset(0.9,"X");
  histo->SetTitleOffset(1.0,"Y");
//   histo->SetNdivisions(509, "XYZ");
  histo->Draw(); 
  f1->cd();

//=========================Histograms used for 1 param 4 samples display ==============================//

//  TString hist = "bgctau50 : distance between first hit";
//  TString htitle = "hTkSim_at10";
//  TString htitle2 = "hTkOth_at10";
//  TString htitle3 = "hTkSim_at20";
//  TString htitle4 = "hTkOth_at20";
//  TString htitle5= "hTkSim_at30";
//  TString htitle6 = "hTkOth_at30";
//  TString htitle7= "hTkSim_at40";
//  TString htitle8 = "hTkOth_at40";

//  TString hist = "bgctau50 : distance between first hit";
//  TString htitle = "hTkSim_at1020";
//  TString htitle2 = "hTkOth_at1020";
//  TString htitle3 = "hTkSim_at2030";
//  TString htitle4 = "hTkOth_at2030";
//  TString htitle5= "hTkSim_at3040";
//  TString htitle6 = "hTkOth_at3040";
//  TString htitle7= "hTkSim_at40XX";
//  TString htitle8 = "hTkOth_at40XX";

//  TString hist = "bgctau50 : Impact parameters Significance";
//  TString htitle = "hTkSim_drSig";
//  TString htitle2 = "hTkOth_drSig";
//  TString htitle3 = "hTkSim_dzSig";
//  TString htitle4 = "hTkOth_dzSig";
//  TString htitle5= "hTkSim_ddSig";
//  TString htitle6 = "hTkOth_ddSig";
// //  TString htitle7= "hTkSim_at40";
// //  TString htitle8 = "hTkOth_at40";

//  TString hist = "bgctau50 : at10 / at20 / drSig / dd Sig";
//  TString htitle = "hTkSim_at10";
//  TString htitle2 = "hTkOth_at10";
//  TString htitle3 = "hTkSim_at20";
//  TString htitle4 = "hTkOth_at20";
//  TString htitle5= "hTkSim_drSig";
//  TString htitle6 = "hTkOth_drSig";
//  TString htitle7= "hTkSim_ddSig";
//  TString htitle8 = "hTkOth_ddSig";

//  TString hist = "bgctau50 : Valid Pixel Hits";
//  TString htitle = "hValStripHitIs";
//  TString htitle2 = "hValStripHitNot";
//  TString htitle3 = "hValTIBHitIs";
//  TString htitle4 = "hValTIBHitNot";
//  TString htitle5= "hValTOBHitIs";
//  TString htitle6 = "hValTOBHitNot";
//  TString htitle7= "hValPixBarHitIs";
//  TString htitle8 = "hValPixBarHitNot";


//  TString hist = "bgctau50 : dr / dz / r1 / z1 (eta1.5)";
//  TString htitle = "hTkSim_dr";
//  TString htitle2 = "hTkOth_dr";
//  TString htitle3 = "hTkSim_dz";
//  TString htitle4 = "hTkOth_dz";
//  TString htitle5= "hr1_etasup1_5_isFromLLP";
//  TString htitle6 = "hr1_etasup1_5_NotFromLLP";
//  TString htitle7= "hz1_etainf1_5_isFromLLP";
//  TString htitle8 = "hz1_etainf1_5_NotFromLLP";

//==========================================================================//

  // TH1F* h0 = (TH1F*)gROOT->FindObject(htitle);//hAllpt
  // float nequpt1 = h0->Integral(0,nbin+1);//nptbin
  
  TH1F* h1 = (TH1F*)gROOT->FindObject(htitle);//hAllpt
  float nequpt2 = h1->Integral(0,nbin1+1);
  cont1(0) = h1->Integral(0,nbin1+1);
  x1[0]=cont1(0)/nequpt2;
  for (Int_t k=1; k<nbin1+1; k++) {
    cont1(k) = cont1(k-1) - h1->GetBinContent(k);
    beff1(k) = cont1(k) / nequpt2;
    x1[k] = beff1(k);
    ex1[k] = TMath::Sqrt(beff1(k)*(1.-beff1(k))/nequpt2);//ne sert à rien acuellement
    //std::cout<<"1k = "<< k<< " \\ bool = false "<<"\\ nequpt2 = "<<nequpt2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h1->GetBinContent(k)<<std::endl;
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequpt2, cont1(k), 0.683, false);
    //std::cout<<"1k = "<< k<< " \\ bool = true "<<"\\ nequpt2 = "<<nequpt2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h1->GetBinContent(k)<<std::endl;
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequpt2, cont1(k), 0.683, true);
    //ClopperPearson(total number of events,number of passed event, CL (1 sigma here),True (upper boundary is returned, false->lower))
  }  //erreur peut de  cont(k) qui serait plus frand que nequBFlav

  ///////
  float L = 100.; 
  float B1 = 0., EBD1 = 0., EBU1 = 0.; 
  float bwp = 0., bwpd = 10., bwpu = -10.; 
  float BWP = 0., EBWPD = 0., EBWPU = 0.; 
  int nwp = 0;
  int kWP1 = 0;
  ////////

   TH1F* h2 = (TH1F*)gROOT->FindObject(htitle2);//htitle

  float nequpt3 = h2->Integral(0,nbin1+1);
  cont1(0) = h2->Integral(0,nbin1+1);
  y1[0]=cont1(0)/nequpt3;

  for (Int_t k=1; k<nbin1+1; k++) {
    cont1(k) = cont1(k-1) - h2->GetBinContent(k);
    leff1(k) = cont1(k) / nequpt3;
    y1[k] = 0.00005;
    if ( leff1(k) < 0.0005 ) continue;
    y1[k] = leff1(k);
    ey1[k] = TMath::Sqrt(leff1(k)*(1.-leff1(k))/nequpt3);//ne sert à rien acuellement
    //std::cout<<"2k = "<< k<< " \\ bool = false "<<"\\ nequpt3 = "<<nequpt3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h2->GetBinContent(k)<<std::endl;
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequpt3, cont1(k), 0.683, false);
    //std::cout<<"2k = "<< k<< " \\ bool = true "<<"\\ nequpt3 = "<<nequpt3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h2->GetBinContent(k)<<std::endl;
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequpt3, cont1(k), 0.683, true);
    if ( TMath::Abs(leff1(k) - WP) < TMath::Abs(L - WP) ) {//WP==0.01: leff(k)>=0.0005: on veut des bins normalisés avec une valeur 
    //supérieure à ce seuil de 0.0005 et ici, 0.01 plus précisement
    //Toujours vérifié: à gauche on compare des grandeurs inférieures à 1, et à droite L=100
      L = leff1(k);
      BWP = x1[k] - (x1[k]-x1[k-1]) / (L-y1[k-1]) * (L-WP);
      EBWPD = ex1d[k];
      EBWPU = ex1u[k];
      kWP1 = k;
    } 
    if ( y1[k]-ey1d[k] < WP && y1[k]+ey1u[k] > WP ) {//la différence et la somme donne les résultats du test de ClopperPearson
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


//   gr1 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr1 = new TGraphAsymmErrors(nbin1,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr1->SetLineColor(5);//color1
  gr1->SetLineWidth(1);
  gr1->SetMarkerColor(5);//color1
  gr1->SetMarkerStyle(mark1);
  gr1->SetMarkerSize(1.0);
  gr1->Draw("LP");
  Inte0 = gr1->Integral();

//#########################f2###########################//
  f2->cd();//f2 == second parameter is studied
// number of equivalent events
  //  TH1F* h3bis = (TH1F*)gROOT->FindObject(htitle3);//htitle3
  // float nequeta = h3bis->Integral(0,nbin+1);//nptbin


   TH1F* h4 = (TH1F*)gROOT->FindObject(htitle3);//htitle3
  cont2(0) = h4->Integral(0,nbin2+1);
  
  float nequeta1 = h4->Integral(0,nbin2+1);//comme nbin est plus grand que nptbin, ça marche mais attention
  x1[0]=cont2(0)/nequeta1;
  for (Int_t k=1; k<nbin2+1; k++) {
    cont2(k) = cont2(k-1) - h4->GetBinContent(k);
    beff2(k) = cont2(k) / nequeta1;
    x1[k] = beff2(k);
    ex1[k] = TMath::Sqrt(beff2(k)*(1.-beff2(k))/nequeta1);//ne sert à rien acuellement
    //std::cout<<"4k = "<< k<< " \\ bool = false "<<"\\ nequeta1 = "<<nequeta1<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h4->GetBinContent(k)<<std::endl;
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequeta1, cont2(k), 0.683, false);
    //std::cout<<"4k = "<< k<< " \\ bool = true "<<"\\ nequeta1 = "<<nequeta1<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h4->GetBinContent(k)<<std::endl;
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequeta1, cont2(k), 0.683, true);
  }  

  L = 100.; 
  float B2 = 0., EBD2 = 0., EBU2 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  int kWP2 = 0;
  nwp = 0;


   TH1F* h5 = (TH1F*)gROOT->FindObject(htitle4);//htitle3
  cont2(0) = h5->Integral(0,nbin2+1);
  
  float nequeta2 = h5->Integral(0,nbin2+1);
  y1[0]=cont2(0)/nequeta2;
  for (Int_t k=1; k<nbin2+1; k++) {
    cont2(k) = cont2(k-1) - h5->GetBinContent(k);
    leff2(k) = cont2(k) / nequeta2;
    y1[k] = 0.00005;
    if ( leff2(k) < 0.0005 ) continue;//pour ça que ça s'arrête à 49 itérations contrairement à h4
    y1[k] = leff2(k);
    ey1[k] = TMath::Sqrt(leff2(k)*(1.-leff2(k))/nequeta2);//ne sert à rien acuellement
    //std::cout<<"5k = "<< k<< " \\ bool = false \\"<<"\\ nequeta2 = "<<nequeta2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h5->GetBinContent(k)<<std::endl;
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequeta2, cont2(k), 0.683, false);
    //std::cout<<"5k = "<< k<< " \\ bool = true "<<"\\ nequeta2 = "<<nequeta2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h5->GetBinContent(k)<<std::endl;
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequeta2, cont2(k), 0.683, true);
    if ( TMath::Abs(leff2(k) - WP) < TMath::Abs(L - WP) ) {
      L = leff2(k);
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


//   gr2 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr2 = new TGraphAsymmErrors(nbin2,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr2->SetLineColor(6);//color2
  gr2->SetLineWidth(1);
  gr2->SetMarkerColor(6);//color2 6==purple
  gr2->SetMarkerStyle(mark2);
  gr2->SetMarkerSize(1.0);
  gr2->Draw("LP"); 
  Inte1 = gr2->Integral();
//#################################End of my scope : 2 files######################################################///
/////////////////

  float B3, EBD3, EBU3; 
  if ( nfiles >= 3 ) {//>=
  f3->cd();
// number of equivalent events
  // TH1F* h7 = (TH1F*)gROOT->FindObject(htitle);
  

  TH1F* h8 = (TH1F*)gROOT->FindObject(htitle5);
  float nequf3 = h8->Integral(0,nbin3+1);
  cont3(0) = h8->Integral(0,nbin3+1);
  x1[0]=cont3(0)/nequf3;
  for (Int_t k=1; k<nbin3+1; k++) {
    cont3(k) = cont3(k-1) - h8->GetBinContent(k);
    beff3(k) = cont3(k) / nequf3;
    x1[k] = beff3(k);
    ex1[k] = TMath::Sqrt(beff3(k)*(1.-beff3(k))/nequf3);//ne sert à rien dans cette version
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequf3, cont3(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequf3, cont3(k), 0.683, true);
  }  

  L = 100.; 
  B3 = 0.; EBD3 = 0.; EBU3 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  nwp = 0;

    TH1F* h9 = (TH1F*)gROOT->FindObject(htitle6);
  float nequf3bis = h9->Integral(0,nbin3+1);
  cont3(0) = h9->Integral(0,nbin3+1);
  y1[0]=cont3(0)/nequf3bis;
  for (Int_t k=1; k<nbin3+1; k++) {
    cont3(k) = cont3(k-1) - h9->GetBinContent(k);
    leff3(k) = cont3(k) / nequf3bis;
    y1[k] = 0.00005;
    if ( leff3(k) < 0.0005 ) continue;
    y1[k] = leff3(k);
    ey1[k] = TMath::Sqrt(leff3(k)*(1.-leff3(k))/nequf3bis);//ne sert à rien dans cette version
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequf3bis, cont3(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequf3bis, cont3(k), 0.683, true);
    if ( TMath::Abs(leff3(k) - WP) < TMath::Abs(L - WP) ) {
      L = leff3(k);
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

  gr3 = new TGraphAsymmErrors(nbin3,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr3->SetLineColor(color3);
  gr3->SetLineWidth(1);
  gr3->SetMarkerColor(color3);
  gr3->SetMarkerStyle(mark3);
  gr3->SetMarkerSize(1.0);
  gr3->Draw("LP");
  Inte2 = gr3->Integral();
  }

/////////////////

  if ( nfiles >= 4 ) {
  f4->cd();
// number of equivalent events

  TH1F* h12 = (TH1F*)gROOT->FindObject(htitle7);
  float nequf4 = h12->Integral(0,nbin4+1);
  cont4(0) = h12->Integral(0,nbin4+1);
  x1[0]=cont4(0)/nequf4;
  for (Int_t k=1; k<nbin4+1; k++) {
    cont4(k) = cont4(k-1) - h12->GetBinContent(k);
    beff4(k) = cont4(k) / nequf4;
    x1[k] = beff4(k);
    ex1[k] = TMath::Sqrt(beff4(k)*(1.-beff4(k))/nequf4);//ne sert à rien dans cette version
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequf4, cont4(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequf4, cont4(k), 0.683, true);
  }  

  TH1F* h13 = (TH1F*)gROOT->FindObject(htitle8);
  float nequf4bis = h13->Integral(0,nbin4+1);
  cont4(0) = h13->Integral(0,nbin4+1);
  y1[0]=cont4(0)/nequf4bis;
  for (Int_t k=1; k<nbin4+1; k++) {
    cont4(k) = cont4(k-1) - h13->GetBinContent(k);
    leff4(k) = cont4(k) / nequf4bis;
    y1[k] = 0.00005;
    if ( leff4(k) < 0.0005 ) continue;
    y1[k] = leff4(k);
    ey1[k] = TMath::Sqrt(leff4(k)*(1.-leff4(k))/nequf4bis);//ne sert à rien dans cette version
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequf4bis, cont4(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequf4bis, cont4(k), 0.683, true);
  }  


  gr4 = new TGraphAsymmErrors(nbin4,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr4->SetLineColor(color4);
  gr4->SetLineWidth(1);
  gr4->SetMarkerColor(color4);
  gr4->SetMarkerStyle(mark4);
  gr4->SetMarkerSize(1.0);
  gr4->Draw("LP");
  Inte3 = gr4->Integral();
  }
  
/////////////////

/////////////////
  std::cout<< "Inte0 = " << 0.5-Inte0 << "//" <<std::endl;
  std::cout<< "Inte1 = " << 0.5-Inte1 << "//" <<std::endl;
  if (nfiles >=3){ std::cout<< "Inte2 = " << 0.5-Inte2 << "//" <<std::endl;}
  if (nfiles >=4) {std::cout<< "Inte3 = " << 0.5-Inte3 << "//" <<std::endl;}
  /////////////////

  TLegend* leg = new TLegend(0.10,0.90,0.72,0.95);
//   TLegend* leg = new TLegend(0.12,0.82,0.72,0.87);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.038);
  leg->SetHeader(hist);
  leg->Draw();
  
  if ( nfiles != 2 ) leg = new TLegend(0.14,0.62,0.23,0.80);
  else               leg = new TLegend(.14,0.62,0.23,0.80);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.028);
  if ( nfiles == 2 ) leg->SetTextSize(0.035);

  leg->SetHeader("Data");
  leg->AddEntry(gr1,"at1020","P");
  leg->AddEntry(gr2,"at2030","P");
  if (nfiles >=3){ leg->AddEntry(gr3,"at3040","P");}
  if (nfiles >=4) {leg->AddEntry(gr4,"at40XX","P");}
  

  leg->Draw();


c1->Update();

}
