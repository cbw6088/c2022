import 'package:flutter/material.dart';
import '../home_components/top_bar.dart';
import '../home_components/bottom_bar.dart';

class IpList extends StatefulWidget {
  final List<String> ipAddresses;

  IpList({required this.ipAddresses});

  @override
  _IpListState createState() => _IpListState();
}

class _IpListState extends State<IpList> {
  @override
  Widget build(BuildContext context) {

    return Scaffold(
      appBar: TopBar(),
      body: Column(
        children: [
          Expanded(
            child: ListView.builder(
              itemCount: widget.ipAddresses.length,
              itemBuilder: (context, index) {
                return ListTile(
                  title: Text(widget.ipAddresses[index]),
                );
              },
            ),
          ),
          BottomBar(),
        ],
      ),
    );
  }
}
