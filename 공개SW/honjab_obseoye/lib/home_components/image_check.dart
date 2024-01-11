import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class ImageCheck extends StatefulWidget {
  @override
  _ImageCheckState createState() => _ImageCheckState();
}

class _ImageCheckState extends State<ImageCheck> {
  bool isOn = false;

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(10),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              GestureDetector(
                child: Container(
                  width: 140,
                  height: 35,
                  decoration: BoxDecoration(
                    color: isOn ? Colors.grey : Colors.blueAccent,
                    borderRadius: BorderRadius.circular(8),
                  ),
                  child: Center(
                    child: Text(
                      isOn ? "혼잡 이미지" : "현재 이미지",
                      style: TextStyle(fontSize: 22, color: Colors.white),
                    ),
                  ),
                ),
                onTap: () {
                  setState(() {
                    isOn = !isOn;
                  });
                },
              ),
              GestureDetector(
                child: AnimatedContainer(
                  duration: Duration(milliseconds: 100),
                  curve: Curves.easeInOut,
                  margin: EdgeInsets.only(left: isOn ? 10 : 0),
                  width: 50,
                  height: 30,
                  decoration: BoxDecoration(
                    color: isOn ? Colors.grey : Colors.green,
                    borderRadius: BorderRadius.circular(15),
                  ),
                  child: Center(
                    child: GestureDetector(
                      onTap: () {
                        setState(() {
                          isOn = !isOn;
                        });
                      },
                      child: AnimatedContainer(
                        duration: Duration(milliseconds: 300),
                        curve: Curves.easeInOut,
                        width: 25,
                        height: 25,
                        decoration: BoxDecoration(
                          shape: BoxShape.circle,
                          color: Colors.white,
                        ),
                        margin: EdgeInsets.only(
                          right: isOn ? 0 : 20,
                          left: isOn ? 20 : 0,
                        ),
                      ),
                    ),
                  ),
                ),
              ),
            ],
          ),
          SizedBox(height: 10),
          StreamBuilder<DocumentSnapshot>(
            stream: FirebaseFirestore.instance.collection('users').doc('crowd').snapshots(),
            builder: (context, snapshot) {
              if (snapshot.connectionState == ConnectionState.waiting) {
                return CircularProgressIndicator();
              }

              if (!snapshot.hasData || snapshot.data == null) {
                return Text("No data available");
              }

              String imageUrl = isOn
                  ? (snapshot.data?['fidt_fileUrl']) ?? ''
                  : (snapshot.data?['ori_fileUrl']) ?? '';

              return imageUrl.isNotEmpty
                  ? Image.network(
                imageUrl,
                width: 380,
                height: 220,
                fit: BoxFit.contain,
              )
                  : CircularProgressIndicator();
            },
          ),
        ],
      ),
    );
  }
}
