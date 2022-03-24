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
 
//  f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");
//  f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

//  f1 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepCSV.root");
//  f2 = new TFile("../output/TTJets_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15_55nPUtrue76_DeepJet.root");
//  f1 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepCSV.root");
//  f2 = new TFile("../output/TTbar_14TeV_TuneCP5_Pythia8_Run3Summer19MiniAOD-106X_mcRun3_2024_realistic_v4_DeepJet.root");

 f1 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau70_smu250_snu200.root");
 f2 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau50_smu275_snu225.root");
 f3 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau30_smu300_snu250.root");
 f4 = new TFile("/opt/sbg/cms/ui2_data1/pvaucell/LLTopAna/output/h_UDD_bgctau10_smu250_snu200.root");

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
//always check for the bin number when changing the variable
  int nbin =99;
  //int nptbin = 199;//199 //Mettre à 99 si pt, 49 pour eta
  //Sachant que nptbin est associé à h0==pt, nptbin=99 et nbin=49
  
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
  
///////histogram used//////////
   f1->cd();
// // // TString hAllpt = "hTk_pt";//nbin = 99
// // // TString hAlleta = "hTk_eta";//nptbin = 49
// TString htitle = "hTkSim_pt";
// TString htitle2 = "hTkOth_pt";

// // TString hAllpt = "hTk_dr";//nbin = 199
// // TString hAlleta = "hTk_drSig";//nptbin= 199
// TString htitle = "hTkSim_dr";
// TString htitle2 = "hTkOth_dr";

//  TString hAllpt = "hTk_dz";//nbin = 199
// // // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_dz";
// TString htitle2 = "hTkOth_dz";


// TString hAllpt = "hTk_dd";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_dd";
// TString htitle2 = "hTkOth_dd";


// // // TString hAllpt = "hTk_drSig";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_drSig";
// TString htitle2 = "hTkOth_drSig";


// TString hAllpt = "hTk_dzSig";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_dzSig";
// TString htitle2 = "hTkOth_dzSig";


// TString hAllpt = "hTk_ddSig";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_ddSig";
// TString htitle2 = "hTkOth_ddSig";

// TString hAllpt = "hTk_inJet";//nbin = 1
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_inJet";
// TString htitle2 = "hTkOth_inJet";

// TString hAllpt = "hTk_pix";//nbin = 29
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_pix";
// TString htitle2 = "hTkOth_pix";

//  TString hAllpt = "hTk_hit";//nbin = 29
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_hit";
// TString htitle2 = "hTkOth_hit";

//  TString hAllpt = "hTk_chi";//nbin = 49
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_chi";
// TString htitle2 = "hTkOth_chi";

//  TString hAllpt = "hTk_r1";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_r1";
// TString htitle2 = "hTkOth_r1";

// TString hAllpt = "hTk_z1";//nbin = 199
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_z1";
// TString htitle2 = "hTkOth_z1";

// TString hAllpt = "hTk_at10";//nbin = 100
// // // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_at10";
// TString htitle2 = "hTkOth_at10";

// TString hAllpt = "hTk_at20";//nbin = 100
// // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_at20";
// TString htitle2 = "hTkOth_at20";

// TString hAllpt = "hTk_at30";//nbin = 100
// // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_at30";
// TString htitle2 = "hTkOth_at30";

// TString hAllpt = "hTk_at40";//nbin = 100
// // TString hAlleta = "hTk_eta";
// TString htitle = "hTkSim_at40";
// TString htitle2 = "hTkOth_at40";

