#include <vector>
 
 #include "TFile.h"
 #include "TTree.h"
 #include "TCanvas.h"
 #include "TFrame.h"
 #include "TH1F.h"
 #include "TBenchmark.h"
 #include "TRandom.h"
 #include "TSystem.h"

void read()
 {
 
    TFile *f = TFile::Open("temp_file.root","READ");
 
    if (!f) { return; }
 
    TTree *t1; f->GetObject("tvec",t);
 
    std::vector<float> *temp_vec = 0;
    t1->SetBranchAddress("tvec",&temp_vec)
    for (int i=0;i<10;i++){
      t1->GetEntry(i);
    } 
    t->ResetBranchAddresses();
 }
