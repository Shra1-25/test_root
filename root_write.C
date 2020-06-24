 #include <vector>
 
 #include "TFile.h"
 #include "TTree.h"
 #include "TCanvas.h"
 #include "TFrame.h"
 #include "TH1F.h"
 #include "TBenchmark.h"
 #include "TRandom.h"
 #include "TSystem.h"
 
 void root_write()
 {
 
    TFile *f = TFile::Open("temp_file.root","RECREATE");
    if (!f) { return; }
    std::vector<float> temp_vec;
    // Create a TTree
    TTree *t = new TTree("tvec","Tree with vectors");
    t->Branch("tempvec",&temp_vec);
    for(int i=0;i<10;i++){
      temp_vec.pushback(i);
    }
    t->Fill();
    f->Write();
    delete f;
}
