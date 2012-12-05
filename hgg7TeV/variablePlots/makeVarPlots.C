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

	// ---------------------------------------------------------------------------------------------------------------------------------------------------
	// Variables that are to be drawn
	std::vector<struct_histo> vars;
	struct_histo v_mass; v_mass.name = "mass"; v_mass.xLabel = "m_{#gamma#gamma} GeV"; v_mass.yLabel = "Events / GeV"; v_mass.nBins = 80; v_mass.xMin=100;v_mass.xMax = 180; v_mass.isLog=false;v_mass.yMin=-10;v_mass.yMax=-10;
	struct_histo v_bdtoutput; v_bdtoutput.name = "bdtoutput"; v_bdtoutput.xLabel = "BDT Output"; v_bdtoutput.yLabel = "Events"; v_bdtoutput.nBins = 50; v_bdtoutput.xMin=-1;v_bdtoutput.xMax = 1;v_bdtoutput.isLog=true;v_bdtoutput.yMax=50000;v_bdtoutput.yMin=-10;
	struct_histo v_pt_1om; v_pt_1om.name = "pt_1om"; v_pt_1om.xLabel = "p_{T}^{1}/m_{#gamma#gamma}"; v_pt_1om.yLabel = "Events"; v_pt_1om.nBins = 50 ; v_pt_1om.xMin=0.3;v_pt_1om.xMax = 0.8;v_pt_1om.isLog=false;v_pt_1om.yMax=-10;v_pt_1om.yMin=-10;
	struct_histo v_pt_2om; v_pt_2om.name = "pt_2om"; v_pt_2om.xLabel = "p_{T}^{2}/m_{#gamma#gamma}"; v_pt_2om.yLabel = "Events"; v_pt_2om.nBins = 50 ; v_pt_2om.xMin=0.3;v_pt_2om.xMax = 0.8;v_pt_2om.isLog=false;v_pt_2om.yMax=-10;v_pt_2om.yMin=-10;
	struct_histo v_phoeta_1; v_phoeta_1.name = "phoeta_1"; v_phoeta_1.xLabel = "#eta^{1}"; v_phoeta_1.yLabel = "Events"; v_phoeta_1.nBins = 50 ; v_phoeta_1.xMin=-2.5;v_phoeta_1.xMax = 2.5;v_phoeta_1.isLog=false;v_phoeta_1.yMin=-10;v_phoeta_1.yMax=1200;
	struct_histo v_phoeta_2; v_phoeta_2.name = "phoeta_2"; v_phoeta_2.xLabel = "#eta^{2}"; v_phoeta_2.yLabel = "Events"; v_phoeta_2.nBins = 50 ; v_phoeta_2.xMin=-2.5;v_phoeta_2.xMax = 2.5;v_phoeta_2.isLog=false;v_phoeta_2.yMin=-10;v_phoeta_2.yMax=1200;
	struct_histo v_cosdphi; v_cosdphi.name = "cosdphi"; v_cosdphi.xLabel = "cos(#Delta#phi)"; v_cosdphi.yLabel = "Events"; v_cosdphi.nBins = 50 ; v_cosdphi.xMin=-1;v_cosdphi.xMax = 1;v_cosdphi.isLog=true;v_cosdphi.yMin=-10;v_cosdphi.yMax=-10;
	struct_histo v_phoid_1; v_phoid_1.name = "phoid_1"; v_phoid_1.xLabel = "#gamma^{1} ID MVA Output"; v_phoid_1.yLabel = "Events"; v_phoid_1.nBins = 65 ; v_phoid_1.xMin=-.3;v_phoid_1.xMax = 1;v_phoid_1.isLog=false;v_phoid_1.yMin=-10;v_phoid_1.yMax=-2;
	struct_histo v_phoid_2; v_phoid_2.name = "phoid_2"; v_phoid_2.xLabel = "#gamma^{1} ID MVA Output"; v_phoid_2.yLabel = "Events"; v_phoid_2.nBins = 65 ; v_phoid_2.xMin=-.3;v_phoid_2.xMax = 1;v_phoid_2.isLog=false;v_phoid_2.yMin=-10;v_phoid_2.yMax=-2;
	struct_histo v_sigmrv; v_sigmrv.name = "sigmrv"; v_sigmrv.xLabel = "#sigma_{m_{#gamma#gamma}} right-vtx GeV"; v_sigmrv.yLabel = "Events / 0.1 GeV"; v_sigmrv.nBins = 80; v_sigmrv.xMin=0;v_sigmrv.xMax = 8; v_sigmrv.isLog=false;v_sigmrv.yMin=-10;v_sigmrv.yMax=-10;
	
	struct_histo v_sigmwv; v_sigmwv.name = "sigmwv"; v_sigmwv.xLabel = "#sigma_{m_{#gamma#gamma}} wrong-vtx GeV"; v_sigmwv.yLabel = "Events / 0.1 GeV"; v_sigmwv.nBins = 80; v_sigmwv.xMin=0;v_sigmwv.xMax = 8; v_sigmwv.isLog=false;v_sigmwv.yMin=-10;v_sigmwv.yMax=1200;

	// Add the variables
	//vars.push_back(v_mass);
	vars.push_back(v_bdtoutput);
	//vars.push_back(v_pt_1om);
	//vars.push_back(v_pt_2om);
	//vars.push_back(v_phoeta_1);
	//vars.push_back(v_phoeta_2);
	//vars.push_back(v_phoid_1);
	//vars.push_back(v_phoid_2);
	//vars.push_back(v_cosdphi);
	//vars.push_back(v_sigmrv);
	//vars.push_back(v_sigmwv);
	// ---------------------------------------------------------------------------------------------------------------------------------------------------
	
	int pCOUNT = 0;
	std::vector<struct_histo>::iterator it_vars  = vars.begin();
	std::vector<struct_histo>::iterator end_vars = vars.end();


	for (pCOUNT=0;it_vars!=end_vars;it_vars++,pCOUNT++){

		std::cout << "About to create Histograms .... " << std::endl;
		std::cout << "Data + Signal .... " << std::endl;
		t_data->Draw(Form(	"%s>>h_data_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_ggh->Draw(Form(	"%s>>h_ggh_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_vbf->Draw(Form(	"%s>>h_vbf_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_wzh->Draw(Form(	"%s>>h_wzh_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_tth->Draw(Form(	"%s>>h_tth_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		std::cout << "PP .... " << std::endl;
		t_ppjets->Draw(Form(	"%s>>h_ppjets_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_box->Draw(Form(	"%s>>h_box_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		std::cout << "PF .... " << std::endl;
		t_qcd30_pf->Draw(Form(	"%s>>h_qcd30_pf_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));
		t_qcd40_pf->Draw(Form(	"%s>>h_qcd40_pf_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str())); 	
		t_gjet->Draw(Form(	"%s>>h_gjet_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));     	
		std::cout << "FF .... " << std::endl;
		t_qcd30_ff->Draw(Form(	"%s>>h_qcd30_ff_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));	
		t_qcd40_ff->Draw(Form(	"%s>>h_qcd40_ff_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));		
		std::cout << "DY .... " << std::endl;
		t_dyee->Draw(Form(	"%s>>h_dyee_%s(%d,%f,%f)",(*it_vars).name.c_str(),(*it_vars).name.c_str(),(*it_vars).nBins,(*it_vars).xMin,(*it_vars).xMax),Form("%s",gCUT.c_str()));		
		std::cout << ".... Done" << std::endl;

		// find the objects
		std::cout << "Finding Histograms .... " << std::endl;
		TH1F *h_data	= (TH1F*) gROOT->FindObject(Form("h_data_%s",(*it_vars).name.c_str()));
		TH1F *h_ggh	= (TH1F*) gROOT->FindObject(Form("h_ggh_%s",(*it_vars).name.c_str()));
		TH1F *h_vbf 	= (TH1F*) gROOT->FindObject(Form("h_vbf_%s",(*it_vars).name.c_str()));
		TH1F *h_wzh 	= (TH1F*) gROOT->FindObject(Form("h_wzh_%s",(*it_vars).name.c_str()));
		TH1F *h_tth 	= (TH1F*) gROOT->FindObject(Form("h_tth_%s",(*it_vars).name.c_str()));
		TH1F *h_ppjets 	= (TH1F*) gROOT->FindObject(Form("h_ppjets_%s",(*it_vars).name.c_str()));
		TH1F *h_box    	= (TH1F*) gROOT->FindObject(Form("h_box_%s",(*it_vars).name.c_str()));
		TH1F *h_qcd30_pf= (TH1F*) gROOT->FindObject(Form("h_qcd30_pf_%s",(*it_vars).name.c_str()));
		TH1F *h_qcd40_pf= (TH1F*) gROOT->FindObject(Form("h_qcd40_pf_%s",(*it_vars).name.c_str()));
		TH1F *h_gjet   	= (TH1F*) gROOT->FindObject(Form("h_gjet_%s",(*it_vars).name.c_str()));
		TH1F *h_qcd30_ff= (TH1F*) gROOT->FindObject(Form("h_qcd30_ff_%s",(*it_vars).name.c_str()));
		TH1F *h_qcd40_ff= (TH1F*) gROOT->FindObject(Form("h_qcd40_ff_%s",(*it_vars).name.c_str()));
		TH1F *h_dyee	= (TH1F*) gROOT->FindObject(Form("h_dyee_%s",(*it_vars).name.c_str()));
		std::cout << ".... Done" << std::endl;

		// Have the histograms so now need to put them together
		h_ggh->Add(h_vbf);h_ggh->Add(h_wzh);h_ggh->Add(h_tth);	// Signal
		h_ppjets->Add(h_box);								// PP
		h_qcd30_pf->Add(h_qcd40_pf);h_qcd30_pf->Add(h_gjet);				// PF
		h_qcd30_ff->Add(h_qcd40_ff);							// FF
		
		// Scale the signal 
		h_ggh->Scale(scSIGNAL);

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
