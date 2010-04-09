#ifndef Utilities_hh
#define Utilities_hh

#include "TROOT.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TString.h"
#include "TMath.h"

#include <stdio.h>
#include <stdlib.h>

namespace Util {
  //__________________________________________________________________________
  inline TString MakeOutputDir(TString dir){
    if(!dir.EndsWith("/")) dir += "/";
    // Create directory if needed
    //  >> NOTE: This function needs to be called before the booking functions!
    char cmd[100];
    sprintf(cmd,"mkdir -p %s", dir.Data());
    system(cmd);
    return dir;
  }

  //__________________________________________________________________________
  inline void SetStyle(){
    TStyle *style = new TStyle("ETHStyle", "Standard Plain");
    style->SetCanvasColor(0);
    style->SetFrameFillColor(0);
    style->SetFrameBorderMode(0);
    style->SetFrameBorderSize(0);
    style->SetPalette(1,0);
    style->SetOptTitle(0);
    style->SetOptStat(111111);
    style->SetStatColor(0);
    style->SetStatStyle(3001);
    style->SetStatBorderSize(1);

    // Fonts
    Int_t font = 42;
    style->SetStatFont(font);
    style->SetTextFont(font);
    style->SetLabelFont(font, "xyz");
    style->SetTitleFont(font, "xyz");

    // Histograms
    style->SetHistFillColor(15);
    style->SetHistFillStyle(1001);
    style->SetHistLineWidth(2);
    gROOT->SetStyle("ETHStyle");
    gROOT->ForceStyle();
  }

 //__________________________________________________________________________
  inline void PrintPNG(TCanvas *cin, TString name, TString dir){
    // Prints a ROOT TCanvas Object to a .png file
    //  name is the bare output filename, e.g. "fit_4_8",
    //  dir is the output directory (inside the overall output dir.)
    // Create sub directories if needed
    if(!dir.EndsWith("/")) dir += "/";
    char cmd[100];
    sprintf(cmd,"mkdir -p %s", dir.Data());
    system(cmd);

    dir += name;
    dir += ".png";
    cin->Print(dir,"png");
  }

  //__________________________________________________________________________
  inline void PrintPDF(TCanvas *cin, TString name, TString dir){
    // Prints a ROOT TCanvas Object to a .png file
    //  name is the bare output filename, e.g. "fit_4_8",
    //  dir is the output directory (inside the overall output dir.)
    // Create sub directories if needed
    if(!dir.EndsWith("/")) dir += "/";
    char cmd[100];
    sprintf(cmd,"mkdir -p %s", dir.Data());
    system(cmd);

    dir += name;
    dir += ".pdf";
    cin->Print(dir,"pdf");
  }

  //__________________________________________________________________________
  inline void PrintEPS(TCanvas *cin, TString name, TString dir){
    // Prints a ROOT TCanvas Object to a .eps file
    //  name is the bare output filename, e.g. "fit_4_8",
    //  dir is the output directory (inside the overall output dir.)
    // Create sub directories if needed
    if(!dir.EndsWith("/")) dir += "/";
    char cmd[100];
    sprintf(cmd,"mkdir -p %s", dir.Data());
    system(cmd);

    dir += name;
    dir += ".eps";
    cin->Print(dir,"eps");
  }

  //__________________________________________________________________________
  inline void PrintBoth(TCanvas *cin, TString name, TString dir) {
    // Print both EPS and PNG
    Util::PrintPNG(cin,name,dir);
    Util::PrintEPS(cin,name,dir);
  }

   //__________________________________________________________________________
  inline double DeltaPhi(double v1, double v2){
    // Computes the correctly normalized phi difference
    // v1, v2 = phi of object 1 and 2
    double diff = fabs(v2 - v1);
    double corr = TMath::TwoPi() - diff;
    if (diff < TMath::Pi()){ return diff;} else { return corr;}
  }

  //__________________________________________________________________________
  inline double GetDeltaR(double eta1, double eta2, double phi1, double phi2){
    // Computes the DeltaR of two objects from their eta and phi values
    return sqrt( (eta1-eta2)*(eta1-eta2)
                 + Util::DeltaPhi(phi1, phi2)*Util::DeltaPhi(phi1, phi2) );
  }

}

#endif
