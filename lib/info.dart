/* [HISTORY]
import 'package:flutter/material.dart';
import 'package:setask/oss_licenses.dart';

class InfoPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    //throw UnimplementedError();
    String infoText = "Setask 0.1v-preAlpha\n";
    infoText+= "You are installing a software using Setask Installer.\n\n";
    infoText+= "--------------Licenses--------------";
    for (var p in allDependencies){
      infoText += "\n\n";
      infoText += p.name + " | " + "License Text:\n\n";
      infoText += p.license as String;
    }
    var tController = TextEditingController(text: infoText);
    return Scaffold(
      appBar: AppBar(),
      body: Padding(padding: EdgeInsets.all(16.0), child: Card(child: Padding(padding: EdgeInsets.all(16.0), child: TextField(
        maxLines: 3000,
        minLines: 300,
        controller: tController,onChanged: (newText){
        
        tController.text = infoText;
      },),),),),
    );
  }
  
}
*/
// This page was deprecated after accidently discovering LicensePage() while making it, the LicensePage() widget contains more licenses then flutter_oss_licenses generate
// Note: calling the version preAlpha may/might not be accurate