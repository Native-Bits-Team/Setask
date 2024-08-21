#include <fstream>
#include <iostream>

#include <string>
#include <vector>


#include <direct.h>
#include <sys/stat.h>
#include <conio.h>

//#include <windows.h>
//#include <direct.h>
//#include <direct.h>
//#include <dre


/*
int main() {
    int c = 0;
    std::string RCFS = "STRINGTABLE {\n";
    int startID = 1000;
    auto FS = std::fstream("../test_folder/setup.zip.txt");
    //char* H = (char*) calloc(4000,0);
    //std::string H = "";
    //char CH = 'A';
    char* H = (char*) calloc(4000,0);
if(!FS.is_open()){return 0;}
//FS.getline(H,4000);
//FS.getline(H, 300);
//std::cout << "Got" << std::endl;
//while (!FS.eof()){
std::cout << FS.eof();
while(!FS.eof()){
    for (int i =0; i <= 3900; i+=300){
        if (FS.eof()){break;}
    FS.getline(H,300);
std::cout << "t";
RCFS += startID; // COPY REF R
RCFS += ", \""; //
RCFS += H; //
RCFS += "\"\n"; // 

startID+=1;
    }
}


   // FS.read()

    //std::cout << "w";
//for (int i=0; i<4000; ++i){
    //std::cout << "F";
  //  if (FS.eof()){break;}//std::cout << "break";break;}
   // while(!FS.eof()){
    //FS.readsome(H, 4000);
    //FS.get(CH);
    //H += CH;
    //std::cout << CH;
    //std::cout << H << std::endl;
    //RCFS += startID + "\"";
    //RCFS += H;
    //RCFS += "\"\n";
    //startID += 1;
  //  }
//}
//c+=1;
//std::cout << c << std::endl;

/// REF R
//RCFS += startID;
//RCFS += ", \"";
//RCFS += H;
//RCFS += "\"\n"; 
/// END REF R

//}
    FS.close();
    
    auto OS = std::fstream("../test_folder/setup.zip.M.text");

    for (int i = 0; i < RCFS.size(); ++i){
        //OS.put(std::__cxx11::stoi(RCFS[i])); // Got it from CrowSqlite
        OS.put(RCFS[i]);
        std::cout << RCFS[i];
    }
    OS.close();
    std::cout << "Done" << std::endl;
    return 0;
}
*/


//int main() {
  //  listByteToResourceString({"../test_folder/setup.zip.txt", "../test_folder/software,zip.txt"});
//}


//int main() {
void listByteToResourceString(std::vector<std::string> files){
    //auto FS = std::fstream(path);
    //auto OS = std::ofstream(path + ".rc"); // ofstream not fstream
    auto OS = std::ofstream("software.rc");

//for (int j = 0; j < files.size(); ++j){
    std::string startString = "STRINGTABLE {\n";
    std::string H = "";
    std::string HCH = "";
    OS.write(startString.c_str(), startString.size());
    int startID = 1000;
    for (int j=0; j < files.size(); ++j){
    auto FS = std::fstream(files[j]);
    std::cout << j << std::endl;
    if (!FS.is_open()){std::cout << "ERROR"; break;}

    //int debugInt = 0;


    char CH; // [T] REF #P
    FS.get(CH);
    
    while(!FS.eof()){// && debugInt < 300){
       // debugInt+=1;
        //H += startID;
        //OS.put(startID);
        H = std::to_string(startID);
        OS.write(H.c_str(), H.size());
        //break;
        H = ", \"";
        OS.write(H.c_str(), H.size());
        //H = "";
        //char CH; // REF #P
        //FS.get(CH); //
        for (int i=0; i < 4000; ++i){
        //    if (debugInt == 2) {
          //      std::cout << CH;
           // }
          //  if (debugInt == 3){
            //    if (i == 0){
              //      std::cout << " | " << HCH << " | ";
                //}
       //     std::cout << CH;
         //   }
            //if (FS.eof()){break;} // REF #W
            //char CH;
            //FS.get(CH);
            //OS.put(CH);
            
            if (CH == ','){
                for (int k =0; k < HCH.size(); ++k){
                    OS.put(HCH[k]);
                }
                HCH = "";
                FS.get(CH);
              //  if ((i+1) < 4000 && !FS.eof()){
                //    std::cout << (i+1) << "\n";
                OS.put(',');
                //}
                //OS.put(H.c_str());
            } else {
                HCH += CH;
                FS.get(CH);
            }
            if (FS.eof()){break;} // [T] Ref #W
            //std::cout << CH;
        }
        //std::cout << startID;
        H.clear();
        H = "\"\n";
        OS.write(H.c_str(), H.size());
        startID+=1;
        //std::cout << "Done\n";
    }
    FS.close();
    H = std::to_string(startID) + ", \"A\"\n";
    OS.write(H.c_str(), H.size());
}
    OS.put('}');
    //FS.close();
    OS.close();
}



int main() {

    struct direct *subDirectory;
    struct stat * info;

    auto mainDirectory = opendir("./software");
    
    if (mainDirectory != NULL){
        //readdir()
    }

   // struct directory* dr;

    //read();
//readir();
//DIR* d;
    //listByteToResourceString({"../test_folder/setup.zip.txt", "../test_folder/software.zip.txt"});
    listByteToResourceString({"../test_folder/setup.zip.txt"});
    return 0;
}