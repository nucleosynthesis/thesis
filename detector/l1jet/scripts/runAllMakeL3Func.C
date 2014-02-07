{

	gROOT->SetBatch(1);
	gROOT->ProcessLine(".L corrfunc.C");
	
	TFile *f0 = TFile::Open("l3_Eta0to0348.root");
	makePlot(f0,0.000,0.348,1.5,3,80,"egcor0.pdf");

	TFile *f1 = TFile::Open("l3_Eta0348to0695.root");
	makePlot(f1,0.348,0.695,1.5,3,80,"egcor1.pdf");

	TFile *f2 = TFile::Open("l3_Eta0695to1044.root");
	makePlot(f2,0.695,1.044,1.5,3,80,"egcor2.pdf");

	TFile *f3 = TFile::Open("l3_Eta1044to1392.root");
	makePlot(f3,1.044,1.392,1.5,3.5,80,"egcor3.pdf");

	TFile *f4 = TFile::Open("l3_Eta1392to1740.root");
	makePlot(f4,1.392,1.740,1.5,3.5,80,"egcor4.pdf");

	TFile *f5 = TFile::Open("l3_Eta1740to2172.root");
	makePlot(f5,1.740,2.172,1.5,3.5,80,"egcor5.pdf");

	TFile *f6 = TFile::Open("l3_Eta2172to30.root");
	makePlot(f6,2.172,3.000,1,3,80,"egcor6.pdf");

	TFile *f7 = TFile::Open("l3_Eta30to35.root");
	makePlot(f7,3.000,3.500,1.6,2.4,60,"egcor7.pdf");

	TFile *f8 = TFile::Open("l3_Eta35to40.root");
	makePlot(f8,3.500,4.000,1.4,1.8,60,"egcor8.pdf");

	TFile *f9 = TFile::Open("l3_Eta40to45.root");
	makePlot(f9,4.000,4.500,1,2,60,"egcor9.pdf");

	TFile *f10 = TFile::Open("l3_Eta45to50.root");
	makePlot(f10,4.500,5.000,1,2,60,"egcor10.pdf");
	

}
