import 'package:flutter/material.dart';
import '../home_components/bottom_bar.dart';
import '../home_components/count_value.dart';
import '../home_components/image_check.dart';
import '../home_components/bottom_button.dart';
import '../home_components/top_bar.dart';


class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: TopBar(),
      body: ListView(
        children: [
          ImageCheck(),
          CountValue(),
          BottomButton(),
        ],
      ),
      bottomNavigationBar: BottomBar(),
    );
  }
}