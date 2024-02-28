import React, {useState} from 'react';
import { Text,View,Image, TextInput, Button, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
import styleSet from './style/style.js';
import {BottomNav} from './style/style.js';
import Maps from './Maps.js';

const Payment = ({navigation,route}) => {
    
    const {leftBtn,leftSub, 대여시작, 대여종료} = route.params;

    const [isProduct, setIsProduct] = useState(true);
    const [isLocation, setIsLocation] = useState(true);
    const [isMethod, setIsMethod] = useState(true);

    const loadProduct = () => {
        setIsProduct(!isProduct);
    }
    const loadLocation = () => {
        setIsLocation(!isLocation);
    }
    const loadMethod = () => {
        setIsMethod(!isMethod);
    }

    return(
        <View style = {styleSet.page}>
            <View style = {styleSet.box}>
                <View style = {[styleSet.rowAndBetween]}>

                    <Text style={styleSet.Text20Bold}>
                        상품 정보
                    </Text>

                    <TouchableOpacity onPress={loadProduct} style={styleSet.iconArea}>
                      <Image source={require('../assets/icon/arrow2.png')} style={styleSet.iconSmall}/>
                    </TouchableOpacity>
                </View>
                {isProduct &&(
                    <View style={styleSet.inBox}>
                        <Text>아이템</Text>
                        <Text>{대여시작}~{대여종료} ({leftSub})</Text>
                    </View>
                )}
            </View>


            <View style = {styleSet.box}>
                <View style = {styleSet.rowAndBetween}>
                    <Text style={styleSet.Text20Bold}>
                        수령 위치
                    </Text>
                    <TouchableOpacity onPress={loadMethod} style={styleSet.iconArea}>
                    
                    <Image source={require('../assets/icon/arrow2.png')} style={styleSet.iconSmall}/>
                    </TouchableOpacity>
                </View>
                {isMethod &&(
                    <View style={styleSet.mapBox}>
                        <Maps/> 
                    </View>
                )}
            </View>

            <View style = {styleSet.box}>
                <View style = {styleSet.rowAndBetween}>
                    <Text style={styleSet.Text20Bold}>
                    결제 방식
                    </Text>
                    <TouchableOpacity onPress={loadLocation} style={styleSet.iconArea}>
                    
                    <Image source={require('../assets/icon/arrow2.png')} style={styleSet.iconSmall}/>
                    </TouchableOpacity>
                </View>
                {isLocation &&(
                    <View style={styleSet.inBox}>
                        <Text>(카드, 페이 등)</Text>
                    </View>
                )}
            </View>

            <BottomNav 
            info={{
                leftBtn : '결제금액',
                leftSub : leftBtn,
                rightBtn : '결제하기'
                }} 
                req ={()=>{navigation.navigate('PaymentEnd')}}/>
        </View>
    );
}


const styles = StyleSheet.create({

});

export default Payment;