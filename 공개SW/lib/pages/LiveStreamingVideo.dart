import 'dart:convert';
import 'dart:typed_data';
import 'package:flutter/material.dart';
import 'websockets.dart';

class VideoStream extends StatefulWidget {
  const VideoStream({Key? key}) : super(key: key);
  @override
  State<VideoStream> createState() => _VideoStreamState();
}

class _VideoStreamState extends State<VideoStream> {
  late WebSocket _socket;
  late List<String> cameraInfo;
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
    // http://172.16.101.92:8080
    _socket = WebSocket("ws://192.168.0.5:6000");
    _socket.connect();
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        padding: const EdgeInsets.all(5),
        margin: const EdgeInsets.all(5),
        child: Column(
          children: [
            const SizedBox(
              height: 10.0,
            ),
            StreamBuilder(
              stream: _socket.stream,
              builder: (context, snapshot) {
                if (!snapshot.hasData) {
                  print('socket does not have data!');
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
                      ));
                }
                //? Working for single frames
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
                        : const Text("확대하기"))),
          ],
        ),
      ),
    );
  }
}
