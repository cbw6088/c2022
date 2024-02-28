import React from 'react';
import { View, Text, Button, StyleSheet, Image, Dimensions, TouchableOpacity } from 'react-native';

const { width, height } = Dimensions.get('window');

const ProfileScreen = ({ navigation }) => {
    const handleProfileChange = () => {
        console.log('프로필 변경');
    };

    return (
    <View style={styles.view}>
        <View style={styles.content}>
        <View style={styles.leftButtonContainer}>
            <Button title="이전" onPress={() => navigation.goBack()} />
        </View>
        <View style={styles.infoBox}>
            <Image
            source={{ uri: 'https://scontent-ssn1-1.cdninstagram.com/v/t51.2885-19/417925521_1055214925719194_8607554024942250217_n.jpg?stp=dst-jpg_s320x320&efg=e30&_nc_ht=scontent-ssn1-1.cdninstagram.com&_nc_cat=102&_nc_ohc=bQjTKj9uOj4AX-PABs8&edm=AOQ1c0wBAAAA&ccb=7-5&oh=00_AfBATrzty5BsPIlB47xqDBAhCDLcO3LX9JycvTVQi2Gv9g&oe=65A24640&_nc_sid=8b3546' }}
            style={styles.image}
            />
            <Text style={styles.name}>챙깐</Text>
        </View>
        <TouchableOpacity style={styles.profileChangeButton} onPress={handleProfileChange}>
            <Text style={styles.profileChangeButtonText}>프로필 변경</Text>
        </TouchableOpacity>   
        </View>
    </View>
    );
};

const styles = StyleSheet.create({
    leftButtonContainer: {
        alignSelf: 'flex-start',
        marginHorizontal: 5, 
        marginTop: 5, 
        marginBottom: 30, 
    },
    view: {
        flex: 1,
        //alignItems: 'left',
        marginLeft: height * 0.02,
        marginRight: height * 0.02,
        marginTop: 50,
    },
    content: {
        flex: 1,
    },
    infoBox: {
        //flexDirection: 'row',
        //justifyContent: 'space-between',
        alignItems: 'center', 
        width: '100%',
        height: height * 0.1,
    },
    image: {
        width: height * 0.1,
        height: height * 0.1,
        borderRadius: 50,
        resizeMode: 'cover',
        marginRight: height * 0.01,
        marginBottom: 15,
    },
    name: {
        fontSize: 20,
        fontWeight: 'bold'
    },
    profileChangeButton: {
        marginTop: 50, 
        backgroundColor: '#A9A9A9', 
        padding: 10, 
        borderRadius: 10,
        borderWidth: 2, 
        width: width * 0.85, 
        borderColor: '#A9A9A9',
        alignSelf: 'center',
    },
    profileChangeButtonText: {
        color: 'white',
        fontSize: 16,
        fontWeight: 'bold',
        textAlign: 'center',
    },
});

export default ProfileScreen;

// npm install @react-navigation/native @react-navigation/stack