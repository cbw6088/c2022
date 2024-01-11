import 'package:flutter/material.dart';

import 'LiveStreamingVideo.dart';
import '../home_components/top_bar.dart'; // TopBar 추가
import '../home_components/bottom_bar.dart'; // BottomBar 추가

class LiveStreamPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: TopBar(), // TopBar 추가
      body: Center(
        child: ListView(
          children: [
            Container(
              padding: const EdgeInsets.only(top: 10),
              alignment: Alignment.center,
              constraints: const BoxConstraints(maxWidth: 300),
              child: Text("실시간 청량리역 라이브 스트리밍"),
            ),
            VideoStream(),
          ],
        ),
      ),
      bottomNavigationBar: BottomBar(), // BottomBar 추가
    );
  }
}
