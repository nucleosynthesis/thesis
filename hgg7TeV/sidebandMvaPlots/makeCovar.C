{
	gStyle->SetPaintTextFormat(".2g");

	TH2F *fcovar = (TH2F*)_file0->Get("mH_124.0/fCovar_124.0");
	TCanvas *can = new TCanvas("c","c",800,800);
	fcovar->SetTitle("");
	for (int i=0;i<7;i++){

		fcovar->GetYaxis()->SetBinLabel(i+1,Form("Bin %d",i+1));
		fcovar->GetXaxis()->SetBinLabel(i+1,Form("Bin %d",i+1));
	}
	fcovar->GetYaxis()->SetBinLabel(8,"Dijet");
	fcovar->GetXaxis()->SetBinLabel(8,"Dijet");

	fcovar->Draw("COL");
	fcovar->SetMarkerSize(1.2);
	fcovar->Draw("sametext45");

}