// number of equivalent events

  TH1F* h0 = (TH1F*)gROOT->FindObject(htitle);//hAllpt
  float nequpt1 = h0->Integral(0,nbin+1);//nptbin
  
  TH1F* h1 = (TH1F*)gROOT->FindObject(htitle);//hAllpt
  float nequpt2 = h1->Integral(0,nbin+1);
  cont(0) = h1->Integral(0,nbin+1);

  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h1->GetBinContent(k);
    beff(k) = cont(k) / nequpt2;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequpt2);//ne sert à rien acuellement
    //std::cout<<"1k = "<< k<< " \\ bool = false "<<"\\ nequpt2 = "<<nequpt2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h1->GetBinContent(k)<<std::endl;
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequpt2, cont(k), 0.683, false);
    //std::cout<<"1k = "<< k<< " \\ bool = true "<<"\\ nequpt2 = "<<nequpt2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h1->GetBinContent(k)<<std::endl;
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequpt2, cont(k), 0.683, true);
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

  h2 = (TH1F*)gROOT->FindObject(htitle2);//htitle

  float nequpt3 = h2->Integral(0,nbin+1);
  cont(0) = h2->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h2->GetBinContent(k);
    leff(k) = cont(k) / nequpt3;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequpt3);//ne sert à rien acuellement
    //std::cout<<"2k = "<< k<< " \\ bool = false "<<"\\ nequpt3 = "<<nequpt3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h2->GetBinContent(k)<<std::endl;
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequpt3, cont(k), 0.683, false);
    //std::cout<<"2k = "<< k<< " \\ bool = true "<<"\\ nequpt3 = "<<nequpt3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h2->GetBinContent(k)<<std::endl;
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequpt3, cont(k), 0.683, true);
    if ( TMath::Abs(leff(k) - WP) < TMath::Abs(L - WP) ) {//WP==0.01: leff(k)>=0.0005: on veut des bins normalisés avec une valeur 
    //supérieure à ce seuil de 0.0005 et ici, 0.01 plus précisement
    //Toujours vérifié: à gauche on compare des grandeurs inférieures à 1, et à droite L=100
      L = leff(k);
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


  // h3 = (TH1F*)gROOT->FindObject(htitle2);//htitle2
  // cont(0) = h3->Integral(0,nbin+1);
  // float nequpt4 = h3->Integral(0,nbin+1);
  // for (Int_t k=1; k<nbin+1; k++) {
  //   cont(k) = cont(k-1) - h3->GetBinContent(k);
  //   ceff(k) = cont(k) / nequpt4;
  //   y2[k] = 0.00005;
  //   if ( ceff(k) < 0.001 ) continue;
  //   y2[k] = ceff(k);
  //   ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequpt4);//ne sert à rien acuellement
  //   //std::cout<<"3k = "<< k<< " \\ bool = false "<<"\\ nequpt4 = "<<nequpt4<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h3->GetBinContent(k)<<std::endl;
  //   ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequpt4, cont(k), 0.683, false);
  //   //std::cout<<"3k = "<< k<< " \\ bool = true "<<"\\ nequpt4 = "<<nequpt4<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h3->GetBinContent(k)<<std::endl;
  //   ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequpt4, cont(k), 0.683, true);
  // }  

//   gr10 = new TGraphErrors(nbin,x1,y2,ex1,ey2);
  // gr10 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  // gr10->SetLineColor(color1);
  // gr10->SetLineWidth(1);
  // gr10->SetMarkerColor(color1);
  // gr10->SetMarkerStyle(markc1);
  // gr10->SetMarkerSize(1.0);
  // gr10->Draw("P"); 

//   gr1 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr1 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr1->SetLineColor(5);//color1
  gr1->SetLineWidth(1);
  gr1->SetMarkerColor(5);//color1
  gr1->SetMarkerStyle(mark1);
  gr1->SetMarkerSize(1.0);
  gr1->Draw("P");
  

//#########################f2###########################//
  f2->cd();//f2 == second parameter is studied
// number of equivalent events
  h3bis = (TH1F*)gROOT->FindObject(htitle);//htitle3
  float nequeta = h3bis->Integral(0,nbin+1);//nptbin


  h4 = (TH1F*)gROOT->FindObject(htitle);//htitle3
  cont(0) = h4->Integral(0,nbin+1);
  float nequeta1 = h4->Integral(0,nbin+1);//comme nbin est plus grand que nptbin, ça marche mais attention

  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h4->GetBinContent(k);
    beff(k) = cont(k) / nequeta1;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequeta1);//ne sert à rien acuellement
    //std::cout<<"4k = "<< k<< " \\ bool = false "<<"\\ nequeta1 = "<<nequeta1<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h4->GetBinContent(k)<<std::endl;
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequeta1, cont(k), 0.683, false);
    //std::cout<<"4k = "<< k<< " \\ bool = true "<<"\\ nequeta1 = "<<nequeta1<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h4->GetBinContent(k)<<std::endl;
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequeta1, cont(k), 0.683, true);
  }  

  L = 100.; 
  float B2 = 0., EBD2 = 0., EBU2 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  int kWP2 = 0;
  nwp = 0;


  h5 = (TH1F*)gROOT->FindObject(htitle2);//htitle3
  cont(0) = h5->Integral(0,nbin+1);
  float nequeta2 = h5->Integral(0,nbin+1);

  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h5->GetBinContent(k);
    leff(k) = cont(k) / nequeta2;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;//pour ça que ça s'arrête à 49 itérations contrairement à h4
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequeta2);//ne sert à rien acuellement
    //std::cout<<"5k = "<< k<< " \\ bool = false \\"<<"\\ nequeta2 = "<<nequeta2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h5->GetBinContent(k)<<std::endl;
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequeta2, cont(k), 0.683, false);
    //std::cout<<"5k = "<< k<< " \\ bool = true "<<"\\ nequeta2 = "<<nequeta2<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h5->GetBinContent(k)<<std::endl;
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequeta2, cont(k), 0.683, true);
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

  // h6 = (TH1F*)gROOT->FindObject(htitle2);//htitle4
  // cont(0) = h6->Integral(0,nbin+1);
  // float nequeta3 = h6->Integral(0,nbin+1);
  // for (Int_t k=1; k<nbin+1; k++) {
  //   cont(k) = cont(k-1) - h6->GetBinContent(k);
  //   ceff(k) = cont(k) / nequeta3;
  //   y2[k] = 0.00005;
  //   if ( ceff(k) < 0.001 ) continue;
  //   y2[k] = ceff(k);
  //   ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequeta3);//ne sert à rien acuellement
  //   //std::cout<<"6k = "<< k<< " \\ bool = false "<<"\\ nequeta3 = "<<nequeta3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h6->GetBinContent(k)<<std::endl;
  //   ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequeta3, cont(k), 0.683, false);
  //   //std::cout<<"6k = "<< k<< " \\ bool = false "<<"\\ nequeta3 = "<<nequeta3<<"\\ cont(k) = "<<cont(k)<< "\\ bin content (k) = "<<h6->GetBinContent(k)<<std::endl;
  //   ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequeta3, cont(k), 0.683, true);
  // }  

