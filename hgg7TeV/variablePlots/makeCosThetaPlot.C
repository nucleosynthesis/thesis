// Make all 2011 h->gg variable plots for thesis
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
#include "TLorentzVector.h"
#include "TLatex.h"
#include <iostream>
using namespace std;

double px1,py1,pz1,e1;
double px2,py2,pz2,e2;
double w;
double bdtoutput,mass;

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

void fillCosThetaHistogram(TTree *t, TH1F *h){
	for (int ci=0;ci<t->GetEntries();ci++){

    		t->GetEntry(ci);
	
    		TLorentzVector p1(px1,py1,pz1,e1);    
    		TLorentzVector p2(px2,py2,pz2,e2);    
    		TLorentzVector H = p1+p2;
    
   		p1.Boost(-1*H.BoostVector());

		if (bdtoutput > 0.05 && mass < 180 && mass >= 100){
			h->Fill(p1.Theta(),w);
		}


	}
};

void makeCosThetaPlot(){

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
	std::string cmsPRE   = "CMS Preliminary";
	std::string cmsLUMI  = "L = 5.1 fb^{-1}";
	std::string cmsSQRTS = "#sqrt{s} = 7 TeV L = 5.1 fb^{-1}";
		
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
	int scSIGNAL = 1;
	int scMASS   = 125;

	// Labels
	std::string lSIGNAL = (std::string)Form("%d#timesSM Higgs m_{H} = %d GeV",scSIGNAL,scMASS);
	std::string lPP	    = "#gamma-#gamma";
	std::string lPF	    = "#gamma-j";
	std::string lFF	    = "j-j";
	std::string lDY	    = "Z#rightarrow e^{+}e^{-}";
	std::string lDATA   = "Data";

	std::string gCUT    = "weight*(bdtoutput>0.05 && mass < 180 && mass >= 100)";
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
	TTree *t_data 		= (TTree*) sFile->Get(n_data.c_str());
	TTree *t_ggh 		= (TTree*) sFile->Get(n_ggh.c_str());
	TTree *t_vbf 		= (TTree*) sFile->Get(n_vbf.c_str());
	TTree *t_wzh 		= (TTree*) sFile->Get(n_wzh.c_str());
	TTree *t_tth 		= (TTree*) sFile->Get(n_tth.c_str());
	TTree *t_ppjets 	= (TTree*) bFile->Get(n_ppjets.c_str());
	TTree *t_box     	= (TTree*) bFile->Get(n_box.c_str());
	TTree *t_qcd30_pf 	= (TTree*) bFile->Get(n_qcd30_pf.c_str());
	TTree *t_qcd40_pf 	= (TTree*) bFile->Get(n_qcd40_pf.c_str());
	TTree *t_gjet     	= (TTree*) bFile->Get(n_gjet.c_str());
	TTree *t_qcd30_ff	= (TTree*) bFile->Get(n_qcd30_ff.c_str());
	TTree *t_qcd40_ff	= (TTree*) bFile->Get(n_qcd40_ff.c_str());
	TTree *t_dyee		= (TTree*) bFile->Get(n_dyee.c_str());
	std::cout << ".... Done" << std::endl;

  	TH1F *h_data 	 = new TH1F("h_data",";#theta^{*};",50,0,TMath::Pi());
  	TH1F *h_ggh 	 = new TH1F("h_ggh",";#theta^{*};",50,0,TMath::Pi());
  	TH1F *h_ppjets 	 = new TH1F("h_ppjets",";#theta^{*};",50,0,TMath::Pi());
  	TH1F *h_qcd30_pf = new TH1F("h_qcd30_pf",";#theta^{*};",50,0,TMath::Pi());
  	TH1F *h_qcd30_ff = new TH1F("h_qcd30_ff",";#theta^{*};",50,0,TMath::Pi());
  	TH1F *h_dyee 	 = new TH1F("h_dyee",";#theta^{*};",50,0,TMath::Pi());


	// Set All the Branches together -----------------------------------//
  	t_data->SetBranchAddress("weight",&w);  
  	t_data->SetBranchAddress("mass",&mass);  
  	t_data->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_data->SetBranchAddress("ph1_e",&e1);
  	t_data->SetBranchAddress("ph1_px",&px1);
  	t_data->SetBranchAddress("ph1_py",&py1);
  	t_data->SetBranchAddress("ph1_pz",&pz1);
  	t_data->SetBranchAddress("ph2_e",&e2);
  	t_data->SetBranchAddress("ph2_px",&px2);
  	t_data->SetBranchAddress("ph2_py",&py2);
  	t_data->SetBranchAddress("ph2_pz",&pz2);

  	t_ggh->SetBranchAddress("weight",&w);  
  	t_ggh->SetBranchAddress("mass",&mass);  
  	t_ggh->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_ggh->SetBranchAddress("ph1_e",&e1);
  	t_ggh->SetBranchAddress("ph1_px",&px1);
  	t_ggh->SetBranchAddress("ph1_py",&py1);
  	t_ggh->SetBranchAddress("ph1_pz",&pz1);
  	t_ggh->SetBranchAddress("ph2_e",&e2);
  	t_ggh->SetBranchAddress("ph2_px",&px2);
  	t_ggh->SetBranchAddress("ph2_py",&py2);
  	t_ggh->SetBranchAddress("ph2_pz",&pz2);

  	t_wzh->SetBranchAddress("weight",&w);  
  	t_wzh->SetBranchAddress("mass",&mass);  
  	t_wzh->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_wzh->SetBranchAddress("ph1_e",&e1);
  	t_wzh->SetBranchAddress("ph1_px",&px1);
  	t_wzh->SetBranchAddress("ph1_py",&py1);
  	t_wzh->SetBranchAddress("ph1_pz",&pz1);
  	t_wzh->SetBranchAddress("ph2_e",&e2);
  	t_wzh->SetBranchAddress("ph2_px",&px2);
  	t_wzh->SetBranchAddress("ph2_py",&py2);
  	t_wzh->SetBranchAddress("ph2_pz",&pz2);

  	t_tth->SetBranchAddress("weight",&w);  
  	t_tth->SetBranchAddress("mass",&mass);  
  	t_tth->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_tth->SetBranchAddress("ph1_e",&e1);
  	t_tth->SetBranchAddress("ph1_px",&px1);
  	t_tth->SetBranchAddress("ph1_py",&py1);
  	t_tth->SetBranchAddress("ph1_pz",&pz1);
  	t_tth->SetBranchAddress("ph2_e",&e2);
  	t_tth->SetBranchAddress("ph2_px",&px2);
  	t_tth->SetBranchAddress("ph2_py",&py2);
  	t_tth->SetBranchAddress("ph2_pz",&pz2);

  	t_vbf->SetBranchAddress("weight",&w);  
  	t_vbf->SetBranchAddress("mass",&mass);  
  	t_vbf->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_vbf->SetBranchAddress("ph1_e",&e1);
  	t_vbf->SetBranchAddress("ph1_px",&px1);
  	t_vbf->SetBranchAddress("ph1_py",&py1);
  	t_vbf->SetBranchAddress("ph1_pz",&pz1);
  	t_vbf->SetBranchAddress("ph2_e",&e2);
  	t_vbf->SetBranchAddress("ph2_px",&px2);
  	t_vbf->SetBranchAddress("ph2_py",&py2);
  	t_vbf->SetBranchAddress("ph2_pz",&pz2);

  	t_ppjets->SetBranchAddress("weight",&w);  
  	t_ppjets->SetBranchAddress("mass",&mass);  
  	t_ppjets->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_ppjets->SetBranchAddress("ph1_e",&e1);
  	t_ppjets->SetBranchAddress("ph1_px",&px1);
  	t_ppjets->SetBranchAddress("ph1_py",&py1);
  	t_ppjets->SetBranchAddress("ph1_pz",&pz1);
  	t_ppjets->SetBranchAddress("ph2_e",&e2);
  	t_ppjets->SetBranchAddress("ph2_px",&px2);
  	t_ppjets->SetBranchAddress("ph2_py",&py2);
  	t_ppjets->SetBranchAddress("ph2_pz",&pz2);

  	t_box->SetBranchAddress("weight",&w);  
  	t_box->SetBranchAddress("mass",&mass);  
  	t_box->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_box->SetBranchAddress("ph1_e",&e1);
  	t_box->SetBranchAddress("ph1_px",&px1);
  	t_box->SetBranchAddress("ph1_py",&py1);
  	t_box->SetBranchAddress("ph1_pz",&pz1);
  	t_box->SetBranchAddress("ph2_e",&e2);
  	t_box->SetBranchAddress("ph2_px",&px2);
  	t_box->SetBranchAddress("ph2_py",&py2);
  	t_box->SetBranchAddress("ph2_pz",&pz2);

  	t_qcd30_pf->SetBranchAddress("weight",&w);  
  	t_qcd30_pf->SetBranchAddress("mass",&mass);  
  	t_qcd30_pf->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_qcd30_pf->SetBranchAddress("ph1_e",&e1);
  	t_qcd30_pf->SetBranchAddress("ph1_px",&px1);
  	t_qcd30_pf->SetBranchAddress("ph1_py",&py1);
  	t_qcd30_pf->SetBranchAddress("ph1_pz",&pz1);
  	t_qcd30_pf->SetBranchAddress("ph2_e",&e2);
  	t_qcd30_pf->SetBranchAddress("ph2_px",&px2);
  	t_qcd30_pf->SetBranchAddress("ph2_py",&py2);
  	t_qcd30_pf->SetBranchAddress("ph2_pz",&pz2);

  	t_qcd40_pf->SetBranchAddress("weight",&w);  
  	t_qcd40_pf->SetBranchAddress("mass",&mass);  
  	t_qcd40_pf->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_qcd40_pf->SetBranchAddress("ph1_e",&e1);
  	t_qcd40_pf->SetBranchAddress("ph1_px",&px1);
  	t_qcd40_pf->SetBranchAddress("ph1_py",&py1);
  	t_qcd40_pf->SetBranchAddress("ph1_pz",&pz1);
  	t_qcd40_pf->SetBranchAddress("ph2_e",&e2);
  	t_qcd40_pf->SetBranchAddress("ph2_px",&px2);
  	t_qcd40_pf->SetBranchAddress("ph2_py",&py2);
  	t_qcd40_pf->SetBranchAddress("ph2_pz",&pz2);

  	t_gjet->SetBranchAddress("weight",&w);  
  	t_gjet->SetBranchAddress("mass",&mass);  
  	t_gjet->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_gjet->SetBranchAddress("ph1_e",&e1);
  	t_gjet->SetBranchAddress("ph1_px",&px1);
  	t_gjet->SetBranchAddress("ph1_py",&py1);
  	t_gjet->SetBranchAddress("ph1_pz",&pz1);
  	t_gjet->SetBranchAddress("ph2_e",&e2);
  	t_gjet->SetBranchAddress("ph2_px",&px2);
  	t_gjet->SetBranchAddress("ph2_py",&py2);
  	t_gjet->SetBranchAddress("ph2_pz",&pz2);

  	t_qcd30_ff->SetBranchAddress("weight",&w);  
  	t_qcd30_ff->SetBranchAddress("mass",&mass);  
  	t_qcd30_ff->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_qcd30_ff->SetBranchAddress("ph1_e",&e1);
  	t_qcd30_ff->SetBranchAddress("ph1_px",&px1);
  	t_qcd30_ff->SetBranchAddress("ph1_py",&py1);
  	t_qcd30_ff->SetBranchAddress("ph1_pz",&pz1);
  	t_qcd30_ff->SetBranchAddress("ph2_e",&e2);
  	t_qcd30_ff->SetBranchAddress("ph2_px",&px2);
  	t_qcd30_ff->SetBranchAddress("ph2_py",&py2);
  	t_qcd30_ff->SetBranchAddress("ph2_pz",&pz2);

  	t_qcd40_ff->SetBranchAddress("weight",&w);  
  	t_qcd40_ff->SetBranchAddress("mass",&mass);  
  	t_qcd40_ff->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_qcd40_ff->SetBranchAddress("ph1_e",&e1);
  	t_qcd40_ff->SetBranchAddress("ph1_px",&px1);
  	t_qcd40_ff->SetBranchAddress("ph1_py",&py1);
  	t_qcd40_ff->SetBranchAddress("ph1_pz",&pz1);
  	t_qcd40_ff->SetBranchAddress("ph2_e",&e2);
  	t_qcd40_ff->SetBranchAddress("ph2_px",&px2);
  	t_qcd40_ff->SetBranchAddress("ph2_py",&py2);
  	t_qcd40_ff->SetBranchAddress("ph2_pz",&pz2);

  	t_dyee->SetBranchAddress("weight",&w);  
  	t_dyee->SetBranchAddress("mass",&mass);  
  	t_dyee->SetBranchAddress("bdtoutput",&bdtoutput);  
  	t_dyee->SetBranchAddress("ph1_e",&e1);
  	t_dyee->SetBranchAddress("ph1_px",&px1);
  	t_dyee->SetBranchAddress("ph1_py",&py1);
  	t_dyee->SetBranchAddress("ph1_pz",&pz1);
  	t_dyee->SetBranchAddress("ph2_e",&e2);
  	t_dyee->SetBranchAddress("ph2_px",&px2);
  	t_dyee->SetBranchAddress("ph2_py",&py2);
  	t_dyee->SetBranchAddress("ph2_pz",&pz2);

	// data plot ------------------------------------------------------// 
	fillCosThetaHistogram(t_data,h_data);
	// signal plot ----------------------------------------------------// 
	fillCosThetaHistogram(t_ggh,h_ggh);
	fillCosThetaHistogram(t_wzh,h_ggh);
	fillCosThetaHistogram(t_tth,h_ggh);
	fillCosThetaHistogram(t_vbf,h_ggh);
	// pp plot ----------------------------------------------------// 
	fillCosThetaHistogram(t_ppjets,h_ppjets);
	fillCosThetaHistogram(t_box,h_ppjets);
	// pf plot ----------------------------------------------------// 
	fillCosThetaHistogram(t_qcd30_pf,h_qcd30_pf);
	fillCosThetaHistogram(t_qcd40_pf,h_qcd30_pf);
	fillCosThetaHistogram(t_gjet,h_qcd30_pf);
	// ff plot ----------------------------------------------------// 
	fillCosThetaHistogram(t_qcd30_ff,h_qcd30_ff);
	fillCosThetaHistogram(t_qcd40_ff,h_qcd30_ff);
	// dyee plot ----------------------------------------------------// 
	fillCosThetaHistogram(t_dyee,h_dyee);
	// ---------------------------------------------------------------//

	std::vector<struct_histo> vars;
	struct_histo v_mass; v_mass.name = "costheta"; v_mass.xLabel = "#theta^{*}"; v_mass.yLabel = "Events"; v_mass.nBins = 50; v_mass.xMin=0;v_mass.xMax = TMath::Pi(); v_mass.isLog=false;v_mass.yMin=-10;v_mass.yMax=1800;
	vars.push_back(v_mass);

	int pCOUNT = 0;
	std::vector<struct_histo>::iterator it_vars  = vars.begin();
	std::vector<struct_histo>::iterator end_vars = vars.end();

	for (pCOUNT=0;it_vars!=end_vars;it_vars++,pCOUNT++){

		// Scale the signal 
		h_ggh->Scale(scSIGNAL*h_data->Integral()/h_ggh->Integral());

		// Make dataerrors
		h_data->Sumw2();
		h_data->SetTitle("");

		// Data is the one with the labels
		h_data->GetYaxis()->SetTitle((*it_vars).yLabel.c_str());
		h_data->GetXaxis()->SetTitle((*it_vars).xLabel.c_str());
		h_data->SetMarkerStyle(cMARKER);
		h_data->SetMarkerSize(cMSIZE);
		h_data->SetMarkerColor(cDATA);
		h_data->GetYaxis()->SetTitleOffset(yOFFSET);
		if ((*it_vars).yMin > -1 ) h_data->SetMinimum((*it_vars).yMin);
		if ((*it_vars).yMax > -1 ) h_data->SetMaximum((*it_vars).yMax);

		// Repeated Settings
		h_data->SetLineWidth(cLINEWIDTH);
		h_data->SetLineStyle(cLINESTYLE);
		h_data->SetFillStyle(0);	// Data not Filled
		h_data->SetLineColor(kBlack);

		h_ggh->SetLineWidth(cLINEWIDTH);
		h_ggh->SetLineStyle(cLINESTYLE);
		h_ggh->SetFillStyle(0);	// Signal has no fill
		h_ggh->SetLineColor(kBlack);

		h_ppjets->SetLineWidth(cLINEWIDTH);
		h_ppjets->SetLineStyle(cLINESTYLE);
		h_ppjets->SetFillStyle(cFILL);
		h_ppjets->SetLineColor(kBlack);

		h_qcd30_pf->SetLineWidth(cLINEWIDTH);
		h_qcd30_pf->SetLineStyle(cLINESTYLE);
		h_qcd30_pf->SetFillStyle(cFILL);
		h_qcd30_pf->SetLineColor(kBlack);
		
		h_qcd30_ff->SetLineWidth(cLINEWIDTH);
		h_qcd30_ff->SetLineStyle(cLINESTYLE);
		h_qcd30_ff->SetFillStyle(cFILL);
		h_qcd30_ff->SetLineColor(kBlack);

		h_dyee->SetLineWidth(cLINEWIDTH);
		h_dyee->SetLineStyle(cLINESTYLE);
		h_dyee->SetFillStyle(cFILL);
		h_dyee->SetLineColor(kBlack);
	
		// SetColors
		h_ggh->SetLineColor(cSIGNAL);
		h_ppjets->SetFillColor(cPP);
		h_qcd30_pf->SetFillColor(cPF);
		h_qcd30_ff->SetFillColor(cFF);
		h_dyee->SetFillColor(cDY);
		
		// Make a stack for the Background MC
		THStack *bkgStack = new THStack(Form("bkgStack_%s",(*it_vars).name.c_str()),Form("bkgStack_%s",(*it_vars).name.c_str()));
		bkgStack->Add(h_ppjets);
		bkgStack->Add(h_qcd30_pf);
		bkgStack->Add(h_qcd30_ff);
		bkgStack->Add(h_dyee);

		TLegend *tLEG = new TLegend(tX1,tY1,tX2,tY2);
		tLEG->SetTextFont(fSTYLE);
		tLEG->SetTextSize(fSIZE);
	
		tLEG->SetFillColor(kWhite);
		tLEG->AddEntry(h_data,lDATA.c_str(),"PEL");
		tLEG->AddEntry(h_ppjets,lPP.c_str(),"F");
		tLEG->AddEntry(h_qcd30_pf,lPF.c_str(),"F");
		tLEG->AddEntry(h_qcd30_ff,lFF.c_str(),"F");
		tLEG->AddEntry(h_dyee,lDY.c_str(),"F");
		tLEG->AddEntry(h_ggh,lSIGNAL.c_str(),"L");

		// Finally Make Canvas and Draw
		TCanvas *can = new TCanvas(Form("c%d",pCOUNT),"c",gcWIDTH,gcHEIGHT); can->cd();
		can->SetLogy((*it_vars).isLog);

		h_data->Draw("P");
		bkgStack->Draw("samehist");
		h_ggh->Draw("samehist");
		h_data->Draw("sameP");

		tLEG->Draw();

  		gPad->RedrawAxis();

		TLatex *txt = new TLatex();
		txt->SetTextSize(fSIZE);	txt->SetNDC(); txt->SetTextFont(fSTYLE);
		txt->DrawLatex(0.1,0.91,cmsPRE.c_str());
		txt->DrawLatex(0.67,0.91,cmsSQRTS.c_str());
		
		can->SaveAs(Form("%s.pdf",(*it_vars).name.c_str()));

	}
                         
}                
