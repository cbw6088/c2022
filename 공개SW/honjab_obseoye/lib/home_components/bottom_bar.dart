import 'package:flutter/material.dart';

class BottomBar extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(20),
      child: Container(
        height: 60.0,
        decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(30),
          border: Border.all(
            color: Colors.blueAccent,
            width: 2,
          ),
        ),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            GestureDetector(
              child: Icon(Icons.person, color: Colors.blueAccent, size: 45),
            ),
            GestureDetector(
              onTap: () {
                Navigator.pushReplacementNamed(context, "/home");
              },
              child: Icon(Icons.home, color: Colors.blueAccent, size: 45),
            ),
            Icon(Icons.settings, color: Colors.blueAccent, size: 45),
          ],
        ),
      ),
    );
  }
}
