import 'dart:io';

import 'package:archive/archive_io.dart';
import 'package:flutter/material.dart';
import 'package:setask/info.dart';

void install(String path) { // origin was main.dart
  Directory(path).createSync(recursive: true);
  var zipD = ZipDecoder();
  var inputFS = InputFileStream("software.zip");
  var software = zipD.decodeBuffer(inputFS);
  for (var file in software.files) {
    var o = OutputFileStream(path+ "/" + file.name);
    file.writeContent(o);
    o.closeSync();
  }
  inputFS.closeSync();
}

void clean() {
  File("software.zip").deleteSync();
}

class installer extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    //throw UnimplementedError();

    return Scaffold(
      body: Padding(padding: const EdgeInsets.all(16.0),child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          const Text("Ready to Install My Software?", style: TextStyle(color: Colors.white),),
          Expanded(child: Center(child: TextButton.icon(icon: const Icon(Icons.arrow_downward),label: const Text("Install"), onPressed: (){

          //},))),
          //IconButton(onPressed: (){
            install("C://test");

            showDialog(context: context, builder: (context) {
              return Dialog(child: Column(children: [const Text("Installed Successed"), TextButton(onPressed: () {
              }, child: const Text("Close"))],));
            });
  }))),
          //}, icon: const Icon(Icons.info))
          IconButton(onPressed: (){
            showLicensePage(context: context, applicationName: "Setask", applicationVersion: "0.1v-preAlpha"); // see NOTE #L below
           /* return;
            Navigator.push(context, MaterialPageRoute(builder: (context){
              //showLicensePage(context: context);
              return LicensePage(applicationName: "Setask", applicationVersion: "0.1v-preAlpha", applicationLegalese: "By Native Bits Team",); //InfoPage(); // See info.dart for more information | and Ref #L in main.dart | calling it preAlpha may/might not be accurate | NOTE #L
            }));*/
          }, icon: Icon(Icons.info))],
      ),
    ));
  }
}