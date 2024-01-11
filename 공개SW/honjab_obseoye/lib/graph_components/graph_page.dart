import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';

import '../home_components/bottom_bar.dart';
import '../home_components/top_bar.dart';

class MyGraphPage extends StatefulWidget {
  @override
  _MyGraphState createState() => _MyGraphState();
}

class _MyGraphState extends State<MyGraphPage> {
  CollectionReference product = FirebaseFirestore.instance.collection('users');
  List<MyData> dataList = [];
  List<int> temp1 = [];
  List<int> temp2 = [];
  List<int> temp3 = [];
  List<int> countings = [];
  List<int> hours = [];
  List<int> minutes = [];
  int flag = 0;
  int lastMinute = 5;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: TopBar(),
      body: StreamBuilder(
        stream: product.snapshots(),
        builder:
            (BuildContext context, AsyncSnapshot<QuerySnapshot> streamSnapshot) {
          if (streamSnapshot.hasData) {
            dataList.clear();
            for (var doc in streamSnapshot.data!.docs) {
              String counting = doc['counting'];
              String date = doc['date'];
              String hourPart = date.substring(9, 11);
              String minutePart = date.substring(11, 13);
              int currentMinute = int.parse(minutePart);

              if (temp1.length != 5){ // 추후 수정 (그려지는 시간)
                //print('현재 데이터 개수 : $temp1');
                temp1.add(int.parse((counting)));
                temp2.add(int.parse((hourPart)));
                temp3.add(int.parse((minutePart)));
              }
              else{
                for(int i = 0; i < temp1.length; i++){
                  countings.add(temp1[i]);
                  hours.add(temp2[i]);
                  minutes.add(temp3[i]);
                }
                temp1.clear();
                temp2.clear();
                temp3.clear();
              }
              for(int i = 0; i < countings.length; i++) {
                dataList.add(MyData(
                  counting: countings[i],
                  //hour: hours[i],
                  minute: i, // 추후 수정 (분 단위)
                ));
              }
            }
            return Center(
              child: Container(
                child: SfCartesianChart(
                  primaryXAxis: NumericAxis(
                    /*
                    minimum: 0,
                    maximum: 20,
                    interval: 5,
                     */
                  ),
                  primaryYAxis: NumericAxis(
                    /*
                    minimum: 0,
                    maximum: 1000,
                    interval: 10,
                     */
                  ),
                  series: <ChartSeries>[
                    SplineSeries<MyData, int>(
                      dataSource: dataList,
                      splineType: SplineType.monotonic,
                      cardinalSplineTension: 0.9,
                      xValueMapper: (MyData data, _) => data.minute,
                      yValueMapper: (MyData data, _) => data.counting,
                    ),
                  ],
                ),
              ),
            );
          } else if (streamSnapshot.hasError) {
            return Text("Error: ${streamSnapshot.error}");
          } else {
            return CircularProgressIndicator();
          }
        },
      ),
      bottomNavigationBar: BottomBar(), // BottomBar 추가
    );
  }
}

class MyData {
  final int counting;
  //final int hour;
  final int minute;

  MyData({
    required this.counting,
    //required this.hour,
    required this.minute,
  });
}

// ... 나머지 코드 ...
