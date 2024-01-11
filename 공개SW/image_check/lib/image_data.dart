import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class ImageData extends StatefulWidget {
  @override
  _ImageDataState createState() => _ImageDataState();
}

class _ImageDataState extends State<ImageData> {
  final firestore = FirebaseFirestore.instance;
  String imageUrl = '';

  Future<void> getImageData() async {
    var result = await firestore.collection('users').doc('crowd').get();
    if (result.exists) {
      setState(() {
        imageUrl = result.data()?['fidt_fileUrl'] ?? '';
      });
    }
  }

  @override
  void initState() {
    super.initState();
    getImageData();
  }

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(20),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(
            width: 100,
            height: 30,
            decoration: BoxDecoration(
              color: Colors.blueAccent,
              borderRadius: BorderRadius.circular(8),
            ),
            child: Center(
              child: Text(
                "이미지",
                style: TextStyle(fontSize: 20, color: Colors.white),
              ),
            ),
          ),
          SizedBox(height: 1),
          imageUrl.isNotEmpty
              ? Image.network(
            imageUrl,
            width: 360,
            height: 220,
            fit: BoxFit.contain,
          )
              : CircularProgressIndicator(),
        ],
      ),
    );
  }
}


/*
@override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Cloud Firestore'),
      ),
      body: StreamBuilder(
        stream: product.snapshots(),
        builder: (BuildContext context,
          AsyncSnapshot<QuerySnapshot> streamSnapshot) {
            if(streamSnapshot.hasData){
              return ListView.builder(
                itemCount: streamSnapshot.data!.docs.length,
                itemBuilder: (context, index){
                  final DocumentSnapshot documentSnapshot = streamSnapshot.data!.docs[index];
                  return Card(
                    child: ListTile(
                      title: Text(documentSnapshot['counting']),
                      subtitle: Text(documentSnapshot['date']),
                    ),
                  );
                },
              );
            }
            return CircularProgressIndicator();
        },
      ),
    );
 */