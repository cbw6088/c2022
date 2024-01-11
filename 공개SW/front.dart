import 'package:flutter/material.dart';
import 'package:location/location.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Congestion Checker',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: CongestionPage(),
    );
  }
}

class CongestionPage extends StatefulWidget {
  @override
  _CongestionPageState createState() => _CongestionPageState();
}

class _CongestionPageState extends State<CongestionPage> {
  double targetPercentage = 80;
  FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
      FlutterLocalNotificationsPlugin();

  @override
  void initState() {
    super.initState();
    initializeFlutterLocalNotificationsPlugin();
  }

  Future<void> initializeFlutterLocalNotificationsPlugin() async {
    final AndroidInitializationSettings initializationSettingsAndroid =
        AndroidInitializationSettings('app_icon');
    final InitializationSettings initializationSettings =
        InitializationSettings(android: initializationSettingsAndroid);
    await flutterLocalNotificationsPlugin.initialize(initializationSettings);
  }

  Future<void> showNotification(String content) async {
    const AndroidNotificationDetails androidPlatformChannelSpecifics =
        AndroidNotificationDetails(
      'congestion_channel_id',
      'Congestion Channel',
      'Channel for congestion notifications',
      importance: Importance.high,
      priority: Priority.high,
      ticker: 'ticker',
    );
    const NotificationDetails platformChannelSpecifics =
        NotificationDetails(android: androidPlatformChannelSpecifics);
    await flutterLocalNotificationsPlugin.show(
      0,
      'Congestion Alert',
      content,
      platformChannelSpecifics,
    );
  }

  Future<void> checkCongestion() async {
    // TODO: 객체 인식 및 혼잡도 체크 기능 구현

    // 임시로 혼잡도를 랜덤으로 설정
    double congestionPercentage = 70; // 예시로 70%로 설정

    // GPS 기능 사용하여 사용자 위치 확인
    Location location = Location();
    LocationData currentLocation;
    try {
      currentLocation = await location.getLocation();
    } catch (e) {
      // 위치 정보를 가져오지 못한 경우 처리
      print('Failed to get location: $e');
    }

    // 사용자 위치와 카메라에 잡힌 위치 비교
    if (currentLocation != null) {
      // 임시로 카메라에 잡힌 위치와의 거리를 비교하지만, 실제 사용자 위치 확인이 필요
      double distance = calculateDistance(
        currentLocation.latitude,
        currentLocation.longitude,
        cameraLocationLatitude,
        cameraLocationLongitude,
      );

      // 혼잡 단계이고 사용자가 카메라에 잡힌 위치에 있을 경우 알림 보내기
      if (congestionPercentage >= 70 && distance <= 100) {
        showNotification('You are in a congested area!');
      }
    }
  }

  double calculateDistance(
    double userLatitude,
    double userLongitude,
    double cameraLatitude,
    double cameraLongitude,
  ) {
    // TODO: 실제 거리 계산 알고리즘 적용
    // 임시로 거리를 랜덤으로 설정
    return 50; // 예시로 50m로 설정
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Congestion Checker'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'Welcome to the Congestion Checker App!',
              style: TextStyle(fontSize: 20),
              textAlign: TextAlign.center,
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: checkCongestion,
              child: Text('Check Congestion'),
            ),
            SizedBox(height: 10),
            ElevatedButton(
              onPressed: () {
                // TODO: GPS 기능 구현
              },
              child: Text('Check Location'),
            ),
            SizedBox(height: 10),
            ElevatedButton(
              onPressed: () {
                // 사용자가 알림 시계로 설정한 수치
                double userSetPercentage = 80; // 예시로 80%로 설정

                // 현재 혼잡도와 설정한 수치 비교하여 알림 보내기
                if (congestionPercentage <= userSetPercentage) {
                  showNotification(
                      'Congestion is below the set percentage threshold!');
                }
              },
              child: Text('Set Congestion Threshold'),
            ),
          ],
        ),
      ),
    );
  }
}
