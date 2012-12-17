{


	nb = 8;

	TLatex *lat = new TLatex();
	TLatex *latv = new TLatex();
	TLatex *lat2 = new TLatex();
	lat->SetNDC();
	lat2->SetNDC();
	latv->SetNDC();
	latv->SetTextAngle(90);
	lat->SetTextSize(0.055);
	lat2->SetTextSize(0.045);
	latv->SetTextSize(0.055);
	TDirectory *dir = _file0->Get("mH_124.0");
	dir->cd();
	for (int i=0;i<nb;i++){
		TCanvas *can =(TCanvas*)dir->Get(Form("Fit_BDT%d",i));
		can->Draw();
//		can->SetCanvasSize(900,900);
		lat->DrawLatex(0.8,0.02,"m_{H,i}");
		lat2->DrawLatex(0.6,0.73,"#sqrt{s}=7 TeV L = 5.1 fb^{-1}");
		if (i<7){
			latv->DrawLatex(0.031,0.38,Form("Fraction in Bin %d",i+1));	
		} else {
			latv->DrawLatex(0.031,0.38,"Fraction in Dijet Bin");
		}	
		can->SaveAs(Form("fits/m124_bg_bdt_bin_%d.pdf",i+1));
	}

}