//   gr20 = new TGraphErrors(nbin,x1,y2,ex1,ey2);
  // gr20 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  // gr20->SetLineColor(color2);
  // gr20->SetLineWidth(1);
  // gr20->SetMarkerColor(color2);
  // gr20->SetMarkerStyle(markc2);
  // gr20->SetMarkerSize(1.0);
  // gr20->Draw("P"); 

//   gr2 = new TGraphErrors(nbin,x1,y1,ex1,ey1);
  gr2 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr2->SetLineColor(6);//color2
  gr2->SetLineWidth(1);
  gr2->SetMarkerColor(6);//color2 6==purple
  gr2->SetMarkerStyle(mark2);
  gr2->SetMarkerSize(1.0);
  gr2->Draw("P"); 

//#################################End of my scope : 2 files######################################################///
/////////////////

  float B3, EBD3, EBU3; 
  //if ( nfiles == 3 ) {//>=
  f3->cd();
// number of equivalent events
  h7 = (TH1F*)gROOT->FindObject(htitle);
  float nequf3 = h7->Integral(0,nbin+1);

  h8 = (TH1F*)gROOT->FindObject(htitle);
  cont(0) = h8->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h8->GetBinContent(k);
    beff(k) = cont(k) / nequf3;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequf3);//ne sert à rien dans cette version
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequf3, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequf3, cont(k), 0.683, true);
  }  

  L = 100.; 
  B3 = 0.; EBD3 = 0.; EBU3 = 0.; 
  bwp = 0.; bwpd = 10.; bwpu = -10.; 
  BWP = 0.; EBWPD = 0.; EBWPU = 0.; 
  nwp = 0;

  h9 = (TH1F*)gROOT->FindObject(htitle2);
  float nequf3bis = h9->Integral(0,nbin+1);
  cont(0) = h9->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h9->GetBinContent(k);
    leff(k) = cont(k) / nequf3bis;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequf3bis);//ne sert à rien dans cette version
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequf3bis, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequf3bis, cont(k), 0.683, true);
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

  // h10 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  // cont(0) = h1->Integral(0,nbin+1);
  // for (Int_t k=1; k<nbin+1; k++) {
  //   cont(k) = cont(k-1) - h1->GetBinContent(k);
  //   ceff(k) = cont(k) / nequCFlav;
  //   y2[k] = 0.00005;
  //   if ( ceff(k) < 0.001 ) continue;
  //   y2[k] = ceff(k);
  //   ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
  //   ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
  //   ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  // }  


  // gr30 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  // gr30->SetLineColor(color3);
  // gr30->SetLineWidth(1);
  // gr30->SetMarkerColor(color3);
  // gr30->SetMarkerStyle(markc3);
  // gr30->SetMarkerSize(1.0);
  // gr30->Draw("P"); 

  gr3 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr3->SetLineColor(color3);
  gr3->SetLineWidth(1);
  gr3->SetMarkerColor(color3);
  gr3->SetMarkerStyle(mark3);
  gr3->SetMarkerSize(1.0);
  gr3->Draw("P"); 
  //}

