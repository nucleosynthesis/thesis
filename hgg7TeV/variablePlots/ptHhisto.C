// Make the ptHiggs plot for 2011 Signal MC
//
#include "TROOT.h"
#include "TMath.h"
#include "TFile.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TFile.h"
#include "THStack.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include <iostream>
using namespace std;

struct struct_histo{

	std::string name;
	std::string xLabel;
	std::string yLabel;
	double xMin;
	double xMax;  
	double yMin;
	double yMax;  
	int nBins;
	bool isLog;
} ;

void makeVarPlots(){

	// Global Style ---- //
//	gROOT->ProcessLine(".x tdrstyle.cc");
	gROOT->SetBatch(true);
	gStyle->SetOptStat(0);
	
	// Font
	int fSTYLE = 42;
	double fSIZE = 0.032;

	// Canvas size
	int gcWIDTH  = 800;
	int gcHEIGHT = 600;

	// Y-axis offset
	double yOFFSET = 1.25;

	// Legend
	double tX1 = 0.49;
	double tX2 = 0.88;
	double tY1 = 0.6;
	double tY2 = 0.88;

	// Some Global strings
	std::string cmsPRE   = "CMS Simulation";
	std::string cmsLUMI  = "";
	std::string cmsSQRTS = "#sqrt{s} = 7 TeV m_{H} = 125 GeV";
		
	// Color Map 1 -- Blue -> Gray scales
	int cSIGNAL = kRed+1;
	int cPP	= kGray+2;
	int cFF	= kGray;
	int cDY	= kBlue+2;
	int cPF = kWhite;
	int cDATA=kBlack;

	// Color Map 2 -- Red -> Yellow scales
	/*
	int cSIGNAL = kBlue-2;
	int cFF	= kYellow;
	int cPF	= kOrange+1;
	int cDY	= kWhite;
	int cPP = kRed+2;
	int cDATA=kBlack;
	*/

	// Lines/styles
	int cLINEWIDTH  = 2;
	int cLINESTYLE  = 1;
	int cMARKER = 20;
	double cMSIZE  = 0.8;
	int cFILL   = 1001;
	
	// Signal Scale
	int scSIGNAL = 10;
	int scMASS   = 125;

	// Labels
	std::string lSIGNAL = (std::string)Form("%d#timesSM Higgs m_{H} = %d GeV",scSIGNAL,scMASS);
	std::string lPP	    = "#gamma-#gamma";
	std::string lPF	    = "#gamma-j";
	std::string lFF	    = "j-j";
	std::string lDY	    = "Z#rightarrow e^{+}e^{-}";
	std::string lDATA   = "Data";

//	std::string gCUT    = "weight*(bdtoutput>0.05 && mass < 180 && mass >= 100)";
	std::string gCUT    = "weight*(mass < 180 && mass >= 100)";
	// START ------------------------------------//
	
	std::string sName = "hgg-trees-2011-sig.root";
	std::string bName = "hgg-trees-2011-bkg.root";

	TFile *sFile = TFile::Open(sName.c_str());
	TFile *bFile = TFile::Open(bName.c_str());

	// Data
	std::string n_data = "Data";

	// Signal 
	std::string n_ggh = Form("gluglu_H_gg_%d_pu2011",scMASS);
	std::string n_vbf = Form("vbf_H_gg_%d_pu2011",scMASS);
	std::string n_wzh = Form("wz_H_gg_%d_pu2011",scMASS);
	std::string n_tth = Form("tt_H_gg_%d_pu2011",scMASS);
	
	// PP Background
	std::string n_ppjets = "DiPhotonJets";
	std::string n_box    = "Box25";

	// PF Background 
	std::string n_qcd30_pf = "QCD30PF";
	std::string n_qcd40_pf = "QCD40PF";
	std::string n_gjet     = "GJet";

	// FF Background 
	std::string n_qcd30_ff = "QCD30FF";
	std::string n_qcd40_ff = "QCD40FF";

	// DY - ee
	std::string n_dyee = "DYJetsToLL";

	std::cout << "Gathering Trees .... " << std::endl;
	// Gather the Trees 
	TTree *t_ggh 		= (TTree*) sFile->Get(n_ggh.c_str());
	TTree *t_vbf 		= (TTree*) sFile->Get(n_vbf.c_str());
	TTree *t_wzh 		= (TTree*) sFile->Get(n_wzh.c_str());
	TTree *t_tth 		= (TTree*) sFile->Get(n_tth.c_str());
	std::cout << ".... Done" << std::endl;

	// ---------------------------------------------------------------------------------------------------------------------------------------------------
	// Variables that are to be drawn
	std::vector<struct_histo> vars;
	struct_histo v_ptH; v_ptH.name = "ptH"; v_ptH.xLabel = "p_{T}^{H} GeV"; v_ptH.yLabel = "Arbitrary Units"; v_ptH.nBins = 100; v_ptH.xMin=0;v_ptH.xMax = 200; v_ptH.isLog=false;v_ptH.yMin=-10;v_ptH.yMax=-1;

	// Add the variables
	vars.push_back(v_ptH);
	// ---------------------------------------------------------------------------------------------------------------------------------------------------
	
	int pCOUNT = 0;
	std::vector<struct_histo>::iterator it_vars  = vars.begin();
	std::vector<struct_histo>::iterator end_vars = vars.end();


	for (pCOUNT=0;it_vars!=end_vars;it_vars++,pCOUNT++){

		std::cout << "About to create Histograms .... " << std::endl;
		std::cout << "Data + Signal .... " << std::endl;
		t_ggh->Draw(Form(	"%s>>h_ggh_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_vbf->Draw(Form(	"%s>>h_vbf_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_wzh->Draw(Form(	"%s>>h_wzh_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_tth->Draw(Form(	"%s>>h_tth_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));

		// find the objects
		std::cout << "Finding Histograms .... " << std::endl;
		TH1F *h_ggh	= (TH1F*) gROOT->FindObject(Form("h_ggh_%s",(*it_vars).name.c_str()));
		TH1F *h_vbf 	= (TH1F*) gROOT->FindObject(Form("h_vbf_%s",(*it_vars).name.c_str()));
		TH1F *h_wzh 	= (TH1F*) gROOT->FindObject(Form("h_wzh_%s",(*it_vars).name.c_str()));
		TH1F *h_tth 	= (TH1F*) gROOT->FindObject(Form("h_tth_%s",(*it_vars).name.c_str()));
		std::cout << ".... Done" << std::endl;

		// Have the histograms so now need to put them together
		
		// Scale the signals to unit area
		h_ggh->Scale(1./h_ggh->Integral());
		h_wzh->Scale(1./h_wzh->Integral());
		h_vbf->Scale(1./h_vbf->Integral());
		h_tth->Scale(1./h_tth->Integral());


		// GGH is the one with the labels
		h_ggh->SetTitle("");
		h_ggh->GetYaxis()->SetTitle((*it_vars).yLabel.c_str());
		h_ggh->GetXaxis()->SetTitle((*it_vars).xLabel.c_str());
		h_ggh->SetMarkerStyle(cMARKER);
		h_ggh->SetMarkerSize(cMSIZE);
		h_ggh->SetMarkerColor(cDATA);
		h_ggh->GetYaxis()->SetTitleOffset(yOFFSET);
		if ((*it_vars).yMin > -1 ) h_ggh->SetMinimum((*it_vars).yMin);
		if ((*it_vars).yMax > -1 ) h_ggh->SetMaximum((*it_vars).yMax);


		h_ggh->SetLineWidth(cLINEWIDTH);
		h_ggh->SetLineStyle(cLINESTYLE);
		h_ggh->SetFillStyle(0);	// Signal has no fill
		h_ggh->SetLineColor(kBlue);

		h_vbf->SetLineWidth(cLINEWIDTH);
		h_vbf->SetLineStyle(cLINESTYLE);
		h_vbf->SetFillStyle(0);	// Signal has no fill
		h_vbf->SetLineColor(kRed);

		h_wzh->SetLineWidth(cLINEWIDTH);
		h_wzh->SetLineStyle(cLINESTYLE);
		h_wzh->SetFillStyle(0);	// Signal has no fill
		h_wzh->SetLineColor(kGreen+2);

		h_tth->SetLineWidth(cLINEWIDTH);
		h_tth->SetLineStyle(cLINESTYLE);
		h_tth->SetFillStyle(0);	// Signal has no fill
		h_tth->SetLineColor(kMagenta+1);

		TLegend *tLEG = new TLegend(tX1,tY1,tX2,tY2);
		tLEG->SetTextFont(fSTYLE);
		tLEG->SetTextSize(fSIZE);
	
		tLEG->SetFillColor(kWhite);
		tLEG->AddEntry(h_ggh,"gg Fusion","L");
		tLEG->AddEntry(h_vbf,"Vector Boson Fusion","L");
		tLEG->AddEntry(h_wzh,"W/Z Associated","L");
		tLEG->AddEntry(h_tth,"t#bar{t} Associated","L");

		// Finally Make Canvas and Draw
		TCanvas *can = new TCanvas(Form("c%d",pCOUNT),"c",gcWIDTH,gcHEIGHT); can->cd();
		can->SetLogy((*it_vars).isLog);

		h_ggh->Draw("hist");
		h_vbf->Draw("histsame");
		h_wzh->Draw("histsame");
		h_tth->Draw("histsame");

		tLEG->Draw();

  		gPad->RedrawAxis();

		TLatex *txt = new TLatex();
		txt->SetTextSize(fSIZE);	txt->SetNDC(); txt->SetTextFont(fSTYLE);
		txt->DrawLatex(0.1,0.91,cmsPRE.c_str());
		txt->DrawLatex(0.65,0.91,cmsSQRTS.c_str());
		
		can->SaveAs(Form("%s.pdf",(*it_vars).name.c_str()));

	}
                         
}                
