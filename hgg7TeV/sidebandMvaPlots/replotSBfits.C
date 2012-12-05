{


	nb = 8;

	TLatex *lat = new TLatex();
	TLatex *latv = new TLatex();
	lat->SetNDC();
	latv->SetNDC();
	latv->SetTextAngle(90);

	TDirectory *dir = _file0->Get("mH_124.0");
	dir->cd();
	for (int i=0;i<nb;i++){
		TCanvas *can =(TCanvas*)dir->Get(Form("Fit_BDT%d",i));
		can->Draw();
		lat->DrawLatex(0.8,0.02,"m_{H}");
		if (i<7){
			latv->DrawLatex(0.032,0.4,Form("Fraction in Bin %d",i+1));	
		} else {
			latv->DrawLatex(0.032,0.4,"Fraction in Dijet Bin");
		}	
		can->SaveAs(Form("m124_bg_bdt_bin_%d.pdf",i+1));
	}

}
