import 'dart:convert';
import 'dart:typed_data';
import 'package:flutter/material.dart';
import 'websockets.dart';

class VideoStream extends StatefulWidget {
  @override
  State<VideoStream> createState() => _VideoStreamState();
}

class _VideoStreamState extends State<VideoStream> {
  late WebSocket _socket;
  bool _isfullscreen = false;

  void ChangeScreenSize() {
    setState(() {
      _isfullscreen = !_isfullscreen;
    });
  }

  @override
  void dispose() {
    _socket.disconnect();
    super.dispose();
  }

  @override
  void initState() {
    _socket = WebSocket("ws://172.30.1.95:6000");
    _socket.connect();
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        padding: const EdgeInsets.all(5),
        margin: const EdgeInsets.all(5),
        child: Column(
          children: [
            StreamBuilder(
              stream: _socket.stream,
              builder: (context, snapshot) {
                if (!snapshot.hasData) {
                  return const CircularProgressIndicator();
                }

                if (snapshot.connectionState == ConnectionState.done) {
                  return const Center(
                    child: Text("Connection Closed !"),
                  );
                }

                if (_isfullscreen) {
                  return RotatedBox(
                    quarterTurns: 1,
                    child: Image.memory(
                      Uint8List.fromList(
                        base64Decode(
                          (snapshot.data.toString()),
                        ),
                      ),
                      gaplessPlayback: true,
                      excludeFromSemantics: true,
                    ),
                  );
                }

                return Image.memory(
                  Uint8List.fromList(
                    base64Decode(
                      (snapshot.data.toString()),
                    ),
                  ),
                  gaplessPlayback: true,
                  excludeFromSemantics: true,
                );
              },
            ),
            SizedBox(
              width: double.infinity,
              child: TextButton(
                onPressed: ChangeScreenSize,
                child: _isfullscreen
                    ? const Text("축소하기")
                    : const Text("확대하기"),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
