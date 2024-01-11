import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:live_streaming/page/Graph_Page.dart';
import 'package:live_streaming/page/firebase_option.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );

  return runApp(MyApp ());
}

class MyApp  extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(primarySwatch: Colors.blue),
      home: MyGraphPage(),
    );
  }
}

