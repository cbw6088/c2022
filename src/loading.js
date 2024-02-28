import React, { useState, useEffect } from 'react';
import { View, Text, Image, StyleSheet } from 'react-native';

const Loading = () => {
    const [loadingText, setLoadingText] = useState('');

    useEffect(() => {
        const dots = ['', '.', '. .', '. . .'];
        let currentDot = 0;

        const interval = setInterval(() => {
            setLoadingText(dots[currentDot]);
            currentDot = (currentDot + 1) % dots.length;
        }, 500); // 500ms 간격으로 변경

        return () => clearInterval(interval);
    }, []);

    return (
        <View style={styles.container}>
            <Image
                source={require('../assets/logo/lida_logo.png')} // 이미지 경로 지정
                style={styles.loadingImage}
            />
            <Text style={styles.loadingText}>{loadingText}</Text>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: 'white'
    },
    loadingText: {
        fontSize: 24,
        fontWeight: 'bold',
        marginTop: 20 
    },
    loadingImage: {
        width: 100,
        height: 100, 
        resizeMode: 'contain'
    }
});

export default Loading;