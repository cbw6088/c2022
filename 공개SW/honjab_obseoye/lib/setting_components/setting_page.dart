import 'package:flutter/material.dart';
import '../home_components/bottom_bar.dart';
import '../home_components/top_bar.dart';
import 'ip_list.dart';

class SettingPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: TopBar(), // TopBar 위젯 추가
      body: Center(
        child: ElevatedButton(
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (context) => IpList(ipAddresses: [])),
            );
          },
          child: Text('Go to IP List'),
        ),
      ),
      bottomNavigationBar: BottomBar(),
    );
  }
}
