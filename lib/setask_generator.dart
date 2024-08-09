
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


void generateResourceScript(){
  var sData = File("software.zip").readAsBytesSync();
  //print(sData.toString());
  //print(sData.toString().length.toString());
  var data = "STRINGTABLE{\n1000, \"${sData.toString().replaceAll(' ', '').length}\"\n1001, \"${sData.toString().replaceAll(' ', '')}\"\n}";
  File("lib/software.rc").writeAsStringSync(data);
}
/////

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
        generateZipFromSoftwareDir("software");
        generateResourceScript();
        runSetaskExec();
      }, label: const Text("Generate")))],),),
    );
  }
  
}