/////////////////

  //if ( nfiles == 4 ) {
  f4->cd();
// number of equivalent events

  h12 = (TH1F*)gROOT->FindObject(htitle);
  float nequf4 = h12->Integral(0,nbin+1);
  cont(0) = h12->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h12->GetBinContent(k);
    beff(k) = cont(k) / nequf4;
    x1[k] = beff(k);
    ex1[k] = TMath::Sqrt(beff(k)*(1.-beff(k))/nequf4);//ne sert à rien dans cette version
    ex1d[k] =  x1[k] - EfficiencyUtil->ClopperPearson(nequf4, cont(k), 0.683, false);
    ex1u[k] = -x1[k] + EfficiencyUtil->ClopperPearson(nequf4, cont(k), 0.683, true);
  }  

  h13 = (TH1F*)gROOT->FindObject(htitle2);
  float nequf4bis = h13->Integral(0,nbin+1);
  cont(0) = h13->Integral(0,nbin+1);
  for (Int_t k=1; k<nbin+1; k++) {
    cont(k) = cont(k-1) - h13->GetBinContent(k);
    leff(k) = cont(k) / nequf4bis;
    y1[k] = 0.00005;
    if ( leff(k) < 0.0005 ) continue;
    y1[k] = leff(k);
    ey1[k] = TMath::Sqrt(leff(k)*(1.-leff(k))/nequf4bis);//ne sert à rien dans cette version
    ey1d[k] =  y1[k] - EfficiencyUtil->ClopperPearson(nequf4bis, cont(k), 0.683, false);
    ey1u[k] = -y1[k] + EfficiencyUtil->ClopperPearson(nequf4bis, cont(k), 0.683, true);
  }  

  // h14 = (TH1F*)gROOT->FindObject("hCFlav_PosTagger_etaLT25");
  // cont(0) = h14->Integral(0,nbin+1);
  // for (Int_t k=1; k<nbin+1; k++) {
  //   cont(k) = cont(k-1) - h14->GetBinContent(k);
  //   ceff(k) = cont(k) / nequCFlav;
  //   y2[k] = 0.00005;
  //   if ( ceff(k) < 0.001 ) continue;
  //   y2[k] = ceff(k);
  //   ey2[k] = TMath::Sqrt(ceff(k)*(1.-ceff(k))/nequCFlav);
  //   ey2d[k] =  y2[k] - EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, false);
  //   ey2u[k] = -y2[k] + EfficiencyUtil->ClopperPearson(nequCFlav, cont(k), 0.683, true);
  // }  

  // gr40 = new TGraphAsymmErrors(nbin,x1,y2,ex1d,ex1u,ey2d,ey2u);
  // gr40->SetLineColor(color4);
  // gr40->SetLineWidth(1);
  // gr40->SetMarkerColor(color4);
  // gr40->SetMarkerStyle(markc4);
  // gr40->SetMarkerSize(1.0);
  // gr40->Draw("P"); 

  gr4 = new TGraphAsymmErrors(nbin,x1,y1,ex1d,ex1u,ey1d,ey1u);
  gr4->SetLineColor(color4);
  gr4->SetLineWidth(1);
  gr4->SetMarkerColor(color4);
  gr4->SetMarkerStyle(mark4);
  gr4->SetMarkerSize(1.0);
  gr4->Draw("P"); 
  //}

/////////////////

  TLegend* leg = new TLegend(0.10,0.90,0.72,0.95);
//   TLegend* leg = new TLegend(0.12,0.82,0.72,0.87);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.038);
  leg->SetHeader(hAllpt);
  leg->Draw();
  
  if ( nfiles != 2 ) leg = new TLegend(0.14,0.62,0.37,0.85);
  else               leg = new TLegend(.14,0.62,0.37,0.85);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  leg->SetTextSize(0.028);
  if ( nfiles == 2 ) leg->SetTextSize(0.035);

  leg->SetHeader("Data");
  leg->AddEntry(gr1,"bgctau70","P");
  leg->AddEntry(gr2,"bgctau50","P");
  leg->AddEntry(gr3,"bgctau30","P");
  leg->AddEntry(gr4,"bgctau10","P");

  leg->Draw();
/*  
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
*/
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
//##################################################################"//

c1->Update();

}
