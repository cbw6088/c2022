import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class CountValue extends StatefulWidget {
  @override
  _CountValue createState() => _CountValue();
}

class _CountValue extends State<CountValue> {
  late Stream<QuerySnapshot> _stream;

  @override
  void initState() {
    super.initState();
    _stream = FirebaseFirestore.instance.collection('users').snapshots();
  }

  @override
  Widget build(BuildContext context) {
    return StreamBuilder(
      stream: _stream,
      builder: (BuildContext context, AsyncSnapshot<QuerySnapshot> streamSnapshot) {
        if (streamSnapshot.hasData) {
          var docs = streamSnapshot.data!.docs;
          if (docs.isNotEmpty) {
            var counting = docs[0]['counting'] ?? '0';
            var date = docs[0]['date'] ?? '00000000000000';
            var hour = date.substring(9, 11);
            var minute = date.substring(11, 13);
            var second = date.substring(13, 15);
            return Column(
              children: [
                Padding(
                  padding: const EdgeInsets.all(10.0),
                  child: Container(
                    width: double.infinity,
                    height: 110,
                    decoration: BoxDecoration(
                      color: Colors.white,
                      border: Border.all(color: Colors.black54),
                      borderRadius: BorderRadius.circular(15),
                    ),
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Text(
                          "Count",
                          style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
                        ),
                        Text(
                          counting,
                          style: TextStyle(fontSize: 60, color: Colors.black),
                        ),
                      ],
                    ),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.all(0),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: [
                      _buildTimeBox("Hour", hour),
                      _buildTimeBox("Minute", minute),
                      _buildTimeBox("Second", second),
                    ],
                  ),
                ),
              ],
            );
          }
        }
        return Center(child: CircularProgressIndicator());},
    );
  }

  Widget _buildTimeBox(String label, String value) {
    return Container(
      width: MediaQuery.of(context).size.width / 3.5,
      height: 100,
      decoration: BoxDecoration(
        border: Border.all(color: Colors.black54),
        borderRadius: BorderRadius.circular(15),
      ),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Text(label, style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
          SizedBox(height: 5),
          Text(value, style: TextStyle(fontSize: 24)),
        ],
      ),
    );
  }
}
