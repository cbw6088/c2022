import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:honjab_obseoye/pages/home_page.dart';
import 'package:honjab_obseoye/pages/login_page.dart';
import 'package:honjab_obseoye/pages/register_page.dart';
import 'package:honjab_obseoye/video_components/LiveStreamPage.dart';
import 'graph_components/graph_page.dart';
import 'home_components/firebase_option.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );
  return runApp(MyApp ());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        textButtonTheme: TextButtonThemeData(
          style: TextButton.styleFrom(
            backgroundColor: Colors.blueAccent,
            primary: Colors.white,
            shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(30),
            ),
            minimumSize: Size(400, 60),
          ),
        ),
      ),
      initialRoute: "/login",
      routes: {
        "/login" : (context) => LoginPage(),
        "/home" : (context) => HomePage(),
        "/register" : (context) => RegisterPage(),
        "/graph": (context) => MyGraphPage(),
        "/liveStreaming": (context) => LiveStreamPage(),
      },
    );
  }
}