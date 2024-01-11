import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';

class MyGraphPage extends StatefulWidget {
  MyGraphPage({Key? key}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyGraphPage> {
  CollectionReference product = FirebaseFirestore.instance.collection('users');
  List<MyData> dataList = [];
  int lastMinute = -1; // 저장된 마지막 분 값

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: StreamBuilder(
          stream: product.snapshots(),
          builder: (BuildContext context, AsyncSnapshot<QuerySnapshot> streamSnapshot) {
            if (streamSnapshot.hasData) {
              dataList.clear(); // 데이터를 초기화
              for (var doc in streamSnapshot.data!.docs) {
                String counting = doc['counting'];
                String date = doc['date'];
                String hourPart = date.substring(9, 11);
                String minutePart = date.substring(11, 13);
                int currentMinute = int.parse(minutePart);

                if (currentMinute == 0 && lastMinute != 0) {
                  // 00분일 때 그래프 초기화
                  dataList.clear();
                }
                lastMinute = currentMinute;

                //currentIndex = int.parse(minutePart);
                dataList.add(MyData(
                  counting: int.parse(counting),
                  hour: int.parse(hourPart),
                  minute: int.parse(minutePart),
                ));
                dataList.add(MyData(
                  counting: 17, // 임의의 counting 데이터 추가
                  hour: 7,     // 임의의 hour 데이터 추가
                  minute: 5,  // 임의의 minute 데이터 추가
                ));
                dataList.add(MyData(
                  counting: 35, // 임의의 counting 데이터 추가
                  hour: 7,     // 임의의 hour 데이터 추가
                  minute: 10,  // 임의의 minute 데이터 추가
                ));
                dataList.add(MyData(
                  counting: 48, // 임의의 counting 데이터 추가
                  hour: 7,     // 임의의 hour 데이터 추가
                  minute: 15,  // 임의의 minute 데이터 추가
                ));dataList.add(MyData(
                  counting: 31, // 임의의 counting 데이터 추가
                  hour: 7,     // 임의의 hour 데이터 추가
                  minute: 20,  // 임의의 minute 데이터 추가
                ));
                dataList.add(MyData(
                  counting: 77, // 임의의 counting 데이터 추가
                  hour: 7,     // 임의의 hour 데이터 추가
                  minute: 25,  // 임의의 minute 데이터 추가
                ));


              }
              return Center(
                child: Container(
                  child: SfCartesianChart(
                    primaryXAxis: NumericAxis(
                      minimum: 0,
                      maximum: 60,
                      interval: 5,
                    ),
                    primaryYAxis: NumericAxis(
                      minimum: 0,
                      maximum: 150,
                      interval: 10,
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
            }
            else if (streamSnapshot.hasError) {
              return Text("Error: ${streamSnapshot.error}");
            }
            else {
              return CircularProgressIndicator();
            }
          },
        )
    );
  }
}

class MyData {
  final int counting;
  final int hour;
  final int minute;

  MyData({required this.counting, required this.hour, required this.minute});
}


/*
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:syncfusion_flutter_charts/charts.dart';
import 'package:syncfusion_flutter_charts/sparkcharts.dart';

class MyGraphPage extends StatefulWidget {
  // ignore: prefer_const_constructors_in_immutables
  MyGraphPage({Key? key}) : super(key: key);

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyGraphPage> {

  CollectionReference product = FirebaseFirestore.instance.collection('users');

  @override
  Widget build(BuildContext context) {
    /*
    final List<ChartData> chartData = [
      ChartData(1, 20),
      ChartData(2, 30),
      ChartData(3, 20),
      ChartData(4, 5),
      ChartData(5, 17),
      ChartData(6, 2),
      ChartData(7, 10),
      ChartData(8, 0),
      ChartData(9, 20),
      ChartData(10,20),
    ];
     */
    return Scaffold(
      body: StreamBuilder(
        stream: product.snapshots(),
        builder: (BuildContext context, AsyncSnapshot<QuerySnapshot> streamSnapshot){
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
      /*
        body: Center(
            child: Container(
                child: SfCartesianChart(
                    series: <ChartSeries>[
                      SplineSeries<ChartData, int>(
                          dataSource: chartData,
                          // Type of spline
                          splineType: SplineType.monotonic,
                          cardinalSplineTension: 0.9,
                          xValueMapper: (ChartData data, _) => data.x,
                          yValueMapper: (ChartData data, _) => data.y
                      )
                    ]
                )
            )
        )
       */
    );
  }
}
class ChartData {
  ChartData(this.x, this.y);
  final int x;
  // final List<double> y;
  final double y;
}
 */