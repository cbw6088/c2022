import 'package:flutter/material.dart';
import '../components/Logo.dart';
import '../components/bottom_bar.dart';
import '../components/image_check.dart';
import '../components/middle_button.dart';
import '../components/top_bar.dart';

class HomePage extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: ListView(
        children: [
          TopBar(),
          ImageCheck(),
          MiddleButton(),
          BottomBar(),
        ],
      ),
    );
  }
}
