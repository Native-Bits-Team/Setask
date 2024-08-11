
import 'dart:io';

import 'package:archive/archive_io.dart';
import 'package:flutter/material.dart';

///// COPY PASTED FROM main.dart
void generateZipFromSoftwareDir(String softwareDir){
  var zip = ZipEncoder(); // REF #1
  var outputFS = OutputFileStream("software.zip");
  zip.startEncode(outputFS);
  Directory(softwareDir).listSync(recursive: true).forEach((file){
    //print(file.path.replaceFirst(softwareDir + '\\', ''));
    zip.addFile(ArchiveFile.string(file.path.replaceFirst('$softwareDir\\', ''), File(file.path).readAsStringSync()));
  });
  zip.endEncode();
  outputFS.closeSync();
}

/*
void generateResourceScript(){
  var sData = File("software.zip").readAsBytesSync();
  //print(sData.toString());
  //print(sData.toString().length.toString());
  var data = "STRINGTABLE{\n1000, \"${sData.toString().replaceAll(' ', '').length}\"\n1001, \"${sData.toString().replaceAll(' ', '')}\"\n}";
  File("lib/software.rc").writeAsStringSync(data);
}*/
/////

void generateResourceScriptM(List<String> resourcesList, {String path=""}) { // [T] generateResourceScript() above
  String info = "STRINGTABLES {\n";
  String rLengths = "1000, \"";
  String rData = "";
  //String rName = "1001, \"";
  //int rStartID = 1002;//1001;
  int rStartID = 1001;
  for (String resource in resourcesList){
    //rLengths += ',';
    //rName += resource;
    var rString = File(path+resource).readAsBytesSync().toString().replaceFirst('[', '').replaceFirst(']', '').replaceAll(' ', '');
    rLengths += rString.length.toString();
    rData += rStartID.toString() + ", \"" + rString + "\"\n";
    rStartID+=1;
    rLengths += ','; // Ref #O
    //rName += ','; // [T] Ref #O
  }
  rLengths.replaceRange(rLengths.length-1, rLengths.length, 'A'); // 'A' To mark the end of the list 
  rLengths += "\"\n"; // Ref #P
  //rName.replaceRange(rName.length-1, rName.length, 'A'); //
  //rName += "\"\n"; // [T] Ref #P
  //info += rLengths + rData + "}";
  //info += rLengths + rName + rData + "}";
  info += rLengths + rData + "}";
  File("software.rc").writeAsStringSync(info);
}


void runSetaskExec(){
  // runs windres.exe software.rc -o software.res -O coff
  // runs g++ setask.cpp software.res -o setup.exe
}


class GeneratorPanel extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    //throw UnimplementedError();
    return Scaffold(
      body: Padding(padding: const EdgeInsets.all(16.0), child: Column(children: [Center(child: TextButton.icon(onPressed: (){
        //generateZipFromSoftwareDir("software");
        //generateResourceScript();
        //generateResourceScriptM(["software.zip","setup.zip"]);
        
        /*List<String> rPathList = [];
        Directory("test_folder").listSync(recursive: true).forEach((file){
          if (file is File){
          rPathList.add(file.path);
          }
        });
        */
        //generateResourceScriptM(rPathList);
        generateResourceScriptM(["software.zip", "setup.zip"], path: "test_folder/");
        runSetaskExec();
      }, label: const Text("Generate"))),
      IconButton(onPressed: (){
        showLicensePage(context: context, applicationName: "Setask Generator");
      }, icon: Icon(Icons.info))],),),
    );
  }
  
}