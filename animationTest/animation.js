import React from 'react';
import Svg, { Path } from 'react-native-svg'; 

const SIZE = 300;

export default function Wave() {
    const path= ['M 0 0', 'V 1', 'H 1'].join(' ');
    return <Svg style= { {width: SIZE, height: SIZE} } viewBox= "0 0 1 1">
        <Path fill= {"blue"} d={path}/>
    </Svg>
}
