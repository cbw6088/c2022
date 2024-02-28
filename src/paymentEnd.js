
import React ,{useState}from 'react';
import { Text,View,Image, TextInput, Button, StyleSheet, Alert, ScrollView,TouchableOpacity, Dimensions } from 'react-native';
import styleSet from './style/style.js';
const { width, height } = Dimensions.get('window');

const PaymentEnd = ({navigation}) => {

    const [isProduct, setIsProduct] = useState(true);

    const loadProduct = () => {
        setIsProduct(!isProduct);
    }

    return(
        <View style = {[styleSet.page,{justifyContent:'center'}]}>
            <View style = {styleSet.box}>
                <View style = {[styleSet.rowAndBetween]}>

                    <Text style={styleSet.Text20Bold}>
                        결제가 완료되었습니다.
                    </Text>

                    <TouchableOpacity onPress={loadProduct} style={styleSet.iconArea}>
                      <Image source={require('../assets/icon/arrow2.png')} style={styleSet.icon}/>
                    </TouchableOpacity>
                </View>
                {isProduct &&(
                    <View style={styleSet.inBox}>
                        <Text>결제 정보</Text>
                    </View>
                )}

                <View style={[styleSet.rowAndBetween,styles.btnBox]}>
                    <TouchableOpacity style={styles.btnText}>
                        <Text style={[styleSet.Text15Bold]}>
                            세부내역 보기
                        </Text>
                    </TouchableOpacity>
                    <TouchableOpacity style={[styles.btnText,{backgroundColor:'black'}]}
                    onPress = {() =>{//#  navigation 초기화 해야하나 ?
                        navigation.navigate('Menu');}}
                    >
                    <Text style={[styleSet.Text15Bold,styles.btnText,{color:'white'}]}>
                            확인
                        </Text>
                    </TouchableOpacity>

                </View>
            </View>

       </View>
    );
}


const styles = StyleSheet.create({
    btnBox:{
        width:'100%', 
        height:height*0.04,
        marginTop:height*0.015,
    },

    btnText:{
        width:'30%',
        alignItems:'center',
        justifyContent:'center',
        borderRadius:20,
    }

});

export default PaymentEnd;