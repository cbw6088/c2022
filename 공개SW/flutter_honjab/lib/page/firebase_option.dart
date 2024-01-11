import 'package:firebase_core/firebase_core.dart' show FirebaseOptions;
import 'package:flutter/foundation.dart' show defaultTargetPlatform, kIsWeb, TargetPlatform;

class DefaultFirebaseOptions {
  static FirebaseOptions get currentPlatform {
    if (kIsWeb) {
      throw UnsupportedError(
        'DefaultFirebaseOptions have not been configured for web - '
            'you can reconfigure this by running the FlutterFire CLI again.',
      );
    }
    switch (defaultTargetPlatform) {
      case TargetPlatform.android:
        return android;
      case TargetPlatform.iOS:
        return ios;
      case TargetPlatform.macOS:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for macos - '
              'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.windows:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for windows - '
              'you can reconfigure this by running the FlutterFire CLI again.',
        );
      case TargetPlatform.linux:
        throw UnsupportedError(
          'DefaultFirebaseOptions have not been configured for linux - '
              'you can reconfigure this by running the FlutterFire CLI again.',
        );
      default:
        throw UnsupportedError(
          'DefaultFirebaseOptions are not supported for this platform.',
        );
    }
  }

  static const FirebaseOptions android = FirebaseOptions(
    apiKey: 'AIzaSyDCuD25hjKtGylCHi1NtKqPHXjXAcuOEq4',
    appId: '1:1047002174264:web:7d8cd8952e557d4b40a7cd',
    messagingSenderId: '1047002174264',
    projectId: 'honjab-obseoye',
    storageBucket: 'honjab-obseoye.appspot.com',
  );

  static const FirebaseOptions ios = FirebaseOptions(
    apiKey: 'AIzaSyDCuD25hjKtGylCHi1NtKqPHXjXAcuOEq4',
    appId: '1:1047002174264:web:7d8cd8952e557d4b40a7cd',
    messagingSenderId: '1047002174264',
    projectId: 'honjab-obseoye',
    storageBucket: 'honjab-obseoye.appspot.com',
    iosClientId: '927007293579-8d9sdvg4jqd2cici76v19od1s4kia26s.apps.googleusercontent.com',
    iosBundleId: 'com.example.carkeeper',
  );
}