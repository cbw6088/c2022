import React, { useState, useRef } from 'react';
import { Text, View, Image, TextInput, Button, StyleSheet, Alert, ScrollView, TouchableOpacity, Dimensions } from 'react-native';
import MapView, { Marker, Polygon } from 'react-native-maps';

const Maps = () => {
  const [selectedMarker, setSelectedMarker] = useState(null);
  const mapRef = useRef(null);

  const serviceArea = [
    { name: '1번',address:'서울시 광진구 중곡동', coordinates: { latitude: 37.5515, longitude: 127.07 } },
    { name: '2번',address:'서울시 광진구 @@@동', coordinates: { latitude: 37.5475, longitude: 127.075 } },
    { name: '3번',address:'서울시 광진구 ##동', coordinates: { latitude: 37.5575, longitude: 127.08 } },
    { name: '4번',address:'서울시 광진구 화양동', coordinates: { latitude: 37.5585, longitude: 127.074 } },
  ];

  const polygonCoordinates = serviceArea.map((spot) => spot.coordinates);

  const handleMarkerPress = (marker) => {
    setSelectedMarker(marker);
    if (mapRef.current) {
      mapRef.current.animateToRegion({
        latitude: marker.coordinates.latitude,
        longitude: marker.coordinates.longitude,
        latitudeDelta: 0.02, // 원하는 확대 수준으로 조절
        longitudeDelta: 0.02,
      });
    }
  };

  return (
    <MapView
      ref={mapRef}
      showsUserLocation
      followsUserLocation
      style={{ flex: 1 }}
      initialRegion={{
        latitude: 37.5545,
        longitude: 127.0780,
        latitudeDelta: 0.0222,
        longitudeDelta: 0.0221,
      }}
    >
      {serviceArea.map((spot, index) => (
        <Marker
          key={index}
          coordinate={spot.coordinates}
          title={spot.name}
          onPress={() => handleMarkerPress(spot)} // Marker 클릭 시 이벤트 핸들러 호출
          initialRegion={{
            latitude: 37.5515, 
            longitude: 127.07, 
            latitudeDelta: 0.0922,
            longitudeDelta: 0.0421,
          }}
        >
          <Image source = {require('../assets/icon/locker1.png')} style={{width:30,height:30}}/>
          </Marker>
      ))}

      <Polygon
        coordinates={polygonCoordinates}
        fillColor="rgba(0, 128, 255, 0.3)"
        strokeColor="rgba(0, 128, 255, 0.8)"
        strokeWidth={2}
      />

      {selectedMarker && (
        <View style={styles.markerInfoContainer}>
          <Text style={{fontSize:14}}>{selectedMarker.address}</Text>
        </View>
      )}
    
    </MapView>
  );
};

const styles = StyleSheet.create({
  markerInfoContainer: {
    position: 'absolute',
    bottom: 0,
    left: 0,
    right: 0,
    backgroundColor: 'white',
    padding: 10,
    alignItems: 'center',
  },
});

export default Maps;
