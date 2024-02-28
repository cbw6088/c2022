import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';

const MyAddress = ({ navigation }) => {
  return (
    <View style={styles.container}>
      <Text>MyAddress Page</Text>
      <Button
        title="뒤로"
        onPress={() => navigation.goBack()}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
});

export default MyAddress;
