import 'package:flutter/material.dart';

import 'LiveStreamingVideo.dart';

class LiveStreamPage extends StatelessWidget {
  const LiveStreamPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "혼잡도 실시간 스트리밍",
          style: TextStyle(color: Colors.blue),
        ),
        leading: IconButton(
            onPressed: () {
              Navigator.pop(context); //뒤로가기
            },
            color: const Color(0xFF06A66C),
            icon: const Icon(Icons.arrow_back)),
      ),
      body: Center(
          child: ListView(
        children: [
          Container(
            padding: const EdgeInsets.only(top: 10),
            alignment: Alignment.center,
            constraints: const BoxConstraints(maxWidth: 300),
            child: Text("실시간 청량리역 라이브 스트리밍"),
          ),
          const VideoStream(),
        ],
      )),
    );
  }
}
